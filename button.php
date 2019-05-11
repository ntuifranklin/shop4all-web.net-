<?php
		$_GET['text'] = "I works !!" ;
		header("Content-type: image/png") ;
		$string = $_GET['text'] ;
		$im     = imagecreatefrompng("images/button1.png") ;
		$orange = imagecolorallocate($im, 420, 510, 40);
		$px     = (imagesx($im) - 7.5 * strlen($string)) / 2 ;
		imagestring($im, 3, $px, 9, $string, $orange);
		imagepng($im);
		//imagedestroy($im);
?>
