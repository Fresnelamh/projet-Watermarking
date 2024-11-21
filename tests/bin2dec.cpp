#include <iostream>
#include <cmath> // pour utiliser la fonction puissance

using namespace std;

// Fonction pour convertir un nombre décimal en binaire

void binarytodecimal(int array_binary [][8], int nombre_lignes) 
{

    
     for (int i = 0; i < nombre_lignes; i++)
     {
          int decimal = 0; // ici on initialise le compteur 
          
          // parcours les bits de chaque lignes 
          // j ici c'est le poids 

          for (int j = 0; j < 8; j++)
          {
               decimal += array_binary[i][j] * pow (2, 7-j) ;
          }

          // ici on affiche la convertion 
          for (int j=0 ; j<8; j++)
          {
               cout << array_binary[i][j] ;

          }

          cout << "---> Decimal = "  << decimal <<endl ;
     }
}



/*int main()
{
     int array_binary [4][8] = {
          {1}, {1,0,1,0},{1,0,1,1,0,1} ,{1,0,0,0,1,1,0}
     };
     int nombre_lignes = 4 ;

     binarytodecimal(array_binary, nombre_lignes) ;

          return 0;
     
}
