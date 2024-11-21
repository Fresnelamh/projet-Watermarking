#include <iostream>
#include <opencv2/opencv.hpp> // Inclure le bon header OpenCV avec .hpp
#include <bitset>

using namespace std;
using namespace cv;

int main() 
{
    cout << "PARTIE TEXTE" << endl;
    string message; // Déclaration de la variable "message"

    cout << "Bonjour, entrez un message : "; // Correction de l'affichage
    cin >> message;

    int n = message.size(); // Obtenir la taille du message

    int* array = new int[n]; // Utiliser un tableau dynamique pour stocker les valeurs ASCII
    bitset<8>* array_binary = new bitset<8>[n]; // Déclaration du tableau pour les binaires

    // Boucle pour convertir chaque caractère en sa valeur ASCII
    for (int i = 0; i < n; i++) {
        array[i] = int(message[i]);
    }

    cout << "Valeurs du tableau en ASCII" << endl;
    // Affichage des valeurs ASCII
    for (int i = 0; i < n; i++) {
        cout << array[i] << endl;
    }

    // Conversion de la chaîne en ASCII en binaire
    for (int i = 0; i < n; ++i) {
        array_binary[i] = bitset<8>(array[i]);
    }

    // Affichage du tableau de façon horizontale
    cout << "Valeurs du tableau en binaire" << endl;
    for (int i = 0; i < n; ++i) {
        cout << array_binary[i] << " ";
    }
    cout << endl;

    delete[] array; // Libérer la mémoire allouée pour le tableau dynamique
    delete[] array_binary;

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

    // Stocker les valeurs de l'image en décimal dans un tableau
    int rows = image.rows;
    int cols = image.cols;
    int channels = image.channels();

    // Créer un tableau dynamique pour stocker les valeurs en décimal
    int* array_decimal_image = new int[rows * cols * channels];
    bitset<8>* array_image_binary = new bitset<8>[rows * cols * channels];

    // Parcourir l'image et remplir les tableaux
    int index = 0;
    cout << "Valeurs de l'image en décimal :" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Vec3b pixel = image.at<Vec3b>(i, j); // Accéder au pixel (BGR)
            array_decimal_image[index] = pixel[0]; // Bleu
            array_image_binary[index] = bitset<8>(pixel[0]);
            index++;

            array_decimal_image[index] = pixel[1]; // Vert
            array_image_binary[index] = bitset<8>(pixel[1]);
            index++;

            array_decimal_image[index] = pixel[2]; // Rouge
            array_image_binary[index] = bitset<8>(pixel[2]);
            index++;

            // Afficher les valeurs BGR
            cout << "[" << int(pixel[0]) << ", " << int(pixel[1]) << ", " << int(pixel[2]) << "] ";
        }
        cout << endl;
    }

    // Afficher les valeurs binaires de l'image
    cout << "Valeurs de l'image en binaire :" << endl;
    for (int i = 0; i < rows * cols * channels; ++i) {
        cout << array_image_binary[i] << endl;
    }

    delete[] array_decimal_image; // Libérer la mémoire allouée pour le tableau dynamique
    delete[] array_image_binary;

    return 0;
}
