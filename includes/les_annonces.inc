<?php

        //On affiche les deux ou trois dernieres images inserers une par objet
        $pho = new Photo();
	$q = "select distinct Table_appartenance , ObjectId , ImagesId from ImagesTab group by Table_appartenance order by ImagesId desc " ;
	$result = execute($q); $Max = 5 ;
	if(mysql_num_rows($result) > 0){
		$i = 0 ;
		$objectIds = array(); $condition = " where ( " ;
	while($ligne = mysql_fetch_assoc($result) and $i < $Max){
		$objectIds[$i] = $ligne['Table_appartenance'] ;
		$condition .= " ( Table_appartenance=\"{$ligne['Table_appartenance']}\" and ObjectId={$ligne['ObjectId']} ) or " ;
		$i++ ;
	}
		$condition .= " 1=1 ) " ;
        $query = "select * from ImagesTab $condition group by Table_appartenance order by ImagesId desc ";
	//echo prmess("<br>Requete : $query <br>");
        $res = execute($query); $recent = ""; 
		if(mysql_num_rows($res)> 0){//S'il existe au moins une image alors on  l'affiche
		        $i = 0 ;$max = 6 ;
			$recent .= "<table cellspacing=10>";
		        while($l = mysql_fetch_assoc($res) ){
		                $i++ ;
		                $nomtable  = $l['Table_appartenance']; $objectid = $l['ObjectId']; $objet = new $nomtable();
				$inittable = str_replace("Tab","",$nomtable) ;//Pour les initiales de la table
		                if(! empty($nomtable)){
					//Le champ date est au format Y-m-d H:i:s. Donc pour avoir les insertions d'aujourd'hui il faudra trier la date avec date_format
		                        $q = "select * , date_format(Date_ins ,'%Y-%m-%d') as dateToday ,date_format(Date_ins ,'%H:%i:%s') as timeToday from $nomtable where ".$inittable."Id=".$objectid;
		                        $r = execute($q);
		                        $li = mysql_fetch_assoc($r); $rid = $li['RubriqueId']; $timeToday=$li['timeToday'];$dateToday = $li['dateToday']; $prix = $li[$inittable."_prix"] ; 
					$arraytitre = $objet -> getArrayTitreTable(); //Retourne un tableau contenant les champs pour representer les titre de l'objet
					$titreobjet = "";
					foreach($arraytitre as $field)
						$titreobjet .= stripslashes($li[$inittable."_".$field]);
		                        if(! empty($rid)){
		                                $re = execute("select * from RubriqueTab where RubriqueId=$rid");
		                                $lig = mysql_fetch_assoc($re); 
		                                $titter = $lig['Rubrique_nom'];
		                        }
		                }
				$recent .= "<tr>";
				$recent .= "<td>";
				$recent .= ($dateToday == date("Y-m-d")) ? "Aujourd'hui &agrave; $timeToday" : date("d-m-Y" ,strtotime($dateToday))." &agrave; $timeToday" ;
				$recent .= "</td>";
				$recent .= "<td>";
			
		                if(is_file(getUserFileDir().'/'.$l['nom'])){ $recent .= "<a href='fullview.php?nt=$nomtable&oid=$objectid&nr=$rid&tit=$titreobjet'>".
		                "<img src='".getUserFileDir()."/".$l['nom']."' width=200 height=200 title=\"$titter\"></a><br>"   ;
				$recent .= "</td>";
				$recent .= "<td>";
				$recent .= "<a href='fullview.php?nt=$nomtable&nr=$rid&oid=$objectid'><font color=blue>".$titreobjet."</font></a>";
				$recent .= "</td>";
				$recent .= "<td>";
				if(! empty($prix) )
				$recent .= $prix." FCFA";
				else		
				$recent .= "Pas de prix pr&eacute;cis&eacute;";
				$recent .= "</td>";
				}
			
				$recent .= "</tr>";
				$recent .= "<tr><td colspan=4><hr></tr>";
		                if($i == $max)break ;//Si on a deja afficher 4 images alors on sort
		        }
			$recent .= "</table>";
			if(!empty($recent))
		        echo "Les insertions les plus recentes<br>".$recent;
		

		}else{
		        echo "Pas d'images &agrave; afficher.";
		}
	}

?>
