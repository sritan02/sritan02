#include "commercial.h"
#include "analysis.h"

Hyderabad commercialProcess(Hyderabad& city, std::vector<std::vector<Hyderabad> >& Region, int x, int y) {
    Hyderabad newCity = city;

    if (city.getPopulation() == 0) {
        if (isAdjacentToPowerline(Region, x, y)) {
            newCity.updatePopulation();

            return newCity;
        }
        return newCity;
    }
    else if (city.getPopulation() == 0 && countAdjacentOfPopulation(Region, x, y, 1) >= 2) {
        newCity.updatePopulation();

        return newCity;
    }
    else if (city.getPopulation() == 1 && countAdjacentOfPopulation(Region, x, y, 2) >= 4) {
        newCity.updatePopulation();

        return newCity;
    }

    return newCity;
}
