#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Cellule.h"

std::vector<CCellule::pCellule> getFichier(const std::string& filename);
void afficherDonnees(std::vector<CCellule::pCellule> data);