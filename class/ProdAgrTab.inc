<?php
       
        /*
        *@Cette class modelise un objet ProdAgr
        *
        *@Tout ses attributs correspondent a ceux de la table-ProdAgrTab a la quelle cet objet appartient
        *
        *
        *
        */

        class ProdAgrTab{
                private $ProdAgrId = 0 ; private $UserId= 0 ; private $ProdAgr_nom ;  
                private $ProdAgr_desc ; private $ProdAgr_dim = "" ;
                private $ProdAgr_prix = 0 ;private $Date_ins = "" ;
                private $ProdAgr_masse = 0 ; private $ObjTyp = 0 ;
                private $ProdAgr_lieu ; private $Date_modif = "" ; private $RubriqueId = 0 ;

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d");
                        $this -> RubriqueId = 0 ;
                        $this -> UserId = 0 ;
                        $this -> ProdAgrId = 0 ;
                        $this -> ProdAgr_masse = 0 ;
                        $this -> ProdAgr_prix = 0 ;
                        $this -> ObjTyp = 0 ;
		}
                

                //Modificateurs setters
                public function setId($p){
                        $this -> ProdAgrId = $p ;
                }

                public function setUserId($p){
                        $this -> UserId = $p ;
                }

                public function setNom($p){
                        $this -> ProdAgr_nom = $p ;
                }

                public function setDesc($p){
                        $this -> ProdAgr_desc = $p ;
                }

                public function setDim($p){
                        $this -> ProdAgr_dim = $p ;
                }

                public function setPrix($p){
                        $this -> ProdAgr_prix = $p ;
                }

                public function setDateIns($p){
                        $this -> Date_ins = $p ;
                }

                public function setMasse($p){
                        $this -> ProdAgr_masse = $p ;
                }

                public function setObjTyp($p){
                        $this -> ObjTyp = $p ;
                }
	
                public function setLieu($p){
                        $this -> ProdAgr_lieu = $p ;
                }

                public function setDateModif($p){
                        $this -> Date_modif = $p ;
                }

                public function setRubriqueId($p){
                        $this -> RubriqueId = $p ;
                }
               
                //Accesseurs getters
                public function getId(){
                        return $this -> ProdAgrId   ;
                }

                public function getUserId(){
                        return $this -> UserId   ;
                }

                public function getNom(){
                        return $this -> ProdAgr_nom   ;
                }

                public function getDesc(){
                        return $this -> ProdAgr_desc   ;
                }

                public function getDim(){
                        return $this -> ProdAgr_dim   ;
                }

                public function getPrix(){
                        return $this -> ProdAgr_prix   ;
                }

                public function getDateIns(){
                        return $this -> Date_ins   ;
                }

                public function getMasse(){
                        return $this -> ProdAgr_masse   ;
                }

                public function getObjTyp(){
                        return $this -> ObjTyp   ;
                }
	
                public function getLieu(){
                        return $this -> ProdAgr_lieu   ;
                }

                public function getDateModif(){
                        return $this -> Date_modif   ;
                }

                public function getRubriqueId(){
                        return $this -> RubriqueId  ;
                }
	
                public function getAttribAsArray(){
                        $t = array(
		                "Titre" => "ProdAgr_nom",
		                //"Ville" => "ProdAgr_lieu",
		                "Detail" => "ProdAgr_desc",
		                "Prix" => "ProdAgr_prix",
		                "Masse" => "ProdAgr_masse"
	                );
                        return $t ;
                }


                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(1,1,0,0);
                        return $t ;
                }


                public function getTableTailles(){
                //Cette fonction retoure un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(100,100,11,11);
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(0,1,0,1);
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

                public function creer($nomtable="ProdAgrTab"){
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
                        $lieu = $this -> getLieu();//Le lieu ici est l'id de la ville et non le nom du lieu
			$ville = new Ville(); $villeid = 0 ;
			$villeid = ( filter_var($lieu , FILTER_VALIDATE_INT)) ? $lieu : 0  ;//On recupere la villeid de ce lieu appartenant a cet objet 
                        $date_ins = date("Y-m-d H:i:s");
                        $date_modif = $this -> getDateModif();
                        $prix = $this -> getPrix();
                        $masse = $this -> getMasse();
                        $objtyp = $this -> getObjTyp();
                        $RubriqueId = $this -> getRubriqueId();
                        $query = "insert into $nomtable values(".
                                 "ProdAgrId,".
                                 $userid.",".
                                 "\"".$nom."\",".
                                 "\"".$desc."\",".
                                     $villeid.",".
                                 "\"".$date_ins."\",".
                                 "\"".$date_modif."\",".
                                     $prix.",".
                                     $masse.",".
                                     $objtyp.",".
                                     $RubriqueId.
                                 ")";

                         $res = execute($query); 
                         $ProdAgrId = getAutoIncrementValue("$nomtable") ; //Je recupere L'id de cet objet 
                         $this -> setId($ProdAgrId);
                        //}
                }

                public function placerChampsTab($_T){
                        $this -> setNom(webtotext($_T['ProdAgr_nom']));
                        $this -> setDesc(webtotext($_T['ProdAgr_desc']));
                        $this -> setLieu($_T['villeid']);
                        $this -> setPrix($_T['ProdAgr_prix']);
                        $this -> setMasse($_T['ProdAgr_masse']);
                        $this -> setObjTyp($_T['objtyp']);
                        $this -> setRubriqueId($_T['norubr']);
                }


                public function createFromSession(){//Permet de sauvegarder les attributs d'un objet en session en attendant la connexion du User
                       
                                $this -> placerChampsTab($_SESSION);
                                $this -> creer();
                                return true ;
                                
                }


                        public function getArrayTitreTable(){
	                        //Permet de retourner les nom des champs de la table correspondante a cette classe permetant de former le titre d'une insertion
	                        //Ceci permet de titrer une insertion afficher
	                        $t = array();
	                        $t[0] = "nom";
	                        return $t ;
                        }
        }//Fin classe ProdAgrTab

?>
