<?php

	//Creation des villes et provinces
	include_once('includes/header.inc');
	inclusionTete() ;

	$ville = new Ville();
	$province = new Province(); $provid = 0 ;
	$fichier = file("listesVilles.txt") ;
	foreach( $fichier as $field => $value){
		$ligne = explode("#" , $value);
		$provid = $ligne[2];
		$nomville = $ligne[0] ;
		$ville -> setNom($nomville);
		$ville -> setProvinceId($provid);
		$ville -> creer();
		
	}
	echo prmess("Action effectuer") ;
 	//echo "Listes des provinces : ". $province -> listProvinces() ;
 	//echo "Listes des villes : ". $ville ->listVilles() ;


	inclusionPied() ;

?>
