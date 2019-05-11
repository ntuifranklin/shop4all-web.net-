<?php
       
        /*
        *@Cette class lieuise un objet Electromobile
        *
        *@Tout ses attributs correspondent a ceux de la table-ElectroTab a la quelle cet objet appartient
        *
        *
        *
        */

        class ElectroTab{
                private $ElectroId = 0 ; private $UserId = 0 ; private $Electro_nom = "" ; 
		//private $VilleId = 0;
		private $Electro_lieu = ""; 
                private $Electro_desc = "" ; private $Date_ins = "" ;
                private $Electro_prix = 0 ;  private $Electro_dim = "" ;
                private $Electro_masse = 0 ; 
                private $ObjTyp = 0 ; private $Date_modif = "" ; private $RubriqueId = 0 ;

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d");
			$this -> Electro_nom = "" ;
			$this -> Electro_desc = 0 ;
			$this -> Electro_dim = 0 ;
			$this -> Electro_prix = 0 ;
			$this -> Electro_masse = 0 ;
			$this -> ObjTyp = 0 ;
			$this -> UserId = 0 ;
                        $this -> ElectroId = 0 ;
			$this -> RubriqueId = 0 ;
		}
                

                //Modificateurs setters
                public function setId($id){
                        $this -> ElectroId = $id ;
                }

                public function setUserId($id){
                        $this -> UserId = $id ;
                }

                public function setNom($m){
                        $this -> Electro_nom = $m ;
                }

                public function setLieu($l){
                        $this -> Electro_lieu = $l ;
                }
                public function setDesc($p){
                        $this -> Electro_desc = $p ;
                }

                public function setPrix($p){
                        $this -> Electro_prix = $p ;
                }


                public function setDim($p){
                        $this -> Electro_dim = $p ;
                }

                public function setDateIns($di){
                        $this -> Date_ins = $di ;
                }

                public function setDateModif($p){
                        $this -> Date_modif = $p ;
                }

                public function setMasse($p){
                        $this -> Electro_masse = $p ;
                }

                public function setObjTyp($p){
                        $this -> ObjTyp = $p ;
                }
	
                public function setRubriqueId($p){
                        $this -> RubriqueId = $p ;
                }

               
                //Accesseurs getters
                public function getId(){
                        return $this -> ElectroId  ;
                }

                public function getUserId(){
                        return $this-> UserId  ;
                }

                public function getNom(){
                        return $this-> Electro_nom  ;
                }

                public function getLieu(){
                        return $this-> Electro_lieu  ;
                }
                public function getDesc(){
                        return $this-> Electro_desc  ;
                }

                public function getPrix(){
                        return $this-> Electro_prix  ;
                }

                public function getDim(){
                        return $this-> Electro_dim  ;
                }

                public function getDateIns(){
                        return $this-> Date_ins  ;
                }

                public function getDateModif(){
                        return $this-> Date_modif  ;
                }

                public function getMasse(){
                        return $this-> Electro_masse  ;
                }

                public function getObjTyp(){
                        return $this-> ObjTyp  ;
                }
	
               
                public function getRubriqueId(){
                        return $this -> RubriqueId ;
                }

                public function getAttribAsArray(){
                        $t = array(
		                "Titre" => "Electro_nom",
		                //"Ville" => "Electro_lieu",
		                "Detail" => "Electro_desc",
		                "Prix" => "Electro_prix",
		                "Dimension" => "Electro_dim",
		                "Masse" => "Electro_masse"
	                );
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(0,1,0,1,1);;
                        return $t ;
                }

                public function placerChamps(){
			$this -> placerChampsTab($_POST);
                }

                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(1,1,0,1,0); ;
                        return $t ;
                }


                public function getTableTailles(){
                //Cette fonction retoure un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(100,100,11,30,11); ;
                        return $t ;
                }


                public function creer($nomtable="ElectroTab"){
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
                        $lieu = addslashes($this -> getLieu());
                        $lieu = $this -> getLieu();//Le lieu ici est l'id de la ville et non le nom du lieu
			$ville = new Ville(); $villeid = 0 ;
			$villeid = ( filter_var($lieu , FILTER_VALIDATE_INT)) ? $lieu : 0  ;//On recupere la villeid de ce lieu appartenant a cet objet                      
                        $desc = addslashes($this -> getDesc());
                        $prix = $this -> getPrix();
                        $dim = addslashes($this -> getDim());
                        $date_ins = date("Y-m-d H:i:s");
                        $date_modif = $this -> getDateModif();
                        $masse = $this -> getMasse();
                        $objtyp = $this -> getObjTyp();
			$RubriqueId = $this -> getRubriqueId();
                        $query = "insert into $nomtable values(".
                                 "ElectroId,".
                                 $userid.",".
                                 "\"".$nom."\",".
                                     $villeid.",".
                                 "\"".$desc."\",".
                                     $prix.",".
                                 "\"".$dim."\",".
                                 "\"".$date_ins."\",".
                                 "\"".$date_modif."\",".
                                     $masse.",".
                                     $objtyp.",".
				     $RubriqueId.
                                 ")";

                         $res = execute($query); 
                         $ElectroId = getAutoIncrementValue("$nomtable") ; //Je recupere L'id de cet objet 
                         $this -> setId($ElectroId);

                        //}
                }
	
                public function placerChampsTab(array $_T){//Permet d'affecter aux champs de l'objet , venant d'un array quelconque
                        $this -> setNom(webtotext($_T['Electro_nom']));
                        $this -> setLieu($_T['villeid']);
                        $this -> setDesc(webtotext($_T['Electro_desc']));
                        $this -> setPrix($_T['Electro_prix']);
                        $this -> setDim(webtotext($_T['Electro_dim']));
                        $this -> setMasse($_T['Electro_masse']);
                        $this -> setObjTyp($_T['objtyp']);
                        $this -> setRubriqueId($_T['norubr']);
                }

		public function getArrayTitreTable(){
		//Permet de retourner les nom des champs de la table correspondante a cette classe pwermetant de former le titre d'une insertion
		//Ceci permet de titrer une insertion afficher
		$t = array();
		$t[0] = "nom";
		return $t ;
		}

                public function createFromSession(){//Permet de sauvegarder les attributs d'un objet en session en attendant la connexion du User
                       
                                $this -> placerChampsTab($_SESSION);
                                $this -> creer();
                                return true ;
                                
                }

        }//Fin classe ElectroTab

?>
