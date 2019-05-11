<?php
	$_GET['tit'] = "Recherche d'insertions par provinces";
	include_once('includes/header.inc');
	inclusionTete() ;//
	echo "<font color=blue size=4>Choisissez la province dont les insertions vous interesse</font><br>" ;
	include_once("includes/carte.inc") ;//Carte sur la quelle on clique pour voir insertions par povinces
	inclusionPied() ;

?>
