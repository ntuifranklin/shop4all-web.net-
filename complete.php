<?php

	//A la date du 01-03-2012 ce fichier n'est plus trop utiliser
	include_once('includes/header.inc');
	inclusionTete() ;
			//On veut completer l'inscription
			//On va supposer que le user avait entrer les informations eronnées lors de son inscription partielle. 
			//Alors , là on lui donne la possibilité de corriger ces infos en affichant un formulaire d'inscription complet conténant tout ce qu'il 
			//avait saisie

       //Je prefere recuperer le pseudo dans la session au lieu de dans $_GET , car s'il ya erreur d'intégrité des données,il faudra reafficher le formulaire , surtout que le pseudo peut changer
        $email = $_GET['email']; $pseudo = getUserName() ;        $u = new User();
        $u -> setPseudo($pseudo);
        $u -> loadData();

		if(! $_POST['completer']){
			echo "<font color=blue>Formulaire pour completer l'inscription</font>";
			include_once("includes/complete.inc");

		}else{
			echo "<font color=blue>Traitement du formulaire pour completer l'inscription</font>";
			//On veut traiter le formulaire pour completer l'inscription


				$errorMessages = "" ; $confMessage = "" ;
				$pseudo = getUserName();//Je recupere le pseudonyme de l'utilisateur en cours de session
				$u -> setPseudo($pseudo);//Precision du pseudonyme

				$u -> loadData() ;//Chargement des données du user
				$email = $u -> getEmail();//On recupere son ancien email , 
				//On commence par l'email
				if($_POST['User_email'] != $email ){//Si l'ancien email est different du nouveau => Il veut modifier son email
					$u -> setEmail($_POST['User_email']);//on place l'email

					if($u -> emailExists()) {
					 $errorMessage .= "Cet email ".$_POST['User_email']." existe d&eacute;ja<br>" ;
					}else{
					 $u -> update("User_email",$_POST['User_email'])  ; 
					 $confMessage .= "Email modifier avec succes<br>";
					 $u -> loadData()  ; 
					}
				}

				//On continu avec le pseudonyme 
				$pseudo = getUserName();
				if($_POST['User_pseudo'] != $pseudo ){//Si l'ancien pseudonyme est different du nouveau => Il veut modifier son pseudo
					if($u -> fieldExists("User_pseudo",$_POST['User_pseudo']) ){//on verifie si elle est unique
					 $errorMessage .= "Cet pseudonyme ".$_POST['User_pseudo']." existe d&eacute;ja<br>" ;
					}else{//Elle n'existe pas encore donc on peut effectuer la modification
					 $u -> update("User_pseudo",$_POST['User_pseudo'])  ; 
					 $confMessage .="Pseudonyme  modifier avec succes<br>";
					 /*Le pseudonyme a changer et la fonction User :: loadData()
					 * se sert du pseudonyme pour charger les donnees donc il faut aussi la mettre a jour
					 */
					 $u -> setPseudo($_POST['User_pseudo']);
					 sessionReset() ; //Reinitialisation de la session
					 createSession($_POST['User_pseudo']);//Il faut mettre a jour les variables de session
					// $u -> loadData()  ; 

					}
				}
		

				//On continu avec le numero de telephone
		
				$pseudo = getUserName();
				$u -> setPseudo($pseudo); $u -> loadData();
				$tel = $u -> getTel();
				if($_POST['User_tel'] != $tel ){//Si l'ancien numero de telephone est different du nouveau => Il veut modifier son numero de telephone

					if($u -> fieldExists("User_tel",$_POST['User_tel'])) {
					 $errorMessage .= "Ce num&eacute;ro de telephone : ".$_POST['User_tel']." existe d&eacute;ja<br>" ;				 
					}else{
					 $u -> update("User_tel",$_POST['User_tel'])  ; 
					 $confMessage .="Telephone  modifier avec succes<br>";
					 $u -> loadData()  ;
				         $u -> sendConfMail() ;//Envoi du mail de confirmation 

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

				   	$u -> update("User_nom",$_POST['User_nom'])  ; 
					$confMessage .="Nom  modifier avec succes<br>";
				   }

				   $nouveauPrenom = $_POST['User_prenom'] ; $ancienPrenom = $u -> getPrenom();
				   if($nouveauPrenom !=  $ancienPrenom){//Si l'utilisateur veut changer de prenom

				   	$u -> update("User_prenom",$_POST['User_prenom'])  ; 
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
				   if($nouvVilleId != $ancienVilleId && $_POST['villeid'] > 0){//Si l'utilisateur veut changer de ville
				        
				   	$u -> update("VilleId",$_POST['villeid'])  ; 
					$confMessage .="Ville  modifier avec succes<br>";
				   }
				        

				/*
				* Maintenant , on va effectuer les modifications pour le mot de passe :
				* Pour modifier le mote de passe , il doit tapper l'ancien , le nouveau , et la confirmation du mot de passe
				*/
				if(!( empty($_POST['User_pw1']) || empty($_POST['User_pw2']) )){
				//Si l'un des mots de passes est renseignes alors l'utilisateur souhaite effectuer des modifications du mot de passe
				   $pseudo = getUserName();					 
				   $u -> setPseudo($pseudo);
				   $u -> setPw($_POST['User_pw1']);
				    //$mdpEstCorrecte = false ;  
				   if($_POST['User_pw1'] == $_POST['User_pw2']){//Si le nouveau mot de passe et sa confirmation sont correctes
					$u -> updatePassword($_POST['User_pw1']);//Mise a jour du mot de passe 
					$confMessage .="Mot de passe  modifier avec succes<br>";
				   }else{

					$errorMessage .= "Les deux nouveaux mots de passe sont differents<br>";
				   }

				}

				 //$u -> inscrire();
				  $u -> sendConfMail();//envoi du mail de confirmation , puis on attends sa confirmation. S'il le fait alors on l'inscrit effectivement
				                         
				
				

				
			      	
				if(!empty($errorMessage)){//S'il ya des erreurs on affiche ces erreurs la
					echo errmess($errorMessage);
					include_once("includes/complete.inc");

				}

				if(!empty($confMessage)){//Si la modification s'est effectuer avec succes alors on signale cela
					echo confmess($confMessage);
				        
				}
					$pseudo = getUserName();
					$u -> setPseudo($pseudo); $u -> loadData();
				        echo $u -> visualiseData();//reaffichage du formulaire signalant si oui ou non il ya eu modification

				
				/* S'il y'a un objet en attente alors on l'enregistre 
				         if( objetEnAttente()){
		                        $nomtable = getTabNameFromSess();//Retourne le nom de la table sauvegarder dans la session
					$userEmail = $u -> getEmail();
				                if(! empty($nomtable)){
				                        $obj = new $nomtable(); 
				        		$obj -> setRubriqueId($_SESSION['norubr']);
				                        $retour = $obj -> createFromSession();
				                        echo confmess("Objet en attente sauvegarder avec succes");
						$corps = "Insertion effectuer chez ".getServerName()." d'un objet. ".$tab[$_SESSION['norubr']]
						." . Heure : ".date("Y-m-d H:i:s"); $nomperson = $u -> getPrenom()." ".$u -> getNom();
						sendmeil($userEmail , $corps , $nomperson  ) ;
		                                sessionReset();//Reinitialiser la session pour que l'objet en session disparaisse
		                       		}
                       			}
				*/



		}
			

	inclusionPied() ;
?>
