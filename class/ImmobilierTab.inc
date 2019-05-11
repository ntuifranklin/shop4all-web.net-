<?php
       
        /*
        *@Cette class lieuise un objet Immobiliermobile
        *
        *@Tout ses attributs correspondent a ceux de la table-ImmobilierTab a la quelle cet objet appartient
        *
        *
        *
        */

        class ImmobilierTab{
                private $ImmobilierId = 0 ; private $UserId= 0 ; private $Immobilier_nom ;  private $Immobilier_desc ;
                private $ObjTyp = 0 ;   private $Date_ins = "" ;private $Immobilier_prix = "" ;
                private $Immobilier_lieu ; 
                private $Date_modif = "" ; private $RubriqueId = 0;

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d"); 
			$this -> RubriqueId = 0 ;
			$this -> ObjTyp = 0 ;
			$this -> UserId = 0 ;
			$this -> ImmobilierId = 0 ;
			$this -> Immobilier_lieu = 0 ;
			$this -> Immobilier_nom = "" ;
			$this -> Immobilier_desc = "" ;
			$this -> Immobilier_prix = 0 ;
		}
                

                //Modificateurs setters
                public function setId($id){
                        $this -> ImmobilierId = $id ;
                }

                public function setUserId($id){
                        $this -> UserId = $id ;
                }

                public function setNom($m){
                        $this -> Immobilier_nom = $m ;
                }

                public function setDesc($p){
                        $this -> Immobilier_desc = $p ;
                }

                public function setObjTyp($p){
                        $this -> ObjTyp = $p ;
                }

                public function setDateIns($di){
                        $this -> Date_ins = $di ;
                }

                public function setPrix($p){
                        $this -> Immobilier_prix = $p ;
                }

                public function setLieu($l){
                        $this -> Immobilier_lieu = $l ;
                }


                public function setDateModif($p){
                        $this -> Date_modif = $p ;
                }

                public function setRubriqueId($p){
                        $this -> RubriqueId = $p ;
                }

	
                               //Modificateurs getters
                public function getId(){
                        return $this -> ImmobilierId  ;
                }

                public function getUserId(){
                        return $this -> UserId  ;
                }

                public function getNom(){
                        return $this -> Immobilier_nom  ;
                }

                public function getDesc(){
                        return $this -> Immobilier_desc  ;
                }

                public function getObjTyp(){
                        return $this -> ObjTyp  ;
                }

                public function getDateIns(){
                        return $this -> Date_ins ;
                }

                public function getPrix(){
                        return $this -> Immobilier_prix;
                }

                public function getLieu(){
                        return $this -> Immobilier_lieu ;
                }


                public function getDateModif(){
                        return $this -> Date_modif ;
                }


                public function getRubriqueId(){
                        return $this -> RubriqueId ;
                }


                public function getAttribAsArray(){
                        $t = array(
		                
		                "Titre" => "Immobilier_nom",
		                "Detail" => "Immobilier_desc",
		                "Prix" => "Immobilier_prix"
		               // "Ville" => "Immobilier_lieu"
	                );
                        return $t ;
                }
	       
                public function placerChamps(){
			$this -> placerChampsTab($_POST);
                }

                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(1,1,0);
                        return $t ;
                }


                public function getTableTailles(){
                //Cette fonction retoure un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(100,100,11);
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retourne un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribAsArray();
                        $t = array(0,1,0);
                        return $t ;
                }

                public function creer($nomtable="ImmobilierTab"){
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
                       
                        $date_ins = date("Y-m-d H:i:s");
                        $date_modif = $this -> getDateModif();
                        $RubriqueId = $this -> getRubriqueId();
                        $objtyp = $this -> getObjTyp();
                        $query = "insert into $nomtable values(".
                                 "ImmobilierId,".
                                 $userid.",".
                                 "\"".$nom."\",".
                                 "\"".$desc."\",".
                                     $objtyp.",".
                                 "\"".$date_ins."\",".
                                     $prix.",".
                                     $villeid.",".
                                 "\"".$date_modif."\" ,".
				     $RubriqueId.
                                 ")";

                         $res = execute($query); 
                         $ImmobilierId = getAutoIncrementValue("$nomtable") ; //Je recupere L'id de cet objet 
                         $this -> setId($ImmobilierId); 
                        //}
                }
	
                public function placerChampsTab($_T){
                        $this -> setNom(webtotext($_T['Immobilier_nom']));
                        $this -> setLieu($_T['villeid']);
                        $this -> setDesc(webtotext($_T['Immobilier_desc']));
                        $this -> setPrix($_T['Immobilier_prix']);
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

        }//Fin classe ImmobilierTab

?>
