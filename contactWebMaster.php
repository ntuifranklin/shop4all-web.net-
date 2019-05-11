<?php
	include_once('includes/header.inc');
	inclusionTete() ;
		if(! $_POST["contactweb"]){
			include_once("includes/contactWebMaster.inc");
		}else{
			//Traitement du formulaire
			$mess = $_POST['mess'] ; $email = $_POST['email'] ; $pseudo = $_POST['pseudo'] ; $tel = $_POST['tel'] ;
			if( empty($mess) || empty($email) || empty($pseudo) || empty($tel) ){
				echo errmess("L'un des champs n'est pas renseign&eacute;") ;
				include_once("includes/contactWebMaster.inc");
			}else{
				$body = $mess ; $nomperson = "webmaster at shop4all-web.net" ;
				$title = "Mail from unknown user  with Pseudonyme $pseudo at shop4all-web.net with email $email <br> Telephone : $tel " ;
				$emailWebMaster = "ntuifranklin_2005@yahoo.fr;ntuifranklin2005@gmail.com" ;
				if(sendmeil($emailWebMaster , $body , $nomperson , $title))
				 echo confmess("Mail envoy&eacute; avec succes") ;
				else
				 echo confmess("Mail non envoy&eacute; <br> Message : <br> $body") ;
				 ;
			} 
		}
	inclusionPied() ;

?>
