<?php
	$_GET['tit'] = "Nouvelle insertion";
	include_once('includes/nosearch.inc');//Inclusion de fichier entete sans module de recherche
        include_once('includes/navigauche.inc');
                if(empty($_REQUEST['typetyp']) || !isset($_REQUEST['typetyp'])){ //On ne viens pas du formulaire de choix de ObjType
                       /*
                        echo "Choisissez la rubrique dans laquelle vous souhaiter inserer:<br>";
	                $t = getT();//Rubriques et indicies des tables mysql correspondante
                        $longeur = count($t);
                        $k = 0 ;
                        foreach($t as $field => $value){
                        //On affiche la liste des rubriques et le User cliquera sur celui 
                        //dans la quelle il voudra effectuer l'insertion
                                $k++ ;
                                if($k != 1)
                                echo "<a href='formulaire.php?typetab=$value&amp;titreRub=$field'>$field</a><br>";
                        }
                        */
                        include_once("includes/choix.inc");

	        }


	inclusionPied() ;
	
?>
