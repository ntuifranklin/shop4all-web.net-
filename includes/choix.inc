<?php
                        echo "<form action='formulaire.php' method=post name='choi' onSubmit=\" return ck2();\">";
                        echo "<table>";
                        echo "<caption>Choisissez la rubrique dans laquelle vous voulez effectuer votre insertion</caption>";
                       
                        echo "<tr>"; 
                        echo "<td>";
                        $nom = "Vous : ".getDropDownObjTyp("objtyp" , $objtyp) ;
                        echo $nom ;
                       
                        echo "</td>";
                        /*
                        echo "</tr>";
                        echo "<tr>"; 
                        */
                        echo "<td>";
                        echo " un objet/des services";
                        echo "</td>";
                        /*
                        echo "</tr>";
                        echo "<tr>"; 
                        */
                        echo "<td>";
                        $nom = "norubr"; $options = getT() ; $selected = 1 ; 
                        echo "dans la rubrique  "; 
                        echo "</td>";
                        /*
                        echo "</tr>";
                        echo "<tr>"; 
                        */
                        echo "<td>";
                                echo dropdown2($nom,$options,1);
                        echo "</td>";
                        echo "</tr>";
                        echo "<tr>"; 
                        echo "<td colspan=5>";
			echo "Choisir la province au quel appartient ta ville" ;
                               $p = new Province() ;
			       echo $p -> getDropDownProvinces("provid") ;//Pour le choix de la provinces
                        echo "</td>";
                        echo "</tr>";
                        echo "<tr>"; 
                        echo "<td colspan=5 align=center>";
                        echo "<input type=submit id='imSButton' name='choix' value='continuer' >";
                        echo "</td>";
                        echo "</tr>";
                        echo "</table>";
                        echo "</form>";

?>
