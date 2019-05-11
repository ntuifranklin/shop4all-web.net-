<?php 
function reduction ($image){   
$dim=getimagesize($image);   
$pixmaxi=200; //on fixe ici la taille maximum souhaitée.  

$hauteur=$dim[1];   
$largeur=$dim[0];   

if ($largeur>$pixmaxi) // on agit sur la largeur dans ce cas  
{   
$reduire=$pixmaxi/$largeur;   
$largeur=$pixmaxi;   
$hauteur=ceil($hauteur*$reduction);   
}   
if (file_exists($image))  
{   
echo '<img src="',$image,'" heigth="',$hauteur,'" width="',$largeur,'">';   
} else {   
echo 'Image non disponible';   
}   
} 
// à l'endroit de l'affichage, on appele la fonction  
echo '....blabla...';   
// attention, pas de ' dans cet echo  
echo reduction($image);   

echo '....blabla...';   

?> 
