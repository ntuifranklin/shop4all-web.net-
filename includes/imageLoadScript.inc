	<?php
	//$e = "nt=ObjArtTab&nr=8&oid=1";
	//$_GET['nt'] = "ObjArtTab"; $_GET['nr'] = 8; $_GET['oid'] = 1 ;
	if(!empty($_GET['nt']) && !empty($_GET['oid'])){
	$rep = getUserFileDir();//repertoire ou se trouve les images sauvegarder du user
	$obj = new $_GET['nt'](); $pho = new Photo();   $nomtable = $_GET['nt']; $objectid = $_GET['oid']; $imns = array();
	$nr = $_GET['nr'] ;
	$tableId = str_replace("Tab","",$nomtable)."Id" ;
	$imvar = $pho -> getAllImages($objectid,$nomtable); 
	$sources = array();
	//$imvar = array('4_1_3.gif','4_2_1.gif','4_2_2.gif','4_2_3.gif','4_2_4.gif');
	echo "<script language='javascript'>";
	$defvar  = "var srces = new Array(";
	$defvar .= "'".$pho -> getImage($imvar[0])."'";
	echo "var ims = new Array(); " ; 
	for($i=1 ; $i<count($imvar) ;$i++){
		$field = $imvar[$i] ;
		$nomimage = $pho -> getImage($field);
		$defvar .= " , '".$nomimage."'" ;
	}
	$defvar .= " ) ;";
	echo $defvar ;
	echo "
	for(i=0;i<srces.length ; i++){
		ims[i] = new Image();
		ims[i].src = '$rep/' + srces[i] ;
	}
	var ind = 0 ;
	function next(im){
		im = document.imag ;
		if( ind == srces.length - 1)
		 ind = 0 ;
		else
		 ind++ ;
		im.src = '$rep/' + srces[ind] ;
		//confirm('current image ' + '$rep/' + srces[ind]);
		informLength();//Informe s'il nya qu'une seule image a afficher 
	};

	function previous(im){
		im = document.imag ;
		if( ind == 0)
		 ind = srces.length - 1;
		else
		 ind-- ;
		im.src = '$rep/' + srces[ind] ;
		//confirm('current image ' + '$rep/' + srces[ind]);
		informLength();//Informe s'il nya qu'une seule image a afficher 
	};
	
	function informLength(){//Prompte le user si le nombre d'images n'est que 1
		if( srces.length == 1){
			confirm('Il existe une seule image pour cet objet');
		}
	}
	";
	echo "</script>";
	}
	?>

