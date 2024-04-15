#ifndef HYDERABAD_H
#define HYDERABAD_H


#include <vector>
using namespace std;

class Hyderabad {
public:
    // Constructor with default values
    Hyderabad(char T = '\0', int P = 0);

    // Setter for the city type
    void setType(char t);

    // Setter for pollution level
    void setPollution(int p);

    // Getter for city type
    char getType();

    // Getter for pollution level
    int getPollution();

    // Getter for the number of workers
    int getWorkers();

    // Getter for the number of goods
    int getGoods();

    // Getter for the population
    int getPopulation();

    // Increment population count
    void updatePopulation();
	
	// Check if adjacent file is powerline
	bool isPowerline();
	
	// Assign worker to HyderabadCity element
	void assignWorker();
	
	// Assign good to HyderbadCity element
	void assignGoods();
	

private: //declaring the class members private
    char type = '\0';
    int pollution = 0;
    int workers = 0;
    int goods = 0;
    int population = 0;
	bool hasWorker = false;
	bool hasGood = false;

    // Adjacency list to store neighboring cities
    vector<Hyderabad> adjacencyList;
};

#endif
