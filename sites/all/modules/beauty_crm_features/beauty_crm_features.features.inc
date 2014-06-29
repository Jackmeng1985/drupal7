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
