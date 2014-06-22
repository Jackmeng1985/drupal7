<?php


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