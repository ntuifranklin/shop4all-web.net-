<?php
	include_once('includes/header.inc');
	inclusionTete() ;
	echo "<font color=blue size=3>Cette aide vous permettra de pouvoir utiliser le site sans souci</font>";
	echo "<br>Les operations suivantes sont disponible sur ce site : ";
		
		echo "<ul>";
		echo "<li title=\"L'insertion peut &ecirc;tre une vente , une location , un offre d'emploi ...\"><a href='insertion.php'>L'insertion d'un objet</a></li>";
		echo "<li>La <a href='index.php'>visualisation</a> de l'objet inser&eacute; </li>";
		echo "<li>La modification de l'objet inser&eacute; </li>";
		echo "<li>La suppression de l'objet inser&eacute; </li>";
		echo "<li><a href='inscription.php'>L'inscription</a> sur le site</li>";
		echo "<li>La <a href='connect.php'>connexion</a> et la <a href='disconnect.php'>deconnexion</a> sur le site</li>";
		echo "</ul>";
		
		echo "<p>";
		echo "<font color=green size=2><u>Comment inserer un objet</u><br></font>";
		echo "Un objet ici c'est toute chose utile qui peut &ecirc;tre vendu ou louer. Un objet appartient &agrave; une rubrique precise. <br>"; 
		echo "Les rubriques disponobles sont : <br>";
		$t = getRubriquesAsArray(); $max = count($t);
		echo "<ul>";
		for($i=1;$i<$max ; $i++){
			echo  "<li><font color=blue>".$t[$i]."</font> </li>" ;
		}
		echo "</ul>";
		echo "En cliquant sur ".getLink("insertion.php","insertion")." sur le menu en dessous de la baniere haute de la page<br>";
		echo "ou sur ".getLink("insertion.php?titreaction=Vente&objtyp=0","Vendre").", <br>".
		getLink("insertion.php?titreaction=Achat&objtyp=1","Acheter")." , <br>".
		getLink("insertion.php?titreaction=location&objtyp=10","Mettre en location").",<br> ".
		getLink("insertion.php?titreaction=Recherche+de+location&objtyp=11","louer")." sur le menu de navigation gauche de la page ,<br>";
		echo "une page se presente pour vous permetre de choisir la rubrique auquel l'insertion appartient <br>";
		echo "Apr&egrave;s le choix de la rubrique auquel appartiendra l'insertion , il faudra remplir le formulaire correspondant &agrave; la rubrique choisi.<br>";
		echo "Si le formulaire est valide alors l'objet sera sauvagard&eacute; de fa&ccedil;on permanente si on est connect&acute;(donc inscrit) , ou temporairement si on n'est pas connect&eacute;<br>";
		echo "En g&eacute;n&eacute;rale, si on n'est pas inscrit sur le site , notre insertion ne sera pas sauvegard&eacute; definitivement.";
		echo "&Agrave; noter que lorsqu'on effectu une insertion en mode invit&eacute;(sans s'identifier), la dure&eacute; de vie de l'insertion n'est valable que pour la session courante. De plus il n'est pas possible d'effectuer une insertion avec des images sans &ecirc;tre connect&eacute;<br>";
		echo "Lorsque vous(pour un user non inscrit) reviendrez sur le site , vous pouriez visualiser votre objet , mais pas la modifier , ou la supprimer";
		echo "</p>";

		echo "<p>";
		echo "Les insertions faites par un utilisateur inscrit sont visible dans le menu ".getLink("mon_shop.php?tit=Mon+Shop","Mon shop")."<br>";
		echo "Un user non connecter ne peut uploader des images de son insertion vers le serveur. <br> ".
		"Mais &eacute;tant connecter , il peut modifier ses insertions en ajoutant des images &agrave; son insertion<br>";
		echo "Les op&eacute;rations de modification et de suppression d'objets ne sont accessibles que si les conditions suivantes sont remplies: <br>";
		echo "<ol>";
		echo "<li> Vous &ecirc;tes <a href='connect.php'>connect&eacute;</a> et que </li>";
		echo "<li>L'objet en cours de visualisation vous appartienne </li>";
		echo "</ol>";
		echo "Lors de la visualisation d'un(des) objet(s) suite &agrave; une recherche(demande de visualisation) d'objets , les boutons de modification et de suppression sont accessibles si la ligne en vue vous apartient";
		
		echo "</p>";
	
	
	inclusionPied() ;

?>
