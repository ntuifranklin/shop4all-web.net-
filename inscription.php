<?php
	$_GET['tit'] = "Nouvelle inscription sur {$_SERVER['SERVER_NAME']}";
	include_once('includes/header.inc');
	inclusionTete() ;
	if(! sessionExists() && ! $_POST['enreg'] && !$_POST['nonenreg']){
		//La session n'existe pas alors on affiche le formulaire d'inscription
		 showInscripForm($_POST);

	}elseif( $_POST['enreg']){
		//On n'est pas connecte et on viens du formulaire  d'inscription 
		$r = execute("select * from UserTab");
		$u = new User();
		$u -> setPseudo(webtotext($_POST['pseudo']));
		$u -> setNom(webtotext($_POST['nom']));
		$u -> setPrenom(webtotext($_POST['prenom']));
		$u -> setEmail($_POST['email']);
		$u -> setTel(webtotext($_POST['tel']));
		$u -> setPw($_POST['mdp1']);
		$u -> setNLetter($_POST['nletter']);
		$errmess = "" ;
		// On verifie l'integrite des donnees , si elle est bonne alors , on enregistre ce User
		$errmess .= (strlen(addslashes($_POST['pseudo']) ) > 30 || empty($_POST['pseudo'])  ) ? "Pseudonyme trop long/vide<br>" : "" ;
		$errmess .= (strlen(addslashes($_POST['nom']) ) > 30 ) ? "Nom trop long" : "" ;
		$errmess .= (strlen(addslashes($_POST['prenom']) ) > 30 ) ? "Prenom trop long" : "" ;
		$errmess .= (strlen(addslashes($_POST['email']) ) > 30 || empty($_POST['email'])  ) ? "Email trop long/vide<br>" : "" ;
		$errmess .= (strlen(addslashes($_POST['tel']) ) > 30 || empty($_POST['tel'])  ) ? "Telephone trop long/vide<br>" : "" ;
		$errmess .= (strlen(addslashes($_POST['ville']) ) > 40   ) ? "Ville d'habitat trop longbr>" : "" ;
		$errmess .= ( $_POST['mdp1'] != $_POST['mdp2'] || empty($_POST['mdp1']) || empty($_POST['mdp2'])  ) ? "Mot de passe trop long/vide/differents<br>" : "" ;
		$errmess .= ( $u -> fieldExists("User_pseudo",$_POST['pseudo']) ) ? "Ce pseudonyme existe d&eacute;ja<br>" : "" ;
		$errmess .= ( $u -> fieldExists("User_email",$_POST['email']) ) ? "Cet email existe d&eacute;ja<br>" : "" ;
		$errmess .= ( $u -> fieldExists("User_tel",$_POST['tel']) ) ? "Ce num&eacute;ro de telephone existe d&eacute;ja<br>" : "" ;
		$errmess .= ( ! emailIsValid($_POST['email']) ) ? "Cet email n'est pas valide<br>" : "" ;
		$errmess .= (  empty($_POST['villeid']) || $_POST['villeid'] < 0 ) ? "Vous n'avez pas choisi votre ville d'habitat<br>" : "" ;
		if( empty($errmess)){
			//$ville = new Ville();
			//$ville -> setNom($_POST['ville']);
			//$ville -> creer();
			$idville = $_POST['villeid'];
			$u -> setVilleId($idville);
			$u -> setInscrit(0);
			$u -> creer();
			$u -> loadData();
			//echo confmess("Enregistrement reussi<br> ");
			if($u -> sendConfMail() )
			//Fonction qui insere une ligne dans noconfinscrit  lorsqu'un user recoit un mail de confirmation ou met la ligne existante a jour en
			signalConfInscrit($iduser ) ;
			//On cree une session pour le user 
			//$u -> connect();
			//echo $u -> visualiseData();
		}else{
			echo errmess($errmess);
                       			 showInscripForm($_POST);//Reaffichage du formulaire
		}
	}

        if($_POST['nonenreg']){//On viens du formulaire d'enregistrement incomplete , un user qui insere et qui ne veut pas s'inscrire
		$u = new User();
		$u -> setPseudo(webtotext($_POST['pseudo']));
		$u -> setEmail($_POST['email']);
		$u -> setTel(webtotext($_POST['tel']));
		$errmess = "" ;
		// On verifie l'integrite des donnees , si elle est bonne alors , on enregistre ce User
		$errmess .= (strlen(addslashes($_POST['pseudo']) ) > 30 || empty($_POST['pseudo'])  ) ? "Pseudonyme trop long/vide<br>" : "" ;
		$errmess .= (strlen(addslashes($_POST['email']) ) > 30 || empty($_POST['email'])  ) ? "Email trop long/vide<br>" : "" ;
		$errmess .= (strlen(addslashes($_POST['tel']) ) > 30 || empty($_POST['tel'])  ) ? "Telephone trop long/vide<br>" : "" ;
		$errmess .= ( $u -> fieldExists("User_pseudo",$_POST['pseudo']) ) ? "Ce pseudonyme existe d&eacute;ja<br>" : "" ;
		$errmess .= ( $u -> fieldExists("User_email",$_POST['email']) ) ? "Cet email existe d&eacute;ja<br>" : "" ;
		$errmess .= ( $u -> fieldExists("User_tel",$_POST['tel']) ) ? "Ce num&eacute;ro de telephone existe d&eacute;ja<br>" : "" ;
		$errmess .= ( ! emailIsValid($_POST['email']) ) ? "Cet email n'est pas valide<br>" : "" ;

                if(!empty($errmess)){//Si le formulaire est invalide alors on la reaffiche
                        echo errmess($errmess);
                        include_once("includes/incompleteform.inc");
                }else{//Si le formulaire est valide alors on essai de creer un nouveau user avec un Id et on le demande de confirmer son inscription depuis son mail.
	//S'il le fait alors on enregistre son insertion 
                       $u -> createNoUser() ;//Cree un user qui ne veux pas s'inscrire avec attribut User_inscrit = 0
                       $id = $u ->  getUserId(); $ps = $u -> getPseudo() ; $em = $u -> getEmail();
                       $u -> loadData();
	//createSession($ps);
	$subject = "Confirmation d'insertion chez ".$_SERVER['SERVER_NAME']." !\n\n";
			
                        $body = "Bonjour $ps,\n\n Si vous recevez ce mail alors vous avez ".utf8_decode("êtes")." effectuez une insertion chez nous et vous devez la confirmer".
                        "\n en cliquant sur ce liens ou en copiant le lien ci dessus dans la barre d'adresse : \n".
                        "<a href=\"http://".$_SERVER['SERVER_NAME']."/confirminsertion.php?actionnumber=".$id."&tr=".crypt($email).
			"&tit=Confirmation++d''une insertion\">liens de confirmation</a>";
	if ( sendmeil($em,  $body , $ps , $subject) ){
                          echo prmess("Un mail de confirmation d'insertion vous &agrave; &eacute;t&egrave; envoy&eacute;.");	
	$iduser = $id ;
	signalConfInscrit($iduser ); //Fonction qui insere une ligne dans noconfinscrit  lorsqu'un user recoit un mail de confirmation ou met la ligne existante a jour en
			// mettant à jour le nombre de fois que le user recoit le mail de confirmation
	}else{
	  echo prmess("Message  :<br>$body");	
	}
                }

        }

	inclusionPied() ;
    
?>
