SET AUTOCOMMIT=0;
START TRANSACTION;
DROP TABLE IF EXISTS `ProvinceTab`;
CREATE TABLE IF NOT EXISTS `ProvinceTab` (
  `ProvinceId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Province_nom` varchar(30) NOT NULL,
  PRIMARY KEY (`ProvinceId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;
INSERT INTO `ProvinceTab` (`ProvinceId`, `Province_nom`) VALUES
(1, 'Est \n'),
(2, 'Centre \n'),
(3, 'Nord-Ouest \n'),
(4, 'Sud \n'),
(5, 'Sud-Ouest \n'),
(6, 'Ouest \n'),
(7, 'Adamaoua \n'),
(8, 'Littoral \n'),
(9, 'Nord \n'),
(10, 'Extreme-Nord \n');
DROP TABLE IF EXISTS `RubriqueTab`;
CREATE TABLE IF NOT EXISTS `RubriqueTab` (
  `RubriqueId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Rubrique_nom` varchar(40) DEFAULT NULL,
  `tab` varchar(20) NOT NULL COMMENT 'La table MySQL correspondiquesant aux rubr',
  PRIMARY KEY (`RubriqueId`),
  KEY `Rubrique_nom` (`Rubrique_nom`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;
INSERT INTO `RubriqueTab` (`RubriqueId`, `Rubrique_nom`, `tab`) VALUES
(1, 'Automobile', 'AutoTab'),
(2, 'Electromenager', 'ElectroTab'),
(3, 'Electronique', 'ElectroTab'),
(4, 'Immobilier', 'ImmobilierTab'),
(5, 'Meubles', 'MeubleTab'),
(6, 'Jobs et Business', 'JobTab'),
(7, 'Services', 'JobTab'),
(8, 'Objets d''arts', 'ObjArtTab'),
(9, 'Tableau d''arts', 'ObjArtTab'),
(10, 'Produits agricoles', 'ProdAgrTab'),
(11, 'Machine agricoles', 'AutoTab');
COMMIT;
