<?php
	include_once('includes/header.inc');
        
	if(! sessionExists()){
                inclusionTete();
		//La session n'existe pas alors on affiche le formulaire de connexion
		//include_once("includes/connect.inc");
	}else{     
                inclusionUserMenu(); 
	}
                //On est deja connecter alors on affichera les insertions de ce User s'ils existe
                $nomtable = $_GET['nt']; $id = $_GET['oid'] ; $norubr = $_GET['nr'];
		if( ( !empty($nomtable) && !empty($norubr) && !empty($id) ) ){
			echo showUserInserts($nomtable, "select * from ".$nomtable." where ".str_replace("Tab","",$nomtable)."Id=$id", $norubr); 
		}elseif( !empty($nomtable) && !empty($norubr) ){
                	echo   showUserInserts($nomtable ,"select * from ".$nomtable." where RubriqueId=$norubr" , $norubr );
                }elseif(  !empty($nomtable) && !empty($id) ){
                	echo   showUserInserts($nomtable ,"select * from ".$nomtable." where ".str_replace("Tab","",$nomtable)."Id=$id" , $norubr );
                }else{
                	echo   showUserInserts($nomtable ,"select * from $nomtable" , 0 );
		}
               

	inclusionPied() ;

?>
