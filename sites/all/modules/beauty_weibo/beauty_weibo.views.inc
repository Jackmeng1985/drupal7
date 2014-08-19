<?php

/**
 * Implements hook_views_data().
 */
function beauty_weibo_views_data() {
  //Table beauty_weibo_user
  $data['beauty_weibo_user']['table']['group'] = t('Beauty Weibo User');
  $data['beauty_weibo_user']['table']['base'] = array(
    'field' => 'wuid',
    'title' => t('Beauty Weibo User'),
  );

  //微博用户 ID
  $data['beauty_weibo_user']['wuid'] = array(
    'title' => t('Wuid'),
    'help' => t('The weibo user id.'),
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

  //微博用户名
  $data['beauty_weibo_user']['wuname'] = array(
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

  //抓取时间
  $data['beauty_weibo_user']['created'] = array(
    'title' => t('Grabed time'),
    'help' => t('Weibo user grabed time.'),
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

  //微博用户描述
  $data['beauty_weibo_user']['description'] = array(
    'title' => t('Description'),
    'help' => t('Weibo user description.'),
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
  //是否已抓取
  $data['beauty_weibo_user']['status'] = array(
    'title' => t('Is grabed'),
    'help' => t('Weibo grabed status.'),
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

  //Table beauty_weibo_post
  $data['beauty_weibo_post']['table']['group'] = t('Beauty Weibo Post');

  $data['beauty_weibo_post']['table']['base'] = array(
    'field' => 'wid',
    'title' => t('Beauty Weibo Post'),
  );

  //微博 ID
  $data['beauty_weibo_post']['wid'] = array(
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
  $data['beauty_weibo_post']['wuid'] = array(
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
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  //微博用户名
  $data['beauty_weibo_post']['wuname'] = array(
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
  $data['beauty_weibo_post']['wtext'] = array(
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
  $data['beauty_weibo_post']['created'] = array(
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
  $data['beauty_weibo_post']['reposts_count'] = array(
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
  $data['beauty_weibo_post']['comments_count'] = array(
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

  //是否已抓取
  $data['beauty_weibo_post']['status'] = array(
    'title' => t('Is grabed'),
    'help' => t('Weibo grabed status.'),
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

  //Table beauty_weibo_repost
  $data['beauty_weibo_repost']['table']['group'] = t('Beauty Weibo Repost');

  $data['beauty_weibo_repost']['table']['base'] = array(
    'field' => 'uid',
    'title' => t('Beauty Weibo Repost'),
  );

  //转发的微博ID
  $data['beauty_weibo_repost']['rwid'] = array(
    'title' => t('Rwid'),
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
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
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
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
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

  //是否水军
  $data['beauty_weibo_repost']['status'] = array(
    'title' => '水军',
    'help' => '是否是水军',
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => '水军',
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

  //客服回复表
  $data['beauty_weibo_marketing_comment']['table']['group'] = '客服回复';

  $data['beauty_weibo_marketing_comment']['table']['base'] = array(
    'field' => 'wid',
    'title' => '客服回复',
  );

  //微博ID
  $data['beauty_weibo_marketing_comment']['wid'] = array(
    'title' => '微博ID',
    'help' => '微博ID',
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
  $data['beauty_weibo_marketing_comment']['wuid'] = array(
    'title' => '微博用户ID',
    'help' => '微博用户ID',
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
  $data['beauty_weibo_marketing_comment']['wuname'] = array(
    'title' => '微博用户名',
    'help' => '微博用户名',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //微博内容
  $data['beauty_weibo_marketing_comment']['wtext'] = array(
    'title' => '微博内容',
    'help' => '微博内容',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  //创建时间
  $data['beauty_weibo_marketing_comment']['created'] = array(
    'title' => '创建时间',
    'help' => '创建时间',
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

  //Drupal用户ID
  $data['beauty_weibo_marketing_comment']['duid'] = array(
    'title' => 'Drupal用户ID',
    'help' => 'Drupal用户ID',
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

  return $data;
}
