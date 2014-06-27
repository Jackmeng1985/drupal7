<?php


/**
 * 
 */

function beauty_crm_edit_hair_picture(Entity $beauty_hairstyle) {
//    dsm($beauty_hairstyle);
    
    drupal_add_css(drupal_get_path('module', 'beauty_crm') . "/js/hairstyle.css");
    drupal_add_js(drupal_get_path('module', 'beauty_crm') . "/js/drag.js");
    return theme('beauty_crm_edit_hair_picture', array('beauty_hairstyle' => $beauty_hairstyle));
}