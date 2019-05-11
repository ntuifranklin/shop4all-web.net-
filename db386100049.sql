-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 22, 2012 at 02:53 PM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `db386100049`
--

-- --------------------------------------------------------

--
-- Table structure for table `AutoTab`
--

CREATE TABLE IF NOT EXISTS `AutoTab` (
  `AutoId` bigint(20) NOT NULL AUTO_INCREMENT,
  `UserId` bigint(20) NOT NULL,
  `Auto_titre` varchar(100) NOT NULL,
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
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `AutoTab`
--

INSERT INTO `AutoTab` (`AutoId`, `UserId`, `Auto_titre`, `Auto_marque`, `Auto_model`, `VilleId`, `Date_ins`, `Auto_proprios`, `Auto_puissance`, `Auto_kilometrage`, `Auto_prix`, `Auto_carburant`, `Auto_couleur`, `Auto_comfort`, `Auto_desc`, `ObjTyp`, `Date_modif`, `RubriqueId`) VALUES
(1, 1, 'Peugeot 504 a vendre', 'Peogeot', '504', 184, '2012-02-22 00:00:00', 2, 147, 12, 1450000, 'essence', 'Noir', 'Oui tres confortable', '- En bon etat', 0, '2012-02-22 00:00:00', 1);

-- --------------------------------------------------------

--
-- Table structure for table `connected`
--

CREATE TABLE IF NOT EXISTS `connected` (
  `id` bigint(10) NOT NULL AUTO_INCREMENT,
  `macaddr` varchar(16) DEFAULT NULL,
  `datec` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `connected`
--

INSERT INTO `connected` (`id`, `macaddr`, `datec`) VALUES
(8, '127.0.0.1', '2012-02-22 14:15:58');

-- --------------------------------------------------------

--
-- Table structure for table `ElectroTab`
--

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
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ImagesTab`
--

CREATE TABLE IF NOT EXISTS `ImagesTab` (
  `ImagesId` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'Id de cet image',
  `ObjectId` int(20) NOT NULL COMMENT 'Id de l''objet a qui appartient cet image',
  `Table_appartenance` varchar(30) NOT NULL COMMENT 'Table d''appartenance',
  `nom` varchar(20) NOT NULL COMMENT 'Nom de l''image dans le dossier files',
  PRIMARY KEY (`ImagesId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=7 ;

--
-- Dumping data for table `ImagesTab`
--

INSERT INTO `ImagesTab` (`ImagesId`, `ObjectId`, `Table_appartenance`, `nom`) VALUES
(1, 2, 'ImmobilierTab', '4_2_1.jpg'),
(2, 2, 'ImmobilierTab', '4_2_2.jpg'),
(3, 2, 'ImmobilierTab', '4_2_3.gif'),
(4, 1, 'AutoTab', '1_1_1.gif'),
(5, 1, 'AutoTab', '1_1_2.gif'),
(6, 1, 'AutoTab', '1_1_3.gif');

-- --------------------------------------------------------

--
-- Table structure for table `ImmobilierTab`
--

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
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `ImmobilierTab`
--

INSERT INTO `ImmobilierTab` (`ImmobilierId`, `UserId`, `Immobilier_nom`, `Immobilier_desc`, `ObjTyp`, `Date_ins`, `Immobilier_prix`, `VilleId`, `Date_modif`, `RubriqueId`) VALUES
(1, 1, 'Recherhe chambre a louer', '-Pret a payer beaucoup pour cela\r\n- Je vie seule\r\n- Comme un ...\r\n- Merci bien\r\n-Cordialement', 11, '2012-02-10 09:18:17', 125.00, 27, '2012-02-18 00:00:00', 4),
(2, 1, 'Jolie immeuble ', '- 4 etages\r\n- 3 chambres par etage\r\n- Une cusine par etage', 0, '2012-02-18 00:00:00', 90000000.00, 188, '2012-02-18 00:00:00', 4);

-- --------------------------------------------------------

--
-- Table structure for table `JobTab`
--

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
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `log`
--

CREATE TABLE IF NOT EXISTS `log` (
  `id` bigint(10) NOT NULL AUTO_INCREMENT,
  `iduser` int(8) DEFAULT NULL,
  `macaddr` varchar(16) DEFAULT NULL,
  `datel` datetime DEFAULT NULL,
  `url` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=190 ;

--
-- Dumping data for table `log`
--

INSERT INTO `log` (`id`, `iduser`, `macaddr`, `datel`, `url`) VALUES
(1, 0, '127.0.0.1', '2012-02-10 06:55:00', '/shop4all.de/index.php'),
(2, 0, '127.0.0.1', '2012-02-10 06:57:27', '/shop4all.de/connect.php'),
(3, 0, '127.0.0.1', '2012-02-10 06:57:36', '/shop4all.de/inscription.php'),
(4, 0, '127.0.0.1', '2012-02-10 06:58:26', '/shop4all.de/index.php'),
(5, 0, '127.0.0.1', '2012-02-10 06:58:59', '/shop4all.de/createVille.php'),
(6, 0, '127.0.0.1', '2012-02-10 06:59:09', '/shop4all.de/inscription.php'),
(7, 0, '127.0.0.1', '2012-02-10 06:59:33', '/shop4all.de/inscription.php'),
(8, 0, '127.0.0.1', '2012-02-10 07:04:27', '/shop4all.de/aide.php'),
(9, 0, '127.0.0.1', '2012-02-10 07:19:31', '/shop4all.de/index.php'),
(10, 0, '127.0.0.1', '2012-02-10 07:19:33', '/shop4all.de/insertion.php'),
(11, 0, '127.0.0.1', '2012-02-10 07:19:35', '/shop4all.de/mon_shop.php'),
(12, 0, '127.0.0.1', '2012-02-10 07:20:05', '/shop4all.de/aide.php'),
(13, 0, '127.0.0.1', '2012-02-10 07:22:08', '/shop4all.de/les_annonces.php'),
(14, 0, '127.0.0.1', '2012-02-10 07:22:10', '/shop4all.de/index.php'),
(15, 0, '127.0.0.1', '2012-02-10 07:22:13', '/shop4all.de/insertion.php'),
(16, 0, '127.0.0.1', '2012-02-10 07:22:14', '/shop4all.de/mon_shop.php'),
(17, 0, '127.0.0.1', '2012-02-10 07:22:16', '/shop4all.de/aide.php'),
(18, 0, '127.0.0.1', '2012-02-10 07:22:18', '/shop4all.de/mon_shop.php'),
(19, 0, '127.0.0.1', '2012-02-10 07:27:52', '/shop4all.de/mon_shop.php'),
(20, 0, '127.0.0.1', '2012-02-10 07:27:55', '/shop4all.de/aide.php'),
(21, 0, '127.0.0.1', '2012-02-10 07:27:57', '/shop4all.de/index.php'),
(22, 0, '192.168.1.4', '2012-02-10 07:29:42', '/shop4all.de/index.php'),
(23, 0, '127.0.0.1', '2012-02-10 07:30:14', '/shop4all.de/mon_shop.php'),
(24, 0, '127.0.0.1', '2012-02-10 07:30:16', '/shop4all.de/insertion.php'),
(25, 0, '127.0.0.1', '2012-02-10 07:30:18', '/shop4all.de/index.php'),
(26, 0, '127.0.0.1', '2012-02-10 07:30:20', '/shop4all.de/insertion.php'),
(27, 0, '127.0.0.1', '2012-02-10 07:30:21', '/shop4all.de/les_annonces.php'),
(28, 0, '127.0.0.1', '2012-02-10 07:30:23', '/shop4all.de/mon_shop.php'),
(29, 0, '127.0.0.1', '2012-02-10 07:40:00', '/shop4all.de/confirm.php'),
(30, 0, '127.0.0.1', '2012-02-10 07:40:46', '/shop4all.de/confirm.php'),
(31, 0, '127.0.0.1', '2012-02-10 07:47:24', '/shop4all.de/mon_shop.php'),
(32, 0, '127.0.0.1', '2012-02-10 07:47:26', '/shop4all.de/les_annonces.php'),
(33, 0, '127.0.0.1', '2012-02-10 08:16:57', '/shop4all.de/index.php'),
(34, 0, '127.0.0.1', '2012-02-10 08:40:16', '/shop4all.de/insertion.php'),
(35, 0, '127.0.0.1', '2012-02-10 08:40:22', '/shop4all.de/formulaire.php'),
(36, 0, '127.0.0.1', '2012-02-10 08:40:49', '/shop4all.de/treatinsertion.php'),
(37, 0, '127.0.0.1', '2012-02-10 08:41:07', '/shop4all.de/connect.php'),
(38, 1, '127.0.0.1', '2012-02-10 08:41:10', '/shop4all.de/visualise.php'),
(39, 1, '127.0.0.1', '2012-02-10 08:42:53', '/shop4all.de/a.php'),
(40, 1, '127.0.0.1', '2012-02-10 08:45:01', '/shop4all.de/a.php'),
(41, 0, '127.0.0.1', '2012-02-10 08:48:51', '/shop4all.de/disconnect.php'),
(42, 0, '127.0.0.1', '2012-02-10 08:48:52', '/shop4all.de/connect.php'),
(43, 0, '127.0.0.1', '2012-02-10 08:48:53', '/shop4all.de/connect.php'),
(44, 0, '127.0.0.1', '2012-02-10 08:48:55', '/shop4all.de/connect.php'),
(45, 0, '127.0.0.1', '2012-02-10 08:49:43', '/shop4all.de/connect.php'),
(46, 0, '127.0.0.1', '2012-02-10 08:49:46', '/shop4all.de/connect.php'),
(47, 0, '127.0.0.1', '2012-02-10 08:50:02', '/shop4all.de/connect.php'),
(48, 0, '127.0.0.1', '2012-02-10 08:50:07', '/shop4all.de/connect.php'),
(49, 0, '127.0.0.1', '2012-02-10 08:52:56', '/shop4all.de/inscription.php'),
(50, 0, '127.0.0.1', '2012-02-10 08:56:36', '/shop4all.de/test.php'),
(51, 0, '127.0.0.1', '2012-02-10 08:59:23', '/shop4all.de/test.php'),
(52, 0, '127.0.0.1', '2012-02-10 09:00:19', '/shop4all.de/test.php'),
(53, 0, '127.0.0.1', '2012-02-10 09:10:15', '/shop4all.de/insertion.php'),
(54, 0, '127.0.0.1', '2012-02-10 09:14:57', '/shop4all.de/les_annonces.php'),
(55, 0, '127.0.0.1', '2012-02-10 09:14:58', '/shop4all.de/insertion.php'),
(56, 0, '127.0.0.1', '2012-02-10 09:15:12', '/shop4all.de/connect.php'),
(57, 0, '127.0.0.1', '2012-02-10 09:15:15', '/shop4all.de/connect.php'),
(58, 0, '127.0.0.1', '2012-02-10 09:15:32', '/shop4all.de/connect.php'),
(59, 0, '127.0.0.1', '2012-02-10 09:16:22', '/shop4all.de/index.php'),
(60, 0, '127.0.0.1', '2012-02-10 09:16:23', '/shop4all.de/les_annonces.php'),
(61, 0, '127.0.0.1', '2012-02-10 09:23:21', '/shop4all.de/index.php'),
(62, 0, '127.0.0.1', '2012-02-10 09:23:24', '/shop4all.de/les_annonces.php'),
(63, 0, '127.0.0.1', '2012-02-10 09:23:25', '/shop4all.de/insertion.php'),
(64, 0, '127.0.0.1', '2012-02-10 09:29:10', '/shop4all.de/les_annonces.php'),
(65, 0, '127.0.0.1', '2012-02-18 09:19:57', '/shop4all.de/index.php'),
(66, 0, '127.0.0.1', '2012-02-18 09:20:11', '/shop4all.de/index.php'),
(67, 0, '127.0.0.1', '2012-02-18 09:20:23', '/shop4all.de/index.php'),
(68, 0, '127.0.0.1', '2012-02-18 09:20:31', '/shop4all.de/visualise.php'),
(69, 0, '127.0.0.1', '2012-02-18 09:20:35', '/shop4all.de/fullview.php'),
(70, 0, '127.0.0.1', '2012-02-18 09:26:00', '/shop4all.de/visualise.php'),
(71, 0, '127.0.0.1', '2012-02-18 09:29:20', '/shop4all.de/insertion.php'),
(72, 0, '127.0.0.1', '2012-02-18 09:29:27', '/shop4all.de/formulaire.php'),
(73, 0, '127.0.0.1', '2012-02-18 09:29:29', '/shop4all.de/insertion.php'),
(74, 0, '127.0.0.1', '2012-02-18 09:29:37', '/shop4all.de/formulaire.php'),
(75, 0, '127.0.0.1', '2012-02-18 09:57:15', '/shop4all.de/visualise.php'),
(76, 0, '127.0.0.1', '2012-02-18 09:57:20', '/shop4all.de/fullview.php'),
(77, 0, '127.0.0.1', '2012-02-18 09:57:30', '/shop4all.de/index.php'),
(78, 0, '127.0.0.1', '2012-02-18 09:57:32', '/shop4all.de/visualise.php'),
(79, 0, '127.0.0.1', '2012-02-18 09:57:37', '/shop4all.de/fullview.php'),
(80, 0, '127.0.0.1', '2012-02-18 09:58:32', '/shop4all.de/fullview.php'),
(81, 0, '127.0.0.1', '2012-02-18 09:58:47', '/shop4all.de/fullview.php'),
(82, 0, '127.0.0.1', '2012-02-18 10:09:24', '/shop4all.de/index.php'),
(83, 0, '127.0.0.1', '2012-02-18 10:09:26', '/shop4all.de/visualise.php'),
(84, 0, '127.0.0.1', '2012-02-18 10:09:28', '/shop4all.de/fullview.php'),
(85, 0, '127.0.0.1', '2012-02-18 10:11:00', '/shop4all.de/fullview.php'),
(86, 0, '127.0.0.1', '2012-02-18 10:11:46', '/shop4all.de/fullview.php'),
(87, 0, '127.0.0.1', '2012-02-18 10:24:47', '/shop4all.de/fullview.php'),
(88, 0, '127.0.0.1', '2012-02-18 10:26:22', '/shop4all.de/fullview.php'),
(89, 0, '127.0.0.1', '2012-02-18 10:26:40', '/shop4all.de/fullview.php'),
(90, 0, '127.0.0.1', '2012-02-18 10:27:22', '/shop4all.de/fullview.php'),
(91, 0, '127.0.0.1', '2012-02-18 10:28:00', '/shop4all.de/fullview.php'),
(92, 0, '127.0.0.1', '2012-02-18 10:30:53', '/shop4all.de/fullview.php'),
(93, 0, '127.0.0.1', '2012-02-18 10:32:20', '/shop4all.de/fullview.php'),
(94, 0, '127.0.0.1', '2012-02-18 10:34:34', '/shop4all.de/fullview.php'),
(95, 0, '127.0.0.1', '2012-02-18 10:35:09', '/shop4all.de/connect.php'),
(96, 0, '127.0.0.1', '2012-02-18 10:35:13', '/shop4all.de/connect.php'),
(97, 1, '127.0.0.1', '2012-02-18 10:35:15', '/shop4all.de/mon_shop.php'),
(98, 1, '127.0.0.1', '2012-02-18 10:35:18', '/shop4all.de/editinsertion.php'),
(99, 1, '127.0.0.1', '2012-02-18 10:36:01', '/shop4all.de/editinsertion.php'),
(100, 1, '127.0.0.1', '2012-02-18 10:36:08', '/shop4all.de/visualise.php'),
(101, 1, '127.0.0.1', '2012-02-18 10:36:13', '/shop4all.de/fullview.php'),
(102, 1, '127.0.0.1', '2012-02-18 10:40:15', '/shop4all.de/fullview.php'),
(103, 1, '127.0.0.1', '2012-02-18 10:40:46', '/shop4all.de/fullview.php'),
(104, 1, '127.0.0.1', '2012-02-18 10:41:18', '/shop4all.de/fullview.php'),
(105, 1, '127.0.0.1', '2012-02-18 10:41:21', '/shop4all.de/fullview.php'),
(106, 1, '127.0.0.1', '2012-02-18 10:42:01', '/shop4all.de/fullview.php'),
(107, 1, '127.0.0.1', '2012-02-18 10:46:30', '/shop4all.de/fullview.php'),
(108, 1, '127.0.0.1', '2012-02-18 10:46:50', '/shop4all.de/fullview.php'),
(109, 1, '127.0.0.1', '2012-02-18 10:49:15', '/shop4all.de/fullview.php'),
(110, 1, '127.0.0.1', '2012-02-18 10:50:19', '/shop4all.de/fullview.php'),
(111, 1, '127.0.0.1', '2012-02-18 10:50:39', '/shop4all.de/fullview.php'),
(112, 1, '127.0.0.1', '2012-02-18 10:51:21', '/shop4all.de/fullview.php'),
(113, 1, '127.0.0.1', '2012-02-18 10:52:15', '/shop4all.de/fullview.php'),
(114, 1, '127.0.0.1', '2012-02-18 10:58:49', '/shop4all.de/fullview.php'),
(115, 1, '127.0.0.1', '2012-02-18 11:01:30', '/shop4all.de/fullview.php'),
(116, 1, '127.0.0.1', '2012-02-18 11:03:58', '/shop4all.de/fullview.php'),
(117, 1, '127.0.0.1', '2012-02-18 11:05:20', '/shop4all.de/fullview.php'),
(118, 1, '127.0.0.1', '2012-02-18 11:05:38', '/shop4all.de/fullview.php'),
(119, 1, '127.0.0.1', '2012-02-18 11:06:50', '/shop4all.de/fullview.php'),
(120, 1, '127.0.0.1', '2012-02-18 11:07:02', '/shop4all.de/fullview.php'),
(121, 1, '127.0.0.1', '2012-02-18 11:07:54', '/shop4all.de/fullview.php'),
(122, 1, '127.0.0.1', '2012-02-18 11:08:44', '/shop4all.de/mon_shop.php'),
(123, 1, '127.0.0.1', '2012-02-18 11:08:46', '/shop4all.de/editinsertion.php'),
(124, 1, '127.0.0.1', '2012-02-18 11:09:00', '/shop4all.de/editinsertion.php'),
(125, 1, '127.0.0.1', '2012-02-18 11:09:03', '/shop4all.de/fullview.php'),
(126, 1, '127.0.0.1', '2012-02-18 11:09:05', '/shop4all.de/index.php'),
(127, 1, '127.0.0.1', '2012-02-18 11:09:07', '/shop4all.de/visualise.php'),
(128, 1, '127.0.0.1', '2012-02-18 11:09:16', '/shop4all.de/editinsertion.php'),
(129, 1, '127.0.0.1', '2012-02-18 11:11:56', '/shop4all.de/editinsertion.php'),
(130, 1, '127.0.0.1', '2012-02-18 11:12:00', '/shop4all.de/editinsertion.php'),
(131, 1, '127.0.0.1', '2012-02-18 11:12:04', '/shop4all.de/visualise.php'),
(132, 1, '127.0.0.1', '2012-02-18 11:12:07', '/shop4all.de/editinsertion.php'),
(133, 1, '127.0.0.1', '2012-02-18 11:12:19', '/shop4all.de/insertion.php'),
(134, 1, '127.0.0.1', '2012-02-18 11:12:31', '/shop4all.de/formulaire.php'),
(135, 1, '127.0.0.1', '2012-02-18 11:13:56', '/shop4all.de/treatinsertion.php'),
(136, 1, '127.0.0.1', '2012-02-18 11:13:58', '/shop4all.de/visualise.php'),
(137, 1, '127.0.0.1', '2012-02-18 11:14:01', '/shop4all.de/editinsertion.php'),
(138, 1, '127.0.0.1', '2012-02-18 11:14:06', '/shop4all.de/mon_shop.php'),
(139, 1, '127.0.0.1', '2012-02-18 11:14:08', '/shop4all.de/fullview.php'),
(140, 1, '127.0.0.1', '2012-02-18 11:16:12', '/shop4all.de/fullview.php'),
(141, 1, '127.0.0.1', '2012-02-18 11:17:57', '/shop4all.de/fullview.php'),
(142, 1, '127.0.0.1', '2012-02-18 11:18:41', '/shop4all.de/fullview.php'),
(143, 1, '127.0.0.1', '2012-02-18 11:19:01', '/shop4all.de/fullview.php'),
(144, 1, '127.0.0.1', '2012-02-18 11:19:17', '/shop4all.de/fullview.php'),
(145, 1, '127.0.0.1', '2012-02-18 11:19:33', '/shop4all.de/fullview.php'),
(146, 1, '127.0.0.1', '2012-02-18 11:20:33', '/shop4all.de/insertion.php'),
(147, 1, '127.0.0.1', '2012-02-18 11:20:34', '/shop4all.de/mon_shop.php'),
(148, 1, '127.0.0.1', '2012-02-18 11:20:37', '/shop4all.de/editinsertion.php'),
(149, 1, '127.0.0.1', '2012-02-18 11:20:55', '/shop4all.de/editinsertion.php'),
(150, 1, '127.0.0.1', '2012-02-18 11:20:58', '/shop4all.de/visualise.php'),
(151, 1, '127.0.0.1', '2012-02-18 11:21:06', '/shop4all.de/editinsertion.php'),
(152, 1, '127.0.0.1', '2012-02-18 11:21:22', '/shop4all.de/editinsertion.php'),
(153, 1, '127.0.0.1', '2012-02-18 11:21:24', '/shop4all.de/visualise.php'),
(154, 1, '127.0.0.1', '2012-02-18 11:21:26', '/shop4all.de/fullview.php'),
(155, 1, '127.0.0.1', '2012-02-18 11:39:46', '/shop4all.de/fullview.php'),
(156, 1, '127.0.0.1', '2012-02-18 11:41:10', '/shop4all.de/fullview.php'),
(157, 1, '127.0.0.1', '2012-02-18 11:43:37', '/shop4all.de/fullview.php'),
(158, 1, '127.0.0.1', '2012-02-18 11:44:08', '/shop4all.de/fullview.php'),
(159, 1, '127.0.0.1', '2012-02-18 11:44:33', '/shop4all.de/fullview.php'),
(160, 1, '127.0.0.1', '2012-02-18 11:44:52', '/shop4all.de/fullview.php'),
(161, 1, '127.0.0.1', '2012-02-18 11:45:23', '/shop4all.de/fullview.php'),
(162, 1, '127.0.0.1', '2012-02-18 11:47:22', '/shop4all.de/fullview.php'),
(163, 1, '127.0.0.1', '2012-02-18 11:47:46', '/shop4all.de/fullview.php'),
(164, 1, '127.0.0.1', '2012-02-18 11:48:02', '/shop4all.de/fullview.php'),
(165, 1, '127.0.0.1', '2012-02-18 11:51:08', '/shop4all.de/fullview.php'),
(166, 1, '127.0.0.1', '2012-02-18 11:51:42', '/shop4all.de/fullview.php'),
(167, 1, '127.0.0.1', '2012-02-18 11:52:26', '/shop4all.de/fullview.php'),
(168, 1, '127.0.0.1', '2012-02-18 11:52:50', '/shop4all.de/fullview.php'),
(169, 1, '127.0.0.1', '2012-02-18 11:59:13', '/shop4all.de/fullview.php'),
(170, 1, '127.0.0.1', '2012-02-18 11:59:58', '/shop4all.de/fullview.php'),
(171, 0, '127.0.0.1', '2012-02-22 14:15:58', '/shop4all.de/index.php'),
(172, 0, '127.0.0.1', '2012-02-22 14:39:06', '/shop4all.de/insertion.php'),
(173, 0, '127.0.0.1', '2012-02-22 14:39:26', '/shop4all.de/les_annonces.php'),
(174, 0, '127.0.0.1', '2012-02-22 14:40:34', '/shop4all.de/mon_shop.php'),
(175, 0, '127.0.0.1', '2012-02-22 14:40:35', '/shop4all.de/insertion.php'),
(176, 0, '127.0.0.1', '2012-02-22 14:40:37', '/shop4all.de/les_annonces.php'),
(177, 0, '127.0.0.1', '2012-02-22 14:41:05', '/shop4all.de/insertion.php'),
(178, 0, '127.0.0.1', '2012-02-22 14:41:16', '/shop4all.de/formulaire.php'),
(179, 0, '127.0.0.1', '2012-02-22 14:41:27', '/shop4all.de/treatinsertion.php'),
(180, 0, '127.0.0.1', '2012-02-22 14:41:29', '/shop4all.de/les_annonces.php'),
(181, 0, '127.0.0.1', '2012-02-22 14:41:37', '/shop4all.de/insertion.php'),
(182, 0, '127.0.0.1', '2012-02-22 14:41:40', '/shop4all.de/connect.php'),
(183, 0, '127.0.0.1', '2012-02-22 14:42:02', '/shop4all.de/connect.php'),
(184, 1, '127.0.0.1', '2012-02-22 14:42:03', '/shop4all.de/index.php'),
(185, 1, '127.0.0.1', '2012-02-22 14:42:05', '/shop4all.de/insertion.php'),
(186, 1, '127.0.0.1', '2012-02-22 14:42:14', '/shop4all.de/formulaire.php'),
(187, 1, '127.0.0.1', '2012-02-22 14:44:12', '/shop4all.de/treatinsertion.php'),
(188, 1, '127.0.0.1', '2012-02-22 14:44:14', '/shop4all.de/visualise.php'),
(189, 1, '127.0.0.1', '2012-02-22 14:44:17', '/shop4all.de/fullview.php');

-- --------------------------------------------------------

--
-- Table structure for table `MeubleTab`
--

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
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `NewsLetterTab`
--

CREATE TABLE IF NOT EXISTS `NewsLetterTab` (
  `NewsLetterId` int(11) NOT NULL AUTO_INCREMENT,
  `NewsLetter_mail` varchar(30) NOT NULL,
  PRIMARY KEY (`NewsLetterId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `NewsLetterTab`
--

INSERT INTO `NewsLetterTab` (`NewsLetterId`, `NewsLetter_mail`) VALUES
(1, 'f@f.rt');

-- --------------------------------------------------------

--
-- Table structure for table `noconfinscrit`
--

CREATE TABLE IF NOT EXISTS `noconfinscrit` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `UserId` int(11) NOT NULL COMMENT 'iduser qui ne veux as confirmer son insertion',
  `nofois` int(11) NOT NULL COMMENT 'nombre de fois que ce user recoit le mail de confirmation',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COMMENT='Conserve les users qui ne veulent pas confirmer leur inscrip' AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `noconfinsert`
--

CREATE TABLE IF NOT EXISTS `noconfinsert` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'id',
  `UserId` int(11) NOT NULL COMMENT 'iduser  qui ne veux pas confirmer son insertion',
  `RubriqueId` int(11) NOT NULL COMMENT 'Id de la rubrique auquel appartient l''objet inserer non confirmer',
  `ObjectId` int(11) NOT NULL COMMENT 'id de l''objet dont l''insetion n''as pas été confirmer',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 COMMENT='Conserve la trace des users qui insere et ne confirme pas le' AUTO_INCREMENT=3 ;

--
-- Dumping data for table `noconfinsert`
--

INSERT INTO `noconfinsert` (`id`, `UserId`, `RubriqueId`, `ObjectId`) VALUES
(1, 1, 4, 2),
(2, 1, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `ObjArtTab`
--

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
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProdAgrTab`
--

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
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `ProvinceTab`
--

CREATE TABLE IF NOT EXISTS `ProvinceTab` (
  `ProvinceId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Province_nom` varchar(30) NOT NULL,
  PRIMARY KEY (`ProvinceId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=11 ;

--
-- Dumping data for table `ProvinceTab`
--

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

-- --------------------------------------------------------

--
-- Table structure for table `RubriqueTab`
--

CREATE TABLE IF NOT EXISTS `RubriqueTab` (
  `RubriqueId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Rubrique_nom` varchar(40) DEFAULT NULL,
  `tab` varchar(20) NOT NULL COMMENT 'La table MySQL correspondiquesant aux rubr',
  PRIMARY KEY (`RubriqueId`),
  KEY `Rubrique_nom` (`Rubrique_nom`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `RubriqueTab`
--

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

-- --------------------------------------------------------

--
-- Table structure for table `UserTab`
--

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
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `UserTab`
--

INSERT INTO `UserTab` (`UserId`, `VilleId`, `User_pseudo`, `User_nom`, `User_prenom`, `Date_Ins`, `Date_modif`, `User_email`, `User_tel`, `User_pw`, `User_nletter`, `User_etat`, `User_inscrit`) VALUES
(1, 11, 'f', 'f', 'f', '2012-02-10', '2012-02-10', 'f@f.rt', '1', '*241E241B694B4F0B740CF5B9775AFD9A511E1CEC', 1, 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `VilleTab`
--

CREATE TABLE IF NOT EXISTS `VilleTab` (
  `VilleId` bigint(20) NOT NULL AUTO_INCREMENT,
  `Ville_nom` varchar(40) NOT NULL,
  `ProvinceId` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`VilleId`),
  KEY `ProvinceId` (`ProvinceId`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=333 ;

--
-- Dumping data for table `VilleTab`
--

INSERT INTO `VilleTab` (`VilleId`, `Ville_nom`, `ProvinceId`) VALUES
(1, 'Abong-Mbang', 1),
(2, 'Afanloum', 2),
(3, 'Ako', 3),
(4, 'Akoeman', 2),
(5, 'Akom II', 4),
(6, 'Akono', 2),
(7, 'Akonolinga', 2),
(8, 'Akwaya', 5),
(9, 'Alou', 5),
(10, 'Ambam', 4),
(11, 'Andek', 3),
(12, 'Angossas', 1),
(13, 'Atok', 1),
(14, 'Awa&eacute;', 2),
(15, 'Ayos', 2),
(16, 'Babadjou', 6),
(17, 'Babessi', 3),
(18, 'Babouantou', 6),
(19, 'Bafang', 6),
(20, 'Bafia', 2),
(21, 'Bafou', 6),
(22, 'Bafoussam', 6),
(23, 'Bafut', 3),
(24, 'Baham', 6),
(25, 'Bali', 3),
(26, 'Balikumbat', 3),
(27, 'Bamenda', 3),
(28, 'Bamendjou', 6),
(29, 'Bamuso', 5),
(30, 'Bana', 6),
(31, 'Bandja', 6),
(32, 'Bandjoun', 6),
(33, 'Bangangt&eacute;', 6),
(34, 'Bangem', 5),
(35, 'Banka', 6),
(36, 'Bangou', 6),
(37, 'Bangourain', 6),
(38, 'Bankim', 7),
(39, 'Banyo', 7),
(40, 'Bar&eacute;', 8),
(41, 'Bash&eacute;o', 9),
(42, 'Bassamba', 6),
(43, 'Batcham', 6),
(44, 'Batchenga', 2),
(45, 'Batibo', 3),
(46, 'Bati&eacute;', 6),
(47, 'Batoufam', 6),
(48, 'Batouri', 1),
(49, 'Bayangam', 6),
(50, 'Bazou', 6),
(51, 'Beka', 9),
(52, 'B&eacute;labo', 1),
(53, 'Belel', 7),
(54, 'Belo', 3),
(55, 'Benakuma', 3),
(56, 'Bengbis', 4),
(57, 'Bertoua', 1),
(58, 'B&eacute;tar&eacute;-Oya', 1),
(59, 'Bibemi', 9),
(60, 'Bibey', 2),
(61, 'Bidjouka', 4),
(62, 'Bikok', 2),
(63, 'Bipindi', 4),
(64, 'Biwong-Bane', 4),
(65, 'Biwong-Bulu', 4),
(66, 'Biyouha', 2),
(67, 'Blangoua', 10),
(68, 'Bokito', 2),
(69, 'Bonal&eacute;a', 8),
(70, 'Bondjock', 2),
(71, 'Bot-Makak', 2),
(72, 'Bourrha', 10),
(73, 'Bu&eacute;a', 5),
(74, 'Campo', 4),
(75, 'Dargala', 10),
(76, 'Darak', 10),
(77, 'Datcheka', 10),
(78, 'Dembo', 9),
(79, 'Demding', 6),
(80, 'Deuk', 2),
(81, 'Diang', 1),
(82, 'Dibamba', 8),
(83, 'Dibang', 2),
(84, 'Dibombari', 8),
(85, 'Dikome-Balue', 5),
(86, 'Dimako', 1),
(87, 'Dir', 7),
(88, 'Dizangu&eacute;', 8),
(89, 'Djohong', 7),
(90, 'Djoum', 4),
(91, 'Douala', 8),
(92, 'Doumaintang', 1),
(93, 'Doum&eacute;', 1),
(94, 'Dschang', 6),
(95, 'Dzeng', 2),
(96, 'Dziguilao', 10),
(97, 'Ebebda', 2),
(98, 'Ebolowa', 4),
(99, 'Ebone', 8),
(100, '&eacute;d&eacute;a', 8),
(101, 'Edzendouan', 2),
(102, 'Efoulan', 4),
(103, 'Ekondo-Titi', 5),
(104, 'Elak-Oku', 3),
(105, 'Elig-Mfomo', 2),
(106, 'Endom', 2),
(107, '&eacute;s&eacute;ka', 2),
(108, 'Esse', 2),
(109, 'Evodoula', 2),
(110, 'Eyumodjock', 5),
(111, 'Figuil', 9),
(112, 'Fondjomekwet', 6),
(113, 'Fokou&eacute;', 6),
(114, 'Fonfuka', 3),
(115, 'Fongo-Tongo', 6),
(116, 'Fotokol', 10),
(117, 'Foumban', 6),
(118, 'Foumbot', 6),
(119, 'Fundong', 3),
(120, 'Furu-Awa', 3),
(121, 'Galim', 6),
(122, 'Galim-Tign&egrave;re', 7),
(123, 'Gari-Gombo', 1),
(124, 'Garoua', 9),
(125, 'Garoua-Boula&iuml;', 1),
(126, 'Gashiga', 9),
(127, 'Gawaza', 10),
(128, 'Gobo', 10),
(129, 'Goulfey', 10),
(130, 'Gueme', 10),
(131, 'Guere', 10),
(132, 'Guider', 9),
(133, 'Guidiguis', 10),
(134, 'Hile-Alifa', 10),
(135, 'Hina', 10),
(136, 'Idabato', 5),
(137, 'Idenau', 5),
(138, 'Isanguele', 5),
(139, 'Jakiri', 3),
(140, 'Ka&eacute;l&eacute;', 10),
(141, 'Kai-Kai', 10),
(142, 'Kalfou', 10),
(143, 'Kay-Hay', 10),
(144, 'K&eacute;kem', 6),
(145, 'Kentzou', 1),
(146, 'Kette', 1),
(147, 'Kiiki', 2),
(148, 'Kobdombo', 2),
(149, 'Kolofata', 10),
(150, 'Kombo-Abedimo', 5),
(151, 'Kombo-Idinti', 5),
(152, 'Kon-Yambetta', 2),
(153, 'Kongso-Bamougoum', 6),
(154, 'Kontcha', 7),
(155, 'Konye', 5),
(156, 'Kouoptamo', 6),
(157, 'Kouss&eacute;ri', 10),
(158, 'Koutaba', 6),
(159, 'Koza', 10),
(160, 'Kribi', 4),
(161, 'Kumba', 5),
(162, 'Kumbo', 3),
(163, 'Laf&eacute;-Baleng', 6),
(164, 'Lagdo', 9),
(165, 'Lembe-Yezoum', 2),
(166, 'Limb&eacute;', 5),
(167, 'Lobo', 2),
(168, 'Logone-Birni', 10),
(169, 'Lokoundje', 4),
(170, 'Lolodorf', 4),
(171, 'Lomi&eacute;', 1),
(172, 'Loum', 8),
(173, 'Ma''an', 4),
(174, 'Mabanga', 7),
(175, 'Maga', 10),
(176, 'Magba', 6),
(177, 'Maikari', 10),
(178, 'Makak', 2),
(179, 'Mak&eacute;n&eacute;n&eacute;', 2),
(180, 'Malentouen', 6),
(181, 'Mamf&eacute;', 5),
(182, 'Mandingring', 9),
(183, 'Mandjou', 1),
(184, 'Manjo', 8),
(185, 'Manoka', 8),
(186, 'Maroua', 10),
(187, 'Massangam', 6),
(188, 'Massock', 8),
(189, 'Matomb', 2),
(190, 'Mayo-Bal&eacute;o', 7),
(191, 'Mayo-Darl&eacute;', 7),
(192, 'Mayo-Hourna', 9),
(193, 'Mayo-Oulo', 9),
(194, 'Mbalmayo', 2),
(195, 'Mbandjock', 2),
(196, 'Mbang', 1),
(197, 'Mbanga', 8),
(198, 'Mbangassina', 2),
(199, 'Mbankomo', 2),
(200, 'Mbe', 7),
(201, 'Mbengwi', 3),
(202, 'Mbiame', 3),
(203, 'Mboma', 1),
(204, 'Mbonge', 5),
(205, 'Mbouda', 6),
(206, 'Meiganga', 7),
(207, 'Melong', 8),
(208, 'Mengang', 2),
(209, 'Mengong', 4),
(210, 'Mengueme', 2),
(211, 'Menji', 5),
(212, 'Meri', 10),
(213, 'Messamena', 1),
(214, 'Messok', 1),
(215, 'Messondo', 2),
(216, 'Meyomessala', 4),
(217, 'Meyomessi', 4),
(218, 'Mfou', 2),
(219, 'Mindif', 10),
(220, 'Mindourou', 1),
(221, 'Minta', 2),
(222, 'Mintom', 4),
(223, 'Misaje', 3),
(224, 'Modzogo', 10),
(225, 'Mogode', 10),
(226, 'Mokolo', 10),
(227, 'Moloundou', 1),
(228, 'Mombo', 8),
(229, 'Monat&eacute;l&eacute;', 2),
(230, 'Mora', 10),
(231, 'Mouanko', 8),
(232, 'Moulvoudaye', 10),
(233, 'Moutourwa', 10),
(234, 'Mudemba', 5),
(235, 'Muyuka', 5),
(236, 'Mvangane', 4),
(237, 'Mvengue', 4),
(238, 'Nanga-Eboko', 2),
(239, 'Ndelele', 1),
(240, 'Ndikinim&eacute;ki', 2),
(241, 'Ndobian', 8),
(242, 'Ndom', 8),
(243, 'Ndop', 3),
(244, 'Ndoukoula', 10),
(245, 'Ndu', 3),
(246, 'Nganha', 7),
(247, 'Ngamb&eacute;', 8),
(248, 'Ngamb&egrave;-Tikar', 2),
(249, 'Ngaoui', 7),
(250, 'Ngaoundal', 7),
(251, 'Ngaound&eacute;r&eacute;', 7),
(252, 'Ngog-Mapubi', 2),
(253, 'Ngomedzap', 2),
(254, 'Ngong', 9),
(255, 'Ngoro', 2),
(256, 'Ngoulemakong', 4),
(257, 'Ngoumou', 2),
(258, 'Ngoura', 1),
(259, 'Ngoyla', 1),
(260, 'Nguelebok', 1),
(261, 'Nguelemendouka', 1),
(262, 'Ngui-Bassal', 2),
(263, 'Ngwei', 8),
(264, 'Niete', 4),
(265, 'Nitoukou', 2),
(266, 'Njikwa', 3),
(267, 'Njimom', 6),
(268, 'Njinikom', 3),
(269, 'Njomb&eacute;', 8),
(270, 'Nkamb&eacute;', 3),
(271, 'Nkolafamba', 2),
(272, 'Nkolmetet', 2),
(273, 'Nkondjock', 8),
(274, 'Nkongsamba', 8),
(275, 'Nkong-Zem', 6),
(276, 'Nkor', 3),
(277, 'Nkoteng', 2),
(278, 'Nkum', 3),
(279, 'Nsem', 2),
(280, 'Ntui', 2),
(281, 'Nwa', 3),
(282, 'Nyambaka', 7),
(283, 'Nyanon', 8),
(284, 'Obala', 2),
(285, 'Okola', 2),
(286, 'Olamze', 4),
(287, 'Olanguina', 2),
(288, 'Ombessa', 2),
(289, 'Ouli', 1),
(290, 'Oveng', 4),
(291, 'Penja', 8),
(292, 'Penka-Michel', 6),
(293, 'Pett&eacute;', 10),
(294, 'Pitoa', 9),
(295, 'Poli', 9),
(296, 'Pouma', 8),
(297, 'Roua', 10),
(298, 'Sa''a', 2),
(299, 'Salapoumb&eacute;', 1),
(300, 'Sangm&eacute;lima', 4),
(301, 'Santa', 3),
(302, 'Santchou', 6),
(303, 'Soa', 2),
(304, 'Somalomo', 1),
(305, 'Tchati-Bali', 10),
(306, 'Tchollir&eacute;', 9),
(307, 'Tibati', 7),
(308, 'Tign&egrave;re', 7),
(309, 'Tiko', 5),
(310, 'Tinto', 5),
(311, 'Toko', 5),
(312, 'Tokomb&eacute;r&eacute;', 10),
(313, 'Tombel', 5),
(314, 'Tonga', 6),
(315, 'Touboro', 9),
(316, 'Touloum', 10),
(317, 'Touroua', 9),
(318, 'Tubah', 3),
(319, 'Wabane', 5),
(320, 'Wasa', 10),
(321, 'Widikum-Boffe', 3),
(322, 'Wina', 10),
(323, 'Wum', 3),
(324, 'Yabassi', 8),
(325, 'Yagoua', 10),
(326, 'Yaound&eacute;', 2),
(327, 'Yingui', 8),
(328, 'Yokadouma', 1),
(329, 'Yoko', 2),
(330, 'Zhoa', 3),
(331, 'Zina', 10),
(332, 'Zo&eacute;t&eacute;l&eacute;', 4);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
