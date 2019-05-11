<?php
//header ("Content-type: image/gif");
$pourcentx = 7/150 ; $pourcenty = 10/150 ; $taix = 20 ; $taiy = $taix - (int)($taix / 5) ;
$im = @imagecreate ($taix,$taiy )
	or die("Impossible de creer l'image");
$background_color = imagecolorallocate ($im, 512, 24, 1050);
$text_color = imagecolorallocate ($im, 333, 114,191) ;
imagestring ($im, 5,(int)($pourcentx *$taix), (int)($pourcenty * $taiy), " S " , $text_color);
imagegif ($im , "/opt/lampp/htdocs/image.gif") ;		
?>
