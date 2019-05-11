<?php
	/**
	 *
	 * @cree un dropdown select
	 *
	 * @param string $name
	 *
	 * @param array $options
	 *
	 * @param string $selected (optional)
	 *
	 * @return string
	 *
	 */
	function dropdown( $name, array $options, $selected=null ){
	    /*** Debutte le select ***/
	    $dropdown = '<select name="'.$name.'" id="'.$name.'">'."\n";

	    $selected = $selected;
	    /*** Boucler sur les options ***/
	    foreach( $options as $key=>$option ){
		/*** assigner un un valeur de selected ***/
		$select = ($selected==$key ) ? ' selected' : null;

		/*** ajouter chaque option au dropdown ***/
		$dropdown .= '<option value='.$key.' '.$select.'>'.$option.'</option>'."\n";
	    }

	    /*** Fermer le select ***/
	    $dropdown .= '</select>'."\n";

	    /*** et retourne le dropdown complet***/
	    return $dropdown;
	}//Fin dropdown

	/**
	 *
	 * @cree un dropdown select
	 *
	 * @param string $name
	 *
	 * @param array $options
	 *
	 * @param string $selected (optional)
	 *
	 * @return string
	 *
	 */
	function dropdown2( $name, array $options, $selected=null ){
	    /*** Debutte le select ***/
	    $dropdown = "<select name='$name' id='$name' onChange='changeChoix(this,\"objtyp\",6,0)'> \n";

	    $selected = $selected;
	    /*** Boucler sur les options ***/
	    foreach( $options as $key=>$option ){
		/*** assigner un un valeur de selected ***/
		if( $option == $_POST[$name])
		$select = ' selected' ;
		else
		$select = ' null' ;
		//$select = ($selected==$option ) ? ' selected' : null;

		/*** ajouter chaque option au dropdown ***/
		$dropdown .= '<option value='.$option.' '.$select.'>'.$key.'</option>'."\n";
	    }

	    /*** Fermer le select ***/
	    $dropdown .= '</select>'."\n";

	    /*** et retourne le dropdown complet***/
	    return $dropdown;
	}//Fin dropdown2



	/**
	 *
	 * @cree un dropdown select
	 *
	 * @param string $name
	 *
	 * @param array $options
	 *
	 * @param string $selected (optional)
	 *
	 * @return string
	 *
	 */
	function dropdownListener( $name, array $options, $selected=null,$nomtable="auto" ){
	    /*** Debutte le select ***/
            $nomfichier = 'viewInsertions.php';
	    $dropdown = "<select name='".$name."' id='".$name."' onchange='changerRubrique(this[selectedIndex].value);'>\n";

	    $selected = $selected;
	    /*** Boucler sur les options ***/
	    foreach( $options as $key=>$option ){
		/*** assigner un un valeur de selected ***/
		$select = ($selected==$key ) ? ' selected' : null;

		/*** ajouter chaque option au dropdown ***/
		$dropdown .= '<option value='.$key.' '.$select.'>'.$option.'</option>'."\n";
	    }

	    /*** Fermer le select ***/
	    $dropdown .= '</select>'."\n";

	    /*** et retourne le dropdown complet***/
	    return $dropdown;
	}//Fin dropdownListener

	/**
	 *
	 * @execute une requete MySQL
	 *
	 * @param string $query
	 *
	 * @retourne un resultset si la requete est de type DML(Data Manipulating Langauge ex : type SELECT , SHOW , DESCRIBE )ou  
     * @ne retourne rien si la requete est de type DDL(Data Definition Language ex : create , update , insert , grant) type query
	 * 
	 *
	 */
	function execute( $query ){
                 $hote = $_SERVER['SERVER_NAME'];
		 $ar = explode("." , $hote);
                 if($hote != "127.0.0.1" && $hote != "localhost" && $hote != "192.168.1.4" && $ar[0] != "192") {
			 $serveur = "db386100049.db.1and1.com"  ; 
		 	 $user = "dbo386100049"; $pass = "franklin";
		 }else{
		         $serveur = "localhost" ;
		 	 $user = 'root' ; $pass = '';
		 } 
		 
		 $db = mysql_connect($serveur,$user,$pass);
		 if(!$db){
			echo errmess("Erreur : &agrave; ".$_SERVER['PHP_SELF']." avec la fonction execute(\"$query\")<br>".
						 " impossible de se connecte a la base de donnees avec utilisateur : $user. l'hote $hote pass $pass \n".
						 "Essayez plus tard."
						);
			exit ;

		 }
		 //echo "selection bd <br>";
		 $nombd = selectionBd() ;//Retourne le nom de la base sur la quelle la requete sera executer
		 mysql_select_db($nombd , $db);
		 //echo "bd selectionner avec succes $nombd <br>";

		 $result = mysql_query($query,$db);


		$mess = "" ;
	
		if(!$result ){
			$no = mysql_errno() ;
		     if($no == 1045){
			$mess .=  "Mauvais mot de passe : '".$pass."' pour l'utilisateur '".$user.
			     "' ou alors cet utilisateur n'est pas valide";
			 
		     }else{
			  	
			$mess .=  errmess('Une erreur d\'execution de la requ&ecirc;te'); 
   			$mess .=  "Erreur " . mysql_errno() . " en SQL ";
  		        $mess .=  "<PRE>$query</PRE>";
   			$mess .=  mysql_error();
		     }
			//($email , $body , $nomperson , $title = "")
			$email = "ntuifranklin_2005@yahoo.fr";
			if( ! sendmeil($email , $mess ,"Unknown User at macadrr {$_SERVER['REMOTE_ADDR']}"))
				echo $mess ;
		}else{ 
		    return $result ;
		}
	

	}//Fin execute

        
        /**
	 * 
	 * @Retourneun message formatte 
	 *
	 * @param string $message
	 *
	 * @retourne  string
	 *
	 */
	function errmess($message){

			// Prends en parametre un message d'erreur , le format et le retourne
                        $tete = "<div style='font-family:verdana; font-size:5; font-weight:300;".
				"background-color:#f0fff0; width:250px' ;margin: 0.3em 0 0 0; font-color=blue>";
		        $pied = "</div>"; 
                        $titre = "<h5 >".
				 "<img src='images/redlight.png' width=20 height=20><font color=red>ANOMALIE DE DONNEES</font> </h5>";
                        $mess = $message ;
                        $message = "<br>".$mess ;
			return $tete.$titre.$message."<br>".$pied;
	}

 
        /**
	 * 
	 * @Retourne un message de success formatter
	 *
	 * @param string $message
	 *
	 * @return string
	 *
	 */
	function confmess($message){

			// Prends en parametre un message de confirmation , le format et le retourne
                        $tete = "<div style=\"font-family: verdana; font-size: 5; font-weight: 300;".
				"background-color: #b0c4de; width: 250px ;  border-width: 2px solid ; border-color: green ;margin: 0.3em 0 0 0; \">";
		        $pied = "</div>"; 
                        $titre = "<H5>".
				 "<img src='images/success.png' width=20 height=20><font color='blue'>Success d'operation</font> </H5>";
                        $mess = $message ;
                        $message = "".$mess ;
			return $tete.$titre.$message.$pied;
	}

/*	
div.success,
div.notice,
div.warning,
div.error {
    margin:             0.3em 0 0 0;
    border:             2px solid;
    <?php if ($GLOBALS['cfg']['ErrorIconic']) { ?>
    background-repeat:  no-repeat;
        <?php if ($GLOBALS['text_dir'] === 'ltr') { ?>
    background-position: 10px 50%;
    padding:            0.1em 0.1em 0.1em 36px;
        <?php } else { ?>
    background-position: 99% 50%;
    padding:            10px 5% 10px 10px;
        <?php } ?>
    <?php } else { ?>
    padding:            0.3em;
    <?php } ?>
}

.success {
    color:              #000000;
    background-color:   #f0fff0;
}

*/
     	/**
	 * 
	 * @Retourne un message de success formatter
	 *
	 * @param string $message
	 *
	 * @return string
	 *
	 */
	function prmess($message){

			// Prends en parametre un message de bonne fin , le format et le retourne
                        $tete = "<div style=\"font-family: verdana; font-size: 5; font-weight: 300;".
				"background-color: #b0c4de; width: 250px ;  border-width: 2px solid ; border-color: green ; margin: 0.3em 0 0 0;\">";
		        $pied = "</div>"; 
                        $titre = "<H5>".
				 "<img src='images/info.png' width=35 height=35> </H5>";
                        $mess = $message ;
                        $message = "".$mess ;
			return $tete.$titre.$message.$pied;
	}
	


	/**
	 * retourne la bd en cours d'utilisation
	 *
	 */
	function selectionBd(){
		$nombase = "db386100049";
		//$nombase = "shopforall";
		return $nombase ;
	}// Fin selectionBd

	/**
	 * @Inclus tous les fichiers necessaires	 
	 */
	function inclusionTete(){
                                
		
	 include_once('includes/header.inc');
               	 include_once("includes/navigauche.inc");


	}// Fin inclusionTete

	/**
	 * @Inclus tous les fichiers necessaires pour le bas de la page	
	 */
        
	function inclusionPied(){
               	 include_once('includes/footer.inc');
	}// Fin inclusionPied

        
	/**
	 * @Inclus tous les fichiers necessaires pour le haut de la page dans l'environnement du User
	 */
         function inclusionUserMenu(){
                include_once("includes/usernavigauche.inc");

         }
         
                        
	/**
	 * @Inclus tous les fichiers necessaires pour le haut de la page dans l'environnement du User
	 */
         function  showWelcomeMessage(){
	include_once("includes/welcomeMessage.inc");
         }

	/**
	 * @Inclus tous les fichiers classes  necessaires dans le repertoire class  
	 */
        
	function inclusionClasses(){
                include_once('class/Photo.inc');
                include_once('class/Object.inc');
                include_once('class/User.inc');
                include_once('class/AutoTab.inc');
                include_once('class/ElectroTab.inc');
                include_once('class/ImmobilierTab.inc');
                include_once('class/JobTab.inc');
                include_once('class/MeubleTab.inc');
                include_once('class/ObjArtTab.inc');
                include_once('class/ProdAgrTab.inc');
                include_once('class/VilleTab.inc');
                include_once('class/ProvinceTab.inc');
                include_once('class/Log.inc');
	}// Fin inclusionClasses


	/**
	 * @cree un tableau de rubriques	 
         *
	 * @retourne tableau
        */
        
	function getRubriquesAsArray(){
                $o = new Object();
		$options = $o -> getRubriques();
                                  
                return $options ;
                
	}/*** Fin getRubriquesAsArray ***/



	/**
	 * @cree un tableau de rubriques	 
         *
	 * @retourne tableau
        */
        
	function getRubriquesAndTableAsArray(){
                        
		$options = array(); 
		$ob = new Object(); $rubs = $ob -> getRubriques(); $tabs = $ob -> getTabs();
		for($i = 1 ; $i < count($rubs) ; $i++){
			$titchamp = $rubs[$i];
			$options[$titchamp] = $tabs[$i];

		}
                 
                return $options ;
                
	}/*** Fin getRubriquesAsArray ***/


        /**
	 * 
	 * @cree une liste de input de type=text avec labels associes a chaque rubrique.
	 *
	 * @param string $nom
	 *
	 * @param array $options
	 *
	 * @param string $checked 
	 * 
	 * @param tableau $t doit etre a une dimension et de meme longeur que celle de $options
	 *
	 * @retourne string
	 *
	 */
	function getRubriquesList( $nom, array $options, $checked=1 , array $t ){
	    
	    $liste = ""; 

                for($k=0;$k < count($options) ; $k++){
                        if($k == $checked)
                               $liste .= "<input type=\"radio\" id=\"$t[$k]\" name=\"$nom\" value=\"$k\" checked >\n<label for=\"$t[$k]\">$options[$k]</label>\n<br /> ";
                        else 
                                $liste .= "<input type=\"radio\" id=\"$t[$k]\" name=\"$nom\" value=\"$k\"  >\n<label for=\"$t[$k]\">$options[$k]</label>\n<br />";
                }

	    return $liste;
	}/*** Fin getRubriqueList ***/


        /**
	 * 
	 * @Retourne la valeur courante d'un autoincrement d'une table $nomtable
	 *
	 * @param string $nomtable
	 *
	 * @retourne int
	 *
	 */
        function getAutoIncrementValue($nomtable){

                                if(empty($nomtable)){
                                        echo 'Demande de valeur Auto_increment depuis /includes/LesFontions.inc avec un nom de table vide <br> Code Exit';
                                        exit ;

                                }  
                             $ask = "show table status where Name = '".$nomtable."' ;";
                             $nomdb = selectionBd();   
                             $result  = execute($ask);
                             $ligne   = mysql_fetch_assoc($result);
                             $value     = (int)$ligne['Auto_increment'];
                             $value-- ; 
        
                             return (int)$value;   



        }// Fin getAutoIncrementValue
        /**

	 * 

	 * @Retourne boolean si l'image pris en parametre est un jpeg ou jpg et la reduit pour sauvegarder en gif

	 *

	 * @param string $nomfichier , le nom du fichier dans input type=file, $folder le repertoire de sauvegarde , $nomfinal le nom final de ce fichier

	 *

	 * @retourne boolean

	 *

	 */
	function createJpeg($nomfichier , $folder , $nomFinal){//fonction qui prends en parametre un fichier jpeg temporaire et reduit considerablement sa taille
	
		$ext = getExtension($_FILES[$nomfichier]["name"]);
		$my_img = $_FILES[$nomfichier]["tmp_name"];
		$pref = getPrefixeFichier($nomFinal);
		$nomFinal = $pref ;
		$size = GetImageSize($my_img);

		if(is_dir($folder)){//Si le repertoire passer en parametre est valide
				
			switch ($size[2]) {//On determine les types de l'image charger
				case 2:
				$src_im = @imagecreatefromjpeg($my_img);
				$src_w = $size[0];
				$src_h = $size[1];
				$dst_w = 629;//Taille maximum souhaiter
				$dst_h = round(($dst_w / $src_w) * $src_h);
				$dst_im = @imagecreatetruecolor($dst_w,$dst_h);
				if(!imagecopyresampled($dst_im,$src_im,0,0,0,0,$dst_w,$dst_h,$src_w,$src_h)) return false;
				if(imagegif($dst_im, $folder."/".$nomFinal.".gif")){
					imagedestroy($dst_im);
					return true ;
				}
				break;
			}
			return false ;
			//Destruction de l'image temporaire en tampon pour liberer la memoire
		}else{
			//echo "Ce repertoire de sauvegarde d'image n'existe pas";
			return false;
		}

	}


        /**
	 * 
	 * @Retourne boolean si l'image pris en parametre est un gif ou png et la reduit pour sauvegarder en gif
	 *
	 * @param string $nomfichier , le nom du fichier dans input type=file, $folder le repertoire de sauvegarde , $nomfinal le nom final de ce fichier
	 *
	 * @retourne boolean
	 *
	 */
	function createGifAndPng($nomfichier , $folder , $nomFinal){//fonction qui prends en parametre un fichier temporaire qui n'est pas un jpeg et reduit considerablement sa taille
	
		$ext = getExtension($_FILES[$nomfichier]["name"]);
		$my_img = $_FILES[$nomfichier]["tmp_name"];
		$size = getImageSize($my_img);
		$pref = getPrefixeFichier($nomFinal);
		$nomFinal = $pref ;
	
		if(is_dir($folder)){//Si le repertoire passer en parametre est valide
			switch ($size[2]) {//On determine les types de l'image charger
				case 1: //un fichier gif
				$src_im = @imagecreatefromgif($my_img);
				break ;
				case 3: //un fichier png
				$src_im = @imagecreatefrompng($my_img);
				break;
			}	
			//Calcule dynamique de la taille
			$prcent = 103.0000 ;
			if( $size[0]*$size[1]< 25000000 && $size[0]*$size[1] >= 15000000 ){
				$prcent=99.9999 ;//1
			}
			if($size[0]*$size[1]<15000000 && $size[0]*$size[1]>= 5000000){
				$prcent=99.000 ;//2
			}
			if($size[0]*$size[1]<5000000 && $size[0]*$size[1]>= 1000000){
				$prcent=98.9999 ;//5
			}
			if($size[0]*$size[1]<1000000 && $size[0]*$size[1]>= 500000){
				$prcent=98.000 ;//10
			}
			if($size[0]*$size[1]<500000 && $size[0]*$size[1]>= 100000){
				$prcent=97.999 ;//10
			}
			if($size[0]*$size[1]<100000 && $size[0]*$size[1]>= 50000){
				$prcent=97.00 ;//20
			}

			$largeMax = $size[0];
			$hauteMax = $size[1];
			$hauteurVignette = (1.0 * $hauteMax*($prcent*1.0))/(100.0 );
			$largeurVignette = (1.0 * $largeMax*($prcent*1.0))/(100.0 );
			//echo "pour centage = $prcent largeur = $largeurVignette, hauteur = $hauteurVignette<br>large initiale = $largeMax, haute initiale = $hauteMax" ;	


			if($size[2] != 1 ){//Si l'image  n'est pas un gif
				$dst_im = imagecreatetruecolor($largeurVignette, $hauteurVignette) ;
			}else{//c'est un gif. donc on cree une image vide
				$dst_im = imagecreate($largeurVignette, $hauteurVignette);
			}		
		
			if(!imagecopyresized($dst_im, $src_im, 0, 0, 0, 0 ,$largeurVignette, $hauteurVignette, $largeMax, $hauteMax)){
				return false;
			}

			if(imagegif($dst_im, $folder."/".$nomFinal.".gif")){
				imagedestroy($dst_im);
				return true ;
			}			//Destruction de l'image temporaire en tampon pour liberer la memoire
		
		}else{
			//echo "Ce repertoire de sauvegarde n'existe pas";
			return false ;
		}

	}

        /**
	 * 
	 * @Retourne un le chemin d'acces a un fichier copier venant de la machine cliente
	 *
	 * @param fichier $nom
	 *
	 * @return string
	 *
	 */
        function copyFile( $nom , $nomtable , $objectId){// Prends un fichier uploader depuis chez le client et le  copie au repertoire ./files
            //Retourne une erreur si les droits d'acces du repertoire est different de : 0777 pour un serveur linux
                $pho = new Photo();
                $lien = 0 ;
                $nbimages = $pho -> getTotalNb();
                $nouveauNomImage = $nbimages + 1 ;
                $fichiertemp    = $_FILES[$nom]["tmp_name"]; $taille = $_FILES[$nom]["size"] ;
                $nomfichier     = $_FILES[$nom]["name"]; $repertoire = getUserFileDir();
                $lien = "";
                if( is_uploaded_file($fichiertemp) && $taille != 0 ){
                        

                     if( ! is_dir($repertoire)){//Verifier si le repertoire existe, sinon le cree
                                mkdir($repertoire);chmod($repertoire."/" , 0777);
                     }
                        
                               
                     if(move_uploaded_file( $fichiertemp, $repertoire."/" . $nouveauNomImage ) &&  chmod($repertoire."/" . $nouveauNomImage  , 0777)){
                                
                                $lien =  $nouveauNomImage ;
                                                 
                                //echo "<br>Nb images :$nbimages <br>";
                                $pho -> setId($nouveauNomImage);
                                $pho -> setObjectId($objectId);
                                $pho -> setTableAppartenance($nomtable);
                                $pho -> create();
                        }
                 }
                return $lien ;

        }// Fin copyFile

        /* This function is used to reset the session
        *        
        */
        function sessionReset(){//Pour refaire la session.
		//Si un user etait déja connecté alors on recupère son user pseudo
		if(sessionExists()){
		        $nomuser = getUserName();//Retourne le pseudonyme du user en cours de connexion
		        $_SESSION['objEnAttente'] = 0 ;
		        unset($_SESSION);
		        $_SESSION = array();
		        createSession($nomuser);
		}else{
		        unset($_SESSION);
		        $_SESSION = array();
		}

        }

        /* Cette fonction est utilisée pour dire à la session qu'un mail de confirmation d'inscription viens d'être envoyée chez le user
        *        
        */
	function confMailSess(){
			   $_SESSION['confmailsent']  = true ;//On precise que le mail de confirmation à été envoyé
	}

        /* Cette fonction est utilisée pour dire à la session qu'un mail de confirmation d'inscription viens d'être envoyée chez le user
        *        
        */
	function confMailWasAnswered(){
			   $_SESSION['confmailans']  = true ;//On precise que le mail de confirmation à été repondu
			   return (isset($_SESSION['confmailsent']) && $_SESSION['confmailans'] == true ) ;	
	}

        /* Cette fonction est utilisée pour dire si un mail de confirmation d'inscription viens d'être envoyée chez le user
        *        
        */
	function confMailWasSent(){
			   return (isset($_SESSION['confmailsent']) && $_SESSION['confmailsent'] == true )  ;//On precise que le mail de confirmation à été envoyé
	}

        /**
	 * 
	 * @Verifie si un utilsateur est connecter
	 *
	 * @retourne booleen
	 *
	 */
	 function sessionExists( ){
				$booleen = false ;
				if(! empty($_SESSION['uzer'])) $booleen = true ;

				return $booleen ;

	}//Fin sessionExists


        /**
	 * 
	 * @Verifie si un utilsateur est connecter et laisse l'affichage continu de la page sinon affihe le formulaire de connection
	 *
	 *
	 */
	 function backToStart( ){
				$pageDeConnexion = "connect.php";
				if( ! sessionExists()){
					include_once($pageDeConnexion);
					exit ;
				}

	}//Fin backToStart


        /**
	 * 
	 *
	 * @retourne String
	 *
	 */
        function getUserName( ){
               
                if(sessionExists())
                 return $_SESSION['uzer'] ;
                else
                 return "Inconnu";

        }//Fin getUserName


        /**
	 * 
	 * @Permet de demarrer une session pour l'utilisateur
	 *
	 * @Ne retourne rien
	 *
	 */
        function createSession($pseudoUtilisateur ){
                $_SESSION['uzer']= $pseudoUtilisateur;
                $_SESSION['conn']= true ;        
        }//createSession

        /**
	 * 
	 * @Permet de verifier si l'email pris en parametre est valide
	 *
	 * @ retourne vrai ou faux 
	 *
	 */
        function emailIsValid($email){
			$tabemail = explode('@',$email); 
			//si le tableau est de taille inferieure a 1 ou superieure a 2
			$b =  (count($tabemail) == 2 && ! empty($tabemail[0]) && ! empty($tabemail[1]) ) ? true : false;   
			return $b ;   
        }//emailIsValid

        /**
	 * 
	 * @Permet d'envoyer un mail
	 *
	 * @ retourne vrai ou faux 
	 *
	 */
        function sendmeil($email , $body , $nomperson , $title = ""){
                        $to = $email;
                        $subject = "Bonjour $nomperson !";
			if($title != "") $subject = $title ;
			/* To send HTML mail, you can set the Content-type header. */
			$headers = "MIME-Version: 1.0\r\n";
			$headers .= "Content-type: text/html; charset=iso-8859-1\r\n";

                       // $body = "Hi,\n\nHow are you?";
                         if (mail($to, $subject, $body , $headers. "From: webmaster@{$_SERVER['SERVER_NAME']}\r\n".
							 "Reply-To: webmaster@{$_SERVER['SERVER_NAME']}\r\n".
							 "X-Mailer: PHP/" . phpversion())) {

                          return true ;
                          } else {
                           return false ;
                          }
        }//sendmeil


        /**
	 * 
	 * @Permet d'envoyer un mail
	 *
	 * @ retourne vrai ou faux 
	 *
	 */
        function getServerName(){
			return $_SERVER['SERVER_NAME'] ;
        }//getServerName

        /**
	 * 
	 * @ Retourne un tableau contenant le nom de toutes les tables dans mysql correspondant a chaque rubrique
	 *
	 * @ retourne un tableau
	 *
	 */
        function getRubriqueTableAsArray(){
			/*** A noter que le tableau ci dessous contient pour chaque valeur, le meme nom pour une rubrique comme table sur bd*/
			$t = array();
			$oj = new Object();
			$t = $oj -> getTabs();
			return $t ;  

                
        }//getRubriqueTableAsArray


         /**
	 * 
	 * @ Retourne un tableau contenant le nom de toutes les tables dans mysql correspondant a chaque rubrique
	 *
	 * @ retourne un tableau
	 *
	 */ function showUserInserts($nomtable , $defaultQuery = "" , $norubr = 0 , $pagination = true , $borne=0 ){
                        //Retourne les lignes de cette rubrique pour ce User s'il en a 
                        $cl = new $nomtable(); $pho =  new Photo(); $imids = array();//Stockera les id des images
                        //$t = $cl -> getAttribAsArray() ;//La liste des champs visualisable par cette objet
                        $t = array("Titre","Ville","Prix");$rubs = getRubriquesAsArray();
                        $ville = new Ville(); 
                        $inserts = "";
                        $user = new User(); $user -> setPseudo(getUserName()) ; $user -> loadData();
                        $userid = $user -> getUserId(); $inscrit = $user -> getInscrit();
                        
                        $query =(empty($defaultQuery)) ? "select * from ".$nomtable." where 1 order by Date_ins desc" : $defaultQuery;
                        $res = execute($query);$nblignes = getNbVisualisedLines() ;//Retourne le nombre de ligne à visualiser dans les resultats d'un select
			$nbpages = 0 ;
                        if($norubr > 0 ){
                                $titreRub = $rubs[$norubr];
                        }
			$nbresul = mysql_num_rows($res) ; $resteDiv = 0;
			//On verifie si la requete est deja paginee , si oui on ne la pagine plus
			$queryArray = explode(" limit " , $query);
			if(count($queryArray) > 1) $pagination = false ; $lienPaginee = "" ;
                        if($nbresul > 0 ){//On verifie qu'il ya des insertions , s'il yen a on l'affiche sinon on degage 

			//On essaiera d'afficher les liens pour les pages de sorte que le user puisse naviguer entre ces pages
				
				if($nbresul > $nblignes && $pagination == true ){
					$taille = " width=40 height=30 " ;
					$next = "<img src=\"images/nextpage.png\" $taille title='Prochaine page'>";
					$lastpage = "<img src=\"images/lastpage.png\"  $taille title='Derniere page'>";
					$back = "<img src=\"images/prevpage.png\"  $taille title='Reculer page'>" ; 
					$firstpage = "<img src=\"images/firstpage.png\" $taille title='Premiere page'></a>" ;
					$res = execute($query . " limit $borne , $nblignes"); //echo prmess( $query . " limit $borne , $nblignes" ) ;
					$resteDiv = ($nbresul % $nblignes ) ;
					$nbpages = ($nbresul - $resteDiv) / $nblignes ;
					if($resteDiv > 0)
					$nbpages += 1 ;
					if($borne == 0){//Pour l'affichage de la page numero en cours de visualisation
					$nopage = 1 ;
					}else{ 
						$nopage = ($borne / $nblignes) + 1 ;
					}
					$u=0;
						$prochain = $nopage + 1;
						$precedent = $nopage - 1 ;
					if($nopage > 1 && $nopage < $nbpages){//On est ni à la derniere ni à la premiere
						$avancer = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=$prochain&nr=$norubr\">$next</a>" ;
						$reculer = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=$precedent&nr=$norubr\">$back</a>" ;
						$derpage = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=$nbpages&nr=$norubr\">$lastpage</a>" ;
						$prepage = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=1&nr=$norubr\">$firstpage</a>" ;
					}elseif($nopage == $nbpages ){//On est à la derniere page
						$avancer = "<a class='topnav' href=\"#\">$next</a>" ;
						$reculer = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=$precedent&nr=$norubr\">$back</a>" ;
						$derpage = "<a class='topnav' href=\"#\">$lastpage</a>" ;
						$prepage = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=1&nr=$norubr\">$firstpage</a>" ;
					}else{
						$avancer = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=$prochain&nr=$norubr\">$next</a>" ;
						$reculer = "<a class='topnav' href=\"#\">$back</a>" ;
						$derpage = "<a class='topnav' href=\"pageview.php?tit=$titreRub&nt=$nomtable&np=$nbpages&nr=$norubr\">$lastpage</a>" ;
						$prepage = "<a class='topnav' href=\"#\">$firstpage</a>" ;
					}					
					
					$lienPaginee .= "<font size=4 color=green> Page $nopage $prepage $reculer <font size=6 color=black> [ </font>" ;
					for($u=1;$u<$nbpages + 1 ; $u++)
					$lienPaginee .= "<u><a href=\"pageview.php?nt=$nomtable&np=$u&nr=$norubr\" title=\"Page $u\">$u</a></u> ";
					$lienPaginee .= " <font size=6 color=black> ] </font> $avancer $derpage  </font>" ;
					//echo prmess($avancer ."  ". $reculer . "  " . $derpage . " " . $prepage);
				}
			$inserts .= $lienPaginee ;
                        $inserts .= "<div>";
                        $inserts .= "<table style=\"border-width: 2px; border-style: solid; border-color: white; cellpadding: 1 ; cellspacing: 1;\">";
                        $titreRub = "Undefined";
                        if($norubr > 0 ){
                                $titreRub = $rubs[$norubr];
                        }
                        $inserts .= "<caption><font color=blue size32>Insertions concernant la rubrique ".$titreRub."</font></caption>";
                        //Affichage de la ligne titre du tableau
                        $alignem = "align=center ";//Alignement du tableau
                        $inserts .= "<tr>" ;
                        $inserts .= "<td $alignem>";
			$inserts .="<u><font size=2>Les images de l'insertion</font></u></td>" ;
                        foreach($t as $titre => $nomchamp)
                        $inserts .= "<td $alignem><u><font size=2>".$t[$titre]."</font></u></td>" ;
                        $inserts .= "<td $alignem colspan=2><u><font size=3>Actions</font></u></td>" ;
			//Affichage de la date d'insertion
                        //$inserts .= "<td $alignem>Date de creation</td>" ;
                        //$inserts .= "<td $alignem>Date de derniere modification</td>" ;
                        $inserts .= "</tr>" ;
                        //Affichage des differentes lignes de la table
                                $i = 0 ;
				
				$pasDimage = getNoImage() ;//Image par defaut pour objets n'ayant pas d'images
                                while($l = mysql_fetch_assoc($res)){
				$inserts .= "<tr><td align=center colspan=7><hr><tr>"; //Pour eparer en lignes
                                $titretd = "title=\"objet numero ".$l[str_replace("Tab","",$nomtable)."Id"]."\"";
                                $i++ ;
                                if($i % 2 == 0)//Even line 
                                $style = "class='even'";
                                else
                                $style = "class='odd'";
                                $objectid =  $l[str_replace("Tab","",$nomtable)."Id"];
                                $inserts .= "<tr ".$style." >" ;
				//Affichage des images de l'objet
                                
                        	$inserts .= "<td $alignem $titretd>" ; 
				$inserts .= (sessionExists() && $l['UserId'] == $userid) ? "<img src='images/ouvert.png' title=\"Vous pouvez modifier cette insertion en cliquant sur l'icon modifier\" width=20 height=20>" : "<img src='images/fermer.png' title='Vous ne pouvez pas modifier cette insertion' width=20 height=20>"; 
				$tableId = str_replace("Tab","",$nomtable)."Id" ;
				$imids = $pho -> getAllImages($l[$tableId],$nomtable);//Recuperation des images appartenant a cet objet
				//Affichage des images
				$minImage = 0 ; $maxImage = count($imids) - 1 ;
				$v = rand($minImage,$maxImage);//On n'affiche qu'une seule image aleatoire entre toutes les images disponibles
                                if(count($imids) > 0){
				       		
                                                $nomimage = $pho -> getImage($imids[$v]) ;
					        $imagefile = getUserFileDir()."/$nomimage";
						$ext = getExtension($nomimage);
					        //on double le nn pour ne pas confondre avec ce que php utilise
					        if( is_file($imagefile) && extensionIsValid($nomimage) && $ext != "pdf" && $ext != "docx" && $ext != "doc"){//si image n'est pas un cv ou un prospectus de service 
					       		 
							$inserts .= "<a href='fullview.php?nt=$nomtable&nr=$norubr&oid=".
							"$objectid'><img src='".$imagefile.
			                                "' width=50 height=50 title=\"Visualiser cette image no ".($v + 1).
							" en grand format \" alt=\"Image manquant\" ></a>";

                                                }elseif(isPdfWord($nomimage)){//Si le fichier joint est un document word ou pdf
							$inserts .= "<a href='fullview.php?nt=$nomtable&nr=$norubr&oid=".
							"$objectid'><img src='images/pj.png' width=30 height=30 title=\"Il y'a une Pi&egrave;ce jointe &agrave; cette insertion\"></a>";
						}else{
							$inserts .= $pasDimage;
						}
                                }else{
					        $inserts .= $pasDimage;
                                }
				$inserts .= "</td>" ;
                                //Maintenant on affiche le titre de l'objet
                                 $ville -> setId($l['VilleId']); $ville -> loadDataFromId();
                                 $nomville = $ville -> getNom();
                                 $prix = $l[str_replace("Tab","",$nomtable)."_prix"];
                                if(($nomtable == "JobTab")){
                                        $nom = stripslashes($l["Job_nom"]); $prix = "Non pr&eacute;cis&eacute;";
                                }else{
                                        $nom = stripslashes($l[str_replace("Tab","",$nomtable)."_nom"]);
                                }

				$inserts .= "<td title=\"Intitule $nom\">";
                                $inserts .= "$nom</td>";//Pour le titre
                                
                                $inserts .= "<td title=\"Le lieu est $nomville\">$nomville  </td>";//Pour la ville
                                $inserts .= "<td title=\"Le prix &agrave; payer(louer)\">$prix</td>";//Pour le prix
				$titreObjet = $nom;//Le titre qui sera vue lors de la visualisation des details
                                $inserts .= "<td $alignem title=\"Les details de cette insertion\" ><a href=\"fullview.php?nt=".
				"$nomtable&nr=$norubr&oid=$objectid&tit=$titreObjet\" >Voir details</a></td>" ;
                                if($l["UserId"] == $userid && $inscrit == 1){
                                $taille = "width=25 height=25";
                                $inserts .= "<td><a href=\"editinsertion.php?nt=$nomtable&oid=$objectid&nr=$norubr&tit=$nom\">".
                                "<img src='images/edit.png' title=\"Modifier cette insertion\" $taille></td>";




                                $inserts .= "<td><a href='deleteinsertion.php?nt=$nomtable&oid=$objectid&nr=$norubr&tit=$nom'>".
                                "<img src='images/delete2.png' title=\"Supprimer cette insertion\"   $taille onclick=\"return confirm('Voulez vous vraiment effectuer cette action de suppression ? ')\"></td>";
                                }
                                $inserts .= "</tr>" ;
                                


                                };
                              
                        $inserts .= "</table>";
			$inserts .= $lienPaginee ;
                        $inserts .= "</div>";
                        }
			//$inserts = prmess("La requete &agrave; echou&eacute;") ;
                        return $inserts ;

                }
        /**
	 * Retourne un tableau contenant les attributs d'un object indexable sur une table-rubrique, et permettant d'affiner une recherche 
	 *
	 *
	 * @retourne tableau
	 *
	 */
        function getObjectPropAsArray(){
                $tab = array("id","titre","lieu","prix","taille","couleur","poids","datemise");
                return $tab ;

        }//Fin getObjectPropAsArray	


        /**
	 * Retourne un tableau contenant les differents types d'insertions ==> array(offre , demande , location-offre , location-demande)
	 *
	 *
	 * @retourne tableau
	 *
	 */
        function getAsArrayObjTyp(){
                $tab = array(
                                "Mettez en vente" => 00 ,
                                "Recherchez/Voulez acheter" => 01 ,
                                "Mettez en location" => 10 ,
                                "Voulez louer" => 11
                );
                return $tab ;

        }//Fin getAsArrayObjTyp

        /**
	 * Retourne une liste deroulante contenant les differents types d'insertions ==> array(offre , demande , location-offre , location-demande)
	 *
	 *
	 * @retourne String
	 *
	 */
        function getDropDownObjTyp($nomListe, $selected=null){
                $tab = getAsArrayObjTyp() ;
                $dropdown = "";
                $dropdown .= "<select name='$nomListe'>";
                foreach($tab as $field => $value)
                        if( (!empty($_POST[$nomListe]) && $_POST[$nomListe] == $value ) || $selected == $value)
                                $dropdown .= "<option value=$value selected>$field";
                        else
                                $dropdown .= "<option value=$value >$field";
                $dropdown .= "</select>";

                return $dropdown ;
        }//Fin getDropDownObjTyp

	
        /**
	 * Retourne une formulaire pour l'envoi d'une annonce a un ami
	 * Prends en parametre le nomde la table au quel a[pprtient l'insertion pour envoi , l'id de l'insertio et l'id de la rubrique
	 * auquel l'insertion appartient
	 *
	 * @retourne String
	 *
	 */
        function sendAnnonceForm($nomtable, $objectid , $rid){
		$form = "";
	 if(!empty($nomtable) && is_numeric($objectid) ){
		$form .= "<br><br><form action='sendmail.php' method=get name='envoiannonce' onSubmit=\"return ck7() ;\">";
			$obliger = "<font color=red size=2>*</font>"; $petitmessage = "( ".$obliger." ) => champs obligatoires";  
			$alaligne =" </td><td>";	
			$fontTitreDebut ="<u><H2>" ;
			$fontTitreFin = "</H2>" ;
			$tr = "<tr><td align=right>" ;	
			$form .= "<table>";
			$form .= "$tr Votre Pseudonyme $alaligne <input type=text name='pseudo' value='".stripslashes($_GET['pseudo'])."'  size=20 >".
			"$obliger</td></tr>";      
			$form .= "$tr Votre email $alaligne <input type=text name='email' value='".stripslashes($_GET['email'])."'  size=20 >$obliger</td></tr>";          
			$form .= "$tr L'email de votre ami $alaligne <input type=text name='emailami' value='".stripslashes($_GET['emailami'])."'  size=20 >".
			"$obliger </td></tr>"; 
			$form .= "<tr><td colspan=2 align=center>". $petitmessage . "</tr>";   
			$form .= "<tr><td colspan=2 align=center><p align=center><input type=submit value='Envoyer' name='sendannonce'></p></tr>";
			//messtype=2&nt=$nomtable&oid=$objectid&rid=$rid
			$form .= "<input type=hidden name=messtype value=2>";      
			$form .= "<input type=hidden name=nt value='$nomtable'>"; 
			$form .= "<input type=hidden name=oid value=$objectid>";
			$form .= "<input type=hidden name=nr value=$rid>";                 
			$form .= "</table>";

		$form .= "</form>";
	}
	return $form ;
        }//Fin sendAnnonceForm
      
		
	/*
	* Fonction qui prends en parametre un tableau d'attributs et le retourne un tableau formatte contenu dans un formulaire
	* $titre garde le titre du formulaire
	* $actionFile est le fichier a executer sur le serveur lors de l'envoi
	* $name est le nom qu'on donnera au formulaire pour l'identifier sur le serveur
	* $tabValeurs est le tableau d'attributs a afficher
	* $numTableListe est le numero de la table mysql dans la liste des tables corespondant a chaque rubrique
	*
	*/

	function getForm($titre , $actionFile , $name , array $tabValeurs,$numTableListe , $objtyp = 00){
		$form = "" ; 
		$norubr = $numTableListe ;//Le numero de cette rubrique dans la table des rubriques
		$arr = getRubriquesAsArray();
		$ti = $arr[$norubr];
		$form .= "<form enctype='multipart/form-data' action='$actionFile' method='POST' name='$name' onSubmit=\"return w('$name') || generalVF('$name');\">";
                $form.= "<input type=hidden name='MAX_FILE_SIZE' value='".getMaxFileSize()."'  >";
		$form .= "<table>";
		$form .= "<caption><u> <font color=blue size=2>";
                $form .= "Decrivez votre insertion ".ucfirst($ti)." en remplissant ce formulaire ci dessous </caption>";
		$pr = new Province() ; $ville = new Ville();
		$t = array () ;
		$t = $tabValeurs ;
		$longeur = count($tabValeurs);
		$i=0; $M=1;
			if($longeur >= 4)
			$M=2;
		$provid = $_POST['provid'] ;$nomProvince = $pr -> getProvinceFromId($provid) ;
		$form .= "<tr><td colspan=6 align=center title=\"Choix de la ville \">Choisir une ville dans la province ".$nomProvince." ".
		$ville -> getVilleProvince($provid , "villeid"). "</td></tr>" ;
		foreach($t as $field => $value){
		        $i++ ;
                        $haystack = $value ; $needle = "_desc";
                        $pos = strpos($haystack,$needle);

                        if( ! ($pos === false)) {//On veut mettre le champ description dans un textarea et non un input
                         
		                if($i == 1 ){
                                        $nblignes = "rows=10 cols=20";
			                $form .=  "<tr><td align=right>".ucfirst($field)."</td>" ;
			                $form .= "<td><textarea name='$value'  ".$nblignes.">".stripslashes($_POST[$value])."</textarea>  </td>" ;
		                }elseif($i == $M ){
			                $form .= "<td align=right>".ucfirst($field)."  </td>" ;
			                $form .= "<td><textarea  name='$value' ".$nblignes.">".stripslashes($_POST[$value])."</textarea>   </td></tr>" ;
		                   $i = 0 ;		
		                }else{
			                $form .=  "<td align=right>".ucfirst($field)." </td>" ;
			                $form .= "<td><textarea  name='$value' ".$nblignes.">".stripslashes($_POST[$value])."</textarea>   </td>" ;


                                }

                        }else{//On place les attributs dans un input et non un textarea

				$ajout = "";
		                $haystack = $field ; $needle = "prix";
		                $posCh = strpos($haystack,$needle);//Si le champ est un champ de prix
				if($posCh === true ) $ajout = "CFA";
		                $needle = "masse";
		                $posCh = strpos($haystack,$needle);//Si le champ est un champ de masse
				if($posCh === true ) $ajout = "kg";
		                $needle = "Puissance";
		                $posCh = strpos($haystack,$needle);//Si le champ est un champ de puissance
				if($posCh === true ) $ajout = "Chevaux";
				$taille = " size=20 " ;
		                if($i == 1 ){
			                $form .=  "<tr><td align=right>".ucfirst($field)." </td>" ;
			                $form .= "<td><input type=text name='$value' value=\"".stripslashes($_POST[$value])."\" $taille>$ajout  </td>" ;
		                }elseif($i == $M ){
			                $form .= "<td align=right>".ucfirst($field)." </td>" ;
			                $form .= "<td><input type=text name='$value' value=\"".stripslashes($_POST[$value])."\" $taille>$ajout  </td></tr>" ;
		                   $i = 0 ;		
		                }else{
			                $form .=  "<td align=right>".ucfirst($field)." </td>" ;
			                $form .= "<td><input type=text name='$value' value=\"".stripslashes($_POST[$value])."\" $taille>$ajout  </td>" ;
                                }
                        }	
		} 
                //On l'utilisera pour placer le nom du champ pour 
                //le type d'insertion et elle sera utiliser dans la 
                //classe enregistreuse
                
		$form .= "<input type=hidden name='norubr' value=$norubr>";
		$form .= "<input type=hidden name='objtyp' value=$objtyp>";
		$form .= "<input type=hidden name='titreRub' value=\"$titre\">";
		$form .= "<input type=hidden name='provid' value=\"$provid\">";
                //On doit afficher les images pour uploading

		if( ($objtyp != 1 && $objtyp != 11)  && ($norubr != 6 && $norubr !=  7) && sessionExists()){
                //Si la rubrique n'est pas un service , un job ou alors l'objet n'est pas une recherche de location ,
                //une recherche d'emploi alors on n'affiche pas de champ pour charger l'image
		        $form .= "<tr><td align=center colspan=2><img src='images/pj.png' height=24 width=24><font size=3>Joindre des images &agrave; cette insertion : </font></td></tr>";
		        $NB = 1 ;
		        if(sessionExists())
		        $NB = 3 ;


		        for($i=0;$i<$NB;$i++){
		                $no = $i + 1 ;
		                $form .= "<tr><td>Image ".$no."</td><td><input type=file name='im".$no."'></td></tr>";
		        }
			$form .= "<input type=hidden name='maximages' value=$NB>";//Pour le nombre maximum d'images a uploader
		}


		if( ($objtyp == 01)  && ($norubr == 6) && sessionExists()){//La rubrique est un job et la personne recherche du job
                //Si la rubrique est un job alors on donne la possibilté d'uploader un cv
		        $form .= "<tr><td align=center colspan=4>Uploadez votre CV au format word ou pdf : <input type=file name='fichier'></td></tr>";
		}


		if( ($objtyp == 00 || $objtyp == 10)  && ($norubr == 7) && sessionExists()){//La rubrique est un service et la personne vend/met en location ses services
                
		        $form .= "<tr><td align=center colspan=4>Uploader une description de vos services au format word ou pdf : <input type=file name='fichier'></td></tr>";
		}



		$t = getRubriqueTableAsArray();
		$nom = $t[$norubr];
		$form .= "<tr><td colspan=6 align=center><input type=submit name='$nom' value=\"OK\" onclick=\"return verifForm();\"></td></tr>";
		$form .= "</table>";
		$form .= "</form></center>";
		return $form ;


	}


	/*
	* Fonction qui prends en parametre un tableau d'attributs et le retourne un tableau formatte contenu dans un formulaire pour modification
	* $titre garde le titre du formulaire
	* $actionFile est le fichier a executer sur le serveur lors de l'envoi
	* $name est le nom qu'on donnera au formulaire pour l'identifier sur le serveur
	* $tabValeurs est le tableau d'attributs a afficher
	* $_T est le tableau ($l=mysql_fetch_assoc(....)) qui contient les attributs a modifier
	*/

	function getModifyForm( $actionFile , $nom , $nomtable,array $tabValeurs,  $_T = array(), $objectid){
		$form = "" ; $o = new Object(); $nt = $nomtable ; 
                $norubr = $o -> getNoRubrique($nomtable , $objectid);
                $tabr = getRubriquesAsArray();$tit = $tabr[$norubr];
		//if(   ! is_array($_T) || ! (count($_T) < 1) ) $_T = $_POST ;//Si le tableau $_T n'est pas placer
		$form .= "<center><form  method='POST' action='$actionFile' enctype='multipart/form-data'   name='$nom' >";
                $form .= "<input type=hidden name='MAX_FILE_SIZE' value='".getMaxFileSize()."'  >";
		$form .= "<table>";
		$form .= "<caption><u> <font color=blue size=2>";
                $form .= "Modifiez votre insertion \"{$_GET['ancientit']}\" ci dessous en modifiant ce formulaire </caption>";
		$pr = new Province();
		$t = array () ;
		$t = $tabValeurs ; 
                //Dans chaque table , les *_lieu sont devenus des VilleId , ce qui fait qu'il faut remplacer la VilleId par sa ville de nom 
                $villeid = $_T['VilleId'] ;
                $ville = new Ville() ; $ville -> setId($villeid); $ville -> loadData() ;$nomville = $ville -> getNom();
		$longeur = count($tabValeurs);
		$i=0;
			if($longeur < 4)
				$M=3;
			else
				$M=2;
		$selected = $_T['VilleId'] ;//L'id de la ville de cet objet , c'est elle qui sera selectionner lors de l'affichage de la liste
		$form .= "<tr><td align=right title=\"Choix de la ville \">Votre ville </td><td>".$ville -> getDropDownVilles("VilleId" , $selected ). 
		"</td></tr>" ;
		foreach($t as $field => $value){
		        $i++ ;
                        $haystack = $value ; $needle = "_desc";//Pour le choix des types de champs , input ou textarea
                        $pos = strpos($haystack,$needle);

                        if( ! ($pos === false)) {//On veut mettre le champ description dans un textarea et non un input
                         
		                if($i == 1 ){
                                        $nblignes = "rows=10";
			                $form .=  "<tr><td align=right>".ucfirst($field)." : </td>" ;
			                $form .= "<td><textarea name='$value'  ".$nblignes.">".stripslashes($_T[$value])."</textarea>  </td>" ;
		                }elseif($i == $M ){
			                $form .= "<td align=right>".ucfirst($field)." : </td>" ;
			                $form .= "<td><textarea  name='$value' ".$nblignes.">".stripslashes($_T[$value])."</textarea>   </td></tr>" ;
		                   $i = 0 ;		
		                }else{
			                $form .=  "<td align=right>".ucfirst($field)." : </td>" ;
			                $form .= "<td><textarea  name='$value' ".$nblignes.">".stripslashes($_T[$value])."</textarea>   </td>" ;
                                }

                        }else{//On place les attributs dans un input et non un textarea
                                if($field == "Ville") $_T[$value] = $nomville ;//Pour permettre l'affichage du nom de la ville et pas de son id
				$taille = " size= 20 " ;
                                if($i == 1 ){
			                $form .=  "<tr><td align=right>".ucfirst($field)." : </td>" ;
			                $form .= "<td><input type=text name='$value' value=\"".stripslashes($_T[$value])."\" $taille >  </td>" ;
		                }elseif($i == $M ){
			                $form .= "<td align=right>".ucfirst($field)." : </td>" ;
			                $form .= "<td><input type=text name='$value' value=\"".stripslashes($_T[$value])."\" $taille >  </td></tr>" ;
		                   $i = 0 ;		
		                }else{
			                $form .=  "<td align=right>".ucfirst($field)." : </td>" ;
			                $form .= "<td><input type=text name='$value' value=\"".stripslashes($_T[$value])."\" $taille >  </td>" ;
                                }
                        }
		} 
		$form .= "<input type=hidden name='maximages' value=$NB>";//Pour le nombre maximum d'images a uploader
		$form .= "<tr><td colspan=4 align=center><input type=submit name='$nom' value=\"Modifier\"></td></tr>";
		
                $pho = new Photo();
                //On l'utilisera pour placer le nom du champ pour 
                //le type d'insertion et elle sera utiliser dans la 
                //classe enregistreuse
                $objectid = $_REQUEST['oid']; $villeid = $_T['VilleId'] ;
                $nomm = str_replace("Tab","",$nomtable);
		$form .= "<input type=hidden name='titreRub' value=\"$titre\">";
		$form .= "<input type=hidden name='oid' value=$objectid>";
		$form .= "<input type=hidden name='nomtable' value=\"$nomtable\">";
		$form .= "<input type=hidden name='norubr' value=$norubr>";
                //On doit afficher les images pour uploading de modification cad , si il a les images , on affiche et on le permet de modifier ,
               
                $no = $i + 1 ;
               
                $imids = array();
	        $imids = $pho -> getAllImages($objectid,$nomtable);//Recuperation des images appartenant a cet objet
	        //Affichage des images
                
           
                $NB = count($imids) ;$longeur = 100 ; $largeur = $longeur ;
		if($NB <= 3)//Cet objet n'avait pas d'images => on donne la possibilite d'ajouter des images
                   $NB = 3 ; $rep = getUserFileDir();
		$objtyp = $o -> getObjTyp($nomtable , $objectid);
		if(count($imids) > 0 )
			$mess2  = "Images jointes " ;
		else
			$mess2 = "Attacher des images" ;
		if( ($objtyp != 1 && $objtyp != 11)  && ($norubr != 6 && $norubr !=  7) ){
                $form .= "<tr><td align=center colspan=2>$mess2 &agrave; cette insertion : </td></tr>";
                        for($v=0;$v<$NB;$v++){
                         $imagefile = "$rep/".$pho -> getImage($imids[$v]);
                                 //on double le nn pour ne pas confondre avec ce que php utilise
	                        if(is_file($imagefile) ){
					$mess = "Remplacer cette image ";	
	                        $form .= "<tr><td colspan=1><a href='$imagefile'><img src='".$imagefile.
                                "' width=$largeur height=$longeur title=\"Image no ".($v + 1)."\" alt=\"Image manquant\"></a>".
				 "<td colspan=2><a href='imageupdate.php?idimage=".$imids[$v]."&nomtable=$nomtable&oid=$objectid'  ".
				" name='im".($v + 1)."' title='$mess'>$mess</a></tr>";
				//<img src='images/pj.png'>
				}else{
					$mess = "Charger une image ";	
	                        $form .= "<tr>".
				 "<td colspan=1><a href='imageupdate.php?idimage=".$imids[$v]."&nomtable=$nomtable&oid=$objectid'  ".
				" name='im".($v + 1)."' title='$mess'>$mess</a></tr>";
				}
				
		        }
		}
                
                
		$form .= "</table>";
		$form .= "</form></center>";
		
		return $form ;


	}

        /*
        *  fonction qui retourne un tableau et l'indice de leur table mysql correspondante dans la liste des tables mysql pour rubriques
        */
        function getT(){
                        
		$options = array(); 
		$ob = new Object(); $rubs = $ob -> getRubriques(); $tabs = $ob -> getTabs();
		$titchamp = $rubs[0];
		$options[$titchamp] = 0 ;
		for($i = 1 ; $i < count($rubs) ; $i++){
			$titchamp = $rubs[$i];
			$options[$titchamp] = $i;

		}
                return $options ;
        }

        function objetEnAttente(){//Retourne vrai si un objte est en attente d'enregistrement et faux sinon

                              return ($_SESSION["objEnAttente"] == 1) ;
        }
	
        function getTabNameFromSess(){//Retourne le nom de la table mysql sur laqueele l'objet en attente doit etre enregistrer
                              return  $_SESSION["nomtable"] ;  
         }


        function sigUserPresence(){//Signale a la session que le user essai d'acceder a son menu
                              $_SESSION["menuaccess"] = true ;  
        }
	
        function extensionIsValid($nomfichier){
        $exts = array("gif","png","jpg","jpeg");
        $bool = false ;
        $extfichier = getExtension($nomfichier);//Retourne l'extension du fichier
         foreach($exts as $f){
                if(strcasecmp($f , $extfichier) ){//Si les chaines sont equivalentes dans un contexte minuscule et majuscule : case insensitive
                $bool = true ;
		break ;
		}
         }
        
         return $bool ;

        }


        function isPdfWord($nomfichier){//Verifie si un nom de fichier est un pdf , .doc où un .docx
        $exts = array("doc","pdf","docx");
        $bool = false ;
        $extfichier = getExtension($nomfichier);//Retourne l'extension du fichier
         foreach($exts as $f){
                if(strcasecmp($f , $extfichier) ){//Si les chaines sont equivalentes dans un contexte minuscule et majuscule : case insensitive
                $bool = true ;
		break ;
		}
         }
        
         return $bool ;

        }



        function getExtension($nomfichier){
	 $arr = explode('.',$nomfichier);
                 $extfichier =  strtolower( end($arr));//Retourne l'extension du fichier
                 return  $extfichier ;

        }

        function getPrefixeFichier($nomfichier){//Retourne l'avant extension du nom d'un fichier
	 $arr = explode('.',$nomfichier);
		 $prefixe = "";$tai = count($arr);
		for($k=0 ; $k<($tai - 1);$k++){
			$prefixe .= $arr[$k];
			
		}
             
                 return  $prefixe;

        }


	function showInscripForm(array $_T = array()){//Affiche le formulaire d'inscription en prenant en parmetre soit un array de mysql_fetch_assoc , soit $_GET ,  soit $_POST

		$vil = new Ville() ;
	       echo "<form action='inscription.php' method=post name='inscrip' onSubmit=\" return ck1()\">";
			$obliger = "<font color=red size=5>*</font>"; $petitmessage = "( ".$obliger." ) => champs obligatoires";  
			$nouvligne ="</tr><tr><td>";	
			$nouvColonne =" : </td><td align=left>";	$posi = " align=right " ;
                     echo "<table  class='petit' >";
                        echo "<caption style='font-family:verdana; font-size:8; font-weight:700;'>";
                        echo "Formulaire d'inscription</caption>";
                        echo "<tr><td $posi > Votre Nom $nouvColonne <input type=text name='nom' value='".stripslashes($_T['nom'])."' size=20 onBlur=\"".
			"firstCharUp(this);\"></tr>";    
                        echo "<tr><td $posi >Votre Prenom $nouvColonne <input type=text name='prenom' value='".stripslashes($_T['prenom'])."'  size=20 onBlur=\"".
			"firstCharUp(this);\"></td></tr>";  
                        echo "<tr><td $posi >Votre Mot de passe $nouvColonne <input type=password name='mdp1' value='".stripslashes($_T['mdp1'])."'  size=20 >$obliger</td></tr>";   
                        echo "<tr><td $posi >Confirmation du Mot de passe $nouvColonne <input type=password name='mdp2' value='".stripslashes($_T['mdp2'])."'  size=20 >$obliger</td></tr>";    
                        echo "<tr><td $posi >Votre Pseudonyme $nouvColonne <input type=text name='pseudo' value='".stripslashes($_T['pseudo'])."'  size=20 >".
			     "$obliger</td></tr>";      
                        echo "<tr><td $posi >Votre email $nouvColonne <input type=text name='email' value='".stripslashes($_T['email'])."'  size=20 >$obliger</td></tr>";        
                        echo "<tr><td $posi >Votre ville d'habitat $nouvColonne ". $vil -> getDropDownVilles("villeid") ."</td></tr>";   
                        echo "<tr><td $posi >Votre num&eacute;ro de telephone $nouvColonne <input type=text name='tel' value='".
			     stripslashes($_T['tel'])."'  size=20 > $obliger</td></tr>";     
                        echo "<tr><td $posi colspan=2 >Voulez vous recevoir les annonces dans votre boite email ? $nouvligne Oui je suis d'accord<input type=radio name='nletter' value='1' checked>"; 
			echo "</td><td> Non je ne suis pas interess&eacute;<input type=radio name='nletter' value='0' ></td></tr>";   
			echo "<tr><td align=center colspan=2>" .$petitmessage."</td></tr>" ;
    			echo "<tr><td colspan=2 align=center><input type=submit value='Enregistrer' name='enreg'></td></tr>";
                    echo "</table>";
		echo "</form>";

        }


        function showInsertOptions(){//Affiche le menu gauche , Vendre , Acheter , Louer ,etc
                $menugauche = "";
                $menugauche .=  "<table  width=100% border='0' cellpadding='0' cellspacing='14' summary=''> ";
                $navs = array("Vendre" => "Vente","Acheter" => "Achat","Mettre en location" => "Location",
                                "Louer" => "Recherche de Location") ;
                $tab = array("Vendre" => 00,"Acheter" => 01,"Mettre en location" => 10,"Louer" => 11);
                foreach($navs as $field => $titreaction)
                 $menugauche .=  "<tr class=\"navi\">".
                      "<td align=center><a href=\"action.php?titreaction=".str_replace(" ","+",$titreaction).
                      "&objtyp=".$tab[$field]."&tit=$titreaction\"><font color='blue' size=2>".$field."</font></a></td>".
                      "</tr>";  
                $menugauche .=  "</table>\n";
                $menugauche .=  "</td>\n";
                $menugauche .=  "<!-- Fin barre de navi gauche-->\n";
                $menugauche .=  "<!-- Debut partie centrale-->\n";
                $menugauche .=  "<td  align='left' valign='top' >\n";
                $menugauche .=  "<div align='center'>\n";
                return $menugauche ;
        }

        function contientSousChaine($chaine , $souschaine){

                        $haystack = $chaine ; $needle = $souschaine;
                        $pos = strpos($haystack,$needle);
                        if($pos === false )
                        return false ;
                        else return true ;

        }
        

        /*
	* Fonction qui prends en parametre un tableau d'attributs et le retourne un tableau formatte contenu dans un formulaire pour visualisation
        * $nomtable est le nom de la table sur laquelle la visualisation s'effectu
	* $tabValeurs est le tableau d'attributs a afficher
	* $_T est le tableau ($l=mysql_fetch_assoc(....)) qui contient les attributs a visualiser
	*/

	function getView($nomtable,array $tabValeurs,  array $_T  , $objectid){
		$form = "" ; 
		$form .= "<br><font size=4><b>{$_GET['tit']}</b></font><br>";
		//if(   ! is_array($_T) || ! (count($_T) < 1) ) $_T = $_POST ;//Si le tableau $_T n'est pas placer
                //Dans chaque table , les *_lieu sont devenus des VilleId , ce qui fait qu'il faut remplacer la VilleId par sa ville de nom 
                $villeid = $_T['VilleId'] ;$obj = new Object(); $userid = $obj -> getUserId($nomtable , $objectid); 
		$nomrubrique = $obj -> getNomRubrique($nomtable , $objectid);$rid = $obj -> getNoRubrique($nomtable , $objectid);//Le numero de la rubrique
                $ville = new Ville() ; $ville -> setId($villeid); $ville -> loadData() ;$nomville = $ville -> getNom();
		$longeur = count($tabValeurs);$couleurUser = "black size=1" ;$couleurObjet = "blue" ; $fontTitreDebut ="<H4>" ;
		$fontTitreFin = "</H4>" ; $taiIm = "width=20 height=20";

		$debutColor = "<font color=$couleurObjet>" ; $finColor = "</font>" ;
                $pho = new Photo();
		//On doit afficher a qui appartient l'objet dans la visualisation complete de l'objet
		$u = new User(); 
		$u -> setUserId($userid); $u -> loadFromId();$villeid = $u -> getVilleId() ; $ville -> setId($villeid);
		$ville -> loadData(); $villeUser = $ville -> getNom(); $pseudoUser = $u -> getPseudo();
		$dateins = ($_T['jour'] == date("d-m-Y")) ? "Aujourd'hui" : " le ".$_T['jour'] ;
		$titreDeObjet = "Mise en ligne par <a href='#'><font color=green><u>$pseudoUser</u></font></a>  $dateins &agrave; ".$_T['heure'];
		$userinfo = "";
		$userinfo .= "<br><br><div class=\"infosobjet\">";
		$userinfo .= "<table>";
		$userinfo .= "<tr><td colspan=7><font size=3><b>{$_GET['tit']}</b></font></tr>";
		$userinfo .= "<tr><td colspan=7> $fontTitreDebut Informations sur le propri&eacute;taire de cette insertion $fontTitreFin </tr>";
		$userinfo .= "<tr><td colspan=7>$titreDeObjet</tr>" ;
		$userinfo .= "<tr><td align=left colspan=3><img src='images/tel.png' $taiIm >T&eacute;lephoner &agrave; $pseudoUser :</td>".
		"<td colspan=4><font color=$couleurUser><b>".$u -> getTel()."</b></font> </tr>".
			"<tr><td align=left colspan=3> Son lieu de r&eacute;sidence : </td><td colspan=4><font color=$couleurUser><b>".$villeUser."</b></font> </tr>".
			"<tr><td align=left colspan=3> Son addresse Email : </td><td colspan=4><a href='mailto:".
		$u -> getEmail()."'><font color=$couleurUser><b>".$u -> getEmail()."</b></font></a></td></tr>";
		$userinfo .= "</table>";		
		$userinfo .= "</div>";
		$t = array () ;
		$t = $tabValeurs ; 
		$i=0;
		$M=2; 
		$form .= "<font size=2>$titreDeObjet</font>";
		$form .= "<center>";
		$form .= "<div class=\"infosobjet\">";
		$form .= "<table>";
		$form .= "<caption>$fontTitreDebut Details de cette insertion $fontTitreFin </caption>";
                //On affiche d'abord les images :
                $form .= "<tr><td align=center colspan=2>";
                $imids = array();
	        $imids = $pho -> getAllImages($objectid,$nomtable);//Recuperation des images appartenant a cet objet
	        //Affichage des images
                
                $pasDimage = getNoImage() ;//Image par defaut pour objets n'ayant pas d'images
                $NB = count($imids) ;
			 $fichier = $pho -> getImage($imids[0]) ;
                         $imagefile = getUserfileDir()."/".$fichier;//Peut retourner soit un fichier pdf , word ou image
                                 //on double le nn pour ne pas confondre avec ce que php utilise
	                        if(is_file($imagefile)){//On recuperera l'extension puis on vera si c'est une image uo pas
					$fileExt = getExtension($fichier);
					$ext = strtolower($fileExt);
					if($ext != "png" && $ext != "gif" && $ext != "jpeg" && $ext != "jpg"){//On a a faire a un fichier word ou pdf
						if($_T['RubriqueId'] == 6 && $_T['ObjTyp'] == 1)//Cette insertion est une recherche de travail
					        $form .= "CV : <a href='$imagefile' title=\"Le CV joint &agrave; cette insertion\" >".
						"T&eacute;l&eacute;charger ce CV</a></td>";
						if($_T['RubriqueId'] == 7 && ($_T['ObjTyp'] == 00 || $_T['ObjTyp'] == 10))
						//Cette insertion est une offre en vente des services ou une mise en location des services
					        $form .= " Pi&egrave;ce jointe pour ce service: <a href='$imagefile' title=\"Pi&egrave;ce jointe &agrave; cette offre de service\">T&eacute;l&eacute;charger ce document</a></td>";

					}else{
						$taillePrecise = " width=80 height=40 " ;
					        $form .= "<img src='images/previous.png' $taillePrecise title=\"Image pr&eacute;c&eacute;dente\" onclick=\"previous('this.document.imag')\"> ".
						"</td><td><img class='arrondis' src='".$imagefile.
				                "' width=150 height=250 name='imag' alt=\"Image manquant\" title=\"Cliquez sur cette image pour la visualiser sur grand format\" onclick=\"window.open(ims[ind].src)\"></td><td><img src='images/next.png' $taillePrecise onclick=\"next " .
						"('this.document.imag')\" title=\"prochaine image\">".
						"</td><td>";
					}
				}
				else
				$form .= "$pasDimage";
				//$form .= "$imagefile<br>"; Pour voir le nom des images
                $form .= "</td></tr>";
		$form .= "<tr><td align=right >Ville: </td><td><b> $nomville </b></td></tr>" ;
		foreach($t as $field => $value){
		        	//On ajoutera FCFA au champ prix
				$nomm = str_replace("Tab","",$nomtable);
				if($value == $nomm."_prix")
					$_T[$value] .= " FCFA";
                        
				$sizer = " size=15 onFocus=\"this.disabled=true;\" style=\"color:blue\"";
					$champDesc = $nomm."_desc";
					$pos = ( $champDesc == $value );
                                	if($pos === true ){//Si le champ a afficher est une description et non une proprete de l'objet
					        $form .= "<tr><td align=right></td>" ;
					        $form .= "<td>".stripslashes($_T[$value])."</td></tr>" ;

					}else{
					        $form .= "<tr><td align=right>".ucfirst($field)." : </td>" ;
					        $form .= "<td> <b> ".stripslashes($_T[$value])." </b>  </td></tr>" ;
					}
		                  		
		               
                        
		} 
		$form .= "<tr><td></td></tr><tr><td></td></tr>"; //On affiche les infos du user apres avoir tout afficher sur l'objet a voir
		$form .= "</table>";
		$form .= "</div>";
		$form .= $userinfo  ;
		if(empty($_GET['sendfriend']))//Si on n'est pas entrain deja de remplir le formulaire d'envoi d'annonce a un ami alors on 
		//l'affiche le liens le permettant de le faire
		$form .= "<br><p><img src='images/mail.png' width=25 height=20 ><a href='fullview.php?sendfriend=1&nt=$nomtable&oid=$objectid&nr=$rid'><font size=2>Envoyer cette annonce a un ami</font></a></p><br>";
		$form .= "</center>";
		return $form ;

	}

	function getLink($address , $text){
		return "<a href=".$address.">".$text."</a>";
	}

	function getUserFileDir(){//Retourne le nom du repertoire ou les images des user seront sauvegarder
		return "files";
	}
	
	function getMaxFileSize(){//Retourne la taille maximum des fichiers a uploader vers le serveur
		return 500000000 ;//50MegaOctets au maximum
	}

	function getNbVisualisedLines(){//Retourne le nombre de lignes a voir si on visualise une rubrique ayant trop de lignes
		return 15 ;
	}

	function keepLog(){//Fonction qui garde la trace de toutes les pages au quel on accede
		
		$mat = 0 ;
		if(sessionExists()){
			$u = new User() ;
			$ps = getUserName() ;
			$u -> setPseudo($ps);
			$u -> loadData() ;
			$mat = $u -> getUserId();
		}
		
		$datel = date("Y-m-d H:i:s"); $madr = $_SERVER['REMOTE_ADDR'];
       		$lo = new Log($mat , $madr , $datel); //  new Log($mat , $madr ,$datel )
		$lo -> setUrl($_SERVER["SCRIPT_NAME"]);
        	$lo -> createLog() ; // Stores in $_SESSION the macadrr of the user

	}

	function webtotext($webstring){
		$textstring = "" ;
		$trans_tbl = get_html_translation_table (HTML_ENTITIES);
		$trans_tbl = array_flip ($trans_tbl);
		$textstring = strtr ($webstring, $trans_tbl);
		return $textstring ;
	}
//S'il n'ya pas encore de ligne pour cette internaute alors on l'insere

	function texttoweb($textstring){
		$webstring = htmlentities($textstring) ;
		return $webstring ;
	}

	function createRandomPassword() {//Creation de mot de passe aleatoire
	    $chars = "abcdefghijkmnopqrstuvwxyz023456789";
	    srand((double)microtime()*1000000);
	    $i = 0;
	    $pass = '' ;
	    while ($i <= 7) {
		$num = rand() % 33;
		$tmp = substr($chars, $num, 1);
		$pass = $pass . $tmp;
		$i++;
	    }
	    return $pass;
	}

	function getNoImage(){//Cete fonction retourne une image par defaut por ls objets n'yant pas d'image.
		return "<img src='images/noimage.gif' width=120 height=40 title=\"Pas d'image pour cet objet\">" ;
	}

	function putConnect(){//Fonction qui insere une nouvelle connection en bd au siteweb par un internaute
			//On commencera d'abord par supprimer les connections des anciennes dates 
			$r = execute("delete from connected where date_format(datec, '%Y-%m-%d') !='".date("Y-m-d")."'") ;
			//HOUR('10:05:03')
			//On supprimera aussi les connections de la  date courante mais dont ca fait plus d'une heure que cette internaute ne s'es plus connecter
			$r = execute("delete from connected where  ( hour(curtime() ) - hour(datec)  )  > 1 ") ;
			//Ensuite on inserera cette nouvelle connection si elle n'existe pas déja dans la base de données
			$macaddr = $_SERVER['REMOTE_ADDR'] ;
			$query = "select * from connected where macaddr = '$macaddr' and date_format(datec, '%Y-%m-%d')='".date("Y-m-d")."'" ;
			$resu = execute($query) ;
			if(mysql_num_rows($resu) < 1){//S'il n'ya pas encore de ligne pour cette internaute alors on l'insere
				$q = " insert into connected values(id,'$macaddr' ,'".date("Y-m-d H:i:s")."')" ;
				$res = execute($q) ;
			}

	}

	
	function countConnect(){//Fonction qui retourne le nombre de personnes connecter au siteweb actuellement.

		$nb = 0 ;
		$q = "SELECT distinct macaddr from log where (now() - datel)/(60) < 60" ;//Tous les adresse IP des gars qui se sont connecter il ya moins de 60 minutes
		$r = execute($q);
		$nb = mysql_num_rows($r);
		//$l = mysql_fetch_assoc($r);
		return $nb ;

	}

	function signalConfInscrit($iduser ){
	//Fonction qui signale a la base de donnees qu'un user viens de recevoir un autre mail de confirmation d'inscription
	//Si c'est le premier mail de confirmation alors on insere une nouvelle ligne dans la table noconfinscrit
	//sinon on ajoute le nombre de fois que ce user a recu un mail de confirmation
		if(! empty($iduser) && is_numeric($iduser)){
			$q = "select UserId  from noconfinscrit where UserId=$iduser" ;
			$resu = execute($q);
			if(mysql_num_rows($resu) < 1){//S'il n'ya pas encore de ligne pour cette internaute alors on l'insere
				$q = " insert into noconfinscrit values(id,$iduser ,1)" ;
				$res = execute($q) ;
			}else{//Il y'a déja une ligne , alors on ajoute juste le nombre de fois qu'il est entrain de récevoir un mail de confirmation
				$q = " update noconfinscrit set nofois = nofois + 1 where UserId = $iduser" ;
				$res = execute($q) ;
			}
		}

	}

	function signalConfInsert($iduser,$norubr,$idobjet ){
	//Fonction qui signale a la base de donnees qu'un user viens de recevoir un autre mail de confirmation d'insertion d'une insertion qu'il viens d'effectuer
		if(! empty($iduser) && is_numeric($iduser)){//S'il n'ya pas encore de ligne pour cette internaute alors on l'insere
				$q = " insert into noconfinsert values(id,$iduser ,$norubr ,$idobjet)" ;
				$res = execute($q) ;
			
		}

	}
?>
