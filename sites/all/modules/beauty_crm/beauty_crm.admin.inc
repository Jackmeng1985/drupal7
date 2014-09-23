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
    

    
    $items['barber'] = array(
        'header_title' => '美发师',
        'header_info' => "<a href='/admin/beauty-crm/content/beauty_barber'>美发师数量</a>(381)",
    );      
   
    $items['shop'] = array(
        'header_title' => '店铺',
        'header_info' => "<a href='/admin/beauty-crm/content/beauty_shop'>店铺数量</a>(43)",
    );    
    
    $weixin_count = weixin_oauth_get_followers_count();
    $items['weixin'] = array(
        'header_title' => '微信粉丝',
        'header_info' => "粉丝数量($weixin_count)",
    );        
    
    $items['shipin'] = array(
        'header_title' => '视频',
        'header_info' => '视频数量(4)',
        'body' => '<span><a href="/admin/content">店面活动</a>(1)</span> <span><a href="/admin/content">美发作品</a>(3)</span> <span><a href="/admin/content">工作花絮</a>(0)</span> ',
        'footer' => '<span>播放次数：545</span> <span>点赞次数：30</span> <span>分享次数：20</span> <span>点击次数：1128</span> <span>评论次数：198</span> <span>收藏次数：4</span> <span>评论次数：21</span>'
    );
    

    $items['picture'] = array(
        'header_title' => '发型图片',
        'header_info' => '发型图片(16)',
        'body' => '<span><a href="/admin/beauty-crm/content/beauty_hairstyle">男生</a>(10)</span> <span><a href="/admin/beauty-crm/content/beauty_hairstyle">女生</a>(5)</span> <span><a href="/admin/beauty-crm/content/beauty_hairstyle">短发</a>(5)</span> ',
        'footer' => '<span>点击次数：3765</span> <span>点赞次数：87</span> <span>分享次数：59</span> <span>评论次数：368</span> <span>收藏次数：67</span> '
    );    
    
    $items['news'] = array(
        'header_title' => '新闻',
        'header_info' => '新闻数量(2)',
        'body' => '<span><a href="/admin/content">市场</a>(0)</span> <span><a href="/admin/content">娱乐</a>(0)</span> <span><a href="/admin/content">体育</a>(2)</span> ',
        'footer' => '<span>点击次数：238</span> <span>点赞次数：37</span> <span>分享次数：8</span> <span>评论次数：18</span> <span>收藏次数：7</span> '
    );        
    drupal_add_css(drupal_get_path('module', 'beauty_crm') . '/css/admin.css');
    return theme('beauty_crm_admin_page', array('items' => $items));
}
