SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT=0;
START TRANSACTION;
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
COMMIT;
