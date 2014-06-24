<?php
/**
 * @file
 * beauty_crm_features.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function beauty_crm_features_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'beauty_hairstyle-beauty_hairstyle-field_harber'
  $field_instances['beauty_hairstyle-beauty_hairstyle-field_harber'] = array(
    'bundle' => 'beauty_hairstyle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'beauty_hairstyle',
    'field_name' => 'field_harber',
    'label' => 'harber',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'beauty_hairstyle-beauty_hairstyle-field_naked_pic'
  $field_instances['beauty_hairstyle-beauty_hairstyle-field_naked_pic'] = array(
    'bundle' => 'beauty_hairstyle',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'beauty_hairstyle',
    'field_name' => 'field_naked_pic',
    'label' => 'naked_pic',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'beauty_crm/beauty_hairstyle/naked',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'beauty_hairstyle-beauty_hairstyle-field_origin_pic'
  $field_instances['beauty_hairstyle-beauty_hairstyle-field_origin_pic'] = array(
    'bundle' => 'beauty_hairstyle',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'beauty_hairstyle',
    'field_name' => 'field_origin_pic',
    'label' => 'origin_pic',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'beauty_crm/beauty_hairstyle/origin',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'medium',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('harber');
  t('naked_pic');
  t('origin_pic');

  return $field_instances;
}
