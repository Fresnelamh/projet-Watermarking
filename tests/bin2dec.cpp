#include <iostream>
#include <cmath> // pour utiliser la fonction puissance

using namespace std;
using namespace cv ;


vector<int> binaryToDecimal(const Mat& binaryMatrix) {
    // Vérifier si la matrice est non vide
    if (binaryMatrix.empty()) {
        throw invalid_argument("La matrice binaire est vide !");
    }

    int nbre_lignes = binaryMatrix.rows; // Nombre de lignes dans la matrice
    int nbre_colonnes = binaryMatrix.cols; // Nombre de colonnes dans la matrice

    // Vérifier que chaque ligne a 8 colonnes (binaire standard)
    if (nbre_colonnes != 8) {
        throw invalid_argument("Chaque ligne de la matrice doit contenir exactement 8 bits !");
    }

    // Initialisation du vecteur des valeurs décimales
    vector<int> decimalArray(nbre_lignes, 0);

    for (int i = 0; i < nbre_lignes; i++) {
        int decimalValue = 0; // Initialisation de la valeur décimale pour la ligne actuelle
        int poids = 7; // Poids (pour un vecteur binaire de taille 8)

        for (int j = 0; j < nbre_colonnes; j++) { // Parcourir les colonnes de la ligne
            int bit = binaryMatrix.at<int>(i, j); // Récupérer le bit
            decimalValue += bit * pow(2, poids); // Ajouter la contribution du bit au résultat
            poids--; // Réduire le poids pour le prochain bit
        }

        decimalArray[i] = decimalValue; // Stocker la valeur décimale
    }

    return decimalArray;
}




/*
int main()
{
     // Définir un tableau binaire à convertir en décimal

    vector<vector<int>> binaryArray = {
        {0, 1, 1, 0, 0, 1, 0, 1}, // Binaire pour 101
        {1, 0, 0, 0, 0, 0, 1, 1}  // Binaire pour 131
    };

    // Appeler la fonction pour convertir en décimal
     vector<int> decimalArray = binaryToDecimal(binaryArray);


          return 0;
     
}
