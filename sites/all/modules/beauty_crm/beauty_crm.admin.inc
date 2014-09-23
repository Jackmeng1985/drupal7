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
        'body' => '<span><a href="admin/content">店面活动</a>(1)</span> <span><a href="admin/content">美发作品(2)</a></span> <span><a href="admin/content">工作花絮(3)</a></span> ',
        'footer' => '<span>播放次数：545</span> <span>点赞次数：516</span> <span>分享次数：238</span> <span>点击次数：1128</span> <span>评论次数：198</span> <span>收藏次数：211</span> <span>评论次数：221</span> <span>收藏次数：88</span>'
    );
    return theme('beauty_crm_admin_page', array('items' => $items));
}