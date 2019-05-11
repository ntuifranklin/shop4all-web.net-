<?php
       
        /*
        *@ Cette classe modelise un utilisateur
        *
        *@ Tout ses attributs correspondent a ceux de la table UserTab sur bd
        *
        *
        *
        */

        class User{
            private $UserId = 0 ;private $VilleId = 0 ;private $User_pseudo = ""; private $User_nom = ""; 
	    private $User_prenom = ""; private $Date_ins = ""; private $Date_modif = ""; private $User_User_email = ""; 
	    private $User_tel = ""; private $User_pw = ""; private $User_etat = 0 ; private $User_inscrit = 0 ;
            private $User_nletter = 0; 

            function  __construct(){
		$this -> Date_ins = date("Y-m-d");
		$this -> Date_modif = date("Y-m-d");
                $this -> UserId = 0 ;
                $this -> User_etat = 0 ;
                $this -> User_inscrit = 0 ;
                $this -> VilleId = 0;
                $this -> User_nletter = 0; 
            }  

            /*** Modificateurs ***/
            public function setUserId($i){
                $this -> UserId = $i ;
            }

            public function setVilleId($v){
                $this -> VilleId = $v ;
            }


            public function setPseudo($p){
                $this -> User_pseudo = $p ;
            }

            public function setNom($n){
                $this -> User_nom = $n ;
            }

            public function setPrenom($n){
                $this -> User_prenom = $n ;
            }

            public function setDateIns($n){
                $this -> Date_ins = $n ;
            }

            public function setDateModif($n){
                $this -> Date_modif = $n ;
            }

            public function setEmail($e){
                $this -> User_User_email = $e ;
            }

            public function setTel($t){
                $this -> User_tel = $t ;
            }

            public function setPw($p){
                $this -> User_pw = $p ;
            }

            public function setNLetter($e){
                $this -> User_nletter = $e ;
            }

            public function setEtat($etat){
                 $this -> User_etat = $etat  ;
            }


            public function setInscrit($i){
                $this -> User_inscrit = $i ;
            }

            /*** Accesseurs ***/
            public function getUserId(){
                return $this -> UserId  ;
            }

            public function getVilleId(){
                return $this -> VilleId  ;
            }


            public function getPseudo(){
                return $this -> User_pseudo  ;
            }

            public function getNom(){
                return $this -> User_nom  ;
            }

            public function getPrenom(){
                return $this -> User_prenom  ;
            }

            public function getDateIns(){
                return $this -> Date_ins  ;
            }

            public function getDateModif(){
                return $this -> Date_modif  ;
            }

            public function getEmail(){
                return $this -> User_User_email  ;
            }

            public function getTel(){
                return $this -> User_tel ;
            }

            public function getPw(){
                return $this -> User_pw ;
            }

            public function getNLetter(){
                return $this -> User_nletter  ;
            }


            public function getEtat(){
                return $this -> User_etat  ;
            }

            public function getInscrit(){
                return $this -> User_inscrit  ;
            }


	 /**
	 * En dessous les fonctions de responsabilites :
	 */


            public function creer(){ /*** Cree un utilisateur par insertion d'un tuple dans la table UserTab ***/
                     
                       
                    // $this -> setInscrit(1);
                     $this -> insertDb();//Insertion en Bd d'un tuple user
			
           } //Fin create



	    public function disconnect(){/*** Deconnectes un utilisateur ***/
			$UserId = $this -> getUserId();

		if(is_numeric($UserId) && !empty($UserId)){
                        $this -> setEtat(0);
                        $this -> update("User_etat" , 0);
			unset($_SESSION);
		}

	    }


	    public function connect(){/*** Connectes un utilisateur ***/
                $pseudo = $this -> getPseudo();
                if(! empty($pseudo)){
                        $this -> loadData();
                        createSession($pseudo);
                        $this -> setEtat(1);
                        $this -> update("User_etat" , 1);
                }

	    }

	    public function userExists(){/*** Verifie si cet utilisateur de ce pseudonymee n'existe pas deja en base de donnees ***/
		$bool = false ;
		$pseudo = addslashes($this -> getPseudo()) ;
		$r = execute("select count(User_pseudo) as nb from UserTab where User_pseudo='".$pseudo."'");	
		while($l = mysql_fetch_assoc($r)){
			if($l['nb'] > 0)
				$bool = true ;
		}		
	
		return $bool ;
	    }//Fin userExists
	      
	    public function update($User_nomchamp , $valeur){/*** Met a jour la colonne $User_nomchamp avec $valeur pour cet utilisateur ***/
		$pseudo = addslashes($this -> getPseudo());
		if(!empty($pseudo)){//Si le pseudonyme est nonvide
		        if( ! $this -> estNumerique($User_nomchamp)){//si la colonne a modifier n'est pas de type numerique
			        $valeur = "'".addslashes($valeur)."'" ;
		        }

                        
		        if($this -> champValide($User_nomchamp)){
			        $r = execute("update UserTab set $User_nomchamp = ".$valeur." where User_pseudo = '".$pseudo."'");	
			
		        }
                }

	    }//Fin update


            public function estNumerique($User_nomchamp){
                        $retour = false ;
                if($User_nomchamp == 'UserId' || $User_nomchamp == 'VilleId' || $User_nomchamp == 'User_etat' || $User_nomchamp == "User_inscrit"){
                        //si la colonne a modifier n'est pas de type numerique
			$retour =  true ;
		}
                        return  $retour ;
            }


            public function champValide($User_nomchamp){
                        $retour = false ;
                if($User_nomchamp == "User_nom" || $User_nomchamp == "User_prenom" || $User_nomchamp == "User_pseudo" || $User_nomchamp == "User_pw"
                        || $User_nomchamp == "User_email" || $User_nomchamp == "User_tel" || $User_nomchamp == "User_etat" || 
                        $User_nomchamp == "User_inscrit" || $User_nomchamp == "VilleId"){
			$retour =  true ;
		}
                        return  $retour ;
            }

	    public function fieldExists($User_nomchamp , $valeur){
		// Verifie s'il existe un utilisateur de meme valeur que $valeur sur la colonne $User_nomchamp dans la table UserTab et retourne un booleen
		$bool = false ;
                $va = "$valeur";
                $query = "";
		if(  $this -> estNumerique($User_nomchamp)){//si la colonne a modifier n'est pas de type numerique
			  
                        $query = "select count(User_pseudo) as nb from UserTab where $User_nomchamp=".$valeur;
		}else{

                
                        $query = "select count(User_pseudo) as nb from UserTab where $User_nomchamp='".addslashes($valeur)."'";
                }

		//On verifie que $User_nomchamp se trouve dans la liste des champs contenu dans la table UserTab

		if( $this -> champValide($User_nomchamp)  && !empty($query)){
			$r = execute($query);	
			while($l = mysql_fetch_assoc($r)){
				if($l['nb'] > 0)
					$bool = true ;
			}		

		}
			return $bool ;
	    }//Fin fieldExists
      


	    public function emailExists(){/*** Verifie si cet utilisateur de meme User_email n'existe pas deja en base de donnees ***/
		$bool = false ;
		$User_email = addslashes($this -> getEmail()) ;
		$r = execute("select count(User_email) as nb from UserTab where User_email='".$User_email."'");	
		while($l = mysql_fetch_assoc($r)){
			if($l['nb'] > 0)
				$bool = true ;
		}		
	
		return $bool ;
	    }//Fin emailExists

	   public function setFields(array $l){/*** Recupere une ligne resultante d'une requete et l'affecte au cet objet de classe ***/
		$this -> setUserId($l['UserId']);
		$this -> setVilleId($l['VilleId']);
		$this -> setNom(stripslashes($l['User_nom']));
		$this -> setPrenom(stripslashes($l['User_prenom']));
		$this -> setDateIns($l['Date_ins']);
		$this -> setDateModif($l['Date_modif']);
		$this -> setEmail(stripslashes($l['User_email']));
		$this -> setTel(stripslashes($l['User_tel']));
		$this -> setPw($l['User_pw']);
		$this -> setNLetter($l['User_nletter']);
		$this -> setEtat($l['User_etat']);
		$this -> setInscrit($l['User_inscrit']);
		$this -> setPseudo($l['User_pseudo']);

	   }//Fin setFields

	   public function loadFromQuery($query){/*** Prends une requete en parametre , l'execute et charge le resultat dans cet objet User ***/
			$r = execute($query);
			while( $l = mysql_fetch_assoc($r) ){
				$this -> setFields($l);//Affectation aux champs de l'objet UserTab 
			}
	   }

	   public function loadFromId(){/*** Prends une requete en parametre , l'execute et charge le resultat dans cet objet User ***/
		$id = $this -> getUserId();
		if(is_numeric($id))
			$this -> loadFromQuery("select * from UserTab where UserId=".$id);
	   }

	   public function loadFromEmail(){/*** Prends une requete en parametre , l'execute et charge le resultat dans cet objet User ***/
		$em = $this -> getEmail();
		if(!empty($em))
		 $this -> loadFromQuery("select * from UserTab where User_email='".$em."'");
	   }



	   public function loadDataFromId(){/*** Prends une requete en parametre , l'execute et charge le resultat dans cet objet User ***/
			$this -> loadFromId();
	   }

	   public function loadData(){
               /*** Charge dans cet objet de classe une ligne de la table UserTab correspondant a celui de l'User_email de cet objet ***/
			 $pseudo = addslashes($this -> getPseudo()) ;

		 if(! empty($pseudo)){
			$q = "select * from UserTab where User_pseudo='".$pseudo."'";
			$r = execute($q);
			while( $l = mysql_fetch_assoc($r) ){
				$this -> setFields($l);//Affectation aux champs de l'objet UserTab 
			}
		 }

	   }//Fin loadData

	   public function passwordIsCorrect(){//Verifie si le mot de passe de cet utilisateur est correcte
			$booleen = false ;
			$pseudo = addslashes($this -> getPseudo()) ; $pass = $this -> getPw();
			$q = "select count(User_pseudo) as nb from UserTab where User_pseudo='".$pseudo."' and User_pw=password('".$pass."')";
			$r = execute($q);
			while( $l = mysql_fetch_assoc($r) ){
				if($l['nb'] > 0)
					$booleen = true ;
			}

			return $booleen ;

	   }//Fin passwordIsCorrect

	 public function updatePassword($pass){//Recupere une chaine et met a jour le mot de passe de ce UserTab avec cette chaine
			$pseudo = addslashes($this -> getPseudo()) ; 
			if(!empty($pass)){//Si le mot de passe est non vide
				$res = execute("update UserTab set User_pw=password(\"".$pass."\") where User_pseudo='".$pseudo."'");
			}
	 }//Fin updatePassword

	 
	   public function visualiseData($valeurBouton="Modifier"){//Affiche les Infos personnelles de cet utilisateur pour permettre une modification
		
               
                $vi = new Ville(); $vid = $this -> getVilleId(); $ville = "";
                if(filter_var($vid , FILTER_VALIDATE_INT) ){//Si la ville du user est renseigner on affiche cette ville la
                        $vi -> setId($vid);
                        $vi -> loadDataFromId();
                        $ville = $vi -> getNom();
                }
	       	$data   .= "<form action='modifier.php' method=post name=\"modi\" onSubmit=\"return ck6();\">";
			$nouvColonne="  </td><td> ";		$taille = "size=30";
                     $data .= "<table><caption>Mes informations </cation>";   
                    // $data   .= "<fieldset  class='petit' >";
                        //$data   .= "<legend style='font-family:verdana; font-size:8; font-weight:700;'>";
                      //  $data   .= "Vos informations personnelles</legend>";
                        $data   .= "<tr><td align=center>Votre Nom $nouvColonne <input type=text name='User_nom' value='".stripslashes($this -> getNom()).
				 "' $taille onBlur=\"firstCharUp(this);\" onLoad=\"firstCharUp(this);\"></td></tr>";    
                        $data   .= "<tr><td align=center>Votre Prenom $nouvColonne <input type=text name='User_prenom' value='".
				   stripslashes($this -> getPrenom())."' $taille onBlur=\"firstCharUp(this);\" onLoad=\"firstCharUp(this);\" ></td></tr>";  
                        $data   .= "<tr><td align=center>Votre Ancien Mot de passe $nouvColonne <input type=password name='User_pw' value='' $taille></td></tr>";   
                        $data   .= "<tr><td align=center>Votre Nouveau Mot de passe $nouvColonne <input type=password name='User_pw1' value='' $taille ></td></tr>";   
                        $data   .= "<tr><td align=center>Confirmation du Nouveau Mot de passe $nouvColonne <input type=password name='User_pw2' value='' $taille></td></tr>";    
                        $data   .= "<tr><td align=center>Votre Pseudonyme  $nouvColonne <input type=text name='User_pseudo' value='".stripslashes($this -> getPseudo())."' $taille>".
			     "</td></tr>";      
                        $data   .= "<tr><td align=center>Votre Email  $nouvColonne <input type=text name='User_email' value='".stripslashes($this -> getEmail())."' $taille></td></tr>";        
                        $data   .= "<tr><td align=center>Votre Ville d'habitat  $nouvColonne ". 
				   $vi -> getDropDownVilles("villeid" , $vid) .
			     "</td></tr>";   
                        $data   .= "<tr><td align=center>Votre num&eacute;ro de telephone  $nouvColonne <input type=text name='User_tel' value='".stripslashes($this -> getTel())."' $taille>" ;   
			
    			$data   .= "<tr><td align=center colspan=2><input type=submit value='$valeurBouton' name='modif'></td></tr>";
                     $data .= "</table>"; 
		$data   .= "</form>";
			return $data ;

	   }//Fin visualiseData

           public function sendConfMail(){
	$retour = false ;
                        $email = $this -> getEmail(); $this -> loadFromQuery("select * from UserTab where User_email='".addslashes($email)."'");
                        $id = $this -> getUserId();
                        $to = $email;
                        $subject = "Confirmation d'inscription chez ".$_SERVER['SERVER_NAME']." !\n\n";
			if(empty($corps))
                        $body = "Bonjour,\n\n Si vous recevez ce mail alors vous vous ".utf8_decode("êtes")." inscrit chez nous et vous devez confirmer".
                        " votre inscription \n en cliquant sur ce liens ou en copiant le lien ci dessus dans la barre d'adresse : \n".
                        "<a href=\"http://".$_SERVER['SERVER_NAME']."/confirm.php?actionnumber=".$id."&tr=".crypt($email).
			"&tit=Confirmation d'inscription\">liens de confirmation</a>";
			else
			$body = $corps ; //sendmeil($email , $body , $nomperson , $title = "")
                         if (sendmeil($to,  $body , $nomperson , $title)) {
                           echo confmess("<p>Message de confirmation envoy&eacute; avec success &agrave;  $email !</p>");
			   confMailSess() ; //Tell session that confirmation mail was sent
			$retour = true ;
                          } else {
                           echo  errmess("<p>Message de confirmation non envoy&eacute; &agrave;  $email !<br> Verifiez votre configuration mail sur ".
                        $_SERVER['SERVER_NAME']." </p>");
                          }

	return $retour ;

           }

           public function getUserMenu(){
                $menu = "";
                $menu .= "<table>";
                $menu .= "<caption><h3>Mon menu</h3><caption>";
                $menu .= "<tr><td><a href='me.php'>Mes informations personnels</a></td><td><a href='myinsertions.php'>Mes insertions</a></td></tr>";
                $menu .= "</table>";
                
                return $menu ;
           }
        
           public function insertDb(){
   
                /*** Preparation de la requete pour soumission en bd ***/
			$User_nom = addslashes($this -> getNom()) ;
			$User_prenom = addslashes($this -> getPrenom()) ;
			$User_pseudo = addslashes($this -> getPseudo());
			$User_pw = $this -> getPw();
			$User_email = addslashes($this -> getEmail());
			$VilleId = addslashes($this -> getVilleId()) ;
			$User_tel = addslashes($this -> getTel()) ;
			$Date_ins =  $this -> getDateIns();
			$Date_modif =  $this -> getDateModif();
			$VilleId = $this -> getVilleId();
                        $User_nletter = $this -> getNLetter() ;
                        $User_etat = $this -> getEtat();
                        $nb = $this -> getNbNegativeUsers();
                        $User_inscrit = $this -> getInscrit();//Ce user refuse de s'inscrire
			if(!empty($User_pseudo) && !empty($User_email) && !empty($User_tel)){//Si les champs obligatoires sont renseignes
				$query = "insert into UserTab values(".
				         "UserId,".
				         "$VilleId,".
					 "'".$User_pseudo."',".
				         "'".$User_nom."',".  
				         "'".$User_prenom."',". 
				         "'".$Date_ins."',".		 
				         "'".$Date_modif."',".	
				         "'".$User_email."',". 
				         "'".$User_tel."',".
					 "password(\"".$User_pw."\"),". //fonction password de MySQL crypte une chaine de caractere.
								  // J'utilise \" pour tenir compte des caracteres speciaux de MySQL tel que "'" , "*" , etc  
				            $User_nletter .",".
                                            $User_etat.",".
                                            $User_inscrit.
				         ")";

				/*** Execution de la requete preparer ***/
		                $r = execute($query);
                                if($User_nletter == 1 ){//On insere son mail dans NewsLetterTab si ce user a accepter de recevoir les anonces
                                        $res = execute("insert into NewsLetterTab values(NewsLetterId , '$User_email')");
                                }


				/*** Recupere l'autoincrement pour l'UserId de cet UserTab ***/
				$User_nomtable = 'UserTab';
		                $id = getAutoIncrementValue($User_nomtable);
		                $this -> setUserId($id);
			}


           }

            public function createNoUser(){ /*** Cree un utilisateur non inscrit par insertion d'un tuple dans la table UserTab ***/
             $this -> setInscrit(0);
             $this -> insertDb();//Insertion en Bd d'un tuple user
            
           } //Fin createNoUser


            public function getNbNegativeUsers(){//Retourne le nombre de user enregistrer et non inscrit ==> de UserId negatif
                        $nb = 0 ;
                        $q = "select count(*) as nb from UserTab where UserId < 0 ";
                        $res = execute($q) ;
                        $l = mysql_fetch_assoc($res);
                        $nb = $l['nb'];
                        
                        return $nb ;

            }


            public function getNbUsers(){//Retourne le nombre de user enregistrer et/ou non inscrit 
                        $nb = 0 ;
                        $q = "select count(*) as nb from UserTab  ";
                        $res = execute($q) ;
                        $l = mysql_fetch_assoc($res);
                        $nb = $l['nb'];
                        
                        return $nb ;

            }


            public function inscrire(){//Modifie le champ User_inscrit et le place de 0 a 1
                        $nb = 0 ;
                        $pseudo = $this -> getPseudo();
                        $q = "update UserTab set User_inscrit = 1 where User_pseudo = '".$pseudo."'";
                        $nb = execute($q) ;
                        
                        return $nb ;

            }

            public function isInscrit(){//Verifie si le champ User_inscrit est 1 ou 0 
                        $retour = false ;
                        $pseudo = $this -> getPseudo();
	if(!empty($pseudo)){
	$q = "select User_inscrit  as i from UserTab where User_pseudo = '".$pseudo."'";
	$res = execute($q) ;
		while($l = mysql_fetch_assoc($res)){
		 if($l['i'] == 1) $retour = true ;
		}
	}
                        
                        return $retour ;

            }

        }//Fin classe User

?>
