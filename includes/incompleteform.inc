<?php
	        
      
       echo "<form action='inscription.php' method=post name='partinscrip' onSubmit=\" return ck4();\">";
	$obliger = "<font color=red size=2>*</font>"; $petitmessage = "( ".$obliger." ) => champs obligatoires";  
	$alaligne =" </td><td>";	
	$tr = "<tr><td align=right>" ;	

  
echo "<table>";
echo "$tr Votre Pseudonyme $alaligne <input type=text name='pseudo' value='".stripslashes($_POST['pseudo'])."'  size=20 >".
	     "$obliger</td></tr>";      
echo "$tr Votre email $alaligne <input type=text name='email' value='".stripslashes($_POST['email'])."'  size=20 >$obliger</td></tr>";          
echo "$tr Votre num&eacute;ro de telephone $alaligne <input type=text name='tel' value='".stripslashes($_POST['tel'])."'  size=20 >".
	     "$obliger </td></tr>";
	echo "<tr><td colspan=2 align=center>". $petitmessage . "</tr>";   
	echo "<tr><td colspan=2 align=center><p align=center><input type=submit value='Enregistrer' name='nonenreg'></p></tr>";      
echo "</table>";

      echo "</form>";
?>
