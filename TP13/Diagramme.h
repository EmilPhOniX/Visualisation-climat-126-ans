#pragma once
#include "cellule.h"
#include "DataReader.h"
#include "LibGraph2.h"
#include <array>

class CDiagramme
{
public:
	CDiagramme(LibGraph2::ILibGraph2* libgraph) { pLibgraph = libgraph; };
	void DrawCellule(CCellule::pCellule& pCellule);
	void ClaireFonce();
	void AfficherDataCF(unsigned int x, unsigned y);
	std::string GetMoisMot(int pos);
	void DrawCelluleBis(CCellule::pCellule& pCellule);
	void MoyenneParMoi();


	CCellule::pCellule pDonneeManquante = CCellule::NewCellule(1, 2024, 200.0, 0);
	std::vector<CCellule::pCellule> data = getFichier("aigoual_Mensuel.csv");

	
private:
	std::vector<LibGraph2::CPoint> vPoint{ LibGraph2::CPoint{1080 * 0.2, 720 * 0.5},LibGraph2::CPoint{1080 * 0.3, 720 * 0.5},LibGraph2::CPoint{1080 * 0.4, 720 * 0.7} };
	std::array<float, 12> MoyenneDesMois = { 0.0f };
	LibGraph2::ILibGraph2* pLibgraph;

};

void Help();