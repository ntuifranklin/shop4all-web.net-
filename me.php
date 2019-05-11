<?php
	$_GET['tit'] = "Mes informations personnelles";
	include_once('includes/header.inc');
	inclusionTete() ;
	if(! sessionExists()){
		//La session n'existe pas alors on affiche le formulaire de connexion
		include_once("includes/connect.inc");

	}else{
		//On est deja connecter alors on affiche le formulaire pour modifier les infos du User
                $u = new User();
                $pseudo = getUserName();
                $u -> setPseudo($pseudo);
                $u -> loadData();
		//echo "Id de la ville est : ".$u -> getVilleId();
                echo $u -> visualiseData();
	}

	inclusionPied() ;
?>
