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


alter table beauty_hairstyle add column `data` smallblob COMMENT '另外数据';
