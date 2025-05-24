#pragma once
#include <memory>

struct CCellule {
    int _mois;
    int _annee;
    float _tempMois;
    int m_Color; // def la couleur de la cellule

    float m_PosX = 0; // abcisse du noeud 
    float m_PosY = 0; // ordonnée du noeud

    using pCellule = std::shared_ptr<CCellule>;
    static pCellule NewCellule(const int mois = 1, int an = 0, float tMoy = 0, int color =0); // Fonction pour ajouter des Cellule{ }

    CCellule(int mois = 0, int an = 0, float tMoy = 0, int color = 0) : _mois{ mois }, _annee{ an }, _tempMois{ tMoy }, m_Color{ color } {}
    
    float GetX()const { return m_PosX; } // renvoie l abscisse du noeud
    float GetY()const { return m_PosY; } // renvoie l ordonnee du noeud
    void SetX(float x) { m_PosX = x; } // modifie l abscisse du noeud 
    void SetY(float y) { m_PosY = y; } // modifie l abscisse du noeud 

    int GetColor() const { return m_Color; } 
    void SetColor(); // Pour donnée une couleur a la cellule par rapport a ça température
};






