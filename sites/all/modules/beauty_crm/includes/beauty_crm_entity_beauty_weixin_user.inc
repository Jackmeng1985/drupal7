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
function beauty_weixin_user_save(Entity $beauty_weixin_user) {
  return $beauty_weixin_user->save();
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
function beauty_weixin_user_load($beauty_weixin_user_id, $reset = FALSE) {
  $models = beauty_weixin_user_load_multiple(array($beauty_weixin_user_id), array(), $reset);
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
function beauty_weixin_user_load_multiple($beauty_weixin_user_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('beauty_weixin_user', $beauty_weixin_user_ids, $conditions, $reset);
}


/**
 * Create a model object.
 */
function beauty_weixin_user_create($values = array()) {
  return entity_get_controller('beauty_weixin_user')->create($values);
}


/**
 * The Controller for Model entities
 */
class BeautyWeixinUserController extends EntityAPIController {

    public function __construct($entityType) {
        parent::__construct($entityType);
    }

    /**
     * 保存的时候同步美发店的id
     */
    public function save($entity, DatabaseTransaction $transaction = NULL) {

        $return = parent::save($entity, $transaction);
        return $return;
    }
}

/**
 * UI controller.
 */
class BeautyWeixinUserUIController extends EntityDefaultUIController {
    
  /**
   * Generates the render array for a overview table for arbitrary entities
   * matching the given conditions.
   *
   * @param $conditions
   *   An array of conditions as needed by entity_load().

   * @return Array
   *   A renderable array.
   */
  public function overviewTable($conditions = array()) {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $this->entityType);

    // Add all conditions to query.
    foreach ($conditions as $key => $value) {
      $query->propertyCondition($key, $value);
    }

    if ($this->overviewPagerLimit) {
      $query->pager($this->overviewPagerLimit);
    }

    $results = $query->execute();

    $ids = isset($results[$this->entityType]) ? array_keys($results[$this->entityType]) : array();
    $entities = $ids ? entity_load($this->entityType, $ids) : array();
    ksort($entities);

    $rows = array();
    foreach ($entities as $entity) {
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity);
    }

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }    
}