<?php
       
        /*
        *@Cette class modelise un objet Jobs et business
        *
        *@Tout ses attributs correspondent a ceux de la table-JobTab a la quelle cet objet appartient
        *
        *
        *
        */

        class JobTab{
                private $JobId = 0 ; private $UserId= 0 ; private $Job_title ;  private $Job_desc ;
                private $ObjTyp = 0 ;   private $Date_ins = "" ;
                private $Job_lieu ; 
                private $Date_modif = "" ; private $RubriqueId ;

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d");
                        $this -> RubriqueId = 0 ;
                        $this -> JobId = 0 ;
                        $this -> ObjTyp = 0 ;
                        $this -> UserId = 0 ;
		}

                //Modificateurs setters
                public function setId($id){
                        $this -> JobId = $id ;
                        
                }

                public function setUserId($id){
                        $this -> UserId = $id ;
                }

                public function setDesc($p){
                        $this -> Job_desc = $p ;
                }

                public function setTitle($m){
                        $this -> Job_title = $m ;
                }

                public function setDateIns($di){
                        $this -> Date_ins = $di ;
                }

                public function setLieu($l){
                        $this -> Job_lieu = $l ;
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
                        return $this -> JobId  ;
                }

                public function getUserId(){
                        return $this -> UserId  ;
                }

                public function getDesc(){
                        return $this -> Job_desc  ;
                }

                public function getTitle(){
                        return $this -> Job_title  ;
                }

                public function getDateIns(){
                        return $this -> Date_ins  ;
                }

                public function getLieu(){
                        return $this -> Job_lieu  ;
                }

                public function getObjTyp(){
                        return $this -> ObjTyp  ;
                }

                public function getDateModif(){
                        return $this -> Date_modif  ;
                }

                public function getRubriqueId(){
                       return $this -> RubriqueId  ;
                }

                public function getAttribAsArray(){
                        $t = array(
		                
                                "Titre" => "Job_nom",
		               // "Ville" => "Job_lieu",
		                "Detail" => "Job_desc"
	                );
                        return $t ;
                }


                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t =  array(1,1);
                        return $t ;
                }


                public function getTableTailles(){
                //Cette fonction retoure un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(100,100);
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(0,1);
                        return $t ;
                }

	
                public function placerChamps(){
                        $this -> placerChampsTab($_POST);
                }

                public function creer($nomtable="JobTab"){
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
                        $title = addslashes($this -> getTitle());
                        //$lieu = addslashes($this -> getLieu());
                        $lieu = $this -> getLieu();//Le lieu ici est l'id de la ville et non le nom du lieu
			$ville = new Ville(); $villeid = 0 ;
			$villeid = ( filter_var($lieu , FILTER_VALIDATE_INT)) ? $lieu : 0  ;//On recupere la villeid de ce lieu appartenant a cet objet              
                        $desc = addslashes($this -> getDesc());
                        $date_ins = date("Y-m-d H:i:s");
                        $date_modif = $this -> getDateModif();
                        $objtyp = $this -> getObjTyp();
                        $RubriqueId  = $this -> getRubriqueId();
                        $query = "insert into $nomtable values(".
                                 "JobId,".
                                 $userid.",".
                                 "\"".$desc."\",".
                                 "\"".$title."\",".
                                 "\"".$date_ins."\",".
                                     $villeid.",".
                                     $objtyp.",".
                                 "\"".$date_modif."\",".
                                     $RubriqueId.
                                 ")";

                         $res = execute($query); 
                         $jobId = getAutoIncrementValue($nomtable) ; //Je recupere L'id de cet objet 
                         $this -> setId($jobId);
                        //}
                }


                public function placerChampsTab($_T){
                        $this -> setTitle(webtotext($_T['Job_nom']));
                        $this -> setLieu($_T['villeid']);
                        $this -> setDesc(webtotext($_T['Job_desc']));
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
		$t[0] = "title";
		return $t ;
		}
        }//Fin classe JobTab

?>
