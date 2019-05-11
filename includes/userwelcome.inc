<?php

if(sessionExists()){//Si le user est connecter alors s'il a des insertions , on affichera une , deux ou trois de ces insertions
        //Page qui affiche un menu pour le user
     
                        $bool = false ;      
                        $tabs = getRubriqueTableAsArray() ;
                        $rubrs = getRubriquesAsArray();
                        $long = count($tabs) ;
                        $classes = array();  $u = new User() ;$u -> setPseudo(getUserName()); $u -> loadData(); $userid = $u -> getUserId();
                        //Affichage des liens vers ses insertions s'il y'en a et autre chose sinon
                        $lines = "";
                        for($i=1; $i<$long ; $i++){
                                $nomtable = $tabs[$i] ;
                                //Requete pour l'affichage des deux dernieres insertions pour ce user
                                $query = "select *  from ".$nomtable." where UserId = ".$userid." and RubriqueId=$i ".
                                "order by Date_ins desc limit 0 , 4";
                                $res = execute($query);
                                if(mysql_num_rows($res) > 0)
                                $lines .= "<hr>". showUserInserts($nomtable , $query , $i);//Affiche 2 dernieres insertions par table
                               
                         
                        }
                        if( ! empty($lines)){//Si il existe au moins un objet inserer

                        echo "<font color=gray>Vos insertions les plus recentes</font>".$lines ;
                        }else{
                                echo "<div>Vous n'avez pas d'insertions<a href='insertion.php'>.<br> Inserez ici</a></div>";

                        }
}
?>
