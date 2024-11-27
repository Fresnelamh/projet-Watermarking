#include <iostream>
#include <cmath> // pour utiliser la fonction puissance

using namespace std;

vector<int> binaryToDecimal(const vector<vector<int>>& binaryArray) {
    int nbre_lignes = binaryArray.size(); // Nombre de lignes (vecteurs binaires)
    vector<int> decimalArray(nbre_lignes, 0); // Initialisation du tableau des valeurs décimales

    for (int i = 0; i < nbre_lignes; i++) {
        int decimalValue = 0; // Initialisation de la valeur décimale pour la ligne actuelle
        int poids = 7; // Poids (pour un vecteur binaire de taille 8)

        for (int bit : binaryArray[i]) { // Parcourir les bits de la ligne
            decimalValue += bit * pow(2, poids); // Ajouter la contribution du bit au résultat
            poids--; // Réduire le poids pour le prochain bit
        }

        decimalArray[i] = decimalValue; // Stocker la valeur décimale
    }

    return decimalArray;
}


/*int binaryToDecimal(int array_binary[][8], int nbre_lignes) // ajout du 25/11/2024 (procedure ----> fonction)
{
    int array_decimal[nbre_lignes][1]; // Tableau pour stocker les valeurs décimales

    for (int i = 0; i < nbre_lignes; i++) 
    {
        int decimal = 0; // Initialiser la valeur décimale à 0 pour chaque ligne

        // ici on parcours chaque colonne du tableau binaire 
        for (int j = 0; j < 8; j++) 
        {
            decimal += array_binary[i][j] * pow(2, 7 - j); // a*2^poids
        }

        array_decimal[i][0] = decimal; // Stocker la valeur décimale dans le tableau

        // Affichage de la conversion
       // cout << "Binaire : ";
        for (int j = 0; j < 8; j++) 
        {
           // cout << array_binary[i][j];
        }
        cout  << decimal << endl;
    }

    return array_decimal;
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
