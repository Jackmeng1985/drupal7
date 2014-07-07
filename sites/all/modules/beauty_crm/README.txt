alter table beauty_shop add column `name` varchar(64) NOT NULL DEFAULT '' COMMENT '美发店 店名.' after sid;

alter table beauty_hairstyle add column `name` varchar(64) NOT NULL DEFAULT '' COMMENT '发型名称' after sid;

drop table beauty_hairstyle;

CREATE TABLE beauty_hairstyle (
`hid` INT NOT NULL auto_increment, 
`bid` INT NOT NULL DEFAULT 0, 
`name` VARCHAR(64) NOT NULL DEFAULT '', 
`description` VARCHAR(255) NOT NULL DEFAULT '', 
`status` TINYINT unsigned NOT NULL DEFAULT 1, 
`created` INT NOT NULL DEFAULT 0, 
PRIMARY KEY (`hid`)
) ENGINE = InnoDB DEFAULT CHARACTER SET utf8;


alter table beauty_hairstyle add column `data` Blob COMMENT '另外数据';


CREATE TABLE IF NOT EXISTS `beauty_works` (
  `wid` int(11) NOT NULL AUTO_INCREMENT COMMENT '作品 ID',
  `bid` int(11) NOT NULL DEFAULT '0' COMMENT '美发师 ID.',
  `name` varchar(64) NOT NULL DEFAULT '' COMMENT '作品名称.',
  `description` varchar(255) NOT NULL DEFAULT '' COMMENT '作品 描述.',
  `status` tinyint(3) unsigned NOT NULL DEFAULT '1' COMMENT '作品 状态.',
  `created` int(11) NOT NULL DEFAULT '0' COMMENT '创建时间.',
  `data` longblob COMMENT '其它数据',
  PRIMARY KEY (`wid`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 


CREATE TABLE {beauty_weixin_user} (
`wxuid` INT NOT NULL auto_increment COMMENT '微信用户 ID', 
`uid` INT NOT NULL DEFAULT 0 COMMENT 'uid', 
`phone` VARCHAR(64) NOT NULL DEFAULT '' COMMENT '电话.', 
`openid` VARCHAR(255) NOT NULL DEFAULT '' COMMENT 'openid.', 
`status` TINYINT unsigned NOT NULL DEFAULT 1 COMMENT '用户 状态.', 
`created` INT NOT NULL DEFAULT 0 COMMENT '创建时间.', 
`data` BLOB NOT NULL COMMENT '其它数据', 
PRIMARY KEY (`wxuid`)
) ENGINE = InnoDB DEFAULT CHARACTER SET utf8;