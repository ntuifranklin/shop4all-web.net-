<?php
	include_once('includes/header.inc');
	inclusionTete() ;
        
                //On est deja connecter alors on affichera les insertions de ce User s'ils existe
                $nomtable = $_GET['nt']; $np = $_GET['np'] ; $norubr = $_GET['nr']; $pagination = true ;
		if( !empty($nomtable) && !empty($norubr) && !empty($np) ){
			$nblignes = $nblignes = getNbVisualisedLines() ; 
			$borne = ($np - 1) * $nblignes ;
                	echo   showUserInserts($nomtable ,"select * from ".$nomtable." where RubriqueId=$norubr " , $norubr , $pagination , $borne);
			
                }else{
                	echo   showUserInserts($nomtable ,"select * from ".$nomtable , $norubr , $pagination , 0 );
                }
         
        
         
	inclusionPied() ;

?>
