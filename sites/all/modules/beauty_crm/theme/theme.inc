<?php

/**
 * Template preprocess for apachesolr search results.
 *
 * We need to add additional entity/bundle-based templates
 */
function beauty_crm_preprocess_beauty_crm_edit_hair_picture(&$variables) {
    $beauty_hairstyle = $variables['beauty_hairstyle'];
    
//    dsm($beauty_hairstyle);
    
    $variables['pic_origin_path'] = image_style_url('hairstyle_change', $beauty_hairstyle->field_origin_pic['und'][0]['uri']);
    $variables['pic_path'] = file_create_url($beauty_hairstyle->field_naked_pic['und'][0]['uri']);
    
    $variables['rawHairContour'] = $beauty_hairstyle->data['rawHairContour'];
    $variables['rawFacePoints'] = $beauty_hairstyle->data['rawFacePoints'];
    
    list($variables['pic_origin_width'], $variables['pic_origin_height']) = getimagesize($variables['pic_origin_path']);
    
}

function theme_beauty_crm_admin_page($vars) {
    $items = $vars['items'];
  
    $output = '<ul>';
    foreach ($items as $key => $item) {
        $output .= '<li>' .theme('beauty_crm_admin_page_item', array('item' => $item, 'item_key' => $key)) . '</li>';
    }
    $output .= '</ul>';
    
    return $output;
}