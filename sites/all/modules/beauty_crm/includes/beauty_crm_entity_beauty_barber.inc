<?php

/**
 * @file
 */



/**
 * Saves a model to the database.
 *
 * @param $model
 *   The model object.
 */
function beauty_barber_save(Entity $beauty_barber) {
  return $beauty_barber->save();
}

/**
 * Fetch a model object. Make sure that the wildcard you choose 
 * in the model entity definition fits the function name here.
 *
 * @param $model_id
 *   Integer specifying the model id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $model object or FALSE if it cannot be loaded.
 *
 * @see model_load_multiple()
 */
function beauty_barber_load($beauty_barber_id, $reset = FALSE) {
  $models = beauty_barber_load_multiple(array($beauty_barber_id), array(), $reset);
  return reset($models);
}


/**
 * Load multiple models based on certain conditions.
 *
 * @param $model_ids
 *   An array of model IDs.
 * @param $conditions
 *   An array of conditions to match against the {model} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of model objects, indexed by model_id.
 *
 * @see entity_load()
 * @see model_load()
 */
function beauty_barber_load_multiple($beauty_barber_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('beauty_barber', $beauty_barber_ids, $conditions, $reset);
}


/**
 * Create a model object.
 */
function beauty_barber_create($values = array()) {
  return entity_get_controller('beauty_barber')->create($values);
}