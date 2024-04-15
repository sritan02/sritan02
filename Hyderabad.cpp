#include <iostream>
#include "Hyderabad.h"


using namespace std;

// Constructor
Hyderabad::Hyderabad(char T, int P) {
    this->type = T;
    this->pollution = P;
}

// Setter for the city type
void Hyderabad::setType(char t) {
    this->type = t;
}

// Setter for pollution level
void Hyderabad::setPollution(int p) {
    this->pollution = p;
}

// Getter for city type
char Hyderabad::getType() {
    if (type != 'E') {
        return type;
    } else {
        return ' ';
    }
}

// Getter for pollution level
int Hyderabad::getPollution() {
    return pollution;
}

// Getter for the number of workers
int Hyderabad::getWorkers() {
    return workers;
}

// Getter for the number of goods
int Hyderabad::getGoods() {
    return goods;
}

// Getter for the population
int Hyderabad::getPopulation() {
    return population;
}

// Increment population count
void Hyderabad::updatePopulation() {
    population++;
}
//check the powerline
bool Hyderabad::isPowerline() {
	return (type == 'T' || type == '#');
}

void Hyderabad::assignWorker() {
	hasWorker = true;
	workers--;
}

void Hyderabad::assignGoods() {
	hasGood = true;
	goods--;
}
