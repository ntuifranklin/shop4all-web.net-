<?php 
       
        
	// Inclusion des fonctions pour usage
         include_once('includes/LesFontions.inc');
         inclusionClasses();
         keepLog();//Fonction qui garde une tracabilité des pages accédes par un internaute
         putConnect();//Fonction qui garde chaque la tracabilité de toute nouvelle ouverture du site par un internaute dans la base de données 

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr" dir="ltr">
<head>
	<title><?php echo stripslashes(stripslashes($_GET['tit'])); ?></title>

	<!-- Contents -->
	<!-- <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />  -->
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<meta http-equiv="Content-Language" content="fr" />
	<meta http-equiv="last-modified" content="28.11.2011 07:00:28" />
	<meta http-equiv="Content-Type-Script" content="text/javascript" />
	<meta name="description" content="Site d'insertion rapide et gratuite" />
	<meta name="keywords" content="insertion, voitures, automobiles, meubles, agriculture, " />
	<!-- imCustomHead -->
	<meta http-equiv="Expires" content="0" />
	<meta name="Resource-Type" content="document" />
	<meta name="Distribution" content="global" />
	<meta name="Robots" content="index, follow" />
	<meta name="Revisit-After" content="21 days" />
	<meta name="Rating" content="general" />
	<!-- Others -->
	<meta name="Generator" content="Incomedia WebSite X5 Evolution 8.0.16 - www.websitex5.com" />
	<meta http-equiv="ImageToolbar" content="False" />
	<meta name="MSSmartTagsPreventParsing" content="True" />
	
	
	<!-- Parent -->
	<link rel="sitemap" href="imsitemap.html" title="Plan général du site" />

	<!-- This is for the icon image --> <link rel="icon" href="images/s1.gif" type="image/x-icon" /> 	<!-- End Icon image --> 

	<!-- Res -->
	<script type="text/javascript" src="res/x5engine.js"></script>
	<link rel="stylesheet" type="text/css" href="res/styles.css" media="screen, print" />
	<link rel="stylesheet" type="text/css" href="res/arrondis.css" media="screen, print" />
	<link rel="stylesheet" type="text/css" href="res/template.css" media="screen" />
	<link rel="stylesheet" type="text/css" href="res/print.css" media="print" />
	<!--[if lt IE 7]><link rel="stylesheet" type="text/css" href="res/iebehavior.css" media="screen" /><![endif]-->
	<link rel="stylesheet" type="text/css" href="res/p003.css" media="screen, print" />
	<link rel="stylesheet" type="text/css" href="res/handheld.css" media="handheld" />
	<link rel="alternate stylesheet" title="Contraste élevé - Accessibilité" type="text/css" href="res/accessibility.css" media="screen" />
        <!-- J'ajoute les style que vous pourez retire apres si bon vous semble. --> 
        <style>
                /* les lignes paires 2,4,6,8,... */
                table tr.even ,td.even,
                .even {
                    background: #b0c4de;
                    height:20px;	
                }

                /* Les choses sur les quelles ont survole */
                .odd:hover,
                .even:hover,
                .hover {
                    background:  #B0E0E6;
                    color: #000000;
                }

                /* Les lignes sur les quelles ont survole */
                table tr.odd:hover ,
                table tr.even:hover ,
                table tr.hover  {
                    background:    #B0E0E6;
                    color:   #000000;
                }

                /*** Les bordures des messages de reussite d'operation et d'echec d'operation ***/
                .good{
                  border:1px solid green;
                }

                .gm{
                  border:1px solid blue;
                }

                .bad{
                  border:1px solid red;
                }

		.infosobjet{
			border:1px solid green; width:500px;

		}

		.arrondis {
		border:1px solid #B0C4DE;
		background-color:green;
		-moz-border-radius:10px;
		-webkit-border-radius:10px;
		width:170px;
		}

        </style>

	<!-- Debut ajout script javascript -->

	<script language="JavaScript" type="text/JavaScript"  src="file.js" charset="iso-8879-1"></script>
	<!-- Fin ajout script javascript -->
        <!-- Fin des ajouts retirable -->



