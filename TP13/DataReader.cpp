#include "DataReader.h"

std::vector<CCellule::pCellule> getFichier(const std::string& filename)
{
    std::vector<CCellule::pCellule> datas;
    std::ifstream fichier(filename);
    if (!fichier) {
        std::cerr << "Erreur d'ouverture du fichier " << filename << std::endl;
    }

    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::istringstream iss(ligne);
        std::string annee;

        std::getline(iss, annee, ';');
        std::string mois = annee.substr(4);
        annee = annee.substr(0, 4);
        std::string temperature;
        std::getline(iss, temperature, ';');
        CCellule::pCellule Cel = std::make_shared<CCellule>(stoi(mois), stoi(annee), stod(temperature));

        datas.push_back(Cel);
    }
    return datas;
}

void afficherDonnees(std::vector<CCellule::pCellule> data) {
    for (auto& pCel : data)
        std::cout << pCel->_mois << " " << pCel->_annee << " " << pCel->_tempMois << "\n";
}