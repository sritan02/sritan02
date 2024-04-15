#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Hyderabad.h"
#include "main.h"

// Helper function to check if a cell is adjacent to a powerline
bool isAdjacentToPowerline(std::vector<std::vector<Hyderabad> >& Region, int x, int y);

// Function to count adjacent cells of a certain population or more
int countAdjacentOfPopulation(std::vector<std::vector<Hyderabad> >& Region, int x, int y, int population);

// Main processing function for a commercial zone
Hyderabad commercialProcess(Hyderabad& city, std::vector<std::vector<Hyderabad> >& Region, int x, int y);

#endif