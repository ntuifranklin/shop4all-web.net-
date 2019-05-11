<?php
	$_GET['tit'] = "Modification de mes informations personnelles";
	include_once('includes/header.inc');
	backToStart();//Affiche la page de connexion si l'utilisateur n'est pas connecter

	inclusionClasses();//les classes a utiliser

		$u = new User();//Declaration d'un nouvel utilisateur
	if(sessionExists() && $_POST['modif']){
	//Si on est connecter et qu'on viens du formulaire de modification de l'utilisateur, 
	//On traite les donnees venant de la machine cliente
		
		/*Pour effectuer les modifications de cet utilisateur , on procedera ainsi :
		* 
		* On verifie que les donnees obligatoires sont presentes
                * ensuite un verifie que ces donnees obligatoires sont unique, c'est a dire que si on effectue la modification , 
		* la table user aura l'email , le pseudonyme et le telephone unique pour cet utilisateur
		* Si ces contraintes citees en dessus ne sont pas verifier alors on reaffichera le formulaire de modification
                * avec les memes attributs de depart 
		*
		* Apres avoir effectuer le dessus , on va faire des modification pour les donnees non obligatoire a savoir le :
		* nom , prenom et ville
		* apres tout ces manipulations on reaffichera les donnees de l'utilsateur qu'il y'ai eu modification ou pas
		* 
		*/

		

		$errorMessages = "" ; $confMessage = "" ;
		$pseudo = getUserName();//Je recupere le pseudonyme de l'utilisateur en cours de session
		$u -> setPseudo($pseudo);//Precision du pseudonyme

		$u -> loadData() ;//Chargement
		$email = $u -> getEmail();//On recupere son ancien email 
		//On commence par l'email
		if($_POST['User_email'] != $email ){//Si l'ancien email est different du nouveau => Il veut modifier son email
			$u -> setEmail($_POST['User_email']);//on place l'email

			if($u -> emailExists()) {
			 $errorMessage .= "Cet email ".$_POST['User_email']." existe d&eacute;ja<br>" ;
			}else{
			 $u -> update("email",$_POST['User_email'])  ; 
			 $confMessage .= "Email modifier avec succes<br>";
			 $u -> loadData()  ; 
			}
		}

		//On continu avec le pseudonyme 
		$pseudo = getUserName();
		if($_POST['User_pseudo'] != $pseudo ){//Si l'ancien pseudonyme est different du nouveau => Il veut modifier son pseudo
			if($u -> fieldExists("pseudonyme",$_POST['User_pseudo']) ){//on verifie si elle est unique
			 $errorMessage .= "Cet pseudonyme ".$_POST['User_pseudo']." existe d&eacute;ja<br>" ;
			}else{//Elle n'existe pas encore donc on peut effectuer la modification
			 $u -> update("User_pseudo",$_POST['User_pseudo'])  ; 
			 $confMessage .="Pseudonyme  modifier avec succes<br>";
			 /*Le pseudonyme a changer et la fonction User :: loadData()
			 * se sert du pseudonyme pour charger les donnees donc il faut aussi la mettre a jour
			 */
			 $u -> setPseudo($_POST['User_pseudo']);
			 createSession($_POST['User_pseudo']);//Il faut mettre a jour les variables de session
			 $u -> loadData()  ; 

			}
		}
		

		//On continu avec le numero de telephone
		
		$tel = $u -> getTel();$pseudo = getUserName();
		$u -> setPseudo($pseudo); $u -> loadData();
		if($_POST['User_tel'] != $tel ){//Si l'ancien numero de telephone est different du nouveau => Il veut modifier son numero de telephone
			

			if($u -> fieldExists("User_tel",$_POST['User_tel'])) {
			 $errorMessage .= "Ce num&eacute;ro de telephone : ".$_POST['User_tel']." existe d&eacute;ja<br>" ;
			 
			}else{
			$nouvtel = webtotext($_POST['User_tel']);//On encadre les caracteres accentuées
			 $u -> update("User_tel",$nouvtel)  ; 
			 $confMessage .="Telephone  modifier avec succes<br>";
			 $u -> loadData()  ;
                         //$u -> sendConfMail() ;//Envoi du mail de confirmation 

			}
		}

		/*
		* Maintenant , on va effectuer les modifications pour les champs non obligatoire a savoir :
		* le nom , prenom et la ville 
		*/					 
		   $u -> setPseudo($pseudo);
		   $u -> loadData();
		   $nouveauNom = $_POST['User_nom'] ; $ancienNom = $u -> getNom();
		   if($nouveauNom !=  $ancienNom){//Si l'utilisateur veut changer de nom
			$nouvnom = webtotext($_POST['User_nom']);//On encadre les caracteres accentuées
		   	$u -> update("User_nom",$nouvnom)  ; 
			$confMessage .="Nom  modifier avec succes<br>";
		   }

		   $nouveauPrenom = $_POST['User_prenom'] ; $ancienPrenom = $u -> getPrenom();
		   if($nouveauPrenom !=  $ancienPrenom){//Si l'utilisateur veut changer de prenom
			$nouvprenom = webtotext($_POST['User_prenom']);//On encadre les caracteres accentuées
		   	$u -> update("User_prenom",$nouvprenom)  ; 
			$confMessage .="Prenom  modifier avec succes<br>";
		   }

                
                   //La modification de la ville requiert un peu de gymnastique
                   //On procede ainsi :
                   //Si la nouvele ville du user existe deja alors on modifie seulement la villeId de ce user
                    //Sinon on cree une ville de ce nom et on retourne l'id de la ville creer
		   $u -> loadData();
                   $userVilleId = $u -> getVilleId(); 
                   $vi = new Ville(); 
                   $vi -> setId($_POST['villeid']); 
		   $vi -> loadDataFromId(); $nouvVilleId = $vi -> getId() ; $ancienVilleId = $userVilleId ;
		   /*
                   if(! $vi -> villeNomExists()){//Si la ville n'existe pas deja alors on la cree
                         $vi -> creer();//Creation et chargement de la nouvelle ville
                   }
	           */
	           if($nouvVilleId != $ancienVilleId){//Si l'utilisateur veut changer de ville
                        
	           	$u -> update("VilleId",$_POST['villeid'])  ; 
		        $confMessage .="Ville  modifier avec succes<br>";
	           }
                        

		/*
		* Maintenant , on va effectuer les modifications pour le mot de passe :
		* Pour modifier le mote de passe , il doit tapper l'ancien , le nouveau , et la confirmation du mot de passe
		*/
		if(!( empty($_POST['User_pw']) || empty($_POST['User_pw1']) || empty($_POST['User_pw2']) )){
		//Si l'un des mots de passes est renseignes alors l'utilisateur souhaite effectuer des modifications du mot de passe
		   $pseudo = getUserName();					 
		   $u -> setPseudo($pseudo);
		   $u -> setPw($_POST['User_pw']);

		   if($u -> passwordIsCorrect() && $_POST['User_pw1'] == $_POST['User_pw2']){//Si le nouveau mot de passe et sa confirmation sont correctes
			$u -> updatePassword($_POST['User_pw1']);//Mise a jour du mot de passe 
			$confMessage .="Mot de passe  modifier avec succes<br>";
		   }else{

			$errorMessage .= "Soit Votre ancien mot de passe est incorrecte/Les deux nouveaux mots de passe sont differents<br>";
		   }

		}

                $inscrit = $u -> getInscrit();
                if($_POST['comp'] == 1 ){//Le user veux confirmer son inscription
		  $u -> inscrire();
                  $u -> sendConfMail();//envoi du mail de confirmation , puis on attends sa confirmation. S'il le fait alors on l'inscrit effectivement
                                         
                }
                
		/*On inlut les fichiers entete tardivement 
		*pour qu'elles prenne en compte les modifications effectues dans la variable $_SESSION 
		*/
		inclusionTete();

                
              	
		if(!empty($errorMessage)){//S'il ya des erreurs on affiche ces erreurs la
			echo errmess($errorMessage);
		}

		if(!empty($confMessage)){//Si la modification s'est effectuer avec succes alors on signale cela
			echo confmess($confMessage);
                        
		}
			$pseudo = getUserName();
			$u -> setPseudo($pseudo); $u -> loadData();
                        echo $u -> visualiseData();//reaffichage du formulaire signalant si oui ou non il ya eu modification
                       
                inclusionPied();


	}
	
?>
