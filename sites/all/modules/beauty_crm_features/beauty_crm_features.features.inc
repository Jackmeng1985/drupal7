<?php
/**
 * @file
 * beauty_crm_features.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function beauty_crm_features_image_default_styles() {
  $styles = array();

  // Exported image style: hairstyle_change.
  $styles['hairstyle_change'] = array(
    'name' => 'hairstyle_change',
    'label' => 'hairstyle_change',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hairstyle_world_cup.
  $styles['hairstyle_world_cup'] = array(
    'name' => 'hairstyle_world_cup',
    'label' => 'hairstyle_world_cup',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 185,
          'height' => 205,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function beauty_crm_features_node_info() {
  $items = array(
    'beauty_news' => array(
      'name' => t('丽锦快讯'),
      'base' => 'node_content',
      'description' => t('丽锦快讯'),
      'has_title' => '1',
      'title_label' => t('标题'),
      'help' => '',
    ),
  );
  return $items;
}
