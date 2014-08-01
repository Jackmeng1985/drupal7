<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * menu callback
 */
function beauty_crm_pages_login() {
    beauty_fashion_add_normal_js();
     beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
  

    return theme('beauty_crm_pages_login', array('hairstyles' => $hairstyles, 'tags' => $tags));
}

function beauty_crm_pages_shops() {
    beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
    $query = db_select('beauty_shop', 'bs');
    $query->addField('bs', 'sid');
    $query->orderBy('bs.sid', 'asc');
    //$query->range(0, 10);
    $result = $query->execute();
    foreach ($result as $row) {
        $rows[] = $row->sid;
    }
    $shops = beauty_shop_load_multiple($rows);
    return theme('beauty_crm_pages_shops', array('shops' => $shops));
}

function beauty_crm_pages_shop($sid) {
    beauty_fashion_add_normal_js();
    beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/merchants.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getWH.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getLocation.js');
  
    $shop = beauty_shop_load_multiple(array($sid));
    return theme('beauty_crm_pages_shop',  array('works' => $works, 'tags' => NULL,'shop' => $shop));
}
function beauty_crm_pages_barbers() {
    beauty_fashion_add_normal_js(); 
     beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages').'/js/index.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getWH.js');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/barberIndex.js');
        
    $query = db_select('beauty_barber', 'bb');
    $query->join('beauty_shop','bs','bs.sid=bb.sid');
    $query->join('beauty_works','bw','bw.bid=bb.bid');
    $query->addField('bb', 'bid');
    $query->addField('bs','sid');
    $query->addField('bw', 'wid');
   $query->orderBy('bb.created', 'desc');
      // $query->range(0,3);
    $result = $query->execute();
    foreach ($result as $row) {
        $rows[] = $row->bid;
        $rowshops[$row->bid]=beauty_shop_load($row->sid);
        $rowworks[$row->bid]=beauty_works_load($row->wid);
    }
  
    $barbers = beauty_barber_load_multiple($rows);
    //print_r($barbers);die();
  
    //$works= beauty_works_load_multiple($rowworks);
   //$shops= beauty_shop_load_multiple($rowshops);
   
   //print_r($works);die();
    return theme('beauty_crm_pages_barbers',  array('barbers' => $barbers,'rowworks'=>$rowworks,'rowshops'=>$rowshops));
}
function beauty_crm_pages_homepage() {
    beauty_fashion_add_normal_js(); 
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages').'/js/index.js');
    beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getWH.js');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getLocation.js');
     
     $query = db_select('beauty_hairstyle', 'bh');
    $query->addField('bh', 'hid');
       $query->orderBy('bh.hid', 'desc');
       //$query->range(0,2);
       $result = $query->execute();
    foreach ($result as $row) {
        $rows[] = $row->hid;
    }
  
    $hairstyles = beauty_hairstyle_load_multiple($rows);
   // print_r($hairstyles);die();

  return theme('beauty_crm_pages_homepage', array('hairstyles' => $hairstyles ));
}

function beauty_crm_pages_changestyle() {
     beauty_fashion_add_normal_js(); 
    beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getWH.js');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getLocation.js');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/changeStyle.js');
     $query = db_select('beauty_hairstyle', 'bh');
    $query->addField('bh', 'hid');
       $query->orderBy('bh.hid', 'desc');
        $result = $query->execute();
    foreach ($result as $row) {
        $rows[] = $row->hid;
    }
  
    $hairstyles = beauty_hairstyle_load_multiple($rows);
     

    return theme('beauty_crm_pages_changestyle', array('hairstyles' => $hairstyles));    
}


function beauty_crm_pages_usertabs() {
    beauty_add_css(drupal_get_path('module', 'beauty_crm_pages') . '/css/style.css');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/userTabs.js');
    beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getWH.js');
     beauty_add_js(drupal_get_path('module', 'beauty_crm_pages') . '/js/util/getLocation.js');
      
    beauty_fashion_add_normal_js();
    return theme('beauty_crm_pages_usertabs', array('banner_news' => $banner_news, 'frontpage_news' => $frontpage_news));
}