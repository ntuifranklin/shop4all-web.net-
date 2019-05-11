
SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT=0;
START TRANSACTION;
DROP TABLE IF EXISTS `AutoTab`;
CREATE TABLE IF NOT EXISTS `AutoTab` (
  `AutoId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `Auto_nom` varchar(100) NOT NULL,
  `Auto_marque` varchar(30) DEFAULT NULL,
  `Auto_model` varchar(30) DEFAULT NULL,
  `VilleId` int(11) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `Date_ins` datetime NOT NULL,
  `Auto_proprios` int(11) DEFAULT NULL,
  `Auto_puissance` int(11) DEFAULT NULL,
  `Auto_kilometrage` int(11) DEFAULT NULL,
  `Auto_prix` int(11) NOT NULL,
  `Auto_carburant` varchar(30) DEFAULT NULL COMMENT 'Type de carburant ',
  `Auto_couleur` varchar(30) DEFAULT NULL,
  `Auto_comfort` varchar(30) DEFAULT NULL,
  `Auto_desc` varchar(500) NOT NULL,
  `ObjTyp` int(11) NOT NULL,
  `Date_modif` datetime DEFAULT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`AutoId`),
  KEY `RubriqueId` (`RubriqueId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `connected`;
CREATE TABLE IF NOT EXISTS `connected` (
  `id` bigint(10) NOT NULL AUTO_INCREMENT,
  `macaddr` varchar(16) DEFAULT NULL,
  `datec` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `ElectroTab`;
CREATE TABLE IF NOT EXISTS `ElectroTab` (
  `ElectroId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `Electro_nom` varchar(100) DEFAULT NULL COMMENT 'Titre de l''objet electromenager ou electronique',
  `VilleId` int(11) NOT NULL COMMENT 'La ville auquel appartient cet objet',
  `Electro_desc` varchar(500) DEFAULT NULL,
  `Electro_prix` double NOT NULL,
  `Electro_dim` varchar(30) DEFAULT NULL,
  `Date_ins` datetime NOT NULL,
  `Date_modif` datetime DEFAULT NULL,
  `Electro_masse` double DEFAULT NULL,
  `ObjTyp` int(11) NOT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`ElectroId`),
  KEY `RubriqueId` (`RubriqueId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `ImagesTab`;
CREATE TABLE IF NOT EXISTS `ImagesTab` (
  `ImagesId` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Id de cet image',
  `ObjectId` int(20) NOT NULL COMMENT 'Id de l''objet a qui appartient cet image',
  `Table_appartenance` varchar(30) NOT NULL COMMENT 'Table d''appartenance',
  `nom` varchar(20) NOT NULL COMMENT 'Nom de l''image dans le dossier files',
  PRIMARY KEY (`ImagesId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `ImmobilierTab`;
CREATE TABLE IF NOT EXISTS `ImmobilierTab` (
  `ImmobilierId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `Immobilier_nom` varchar(100) DEFAULT NULL COMMENT 'Titre de l''objet Immiobilier',
  `Immobilier_desc` varchar(500) DEFAULT NULL,
  `ObjTyp` int(11) NOT NULL,
  `Date_ins` datetime NOT NULL,
  `Immobilier_prix` double(10,2) NOT NULL,
  `VilleId` int(30) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `Date_modif` datetime DEFAULT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`ImmobilierId`),
  KEY `RubriqueId` (`RubriqueId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `JobTab`;
CREATE TABLE IF NOT EXISTS `JobTab` (
  `JobId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `Job_desc` varchar(500) DEFAULT NULL,
  `Job_title` varchar(100) DEFAULT NULL,
  `Date_ins` datetime NOT NULL,
  `VilleId` int(11) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `ObjTyp` int(11) NOT NULL,
  `Date_modif` datetime DEFAULT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`JobId`),
  KEY `RubriqueId` (`RubriqueId`)
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
DROP TABLE IF EXISTS `MeubleTab`;
CREATE TABLE IF NOT EXISTS `MeubleTab` (
  `MeubleId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `Meuble_nom` varchar(100) DEFAULT NULL COMMENT 'Titre du meuble a vendre',
  `Meuble_desc` varchar(500) DEFAULT NULL,
  `VilleId` int(11) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `Meuble_dim` varchar(30) DEFAULT NULL,
  `Meuble_prix` double NOT NULL,
  `Date_ins` datetime NOT NULL,
  `ObjTyp` int(11) NOT NULL,
  `Date_modif` datetime DEFAULT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`MeubleId`),
  KEY `UserId` (`UserId`),
  KEY `RubriqueId` (`RubriqueId`),
  KEY `Meuble_dim` (`Meuble_dim`),
  KEY `RubriqueId_2` (`RubriqueId`),
  KEY `VilleId` (`VilleId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
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
DROP TABLE IF EXISTS `ObjArtTab`;
CREATE TABLE IF NOT EXISTS `ObjArtTab` (
  `ObjArtId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `ObjArt_nom` varchar(100) DEFAULT NULL COMMENT 'Titre du meuble a vendre',
  `ObjArt_desc` varchar(500) DEFAULT NULL,
  `ObjArt_dim` varchar(30) DEFAULT NULL,
  `ObjArt_prix` double NOT NULL,
  `Date_ins` datetime NOT NULL,
  `ObjArt_masse` double DEFAULT NULL,
  `ObjTyp` int(11) NOT NULL,
  `VilleId` int(11) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `Date_modif` datetime DEFAULT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`ObjArtId`),
  KEY `RubriqueId` (`RubriqueId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `ProdAgrTab`;
CREATE TABLE IF NOT EXISTS `ProdAgrTab` (
  `ProdAgrId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `ProdAgr_nom` varchar(100) DEFAULT NULL COMMENT 'Titre des produits agricoles a vendre',
  `ProdAgr_desc` varchar(500) DEFAULT NULL,
  `VilleId` int(11) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `Date_Ins` datetime NOT NULL,
  `Date_modif` datetime DEFAULT NULL,
  `ProdAgr_prix` int(11) NOT NULL,
  `ProdAgr_masse` int(11) DEFAULT NULL,
  `ObjTyp` int(11) NOT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`ProdAgrId`),
  KEY `UserId` (`UserId`),
  KEY `ProdAgr_nom` (`ProdAgr_nom`),
  KEY `RubriqueId` (`RubriqueId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `ProvinceTab`;
CREATE TABLE IF NOT EXISTS `ProvinceTab` (
  `ProvinceId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Province_nom` varchar(30) NOT NULL,
  PRIMARY KEY (`ProvinceId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `RubriqueTab`;
CREATE TABLE IF NOT EXISTS `RubriqueTab` (
  `RubriqueId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Rubrique_nom` varchar(40) DEFAULT NULL,
  `tab` varchar(20) NOT NULL COMMENT 'La table MySQL correspondiquesant aux rubr',
  PRIMARY KEY (`RubriqueId`),
  KEY `Rubrique_nom` (`Rubrique_nom`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `UserTab`;
CREATE TABLE IF NOT EXISTS `UserTab` (
  `UserId` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Id du user',
  `VilleId` bigint(20) DEFAULT NULL COMMENT 'Le id de sa ville si elle existe',
  `User_pseudo` varchar(30) NOT NULL COMMENT 'Son pseudonyme',
  `User_nom` varchar(30) DEFAULT NULL COMMENT 'Nom de ce user',
  `User_prenom` varchar(30) DEFAULT NULL COMMENT 'prenom de ce User',
  `Date_Ins` date NOT NULL COMMENT 'date d''insertion de ce user',
  `Date_modif` date DEFAULT NULL COMMENT 'date de derniere modification des infos de ce user',
  `User_email` varchar(30) NOT NULL COMMENT 'email du user',
  `User_tel` varchar(30) NOT NULL COMMENT 'telephone du user',
  `User_pw` varchar(50) DEFAULT NULL COMMENT 'Mot de passe du user',
  `User_nletter` int(11) DEFAULT NULL COMMENT 'Si l''utilisateur a accepter de recevoir les newsletters',
  `User_etat` int(11) NOT NULL DEFAULT '0' COMMENT 'Permet de savoir si le user est connecter ou non',
  `User_inscrit` int(11) DEFAULT '0' COMMENT 'Permet de savoir si le user est completement inscrit ou pas',
  PRIMARY KEY (`UserId`),
  UNIQUE KEY `User_pseudo` (`User_pseudo`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
DROP TABLE IF EXISTS `VilleTab`;
CREATE TABLE IF NOT EXISTS `VilleTab` (
  `VilleId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Ville_nom` varchar(40) NOT NULL,
  `ProvinceId` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`VilleId`),
  KEY `ProvinceId` (`ProvinceId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1;
COMMIT;
