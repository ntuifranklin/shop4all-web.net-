<?php
	include_once('includes/fullviewheader.inc');//Header pour la visualisation complete d'une insertion avec images cyclique de visualisato
		
        include_once("includes/navigauche.inc");//Barre de naviagtion gauche
        $nomtable = $_GET['nt']; $oid = $_GET['oid']; $nr = $_GET['nr'];
        if(!empty($nomtable) && is_numeric($oid) && !empty($_GET['oid'])){
                $obj = new $nomtable ;
                $t = $obj -> getattribAsarray();
                $q = "select * , date_format(Date_ins ,'%d-%m-%Y') as jour ,date_format(Date_ins ,'%H:%i:%s') as heure from $nomtable where ".str_replace("Tab","",$nomtable)."Id=$oid ";//On a besoin de l'heure et du jour
                $r = execute($q);
                $_T = mysql_fetch_assoc($r);
                //echo "RubriqueId=$nr , nomtable=$nomtable ObjectId=$oid";
		if(mysql_num_rows($r) > 0)
                	echo getView($nomtable,$t,$_T , $oid);
		else 
			echo prmess("L'insertion n'existe plus/n'as jamais exist&eacute;") ;
        }


	if( $_GET['sendfriend'] == 1){//On essai d'envoyer l'annonce a un ami , ayant deja reafficher l'nsertion complete alors on va afficher un formulaire de saisie
			echo sendAnnonceForm($nomtable, $oid , $nr);
	}
	inclusionPied() ;
?>
