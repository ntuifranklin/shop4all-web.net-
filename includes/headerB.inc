

</head>
<body>
<div id="imSite">
<div id="imHeader">
	
	<h1>Shop4all</h1>
</div>
<div class="imInvisible">
<hr />
<a href="#imGoToCont" title="Aller au menu de navigation">Aller au contenu</a>
</div>
<div id="imBody">
	<div id="imMenuMain">

<!-- Menu START -->
<a name="imGoToMenu"></a><p class="imInvisible">Menu principal:</p>
<div id="imMnMn">
<ul>
        <!-- 
                The below was the initial code :

	        <li><a class="imMnItm_1" href="index.html" title=""><span class="imHidden">Accueil</span></a></li>
	        <li><a class="imMnItm_2" href="les_annonces.html" title=""><span class="imHidden">Les annonces</span></a></li>
	        <li><a class="imMnItm_3" href="insertion.html" title=""><span class="imHidden">Insertion</span></a></li>
	        <li><a class="imMnItm_4" href="mon_shop.html" title=""><span class="imHidden">Mon Shop</span></a></li>
	        <li><a class="imMnItm_5" href="aide.html" title=""><span class="imHidden">Aide</span></a></li>
                
                Replaced by the following code, so that each page may have it's body title , used by $_GET['tit'] some lines below:
        -->

	        <li><a class="imMnItm_1" href="index.php?tit=Acceuil" title="Aller &agrave; la page d'acceuil"><span class="imHidden">Accueil</span></a></li>
	        <li><a class="imMnItm_2" href="les_annonces.php?tit=Les+annonces" title="Les annonces r&eacute;centes"><span class="imHidden">Les annonces</span></a></li>
	        <li><a class="imMnItm_3" href="insertion.php?tit=Nouvelle insertion" title="Faire une nouvelle insertion"><span class="imHidden">Insertion</span></a></li>
	        <li><a class="imMnItm_4" href="mon_shop.php?tit=Mon+shop" title="Vos insertions effectuer et vos informations personnelles"><span class="imHidden">Mon Shop</span></a></li>
	        <li><a class="imMnItm_5" href="aide.php?tit=Aide" title="Outil d'aide &agrave; la navigation sur ce site"><span class="imHidden">Aide</span></a></li>
</ul>
</div>
<!-- Menu END -->

	</div>
<hr class="imInvisible" />
<a name="imGoToCont"></a>
	<div id="imContent">

<!-- Page START -->
<h2><?php echo $_GET['tit']?></h2>
<div id="imPage">

<div id="imCel7_01">
<div id="imCel7_01_Cont">
	<div id="imObj7_01">
<!-- Debut Barner -->
