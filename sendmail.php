<?php
	//Cette page permet d'envoyer des mail à des emails precis avec des type de message prédefini
	//si messtype = 1 alors on démande un mail de confimation
	include_once('includes/header.inc');
	inclusionTete() ;
	$typemessage = $_GET['messtype'];
	$em = $_GET['email'];
	$u = new User();$u -> setEmail($em);
	$u -> loadFromEmail() ;
	$ps = $u -> getPseudo() ; $em = $u -> getEmail(); $iduser = $u -> getUSerId() ;
	switch($typemessage){
		case 1: {
		//On essai de reconfirmer une inscription déja faite
		//Faut faire attention aux fanfarons
		
		if ( $u -> sendConfMail() ){
		   echo prmess("Un mail de confirmation vous &agrave; &eacute;t&egrave; envoy&eacute;.");	
		}else{
		  echo prmess("echec d'envoi du mail de confirmation <a href=\"http://".$_SERVER['SERVER_NAME']."/shop4all.de/confirm.php?actionnumber=".$iduser."&tr=".crypt($email).
			"&tit=Confirmation++Inscription\">liens de confirmation</a> ");
		 //Un mail de plus à été envoyé a cet email. Il faut l'enregistrer sur bd , afin que ca puisse servi après à but statistique
		signalConfInscrit($iduser ); //Fonction qui insere une ligne dans noconfinscrit  lorsqu'un user recoit un mail de confirmation ou met la ligne existante a jour en
		// mettant à jour le nombre de fois que le user recoit le mail de confirmation
		}
	       }   ; break ;
		case 2 : { //On essai d'envoyer une annonce a un ami par mail
			 $nomtable = $_GET['nt']; $oid = $_GET['oid']; $nr = $_GET['nr']; $email = $_GET['email'] ; 
			 $nomserveur = "{$_SERVER['SERVER_NAME']}";
			 $emami = $_GET['emailami']; $pseudo = $_GET['pseudo'] ; $liens = "http://$nomserveur/fullview.php?nt=$nomtable&oid=$oid&nr=$nr";
			 $title = "Annonce envoy&eacute;e depuis $nomserveur de $pseudo";
			 $body = "Bonjour ! <br> Votre ami d'adresse $email vous &agrave; envoy&eacute; cette annonce : $liens <br>Pour la visualiser cliquez sur le liens $liens <br> Merci bien ";
			 if(sendmeil( $emami , $body , $nomperson , $title ))
				echo prmess("Votre annonce &agrave; &eacute;t&eacute; envoy&eacute; &agrave; $emami");
			 else
				echo prmess("Corps du message non envoye : <br> $body");
		} ; break ;
		
	       //default : echo "cas par defaut" ;
	}
	inclusionPied() ;

?>
