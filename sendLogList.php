<?php
	error_reporting(E_ERROR | E_PARSE);
	include_once('includes/LesFontions.inc');
	inclusionClasses();
	inclusionTete();
		$q = "select macaddr from log ";
		$r = execute($q);
		$list = "";
		$log = new Log() ;
		$email ="ntuifranklin_2005@yahoo.fr" ;  $nomperson = "Franklin Nkokam Ngongang"; 
		$date = date("Y-m-d") ;
		while($l = mysql_fetch_assoc($r)){
		$ipaddr = $l["macaddr"] ;
		$d = array() ;
		//keepLog();	
		
		$list .= $log -> getLogList($ipaddr , $date) ;
		//sendmeil($email , $body , $nomperson , $title = "")
		/*
		$title = "*---- Liste des visiteurs sur {$_SERVER["SERVER_NAME"]} pour la date du $date ----*";
		$titre = "\n";
		for($i=0;$i<strlen($title);$i++)
		$titre .= "*";
		$titre .= "\n";
		$t = $titre ; $t .= $title ; $t .= $titre ;
		$li = $list ;
		$list = $t;
		$list .= $li ; 
		*/
		}
		$body = texttoweb($list) ;
/*
		if (sendmeil($email , $body , $nomperson , "Liste des visites pour la date du $date") )
			echo "Mail envoyer &agrave; $email";
		else
			echo "Mail non envoye";
*/
		//echo $list ;
		$f = fopen("loglist.txt" , "w+");
		fwrite($f , $list);
		fclose($f);
	inclusionPied();
?>
