
<?php
if(sessionExists()){//Si le user est connecter 
        //Page qui affiche un menu pour le user
        echo "<table>";
        echo "<tr>" ; 
        //Premiere colonne , on affichera un menu dans un tableau, et la deuxieme colonne la liste de ses insertions
                //Premiere colonne : le tableau contenant menu
                echo "<td>";
                        $u = new User();
                        echo $u -> getUserMenu() ;
                echo "</td>";
                //Deuxieme colonne : le tableau contenant les insertions
                //S'il n'ya pas les insertions alors on affiche une ou  deux annonces
              
        echo "</tr>";
        echo "</table>";
}

?>

        </td>
        <!-- Fin barre de navi gauche-->
        <!-- Debut partie centrale-->
        <td  align="left" valign="top" >
        <div align="center">
