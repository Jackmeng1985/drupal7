<?php

function beauty_add_js($data = NULL, $options = NULL) {
  $javascript = &drupal_static(__FUNCTION__, array());

  // Construct the options, taking the defaults into consideration.
  if (isset($options)) {
    if (!is_array($options)) {
      $options = array('type' => $options);
    }
  }
  else {
    $options = array();
  }
  $options += drupal_js_defaults($data);

  // Preprocess can only be set if caching is enabled.
  $options['preprocess'] = $options['cache'] ? $options['preprocess'] : FALSE;

  // Tweak the weight so that files of the same weight are included in the
  // order of the calls to beauty_add_js().
  $options['weight'] += count($javascript) / 1000;

  if (isset($data)) {
    // Add jquery.js and drupal.js, as well as the basePath setting, the
    // first time a JavaScript file is added.
    if (empty($javascript)) {
      // url() generates the prefix using hook_url_outbound_alter(). Instead of
      // running the hook_url_outbound_alter() again here, extract the prefix
      // from url().
      url('', array('prefix' => &$prefix));
//      $javascript = array(
//        'settings' => array(
//          'data' => array(
//            array('basePath' => base_path()),
//            array('pathPrefix' => empty($prefix) ? '' : $prefix),
//          ),
//          'type' => 'setting',
//          'scope' => 'header',
//          'group' => JS_LIBRARY,
//          'every_page' => TRUE,
//          'weight' => 0,
//        ),
//        'misc/drupal.js' => array(
//          'data' => 'misc/drupal.js',
//          'type' => 'file',
//          'scope' => 'header',
//          'group' => JS_LIBRARY,
//          'every_page' => TRUE,
//          'weight' => -1,
//          'preprocess' => TRUE,
//          'cache' => TRUE,
//          'defer' => FALSE,
//        ),
//      );
      // Register all required libraries.
      drupal_add_library('system', 'jquery', TRUE);
      drupal_add_library('system', 'jquery.once', TRUE);
    }

    switch ($options['type']) {
      case 'setting':
        // All JavaScript settings are placed in the header of the page with
        // the library weight so that inline scripts appear afterwards.
        $javascript['settings']['data'][] = $data;
        break;

      case 'inline':
        $javascript[] = $options;
        break;

      default: // 'file' and 'external'
        // Local and external files must keep their name as the associative key
        // so the same JavaScript file is not added twice.
        $javascript[$options['data']] = $options;
    }
  }
  return $javascript;
}

function beauty_get_js($scope = 'header', $javascript = NULL, $skip_alter = FALSE) {
  if (!isset($javascript)) {
    $javascript = beauty_add_js();
  }
  if (empty($javascript)) {
    return '';
  }

  // Allow modules to alter the JavaScript.
  if (!$skip_alter) {
    drupal_alter('js', $javascript);
  }

  // Filter out elements of the given scope.
  $items = array();
  foreach ($javascript as $key => $item) {
    if ($item['scope'] == $scope) {
      $items[$key] = $item;
    }
  }

  $output = '';
  // The index counter is used to keep aggregated and non-aggregated files in
  // order by weight.
  $index = 1;
  $processed = array();
  $files = array();
  $preprocess_js = (variable_get('preprocess_js', FALSE) && (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update'));

  // A dummy query-string is added to filenames, to gain control over
  // browser-caching. The string changes on every update or full cache
  // flush, forcing browsers to load a new copy of the files, as the
  // URL changed. Files that should not be cached (see beauty_add_js())
  // get REQUEST_TIME as query-string instead, to enforce reload on every
  // page request.
  $default_query_string = variable_get('css_js_query_string', '0');

  // For inline JavaScript to validate as XHTML, all JavaScript containing
  // XHTML needs to be wrapped in CDATA. To make that backwards compatible
  // with HTML 4, we need to comment out the CDATA-tag.
  $embed_prefix = "\n<!--//--><![CDATA[//><!--\n";
  $embed_suffix = "\n//--><!]]>\n";

  // Since JavaScript may look for arguments in the URL and act on them, some
  // third-party code might require the use of a different query string.
  $js_version_string = variable_get('drupal_js_version_query_string', 'v=');

  // Sort the JavaScript so that it appears in the correct order.
  uasort($items, 'drupal_sort_css_js');

  // Provide the page with information about the individual JavaScript files
  // used, information not otherwise available when aggregation is enabled.
  $setting['ajaxPageState']['js'] = array_fill_keys(array_keys($items), 1);
  unset($setting['ajaxPageState']['js']['settings']);
  beauty_add_js($setting, 'setting');

  // If we're outputting the header scope, then this might be the final time
  // that drupal_get_js() is running, so add the setting to this output as well
  // as to the beauty_add_js() cache. If $items['settings'] doesn't exist, it's
  // because drupal_get_js() was intentionally passed a $javascript argument
  // stripped off settings, potentially in order to override how settings get
  // output, so in this case, do not add the setting to this output.
  if ($scope == 'header' && isset($items['settings'])) {
    $items['settings']['data'][] = $setting;
  }

  // Loop through the JavaScript to construct the rendered output.
  $element = array(
    '#tag' => 'script',
    '#value' => '',
    '#attributes' => array(
      'type' => 'text/javascript',
    ),
  );
  foreach ($items as $item) {
    $query_string =  empty($item['version']) ? $default_query_string : $js_version_string . $item['version'];

    switch ($item['type']) {
      case 'setting':
        $js_element = $element;
        $js_element['#value_prefix'] = $embed_prefix;
        $js_element['#value'] = 'jQuery.extend(Drupal.settings, ' . drupal_json_encode(drupal_array_merge_deep_array($item['data'])) . ");";
        $js_element['#value_suffix'] = $embed_suffix;
        $output .= theme('html_tag', array('element' => $js_element));
        break;

      case 'inline':
        $js_element = $element;
        if ($item['defer']) {
          $js_element['#attributes']['defer'] = 'defer';
        }
        $js_element['#value_prefix'] = $embed_prefix;
        $js_element['#value'] = $item['data'];
        $js_element['#value_suffix'] = $embed_suffix;
        $processed[$index++] = theme('html_tag', array('element' => $js_element));
        break;

      case 'file':
        $js_element = $element;
        if (!$item['preprocess'] || !$preprocess_js) {
          if ($item['defer']) {
            $js_element['#attributes']['defer'] = 'defer';
          }
          $query_string_separator = (strpos($item['data'], '?') !== FALSE) ? '&' : '?';
          $js_element['#attributes']['src'] = file_create_url($item['data']) . $query_string_separator . ($item['cache'] ? $query_string : REQUEST_TIME);
          $processed[$index++] = theme('html_tag', array('element' => $js_element));
        }
        else {
          // By increasing the index for each aggregated file, we maintain
          // the relative ordering of JS by weight. We also set the key such
          // that groups are split by items sharing the same 'group' value and
          // 'every_page' flag. While this potentially results in more aggregate
          // files, it helps make each one more reusable across a site visit,
          // leading to better front-end performance of a website as a whole.
          // See beauty_add_js() for details.
          $key = 'aggregate_' . $item['group'] . '_' . $item['every_page'] . '_' . $index;
          $processed[$key] = '';
          $files[$key][$item['data']] = $item;
        }
        break;

      case 'external':
        $js_element = $element;
        // Preprocessing for external JavaScript files is ignored.
        if ($item['defer']) {
          $js_element['#attributes']['defer'] = 'defer';
        }
        $js_element['#attributes']['src'] = $item['data'];
        $processed[$index++] = theme('html_tag', array('element' => $js_element));
        break;
    }
  }

  // Aggregate any remaining JS files that haven't already been output.
  if ($preprocess_js && count($files) > 0) {
    foreach ($files as $key => $file_set) {
      $uri = drupal_build_js_cache($file_set);
      // Only include the file if was written successfully. Errors are logged
      // using watchdog.
      if ($uri) {
        $preprocess_file = file_create_url($uri);
        $js_element = $element;
        $js_element['#attributes']['src'] = $preprocess_file;
        $processed[$key] = theme('html_tag', array('element' => $js_element));
      }
    }
  }

  // Keep the order of JS files consistent as some are preprocessed and others are not.
  // Make sure any inline or JS setting variables appear last after libraries have loaded.
  return implode('', $processed) . $output;
}

function beauty_add_css($data = NULL, $options = NULL) {
  $css = &drupal_static(__FUNCTION__, array());

  // Construct the options, taking the defaults into consideration.
  if (isset($options)) {
    if (!is_array($options)) {
      $options = array('type' => $options);
    }
  }
  else {
    $options = array();
  }

  // Create an array of CSS files for each media type first, since each type needs to be served
  // to the browser differently.
  if (isset($data)) {
    $options += array(
      'type' => 'file',
      'group' => CSS_DEFAULT,
      'weight' => 0,
      'every_page' => FALSE,
      'media' => 'all',
      'preprocess' => TRUE,
      'data' => $data,
      'browsers' => array(),
    );
    $options['browsers'] += array(
      'IE' => TRUE,
      '!IE' => TRUE,
    );

    // Files with a query string cannot be preprocessed.
    if ($options['type'] === 'file' && $options['preprocess'] && strpos($options['data'], '?') !== FALSE) {
      $options['preprocess'] = FALSE;
    }

    // Always add a tiny value to the weight, to conserve the insertion order.
    $options['weight'] += count($css) / 1000;

    // Add the data to the CSS array depending on the type.
    switch ($options['type']) {
      case 'inline':
        // For inline stylesheets, we don't want to use the $data as the array
        // key as $data could be a very long string of CSS.
        $css[] = $options;
        break;
      default:
        // Local and external files must keep their name as the associative key
        // so the same CSS file is not be added twice.
        $css[$data] = $options;
    }
  }

  return $css;
}


function beauty_get_css($css = NULL, $skip_alter = FALSE) {
  if (!isset($css)) {
    $css = beauty_add_css();
  }

  // Allow modules and themes to alter the CSS items.
  if (!$skip_alter) {
    drupal_alter('css', $css);
  }

  // Sort CSS items, so that they appear in the correct order.
  uasort($css, 'drupal_sort_css_js');

  // Provide the page with information about the individual CSS files used,
  // information not otherwise available when CSS aggregation is enabled. The
  // setting is attached later in this function, but is set here, so that CSS
  // files removed below are still considered "used" and prevented from being
  // added in a later AJAX request.
  // Skip if no files were added to the page or jQuery.extend() will overwrite
  // the Drupal.settings.ajaxPageState.css object with an empty array.
  if (!empty($css)) {
    // Cast the array to an object to be on the safe side even if not empty.
    $setting['ajaxPageState']['css'] = (object) array_fill_keys(array_keys($css), 1);
  }

  // Remove the overridden CSS files. Later CSS files override former ones.
  $previous_item = array();
  foreach ($css as $key => $item) {
    if ($item['type'] == 'file') {
      // If defined, force a unique basename for this file.
      $basename = isset($item['basename']) ? $item['basename'] : drupal_basename($item['data']);
      if (isset($previous_item[$basename])) {
        // Remove the previous item that shared the same base name.
        unset($css[$previous_item[$basename]]);
      }
      $previous_item[$basename] = $key;
    }
  }

  // Render the HTML needed to load the CSS.
  $styles = array(
    '#type' => 'styles',
    '#items' => $css,
  );

  if (!empty($setting)) {
    $styles['#attached']['js'][] = array('type' => 'setting', 'data' => $setting);
  }

  return drupal_render($styles);
}
