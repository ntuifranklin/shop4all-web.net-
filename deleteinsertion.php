<?php
	include_once('includes/header.inc');
	inclusionTete() ;
        echo "Page de suppression d'insertion"; $nompage = "visualise.php";
        $nomtable = $_GET['nt'] ; $objectid = $_GET['oid'];//id de l'objet a modifier
        $query = "delete from ".$nomtable." where ".str_replace("Tab","",$nomtable)."Id = ".$objectid;
        $pho = new Photo(); 
        $pho -> setTableAppartenance($nomtable);
        $pho -> deleteAllImages($objectid);
        //Recuperons l'id de l'objet pour supprimer les images appartenant a cet objet
        if(!empty($nomtable) && ! empty($objectid))
        $res = execute($query);
        echo confmess("$res insertion(s) supprimer.\n <a href='".$nompage."?nt=$nomtable'>Visualiser cette rubrique</a>");
	inclusionPied() ;

?>
