<?php
	include_once('includes/header.inc');
	inclusionTete() ;
        $classes = getRubriqueTableAsArray(); 
        $long = count($classes); $indice = 0 ; $trouver = false ;
        $pho = new Photo();
        $nomtable = $classes[$_POST['norubr']] ; $objtyp = $_POST["objtyp"];

        $obj = new $nomtable(); 
        if($_POST[$nomtable]){
                //On veut maintenant traiter le formulaire
                $maximages = $_POST['maximages'] ;
                //On verifie si l'extension des images uploader est celle attendu
                $errmes = "";
		$taillemax = getMaxFileSize();//La taille max de tous les fichiers à uploader
                for($i=0;$i<$maximages ; $i++){
                        $numero = $i + 1 ;
                        $nomImage = "im".$numero; $nomfichier = $_FILES[$nomImage]["name"];
                        if($_FILES[$nomImage]['size'] > 0 && !extensionIsValid($nomfichier) && $_FILES[$nomImage]['size'] > $taillemax ){
                         $errmess .= "Le fichier Image_$numero est de type invalide /le fichier est trop lourd<br>";        
                        }
                }


                //On verifie si l'extension des cv uploader est la bonne si nous sommes entrain d'inserer une recherche d'emploi job
                
                        $nom = "fichier"; $nomfichier = $_FILES[$nom]["name"];
                        if( !isPdfWord($nomfichier) || $_FILES[$nom]['size'] > $taillemax ){
                         $errmess .= "Le fichier uploader est de type invalide/trop volumineux <br>";        
                        }

                 //On notifie le client si l'image n'est de bonne type
                 if (! empty($errmess)) { //on notifie et on sort

                        echo errmess($errmess) ; $actionFile = "treatinsertion.php";
                        echo getForm($nom , $actionFile , $nomtable , $obj -> getAttribAsArray(), $_POST['norubr'] , $objtyp) ;
                        
                 }else{
                        $retour = false ;

                        $errmess = "";
			//$errmess .= ($_POST["villeid"] < 1 ) ? "La ville d'insertion n'as pas &eacute;t&eacute; selectionner" : "" ;
                        $attribs = $obj -> getAttribAsArray() ;
                        $class = getRubriqueTableAsArray() ;
                        $taille = $obj -> getTableTailles();
                        $nulls = $obj -> getTableNulls(); //Indices des attributs qui peuvent etre nulle
                        $types = $obj -> getTableTypes(); //Tableau des types attendus. 1 ==> String , 0 ==> numeric
                        $long = count($attribs); $i= -1 ;
                        foreach($attribs as $field => $value){
                                $i++ ;
                                if($nulls[$i] == 0){//==> que cet attribut ne doit pas etre vide
                                      $errmess .=  (empty($_POST[$value]) || strlen(addslashes($_POST[$value])) > $taille[$i] ) ?
                                         "Le champ ".$field." est soit vide/Trop long<br>" : "" ;
        
                                }

                                if($types[$i] == 0){//==> que cet attribut ne doit pas etre different d'un numeric
                                      $errmess .=  (! is_numeric($_POST[$value])  ) ?
                                         "Le champ ".$field." n'est pas numerique<br>" : "" ;        
                                }
                        }
			
                        $errmess .= ( !filter_var($_POST["villeid"] , FILTER_VALIDATE_INT) || $_POST["villeid"]<1 ) ?"Le champ Ville n'as pas &eacute;t&eacute; selectionner<br>" : "" ;        
			
                        if($errmess != "" ){ //S'il ya des erreurs alors on reaffiche le formulaire et on libere le plancher
                             echo errmess($errmess)  ; 
                             $titre = $_POST['titreRub']; $actionFile = "treatinsertion.php"; $nom = $class[$_POST['norubr']] ;
                             echo getForm($titre , $actionFile , $nom , $obj -> getAttribAsArray(), $_POST['norubr'] , $_POST['objtyp']) ; //Reaffichage du formulaire 
                             
                        }else{
                             $retour = true ; 
			}  

                        if($retour == true && sessionExists()){//Si le formulaire est valide et que le user est connecter alors on enregistre son insertion
				// echo confmess("Formulaire bien rempli");
				$obj -> placerChamps();//Place les valeurs venant de $_POST aux champs de l'objet en cours irrespectif de la classe
				//On enverra une mail de confirmation apres insertion effectuer , si ca marche biensure !
				$u = new User(); $u -> setPseudo(getUserName()); $u -> loadData(); 
				$userEmail = $u -> getEmail(); $iduser = $u -> getUserId() ;
				$obj -> setRubriqueId($_POST['norubr']); $norubr = $_POST['norubr'] ; $tab = getRubriquesAsArray();
				//$obj -> setVilleId($_POST['villeid']) ;
				$obj -> creer();
				$objectid = $obj -> getId();
				//Ensuite on enregistre les images s'il y'en a
				$nomperson = $u -> getPseudo();
				$maximages = $_POST['maximages'] ;

				//Si les images ont ete uploader
				for($i=0;$i<$maximages ; $i++){
				        $norubr = $_POST['norubr'] ; $nom = "im".($i + 1);
					if($_FILES[$nom]['size'] > 0)
				        $pho -> createImage($norubr , $nomtable , $objectid , $nom); 
				}

				//Si c'est plutot un cv(prestation de services) qui à été uploader , toujours est -il que les images
				// et cv sont mutuellement exclusifs
				$nomfichier = "fichier" ;//C'est le nom utiliser pour referer le cv uploader
				$nom = $_FILES[$nomfichier]["name"];
				$extension = getExtension($nom) ;
				if($_FILES[$nomfichier]['size'] > 0 && $_FILES[$nomfichier]['size'] < $taillemax && isPdfWord($nom) ) 
				//La taille est supérieure à zero et est inférieure à la taille max permise , et on à faire à un fichier soit word ou pdf
				
				$pho -> copyFile($norubr , $nomtable , $objectid , $nomfichier);
	

				$corps = "Insertion effectuer chez ".getServerName()." d'un objet. ".$tab[$norubr]
				." . Heure : ".date("Y-m-d H:i:s");
				$corps .= "<br> Confirmez votre insertion en cliquant sur ce <a href='{$_SERVER['SERVER_NAME']}/confinsertinscrit.php?v1=$iduser&v2=$norubr&v3=$objectid'>liens</a>";
				 $nomperson = $u -> getPseudo();
				$titre = "Nouvelle insertion chez {$_SERVER['SERVER_NAME']}";
				if(sendmeil($userEmail , $corps , $nomperson , $titre ) )
                                echo prmess("Insertion reussi ! <br> Un mail de confirmation d'insertion vous &agrave; &eacute;t&eacute; envoy&eacute;  ".
		"<br><a href='visualise.php?nt=$nomtable&oid=".$obj -> getId()."&nr=$norubr'>Visualiser cette insertion</a>");
				else{
                                echo prmess("Insertion reussi ! <br> Un mail de confirmation d'insertion n'as pas &eacute;t&eacute; envoy&eacute; ".
				"<br>Message : <br>$titre <br> $corps<br>Probl&egrave;me de configuration mail ".
		"<br><a href='visualise.php?nt=$nomtable&oid=".$obj -> getId()."&nr=$norubr'>Visualiser cette insertion</a>");
				}
				//On insere ce user dans la table des users qui n'ont pas encore confirmer leur
				// insertion mais qui sont inscrit
				signalConfInsert($iduser,$norubr,$objectid );
                                
                                
                        }elseif($retour == true && ! sessionExists()){
                                echo "Vous n'&egrave;tes pas connect&eacute;, veuillez vous connecter ou alors vous ouvrez un compte";
                                //On sauvegarde son objet dans une session et ensuite on enregistrera cet objet s'il decide de se conecter ou alors de s'inscrire
                                //Si on n'est pas connecter alors on ne peut pas uploader d'images
                                //$obj -> saveInSession($nomtable) ;
				//On sauvegarde dans une session l'objet
				//Avant de sauvegarder dans la session,on efface tout le contenu de la session. 
				//sessionReset();//On vide la session d'abord si elle contenait des objets sauvagarder.
				
 				$t = $obj -> getAttribAsArray() ;
                       		foreach($t as $f => $value )
                                $_SESSION[$value] = $_POST[$value];
                                $_SESSION["objEnAttente"] = 1 ;
                                $_SESSION["objtyp"] = $_POST["objtyp"] ; 
                                $_SESSION["nomtable"] = $nomtable ;
	        		$_SESSION["norubr"]  = $_POST["norubr"];
	        		$_SESSION["villeid"] = $_POST["villeid"] ;
				/*
				$obj -> placerChampsTab($_POST) ;//Place les valeurs venant de $_POST aux champs de l'objet en cours irrespectif de la classe
				$nomtableTemp = $nomtable."_temp" ;
				$obj -> creer($nomtableTemp);
				$temporalId = $obj -> getId();
				$_SESSION['oid'] = $temporalId;
				$_SESSION['nttemp']= $nomtableTemp;
				*/
				//On sauvegarde le nom de la table au quel cet objet appartient
                               
                                echo "<table border=1>" ;
                                echo "<tr><td>" ;
	                        include_once("includes/connect.inc");
                                echo "</td>" ;
                                echo "<td>" ;
                
                                echo "Informations minimum n&eacute;cessaires pour effectuer une insertion";
                                include_once("includes/incompleteform.inc");
                                echo "</td></tr>" ;
                                echo "</table>" ;
                        }
                }//Fin de traitement du formulaire
        }
	inclusionPied() ;
	
?>
