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
  `Job_nom` varchar(100) DEFAULT NULL,
  `Date_ins` datetime NOT NULL,
  `VilleId` int(11) NOT NULL COMMENT 'Id de la ville auquel apprtient cet objet',
  `ObjTyp` int(11) NOT NULL,
  `Date_modif` datetime DEFAULT NULL,
  `RubriqueId` int(11) NOT NULL COMMENT 'L''id de la rubrique auquel elle appartient',
  PRIMARY KEY (`JobId`),
  KEY `RubriqueId` (`RubriqueId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
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
