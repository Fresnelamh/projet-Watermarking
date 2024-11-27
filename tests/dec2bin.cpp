#include <vector>
#include <iostream>
using namespace std;

// Fonction pour convertir un tableau de nombres décimaux en binaire
/*int decimalToBinary(int arr[][1], int nbre_lignes)  // ajout du 25/11/2024
{
    int array_binary[nbre_lignes][8] = {0}; // on met le tableau 0 pour etre sur qu'il ne contient pas de valeur à l'intérieur.

    for (int i = 0; i < nbre_lignes; i++)
    {
        int poids = 7; // ici on initialise le poids
        int valeur_decimal = arr[i][0]; // Récupérer la valeur décimale

        while (valeur_decimal > 0)
        {
            array_binary[i][poids] = valeur_decimal % 2; // Calcul du bit de poids faible
            valeur_decimal /= 2; // Division par 2
            poids--; // Aller au bit suivant mais de la droite vers la gauche
        }
    }

    // Affichage des résultats
    //cout << "Conversion des nombres décimaux en binaire :\n";
    /*for (int i = 0; i < nbre_lignes; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << array_binary[i][j];
        }
        cout << endl;
    }

    return array_binary ; //ajout du 25/11/2024*/

// ajout du 25/11/2024

/*int** decimalToBinary(int arr[][1], int nbre_lignes) // Changez le type de retour
        {
    int** array_binary = new int*[nbre_lignes];
    for (int i = 0; i < nbre_lignes; i++) {
        array_binary[i] = new int[8]{0}; // Allouer chaque ligne et initialiser à 0

        int poids = 7; // Initialisation du poids
        int valeur_decimal = arr[i][0]; // Récupérer la valeur décimale

        while (valeur_decimal > 0) {
            array_binary[i][poids] = valeur_decimal % 2; // Calcul du bit de poids faible
            valeur_decimal /= 2; // Division par 2
            poids--; // Aller au bit suivant mais de la droite vers la gauche
        }
    }

    return array_binary; // Retourne le tableau alloué dynamiquement
}*/



/*vector<vector<int>> decimalToBinary(int arr[][1], int nbre_lignes) {
    vector<vector<int>> array_binary(nbre_lignes, vector<int>(8, 0));

    for (int i = 0; i < nbre_lignes; i++) {
        int poids = 7;
        int valeur_decimal = arr[i][0];

        while (valeur_decimal > 0) {
            array_binary[i][poids] = valeur_decimal % 2;
            valeur_decimal /= 2;
            poids--;
        }
    }

    return array_binary;
}

*/

vector<vector<int>> decimalToBinary(const vector<int>& arr) {
    int nbre_lignes = arr.size(); // Taille du vecteur d'entrée
    vector<vector<int>> array_binary(nbre_lignes, vector<int>(8, 0)); // Initialisation du tableau binaire

    for (int i = 0; i < nbre_lignes; i++) {
        int poids = 7; // Poids pour remplir de droite à gauche
        int valeur_decimal = arr[i]; // Récupérer la valeur décimale

        while (valeur_decimal > 0) {
            array_binary[i][poids] = valeur_decimal % 2; // Récupération du bit de poids faible
            valeur_decimal /= 2; // Division par 2
            poids--; // Aller au bit suivant
        }
    }

    return array_binary;
}


// pour tester la fonction 
/*int main() 
{
    // Définir un tableau de nombres décimaux à convertir
    int nbre_lignes = 4; // Nombre de lignes dans le tableau
    int arr[4][1] = { {13}, {45}, {7}, {128} }; // Nombres à convertir en binaire
    
    // Appeler la fonction pour effectuer la conversion
    decimalToBinary(arr, nbre_lignes);

    return 0;
}
*/
