
﻿<HTML>
<BODY>
<center><h3>Réduire le poids d'une image</h3></center>
<form method="post" enctype="multipart/form-data" action="<?php echo $_SERVER['SCRIPT_NAME'] ;?>?ordre=ajouter">
<input name='fichier' type='file' size='20' style="font-size:9pt; color:#FFFFFF ; background-color: #000000">
<input type="text" value="Miniutariser par magie du PHP">
<input type="submit" value="charger" >
</form>
</BODY>
</HTML>

<?php	
        function getPrefixeFichier($nomfichier){//Retourne l'avant extension du nom d'un fichier
	 $arr = explode('.',$nomfichier);
		 $prefixe = "";$tai = count($arr);
		for($k=0 ; $k<($tai - 1);$k++){
			$prefixe .= $arr[$k];
			
		}
             
                 return  $prefixe;

        }

        function getExtension($nomfichier){
	 $arr = explode('.',$nomfichier);
                 $extfichier =  strtolower( end($arr));//Retourne l'extension du fichier
                 return  $extfichier ;

        }

if($_GET['ordre']=='ajouter')
{
$nomfichier = "fichier" ;
$ext = getExtension($_FILES[$nomfichier]["name"]);
$folder = '/home/thadee/c/'; $nomFinal = $_FILES['fichier']['name'];
$size = getImageSize($_FILES[$nomfichier]["tmp_name"]);
if($size[2] != 2)
	$creer = createGifAndPng($nomfichier , $folder , $nomFinal);
else
	$creer = createJpeg($nomfichier , $folder , $nomFinal) ;
echo ($creer == true ) ? "image creer"  : "image non creer" ;
} 


        /**
	 * 
	 * @Retourne boolean si l'image pris en parametre est un jpeg ou jpg et la reduit pour sauvegarder en gif
	 *
	 * @param string $nomfichier , le nom du fichier dans input type=file, $folder le repertoire de sauvegarde , $nomfinal le nom final de ce fichier
	 *
	 * @retourne boolean
	 *
	 */
	function createJpeg($nomfichier , $folder , $nomFinal){//fonction qui prends en parametre un fichier jpeg temporaire et reduit considerablement sa taille
	
		$ext = getExtension($_FILES[$nomfichier]["name"]);
		$my_img = $_FILES[$nomfichier]["tmp_name"];
		$pref = getPrefixeFichier($nomFinal);
		$nomFinal = $pref ;
		$size = GetImageSize($my_img);

		if(is_dir($folder)){//Si le repertoire passer en parametre est valide
				
			switch ($size[2]) {//On determine les types de l'image charger
				case 2:
				$src_im = @imagecreatefromjpeg($my_img);
				$src_w = $size[0];
				$src_h = $size[1];
				$dst_w = 629;//Taille maximum souhaiter
				$dst_h = round(($dst_w / $src_w) * $src_h);
				$dst_im = @imagecreatetruecolor($dst_w,$dst_h);
				if(!imagecopyresampled($dst_im,$src_im,0,0,0,0,$dst_w,$dst_h,$src_w,$src_h)) return false;
				if(imagegif($dst_im, $folder."/".$nomFinal.".gif")){
					imagedestroy($dst_im);
					return true ;
				}
				break;
			}
			return false ;
			//Destruction de l'image temporaire en tampon pour liberer la memoire
		}else{
			//echo "Ce repertoire de sauvegarde d'image n'existe pas";
			return false;
		}

	}

        /**
	 * 
	 * @Retourne boolean si l'image pris en parametre est un gif ou png et la reduit pour sauvegarder en gif
	 *
	 * @param string $nomfichier , le nom du fichier dans input type=file, $folder le repertoire de sauvegarde , $nomfinal le nom final de ce fichier
	 *
	 * @retourne boolean
	 *
	 */
	function createGifAndPng($nomfichier , $folder , $nomFinal){//fonction qui prends en parametre un fichier temporaire qui n'est pas un jpeg et reduit considerablement sa taille
	
		$ext = getExtension($_FILES[$nomfichier]["name"]);
		$my_img = $_FILES[$nomfichier]["tmp_name"];
		$size = getImageSize($my_img);
		$pref = getPrefixeFichier($nomFinal);
		$nomFinal = $pref ;
	
		if(is_dir($folder)){//Si le repertoire passer en parametre est valide
			switch ($size[2]) {//On determine les types de l'image charger
				case 1: //un fichier gif
				$src_im = @imagecreatefromgif($my_img);
				break ;
				case 3: //un fichier png
				$src_im = @imagecreatefrompng($my_img);
				break;
			}	
			//Calcule dynamique de la taille
			$prcent = 103.0000 ;
			if( $size[0]*$size[1]< 25000000 && $size[0]*$size[1] >= 15000000 ){
				$prcent=99.9999 ;//1
			}
			if($size[0]*$size[1]<15000000 && $size[0]*$size[1]>= 5000000){
				$prcent=99.000 ;//2
			}
			if($size[0]*$size[1]<5000000 && $size[0]*$size[1]>= 1000000){
				$prcent=98.9999 ;//5
			}
			if($size[0]*$size[1]<1000000 && $size[0]*$size[1]>= 500000){
				$prcent=98.000 ;//10
			}
			if($size[0]*$size[1]<500000 && $size[0]*$size[1]>= 100000){
				$prcent=97.999 ;//10
			}
			if($size[0]*$size[1]<100000 && $size[0]*$size[1]>= 50000){
				$prcent=97.00 ;//20
			}

			$largeMax = $size[0];
			$hauteMax = $size[1];
			$hauteurVignette = (1.0 * $hauteMax*($prcent*1.0))/(100.0 );
			$largeurVignette = (1.0 * $largeMax*($prcent*1.0))/(100.0 );
			echo "pour centage = $prcent largeur = $largeurVignette, hauteur = $hauteurVignette<br>large initiale = $largeMax, haute initiale = $hauteMax" ;	


			if($size[2] != 1 ){//Si l'image  n'est pas un gif
				$dst_im = imagecreatetruecolor($largeurVignette, $hauteurVignette) ;
			}else{//c'est un gif. donc on cree une image vide
				$dst_im = imagecreate($largeurVignette, $hauteurVignette);
			}		
		
			if(!imagecopyresized($dst_im, $src_im, 0, 0, 0, 0 ,$largeurVignette, $hauteurVignette, $largeMax, $hauteMax)){
				return false;
			}

			if(imagegif($dst_im, $folder."/".$nomFinal.".gif")){
				imagedestroy($dst_im);
				return true ;
			}			//Destruction de l'image temporaire en tampon pour liberer la memoire
		
		}else{
			//echo "Ce repertoire de sauvegarde n'existe pas";
			return false ;
		}

	}

?>
