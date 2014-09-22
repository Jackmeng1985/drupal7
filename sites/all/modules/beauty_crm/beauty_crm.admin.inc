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

function beauty_crm_admin() {
    $items = array();
    
    $items['dianpu'] = array(
        'header_title' => '视频',
        'header_info' => '视频数量(12)',
        'body' => '店面活动(1) 美发作品(2) 工作花絮(3) ',
        'footer' => '播放次数：545 点赞次数：516 分享次数：238 点击次数：1128 评论次数：198 收藏次数：211 评论次数：221 收藏次数：88'
    );
    return theme('beauty_crm_admin_page', array('items' => $items));
}