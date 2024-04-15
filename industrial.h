#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Hyderabad.h"
#include "main.h"

// Function to calculate pollution generation and spread
void calculatePollution(std::vector<std::vector<Hyderabad> >& Region, int x, int y);
// Function to control the generation and distribution of goods from industrial zones
void generateAndDistributeGoods(std::vector<std::vector<Hyderabad> >& Region, int x, int y, vector<vector<int> > mapKey);
//Function for an industrial zone
Hyderabad industrialProcess(Hyderabad& city, std::vector<std::vector<Hyderabad> >& Region, int x, int y);

#endif
