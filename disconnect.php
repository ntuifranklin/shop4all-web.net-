<?php
    session_start();// unset($_SESSION); //Pour tester si,les sessions marche			
	error_reporting(E_ERROR | E_PARSE); // Seulement les erreurs importants seront reported, ceci desactive les warnings sur les wamps(xampp) de windows( et linux)
    $_GET['tit'] = "Vous n'etes plus connect&eacute; &agrave; {$_SERVER['SERVER_NAME']}";;
    $pseudo = $_SESSION['uzer'] ;
    $_SESSION = array();//On vide la session , ensuite on appelle les pages d'entete
    include_once('includes/header.inc');    
        
	inclusionTete() ;
        $u = new User();
        $u -> setPseudo($pseudo);
        $u -> loadData();
        $u -> disconnect();
        echo "Vous &ecirc;tes d&eacute;connect&eacute;.<br>";
        echo "<a href='index.php'>Acceuil.</a><br>";
        echo "<a href='connect.php'>Se connect&eacute;.</a>";
	inclusionPied() ;
?>
