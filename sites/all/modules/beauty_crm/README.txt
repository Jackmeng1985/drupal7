alter table beauty_shop add column `name` varchar(64) NOT NULL DEFAULT '' COMMENT '美发店 店名.' after sid;

alter table beauty_hairstyle add column `name` varchar(64) NOT NULL DEFAULT '' COMMENT '发型名称' after sid;

ALTER TABLE  `beauty_hairstyle` CHANGE  `sid`  `hid` INT( 11 ) NOT NULL AUTO_INCREMENT COMMENT  '发型 ID'