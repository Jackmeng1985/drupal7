<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function beauty_weibo_marketing_comment($wid) {
    if (isset($_SESSION['weibo']['marketing_comment'])) {
        $comment = $_SESSION['weibo']['marketing_comment'];
        unset($_SESSION['weibo']['marketing_comment']);
        $res  = beauty_weibo_api_marketing_comment($wid, $comment);
        if (isset($res['error'])) {
            $e = new Exception("错误信息： {$res['error']} 错误代码： {$res['error_code']}");
            watchdog_exception('beauty', $e, "错误信息： {$res['error']} 错误代码： {$res['error_code']}");
            throw $e;            
        }
        
        $weibo_marketing_comment_record = new stdClass;
        $weibo_marketing_comment_record->wid = $res['id'];
        $weibo_marketing_comment_record->cuid = $res['user']['id'];
        $weibo_marketing_comment_record->wuid = $res['status']['user']['id'];
        $weibo_marketing_comment_record->wuname = $res['user']['name'];
        $weibo_marketing_comment_record->wtext = beauty_weibo_api_replace4byte($res['text']);
        $weibo_marketing_comment_record->created = strtotime($res['created_at']);
        $weibo_marketing_comment_record->duid = $GLOBALS['user']->uid;
        $weibo_marketing_comment_record->data = $res;

        drupal_write_record('beauty_weibo_post', $weibo_marketing_comment_record);
        drupal_set_message('成功评论');
        
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
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => '关注',
    );    
    return $form;
}

function beauty_weibo_marking_comment_form_submit($form, $form_state) {
    $_SESSION['weibo']['marketing_comment'] = $form_state['values']['text'];
}