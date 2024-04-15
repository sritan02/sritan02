#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Hyderabad.h"

using namespace std;
// Function to parse a configuration line in a config file
string ParseConfigLine(string configLine);
// Function to parse a region line from a CSV file and create Hyderabad objects
void ParseRegionLine(string &regionLine, vector<Hyderabad> &row);
// Function to parse the config file at the beginning of the program
void ParseConfigFile(string configFileName, string &regionFileName, int &timeLimit, int &refreshRate);
// Function to parse the region data from a CSV file
void ParseRegionFile(vector<vector<Hyderabad> > &Region, string regionFileName);
// Function to calculate the total pollution in the region
int GetTotalPollution(vector<vector<Hyderabad> > &Region);
// Main initialization function
void Initialize(vector<vector<Hyderabad> > &Region, int &timeLimit, int &refreshRate, vector<vector<int> > &mapKey);
//function to check the simulation

void Simulation(vector<vector<int> > mapKey, vector<vector<Hyderabad> > &Region);
// Function to find adjacent tiles in the region
void FindAdjacentTiles(vector<vector<Hyderabad> > &vect);

#endif
