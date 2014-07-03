<?php
/**
 * @file
 * beauty_crm_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function beauty_crm_features_taxonomy_default_vocabularies() {
  return array(
    'hairstyle_tags' => array(
      'name' => '标签',
      'machine_name' => 'hairstyle_tags',
      'description' => '发型的标签',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'works_tags' => array(
      'name' => '作品集标签',
      'machine_name' => 'works_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
