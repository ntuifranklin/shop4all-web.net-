<?php
	include_once('includes/header.inc');
	inclusionTete() ;
	$var = "provid" ;
	$provid = $_GET[$var] ; $np = $_GET['np'] ;
	
	//echo $ville -> listVilles();
	$pro = new Province() ;$nomprovince =  $pro -> getProvinceFromId($provid) ;
        $obj = new Object();
        $t = $obj -> getTabs(); $nbs = array(); $lines = "";$T = $obj -> getRubriques();
        $lines  = "";
	$lines .= "<table>" ;
	$lines .= "<caption><font size=3 color=green><u>Insertions de toute les rubriques dans la province du/(de l') $nomprovince </u></font></caption>" ;
        for($i=1 ; $i<count($t) ; $i++){
                $nomtable = $t[$i] ;
		//On ajoute la condition pour empecher que les tables qui sauvagarde deux objets de types different ne s'affiche deux fois dans les rubriques correspondantes
		$norubr = $i ; $nomrubrique = $obj -> getNomRubrFromNo($norubr) ;
                $query = "select *  from $nomtable , VilleTab ,ProvinceTab where $nomtable.RubriqueId=$norubr " . 
		" and $nomtable.VilleId=VilleTab.VilleId and VilleTab.ProvinceId=$provid and ProvinceTab.ProvinceId=$provid";
                $res = execute($query);
                $nb = mysql_num_rows($res) ; 
                //$nbs[$i] = $l['nb'];
                if($nb > 0){
			$inserts = showUserInserts($nomtable, $query , $norubr) ;
                	$lines .= "<tr><td align=center> ". $inserts  . "</td></tr>";
			//echo $nb." lignes <br>" ;
			
                }else{
                	//$lines .= "<tr><td ><font size=2 color=red >Pas d'insertion dans la rubrique ".$nomrubrique ." </font></td></tr>";

		}

	}
	$lines .= "</table>" ;
	echo $lines ;

	inclusionPied() ;

?>
