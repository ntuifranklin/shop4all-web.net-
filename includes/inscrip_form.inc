<?php
	        
	      
	       echo "<form action='inscription.php' method=post>";
			$obliger = "<font color=red size=5>*</font>"; $petitmessage = "( ".$obliger." ) => champs obligatoires";  
			$alaligne =" : <br>";	
                     echo "<fieldset  class='petit' >";
                        echo "<legend style='font-family:verdana; font-size:8; font-weight:700;'>";
                        echo "Utilisateur ".getUserName()."</legend>";
                        echo "Votre Nom $alaligne <input type=text name='nom' value='".stripslashes($_POST['nom'])."' size=20 ><br>";    
                        echo "Votre Prenom $alaligne <input type=text name='prenom' value='".stripslashes($_POST['prenom'])."'  size=20 ><br>";  
                        echo "Votre Mot de passe $alaligne <input type=password name='mdp1' value='".stripslashes($_POST['mdp1'])."'  size=20 ><br>";   
                        echo "Confirmation du Mot de passe $alaligne <input type=password name='mdp2' value='".stripslashes($_POST['mdp2'])."'  size=20 ><br>";    
                        echo "Votre Pseudonyme $alaligne <input type=text name='pseudo' value='".stripslashes($_POST['pseudo'])."'  size=20 >".
			     "$obliger<br>";      
                        echo "Votre email $alaligne <input type=text name='email' value='".stripslashes($_POST['email'])."'  size=20 >$obliger<br>";        
                        echo "Votre ville d'habitat $alaligne <input type=text name='ville' value='".stripslashes($_POST['ville'])."'  size=20 >".
			     "<br>";   
                        echo "Votre num&eacute;ro de telephone $alaligne <input type=text name='tel' value='".stripslashes($_POST['tel'])."'  size=20 >".
			     "$obliger<br>";     
                        echo "Voulez vous recevoir les annonces dans votre boite email ? $alaligne Oui je suis d'accord<input type=radio name='nletter' value='1' checked>"; 
			echo "<br> Non je ne suis pas interess&eacute;<input type=radio name='nletter' value='0' >".
			     "<br>";   
			echo $petitmessage;
    			echo "<p align=center><input type=submit value='Enregistrer' name='enreg'></p>";
                    echo "</fieldset>";
		echo "</form>";
?>
