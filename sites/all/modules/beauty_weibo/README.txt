
CREATE TABLE IF NOT EXISTS `beauty_weibo_marketing_comment` (
  `wid` bigint(20) NOT NULL DEFAULT '0' COMMENT '微博 ID.',
  `wuid` bigint(20) NOT NULL DEFAULT '0' COMMENT '微博 用户 ID.',
  `wuname` varchar(255) NOT NULL DEFAULT '' COMMENT '微博用户名.',
  `wtext` varchar(2000) NOT NULL DEFAULT '' COMMENT '微博内容.',
  `created` int(11)  NOT NULL DEFAULT '0' COMMENT '创建时间.'
  `duid` int(11) NOT NULL DEFAULT '0' COMMENT 'Drupal 用户id。.',
  `data` blob NOT NULL COMMENT '其它数据',
  PRIMARY KEY (`wid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='客服回复表.';