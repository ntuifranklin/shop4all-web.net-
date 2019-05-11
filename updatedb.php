<?php
	include_once('includes/header.inc');
	inclusionTete() ;

        //Creation des tables pour insertions permanentes
        $query = "";
        $arr = file("sql/rubriquesTables.sql") ;
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

	////Creation des tables pour insertions temporaires
        $query = "";
        $arr = file("sql/rubriquesTablesTemp.sql") ;
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

	//Creation des provinces
        $query = "";
        $arr = file("sql/provincesAndRubriques.sql") ;
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


	//Creation des autres tables
        $query = "";
        $arr = file("sql/autresTable.sql") ;
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
