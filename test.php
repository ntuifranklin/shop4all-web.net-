<?php
	include_once('includes/header.inc');
	inclusionTete() ;

	echo "<form action=test.php method=post>"; 
		echo "<select name='s' onChange='(this.formt.disabled = true) ;  confirm(\"this.namet\")'>";
			for($i=0 ; $i<3 ; $i++)
			echo "<option value=$i>option $i";
		echo "</select>";
	echo "<input type=submit name=hello>";
	echo "</form>"; 

	var_dump($_SESSION);
	inclusionPied() ;
	
?>
