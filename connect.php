<?php
	$_GET['tit'] = "Connexion &agrave; {$_SERVER['SERVER_NAME']}";
        include_once('includes/header.inc');
        inclusionTete() ;
	$tab = getRubriquesAsArray();
        if(! sessionExists() && ! $_POST['conn']){
	        //La session n'existe pas alors on affiche le formulaire de connexion
	        include_once("includes/connect.inc");
        }elseif(! sessionExists() &&  $_POST['conn']){
	        //On viens du formulaire de connexion
                $u = new User();
                $u -> setPseudo(addslashes($_POST['uzer']));
                $u -> loadData() ;
                $u -> setPw($_POST['mdp']);//On met à jour le champ mot de passe car la partie elseif si execute en aura bsoin
		if($u -> userExists() && ! $u -> isInscrit() && $u -> passwordIsCorrect()){
			//Le user existe , il n'as pas confirmer son inscription mais son mot de passe est correcte
		        //Inscription non confirmer
			$mail = $u -> getEmail() ;
		        echo prmess("<font color=red>Vous n'avez pas encore confirmer votre inscription en ouvrant le liens<br>".
		" contenu dans le mail qu'on vous a envoy&eacute;</font><br> ".
		"Pour recevoir un autre mail de confirmation cliquez <a href='sendmail.php?messtype=1&email=$mail'>ici</a> ");
		        include_once("includes/connect.inc");

                
                }elseif(! empty($_POST['mdp']) && $u -> userExists() && $u -> passwordIsCorrect() && $u -> isInscrit()){
			//Le mot de passe est correcte , le user existe et il est inscrit
                        $u -> loadData();
                        $u -> connect();
                        //Puis qu'on viens de se connecter , on verifiera s'il existais un objet en attente , si oui alors on enregitre cet objet

                        $pseudo = $u -> getPseudo();
			$_SESSION['uzer'] = $pseudo ;//Utiliser dans saveFromSession.inc pour indiquer à qui appartient l'objet en cours de sauvegarde
			include_once("includes/saveFromSession.inc");//Ce fichier cree un objet sauvagarder dans une session		
                        sessionReset();//Reinitialiser la session pour que l'objet en session disparaisse
			$u -> connect();//Pour commencer la session du user
                        echo "Bienvenue <font color=green size=2>".ucfirst($u -> getPseudo())." </font> ";
                        echo "<br><a href='index.php'>Acceuil</a>";
                       
                        
               }else{
			//Le mot de passe et/le user est incorrecte , ou alors le user n'as que rempli le formulaire d'inscription partielle
			// lui permettant de sauvagrder son objet
                        //Erreur de mot de passe
                        echo prmess("<font color=red>Identifiant et/mot de passe incorrecte</font>");
                        include_once("includes/connect.inc");


		}


        }else{
		echo confmess("Vous &ecirc;tes d&eacute;ja connect&eacute;. <br> ".getLink("index.php","Acceuil"));
	}

        inclusionPied() ;
        //exit ;
?>
