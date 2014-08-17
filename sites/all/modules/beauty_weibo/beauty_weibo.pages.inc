<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function beauty_weibo_marking_comment($wid) {
    if (isset($_SESSION['weibo']['marketing_comment'])) {
        $comment = $_SESSION['weibo']['marketing_comment'];
        unset($_SESSION['weibo']['marketing_comment']);
        $res  = beauty_weibo_api_marketing_comment($wid, $_SESSION['weibo']['marketing_comment']);
        
    }
    return drupal_get_form('beauty_weibo_marking_comment_form');
}

function beauty_weibo_marking_comment_form() {
    $form = array();
    
    $form['text'] = array(
        '#type' => 'textarea',
        '#title' => '要回复的内容',
        '#size' => 6
    );
    return $form;
}