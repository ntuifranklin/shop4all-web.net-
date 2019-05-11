<?php
       
        /*
        *@Cette class modelise un objet automobile
        *
        *@Tout ses attributs correspondent a ceux de la table-AutoTab à la quelle cet objet appartient
        *
        *
        *
        */

        class AutoTab{
                private $AutoId = 0 ; private $UserId= 0 ; private $Auto_marque ; private $Auto_titre ;private $Auto_model ; private $Auto_lieu ; //A l'insertion en bd on sauvegardera l'id de ce lieu(cette ville)
                private $Date_ins = "" ;
                private $Auto_proprios = "" ; private $Auto_puissance = 0 ;
                private $Auto_kilometrage = 0 ; private $Auto_prix = 0 ; 
                private $Auto_carburant = "" ; private $Auto_couleur = "" ; 
                private $Auto_comfort = "" ; private $Auto_desc = "" ; 
                private $ObjTyp = 0 ; private $Date_modif = "" ; private $RubriqueId = 0 ; 

		function __construct(){
                        $this -> Date_ins = date("Y-m-d");
                        $this -> Date_modif = date("Y-m-d");
			$this -> RubriqueId = 0 ; 
			$this -> AutoId = 0 ; 
			$this -> ObjTyp = 0 ; 
			$this -> Auto_prix = 0 ; 
			$this -> Auto_couleur = "" ; 
			$this -> Auto_kilometrage = 0 ; 
                        $this -> Auto_puissance = 0 ;
			$this -> UserId = 0 ; 
		}
                

                //Modificateurs setters
                public function setId($id){
                        $this -> AutoId = $id ;
                }

                public function setUserId($id){
                        $this -> UserId = $id ;
                }

                public function setTitre($m){
                        $this -> Auto_titre = $m ;
                }

                public function setMarque($m){
                        $this -> Auto_marque = $m ;
                }

                public function setModel($m){
                        $this -> Auto_model = $m ;
                }

                public function setLieu($l){
                        $this -> Auto_lieu = $l ;
                }

                public function setDateIns($di){
                        $this -> Date_ins = $di ;
                }

                public function setProprios($p){
                        $this -> Auto_proprios = $p ;
                }

                public function setPuissance($p){
                        $this -> Auto_puissance = $p ;
                }

                public function setKilometrage($p){
                        $this -> Auto_kilometrage = $p ;
                }

                public function setPrix($p){
                        $this -> Auto_prix = $p ;
                }

                public function setCarburant($p){
                        $this -> Auto_carburant = $p ;
                }
		
                public function setCouleur($p){
                        $this -> Auto_couleur = $p ;
                }

                public function setComfort($p){
                        $this -> Auto_comfort = $p ;
                }

                public function setDesc($p){
                        $this -> Auto_desc = $p ;
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

          
                //Accesseurs getters
                public function getId(){
                        return $this -> AutoId  ;
                }

                public function getUserId(){
                        return $this -> UserId  ;
                }

                public function getTitre(){
                        return $this -> Auto_titre ;
                }

                public function getMarque(){
                        return $this -> Auto_marque ;
                }

                public function getModel(){
                        return $this -> Auto_model  ;
                }

                public function getLieu(){
                        return $this -> Auto_lieu  ;
                }

                public function getDateIns(){
                        return $this -> Date_ins  ;
                }

                public function getProprios(){
                        return $this -> Auto_proprios  ;
                }

                public function getPuissance(){
                        return $this -> Auto_puissance ;
                }

                public function getKilometrage(){
                        return $this -> Auto_kilometrage  ;
                }

                public function getPrix(){
                        return $this -> Auto_prix  ;
                }

                public function getCarburant(){
                        return $this -> Auto_carburant  ;
                }
		
                public function getCouleur(){
                        return $this -> Auto_couleur  ;
                }

                public function getComfort(){
                        return $this -> Auto_comfort  ;
                }

                public function getDesc(){
                        return $this -> Auto_desc  ;
                }

                public function getObjTyp(){
                        return $this -> ObjTyp  ;
                }

                public function getDateModif(){
                        return $this -> Date_modif  ;
                }
	

                public function getRubriqueId(){
                        return $this -> RubriqueId ;
                }


                public function getAttribAsArray(){
                        $t = array(
				"Titre" => "Auto_nom",
		                "Marque" => "Auto_marque",
		                "Model" => "Auto_model",
		                //"Ville" => "Auto_lieu",
		                "Nombre de Propri&eacute;taires" => "Auto_proprios",
		                "Puissance" => "Auto_puissance",
		                "Kilometrage" => "Auto_kilometrage",
		                "Prix" => "Auto_prix",
		                "Type de carburant" => "Auto_carburant",
		                "Couleur" => "Auto_couleur",
		                "Comfort(Est elle comfortable ?)" => "Auto_comfort",
		                "Details" => "Auto_desc"
	                );
                        return $t ;
                }
                
                public function getTableTypes(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => String , 0 => Numeric
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(1,1,1,0,0,0,0,1,1,1,1); ;
                        return $t ;
		/*
		*	
                        $t = array(
				"Titre" => "Auto_nom",
		                "Marque" => "Auto_marque",
		                "Model" => "Auto_model",
		                //"Ville" => "Auto_lieu",
		                "Nombre de Propri&eacute;taires" => "Auto_proprios",
		                "Puissance" => "Auto_puissance",
		                "Kilometrage" => "Auto_kilometrage",
		                "Prix de cette auto  " => "Auto_prix",
		                "Type de carburant" => "Auto_carburant",
		                "Couleur de cette auto " => "Auto_couleur",
		                "Comfort(Est elle comfortable ?)" => "Auto_comfort",
		                "Description concernant cette auto " => "Auto_desc"
	                );
		*/
                }


                public function getTableTailles(){
                //Cette fonction retoure un tableau pour la longeur max des champs dans MySQL pour la Table correspondant a cette classe
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(100,30,30,11,11,11,11,30,30,30,100) ;
                        return $t ;
                }

                public function getTableNulls(){
                //Cette fonction retoure un tableau pour les types des champs dans MySQL pour la Table correspondant a cette classe
                // La valeur 1 => Oui peut etre vide , 0 => Non ne peut etre vide
                //Ce tableau a une taille equialent a celle retourner par $this -> getAttribasarray();
                        $t = array(0,0,1,1,1,1,0,1,1,1,1);
                        return $t ;
                }
                        
                public function placerChamps(){//Place les champs depuis le tableau $_POST
			$this -> placerChampsTab($_POST);

                }

                public function creer($nomtable = "AutoTab"){
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
			$titre =  addslashes($this -> getTitre()) ;
                        $marque = addslashes($this -> getMarque());
                        $model = addslashes($this -> getModel());
                        $lieu = $this -> getLieu();//Le lieu ici est l'id de la ville et non le nom du lieu comme auparavant
			$ville = new Ville(); $villeid = 0 ;
			$villeid = ( filter_var($lieu , FILTER_VALIDATE_INT)) ? $lieu : 0  ;//On recupere la villeid de ce lieu appartenant a cet objet AutoTab                     
			
                        $date_ins = date("Y-m-d H:i:s");
                        $proprios = addslashes($this -> getProprios());
                        $puissance = addslashes($this -> getPuissance());
                        $kilometrage = $this -> getKilometrage();
                        $prix = $this -> getPrix();
                        $carburant = $this -> getCarburant();
                        $couleur = addslashes($this -> getCouleur());
                        $comfort = addslashes($this -> getComfort());
                        $desc = addslashes($this -> getDesc());
                        $objtyp = $this -> getObjTyp();
                        $date_modif = $this -> getDateModif();
                        $RubriqueId = $this -> getRubriqueId();
			 
                        $query = "insert into $nomtable values(".
                                 "AutoId,".
                                 $userid.",".
                                 "\"".$titre."\",".
                                 "\"".$marque."\",".
                                 "\"".$model."\",".
                                    $villeid.",".
                                 "\"".$date_ins."\",".
                                     $proprios.",".
                                     $puissance.",".
                                     $kilometrage.",".
                                     $prix.",".
                                 "\"".$carburant."\",".
                                 "\"".$couleur."\",".
                                 "\"".$comfort."\",".
                                 "\"".$desc."\",".
                                     $objtyp.",".
                                 "\"".$date_modif."\",".
                                     $RubriqueId.
                                 ")";
                         $res = execute($query); 
                         $AutoId = getAutoIncrementValue("$nomtable") ; //Je recupere L'id de cet objet 
                         $this -> setId($AutoId);
                        
                }


                public function placerChampsTab(array $_T){//Permet d'affecter aux champs de l'objet , venant d'un array quelconque
                        $this -> setMarque(webtotext($_T['Auto_marque']));
                        $this -> setTitre(webtotext($_T['Auto_nom']));
                        $this -> setModel(webtotext($_T['Auto_model']));
                        $this -> setLieu($_T['villeid']);
                        $this -> setProprios($_T['Auto_proprios']);
                        $this -> setPuissance($_T['Auto_puissance']);
                        $this -> setKilometrage($_T['Auto_kilometrage']);
                        $this -> setPrix($_T['Auto_prix']);
                        $this -> setCarburant(webtotext($_T['Auto_carburant']));
                        $this -> setCouleur(webtotext($_T['Auto_couleur']));
                        $this -> setComfort(webtotext($_T['Auto_comfort']));
                        $this -> setDesc(webtotext($_T['Auto_desc']));
                        $this -> setObjTyp($_T['objtyp']);
                        $this -> setRubriqueId($_T['norubr']);
                }

		public function getArrayTitreTable(){
		//Permet de retourner les nom des champs de la table correspondante a cette classe pwermetant de former le titre d'une insertion
		//Ceci permet de titrer une insertion afficher
		$t = array();
		$t[0] = "marque";
		$t[1] = "model";
		return $t ;
		}

                public function createFromSession(){//Permet de sauvegarder les attributs d'un objet en session en attendant la connexion du User
                       
                                $this -> placerChampsTab($_SESSION);
                                $this -> creer();
                                return true ;
                                
                }


                
        }//Fin classe AutoTab

?>
