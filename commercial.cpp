#include "commercial.h"
#include "analysis.h"

Hyderabad commercialProcess(Hyderabad& city, std::vector<std::vector<Hyderabad> >& Region, int x, int y) {
    Hyderabad newCity = city;

    if (city.getPopulation() == 0) {
        if (isAdjacentToPowerline(Region, x, y)/* && city.getWorkers() >= 1 && city.getGoods() >= 1*/) {
            newCity.updatePopulation();
/*            newCity.assignWorker();
            newCity.assignGoods();*/
            return newCity;
        }
        return newCity;
    }
    else if (city.getPopulation() == 0 && countAdjacentOfPopulation(Region, x, y, 1) >= 2/* && city.getWorkers() >= 1 && city.getGoods() >= 1*/) {
        newCity.updatePopulation();
/*        newCity.assignWorker();
        newCity.assignGoods();*/
        return newCity;
    }
    else if (city.getPopulation() == 1 && countAdjacentOfPopulation(Region, x, y, 2) >= 4/* && city.getWorkers() >= 1 && city.getGoods() >= 1*/) {
        newCity.updatePopulation();
/*        newCity.assignWorker();
        newCity.assignGoods();*/
        return newCity;
    }

    return newCity;
}
