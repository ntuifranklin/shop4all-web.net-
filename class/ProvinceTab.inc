<?php
       
        /*
        *@ Cette classe modelise un utilisateur
        *
        *@ Tout ses attributs correspondent a ceux de la table ProvinceTab sur base de données
        *
        *
        *
        */

        class Province{
            private $ProvinceId = 0 ;private $Province_nom = "";  
            

            function  __construct(){
		$this -> ProvinceId = 0;
		$this -> Province_nom = "";
            }  
            

            //Modificateurs
            public function setId($id){
                $this -> ProvinceId = $id ;
            }

            public function setNom($nom){
                $this -> Province_nom = $nom ;
            }



            //Accesseurs

            public function getId(){
                return $this -> ProvinceId   ;
            }

            public function getNom(){
                return $this -> Province_nom   ;
            }



            public function creer(){
                        $nomProvince = addslashes($this -> getNom());
                        $provinceid = (is_numeric($this -> getId())) ? $this -> getId() : 0 ;  
			$ProvinceExiste = false ; $ProvinceExiste =  $this -> ProvinceNomExists();
                        if(! $ProvinceExiste ){ //On cree une nouvelle Province Si et seulement si cette Province n'existe pas deja en bd             
                                $query = "insert into ProvinceTab values(".
                                         "ProvinceId,".
                                         "'".$nomProvince."'"
                                .")" ;
                        
                                $res = execute($query);
                                $nomtable = "ProvinceTab";
                                $id = getAutoIncrementValue($nomtable) ;
                                $this -> setId($id);
                        }else{//Si la Province existe deja alors on charge tout simplement ses donnees dans cet objet Province et on libere le plancher
                                $this -> loadDataFromNom();
                        }
          }

          public function loadData(){
            //Permet de charger dans cet objet Province une ligne de la table ProvinceTab correpondant a la ProvinceId de cet objet
                $Provinceid = $this -> getId();
                if( is_numeric($Provinceid) && !empty($Provinceid) ){
                        $query = "select * from ProvinceTab where ProvinceId=".$Provinceid;

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                while($l = mysql_fetch_assoc($res))
                                        $this -> placerChamps($l);//Affectation au champ de cet objet
                                
                        }
                }

          }


          public function loadDataFromNom(){
                //Permet de charger dans cet objet Province une ligne de la table ProvinceTab correpondant a la Province_nom de cet objet
                $nom = addslashes($this -> getNom());
                if( ! empty($nom)){
                        $query = "select * from ProvinceTab where Province_nom='".$nom."'";

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                while($l = mysql_fetch_assoc($res))
                                        $this -> placerChamps($l);//Affectation au champ de cet objet
                                
                        }
                }

          }


          public function ProvinceNomExists(){
                //Permet de verifier s'il existe au moins deja une vile dans la table
                $nom = addslashes($this -> getNom()); $bool = false ;
                if( ! empty($nom)){
                        $query = "select * from ProvinceTab where Province_nom='".$nom."'";

                        $res = execute($query);
                        if(mysql_num_rows($res) > 0 ){
                                $bool = true ;
                                
                        }
                }
                return $bool ;
          }



        public function placerChamps(array $_T){ 
         //Affecte au champs de cette objet les valeurs venant d'un array contenant les meme attributs que cet objet Province
                $this -> setNom(stripslashes($_T['Province_nom']));
                $this -> setId(stripslashes($_T['ProvinceId']));
        }

	public function whichProvinceId($nomProvince){
		//Prends en parametre une Province et retourne son id
		//Si la Province n'existe pas alors elle sera creer et son id sera retourner		
		$Provinceid = 0 ;
		if(is_string($nomProvince)  ){
			$this -> setNom($nomProvince);
			$this -> creer();
			$Provinceid = $this -> getId();
		}
		return $Provinceid ;
	}


	public function getIdsLikeNom($nomProvince){
		//Prends en parametre une Province et retourne les ids dont les noms sont semblable ou egale a *nomProvince*
		//Si la Province n'existe pas alors elle sera creer et son id sera retourner		
		$Provinceids = array() ;$k=0;
		if(is_string($nomProvince) && !empty($nomProvince) ){
			$q = "select * from ProvinceTab where Province_nom like '_".$nomProvince."_'";
			$res = execute($q);
			while($l = mysql_fetch_assoc($res)){
				$Provinceids[$k] = stripslashes($l["Province_nom"]); $k++ ;

			}
		}
		return $Provinceids ;
	}

	public function listProvinces(){
		$q = "select * from ProvinceTab";
		$res = execute($q); $ligne = "";
		while( $l = mysql_fetch_assoc($res)){
			foreach($l as $field => $nomProvince)
				$ligne .= $field." = ". stripslashes($nomProvince)." ";
				$ligne .= " <br> ";

		}
		return $ligne ;
	}

          public function getDropDownProvinces($nom = "provid"){
                //Permet de verifier s'il existe au moins deja une vile dans la table
                
        
                $query = "select * from ProvinceTab";
		$ligne = "<select name='$nom'>";$dropdown = "" ;
                $res = execute($query);
                if(mysql_num_rows($res) > 0 ){
		   $ligne .= "<option value=-1>Choisir une Province" ;
                   while($l = mysql_fetch_assoc($res))
			if($_POST[$nom] == $l['ProvinceId'])
				$ligne .= "<option value=".$l['ProvinceId']." selected>".$l['Province_nom'] . "</option>" ;
			else 
				$ligne .= "<option value=".$l['ProvinceId'].">".$l['Province_nom'] . "</option>" ;
                   	$ligne .= "</select>" ;     
                }else{
		   $ligne = "<select name='$nom' ><option value=0 selected>Pas de province</option></select>" ;
		}
                $dropdown .= $ligne ;
                return $dropdown ;
          }


          public function getProvinceFromId($provid){
                //Permet de verifier s'il existe au moins deja une vile dans la table
                $nomProvince = "" ;
        	if(filter_var($provid , FILTER_VALIDATE_INT) && $provid > 0){
                	$query = "select Province_nom from ProvinceTab where ProvinceId=$provid";
                	$res = execute($query);
                if(mysql_num_rows($res) > 0 )
                   while($l = mysql_fetch_assoc($res))
			$nomProvince = $l['Province_nom'] ;
		}                

			return $nomProvince ;
          }





        }//Fin classe Province

?>
