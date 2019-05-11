<?php

/*
*@Cette classe conserve en bd la liste  des rubriques que l'application offre
*
*
*/

class Object{
	function __construct(){




	}

	public function getRubriques(){
		$query = "select * from RubriqueTab" ;
		$res = execute($query);
		$rubrs = array(); $i = 0 ;
		$rubrs[$i] = "Choisir une Rubrique";
		while($l = mysql_fetch_assoc($res)){
			$i++ ;
			$rubrs[$i] = $l['Rubrique_nom'];
		}

		return $rubrs ;
	}

	public function getTabs(){
		$query = "select * from RubriqueTab" ;
		$res = execute($query);
		$tabs = array(); $i = 0 ;
		while($l = mysql_fetch_assoc($res)){
			$i++ ;
			$tabs[$i] = $l['tab'];
		}
		// echo $i ;
		return $tabs ;
	}


	public function getNoRubrique($nomtable , $objectid){
                $norubr = 0 ;
                if(!empty($nomtable) && is_numeric($objectid)){
		        $query = "select RubriqueId from RubriqueTab where tab='".$nomtable."'" ;
		        $res = execute($query);
		        while($l = mysql_fetch_assoc($res)){
			        $norubr = $l['RubriqueId'];
		        }
		        
                }
                return $norubr;
	}


	public function getUserId($nomtable , $objectid){
                $userid = 0 ;
                if(!empty($nomtable) && filter_var($objectid , FILTER_VALIDATE_INT)){
		        $query = "select * from $nomtable where ".str_replace("Tab","",$nomtable)."Id=".$objectid ;
		        $res = execute($query);
		        while($l = mysql_fetch_assoc($res)){
			        $userid = $l['UserId'];
		        }
		        
                }else{
                        echo errmess("On n'a pas pu selectionner le no de rubrique nomtable= $nomtable , objectid = $objectid das object :: getUserId(nt , oid)");
        
                }
                return $userid;
	}



	public function getNomRubrique($nomtable , $objectid){
                $nomrubrique = "";
                if(!empty($nomtable) && filter_var($objectid , FILTER_VALIDATE_INT)){
		        $norubr = $this -> getNoRubrique($nomtable , $objectid) ;
			$t = $this -> getRubriques();
			$nomrubrique = $t[$norubr];
                }
			return  $nomrubrique ;
	}

	public function getObjTyp($nomtable , $objectid){
                $objtyp = "";
                if(!empty($nomtable) && filter_var($objectid , FILTER_VALIDATE_INT)){
			$r = execute("select ObjTyp from $nomtable where ".str_replace("Tab","",$nomtable)."Id=$objectid");
			$l = mysql_fetch_assoc($r);
			$objtyp = $l['ObjTyp'];
                }
			return  $objtyp ;
	}


	public function getNomRubrFromNo($norubr){
                $nomrubrique = "";
                if(!empty($norubr) && filter_var($norubr , FILTER_VALIDATE_INT)){
		        
			$t = $this -> getRubriques();
			$nomrubrique = $t[$norubr];
                }
			return  $nomrubrique ;
	}


	public function getVilleId($nomtable , $objectid){
                $villeid = 0 ;
                if(!empty($nomtable) && filter_var($objectid , FILTER_VALIDATE_INT)){
		       $q = "select VilleId from $nomtable where " . str_replace("Tab","",$nomtable) ."Id=$objectid" ;        
			$r = execute($q);
			if(mysql_num_rows($r) > 0){
				while($l = mysql_fetch_assoc($r)){
				$villeid = $l['VilleId'] ;
				//return $l['VilleId'] ;
				}
			}
	        }
			return  $villeid ;
	}


	public function getTitleTab($nomtable){
                $titre = "" ;
                if(!empty($nomtable)){

			switch($nomtable){
				case "AutoTab" :
					$titre = "Auto_nom" ;
					break ;
				case "ElectroTab" :
					$titre = "Electro_nom" ;
					break ;
				case "ImmobilierTab" :
					$titre = "Immobilier_nom" ;
					break ;
				case "JobTab" :
					$titre = "Job_nom" ;
					break ;
				case "MeubleTab" :
					$titre = "Meuble_nom" ;
					break ;
				case "ObjArtTab" :
					$titre = "ObjArt_nom" ;
					break ;
				case "ProdAgrTab" :
					$titre = "ProdAgr_nom" ;
					break ;
				default : 
					echo  errmess("$nomtable is invalid in Object-> getTitleTab in file class/Object.inc");
			}


	        }
			return  $titre ;
	}


}//Fin classe Object

?>
