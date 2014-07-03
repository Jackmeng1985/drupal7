<?php

/**
 * @file
 */

/**
 * 
 * @param type $form_id
 * @param array $form_state
 * @return string
 */
function beauty_shop_form($form_id, $form_state) {
    
//  dsm ($form_state['beauty_shop']);
// Add the default field elements.
  $beauty_shop = $form_state['beauty_shop'];
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => '店铺名称',
    '#default_value' => isset($beauty_shop->name) ? $beauty_shop->name: '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -6,
  );
  
  $form['phone'] = array(
    '#type' => 'textfield',
    '#title' => '店铺前台电话',
    '#default_value' => isset($beauty_shop->phone) ? $beauty_shop->phone : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['address'] = array(
    '#type' => 'textfield',
    '#title' => '店铺地址',
    '#default_value' => isset($beauty_shop->address) ? $beauty_shop->address : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );  
  
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => '店铺描述',
    '#default_value' => isset($beauty_shop->description) ? $beauty_shop->description : '',
  ); 
  
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => '状态',
    '#default_value' => isset($beauty_shop->status) ? $beauty_shop->status : '',
  );     
  

  // Add the field related form elements.
  $form_state['beauty_shop'] = $beauty_shop;
  field_attach_form('beauty_shop', $beauty_shop, $form, $form_state);
  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => '保存',
    '#submit' => $submit + array('beauty_shop_form_submit'),
  );
  

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'beauty_shop_form_validate';
  return $form;
//    return $form_state['wrapper_callback']($form_id, $form_state, $form_state['entity_type'] , NULL, $form_state['build_info']['args'][1]);
}


/**
 * Form API validate callback for the model form
 */
function beauty_shop_form_validate(&$form, &$form_state) {
  $beauty_shop = $form_state['beauty_shop'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('beauty_shop', $beauty_shop, $form, $form_state);
}


/**
 * Form API submit callback for the model form.
 * 
 * @todo remove hard-coded link
 */
function beauty_shop_form_submit(&$form, &$form_state) {
  $beauty_shop = entity_ui_controller('beauty_shop')->entityFormSubmitBuildEntity($form, $form_state);
  
  
  // Save the model and go back to the list of models
  // Add in created and changed times.
  if ($beauty_shop->is_new = isset($beauty_shop->is_new) ? $beauty_shop->is_new : 0){
    $beauty_shop->created = time();
  }

  $beauty_shop->changed = time();
  
  $beauty_shop->save();
  $form_state['redirect'] = 'admin/beauty-crm/content/beauty_shop';
}


function beauty_hairstyle_form($form_id, $form_state) {
//  dsm ($form_state['beauty_shop']);
// Add the default field elements.
  $beauty_hairstyle = $form_state['beauty_hairstyle'];
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => '发型名称',
    '#default_value' => isset($beauty_hairstyle->name) ? $beauty_hairstyle->name: '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -6,
  );
  
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => '发型描述',
    '#default_value' => isset($beauty_hairstyle->description) ? $beauty_hairstyle->description : '',
  ); 
  
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => '状态',
    '#default_value' => isset($beauty_hairstyle->status) ? $beauty_hairstyle->status : '',
  );     
  

  // Add the field related form elements.
  $form_state['beauty_hairstyle'] = $beauty_hairstyle;
  field_attach_form('beauty_hairstyle', $beauty_hairstyle, $form, $form_state);
  
  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => '保存',
    '#submit' => $submit + array('beauty_hairstyle_form_submit'),
  );
  

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'beauty_hairstyle_form_validate';
  return $form;
//    return $form_state['wrapper_callback']($form_id, $form_state, $form_state['entity_type'] , NULL, $form_state['build_info']['args'][1]);
}


/**
 * Form API validate callback for the model form
 */
function beauty_hairstyle_form_validate(&$form, &$form_state) {
  $beauty_hairstyle = $form_state['beauty_hairstyle'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('beauty_hairstyle', $beauty_hairstyle, $form, $form_state);
}


/**
 * Form API submit callback for the model form.
 * 
 * @todo remove hard-coded link
 */
function beauty_hairstyle_form_submit(&$form, &$form_state) {
  $beauty_hairstyle = entity_ui_controller('beauty_hairstyle')->entityFormSubmitBuildEntity($form, $form_state);
  
  
  // Save the model and go back to the list of models
  // Add in created and changed times.
  if ($beauty_hairstyle->is_new = isset($beauty_hairstyle->is_new) ? $beauty_hairstyle->is_new : 0){
    $beauty_hairstyle->created = time();
  }

  $beauty_hairstyle->changed = time();
  
  $beauty_hairstyle->save();
  $form_state['redirect'] = 'admin/beauty-crm/content/beauty_hairstyle';
}



function beauty_barber_form($form_id, $form_state) {
//  dsm ($form_state['beauty_shop']);
// Add the default field elements.
  $beauty_barber = $form_state['beauty_barber'];
  
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => '美发师名',
    '#default_value' => isset($beauty_barber->name) ? $beauty_barber->name: '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -6,
  );
  
  $form['phone'] = array(
    '#type' => 'textfield',
    '#title' => '电话',
    '#default_value' => isset($beauty_barber->phone) ? $beauty_barber->phone : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => '状态',
    '#default_value' => isset($beauty_barber->status) ? $beauty_barber->status : '',
  );     
  

  // Add the field related form elements.
  $form_state['beauty_barber'] = $beauty_barber;
  field_attach_form('beauty_barber', $beauty_barber, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => '保存',
    '#submit' => $submit + array('beauty_barber_form_submit'),
  );
  

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'beauty_barber_form_validate';
  return $form;
//    return $form_state['wrapper_callback']($form_id, $form_state, $form_state['entity_type'] , NULL, $form_state['build_info']['args'][1]);
}


/**
 * Form API validate callback for the model form
 */
function beauty_barber_form_validate(&$form, &$form_state) {
  $beauty_barber = $form_state['beauty_barber'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('beauty_barber', $beauty_barber, $form, $form_state);
}


/**
 * Form API submit callback for the model form.
 * 
 * @todo remove hard-coded link
 */
function beauty_barber_form_submit(&$form, &$form_state) {
  $beauty_barber = entity_ui_controller('beauty_barber')->entityFormSubmitBuildEntity($form, $form_state);
  
  
  // Save the model and go back to the list of models
  // Add in created and changed times.
  if ($beauty_barber->is_new = isset($beauty_barber->is_new) ? $beauty_barber->is_new : 0){
    $beauty_barber->created = time();
  }

  $beauty_barber->changed = time();
  
  $beauty_barber->save();
  $form_state['redirect'] = 'admin/beauty-crm/content/beauty_barber';
}


function beauty_works_form($form_id, $form_state) {
//  dsm ($form_state['beauty_shop']);
// Add the default field elements.
  $beauty_works = $form_state['beauty_works'];
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => '作品名称',
    '#default_value' => isset($beauty_works->name) ? $beauty_works->name: '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -6,
  );
  
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => '作品描述',
    '#default_value' => isset($beauty_works->description) ? $beauty_works->description : '',
  ); 
  
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => '状态',
    '#default_value' => isset($beauty_works->status) ? $beauty_works->status : '',
  );     
  

  // Add the field related form elements.
  $form_state['beauty_hairstyle'] = $beauty_works;
  field_attach_form('beauty_works', $beauty_works, $form, $form_state);
  
  if($beauty_works->is_new && $_GET['bid']) {
    $form['field_harber']['und']['#default_value'] = $_GET['bid'];
  }
  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => '保存',
    '#submit' => $submit + array('beauty_works_form_submit'),
  );
  

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'beauty_works_form_validate';
  return $form;
//    return $form_state['wrapper_callback']($form_id, $form_state, $form_state['entity_type'] , NULL, $form_state['build_info']['args'][1]);
}


/**
 * Form API validate callback for the model form
 */
function beauty_works_form_validate(&$form, &$form_state) {
  $beauty_works = $form_state['beauty_works'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('beauty_works', $beauty_works, $form, $form_state);
}


/**
 * Form API submit callback for the model form.
 * 
 * @todo remove hard-coded link
 */
function beauty_works_form_submit(&$form, &$form_state) {
  $beauty_works = entity_ui_controller('beauty_works')->entityFormSubmitBuildEntity($form, $form_state);
  
  
  // Save the model and go back to the list of models
  // Add in created and changed times.
  if ($beauty_works->is_new = isset($beauty_works->is_new) ? $beauty_works->is_new : 0){
    $beauty_works->created = time();
  }

  $beauty_works->changed = time();
  
  $res = $beauty_works->save();
  
  if ($res) {
      drupal_set_message('成功添加作品', 'status');
  }
  if (!drupal_get_destination()) {
      $form_state['redirect'] = 'admin/beauty-crm/content/beauty_works';
  }
}
