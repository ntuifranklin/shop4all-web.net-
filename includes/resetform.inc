<?php
		
		$mdpinit = "resetpassword.php" ;
		
		
		echo "<form action='$mdpinit' method=POST >";
		echo "<table border=0>";
		echo "<caption>Re - initialisation du mot de passe</caption>";
		echo "<tr><td>Email : </td>";
		echo "<td><input type=text name='em' size=20 value='".$_POST['em']."'></td></tr>";
		echo "<tr><td colspan=2 align=center><input type=submit name='reinitpassword' value=\"Re-initialiser le mot de passe\"></td></tr>";
		echo "</table>";
		echo "</form>";

?>
