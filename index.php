<?php
	$_GET['tit'] = "Acceuil";
	include_once('includes/header.inc');
	inclusionTete() ;
        //On affichera le nombre d'insertions
        $obj = new Object();
        $t = $obj -> getTabs(); $nbs = array(); $lines = "";$T = $obj -> getRubriques();
        $lines = "";// echo count($t)." rubriques " ;
        for($i=1 ; $i<=count($t) ; $i++){
                $nomtable = $t[$i] ;
		//On ajoute la condition pour empecher que les tables qui sauvagarde deux objets de types different ne s'affiche deux fois dans les rubriques correspondantes
                $query = "select count(".str_replace("Tab","",$nomtable)."Id".") as nb from $nomtable where RubriqueId=$i";
                $res = execute($query);
                $l = mysql_fetch_assoc($res);
                $nbs[$i] = $l['nb'];
                if($l['nb'] < 1)
                $lines .= "<tr><td>".$T[$i]."(0)</td></tr>";
		else
		 $lines .= "<tr><td><font size=2><a href=\"visualise.php?nt=$nomtable&nr=".$i."&tit=Insertions disponibles dans la rubrique ".$T[$i]."\" title=\"".$l['nb']." objet(s) ".$T[$i]." \">".
                $T[$i]."(".$l['nb'].")</a></font></td></tr>";
		//echo "requete execute ".$query. " <br> " ;
        }
		//echo $i . " " . $t[$i] ;
		echo "<table>" ;		
		echo "<td>" ; 
			//Premiere colonne affiche les insertions disponibles 
		        echo "<table>";
		        echo "<caption><font color=blue size=2>Insertions disponibles</font></caption>";
		        echo $lines;
		        echo "</table>";

		echo "</td></tr>" ;

                echo "</table>";
?>

<?php		

	inclusionPied() ;

?>
