#include "cellule.h"
#include <iostream>

CCellule::pCellule CCellule::NewCellule(const int mois, int an, float tMoy, int color)
{
	return std::make_shared<CCellule>(mois, an, tMoy, color);;
}

void CCellule::SetColor()
{
    // Celon la température la couleur attribué a la cellule sera plus ou moin bleu ou rouge
    if (_tempMois <= -8.2)
        m_Color = 0;
    else if (_tempMois <= -4.5 && _tempMois > -8.2)
        m_Color = 1;
    else if (_tempMois <= -0.7 && _tempMois > -4.5)
        m_Color = 2;
    else if (_tempMois <= 2.8 && _tempMois > -0.7)
        m_Color = 3;
    else if (_tempMois <= 6.6 && _tempMois > 2.8)
        m_Color = 4;
    else if (_tempMois <= 10.4 && _tempMois > 6.6)
        m_Color = 5;
    else if (_tempMois <= 14.1 && _tempMois > 10.4)
        m_Color = 6;
    else if ( _tempMois > 14.1)
        m_Color = 7;
}