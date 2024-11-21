#include <iostream>
#include <opencv2/opencv.hpp>
#include <bitset>
#include <string>

using namespace cv;
using namespace std;

int main() {
    int choix;
    cout << "0 : Cryptage / 1 : Décryptage - ";
    cin >> choix;

    if (choix == 0) {  // Cryptage
        string message;
        cout << "Entrez le message à cacher : ";
        cin.ignore();
        getline(cin, message);

        string imageName;
        cout << "Ecrivez le nom de l'image qui accueillera le texte : ";
        cin >> imageName;

        Mat image = imread(imageName);  // Charge l'image
        if (image.empty()) {
            cerr << "Erreur : impossible d'ouvrir l'image." << endl;
            return 1;
        }

        int width = image.cols;
        int height = image.rows;
        cout << "Dimensions de l'image : " << width << "x" << height << endl;

        // Convertir le message en binaire
        string binaryMessage;
        for (char c : message) {
            binaryMessage += bitset<8>(c).to_string();
        }
        cout << "Message binaire: " << binaryMessage << endl;

        // Création de l'image de sortie
        Mat image_finale = image.clone();
        int messageIndex = 0;
        int messageLength = binaryMessage.length();

        // Parcourir chaque pixel et insérer les bits du message
        for (int y = 0; y < height && messageIndex < messageLength; y++) {
            for (int x = 0; x < width && messageIndex < messageLength; x++) {
                Vec3b &pixel = image_finale.at<Vec3b>(y, x);
                
                // Modifie le bit de poids faible de la composante rouge pour chaque bit du message
                if (binaryMessage[messageIndex] == '1') {
                    pixel[2] |= 1;  // Met le LSB à 1 si le bit du message est '1'
                } else {
                    pixel[2] &= ~1;  // Met le LSB à 0 si le bit du message est '0'
                }
                messageIndex++;
            }
        }

        // Sauvegarde l'image avec le message caché
        imwrite("Image_finale.png", image_finale);
        cout << "Message caché dans l'image avec succès." << endl;

        // Affiche l'image (nécessite un environnement graphique)
        imshow("Image finale", image_finale);
        waitKey(0);
    }

    return 0;
}
