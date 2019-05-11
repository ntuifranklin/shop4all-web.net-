<?php
	        
      
       echo "<form action='contactWebMaster.php' method=post name='contactw' onSubmit=\" return ck8() ;\">";
	$obliger = "<font color=red size=2>*</font>"; $petitmessage = "( ".$obliger." ) => champs obligatoires";  
	$alaligne =" </td><td>";	
	$fontTitreDebut ="<u><H2>" ;
	$fontTitreFin = "</H2>" ;
	$tr = "<tr><td align=right>" ;	

  
	echo "<table>";

	echo "<caption> $fontTitreDebut Saisissez votre message et envoyez $fontTitreFin </caption>";

		echo "$tr Votre Pseudonyme $alaligne <input type=text name='pseudo' value='".stripslashes($_POST['pseudo'])."'  size=20 >".
		     "$obliger</td></tr>";      
		echo "$tr Votre email $alaligne <input type=text name='email' value='".stripslashes($_POST['email'])."'  size=20 >$obliger</td></tr>";          
		echo "$tr Votre num&eacute;ro de telephone $alaligne <input type=text name='tel' value='".stripslashes($_POST['tel'])."'  size=20 >".
		     "$obliger </td></tr>";
		echo "$tr Message $alaligne <textarea name='mess' value='".stripslashes($_POST['mess'])."'></textarea>$obliger</td></tr>"; 
		echo "<tr><td colspan=2 align=center>". $petitmessage . "</tr>";   
		echo "<tr><td colspan=2 align=center><p align=center><input type=submit value='Envoyer' name='contactweb'></p></tr>";      
	echo "</table>";

      echo "</form>";
?>
