<?php
	$titreTemp = $_GET['tit'];
	$_GET['tit'] = "Modification de l'insertion \"".$titreTemp."\"";
	$_GET['ancientit'] = $titreTemp;
	include_once('includes/header.inc');
	inclusionTete() ;
	$o = new Object();
       $ville = new Ville(); 
       // echo $_GET['nt']. "   ". $_GET['nr'] . "   ". "   ".$_GET['oid'] ;
        if( !empty($_GET['nt']) ){//Si on ne viens pas du formulaire de modification 
                $nomtable = $_GET['nt'] ; $nom = "modifobjet"; $objectid = $_GET['oid'];//id de l'objet a modifier
                $cl = new $nomtable(); $titre = str_replace("Tab","",$nomtable); $actionFile = "editinsertion.php";
                $tabValeurs = $cl -> getAttribAsArray(); $norubr = $_GET['nr'];
                
                       
                if(!empty($nomtable)){
                        $query = "select * from ".$nomtable." where 1 " ;
                        
                        $condition  = (! empty($objectid) ) ?   " and ".str_replace("Tab","",$nomtable)."Id=".$objectid : "";
                       // $condition .= (!empty($norubr) && !empty($condition) ) ? " and RubriqueId=".$norubr : "";
                        $res = execute($query.$condition);  // echo confmess($query.$condition);
			//$r = execute('select RubriqueId from '.$nomtable.' where '.str_replace('tab','',$nomtable).'Id='.$objectid);
                        if(mysql_num_rows($res) >= 1){
                                while($l = mysql_fetch_assoc($res)){ 
					$villeid = $l['VilleId'] ; //Je recupere l'id de la ville de cet objet
					$_GET['VilleId'] = $villeid ;
                                        echo getModifyForm($actionFile , $nom , $nomtable ,$tabValeurs,$l, $objectid) ; 
                                }
                        }
                }

        }



         if($_POST['modifobjet'] && !empty($_POST['nomtable'])){//Si on viens du formulaire de modification 
                $nomt = $_POST['nomtable'] ; $objectid = $_POST['oid'];
              //  echo "Nom table $nomt , ObjectId = $objectid";
                $obj = new $nomt();  $nomtable = $nomt ;
                //Traitement du formulaire
                        $attribs = array(); $class = array(); $taille = array(); $nulls = array(); $types = array();
                        $errmess = ""; 
                        $attribs = $obj -> getAttribAsArray() ;
                        $class = getRubriqueTableAsArray() ;
                        $taille = $obj -> getTableTailles();
                        $nulls = $obj -> getTableNulls(); //Indices des attributs qui peuvent etre nulle
                        $types = $obj -> getTableTypes(); //Tableau des types attendus. 1 ==> String , 0 ==> numeric
                        $long = count($attribs); $i= -1 ;
                        foreach($attribs as $field => $value){
                                $i++ ;
                                
                                if($nulls[$i] == 0){//==> que cet attribut ne doit pas etre vide
                                      $errmess .=  (empty($_POST[$value]) || strlen(addslashes($_POST[$value])) > $taille[$i] ) ?
                                         "Le champ ".$field." est soit vide/Trop long<br>" : "" ;
     
                                }

                                if($types[$i] == 0){//==> que cet attribut ne doit pas etre different d'un numeric
                                      $errmess .=  (! is_numeric($_POST[$value])  ) ?
                                         "Le champ ".$field." n'est pas numerique<br>" : "" ;
        
                                }
                        }

                       
                        if( ! empty($errmess)){ //S'il ya des erreurs alors on reaffiche le formulaire et on libere le plancher
                             echo errmess($errmess)  ; 
                            
                             $res = execute("select * from ".$nomtable." where ".str_replace("Tab","",$nomtable)."Id=".$_POST['oid']) ;
                                    
                             $l = mysql_fetch_assoc($res);
                             $actionFile = "editinsertion.php"; $nom = "modifobjet";
                             echo getModifyForm( $actionFile , $nom , $nomtable ,$attribs, $l , $_POST['oid']); //Reaffichage du formulaire 
                               // echo "Ici 2";
                        }else{
                             //Le formulaire est valide alors on modifie
                                //$obj -> placerChampsTab($_POST);
                                $nbchampsAjour = 0 ; $i = -1 ; $res = 0;
                                foreach($attribs as $field => $value){//Ces attributs ne contiennent pas la ville de l'objet , donc il faudra la mettre à jour serparament
					$i++ ;//Pour parcourir le tableau des attributs                                        
                                                        
                                        //$haystack = $value ; $needle = "_lieu";//Pour le choix des types de champs , input ou textarea
                                        //$pos = strpos($haystack,$needle);

                                        if($types[$i] == 0){//==> que cet attribut ne doit pas etre different d'un numeric
                                                $valeur = $_POST[$value] ;
                                        	$query = "update ".$nomtable." set ".$value." = ".$valeur." where ".str_replace("Tab","",$nomtable).
                                                 "Id = ".$_POST['oid'];
					
                                        }else{
                                               // $valeur = "'".$_POST[$value]."'" ;
                                        	$query = "update ".$nomtable." set ".$value."=\"".webtotext($_POST[$value])."\" where ".str_replace("Tab","",$nomtable).
                                                 "Id = ".$_POST['oid'];
					
                                        }
                                        //Avant la mise à jour il faut verifier que la valeur à modifier est différente de l'ancienne valeur
					$q = "select $value from $nomtable where ".str_replace("Tab","",$nomtable)."Id=".$_POST['oid'];
					$r = execute($q);
					$lig = mysql_fetch_assoc($r);
					//$ancienneValeur = stripslashes($lig[$value]);
					if($lig[$value] != $_POST[$value] ){//On modifie si il ya difference entre l'ancien et le nouveau
			                        $res = execute($query);
			                        $nbchampsAjour = $nbchampsAjour + $res ; //echo "<br>update $res";
						//echo prmess($query) ;
					}
						
                               }
				
			       //On doit maintenant mettre a jour la date de derniere modification , s'il ya eu modification
				
                                                $query = "update ".$nomtable.
                                                         " set Date_modif = '".date('Y-m-d')."' where ".str_replace("Tab","",$nomtable).
                                                         "Id = ".$_POST['oid'];
						if( $nbchampsAjour > 0 ){
                                                $res = execute($query);
                                                $nbchampsAjour = $nbchampsAjour + $res ;
						}

			       //On doit maintenant mettre a jour la Ville de l'objet
				$o = new Object() ;
				
				$anvid = $o -> getVilleId($nomtable , $objectid) ; //Ancien VilleId
				//echo "ancien villeid = $anvid " ;
				$nvid = $_POST['VilleId'] ; //Nouveau VilleId
				//echo "<br>Nouveau villeid = $nvid " ;
				if( $nvid != $anvid){
                                                $query = "update $nomtable set VilleId = $nvid where ".str_replace("Tab","",$nomtable)."Id = ".$_POST['oid'];
                                                $res = execute($query);
                                                $nbchampsAjour = $nbchampsAjour + $res ;
		                       		//echo "Ville mise a jour" ;
				       $norubr = $o -> getNoRubrique($nomtable,$objectid) ;
				}
					
				if( $nbchampsAjour > 0 ){
		                       echo confmess(($nbchampsAjour-1)." champs mis &agrave; jour<br><br><a href='visualise.php?nt=$nomtable&oid=".$_POST['oid']."&nr=$norubr'>Visualiser cela</a>");

				}else{
		                       echo prmess("Aucun champ mis &agrave; jour<br><br><a href='editinsertion.php?nt=$nomtable&oid=".$_POST['oid'].
					"&nr=$norubr'>Aller &agrave; la page de modification</a><br><br><a href='fullview.php?nt=$nomtable&oid=".$_POST['oid'].
					"&nr=$norubr'>Visualiser les details de l'objet , sur grand format</a>");


				}
                        }   
        }
                     
	inclusionPied() ;

?>
