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

  // Exported field_instance: 'beauty_barber-beauty_barber-field_shop'
  $field_instances['beauty_barber-beauty_barber-field_shop'] = array(
    'bundle' => 'beauty_barber',
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'beauty_barber',
    'field_name' => 'field_shop',
    'label' => '美发店',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'beauty_hairstyle-beauty_hairstyle-field_hairstyle_tags'
  $field_instances['beauty_hairstyle-beauty_hairstyle-field_hairstyle_tags'] = array(
    'bundle' => 'beauty_hairstyle',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'beauty_hairstyle',
    'field_name' => 'field_hairstyle_tags',
    'label' => '标签',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 4,
    ),
  );

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
    'label' => '美发师',
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
    'label' => '加工后头型',
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
    'label' => '原始头型',
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
  t('加工后头型');
  t('原始头型');
  t('标签');
  t('美发师');
  t('美发店');

  return $field_instances;
}