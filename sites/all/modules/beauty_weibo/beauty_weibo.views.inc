<?php

/**
 * Implements hook_views_data().
 */
function beauty_weibo_views_data() {
  //Table beauty_weibo
  $data['beauty_weibo']['table']['group'] = t('Beauty Weibo');

  $data['beauty_weibo']['table']['base'] = array(
    'field' => 'wid',
    'title' => t('Beauty Weibo'),
  );

  //微博 ID
  $data['beauty_weibo']['wid'] = array(
    'title' => t('Wid'),
    'help' => t('The weibo id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  //微博用户ID
  $data['beauty_weibo']['wuid'] = array(
    'title' => t('Wuid'),
    'help' => t('Weibo user id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //微博用户名
  $data['beauty_weibo']['wuname'] = array(
    'title' => t('Wuname'),
    'help' => t('Weibo user name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //微博内容
  $data['beauty_weibo']['wtext'] = array(
    'title' => t('Wtext'),
    'help' => t('Weibo content.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //抓取时间
  $data['beauty_weibo']['created'] = array(
    'title' => t('Weibo Created'),
    'help' => t('Weibo created time.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  //转发数
  $data['beauty_weibo']['reposts_count'] = array(
    'title' => t('Reposts count'),
    'help' => t('Weibo reposts count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //评论数
  $data['beauty_weibo']['comments_count'] = array(
    'title' => t('Comments count'),
    'help' => t('Weibo comments count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //Table beauty_weibo_repost
  $data['beauty_weibo_repost']['table']['group'] = t('Beauty Weibo Repost');

  $data['beauty_weibo_repost']['table']['base'] = array(
    'field' => 'wid',
    'title' => t('Beauty Weibo Repost'),
  );

  //转发的微博ID
  $data['beauty_weibo_repost']['rwid'] = array(
    'title' => t('Rweid'),
    'help' => t('The reposted weibo id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //转发的微博用户ID
  $data['beauty_weibo_repost']['ruid'] = array(
    'title' => t('Ruid'),
    'help' => t('The reposted weibo user id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  //微博ID
  $data['beauty_weibo_repost']['wid'] = array(
    'title' => t('Wid'),
    'help' => t('Weibo id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //真实的转发的微博ID
  $data['beauty_weibo_repost']['rrwid'] = array(
    'title' => t('Wid'),
    'help' => t('Real reposted weibo id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //微博内容
  $data['beauty_weibo_repost']['text'] = array(
    'title' => t('Text'),
    'help' => t('Weibo content.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //微博来源
  $data['beauty_weibo_repost']['source'] = array(
    'title' => t('Source'),
    'help' => t('Weibo source.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //转发数
  $data['beauty_weibo_repost']['reposts_count'] = array(
    'title' => t('Reposts count'),
    'help' => t('Weibo reposts count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //评论数
  $data['beauty_weibo_repost']['comments_count'] = array(
    'title' => t('Comments count'),
    'help' => t('Weibo comment_count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //用户ID
  $data['beauty_weibo_repost']['uid'] = array(
    'title' => t('Uid'),
    'help' => t('Weibo user id.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //名字
  $data['beauty_weibo_repost']['name'] = array(
    'title' => t('Name'),
    'help' => t('Weibo user name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //地理位置 城市
  $data['beauty_weibo_repost']['location_city'] = array(
    'title' => t('Location city'),
    'help' => t('Weibo user location city.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //地理位置 省份
  $data['beauty_weibo_repost']['location_province'] = array(
    'title' => t('Location Province'),
    'help' => t('Weibo user location province.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //微博url
  $data['beauty_weibo_repost']['url'] = array(
    'title' => t('Url'),
    'help' => t('Weibo url.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //用户头像url
  $data['beauty_weibo_repost']['profile_image_url'] = array(
    'title' => t('Profile image url'),
    'help' => t('Weibo profile image url.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //性别
  $data['beauty_weibo_repost']['gender'] = array(
    'title' => t('Gender'),
    'help' => t('Weibo user gender.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  //粉丝数
  $data['beauty_weibo_repost']['followers_count'] = array(
    'title' => t('Followers count'),
    'help' => t('Weibo followers count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //朋友数
  $data['beauty_weibo_repost']['friends_count'] = array(
    'title' => t('Friends count'),
    'help' => t('Weibo friends count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //收藏数
  $data['beauty_weibo_repost']['favourites_count'] = array(
    'title' => t('Favourites count'),
    'help' => t('Weibo favourites count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //微博数
  $data['beauty_weibo_repost']['statuses_count'] = array(
    'title' => t('Statuses count'),
    'help' => t('Weibos count.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //是否关注
  $data['beauty_weibo_repost']['following'] = array(
    'title' => t('Following'),
    'help' => t('Is following?'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Following'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //是否验证用户
  $data['beauty_weibo_repost']['verified'] = array(
    'title' => t('Verified'),
    'help' => t('Weibo verified status.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Verified'),
      'type' => 'yes-no',
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //转发时间
  $data['beauty_weibo_repost']['created'] = array(
    'title' => t('Weibo repost Created'),
    'help' => t('Weibo repost created time.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  return $data;
}
