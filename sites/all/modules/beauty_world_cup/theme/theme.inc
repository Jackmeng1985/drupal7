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

    $variables['banner_news_vote'] = beauty_vote_get_vote_widget('node', $variables['banner_news']->nid);
}

function beauty_world_cup_preprocess_beauty_world_cup_news_detail(&$variables) {
    $variables['banner_news_vote'] = beauty_vote_get_vote_widget('node', $variables['news']->nid);
}

/**
 *
 */
function beauty_world_cup_preprocess_beauty_world_cup_hair_advantage(&$variables) {
    $banner_video = $variables['banner_video'];
    $banner_video = node_load_multiple($banner_video);
    $variables['banner_video'] = current($banner_video);

    $advantage_videos = $variables['advantage_videos'];
    $advantage_videos = node_load_multiple($advantage_videos);
    $variables['advantage_videos'] = $advantage_videos;

}
