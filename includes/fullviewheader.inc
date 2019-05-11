<?php  session_start();//Lance la session automatiquement
	// unset($_SESSION); //Pour tester si,les sessions marche			
	error_reporting(E_ERROR | E_PARSE); // Seulement les erreurs importants seront reported, ceci desactive les warnings sur les wamps(xampp) de windows( et linux)
     
include_once("includes/headerA.inc");  	
include_once("includes/imageLoadScript.inc");//Pour les images reloader dans le navigateur pour galerie photo
include_once("includes/headerB.inc");
include_once("includes/recherche.inc");   
include_once("includes/headerC.inc");
?>

