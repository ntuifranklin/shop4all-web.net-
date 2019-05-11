
<div align="left">
<table bgcolor="#b0c4de"  width=98% border="1" cellpadding="0" cellspacing="0" summary="">
<td>    <?php 
                
                        showWelcomeMessage();
                
        ?>
</td>
<?php
	$pasinsertion = true ;
	//Maintenant j'affiche le formulaire de recherche d'objets si on n'est pas entrain de vouloir effectuer une insertion
	$tabf = explode("/" , $_SERVER['SCRIPT_NAME']);//J'explose en tableaux le chemin absolue depuis le serveur vers le script en cours d'execution
	$fichEnCours = end($tabf);//Je recupere le nom du fichier php en cours d'execution
	if($fichEnCours == "insertion.php" || $fichEnCours == "formulaire.php" )
		$pasinsertion = false;
	if($pasinsertion){//Si on n'est pas entrain d'effectuer une insertion alors on affiche le formulaire de recherche d'objets
		echo '<td>';
		echo '<form action="research.php" method="post" name="ch" onSubmit=" return ck0();"> <!-- On précise le nom du formulaire ,sera utile coté serveur --> ' ;
		echo '<table>';	
		echo '<tr><td align=right> Recherche rapide <input type="Text" name="recherche">';
		echo '<td>Province : ' ;
			$pro = new Province() ;
			echo $pro -> getDropDownProvinces("proid") ; //A rappeler que dans le formulaire du doc principale , une liste de nom provid existe deja !

		 echo '</td>';
		 echo '<td>' ;
		 echo '<!--Rubrique <input type="Text" name="rubrique" -->' ;
		 $nom = "rubr"; $options = getT() ; $selected = 1 ;
		 echo "Rubrique ".dropdown2( $nom,  $options, $selected ) ;
		 echo '</tr>';
		 echo '<tr><td colspan=3 align=center><input id="imSButton" type="submit" value="Lancer recherche" name="r" ></tr>';
		 echo '</table>';
		 echo '</form>';
		 echo '</td>' ;
	}
    ?>     
 

</tr>
</table>
</div>
