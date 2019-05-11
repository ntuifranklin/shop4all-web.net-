<?php
	include_once('includes/header.inc');
	inclusionTete() ;
	$villes = array() ; $regions = array() ; $provinces = array() ;
	$array = file("cobai.txt") ;	
	foreach($array as $field => $value ){
		$ar = explode("</a>#=#", $array[$field] ) ;
		$arr = explode("#=#" , $ar[1]) ;
		$regions[] = $arr[0] ;
		$provinces[] = $arr[1] ;
		$v = explode("\">" ,$ar[0] );
		$villes[] = $v[1] ;
	}
	$chaine = "" ;
	for($i=0 ; $i < count($villes) ; $i++){
		echo "ville = ".$villes[$i] . " region = ".$regions[$i] . " provinces = ". $provinces[$i] . " <br>"  ;
		$chaine .= "" . $villes[$i] . "#" . $regions[$i] . "#" . $provinces[$i];
	}
	$fich = fopen("listesVilles.txt" , "w+") ;
	fwrite($fich , $chaine) ;
	fclose($fich) ;
	inclusionPied() ;

?>
