<?php

/**
 * @file
 * Functionality for Weixin administration.
 */

/**
 * Menu callback: Weixin appid and appsecret config.
 */
function beauty_weibo_admin_settings() {
  $form['weibo']['weibo_appkey'] = array(
    '#type' => 'textfield',
    '#title' => t('App Key'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get('weibo_appkey', ''),
  );
  $form['weibo']['weibo_appsecret'] = array(
    '#type' => 'textfield',
    '#title' => t('App Secret'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get('weibo_appsecret', ''),
  );

  return system_settings_form($form);
}
