#include "Cellule.h"
#include "LibGraph2.h"
#include "Diagramme.h"


// Fonction pour afficher les cellules ClaireFonce
void CDiagramme::DrawCellule(CCellule::pCellule& pCellule) {
    LibGraph2::CRectangle rect(LibGraph2::CPoint(pCellule->GetX(), pCellule->GetY()), LibGraph2::CSize{ 70, 7 });
    pLibgraph->setPen(LibGraph2::MakeARGB(255, 0, 0, 0), 1.0f);
    pCellule->SetColor();
    switch (pCellule->GetColor()) {
    case 0:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 128));
        break;
    case 1:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 255));
        break;
    case 2:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 135, 206, 250));
        break;
    case 3:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 173, 216, 230));
        break;
    case 4:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 176, 224, 230));
        break;
    case 5:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 192, 203));
        break;
    case 6:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 160, 122));
        break;
    case 7:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 0, 0));
        break;
    case 8:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 255, 0));
        break;
    default:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(30, 30, 30, 153));
        break;
    }

    pLibgraph->drawRectangle(rect);    
}

// Fonction pour afficher les cellules MoyenneParMoi
void CDiagramme::DrawCelluleBis(CCellule::pCellule& pCellule) {
    LibGraph2::CRectangle rect(LibGraph2::CPoint(pCellule->GetX(), pCellule->GetY()), LibGraph2::CSize{ 70, 7 });
    pLibgraph->setPen(LibGraph2::MakeARGB(255, 0, 0, 0), 1.0f);
    switch (pCellule->GetColor()) {
    case 0:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 128));
        break;
    case 1:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 255));
        break;
    case 2:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 135, 206, 250));
        break;
    case 3:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 173, 216, 230));
        break;
    case 4:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 176, 224, 230));
        break;
    case 5:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 192, 203));
        break;
    case 6:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 160, 122));
        break;
    case 7:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 0, 0));
        break;
    case 8:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 255, 0));
        break;
    default:
        pLibgraph->setSolidBrush(LibGraph2::MakeARGB(30, 30, 30, 153));
        break;
    }
    pLibgraph->drawRectangle(rect);
}

/*
Affiche toute les cellules (mois) en fonction de certain degres de température.
*/
void CDiagramme::ClaireFonce()
{
    int x = 100;
    int y = 50;
    pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
    // Affiche le nom des mois
    for (size_t a = 0; a < 12; a++) {
        pLibgraph->drawString(GetMoisMot(a), LibGraph2::CPoint(x,y));
        x += 70;
    }

    x = 40;
    y = 70; 
    
    for (size_t u = 0; u < data.size() - 12;) {
        // Affiche les années
        if (data[u]->_annee % 5 == 0) {
            pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
            pLibgraph->drawString(std::to_string(data[u]->_annee), LibGraph2::CPoint(x, y));
        }
        x += 60;
        for (size_t i = 0; i < 12; i++) {
            // Cas général
            if (data[u]->_mois == i + 1) {
                data[u]->SetX(x);
                data[u]->SetY(y);
                DrawCellule(data[u]);
                u++;
            }
            // Cas ou il y a pas de donnée
            else if (data[u]->_mois != data[u - 1]->_mois + 1 || data[u]->_mois != data[u + 1]->_mois - 1) {
                u++;
            }

            x += 70; // Largeur de chaque cellule
        }
        x = 40;
        y += 7; // Décalage vertical entre les lignes
    }
}

/*
Affiche en dessous du Diagramme les information sur la cellule cliqué 
*/
void CDiagramme::AfficherDataCF(unsigned int x, unsigned y) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i]->GetX() >= x && data[i]->GetX() < x + 70 && data[i]->GetY() >= y && data[i]->GetY() < y + 7) {
            std::string texte = "En " + std::to_string(data[i]->_annee) + " pendant le mois de " + GetMoisMot(data[i]->_mois) + " il faisait en moyenne " + std::to_string(data[i]->_tempMois);
            
            pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 255, 255));
            pLibgraph->drawRectangle(LibGraph2::CRectangle(LibGraph2::CPoint(250, 959),LibGraph2::CSize(500,20)));
            
            pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
            pLibgraph->drawString(texte, LibGraph2::CPoint(300,960));
        }
    }
}

/*
Permet davoir le mois en string pour l'afficher apres
*/
std::string CDiagramme::GetMoisMot(int pos)
{
    switch (data[pos]->_mois)
    {
    case 1:
        return "Janvier";
        break;
    case 2:
        return "Fevrier";
        break;
    case 3:
        return "Mars";
        break;
    case 4:
        return "Avril";
        break;
    case 5:
        return "Mai";
        break;
    case 6:
        return "Juin";
        break;
    case 7:
        return "Juillet";
        break;
    case 8:
        return "Aout";
        break;
    case 9:
        return "Septembre";
        break;
    case 10:
        return "Octobre";
        break;
    case 11:
        return "Novembre";
        break;
    case 12:
        return "Decembre";
        break;
    default:
        break;
    }
}

/*
Affiche les aides
*/
void Help()
{
    LibGraph2::GetLibGraph2()->guiMessageBox("Aide", "Commandes claviers :\n"
        "A :  Afficher clair/fonce\n"
        "V :  Varitions des normales mensuels\n"
        "M : menu\n"
        "F1 : Affiche cette aise", LibGraph2::msgbtn_types::MsgBtnOK, LibGraph2::msgicon_types::MsgIcnInformation);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
Affiche toute les cellules avec une couleur allant du bleu au rouge 
en fonction de si elle est tant plus chaude ou tant plus froide que la moyenne général du moi concerné.
*/
void CDiagramme::MoyenneParMoi()
{
    // Parcour tous le vecteur pour stoker les température du mois et calculer la moyenne de temperature pour un mois
    for (size_t u = 0; u < data.size() - 12;) {
        for (size_t i = 0; i < 12; i++) {
            if (data[u]->_mois == i + 1) {
                MoyenneDesMois[i] += data[u]->_tempMois;
                u++;
            }
            // Dans le cas ou un mois n'as pas de donnée alors on prend la donnée du meme mois de l'année derniere (comme beaucoup de valeur cette legere aproximation permet de facilité les calcule pour la moyenne sans focer les resultat)
            else if (data[u]->_mois != data[u - 1]->_mois + 1 || data[u]->_mois != data[u + 1]->_mois - 1) {
                MoyenneDesMois[i] += data[u - 12]->_tempMois;
                u++;
            }
        }
    }
    for (size_t i = 0; i < 12; i++) {
        MoyenneDesMois[i] = MoyenneDesMois[i] / 126; // divisé par le nombre d'année
    }

    // A partir de la c est la meme fonction que DrawCellule a une exeption pres
    int x = 100;
    int y = 50;
    pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));

    for (size_t a = 0; a < 12; a++) {
        pLibgraph->drawString(GetMoisMot(a), LibGraph2::CPoint(x, y));
        x += 70;
    }

    x = 40;
    y = 70;

    for (size_t u = 0; u < data.size() - 12;) {
        if (data[u]->_annee % 5 == 0) {
            pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 0, 0, 0));
            pLibgraph->drawString(std::to_string(data[u]->_annee), LibGraph2::CPoint(x, y));
        }
        x += 50;
        for (size_t i = 0; i < 12; i++) {

            if (data[u]->_mois == i + 1) {
                data[u]->SetX(x);
                data[u]->SetY(y);

                // L'exeption est ici car on arrivés pas a adapter la fonction SetColor 
                // A cause du fait que vous m'ayez dis de maitre mon array en privé
                
                if ((data[u]->_tempMois >= MoyenneDesMois[i] - 10) && (data[u]->_tempMois < MoyenneDesMois[i] - 6))
                    data[u]->m_Color = 0;

                else if ((data[u]->_tempMois >= MoyenneDesMois[i] - 6) && (data[u]->_tempMois < MoyenneDesMois[i] - 3))
                    data[u]->m_Color = 1;

                else if ((data[u]->_tempMois >= MoyenneDesMois[i] - 3) && (data[u]->_tempMois < MoyenneDesMois[i] - 1))
                    data[u]->m_Color = 2;

                else if ((data[u]->_tempMois >= MoyenneDesMois[i] - 1) && (data[u]->_tempMois <= MoyenneDesMois[i]))
                    data[u]->m_Color = 3;

                else if ((data[u]->_tempMois > MoyenneDesMois[i]) && data[u]->_tempMois <= MoyenneDesMois[i] + 0.5)
                    data[u]->m_Color = 4;

                else if ((data[u]->_tempMois > MoyenneDesMois[i] + 0.5) && (data[u]->_tempMois <= MoyenneDesMois[i] + 1))
                    data[u]->m_Color = 5;

                else if ((data[u]->_tempMois > MoyenneDesMois[i] + 1) && (data[u]->_tempMois <= MoyenneDesMois[i] + 3))
                    data[u]->m_Color = 6;

                else if ((data[u]->_tempMois > MoyenneDesMois[i] + 3) && (data[u]->_tempMois <= MoyenneDesMois[i] + 8))
                    data[u]->m_Color = 7;

                else
                    data[u]->m_Color = 8;

                DrawCelluleBis(data[u]);
                u++;
            }
            else if (data[u]->_mois != data[u - 1]->_mois + 1 || data[u]->_mois != data[u + 1]->_mois - 1) {
                u++;
            }
            x += 70; // Largeur de chaque cellule
        }
        x = 40;
        y += 7; // Décalage vertical entre les lignes
    }


}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


