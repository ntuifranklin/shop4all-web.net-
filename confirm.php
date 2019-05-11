<?php
	include_once('includes/header.inc');
	inclusionTete() ;
	echo "Page de confirmation d'inscription";
	$id = $_GET['actionnumber'] ;//Ce $_GET['actionnumber'] c'est l'id du user 
	$u = new User();
	if(is_numeric($id)){
		$u -> setUserId($id); 
		$u -> loadFromId();
		
		$res = $u -> inscrire();
		if($res > 0){
			$ps = $u -> getPseudo();
			echo confmess("Confirmation d'inscription pour l'utilisateur <font color=blue size = 2>".$ps."</font>");
			//Il faut supprimer ce user dans la table des fanfarons(ceux qui ne confirme pas leur inscription)	
			$fanfarons = "noconfinscrit" ;
			$q = "delete from $fanfarons where UserId=$id" ;
			$res = execute($q) ;
		}else{
			echo prmess("Probl&egrave; rencontr&eacute; lors de la confirmation de ".$u -> getPseudo());
		}
	}
	if(!sessionExists()){//La session n'existe pas et on est entrain de confirmer une inscription,donc on proposera le formulaire de connexion

	include_once("includes/connect.inc");  

	}

	inclusionPied() ;

?>
