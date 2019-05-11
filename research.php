<?php
	include_once('includes/header.inc');
	inclusionTete() ;
        $u = new User();
         if($_POST["r"]){//Si on viens du formulaire recherche
                $t = getT() ; $numeroListe = $_POST["rubr"]; $liste = getRubriqueTableAsArray() ;
                //Le numero de la table mysql a appeler dans la liste des tables mysql retourner par la fonction getRubriqueTableAsArray() ; 
                if($numeroListe < 1){
                        echo prmess("Pas de rubrique choisi pour votre recherche");

                }else{
                        $tout = $_POST["recherche"] ; $nomtable = $liste[$numeroListe] ;  $idprovince = $_POST["proid"] ;
                        $villeid = 0 ; 
                        $ville = new Ville(); 
                        $defaultQuery = "select * from ".$nomtable;
                        $class = new $nomtable();
                        $attrib = $class -> getAttribAsArray();
                        $condition = " where 1 and RubriqueId=$numeroListe "; $condition2 = "";
			if($_POST["proid"] > 0){
					$villsIds = $ville -> getListId($idprovince) ;//Toutes les ids de ville dont les ProvinceId sont égale à $idprovince
				$condition2 .= " and ( 1=1 " ; //Pour eviter les erreurs, si les conditions n'existent pas
				for($k=0;$k<count($villsIds);$k++)
					if(!empty($villsIds[$k])){
						$condition2 .= " or VilleId=".$villsIds[$k] ;
					};
				
				$condition2 .= " )";
				$condition  .= $condition2 ;
			}
			
                        $res = execute( $defaultQuery.$condition);
                        if(mysql_num_rows( $res) > 0)
                         echo showUserInserts($nomtable , $defaultQuery.$condition , $numeroListe);
                        else
                         echo prmess("Pas de resultats trouv&eacute;s<br> \t<a href='index.php'>Accueil</a>");

			 //echo prmess("<br>Requete envoyer : $defaultQuery $condition proid = $idprovince ") ;
                }
        
         }
	inclusionPied() ;

?>
