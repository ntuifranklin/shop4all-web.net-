/*Begining of Form validation functions */

/* Global variable */
		var couleur = "orange" ;//La couleur à utiliser pour faire focuser un champ in valide
		var couleurdefaut = "white" ;
		var couleurdouce = "brown" ;
		var oldValue = "" ;
		var remov = false ; //Utiliser pour la verification si on a modifier les options d'un select pour empecher les suppression multiples
				    // dans cette option.


		function firstCharUp(inputField){//Prends un input field contenant une chaine de caractere et place le premier caractere en majuscule
			//On scindera la chaine en morceaux separe par des espaces
			var chaine = inputField.value ; 
			var ch = "" , interm = "" ; ;
			var stringArray = chaine.split(" ");//On cree un tableau de chaine contenu de souschaine sans espaces
			var i=0;
			for(i=0;i<stringArray.length ; i++){//On convertit chaque premeir charactere des elements du tableau en majuscule
				ch = stringArray[i] ;
				interm = preCharMaj(ch);
				stringArray[i] = interm ;

			}
			
			chaine = stringArray.join(" ") ;
			inputField.value = chaine ;
		}

		function preCharMaj(chaine){//Prends une chaine et convertit son premier caractere en majuscule
			var invalue = chaine ;//Chaine initiale
			var inputt = invalue.toString();
			var fs = "" ;
			var returnstr = "" ;
			var i=0;
			
			fs = inputt.charAt(0) ;
			fs = fs.toUpperCase();
			//inputField.value = inputField.value.toUpperCase(); 
			returnstr = fs;
			for(i=1 ; i<inputt.length ; i++)//On compte de un a la longeur car le caractere 0 a deja ete transformer
				returnstr = returnstr + inputt.charAt(i);
			return returnstr ;

		}

		function isSubChar(inputVal , achar) {//Verifie si un caractere aChar est comprise dans une chaine inputVal
			var inputStr = inputVal.toString() ;
			var i=0 ;
			var oneChar = '' ;
			for(i = 0; i < inputStr.length; i++) {
				 oneChar = inputStr.charAt(i) ;
				if (oneChar == achar ) {
					return true ;
				}
			}
			return false ;
		}

		
		function emailIsValid(inputVal) {//Verifie si l'email prise en parametre est un email valide , c-a-d de la forme *@* , donc au moins de longeur 3
			var inputStr = inputVal.toString() ;
			var i=0 ;
			var oneChar = '' ;
			if(isEmpty(inputVal) || ! isSubChar(inputVal , '@') || inputVal.toString().length < 3) return false ;
			var emailparts = inputVal.split("@");
			var domain_name = emailparts[1].split(".");
			//Si le nom de domaine depasse 3 caracteres alors l'email n'est pas valide
			if(domain_name.length < 2 || domain_name[domain_name.length - 1].toString().length > 3 || domain_name[domain_name.length - 1].toString().length < 2 
			|| isEmpty(domain_name[domain_name.length - 1])) return false ;
			return true ;
		}


		function isEmpty(inputStr) {
			var inputVal = inputStr.toString() ;
			if (inputStr == "" || inputStr == null || inputVal == "" || inputStr == 0 || inputVal.length < 1) {
			return true ;
			}
			return false ;
		}

		function isPosInteger(inputVal) {
			var inputStr = inputVal.toString() ;
			var i=0 ;
			var oneChar = '' ;
			for(i = 0; i < inputStr.length; i++) {
				 oneChar = inputStr.charAt(i) ;
				if (oneChar < '0' || oneChar > '9') {
					return false ;
				}
			}
			return true ;
		}

		function isInteger(inputVal) {
			return (isPosInteger(inputVal) || isNegInteger(inputVal) || inputVal == 0) ;
		}

		function isNegInteger(inputVal){
			var inputStr = inputVal.toString() ;
			var i=0 ;
			var oneChar = '' ;
			if(inputStr.charAt(0) != '-') return false ;//Si la chaine n'as pas de signe -
			for(i = 1; i < inputStr.length; i++) {
				 oneChar = inputStr.charAt(i) ;
				if ((oneChar < '0' || oneChar > '9') ) {
					return false ;
				}
			}
			return true ; 
		}

/*    End of Form validation functions */

		function ck0(){//Verifie si la rubrique dans le formulaire de recherche a été selectionner
			 	
			 var nor ;	
			 nor = document.forms["ch"].elements["rubr"].value ;

			  if( isNegInteger(nor) || isEmpty(nor)){
					alert("Choisissez la rubrique pour la recherche");
					document.forms["ch"].elements["rubr"].focus();
					return false ;
			  }
		
		 	return true ;
		}//Fin ck0()

		function ck1(){//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire d'inscription
				
			 var mp1 , mp2 , ps, em  , tel ,vid ;//Pour sauvegarder les valeurs
			 var nmp1 , nmp2 , nps, nem   , ntel ,nvid ; //Pour sauveagrder les noms des champs	
	
			 nvid = document.forms["inscrip"].elements["villeid"] ;	
			 nmp1 = document.inscrip.mdp1 ;
			 nmp2 = document.inscrip.mdp2 ;
			 nem = document.inscrip.email ;
			 nps = document.inscrip.pseudo ;
			 ntel = document.inscrip.tel ;

			 vid = document.forms["inscrip"].elements["villeid"].value ;	
			 mp1 = document.inscrip.mdp1.value ;
			 mp2 = document.inscrip.mdp2.value ;
			 em = document.inscrip.email.value ;
			 ps = document.inscrip.pseudo.value ;
			 tel = document.inscrip.tel.value ;


			  if( mp1 != mp2 ){
					alert("Les deux mots de passe sont distinct");
					if( isEmpty(mp1)){
						nmp1.style.backgroundColor = couleur ;
						nmp1.focus();
						nmp1.select();
					}else{
						nmp2.focus();
						nmp2.style.backgroundColor = couleur ;
					}
					return false ;
			  }else{
					nmp1.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(mp1) ){
					nmp1.style.backgroundColor = couleur ;
					nmp1.focus();
					nmp1.select();
					alert("Entrez le mot de passe");
					//nmp1.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nmp1.style.backgroundColor = couleurdefaut ;
			  }
		
			  if( isEmpty(mp2) ){
					nmp2.style.backgroundColor = couleur ;
					nmp2.focus();
					nmp2.select();
					alert("Entrez la confirmation du mot de passe");
					return false ;
			  }else{
					nmp2.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(em) ){
					nem.style.backgroundColor = couleur ;
					alert("Tappez l'email");
					nem.focus();
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if(  ! emailIsValid(em) || isInteger(em)){
					nem.style.backgroundColor = couleur ;
					nem.select();
					nem.focus();
					alert("L'email est invalide");
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(ps) ){
					alert("Le pseudo est vide");
					nps.focus();
					nps.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nps.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(tel) ){
					alert("Tappez le telephone");
					ntel.focus();
					ntel.style.backgroundColor = couleur ;
					return false ;
			  }else{
					ntel.style.backgroundColor = couleurdefaut ;
			  }


			  if( isNegInteger(vid) || isEmpty(vid) ){
					alert("Choisissez votre lieu de residence");
					nvid.focus();
					return false ;
			  }
		 	return true ;
		}//Fin ck1()

		function ck2(){
		//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire de choix de type d'objet , de departement et de rubrique
		var b = true ;	
		//nom des champs select : norubr , provid , objtyp. Ceux necessaire pour verification sont les deux 1ers
		 var norubriqu , provinceid ;
		 var nnorubriqu , nprovinceid ;
		 
		 norubriqu = document.forms["choi"].elements["norubr"].value ;	
		 provinceid = document.forms["choi"].elements["provid"].value ;	
		 nnor = document.forms["choi"].elements["norubr"];	
		 npro = document.forms["choi"].elements["provid"] ;		
			if(norubriqu < 1){
				alert("Selectionner la rubrique");
					nnor.focus();
					//confirm("couleur = "+nnor.backgroundColor) ;
					return false ;
			  }

			if(provinceid < 1){
				alert("Selectionner la province");
				document.forms["choi"].elements["provid"].focus() ;
				b = false ;
				return b ;//On sort sans plus verifier le reste
			}	
				//confirm("ok") ;
		 		return b ;
		}//Fin ck2()

		function ck3(){
		//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire de connexion
		var b = true ;	
		//nom des champs : uzer , mdp
		 var util , mp , nutil , nmp ;
		 
		 nutil = document.forms["con"].uzer ;	
		 nmp = document.forms["con"].mdp ;
		 util = document.forms["con"].uzer.value ;	
		 mp = document.forms["con"].mdp.value ;		
			if(isEmpty(util) || isInteger(util)){
				nutil.style.backgroundColor=couleur;
				nutil.focus();
				nutil.select();
				alert("Pseudo invalide");
				b = false ;
				return b ;
			}else{
				nutil.style.backgroundColor=couleurdefaut;
			}	

			if(isEmpty(mp)){
				alert("Le mot de passe est vide");
				b = false ;
				document.forms["con"].mdp.select();
				nmp.style.backgroundColor=couleur;
				return b ;//On sort sans plus verifier le reste
			
			}else{
				nmp.style.backgroundColor=couleurdefaut;
			}		
				//confirm("ok") ;
		 		return b ;
		}//Fin ck3()


		function ck4(){//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire d'inscription partielle lors d'une insertion
				
			 var  ps, em , tel  ;//Pour sauvegarder les valeurs
			 var  nps, nem , ntel  ; //Pour sauveagrder les noms des champs	
	
			 nem = document.partinscrip.email ;
			 nps = document.partinscrip.pseudo ;
			 ntel = document.partinscrip.tel ;

			 em = document.partinscrip.email.value ;
			 ps = document.partinscrip.pseudo.value ;
			 tel = document.partinscrip.tel.value ;

			  if( isEmpty(ps) ){
					alert("Le pseudonyme est vide");
					nps.focus();
					nps.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nps.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(em) ){
					alert("Tappez l'email");
					nem.focus();
					nem.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if(  ! emailIsValid(em) || isInteger(em)){
					nem.style.backgroundColor = couleur ;
					nem.focus();
					nem.select();
					alert("L'email est invalide");
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(tel) ){
					alert("Tappez le numéro de telephone");
					ntel.focus();
					ntel.style.backgroundColor = couleur ;
					return false ;
			  }else{
					ntel.style.backgroundColor = couleurdefaut ;
			  }

		 	return true ;
		}//Fin ck4()


		function ck5(){//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire d'inscription complete
				
			 var mp1 , mp2 , ps, em  , tel ,vid ;//Pour sauvegarder les valeurs
			 var nmp1 , nmp2 , nps, nem   , ntel ,nvid ; //Pour sauveagrder les noms des champs	
	
			 nvid = document.forms["compl"].elements["villeid"] ;	
			 nmp1 = document.compl.User_pw1 ;
			 nmp2 = document.compl.User_pw2 ;
			 nem = document.compl.User_email ;
			 nps = document.compl.User_pseudo ;
			 ntel = document.compl.User_tel ;

			 vid = document.forms["compl"].elements["villeid"].value ;	
			 mp1 = document.compl.User_pw1.value ;
			 mp2 = document.compl.User_pw2.value ;
			 em = document.compl.User_email.value ;
			 ps = document.compl.User_pseudo.value ;
			 tel = document.compl.User_tel.value ;


			  if( mp1 != mp2 ){
					alert("Les deux mots de passe sont distinct");
					if( isEmpty(mp1)){
						nmp1.focus();
						nmp1.style.backgroundColor = couleur ;
					}else{
						nmp2.focus();
						nmp2.style.backgroundColor = couleur ;
					}
					return false ;
			  }else{
					nmp1.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(mp1) ){
					alert("Entrez le mot de passe");
					nmp1.focus();
					nmp1.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nmp1.style.backgroundColor = couleurdefaut ;
			  }
		
			  if( isEmpty(mp2) ){
					alert("Entrez la confirmation du mot de passe");
					nmp2.focus();
					nmp2.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nmp2.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(em) ){
					alert("Tappez l'email");
					nem.focus();
					nem.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if(  ! emailIsValid(em) || isInteger(em)){
					nem.style.backgroundColor = couleur ;
					nem.focus();
					nem.select();
					alert("L'email est invalide");
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(ps) ){
					nps.style.backgroundColor = couleur ;
					nps.focus();
					nps.select();
					alert("Le pseudo est vide");
					return false ;
			  }else{
					nps.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(tel) ){
					alert("Tappez le numéro de telephone");
					ntel.focus();
					ntel.style.backgroundColor = couleur ;
					return false ;
			  }else{
					ntel.style.backgroundColor = couleurdefaut ;
			  }


			  if( isNegInteger(vid) || isEmpty(vid) ){
					alert("Choisissez votre ville d'habitat");
					nvid.focus();
					return false ;
			  }
		 	return true ;
		}//Fin ck5()

	function ck6(){//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire de modification
		
		 var mp , mp1 , mp2 , ps, em  , tel ,vid ;//Pour sauvegarder les valeurs
		 var nmp1 , nmp2 , nps, nem   , ntel ,nvid ; //Pour sauveagrder les noms des champs	

		 nvid = document.forms["modi"].elements["villeid"] ;	
		 nmp = document.modi.User_pw ;	
		 nmp1 = document.modi.User_pw1 ;
		 nmp2 = document.modi.User_pw2 ;
		 nem = document.modi.User_email ;
		 nps = document.modi.User_pseudo ;
		 ntel = document.modi.User_tel ;

		 vid = document.forms["modi"].elements["villeid"].value ;	
		 mp = document.modi.User_pw.value ;	
		 mp1 = document.modi.User_pw1.value ;
		 mp2 = document.modi.User_pw2.value ;
		 em = document.modi.User_email.value ;
		 ps = document.modi.User_pseudo.value ;
		 tel = document.modi.User_tel.value ;


		  if( (!isEmpty(mp) && mp1 != mp2) || (isEmpty(mp) && ( !isEmpty(mp1) || !isEmpty(mp2)  )) ){//Si le user veut changer de mot de passe
				alert("Les deux mots de passe sont distinct / Le mot de passe courant n'est pas renseigner");
				if( isEmpty(mp1)){
					nmp1.focus();
					nmp1.style.backgroundColor = couleur ;
				}else{
					nmp2.focus();
					nmp2.style.backgroundColor = couleur ;
				}
				return false ;
		  }else{
				nmp1.style.backgroundColor = couleurdefaut ;
		  }



		  if( isEmpty(em) ){
				alert("Tappez l'email");
				nem.focus();
				nem.style.backgroundColor = couleur ;
				return false ;
		  }else{
				nem.style.backgroundColor = couleurdefaut ;
		  }

		  if(  ! emailIsValid(em) || isInteger(em)){
				nem.style.backgroundColor = couleur ;
				nem.focus();
				nem.select();
				alert("L'email est invalide");
				return false ;
		  }else{
				nem.style.backgroundColor = couleurdefaut ;
		  }

		  if( isEmpty(ps) ){
				nps.style.backgroundColor = couleur ;
				nps.focus();
				nps.select();
				alert("Le pseudo est vide");
				return false ;
		  }else{
				nps.style.backgroundColor = couleurdefaut ;
		  }

		  if( isEmpty(tel) ){
				alert("Tappez le numéro de telephone");
				ntel.focus();
				ntel.style.backgroundColor = couleur ;
				return false ;
		  }else{
				ntel.style.backgroundColor = couleurdefaut ;
		  }


		  if( isNegInteger(vid) || isEmpty(vid) ){
				alert("Choisissez votre ville d'habitat");
				nvid.focus();
				return false ;
		  }
	 	return true ;
	}//Fin ck6()
/*
	function changeChoix(thisSel ,otherSel , selIndFor,indexToRemove ){
		//Prends en parametre  un formualire contenant un select avec des options dont il faut supprimer l'element d'indice indexToRemove dans 
		//le formulaire en cours

		var selName = document.forms["choi"].otherSel ;
		var tselName = thisSel ;
		var ind = indexToRemove ;
		var indch =  selIndFor ;
		var selectedIndexe = tselName.selectedIndex ;
		if(selectedIndexe == indch ){
			 
			oldValue = selName.options[ind]  ;
			selName.remove(ind);
			remov = true ;
		}else{
			if(remov == true and selectedIndexe != indch ){
				selName.options[selName.length] = new Option(oldValue) ;
				remov = false ;
			}
		}
	}
*/

		function ck7(){//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire d'envoi d'une annonce d'insertion a un ami
				
			 var  ps, em , emami  ;//Pour sauvegarder les valeurs
			 var  nps, nem , nemailami  ; //Pour sauveagrder les noms des champs	
	
			 nem = document.envoiannonce.email ;
			 nps = document.envoiannonce.pseudo ;
			 nemailami = document.envoiannonce.emailami ;

			 em = document.envoiannonce.email.value ;
			 ps = document.envoiannonce.pseudo.value ;
			 emami = document.envoiannonce.emailami.value ;

			  if( isEmpty(ps) ){
					alert("Le pseudonyme est vide");
					nps.focus();
					nps.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nps.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(em) ){
					alert("Tappez votre email");
					nem.focus();
					nem.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if(  ! emailIsValid(em) || isInteger(em)){
					nem.style.backgroundColor = couleur ;
					nem.focus();
					nem.select();
					alert("Votre email est invalide");
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }
			 
			  if( isEmpty(emami) ){
					alert("Tappez l'email de votre ami");
					nemailami.focus();
					nemailami.style.backgroundColor = couleur ;
					return false ;
			  }else{
					
					nemailami.style.backgroundColor = couleurdefaut ; ;
			  }
			
			  if (  ! emailIsValid(emami) || isInteger(emami) ) {
					alert("L'email de votre ami est invalide");
					nemailami.focus();
					nemailami.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nemailami.style.backgroundColor = couleurdefaut ;
			  }

			  if( em == emami ){//Les deux emails sont differents
					alert("Les deux emails doivent etre differents");
					nemailami.focus();
					nemailami.style.backgroundColor = couleur ;
					return false ;
			  }else{
					
					nemailami.style.backgroundColor = couleurdefaut ; ;
			  }
		 	return true ;
			
		}//Fin ck7()


		function ck8(){//Verifie si certains champs obligatoire ont ete renseignes dans le formulaire de contact du web master
				
			 var  ps, em , tel ,messages ;//Pour sauvegarder les valeurs
			 var  nps, nem , ntel,nmess  ; //Pour sauveagrder les noms des champs	
	
			 nem = document.contactw.email ;
			 nps = document.contactw.pseudo ;
			 ntel = document.contactw.tel ;
			 nmess = document.contactw.mess ;

			 em = document.contactw.email.value ;
			 ps = document.contactw.pseudo.value ;
			 tel = document.contactw.tel.value ;
			 messages = document.contactw.mess.value ;

			  if( isEmpty(ps) ){
					alert("Le pseudonyme est vide");
					nps.focus();
					nps.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nps.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(em) ){
					alert("Tappez l'email");
					nem.focus();
					nem.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }

			  if(  ! emailIsValid(em) || isInteger(em)){
					nem.style.backgroundColor = couleur ;
					nem.focus();
					nem.select();
					alert("L'email est invalide");
					return false ;
			  }else{
					nem.style.backgroundColor = couleurdefaut ;
			  }


			  if( isEmpty(tel) ){
					alert("Tappez le numéro de telephone");
					ntel.focus();
					ntel.style.backgroundColor = couleur ;
					return false ;
			  }else{
					ntel.style.backgroundColor = couleurdefaut ;
			  }

			  if( isEmpty(messages) ){
					alert("Le message est vide");
					nmess.focus();
					nmess.style.backgroundColor = couleur ;
					return false ;
			  }else{
					nmess.style.backgroundColor = couleurdefaut ;
			  }

		 	return true ;
		}//Fin ck8()

