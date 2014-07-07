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


/**
 * The Controller for Model entities
 */
class BeautyBarberController extends EntityAPIController {

    public function __construct($entityType) {
        parent::__construct($entityType);
    }

    /**
     * 保存的时候同步美发店的id
     */
    public function save($entity, DatabaseTransaction $transaction = NULL) {
        if (isset($entity->field_shop)) {
            $entity->sid = $entity->field_shop['und'][0]['target_id'];
        }
        $return = parent::save($entity, $transaction);
        return $return;
    }
}

/**
 * UI controller.
 */
class BeautyBarberUIController extends EntityDefaultUIController {
    
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

    if (isset($_GET['shop']) && is_numeric($_GET['shop']) && $_GET['shop'] != 0) {
        $query->propertyCondition('sid', $_GET['shop'], '=');
    }
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
      $rows[] = $this->overviewTableRow($conditions, entity_id($this->entityType, $entity), $entity, array(l('添加作品集', 'admin/beauty-crm/content/beauty_works/add', array('query' => array('bid' => $entity->bid, 'destination' => current_path())))));
    }

    $render = array(
      '#theme' => 'table',
      '#header' => $this->overviewTableHeaders($conditions, $rows),
      '#rows' => $rows,
      '#empty' => t('None.'),
    );
    return $render;
  }
  /**
   * Builds the entity overview form.
   */
  public function overviewForm($form, &$form_state) {
     
    $query = db_select('beauty_shop', 'b');
    $query->addField('b', 'sid');
    $query->addField('b', 'name');
    $query->orderBy('created', 'desc');
    $result = $query->execute();
     foreach ($result as $row) {
         $options[$row->sid] = $row->name;
     }
    $form['header'] = array(
        '#title' => '门店',
        '#type' => 'select',
        '#options' => array('请选择') + $options,
        '#default_value' => isset($_GET['shop']) ? $_GET['shop'] : 0,
        '#attributes' => array(
           'id' => 'beauty_shop',
           'onChange' => 'javascript:window.location.href="/admin/beauty-crm/content/beauty_barber?shop=" + jQuery("#beauty_shop").val();',
        )
    );
    $return = parent::overviewForm($form, $form_state);
    return $return;
  }  
}