#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "main.h"
#include "init.h"
#include "Hyderabad.h"
#include <vector>

//redeclaring the function with the parameters
bool isAdjacentToPowerline(std::vector<std::vector<Hyderabad> >& Region, int x, int y);
//declaring the count the adjacent population here
int countAdjacentOfPopulation(std::vector<std::vector<Hyderabad> >& Region, int x, int y, int population);

#endif

