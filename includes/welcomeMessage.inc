<?php
                if(sessionExists()){
                        $us = new User();
                        $us -> setPseudo(getUserName());
                        $us -> loadData();
                        $email = $us -> getEmail();
                        $nom = $us -> getNom();
                        $prenom = $us -> getPrenom();
                        $pseudo = $us -> getPseudo();
                        $inscrit = $us -> getInscrit();
                        $tel = $us -> getTel();
                        $email = $us -> getEmail(); $pseudo = $us -> getPseudo();
                        echo "Bienvenue  <font color=green>".$pseudo."</font> ";
                        echo "  <br><a href='disconnect.php'>Deconnexion<img src=\"images/disconnect.png\" width=25 height=25></a>";
                }else{
                        echo "<font color=green><a href='connect.php'>Se connecter </a></font> ";
			//On comptera le nombre de personnes connecter au site et on l'affiche

                }
		
			$nbResultats = countConnect() ;
			if($nbResultats > 0)
				echo " <br><font color=blue>$nbResultats</font> actuellement connect&eacute;(s)" ;
		
		
?>



