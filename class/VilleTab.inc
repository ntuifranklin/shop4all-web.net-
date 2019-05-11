<?php
       
        /*
        *@ Cette classe modelise un utilisateur
        *
        *@ Tout ses attributs correspondent a ceux de la table VilleTab sur bd
        *
        *
        *
        */

        class Ville{
            private $VilleId = 0 ;private $Ville_nom = "";  
            private $ProvinceId = 0; 

            function  __construct(){
		$this -> VilleId = 0;
		$this -> Ville_nom = "";
		$this -> ProvinceId = 0;
            }  
            

            //Modificateurs
            public function setId($id){
                $this -> VilleId = $id ;
            }

            public function setNom($nom){
                $this -> Ville_nom = $nom ;
            }

            public function setProvinceId($id){
                $this -> ProvinceId = $id ;
            }


            //Accesseurs

            public function getId(){
                return $this -> VilleId   ;
            }

            public function getNom(){
                return $this -> Ville_nom   ;
            }

            public function getProvinceId(){
                return $this -> ProvinceId   ;
            }


            public function creer(){
                        $nomville = addslashes($this -> getNom());
                        $provinceid = (is_numeric($this -> getProvinceId())) ? $this -> getProvinceId() : 0 ;  
			$villeExiste = false ; $villeExiste =  $this -> villeNomExists();
                        if(! $villeExiste ){ //On cree une nouvelle ville Si et seulement si cette ville n'existe pas deja en bd             
                                $query = "insert into VilleTab values(".
                                         "VilleId,".
                                         "'".$nomville."',".
                                            $provinceid
                                .")" ;
                        
                                $res = execute($query);
                                $nomtable = "VilleTab";
                                $id = getAutoIncrementValue($nomtable) ;
                                $this -> setId($id);
                        }else{//Si la ville existe deja alors on charge tout simplement ses donnees dans cet objet ville et on libere le plancher
                                $this -> loadDataFromNom();
                        }
          }

          public function loadData(){
            //Permet de charger dans cet objet ville une ligne de la table VilleTab correpondant a la villeId de cet objet
                $villeid = $this -> getId();
                if( is_numeric($villeid) && !empty($villeid) ){
                        $query = "select * from VilleTab where VilleId=".$villeid;

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                while($l = mysql_fetch_assoc($res))
                                        $this -> placerChamps($l);//Affectation au champ de cet objet
                                
                        }
                }

          }


          public function loadDataFromNom(){
                //Permet de charger dans cet objet ville une ligne de la table VilleTab correpondant a la ville_nom de cet objet
                $nom = addslashes($this -> getNom());
                if( ! empty($nom)){
                        $query = "select * from VilleTab where Ville_nom='".$nom."'";

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                while($l = mysql_fetch_assoc($res))
                                        $this -> placerChamps($l);//Affectation au champ de cet objet
                                
                        }
                }

          }

          public function loadDataFromId(){
                //Permet de charger dans cet objet ville une ligne de la table VilleTab correpondant a la ville_nom de cet objet
                $id = $this -> getId();
                if( filter_var($id , FILTER_VALIDATE_INT) ){
                        $query = "select * from VilleTab where VilleId=$id";

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                while($l = mysql_fetch_assoc($res))
                                        $this -> placerChamps($l);//Affectation au champ de cet objet
                                
                        }
                }

          }


          public function villeNomExists(){
                //Permet de verifier s'il existe au moins deja une vile dans la table
                $nom = addslashes($this -> getNom()); $bool = false ;
                if( ! empty($nom)){
                        $query = "select * from VilleTab where Ville_nom='".$nom."'";

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                $bool = true ;
                                
                        }
                }
                return $bool ;
          }



        public function placerChamps(array $_T){ 
         //Affecte au champs de cette objet les valeurs venant d'un array contenant les meme attributs que cet objet Ville
                $this -> setNom($_T['Ville_nom']);
                $this -> setId($_T['VilleId']);
                $this -> setProvinceId($_T['ProvinceId']);
        }

	public function whichVilleId($nomville){
		//Prends en parametre une ville et retourne son id
		//Si la ville n'existe pas alors elle sera creer et son id sera retourner		
		$villeid = 0 ;
		if(is_string($nomville)  ){
			$this -> setNom($nomville);
			$this -> creer();
			$villeid = $this -> getId();
		}
		return $villeid ;
	}


	public function getIdsLikeNom($nomville){
		//Prends en parametre une ville et retourne les ids dont les noms sont semblable ou egale a *nomville*
		//Si la ville n'existe pas alors elle sera creer et son id sera retourner		
		$villeids = array() ;$k=0;
		if(is_string($nomville) && !empty($nomville) ){
			$q = "select * from VilleTab where Ville_nom like '_".$nomville."_'";
			$res = execute($q);
			while($l = mysql_fetch_assoc($res)){
				$villeids[$k] = $l["Ville_nom"]; $k++ ;

			}
		}
		return $villeids ;
	}

	public function listVilles(){
		$q = "select * from VilleTab";
		$res = execute($q); $ligne = ""; $retour = "" ;
		$ligne = "<tr><td align=center>Num&eacute;ro Ville </td><td align=center>Nom de Ville</td><td align=center>Num&eacute;ro de Province</td></tr>";
		if(mysql_num_rows($res) > 0){ 
			while( $l = mysql_fetch_assoc($res)){
				$ligne .= "<tr>" ;
				foreach($l as $field => $nomville)
					$ligne .= "<td align=center>" . $l[$field]." </td>";
				$ligne .= " </tr> ";

			}
		}else{
		$ligne = "<tr><td align=center colsan=3>Pas de ville</td></tr>" ;
		}
		$retour = "<table>" . $ligne . "</table>" ;
		return $retour ;
	}


	public function getVilleProvince($provid , $nomListe = "villeid" , $selected = 0){
		$nomProvince = "" ; $pr = new Province() ;
		if(filter_var($provid , FILTER_VALIDATE_INT)){
			$nomProvince = $pr -> getProvinceFromId($provid) ;
			$q = "select * from VilleTab where ProvinceId=$provid";
			$res = execute($q); $ligne = ""; $retour = "<select name='$nomListe' title=\"Choisissez une ville dans la province de $nomProvince\">" ;
			$retour .= "<option value=0>Choix de votre ville" ;
			while( $l = mysql_fetch_assoc($res)){
					if($_POST[$nomListe] == $l['VilleId'] || $l['VilleId'] == $selected)
						$ligne .= "<option value=".$l['VilleId']." selected>".$l['Ville_nom'];
					else
						$ligne .= "<option value=".$l['VilleId']." >".$l['Ville_nom'];
					

			}
		}
		$retour .= $ligne ;
		$retour .= "</select>" ;
		if( !empty($ligne) )		
		return $retour ;
		else 
		return "Pas de ville correspondant" ;
	}

          public function getDropDownVilles($nom = "villeid" , $selected = -1){ //
                //Permet de verifier s'il existe au moins deja une vile dans la table
                
        
                $query = "select * from VilleTab";
		$ligne = "<select name='$nom' title='Cliquez dessus et tappez les trois premieres lettres de \n votre Ville et il sera selectionner automtiquement'>";$dropdown = "" ;
                $res = execute($query);
                if(mysql_num_rows($res) > 0 ){
		   $ligne .= "<option value=-1>Toutes les Villes" ;
                   while($l = mysql_fetch_assoc($res))
			if($_POST[$nom] == $l['VilleId'] || $l['VilleId'] == $selected )
				$ligne .= "<option value=".$l['VilleId']." selected>".$l['Ville_nom'] . "</option>" ;
			else 
				$ligne .= "<option value=".$l['VilleId'].">".$l['Ville_nom'] . "</option>" ;
                   	$ligne .= "</select>" ;     
                }else{
		   $ligne = "<select name='$nom' ><option value=0 selected>Pas de ville</option></select>" ;
		}
                $dropdown .= $ligne ;
                return $dropdown ;
          }

	public function getListId($provid = 0){//Retourne une array liste d'id des villes pour la province $provid
	//Par défaut , $provid = 0 => on retourne tout les id des villes
		$villeIds = array();
		$q = "select * from VilleTab where 1 ";
		$condition = "" ;$i = 0 ;
		if(filter_var($provid , FILTER_VALIDATE_INT)){
			//$nomProvince = $pr -> getProvinceFromId($provid) ;
			if($provid > 0 )
			$condition .= " and ProvinceId=$provid" ;
			$res = execute($q.$condition);
			while( $l = mysql_fetch_assoc($res)){
					$villeIds[$i] = $l['VilleId'] ;
					$i++ ;

			}
		}

		return($villeIds);

	}


        }//Fin classe Ville

?>
