#include "analysis.h"

bool isAdjacentToPowerline(std::vector<std::vector<Hyderabad> >& Region, int x, int y) {
    // Defines the directions for adjacent cells
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	bool isAdjacent = false;

	
	for (int i = 0; i < 8; i++) {
		
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
		if ((newY < Region.size() && newY >= 0) && (newX >= 0 && newX < Region.size())) {


			if (Region[newX][newY].isPowerline()) {
				isAdjacent = true;
			}
		}
    }
	return isAdjacent;
}
//Funtion to decide the count adjacent of the population
int countAdjacentOfPopulation(std::vector<std::vector<Hyderabad> >& Region, int x, int y, int population) {
    int count = 0;

    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < 8; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
		
        if (newY >= 0 && newY < Region.size() && newX >= 0 && newX < Region[0].size() && Region[newY][newX].getPopulation() >= population) {
            count++;
        }
    }
    return count;
}
