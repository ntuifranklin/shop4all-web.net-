<?php
       
        /*
        *@Cette classe modelise une image appartenant a un Objet
        *
        *@ Touts ses attributs correspondent a celle de la table ImagesTab en base de donnees
        *
        *
        *
        */

        class Photo{
            private $ImagesId = 0 ; private $ObjectId = 0; private $Table_appartenance = "" ; private $nom = "";

            function  __construct(){
                       $this -> setId(""); 
                       $this -> setObjectId(0); 
                       $this -> Table_appartenance = "";
                       $this -> nom = "";
            }  

            /*** Modificateurs ***/
            public function setId($i){
                $this -> ImagesId = $i ;
            }

            public function setObjectId($t){
                $this -> ObjectId = $t ;
            }

            public function setTableAppartenance($n){
                $this -> Table_appartenance = $n ;
            }

            public function setNom($i){
               $this -> nom  = $i ;
            }

           /*** Accesseurs ***/
            public function getId(){
               return  $this -> ImagesId  ;
            }
            public function getObjectId(){
                return $this -> ObjectId  ;
            }

            public function getTableAppartenance(){
                return $this -> Table_appartenance ;
            }


            public function getNom(){
                return $this -> nom;
            }




            public function create(){ /*** Cree un nouvel photo en inserant une ligne dans la table ImagesTab ***/
                
               
                /*** Preparation de la requete pour execution ***/
		
                $objectId = $this -> getObjectId() ;
                $ImagesId = addslashes($this -> getId()) ; // A programmer. Une fonction qui retournera l'id de l'image
                $Table_appartenance = $this -> getTableAppartenance();//Retourne le nom de la table
                $nom = $this -> getNom();//Retourne le nom de l'image dabs le dossier files
                $query = "insert into ImagesTab values(".
                         "ImagesId,".
                         "'".$objectId."',".  
                         "'".$Table_appartenance."',".  
                         "'".$nom."'".  
                         ")";

                        $r = execute($query);
                        $nomtable = 'ImagesTab';

			/*** Recupere l'autoincrement pour l'ImagesId de cet Photo ***/
                        $ImagesId = getAutoIncrementValue($nomtable);
                        $this -> setId($ImagesId);
			
            }   

	
	   public function getImage($ImagesId){//Retourne le ObjectIds vers une image appartenant a l'objet $ImagesIdobject si elle existe
		$ObjectId ="" ;
		if(is_numeric($ImagesId)){//Si l'ImagesId est numerique
			$res = execute("select * from ImagesTab where ImagesId=".$ImagesId);
			if(mysql_num_rows($res) > 0){
			        $line = mysql_fetch_assoc($res);
			        $nomImage = stripslashes($line['nom']);
                        }
		}
		return $nomImage ;

	   }    

	   public function getAllImages($objectid,$nomtable){//Retourne tous les ImagesId d'une image appartenant a l'objet $ImagesIdobject si elle existe dans un tableau
		  $ImagesIds = array(); $k=0;
		if(is_numeric($objectid) && !empty($nomtable)){//Si l'ImagesId est numerique and 
			$res = execute("select * from ImagesTab where ObjectId=".$objectid." and Table_appartenance='".$nomtable."' and nom !='' ");
			
			if(mysql_num_rows($res) > 0){
				while($line = mysql_fetch_assoc($res)){
					$ImagesIds[$k] = $line['ImagesId'];
					$k++;
				}
			}
		}
		return $ImagesIds ;

	   }//Fin getAllImages


           public function deleteAllImages($ImagesIdobject){
                         $nm = $this -> getTableAppartenance();

                        if(!empty($ImagesIdobject) && is_numeric($ImagesIdobject) && ! empty($nm)){
                                
                                $ImagesIds = $this -> getAllImages($ImagesIdobject , $nm);
                                for($i=0;$i<count($ImagesIds) ; $i++){
                                        $query2 = "delete from ImagesTab where ImagesId=".$ImagesIds[$i];
                                        $imagelink = stripslashes($this -> getImage($ImagesIds[$i]));
                                        unlink($imagelink);
                                        $res2 = execute($query2);
                                }
                        }

           }//Fin deleteAllImages

                
         public function getTotalNb(){//Retourne le nombre d'images enregistrer dans la table Images
                $query = "select count(*) as nb from  ImagesTab" ;
                $res = execute($query);
                while($l = mysql_fetch_assoc($res))
                return (int)$l['nb'];
         }//Fin getTotalNb
             
         public function updateImage($idimage ,$objectid,$nomtable , $nom){

                $lien = 0 ; $norubr = 0 ;
                $obj = new Object(); $norubr = $obj -> getNoRubrique($nomtable ,$objectid);
                $nouveauNomImage = $nom ;
		
                $nbimages = $this -> howManyImages($objectid , $nomtable); $nbimages++ ;
                $fichiertemp    = $_FILES[$nom]["tmp_name"]; $taille = $_FILES[$nom]["size"] ;
                $nomfichier     = $_FILES[$nom]["name"]; $repertoire = getUserFileDir();
                //On supprimera d'abord l'ancien fichier
		$nomimage = $this -> getImage($idimage); 
		$ancienPrefixe = getPrefixeFichier($nomimage);
                $nouveauNomImage = $ancienPrefixe.".gif" ;//ancien prefixe.gif sous entendu que les fichiers seront toujours des gifs
		//On supprime d'abord l'ancienne image avant de creer une nouvelle image
                if(is_file($repertoire."/".$nomimage))
                unlink($repertoire."/".$nomimage);
                $lien = "";		
		$size = getImageSize($_FILES[$nom]["tmp_name"]);
                if( is_uploaded_file($fichiertemp) && $taille != 0 ){
                        $size = getImageSize($_FILES[$nom]["tmp_name"]);
                     if( ! is_dir($repertoire)){//Verifier si le repertoire existe, sinon le cree
                                mkdir($repertoire);chmod($repertoire."/" , 0777);
                     }
                  
			switch ($size[2]) {//On determine les types de l'image charger
				case 1: //un fichier gif
				createGifAndPng($nom , $repertoire , $nouveauNomImage);
				break ;
				case 2: //un fichier jpeg
				createJpeg($nom , $repertoire , $nouveauNomImage);
				break ;
				case 3: //un fichier png
				createGifAndPng($nom , $repertoire , $nouveauNomImage);
				break;
			}	
                        
                               
                     
   		     //si la sauvegarde s'est bien effectuer
                     if(is_file( $repertoire."/" . $nouveauNomImage ) &&  chmod($repertoire."/".$nouveauNomImage  , 0777)){
                                
				$q = "update ImagesTab set nom=\"".$nouveauNomImage."\" where ImagesId=$idimage";
				$r = execute($q);
				$this -> setId($idimage) ;

                     }
                 }

		return $r ;//Retourne 1 si une mise a jour a ete effectuer et 0 sinon 

         }//Fin function updateImage

         public function createImage($norubr , $nomtable , $objectid , $nom){
		//createJpeg($nomfichier , $folder , $nomFinal)
		//createGifAndPng($nomfichier , $folder , $nomFinal)
              
                $lien = 0 ;
                $nbimages = $this -> howManyImages($objectid , $nomtable); $nbimages++ ;
                $fichiertemp    = $_FILES[$nom]["tmp_name"]; $taille = $_FILES[$nom]["size"] ;
                $nomfichier     = $_FILES[$nom]["name"]; $repertoire = getUserFileDir();//Retourne le nom du repertoire ou on garde les photos des insertions des users
                $nouveauNomImage = $norubr."_".$objectid."_".$nbimages.".gif" ;
                $lien = "";
		$size = getImageSize($_FILES[$nom]["tmp_name"]);
                if( is_uploaded_file($fichiertemp) && $taille != 0 ){
                        
			$size = getImageSize($_FILES[$nom]["tmp_name"]);
			
	             if( ! is_dir($repertoire)){//Verifier si le repertoire existe, sinon le cree
	                        mkdir($repertoire);chmod($repertoire."/" , 0777);
	             }
			switch ($size[2]) {//On determine les types de l'image charger
				case 1: //un fichier gif
				createGifAndPng($nom , $repertoire , $nouveauNomImage);
				break ;
				case 2: //un fichier jpeg
				createJpeg($nom , $repertoire , $nouveauNomImage);
				break ;
				case 3: //un fichier png
				createGifAndPng($nom , $repertoire , $nouveauNomImage);
				break;
			}	
                        
   		     //si la sauvegarde s'est bien effectuer
                     if(is_file( $repertoire."/" . $nouveauNomImage ) &&  chmod($repertoire."/".$nouveauNomImage  , 0777)){
                                          
                                $this -> setObjectId($objectid);
                                $this -> setNom($nouveauNomImage);
                                $this -> setTableAppartenance($nomtable);
                                $this -> create();
                     }
                          /*     
                     if(move_uploaded_file( $fichiertemp, $repertoire."/" . $nouveauNomImage ) &&  chmod($repertoire."/" . $nouveauNomImage  , 0777)){
                                
                                $lien =  $nouveauNomImage ;
                                 
                                $this -> setObjectId($objectid);
                                $this -> setNom($nouveauNomImage);
                                $this -> setTableAppartenance($nomtable);
                                $this -> create();
                     }
			*/
                 }


         }//fin fonction createImage
	
	public function createFile($norubr , $nomtable , $objectid , $nom){
		return $this -> copyFile($norubr , $nomtable , $objectid , $nom);
	}

	public function copyFile($norubr , $nomtable , $objectid , $nom){
	$pho = new Photo();
                $lien = 0 ;
                $nbimages = $pho -> howManyImages($objectid , $nomtable);$nbimages++;
                $fichiertemp    = $_FILES[$nom]["tmp_name"]; $taille = $_FILES[$nom]["size"] ;
                $nomfichier     = $_FILES[$nom]["name"]; $repertoire = getUserFileDir();
		$nouveauNomImage = $norubr."_".$objectid."_".$nbimages.".".getExtension($nomfichier) ;
                $lien = "";
                if( is_uploaded_file($fichiertemp) && $taille != 0 ){
                        

                     if( ! is_dir($repertoire)){//Verifier si le repertoire existe, sinon le cree
                                mkdir($repertoire);chmod($repertoire."/" , 0777);
                     }
                        
                               
                     if(move_uploaded_file( $fichiertemp, $repertoire."/" . $nouveauNomImage ) &&  chmod($repertoire."/" . $nouveauNomImage  , 0777)){
                                
                                $lien =  $nouveauNomImage ;
                                                 
                                //echo "<br>Nb images :$nbimages <br>";
                                $pho -> setNom($nouveauNomImage);
                                $pho -> setObjectId($objectid);
                                $pho -> setTableAppartenance($nomtable);
                                $pho -> create();
                        }
                 }
                return $lien ;


	}//fin fonction copyFile
    
         public function updateFile($idimage ,$objectid,$nomtable , $nom){

                $lien = 0 ; $norubr = 0 ;
                $obj = new Object(); $norubr = $obj -> getNoRubrique($nomtable ,$objectid);
                $nouveauNomImage = $nom ;
		
                $nbimages = $this -> howManyImages($objectid , $nomtable); $nbimages++ ;
                $fichiertemp    = $_FILES[$nom]["tmp_name"]; $taille = $_FILES[$nom]["size"] ;
                $nomfichier     = $_FILES[$nom]["name"]; $repertoire = getUserFileDir();
                //On supprimera d'abord l'ancien fichier
		$nomimage = $this -> getImage($idimage); 
		$ancienPrefixe = getPrefixeFichier($nomimage);
                $nouveauNomImage = $ancienPrefixe.".".getExtension($nomfichier) ;
		//On supprime d'abord l'ancienne image avant de creer une nouvelle image
                if(is_file($repertoire."/".$nomimage))
                unlink($repertoire."/".$nomimage);
                $lien = "";		
		$size = getImageSize($_FILES[$nom]["tmp_name"]);
                if( is_uploaded_file($fichiertemp) && $taille != 0 ){
                        
                     if( ! is_dir($repertoire)){//Verifier si le repertoire existe, sinon le cree
                                mkdir($repertoire);chmod($repertoire."/" , 0777);
                     }
                  
                               
                     
   		     //si la sauvegarde s'est bien effectuer
                     if(move_uploaded_file( $fichiertemp, $repertoire."/" . $nouveauNomImage ) &&  chmod($repertoire."/".$nouveauNomImage  , 0777)){
                                
				$q = "update ImagesTab set nom=\"".$nouveauNomImage."\" where ImagesId=$idimage";
				$r = execute($q);
				$this -> setId($idimage) ;
                     }
                 }

		return $r ;//Retourne 1 si une mise a jour a ete effectuer et 0 sinon 

         }//Fin function updateFile



         public function howManyImages($objectid , $nomtable){//Compte le nombre d'images apparteat a  un objet
                $nb = 0 ;
                if(!empty($objectid) && !empty($nomtable)){
                $query = "select count(*) as nb from ImagesTab where ObjectId=".$objectid." and Table_appartenance='$nomtable' ";
                $res = execute($query);
                $l = mysql_fetch_assoc($res);
                $nb = $l['nb'] ;
                }
                return $nb ;
         }
       
        }//Fin classe Photo

?>
