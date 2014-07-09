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

/**
 * 
 */
function beauty_world_cup_preprocess_beauty_world_cup_frontpage(&$variables) {
    $banner_news = $variables['banner_news'];
    $banner_news = node_load_multiple($banner_news);
    $variables['banner_news'] = current($banner_news);
    
    $frontpage_news = $variables['frontpage_news'];
    $frontpage_news = node_load_multiple($frontpage_news);
    $variables['frontpage_news'] = $frontpage_news;
    
}