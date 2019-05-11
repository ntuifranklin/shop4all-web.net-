<?php
	include_once('includes/header.inc');
	//Cette page confirme une insertion , en la recuperant de la session pour la mettre en base de données.
	//Elle est utile pour les users qui insere et ne veulent pas s'inscrire.
	//si le user noninscrit confirme quandmeme son insertion alors on ne le place pas dans la table des inseres non inscrit
	inclusionTete() ;
	$u = new User(); $u -> setUserId($_GET['actionnumber']); $u -> loadFromId();
	//$u -> connect();//On le connecte pour que l'insertion puisse avoir lieu
	$em = $u -> getEmail();
	$pseudo = $u -> getPseudo();
	if( ! empty($em)){
		//echo "Email = $em<br>" ;
		include_once('includes/saveFromSession.inc');
		include_once('includes/les_annonces.inc');
	}else{
	   echo errmess("Cet adresse email est inconnu");
	}
	sessionReset();
	//$u -> disconnect();//On remet la session comme il etait

	//unset($_SESSION);
	inclusionPied() ;
    
?>
