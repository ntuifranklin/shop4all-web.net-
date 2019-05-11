<?php
	
	$_GET['tit'] = "Page de confirmation d'insertion ";
	include_once('includes/header.inc');
	inclusionTete() ;
	//Page de confirmation d'insertion d'un user qui a déja confirmer son inscription
	echo "Page de confirmation d'insertion ";
	$iduser = $_GET['v1'] ;//Ce $_GET['v1'] c'est l'id du user 
	$norubr = $_GET['v2'] ;//Ce $_GET['v2'] c'est le numero de rubrique auquel appartient l'objet qu'on souhaite confirmer 
	$ObjectId = $_GET['v3'] ;//Ce $_GET['v3'] c'est l'id de l'objet a confirmer
	$u = new User();
	if(is_numeric($iduser) && is_numeric($norubr) && is_numeric($ObjectId)){
		$u -> setUserId($iduser);
		$u -> loadFromId();
		$ps = $u -> getPseudo();
		//Il faut supprimer cette insertion  dans la table des insertions n'ayant pas été confirmer	
		$fanfarons = "noconfinsert" ;
		$q = "delete from $fanfarons where UserId=$iduser and RubriqueId=$norubr and ObjectId = $ObjectId" ;
		$res = execute($q) ;
		echo prmess("query : $q <br>");
		
		echo confmess("$res action effectu&eacute;e <br>Confirmation d'insertion par <font color=blue size=2>".$ps."</font>");
		
	}

	if(!sessionExists()){//La session n'existe pas et on est entrain de confirmer une insertion,donc on proposera le formulaire de connexion
		include_once("includes/connect.inc");  

	}
         
	inclusionPied() ;

?>
