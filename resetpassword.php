<?php

        include_once('includes/header.inc');
        inclusionTete() ;
		if( ! $_POST['reinitpassword']){
			require("includes/resetform.inc");
		}else{
			$email = $_POST['em'];
			if( ! emailIsValid($email)){
				echo errmess("Cet email entrer est invalide");

			}else{
				$u = new User();
				$u -> setEmail($email);
				if( ! $u -> emailExists()){
					echo prmess("L'utilisateur possedant l'email ".$email.
					" n'est pas inscrit chez nous &agrave; ".$_SERVER['SERVER_NAME']);
				}else{
					$titre = "\n Reinitialisation de mot de passe chez {$_SERVER['SERVER_NAME']} \n";
					$u -> loadFromQuery("select * from UserTab where User_email = '$email'");
					$nomperson = $u -> getNom(); 
					$nouvMdp = createRandomPassword() ;
					$u -> updatePassword($nouvMdp);
					$body = "Vous avez demander &agrave; reinitialiser votre mot de passe\n";
					
					$body .= "Mot de passe : $nouvMdp \n " ; 
					$body .= "Vous pouvez vous connecter <a href=\"{$_SERVER['SERVER_NAME']}/connect.php\">ici</a> \n " ;
 
					if(sendmeil($email , $body , $nomperson , $titre ) ){					
						echo prmess("Un mail vous ete envoyer pour re-initialisation. \n ".
						" Le nouveau mot de passe est contenu dans ce mail") ;
					}else{

						echo errmess("Echec d'operation de mise a jour de mot de passe");
					};

				}
			}
	
		}

        inclusionPied() ;
      
?>
