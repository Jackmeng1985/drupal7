<?php

/**
 * 
 */
function beauty_crm_preprocess_beauty_world_cup_hair(&$variables) {
    
}

/**
 * 
 */
function beauty_crm_preprocess_beauty_world_cup_hair_big(&$variables) {
    $hairstyle = $variables['hairstyle'];
    $tag = taxonomy_term_load($hairstyle->field_hairstyle_tags['und'][0]['tid']);
    $variables['hairstyle_tag_name'] = $tag->name;
}