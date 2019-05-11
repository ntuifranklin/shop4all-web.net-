<?php
	$class = getRubriqueTableAsArray();
        $rubr = new $class[$_POST['norubr']]();//Creation d'une classe correspondant a la rubrique choisi
        $objtyp = $_POST['objtyp'] ; $provid = $_POST['provid'] ;
        $titr = $_POST['titreRub']; $actionFile = "treatinsertion.php"; $nom = $class[$_POST['norubr']] ;
	$obj = new $nom(); //Creation de l'objet
	$arrChamps = $obj -> getAttribAsArray();//La liste des titres => nomchamp du type d'objet dont veut effectuer une insertion
	$arrTypes = $obj -> getTableTypes();//Les types des pour chaque champ retourner par getAttribAsArray
	$arrNulls = $obj -> getTableNulls();
	$arrTailles = $obj -> getTableTailles();
	$nbC = count($arrChamps);//nb de lignes
	$nbT = count($arrTypes);//nb de lignes
	$defvar = "";//Elle contiendra tout le programme javascript

	echo "<script language='javascript'>\n";
	$defvar  .= "\tvar lc = new Array($nbC);\n";//La liste des champs
	$defvar  .= "\tvar lctypes = new Array($nbT);\n";//La liste des types
	$defvar  .= "\tvar lctitles = new Array($nbC);\n";//La liste des titres des champs
	$defvar  .= "\tvar lcnulls = new Array($nbC);\n";//La liste des champs qui peuvent etre nulle ou pas
	$defvar  .= "\tvar lctailles = new Array($nbC);\n";//La liste des tailles des champs 
	//Maintenant on va placer le nom des champs dans ce tableau de meme que les types pour le tableau
	$i=0;
	foreach($arrChamps as $titrechamp => $nomchamp){
		$defvar .= "\t\tlc[$i]=\"$nomchamp\";\n";
		$defvar .= "\t\tlctypes[$i]={$arrTypes[$i]};\n";
		$defvar .= "\t\tlctitles[$i]=\"$titrechamp\";\n";
		$defvar .= "\t\tlcnulls[$i]={$arrNulls[$i]};\n";
		$defvar .= "\t\tlctailles[$i]={$arrTailles[$i]};\n";
		$i++;
	}

	//Maintenant on va definir la fonction qui vont verifier la validite du formulaire d'insertion
	$defvar .= "\tfunction generalVF(fname){//Verifie un formulaire generique dont le nom est passer en parametres et les \n";
	$defvar .= "\t//champs sont déja declarer dans des tableaux via php\n";

	$defvar .= "\t\t	var valeur;//la valeur preciser du champ\n";
	$defvar .= "\t\t	var tit;//Le titre placer devant le champ\n";
	$defvar .= "\t\t	var taille;//La taille du champ\n";
	$defvar .= "\t\t	var typechamp;//Le type du champ\n";
	$defvar .= "\t\t	var nomchamp;//Le type du champ\n";
	$defvar .= "\t\t	var champnull;//Le type du champ\n";
	$defvar .= "\t\t	var numChamp,longeur;//Le numero du champ selon l'ordre d'appartition dans le formulaire\n";
	$defvar .= "\t\t	var ajoutChamp=2;//Le nombre de champs ajouter dans le formulaire \n";
	$defvar .= "\tfor(var i=0;i<lc.length;i++){\n";
	$defvar .= "\t\t	numChamp=i;\n";
	$defvar .= "\t\t	nomchamp=document.forms[fname].elements[numChamp+ajoutChamp];//la valeur preciser du champ\n";
	$defvar .= "\t\t	//confirm('on est a '+nomchamp.name+' valeur '+nomchamp.value);\n";
	$defvar .= "\t\t	tit=lctitles[i];//Le titre placer devant le champ\n";
	$defvar .= "\t\t	taille=lctailles[i];//La taille du champ\n";
	$defvar .= "\t\t	typechamp=lctypes[i];//Le type du champ\n";
	$defvar .= "\t\t	champnull=lcnulls[i];//Les champ  qui peuvent etre null\n";
	$defvar .= "\t\t	//confirm('on est a '+tit+' valeur '+nomchamp.value+' est null ? 0 => non null '+lcnulls[i]);\n";
	$defvar .= "\t\t	if(lcnulls[i] == 0){\n";//Le champ ne doit pas etre vide donc obligatoire
	$defvar .= "\t\t\t		if( lctypes[i] == 0 && !isInteger(nomchamp.value)  ){\n";//Senser etre un entier mais ne l'est pas
	$defvar .= "\t\t\t			confirm(\"Le champ \"+tit+\" n'est pas numerique \");\n";
	$defvar .= "\t\t\t			return false;\n\t\t\t\tbreak;\n";
	$defvar .= "\t\t\t		}\n";
	$defvar .= "\t\t\t		if( nomchamp.value == \"\" ){\n";//Senser etre une chaine obligatoire mais elle est vide
	$defvar .= "\t\t\t			confirm(\"Preciser le champ \"+tit+\".\");\n";
	$defvar .= "\t\t\t			return false;\n\t\t\t\tbreak;\n";
	$defvar .= "\t\t\t		}\n";
	$defvar .= "\t\t	}\n";//Le champ peut etre vide	$defvar .= "\t}\n";
	$defvar .= "\t\treturn true ;\n";
	$defvar .= "\t}\n";
	$defvar .= "}\n";
	echo $defvar ;
	echo "</script>";

	?>

