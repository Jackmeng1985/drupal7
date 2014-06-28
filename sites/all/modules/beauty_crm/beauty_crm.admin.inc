<?php


/**
 * 
 */

function beauty_crm_edit_hair_picture(Entity $beauty_hairstyle) {
    if ($_POST && $_POST['rawHairContour'] && $_POST['rawFacePoints']) {
        $beauty_hairstyle->data = array('rawHairContour' => $_POST['rawHairContour'] ,'rawFacePoints' => $_POST['rawFacePoints']);
        $beauty_hairstyle->save();
        drupal_goto('admin/beauty-crm/content/beauty_hairstyle');
        drupal_set_message('成功储存数据', 'status');
    }
    drupal_add_css(drupal_get_path('module', 'beauty_crm') . "/js/hairstyle.css");
    drupal_add_js(drupal_get_path('module', 'beauty_crm') . "/js/drag.js");
    return theme('beauty_crm_edit_hair_picture', array('beauty_hairstyle' => $beauty_hairstyle));
}