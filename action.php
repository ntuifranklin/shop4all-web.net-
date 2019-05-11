<?php
	include_once('includes/header.inc');
	inclusionTete() ;
        //Ce fichier attends deux parametres :
        // titreaction ==> titre de l'insertion
        // objtyp ==> type de l'insertion. Soit une offre
        $objtyp = $_GET['objtyp'] ;
        $titre = $_GET['titreaction'] ;
        
                        include_once("includes/choix.inc");
                      
	inclusionPied() ;
	
?>
