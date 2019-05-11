<?php  session_start();//Lance la session automatiquement
	// unset($_SESSION); //Pour tester si,les sessions marche			
	error_reporting(E_ERROR | E_PARSE); // Seulement les erreurs importants seront reported, ceci desactive les warnings sur les wamps(xampp) de windows( et linux)
/*
	echo "script_name = {$_SERVER['SCRIPT_NAME']}<br>";
	echo "script_filename = {$_SERVER['SCRIPT_FILENAME']}<br>";
	echo "php_self = {$_SERVER['PHP_SELF']}<br>";
  
*/

     
include("includes/headerA.inc");   
include("includes/headerB.inc");
include("includes/recherche.inc");   
include("includes/headerC.inc");
?>

