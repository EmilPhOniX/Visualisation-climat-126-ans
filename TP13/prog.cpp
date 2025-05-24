#define NOMINMAX
#include <Windows.h>
#include <tchar.h>

#include "cellule.h"
#include "Diagramme.h"
#include "DataReader.h"

#include <chrono>
#define LIBGRAPH2_LEVEL 4
#include <LibGraph2.h>
using namespace LibGraph2;

#include <iostream>
using namespace std;

int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //Affiche la fenêtre graphique avec une taille par défaut
    ILibGraph2* pLibgraph = GetLibGraph2();
    pLibgraph->show(CSize{ 1000, 1000 });

    //Boucle principale d'événements
    evt e;
    bool bShowDisk = true;
    bool CF = false;
    auto tpStartBounce = chrono::high_resolution_clock::now();

    CDiagramme Diagramme(pLibgraph);

    float y = 0; // Position verticale initiale
    float x = 0; // Position horizontale initiale
    while (pLibgraph->waitForEvent(e))
    {
        switch (e.type)  //En fonction du type du dernier événement
        {
        case evt_type::evtRefresh:  //Raffraichissement de l'affichage (tout redessiner)
            //Utiliser éventuellement les fonctions beginPaint() / endPaint() pour activer le backbuffer
            pLibgraph->beginPaint();
            //Utiliser ici les fonctions de dessins
            pLibgraph->drawBitmap("menu.png", CPoint(0, 0));
            pLibgraph->endPaint();
            break;

        case evt_type::evtKeyDown:  //Enfoncement d'une touche
            switch (e.vkKeyCode) //En fonction de la touche enfoncée
            {
            case 'A':
                // Affiche le Diagramme ClaireFonce
                pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 255, 255));
                pLibgraph->drawRectangle(LibGraph2::CRectangle(LibGraph2::CPoint(0, 0), LibGraph2::CSize(1000, 1000)));
                Diagramme.ClaireFonce();
                CF = true;
                break;
            case 'V':
                // Affiche le Diagramme MoyenneParMoi mais pas correct
                pLibgraph->setSolidBrush(LibGraph2::MakeARGB(255, 255, 255, 255));
                pLibgraph->drawRectangle(LibGraph2::CRectangle(LibGraph2::CPoint(0, 0), LibGraph2::CSize(1000, 1000)));
                Diagramme.MoyenneParMoi();
                CF = true;
                break;

            case 'M':
                // Permet de revenir au menu
                CF = false;
                pLibgraph->drawBitmap("menu.png", CPoint(0, 0));
                break;
            case VK_F1:
                Help();
                break;
            }
            break;

        case evt_type::evtMouseDown:  //Déplacement de la souris
            // Permet d'afficher les donnée de la cellule selectionné
            if (CF) {
                Diagramme.AfficherDataCF(e.x, e.y);
            }
            break;
        }
    }

    ReleaseLibGraph2();
    return 0;
}
