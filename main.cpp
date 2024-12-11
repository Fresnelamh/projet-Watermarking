#include <opencv2/opencv.hpp>
#include "/home/johan/Documents/Watermark/tests/naomie.cpp"
#include "/home/johan/Documents/Watermark/tests/dec2bin.cpp"
#include "/home/johan/Documents/Watermark/tests/fresnel.cpp"
#include "/home/johan/Documents/Watermark/tests/lsbmodify.cpp"
#include "/home/johan/Documents/Watermark/tests/bin2dec.cpp"
#include "/home/johan/Documents/Watermark/tests/audiotodecimal.cpp"

using namespace std;
using namespace cv;

int main() {



    cout << "=== Menu Principal ===" << endl;
    cout << "1. Cacher une image dans une image" << endl;
    cout << "2. Cacher un fichier audio dans une image" << endl;
    //cout << "3. Option 3" << endl;
    cout << "0. Quitter" << endl;
    cout << "======================" << endl;
    cout << "Entrez votre choix : ";

    int choix ; 
    cin >> choix;

    switch (choix)
    {

        case 1:
            /* Étape 1 : Extraction des valeurs de l'image à cacher */

        vector<int> imhide = extrairePixelValues("/home/johan/Documents/Watermark/Images/titre.jpeg");

        // Conversion en valeurs binaires (tableau binaire)
        //vector<vector<int>> binaryval = decimalToBinary(imhide);ajout code ce matin 25/11/2024
        vector<vector<int>> binaryval= decimalToBinary(imhide) ;
        // conversion tab---> mat

        Mat binaryMatHide = Mat(binaryval.size(), binaryval[0].size(), CV_32S);
        for (int i = 0; i < binaryval.size(); ++i) {
            for (int j = 0; j < binaryval[i].size(); ++j) {
                binaryMatHide.at<int>(i, j) = binaryval[i][j];
            }
        }


        // Transformation du tableau binaire en une matrice colonne unique
        Mat uniqueColumn = bintocol(binaryMatHide);

        /* Étape 2 : Extraction des valeurs de l'image hôte */
        vector<int> imhote = extrairePixelValues("/home/johan/Documents/Watermark/Images/top-section-bg.jpeg");

        int tabhote = imhote.size();
    
        // Conversion en valeurs binaires (tableau binaire)
       //vector<vector<int>> binaryval = decimalToBinary(imhide);ajout code ce matin 25/11/2024
        vector<vector<int>> binvalhote= decimalToBinary(imhote);
        // conversion tab---> mat

        // Transformation du tableau binaire de l'image hôte en matrice OpenCV
        Mat binaryMatHote = Mat(binvalhote.size(), binvalhote[0].size(), CV_32S);
        for (int i = 0; i < binvalhote.size(); ++i) {
            for (int j = 0; j < binvalhote[i].size(); ++j) {
                binaryMatHote.at<int>(i, j) = binvalhote[i][j];
            }
        }

        //Étape 3 : Remplacement des bits LSB 
        Mat modifiedBitsValues = lsbreplace(uniqueColumn, binaryMatHote);

        //Étape 4 : Reconstruction de l'image modifiée 
        // Reconstruction de l'image à partir des valeurs binaires modifiées avec la fonction de Christian ensuite celle de Naomi sur le résiultat de cette fonction
         vector<int> decimalArray = binaryToDecimal(modifiedBitsValues);

        //Extraction de l'image cachée




         break ; 

     case 2:
        //vector<int> audiohide =  extraireDecimalValuesAudio("chemin d'acces de l'audio") ;


        break ;

    case 0:
        cout << "Quitter le programme..." << endl;
        return 0;

    default:
        cout << "Choix invalide, réessayez." << endl;
        break;

    }

    return 0;

}
