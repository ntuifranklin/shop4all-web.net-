<?php
	include_once('includes/header.inc');
	inclusionTete() ;

        //Pour effectuer des modifications partielles
        $query = "";
        $arr = file("sql/modif.sql") ;
        foreach($arr as $field)
        $query .= $field ;
        $queries = explode(";", $query) ; $i = 0 ;
        foreach($queries as $requete)
        if(!empty($requete)){
                $i++ ;
                if( $requete != "\n"){
                       // echo "<p>Requete no $i = ".$requete."<br>";
                        $res = execute($requete);
                       echo prmess ("Requete no $i = executer avec succes<br></p>");
                }else{
                        echo "La requete etait vide";
                }
        }


	inclusionPied() ;

?>
