<?php
	include_once('includes/header.inc');
	inclusionTete() ;
	/*
	$var = "provid" ;
	$provid = $_GET[$var] ; $np = $_GET['np'] ;
	echo "Province Id = $provid , nom de la province = $np <br>" ;
	$ville = new Ville();
	echo "Affichage de la liste des villes correspondant &agrave; cette province : <br> " ;
	echo $ville -> getVilleProvince($provid) ;
	//echo $ville -> listVilles();
	$q = "select * from noconfinsert";
	$r = execute($q);
	while( $l = mysql_fetch_assoc($r)){
		foreach($l as $field => $value)
		 echo "$field == $value <br>";
	}
	*/
	$o = new Object();
	echo $o -> getObjTyp("ImmobilierTab",1);//nt=ImmobilierTab&oid=1&nr=4
	inclusionPied() ;

?>
