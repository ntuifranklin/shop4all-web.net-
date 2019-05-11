<?php
	$_GET['tit'] = "Mon shop";
	include_once('includes/header.inc');
	if(! sessionExists()){
                inclusionTete();
		//La session n'existe pas alors on affiche le formulaire de connexion
		include_once("includes/connect.inc");

	}else{
               
                inclusionUserMenu();//
		//On est deja connecter alors on se redirige vers l'envorionnement du user
		$environUser = "includes/userwelcome.inc";
                //echo "On est connecter, Ici s'affichera l'environement du User";
                
		include_once($environUser);
	}

	inclusionPied() ;

?>
