<?php

class Log {

              private $id = 0;
              private $iduser = 0 ;
              private $macaddr = '' ;
              private $datel  =  '' ;
			  public function setId($i) {  $this -> id = $i ;}
			  public function setIdUser($mat) { $this -> iduser = $mat ;}
			  public function setMacAddr($adr) {  $this -> macaddr = $adr;}
			  public function setDatel($d) { $this -> datel = $d ;}
			  public function setUrl($d) { $this -> url = $d ;}
			  public function getId() {  return $this -> id  ;}
			  public function getIdUser() { return $this -> iduser  ;}
			  public function getMacAddr() {  return $this -> macaddr ;}
			  public function getDatel() { return $this -> datel ;}
			  public function getUrl() { return $this -> url ;}
			  
				function __construct($mat , $madr ,$datel ){ 
				
						$this -> iduser = $mat ;
						$this -> macaddr = $madr ;
						$this -> datel    = $datel;
				}
			  
			  public function updateDb(){ // Will update the database by updating the table's instance 

			  }

			
			  public function isLog(){// Function used to verify if a user's iduser is already set. if not , the scripts exits. Else continues execution
				if(!isset($this -> iduser)) {echo 'Arret d\'execution : Log class d\'instance nulle ' ; exit ;} 
			  }
			  public function registerDb(){ // Will update the database by inserting a new log into the Database
			  		 $url = addslashes($this -> getUrl()) ;
                    			 $this -> isLog();						
					 $req = "insert into log (id,iduser, macaddr, datel, url)".
							"values (".
							"id ,".
							   $this -> getIdUser().",".
							"'".$this -> getMacAddr()."',".
							"'".$this -> getDatel()."' ,".
							"\"".$url."\"".
							")";

                     			$res = execute($req);
			  } 
			  
			  public function createlog(){
			  
                                        $this -> registerDb();
                              			// Stores the mac address of the user from where she logged in
                              			$_SESSION['macaddr']  =  $this -> getMacAddr();
			  }

			  public function getLogList($ipaddr , $date){
				$q = "select id ,iduser , macaddr , date_format(datel , '%a %D %M %Y') as datel , url from log where macaddr=\"".addslashes($ipaddr)."\" and  date_format(datel , '%Y-%m-%d')=\"".$date."\"" ;
				$res = execute($q) ; 
				$retour = "" ; $l = array() ;
				if(mysql_num_rows($res) > 0){
					$u = new User() ;
					while($l = mysql_fetch_assoc($res)){
						$iduser = $l["iduser"] ; $pseudo = "Invite" ;
						if($iduser > 0){
							$u -> setUserId($iduser) ;
							$u -> loadFromId();
							$nom = $u -> getNom();
							$prenom = $u -> getPrenom() ;
							$pseudo = $u -> getPseudo();
						}else{
							$nom = "";
							$prenom = "" ;
							
						}
						$datel = $l["datel"] ; $ipaddr = $l["macaddr"] ; $url = stripslashes($l["url"]);
						$retour .= "$pseudo\t$nom\t$prenom\t$datel\t$ipaddr\t$url\n" ;		
						//$retour .= "$pseudo $nom  $prenom  $datel $ipaddr $url<br>" ;
					}
				}
				return $retour ;
			  } 
		}


?>
