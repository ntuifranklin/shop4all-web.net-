<?php
	$_GET['tit'] = "Formulaire d'insertion";
	session_start();//Lance la session automatiquement
	// unset($_SESSION); //Pour tester si,les sessions marche			
	error_reporting(E_ERROR | E_PARSE); // Seulement les erreurs importants seront reported, ceci desactive les warnings sur les wamps(xampp) de windows( et linux)
	     
	include_once("includes/headerA.inc");  	
	include_once("includes/insertFormVerifScript.inc");//Pour la fonction javascript de verification de formulaire 'insertion dcharger dynamiquement
	include_once("includes/headerB.inc");
	include_once("includes/recherche.inc");   
	include_once("includes/headerC.inc");
        include_once("includes/navigauche.inc");
     
        if(! empty($_POST['norubr']) && $_POST['provid'] > 0 ){//On a deja chois le type de ObjTyp alors on presentera le formulaire en fonction de la rubrique choisi
                // echo $_POST['typetab'];
                $class = getRubriqueTableAsArray();//La liste des rubriquesTab mysql ex : ElectroTab , AutoTab , ...
                $rubr = new $class[$_POST['norubr']]();//Creation d'une classe correspondant a la rubrique choisi
                $objtyp = $_POST['objtyp'] ; $provid = $_POST['provid'] ;
                $titre = $_POST['titreRub']; $actionFile = "treatinsertion.php"; $nom = $class[$_POST['norubr']] ;
                
		//Affiche un formulaire pour  l'enregistrement d'un objet 
                echo getForm($titre , $actionFile , $nom , $rubr -> getAttribAsArray(), $_POST['norubr'] , $objtyp) ;
               
        }else{
		echo prmess("Aucune rubrique choisi / Pas de province choisi");
		include_once("includes/choix.inc");
	}
	inclusionPied() ;
	
?>
