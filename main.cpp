#include <iostream>
#include <opencv2/opencv.hpp> // Inclure le bon header OpenCV avec .hpp
#include <bitset>

using namespace std;
using namespace cv;

int main() 
{
	cout << "PARTIE TEXTE" << endl ;
    string message; // Déclaration de la variable "message"

    cout << "Bonjour, entrez un message : "; // Correction de l'affichage
    cin >> message;

    int n = message.size(); // Obtenir la taille du message

    
    int* array = new int[n]; // Utiliser un tableau dynamique pour stocker les valeurs ASCII
     bitset<8>* array_binary = new bitset<8> [n] ;// declaration du tableau pour les binaires
   
    // Boucle pour convertir chaque caractère en sa valeur ASCII
    for (int i = 0; i < n; i++) 
    {
        array[i] = int(message[i]);
    }

		cout << "Valeurs du tableau en ASCII" << endl ;
		    // Affichage des valeurs ASCII
		    for (int i = 0; i < n; i++) {
		        cout << array[i] << endl;
		    }
		    // convertion de la chaine en ASCII en binaire 
		        for (int i = 0; i < n; ++i)
		    {
		    	array_binary[i] = bitset<8> (array[i]);
		    
		    }
		// affiche du tableau de facon horizontal
		    cout << "Valeurs du tableau en binaire" << endl ;
		    for (int i = 0; i < n; ++i)
		    {
		    	cout << array_binary[i] << "";
		    }
		    
		    cout << endl ; 



		    delete[] array; // Libérer la mémoire allouée pour le tableau dynamique
		    delete[] array_binary ;

		    cout << "PARTIE IMAGE" << endl;

		    string chemin;
		    cout << "Ecrivez le chemin d'accès de l'image: ";
		    cin.ignore();  // Ignorer le caractère de nouvelle ligne restant
		    std::getline(cin, chemin);

		    Mat image = imread(chemin, IMREAD_COLOR);

		    if (image.empty()) {
		        cout << "Impossible d'ouvrir ou de trouver l'image" << endl;
		        return -1;
		    }

		    imshow("Image", image);
		    waitKey(0);
		    // permet de lire et d'afficher l'image en decimal

		  

		    return 0;

}

   

