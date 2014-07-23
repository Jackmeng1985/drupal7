<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * menu callback
 */
function beauty_world_cup_pages_hair() {
    beauty_add_normal_js();
    $termid = arg(2);
    $query = db_select('beauty_hairstyle', 'bh');
    if (is_numeric($termid)) {
        $query->join('field_data_field_hairstyle_tags', 'fdfht', 'fdfht.entity_id = bh.hid');
        $query->condition('fdfht.field_hairstyle_tags_tid', $termid, '=');
    }
    $query->addField('bh', 'hid');
    $query->orderBy('bh.hid', 'desc');
    $result = $query->execute();
    foreach ($result as $row) {
        $rows[] = $row->hid;
    }
    $hairstyles = beauty_hairstyle_load_multiple($rows);

    $tags = taxonomy_get_tree(2); //TODO vid is required

    return theme('beauty_world_cup_hair', array('hairstyles' => $hairstyles, 'tags' => $tags));
}

function beauty_world_cup_pages_hair_big(Entity $beauty_hairstyle) {
    
    $barber = beauty_barber_load($beauty_hairstyle->bid);
    $shop = beauty_shop_load($beauty_barber->sid);
    return theme('beauty_world_cup_hair_big', array('hairstyle' => $beauty_hairstyle));
}

function beauty_world_cup_pages_works() {
    beauty_add_normal_js();   
    beauty_add_css(drupal_get_path('module', 'beauty_world_cup') . '/css/beauty_works.css');
       $query = db_select('beauty_works', 'bw');
       $query->addField('bw', 'wid');
    $query->orderBy('bw.created', 'desc');
    $result = $query->execute();
    foreach ($result as $row) {
        $rows[] = $row->wid;
    }
    $works = beauty_works_load_multiple($rows);


    return theme('beauty_world_cup_works',  array('works' => $works, 'tags' => NULL));
}
function beauty_world_cup_pages_works_detail($wid) {
    beauty_add_normal_js(); 
          beauty_add_css(drupal_get_path('module', 'beauty_world_cup') . '/css/beauty_works.css');
     $query = db_select('beauty_works', 'bw');
       $query->addField('bw', 'wid');
       $query->condition("bw.wid",$wid,"=");
       $result = $query->execute()->fetchAssoc();
        
       $result = beauty_works_load($result['wid']);
    return theme('beauty_world_cup_works_detail',  array('result' => $result));
}
function beauty_world_cup_page_hair_advantage() {
  $banner_video = db_select('node', 'n')
    ->fields('n')
    ->condition('sticky', 1, '=')
    ->condition('type', 'beauty_video', '=')
    ->condition('status', 1, '=')
    ->orderBy('created', 'desc')
    ->range(0,1)
    ->execute()
    ->fetchAllKeyed();
  $advantage_videos = db_select('node', 'n')
    ->fields('n')
    ->condition('promote', 1, '=')
    ->condition('sticky', 1, '<>')
    ->condition('type', 'beauty_video', '=')
    ->condition('status', 1, '=')
    ->orderBy('created', 'desc')
    ->execute()
    ->fetchAllKeyed();

  return theme('beauty_world_cup_hair_advantage', array('banner_video' => $banner_video, 'advantage_videos' => $advantage_videos));
}

function beauty_world_cup_page_video($nid) {
    $video = node_load($nid);
    if ($video->type <> 'beauty_video') {
        return drupal_access_denied();
    }
    return theme('beauty_world_cup_video', array('video' => $video));    
}


function beauty_world_cup_pages() {
    $banner_news = db_select('node', 'n')
            ->fields('n')
            ->condition('sticky', 1, '=')
            ->condition('type', 'beauty_news', '=')
            ->condition('status', 1, '=')
            ->orderBy('created', 'desc')
            ->range(0,1)
            ->execute()
            ->fetchAllKeyed();
    $frontpage_news = db_select('node', 'n')
            ->fields('n')
            ->condition('promote', 1, '=')
            ->condition('sticky', 1, '<>')
            ->condition('type', 'beauty_news', '=')
            ->condition('status', 1, '=')
            ->orderBy('created', 'desc')
            ->range(0,3)
            ->execute()
            ->fetchAllKeyed();
    beauty_add_normal_js();
    return theme('beauty_world_cup_frontpage', array('banner_news' => $banner_news, 'frontpage_news' => $frontpage_news));
}

function beauty_world_cup_page_news_detail($nid) {
    $news = node_load($nid);
    if ($news->type <> 'beauty_news') {
        return drupal_access_denied();
    }
    beauty_add_normal_js();
    return theme('beauty_world_cup_news_detail', array('news' => $news));
}

function beauty_world_cup_flip_card() {
    beauty_add_normal_js();
    beauty_add_js(drupal_get_path('module', 'beauty_world_cup') . '/js/flip_card.js');
    beauty_add_css(drupal_get_path('module', 'beauty_world_cup') . '/css/flip_card.css');
    return theme('beauty_world_cup_flip_card', array());
}
