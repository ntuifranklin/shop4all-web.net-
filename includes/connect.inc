<?php
		$pageInscription = "inscription.php" ;
		$mdpinit = "resetpassword.php" ;
		
		echo "<fieldset>";
		echo "<legend>oui</legend>";
		echo "<form action='connect.php' method=POST name='con' onSubmit =\" return ck3();\">";
		echo "<table border=0>";
		echo "<caption>Identifiez vous ici</caption>";
		echo "<tr><td align=right>Identifiant(Pseudonyme) : </td>";
		echo "<td><input type=text name='uzer' size=20 value='".$_REQUEST['uzer']."'></td></tr>";
		echo "<tr><td align=right>Mot de passe : </td>";
		echo "<td><input type=password name='mdp' size=20></td></tr>";
		echo "<tr><td colspan=2 align=center><input type=submit name='conn' value=\"login\"></td></tr>";
		echo "</table>";
		echo "</form>";
		echo "</fieldset>";

		echo "<table >";
		echo "<tr><td>Vous n'&ecirc;tes pas encore inscrit ? </td>";
		echo "<td>Inscrivez vous <a href='$pageInscription'><img src='images/newuser.png' width=25 height=25></a></td></tr>";
		echo "<tr><td colspan=2 align=center>Mot de passe oubli&eacute;?  Re-initialisez le mot de passe <a href='$mdpinit'>ici</a></td></tr>";
		echo "</table>";
?>
