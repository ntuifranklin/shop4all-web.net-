<?php
	$_GET['tit'] = "Mes insertions";
	include_once('includes/header.inc');
	inclusionTete() ;
	if(! sessionExists()){
		//La session n'existe pas alors on affiche le formulaire de connexion
		include_once("includes/connect.inc");

	}else{ 
                
		//On est deja connecter alors on se redirige vers l'affichage de tous les insertions appartenant a ce user
		//$environUser = "includes/me.inc";
                //echo "On est connecter, Ici s'affichera l'environement du User";
		//include_once($environUser);


        if(sessionExists()){//Si le user est connecter alors s'il a des insertions , on affichera une , deux ou trois de ces insertions
                        $bool = false ;      
                        $tabs = getRubriqueTableAsArray() ;
                        $rubrs = getRubriquesAsArray();
                        $long = count($tabs) ;
                        $classes = array();  $u = new User() ;$u -> setPseudo(getUserName()); $u -> loadData(); $userid = $u -> getUserId();
                        //Affichage des liens vers ses insertions s'il y'en a et autre chose sinon
                        $lines = "";
                        for($i=1; $i<$long ; $i++){
                                $nomtable = $tabs[$i] ;
                                $query = "select *  from ".$nomtable." where UserId = ".$userid." and RubriqueId=$i order by Date_ins desc ";
                                $res = execute($query);
                                if(mysql_num_rows($res) > 0)
                                $lines .=  showUserInserts($nomtable , $query , $i);
                               
                         
                        }

                        //S'il l'utilisateur courant a des insertions alors on les affiches rubriques
                        if( ! ($lines == "")){//Si il existe au moins un objet inserer

                                //Page qui affiche un menu pour le user
                                echo "<table>";
                                echo "<caption><H3><FONT color=blue >Bienvenue dans votre environnement<br>"; 
                                echo "</FONT>Vos insertions <FONT color=blue > recentes";
                                echo "</FONT></H3></caption>";
                                echo "<tr>" ; 
                                //Premiere colonne , on affichera un menu dans un tableau, et la deuxieme colonne la liste de ses insertions
                                //remiere colonne : le tableau contenant une ou quelques deux
                                //S'il n'ya pas les insertions alors on affiche une ou  deux annonces
                                 echo "<td>";
                                 echo $lines ;                       
                                 echo "</td>";
                                 echo "</tr>";
                                 echo "</table>";
                        }else{
                                echo "<table>";
                                echo "<caption><H3><FONT color=blue >Vous n'avez pas d'insertion<br>"; 
                                echo "</FONT>Inserez  <a href='insertion.php'><FONT color=blue > ici";
                                echo "</FONT></a></H3></caption>";
                                echo "<tr>" ; 
                                echo "<td>";
                                echo "que souhaitez vous faire ?<br>" ; 
                                $menugauche = "";
                                $menugauche .=  "<table   width=100% border='1' cellpadding='1' cellspacing='' summary=''> ";
                                $navs = array("Vendre" => "Vente",
                                              "Acheter" => "Achat",
                                              "Mettre en location" => "Mise en location",
                                              "Louer" => "Recherche de Location") ;
                                $tab = array("Vendre" => 00,"Acheter" => 01,"Mettre en location" => 10,"Louer" => 11);
                                $tits = array("Vendre" => "Je veux Vendre un objet/des services",
                                              "Acheter" => "Je veux Acheter un objet(Voiture , tableau , une maison)",
                                              "Mettre en location" => "Je veux placer en location",
                                              "Louer" => "Je recherche pour louer");
                                foreach($navs as $field => $titreaction)
                                 $menugauche .=  "<tr class=\"navi\">".
                                      "<td align=center><a href='action.php?titreaction=".str_replace(" ","+",$titreaction).
                                      "&objtyp=".$tab[$field]."'><font color='blue'>".$tits[$field]."</font></a></td>".
                                      "</tr>";  
                                $menugauche .=  "</table>";   
                                echo $menugauche ; 
                                echo "</td>";
                                echo "</tr>";
                                echo "</table>";

                        }
        
                }

	}

	inclusionPied() ;

?>
