<?php
// $Id: template.php,v 1.21 2012/08/16 andyzhao Exp $


require_once dirname(__FILE__) . '/includes/beauty.inc';

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
function beauty_preprocess_page(&$vars) {
    if (arg(0) == 'world_cup') {
        if (!arg(1)) {
            $suggestion_template = 'page__beauty_world_cup_front_page';
        }
        else {
            $suggestion_template = 'page__beauty_' . str_replace('/', '_', $_GET['q']);
        }

        if (strstr($_GET['q'], 'world_cup/hair/adjustment') !== FALSE) {
            $suggestion_template = 'page__beauty_world_cup_hair_adjustment';
        }
        if (strstr($_GET['q'], 'world_cup/hair/upload') !== FALSE) {
            $suggestion_template = 'page__beauty_world_cup_hair_upload';
        }

        if (strstr($_GET['q'], 'world_cup/hair/big') !== FALSE) {
            $suggestion_template = 'page__beauty_world_cup_hair_big';
        }
        if (strstr($_GET['q'], 'world_cup/video') !== FALSE) {
            $suggestion_template = 'page__beauty_world_cup_video';
        }
        if (strstr($_GET['q'], 'world_cup/barber') !== FALSE) {
            $suggestion_template = 'page__beauty_world_cup_barber';
        }
        array_splice($vars['theme_hook_suggestions'], 0, 0, $suggestion_template);
    }
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 */
function beauty_preprocess_html(&$vars) {
    $needs_mobile_html_template = FALSE;
    if (strstr($_GET['q'], 'world_cup/hair/adjustment') !== FALSE) {
        $needs_mobile_html_template = TRUE;
    }
    if (strstr($_GET['q'], 'world_cup/hair/upload') !== FALSE) {
        $needs_mobile_html_template = TRUE;
    }
    if (strstr($_GET['q'], 'world_cup/hair') !== FALSE && (!arg(2) || is_numeric(arg(2))) ) {
        $needs_mobile_html_template = TRUE;
    }
    if (strstr($_GET['q'], 'world_cup/news/detail') !== FALSE ) {
        beauty_add_js(drupal_get_path('theme', 'beauty') . '/js/segmented-controllers.js');
        $needs_mobile_html_template = TRUE;
    }
    if (strstr($_GET['q'], 'world_cup/hair/big')) {
        beauty_add_js(drupal_get_path('theme', 'beauty') . '/js/sliders.js');
        $needs_mobile_html_template = TRUE;
    }
    if (strstr($_GET['q'], 'world_cup/flip_card')) {
        $needs_mobile_html_template = TRUE;
    }
    if (strstr($_GET['q'], 'world_cup/video')) {
        $needs_mobile_html_template = TRUE;
    }

    if ($_GET['q'] == 'world_cup') {
//        beauty_add_normal_js();
        beauty_add_js(drupal_get_path('theme', 'beauty') . '/js/segmented-controllers.js');
        beauty_add_js(drupal_get_path('theme', 'beauty') . '/js/mid2url.js');
        beauty_add_js(drupal_get_path('theme', 'beauty') . '/js/template.js');
        beauty_add_js(drupal_get_path('theme', 'beauty') . '/js/tatali.js');
        $needs_mobile_html_template = TRUE;
    }
    if ($needs_mobile_html_template) {
        beauty_add_css(drupal_get_path('theme', 'beauty') . '/css/ratchet.css');
        array_splice($vars['theme_hook_suggestions'], 0, 0, 'html__mobile');
    }

    // 针对微信浏览器
    $vars['head_title'] = explode('|', $vars['head_title']);
    $vars['head_title'] = $vars['head_title'][0];
}

function beauty_add_normal_js() {
   beauty_add_js('misc/jquery.js');
   beauty_add_js('misc/drupal.js');
}
