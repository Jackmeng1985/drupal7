<?php

/**
 * @file
 * Functionality for Weixin administration.
 */

/**
 * Menu callback: Weixin appid and appsecret config.
 */
function weixin_oauth_admin_settings() {
  $form['weixin']['weixin_appid'] = array(
    '#type' => 'textfield',
    '#title' => t('AppId'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get('weixin_appid', ''),
  );
  $form['weixin']['weixin_appsecret'] = array(
    '#type' => 'textfield',
    '#title' => t('AppSecret'),
    '#size' => 40,
    '#maxlength' => 255,
    '#default_value' => variable_get('weixin_appsecret', ''),
  );

  return system_settings_form($form);
}
