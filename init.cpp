	#include "init.h"
	#include "main.h"
	#include "residential.h"
	#include "commercial.h"
	#include "industrial.h"
	using namespace std;

	// Function to parse a configuration line in a config file
	string ParseConfigLine(string configLine) {
		bool hit = false;
		int hitAt = 0;
		string str = "";
		for (size_t i = 0; i < configLine.size(); i++) {
			if (configLine.at(i) == ':') {
				hit = true;
				hitAt = i;
				break;
			}
		}
		if (hit == true) {
			str = configLine.substr(hitAt + 1, configLine.size());
		} else {
			str = "-1";
		}
		return str;
	}
	// Function to parse a region line from a CSV file and create Hyderabad objects
	void ParseRegionLine(string &regionLine, vector<Hyderabad> &row) {
		for (size_t i = 0; i < regionLine.length(); i++) {
			if (regionLine[i] == ',') {
				continue;
			} else {
				Hyderabad new_city;
				new_city.setType(regionLine[i]);
				row.push_back(new_city);
			}
		}
		return;
	}

	
	// Function to parse the config file at the beginning of the program
	void ParseConfigFile(string configFileName, string &regionFileName, int &timeLimit, int &refreshRate) {
		ifstream configStream;
		string configLine = "";

		configStream.open(configFileName);
		cout << configFileName;
		if (configStream.is_open()) {
			cout << " opened successfully.\n";
		} else {
			cout << " failed to open. Exiting with error code -1\n";
			exit(-1);
		}

		int i = 0;
		stringstream ss;
		string tempString;
		while (!configStream.eof()) {
			getline(configStream, configLine);
			i++;
			if (i == 1) {
				regionFileName = ParseConfigLine(configLine);
			}
			if (i == 2) {
				tempString = ParseConfigLine(configLine);
				ss << tempString;
				ss >> timeLimit;
				ss.clear();
			}
			if (i == 3) {
				tempString = ParseConfigLine(configLine);
				ss << tempString;
				ss >> refreshRate;
				ss.clear();
			}
		}

		configStream.close();
		return;
	}

	// Function to parse the region data from a CSV file
	void ParseRegionFile(vector<vector<Hyderabad> > &Region, string regionFileName) {
		ifstream regionStream;

		regionStream.open(regionFileName);
		cout << regionFileName;
		if (regionStream.is_open()) {
			cout << " opened successfully.\n";
		} else {
			cout << " failed to open. Exiting with error code -1\n";
			exit(-1);
		}

		string regionLine;
		while (getline(regionStream, regionLine)) {
			vector<Hyderabad> row;
			stringstream ss(regionLine);
			ParseRegionLine(regionLine, row);
			Region.push_back(row);
		}

		regionStream.close();
		return;
	}

	// Function to calculate the total pollution in the region
	int GetTotalPollution(vector<vector<Hyderabad> > &Region) {
		long int total_pollution = 0;
		vector<vector<Hyderabad> >::iterator iter_rows;
		vector<Hyderabad>::iterator iter_cols;
		for (iter_rows = Region.begin(); iter_rows != Region.end(); iter_rows++) {
			for (iter_cols = iter_rows->begin(); iter_cols != iter_rows->end(); iter_cols++) {
				total_pollution += iter_cols->getPollution();
			}
		}
		return total_pollution;
	}

	// Main initialization function
	void Initialize(vector<vector<Hyderabad> > &Region, int &timeLimit, int &refreshRate, vector<vector<int> > &mapKey) {
		int rows;
		int cols;
		string regionFileName = "";
		string configFileName = "";
		cout << endl << "Enter filename of configuration file: ";
		cin >> configFileName;

		ParseConfigFile(configFileName, regionFileName, timeLimit, refreshRate);

		ParseRegionFile(Region, regionFileName);

		cout << "Time Limit: " << timeLimit << endl;
		cout << "Refresh Rate: " << refreshRate << endl << endl;

		vector<vector<Hyderabad> >::iterator iter_rows;
		vector<Hyderabad>::iterator iter_cols;
		for (iter_rows = Region.begin(); iter_rows != Region.end(); iter_rows++) {
			for (iter_cols = iter_rows->begin(); iter_cols != iter_rows->end(); iter_cols++) {
				cout << iter_cols->getType() << " ";
				cols++;
			}
			rows++;
			cout << endl;
		}
		cout << endl << "Timestep 0, " << "Pollution: " << GetTotalPollution(Region) << endl << endl;

		mapKey.resize(rows, vector<int>(cols / rows)); // Resize mapKey to match the dimensions of Region

	int rowIndex = 0;
	int colIndex = 0;	
	for (auto& row : Region) {
		colIndex = 0;
		for (auto& city : row) {
			// Populate mapKey based on the city type
			if (city.getType() == 'R') {
				mapKey[rowIndex][colIndex] = 1;
			} else if (city.getType() == 'I') {
				mapKey[rowIndex][colIndex] = 2;
			} else if (city.getType() == 'C') {
				mapKey[rowIndex][colIndex] = 3;
			} else {
				mapKey[rowIndex][colIndex] = 0;
			}

			colIndex++;
		}
		rowIndex++;
	}

	}

//declaring the simulation function of void type 
	void Simulation(vector<vector<int> > mapKey, vector<vector<Hyderabad> > &Region) {
		
	int rowIndex = 0;
	int colIndex = 0;

	for (auto& row : mapKey) {
		   colIndex = 0;
		for (auto& city : row) {
			if (city == 1) {
				Region[rowIndex][colIndex] = residentialProcess(Region[rowIndex][colIndex], Region, rowIndex, colIndex);
			} else if (city == 2) {
				Region[rowIndex][colIndex] = industrialProcess(Region[rowIndex][colIndex], Region, colIndex, rowIndex);
				generateAndDistributeGoods(Region, colIndex, rowIndex, mapKey);
			} else if (city == 3) {
				Region[rowIndex][colIndex] = commercialProcess(Region[rowIndex][colIndex], Region, colIndex, rowIndex);
			}
			colIndex++;
		}
		cout << endl;
		rowIndex++;
	}
	}
