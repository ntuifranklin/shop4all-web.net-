<?php
	//echo "saveFromsession<br>" ;
	
	if( objetEnAttente()){
	//echo "Un objet est en attente<br>" ;
	$nomtable = getTabNameFromSess();//Retourne le nom de la table sauvegarder dans la session
	//echo "Nom de la table {$_SESSION["nomtable"]}<br>" ;
		if(! empty($nomtable)){
			$norubr = $_SESSION['norubr']; $tab = getRubriquesAsArray();
			$obj = new $nomtable();$obj -> setRubriqueId($_SESSION['norubr']); $obj -> setLieu($_SESSION["villeid"]) ;
			$obj -> placerChampsTab($_SESSION);
			$obj -> creer();
			$oid = $obj -> getId();
			$o = new Object();
			$norubr = $o -> getNoRubrique($nomtable , $oid);
			if( $oid > 0)
			echo confmess("Insertion confirmer avec succes\n ".
			"<a href='visualise.php?nt=$nomtable&oid=$oid&nr=$norubr'>Visualiser cette insertion</a>");
		}
	}
	/*
	$user = new User();
	if(!empty($_SESSION['uzer']) || !empty($_GET['actionnumber']) ){
	//Soit on viens d'un mail de confirmation ou alors on a 
	// inserer puis on s'est connecter pour justifier cette insertion
		$nomtableTemp = $_SESSION['nttemp'] ; //Nom de la table temporaire
		$arrt  = explode("_" , $_SESSION['nttemp']);
		$nomtable = $arrt[0];
		$objet = new $nomtable();
		$champId = str_replace("Tab","Id",$nomtable);	
		if(!empty($_SESSION['uzer'])){
			$ps = $_SESSION['uzer'];
			$u -> setPseudo($ps);
			$u -> loadData();
			$userid = $u -> getUserId();
		}else{
			$userid = $_GET['actionnumber'];
		}
		
		$temporalId = $_SESSION['oid'];//Id de l'objet en table temporaire
		//On va recuperer ce qui avait été sauvegarder dans la table temporaire pour la mettre en lieu sure dans une table permanente
		$q = "select * from $nomtableTemp where $champId = $temporalId";
		$res = execute($q);
		while($l = mysql_fetch_assoc($res)){
			$objet -> placerChampsTab($l);
			$objet -> creer($nomtable);//Creation effective de l'objet dans la table permanente
			echo prmess("Insertion confirm&eacute; ");
			//Suppression de l'objet dans la table temporaire
			$qu = " delete from $nomtableTemp where $champId=$temporalId";
			$resul = execute($qu);

		}

	}	
	*/



?>

