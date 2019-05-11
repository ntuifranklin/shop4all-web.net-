<?php

		$vi = new Ville() ;$vid=$u -> getVilleId();
		$valeurBouton = "Completer l'inscription" ;
	       	
	       	$data   .= "<form action='complete.php' method=post name=\"compl\" onSubmit=\" return ck5();\">";
			$nouvColonne="  </td><td> ";		$taille = "size=30";
                     $data .= "<table><caption>Mes informations personnels</cation>";   
                    // $data   .= "<fieldset  class='petit' >";
                        //$data   .= "<legend style='font-family:verdana; font-size:8; font-weight:700;'>";
                      //  $data   .= "Vos informations personnelles</legend>";
                        $data   .= "<tr><td align=right>Votre Nom $nouvColonne <input type=text name='User_nom' value='".stripslashes($u -> getNom())."' $taille></td></tr>";    
                        $data   .= "<tr><td align=right>Votre Prenom $nouvColonne <input type=text name='User_prenom' value='".stripslashes($u -> getPrenom())."' $taille></td></tr>";  
                        //$data   .= "<tr><td align=center>Votre Ancien Mot de passe $nouvColonne <input type=password name='User_pw' value='' $taille></td></tr>";   
                        $data   .= "<tr><td align=right>Votre Mot de passe $nouvColonne <input type=password name='User_pw1' value='' $taille ></td></tr>";   
                        $data   .= "<tr><td align=right>Confirmation du Nouveau Mot de passe $nouvColonne <input type=password name='User_pw2' value='' $taille></td></tr>";    
                        $data   .= "<tr><td align=right>Votre Pseudonyme  $nouvColonne <input type=text name='User_pseudo' value='".stripslashes($u -> getPseudo())."' $taille>".
			     "</td></tr>";      
                        $data   .= "<tr><td align=right>Votre Email  $nouvColonne <input type=text name='User_email' value='".stripslashes($u -> getEmail())."' $taille></td></tr>";        
                        $data   .= "<tr><td align=right>Votre Ville d'habitat  $nouvColonne ". 
				   $vi -> getDropDownVilles("villeid" , $vid) .
			     "</td></tr>";   
                        $data   .= "<tr><td align=right>Votre num&eacute;ro de telephone  $nouvColonne <input type=text name='User_tel' value='".stripslashes($u -> getTel())."' $taille>" ;   
			
    			$data   .= "<tr><td align=center colspan=2><input type=submit value=\"$valeurBouton\" name='completer'></td></tr>";
                     $data .= "</table>"; 
		$data   .= "</form>";
			echo $data ;

?>
