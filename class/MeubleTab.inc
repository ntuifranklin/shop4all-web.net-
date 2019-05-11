<?php
       
        /*
        *@Cette class modelise un objet Meuble
        *
        *@Tout ses attributs correspondent a ceux de la table-MeubleTab a la quelle cet objet appartient
        *
        *
        *
        */

        class MeubleTab{
                private $MeubleId = 0 ; private $UserId= 0 ; private $Meuble_nom ;  private $Meuble_desc ;
                private $ObjTyp = 0 ;   private $Date_ins = "" ;private $Meuble_prix = "" ;
                private $Meuble_lieu ; private $Meuble_dim = "";
                private $Date_modif = "" ; private $RubriqueId ;

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d");
			$this -> ObjTyp = 0 ;
			$this -> MeubleId = 0 ;
			$this -> Meuble_nom = "" ;
			$this -> Meuble_desc = "" ;
			$this -> Meuble_dim = "" ;
			$this -> Meuble_prix = 0 ;
			$this -> RubriqueId = 0 ;
			$this -> UserId = 0 ;
		}

                //Modificateurs setters
                public function setId($id){
                        $this -> MeubleId = $id ;
                }

                public function setUserId($id){
                        $this -> UserId = $id ;
                }

                public function setNom($m){
                        $this -> Meuble_nom = $m ;
                }

                public function setdesc($p){
                        $this -> Meuble_desc = $p ;
                }

                public function setLieu($l){
                        $this -> Meuble_lieu = $l ;
                }

                public function setDim($p){
                        $this -> Meuble_dim = $p ;
                }

                public function setPrix($p){
                        $this -> Meuble_prix = $p ;
                }

                public function setDateIns($di){
                        $this -> Date_ins = $di ;
                }


                public function setObjTyp($p){
                        $this -> ObjTyp = $p ;
                }

                public function setDateModif($p){
                        $this -> Date_modif = $p ;
                }

                public function setRubriqueId($p){
                        $this -> RubriqueId = $p ;
                }

	
                               //Modificateurs getters
                public function getId(){
                        return $this -> MeubleId  ;
                }

                public function getUserId(){
                        return $this -> UserId  ;
                }

                public function getNom(){
                        return $this -> Meuble_nom  ;
                }

                public function getDesc(){
                        return $this -> Meuble_desc  ;
                }

                public function getObjTyp(){
                        return $this -> ObjTyp  ;
                }

                public function getDateIns(){
                        return $this -> Date_ins ;
                }

                public function getPrix(){
                        return $this -> Meuble_prix;
                }

                public function getLieu(){
                        return $this -> Meuble_lieu ;
                }


                public function getDateModif(){
                        return $this -> Date_modif ;
                }

                public function getDim(){
                        return $this -> Meuble_dim ;
                }
	
                public function getRubriqueId(){
                       return  $this -> RubriqueId ;
                }

                public function getAttribAsArray(){
                        $t = array(
		                "Titre" => "Meuble_nom",
		               // "Ville" => "Meuble_lieu",
		                "Detail" => "Meuble_desc",
		                "Prix" => "Meuble_prix",
		                "Dimension" => "Meuble_dim"
	                );
                        return $t ;
                }
               

                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(1,1,0,1);
                        return $t ;
                }


                public function getTableTailles(){
                //Cette fonction retoure un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(100,100,11,30);
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(0,1,0,1);
                        return $t ;
                }

             

                public function placerChamps(){
                        $this -> placerChampsTab($_POST);
                }

                public function creer($nomtable="MeubleTab"){
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
                        //$lieu = addslashes($this -> getLieu());
                        $lieu = $this -> getLieu();//Le lieu ici est l'id de la ville et non le nom du lieu
			$ville = new Ville(); $villeid = 0 ;
			$villeid = ( filter_var($lieu , FILTER_VALIDATE_INT)) ? $lieu : 0  ;//On recupere la villeid de ce lieu appartenant a cet objet  
                        $dim = addslashes($this -> getDim());
                        $prix = $this -> getPrix();
                        $date_ins = date("Y-m-d H:i:s");
                        $objtyp = $this -> getObjTyp();
                        $date_modif = $this -> getDateModif();
                        $RubriqueId = $this -> getRubriqueId();
                        $query = "insert into $nomtable values(".
                                 "MeubleId,".
                                 $userid.",".
                                 "\"".$nom."\",".
                                 "\"".$desc."\",".
                                     $villeid.",".
                                 "\"".$dim."\",".
                                     $prix.",".
                                 "\"".$date_ins."\",".
                                     $objtyp.",".
                                 "\"".$date_modif."\",".
                                     $RubriqueId.
                                 ")";

                         $res = execute($query); 
                         $MeubleId = getAutoIncrementValue("$nomtable") ; //Je recupere L'id de cet objet 
                         $this -> setId($MeubleId);
                        //}
                }


                public function placerChampsTab($_T){
                        $this -> setNom(webtotext($_T['Meuble_nom']));
                        $this -> setDesc(webtotext($_T['Meuble_desc']));
                        $this -> setLieu($_T['villeid']);
                        $this -> setDim(webtotext($_T['Meuble_dim']));
                        $this -> setPrix($_T['Meuble_prix']);
                        $this -> setObjTyp($_T['objtyp']);
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
	

        }//Fin classe MeubleTab

?>
