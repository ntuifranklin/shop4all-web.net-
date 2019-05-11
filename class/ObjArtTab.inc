<?php
       
        /*
        *@Cette class modelise un objet ObjArt
        *
        *@Tout ses attributs correspondent a ceux de la table-ObjArtTab a la quelle cet objet appartient
        *
        *
        *
        */

        class ObjArtTab{
                private $ObjArtId = 0 ; private $UserId= 0 ; private $ObjArt_nom ;  
                private $ObjArt_desc ; private $ObjArt_dim = "" ;
                private $ObjArt_prix = 0 ;private $Date_ins = "" ;
                private $ObjArt_masse = 0 ; private $ObjTyp = 0 ;
                private $ObjArt_lieu ; private $Date_modif = "" ; private $RubriqueId = 0 ;

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d");
                        $this -> UserId = 0 ;
                        $this -> ObjTyp = 0 ;
                        $this -> ObjArt_prix = 0 ;
                        $this -> ObjArt_masse = 0 ;
                        $this -> RubriqueId = 0 ;  
                        $this -> ObjArtId = 0 ;
		}
                

                //Modificateurs setters
                public function setId($p){
                        $this -> ObjArtId = $p ;
                }

                public function setUserId($p){
                        $this -> UserId = $p ;
                }

                public function setNom($p){
                        $this -> ObjArt_nom = $p ;
                }

                public function setDesc($p){
                        $this -> ObjArt_desc = $p ;
                }

                public function setDim($p){
                        $this -> ObjArt_dim = $p ;
                }

                public function setPrix($p){
                        $this -> ObjArt_prix = $p ;
                }

                public function setDateIns($p){
                        $this -> Date_ins = $p ;
                }

                public function setMasse($p){
                        $this -> ObjArt_masse = $p ;
                }

                public function setObjTyp($p){
                        $this -> ObjTyp = $p ;
                }
	
                public function setLieu($p){
                        $this -> ObjArt_lieu = $p ;
                }

                public function setDateModif($p){
                        $this -> Date_modif = $p ;
                }


                public function setRubriqueId($p){
                        $this -> RubriqueId = $p ;
                }

               
                //Accesseurs getters
                public function getId(){
                        return $this -> ObjArtId   ;
                }

                public function getUserId(){
                        return $this -> UserId   ;
                }

                public function getNom(){
                        return $this -> ObjArt_nom   ;
                }

                public function getDesc(){
                        return $this -> ObjArt_desc   ;
                }

                public function getDim(){
                        return $this -> ObjArt_dim   ;
                }

                public function getPrix(){
                        return $this -> ObjArt_prix   ;
                }

                public function getDateIns(){
                        return $this -> Date_ins   ;
                }

                public function getMasse(){
                        return $this -> ObjArt_masse   ;
                }

                public function getObjTyp(){
                        return $this -> ObjTyp   ;
                }
	
                public function getLieu(){
                        return $this -> ObjArt_lieu   ;
                }

                public function getDateModif(){
                        return $this -> Date_modif   ;
                }

                public function getRubriqueId(){
                        return $this -> RubriqueId  ;
                }
	
                public function getAttribAsArray(){
                        $t = array(
		                "Titre" => "ObjArt_nom",
		               // "Ville" => "ObjArt_lieu",
		                "Detail" => "ObjArt_desc",
		                "Prix" => "ObjArt_prix",
		                "Dimension" => "ObjArt_dim" ,
		                "Masse" => "ObjArt_masse"
	                );
                        return $t ;
                }
 
                     

                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(1,1,0,1,1);
                        return $t ;
                }


                public function getTableTailles(){
                //Cette fonction retourne un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribAsArray();
                        $t = array(100,500,11,30,11);
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(0,1,0,1,1);
                        return $t ;
                }

                public function treatForm(){
                        $errmess = "";
                        $attribs = $this -> getAttribAsArray() ;
                        $class = getRubriqueTableAsArray() ;
                        $taille = $this -> getTableTailles();
                        $nulls = $this -> getTableNulls(); //Indices des attributs qui peuvent etre nulle
                        $types = $this -> getTableTypes(); //Tableau des types attendus. 1 ==> String , 0 ==> numeric
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

                        if($errmess != "" ){ //S'il ya des erreurs alors on reaffiche le formulaire et on libere le plancher
                             echo errmess($errmess)  ; 
                             $titre = $_POST['titreRub']; $actionFile = "treatinsertion.php"; $nom = $class[$_POST['typetab']] ;
                             echo getForm($titre , $actionFile , $nom , $this -> getAttribAsArray(), $_POST['typetab']) ; //Reaffichage du formulaire 
                             return false ;
                        }else
                             return true ;   
                }

                public function placerChamps(){
                        $this -> placerChampsTab($_POST);
                }

                public function creer($nomtable="ObjArtTab"){
                        //Enregistrement d'un objet
                        $u = new User();
			if(sessionExists()){//On est viens de se connecter ou alors on etait déja conneceter depuis
				$u -> setPseudo(getUserName()); 
				$u -> loadData();
			}else{//On  n'est pas connecter , donc on viens tout droit du mail de confirmation d'insertion
				$u -> setUserId($_GET['actionnumber']); 
				$u -> loadFromId();
			}
                        $userid = $u -> getUserId(); // User :: getUserId(); 
                        $nom = addslashes($this -> getNom());
                        $desc = addslashes($this -> getDesc());
                        $dim = addslashes($this -> getDim());
                        $prix = $this -> getPrix();
                        $date_ins = date("Y-m-d H:i:s");
                        $masse = $this -> getMasse();
                        $objtyp = $this -> getObjTyp();
                        $lieu = $this -> getLieu();//Le lieu ici est l'id de la ville et non le nom du lieu
			$ville = new Ville(); $villeid = 0 ;
			$villeid = ( filter_var($lieu , FILTER_VALIDATE_INT)) ? $lieu : 0  ;//On recupere la villeid de ce lieu appartenant a cet objet 
                        $date_modif = $this -> getDateModif();
                        $RubriqueId = $this -> getRubriqueId();
                        $query = "insert into $nomtable values(".
                                 "ObjArtId,".
                                 $userid.",".
                                 "\"".$nom."\",".
                                 "\"".$desc."\",".
                                 "\"".$dim."\",".
                                     $prix.",".
                                 "\"".$date_ins."\",".
                                     $masse.",".
                                     $objtyp.",".
                                     $villeid.",".
                                 "\"".$date_modif."\",".
                                     $RubriqueId.
                                 ")";

                         $res = execute($query); 
                         $ObjArtId = getAutoIncrementValue("$nomtable") ; //Je recupere L'id de cet objet 
                         $this -> setId($ObjArtId);
                        //}
                }


                public function placerChampsTab(array $_T){
                        $this -> setNom(webtotext($_T['ObjArt_nom']));
                        $this -> setDesc(webtotext($_T['ObjArt_desc']));
                        $this -> setDim(webtotext($_T['ObjArt_dim']));
                        $this -> setPrix($_T['ObjArt_prix']);
                        $this -> setMasse($_T['ObjArt_masse']);
                        $this -> setObjTyp($_T['objtyp']);
                        $this -> setLieu($_T['villeid']);
                        $this -> setRubriqueId($_T['norubr']);
                }

                public function createFromSession(){//Permet de sauvegarder les attributs d'un objet en session en attendant la connexion du User
                       
                                $this -> placerChampsTab($_SESSION);
                                $this -> creer();
                                return true ;
                                
                }


		public function getArrayTitreTable(){
			//Permet de retourner les nom des champs de la table correspondante a cette classe pwermetant de former le titre d'une insertion
			//Ceci permet de titrer une insertion afficher
			$t = array();
			$t[0] = "nom";
			return $t ;
		}
        }//Fin classe ObjArtTab

?>
