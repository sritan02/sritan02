#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "main.h"
#include "init.h"
#include "Hyderabad.h"
#include <vector>

bool isAdjacentToPowerline(std::vector<std::vector<Hyderabad> >& Region, int x, int y);

int countAdjacentOfPopulation(std::vector<std::vector<Hyderabad> >& Region, int x, int y, int population);

#endif

