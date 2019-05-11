<form  method='POST' action='imageupdate.php' enctype='multipart/form-data'>
                <input type=hidden name='MAX_FILE_SIZE' value="<?php echo getMaxFileSize() ; ?>"  >
	<table>
		<?php
			$texte = "Remplacer ";
			$nimage = $pho -> getImage($_GET['idimage']);
			if( ! empty($nimage) ){
				echo "<tr><td>Ancienne image : </td><td><img src='$rep/$nimage' width=100 height=100></td></tr>";
			}else{
				echo "Aucune image n'existais auparavant";
				$texte = "Charger l'image" ;
			}
		?>
		<tr><td>Chargez la nouvelle image ici</td><td><input type=file name="<?php echo 'im'.$_GET['idimage'] ; ?>"></td></tr>
		<input type=hidden name=oid value="<?php echo $_GET['oid'] ;?>">
		<input type=hidden name=nomtable value="<?php echo $_GET['nomtable'] ;?>">
		<input type=hidden name=idimage value="<?php echo $_GET['idimage'] ;?>">
		<tr><td align=center colspan=2><input type=submit value="<?php echo $texte; ?>" name='changeimage'></td></tr>
	</table>


</form>
