<?php
	$_GET['tit'] = "Ajout d'images &agrave; une insertion";
	include_once('includes/header.inc');
	inclusionTete() ;
	$pho = new Photo();$obj = new Object();
	$idimage = $_GET['idimage'];     $rep = getUserFileDir();
	if( ! $_POST['changeimage']){//On viens du formulaire de modification d'objet et pas du formulaire d'upload de fichier
			include_once("includes/uploadimage.inc");
	} else{
		$idimage = $_POST['idimage'] ;
		$nomtable = $_POST['nomtable'] ; $nomfichierClient = "im".$_POST['idimage']; $oid = $_POST['oid'] ;
		$resul = execute("select ".str_replace("Tab","_nom",$nomtable)." as t from $nomtable where ".str_replace("Tab","Id",$nomtable)."=$oid");
		$li = mysql_fetch_assoc($resul);
		$titreInsertion = $li['t'];
		if( !empty($idimage) && ! empty($oid) && ! empty($nomtable) && $_FILES[$nomfichierClient]['size'] > 0 ){
			 if(exif_imagetype($_FILES[$nomfichierClient]["tmp_name"]) > 0)//On à faire à une image
			 $pho -> updateImage($idimage ,$oid,$nomtable,$nomfichierClient) ; 
			else
			 $pho -> updateFile($idimage ,$oid,$nomtable,$nomfichierClient) ; 
			 $nr = $obj -> getNoRubrique($nomtable,$oid);
			  echo prmess("Mise &agrave; jour effectue&eacute;e. Nouvelle image cre&eacute;e<br>".
				"<a href='editinsertion.php?nt=$nomtable&oid=$oid&nr=$nr&tit=$titreInsertion'> ".
			"Revenir &agrave; ".
				" la page de modification</a>" ) ;
		}elseif( empty($idimage) && !empty($oid) && !empty($nomtable) && $_FILES[$nomfichierClient]['size'] > 0){
			 
			 $norubr = $obj -> getNoRubrique($nomtable,$oid);$retourVal = 0 ;
			 if(exif_imagetype($_FILES[$nomfichierClient]["tmp_name"]) > 0)
			   $pho -> createImage($norubr , $nomtable , $oid , $nomfichierClient);
			 else
			   $pho -> createFile($norubr , $nomtable , $oid , $nomfichierClient);
			 echo prmess("Mise &agrave; jour effectue&eacute;e. Nouvelle image cre&eacute;e<br>".
				"<a href='editinsertion.php?nt=$nomtable&oid=$oid&nr=$nr&tit=$titreInsertion'> ".
			"Revenir &agrave; ".
				" la page de modification</a>" ) ;

		}else{
		 echo prmess("Probl&egrave;me de chargement d'image, reessayez avec une image plus l&eacute;g&egrave;re , ou d'une extension valide");
		}
		
	}
	inclusionPied() ;

?>
