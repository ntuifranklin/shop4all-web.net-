SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT=0;
START TRANSACTION;
DROP TABLE IF EXISTS `connected`;
CREATE TABLE IF NOT EXISTS `connected` (
  `id` bigint(10) NOT NULL AUTO_INCREMENT,
  `macaddr` varchar(16) DEFAULT NULL,
  `datec` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `ImagesTab`;
CREATE TABLE IF NOT EXISTS `ImagesTab` (
  `ImagesId` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Id de cet image',
  `ObjectId` int(20) NOT NULL COMMENT 'Id de l''objet a qui appartient cet image',
  `Table_appartenance` varchar(30) NOT NULL COMMENT 'Table d''appartenance',
  `nom` varchar(20) NOT NULL COMMENT 'Nom de l''image dans le dossier files',
  PRIMARY KEY (`ImagesId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `log`;
CREATE TABLE IF NOT EXISTS `log` (
  `id` bigint(10) NOT NULL AUTO_INCREMENT,
  `iduser` int(8) DEFAULT NULL,
  `macaddr` varchar(16) DEFAULT NULL,
  `datel` datetime DEFAULT NULL,
  `url` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `NewsLetterTab`;
CREATE TABLE IF NOT EXISTS `NewsLetterTab` (
  `NewsLetterId` int(11) NOT NULL AUTO_INCREMENT,
  `NewsLetter_mail` varchar(30) NOT NULL,
  PRIMARY KEY (`NewsLetterId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `noconfinscrit`;
CREATE TABLE IF NOT EXISTS `noconfinscrit` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `UserId` int(11) NOT NULL COMMENT 'iduser qui ne veux as confirmer son insertion',
  `nofois` int(11) NOT NULL COMMENT 'nombre de fois que ce user recoit le mail de confirmation',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Conserve les users qui ne veulent pas confirmer leur inscrip';
DROP TABLE IF EXISTS `noconfinsert`;
CREATE TABLE IF NOT EXISTS `noconfinsert` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'id',
  `UserId` int(11) NOT NULL COMMENT 'iduser  qui ne veux pas confirmer son insertion',
  `RubriqueId` int(11) NOT NULL COMMENT 'Id de la rubrique auquel appartient l''objet inserer non confirmer',
  `ObjectId` int(11) NOT NULL COMMENT 'id de l''objet dont l''insetion n''as pas été confirmer',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 COMMENT='Conserve la trace des users qui insere et ne confirme pas le';
COMMIT;
