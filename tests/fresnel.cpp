#include <opencv2/opencv.hpp> //Permet d'accéder à toutes les fonctionnalités principakes d'OpenCV y compris la manipulation d'images
#include <iostream>//Import de la bibliothèque iostream nécessaire pour les entrées /sorties standard comme l'affichage avec std:cout
using namespace cv;
using namespace std;

Mat bintocol (const Mat& tableauBinaire)
{ 
 


    // Transformer la matrice en une seule colonne avec reshape(1,...)


    Mat colonneUnique = tableauBinaire.reshape(1, tableauBinaire.rows * tableauBinaire.cols);
    

    //L'argument 1 signifie que chaque ligne de l'ancienne matrice sera transformée en une seule colonne
    // Afficher la matrice colonne unique


    
    
   

return colonneUnique ; 
 };