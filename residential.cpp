#include "residential.h"
#include "main.h"
#include "analysis.h"
Hyderabad residentialProcess(Hyderabad& city, std::vector<std::vector<Hyderabad> >& Region, int x, int y) {
    Hyderabad newCity = city;

    if (city.getPopulation() == 0) { //checking if the population is 0
        if (isAdjacentToPowerline(Region, x, y)  || countAdjacentOfPopulation(Region, x, y, 1) >= 1) {
            newCity.updatePopulation();
			return newCity;
        }
		
        return newCity;	
    } else if (city.getPopulation() == 1 && countAdjacentOfPopulation(Region, x, y, 1) >= 2) {
        newCity.updatePopulation();
		return newCity;
    } else if (city.getPopulation() == 2 && countAdjacentOfPopulation(Region, x, y, 2) >= 4) {
        newCity.updatePopulation();
		return newCity;
    } else if (city.getPopulation() == 3 && countAdjacentOfPopulation(Region, x, y, 3) >= 6) {
        newCity.updatePopulation();
		return newCity;
    } else if (city.getPopulation() == 4 && countAdjacentOfPopulation(Region, x, y, 4) >= 8) {
        newCity.updatePopulation();
		return newCity;
    }

    return newCity;
}
