<?php

		//Le travail à faire est de verifier s'il existe au moins une insertion dans n'importe quel rubrique pour chaque province
		$provinces = array() ; $prov = new Province();
		$nomfichier = "provincesearch.php";
		$map  = array();$coord = ""; $provid = 0 ; $objet = new Object(); $tabs = $objet -> getTabs() ;
		$liste = file("area.inc");
		$area = "" ;
		for($i=0;$i<count($liste);$i++){
			$ligne = $liste[$i];
			$map = explode("#",$ligne);
			$provid = $map[0];$deja = 0 ; $nombre = 0;
			$coord = $map[1] ; $nomprovince = $prov -> getProvinceFromId($provid);$title = "" ;
			for($k=1;$k<count($tabs) + 1 ;$k++){
				$nomtable = $tabs[$k] ; $norubr = $k ;
				$q = "select *  from $nomtable , VilleTab ,ProvinceTab where $nomtable.RubriqueId=$norubr  and $nomtable.VilleId=VilleTab.VilleId".
				     " and VilleTab.ProvinceId=$provid and ProvinceTab.ProvinceId=$provid";
				$res = execute($q);
				if(mysql_num_rows($res) > 0){
							$deja = 1 ;
							$nombre = $nombre + mysql_num_rows($res) ;
				}

			}
			$param="?provid=$provid";
			//echo "Ligne no $i " . $ligne . "<br>" ;
			$title = "$nombre insertions dans cette province : $nomprovince , toutes rubriques confondu" ;
			 if($deja == 0 ){
				$nomfichier  = "#"; $coord = "" ; $param = "";

			 } 
			 $lien = "$nomfichier"."$param" ;
			 $area .= "\n<area shape='poly' href=\"$lien\" title=\"$title\" coords=\"$coord\" />" ;			
			 $nomfichier = "provincesearch.php";
		}
?>


<img src="cameroon-map.jpg" width="450" height="588" border="0" usemap="#map" />

<map name="map">
	<?php
		echo $area ;
	?>
</map>
