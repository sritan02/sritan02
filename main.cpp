#include "main.h"



void Print(int loop_value, vector<vector<Hyderabad> > &region) {
    // Print the current state of the region
    vector<vector<Hyderabad> >::iterator iter_rows;
    vector<Hyderabad>::iterator iter_cols;
    for (iter_rows = region.begin(); iter_rows != region.end(); iter_rows++) {
        for (iter_cols = iter_rows->begin(); iter_cols != iter_rows->end(); iter_cols++) {
            if (iter_cols->getType() == 'R' || iter_cols->getType() == 'C' || iter_cols->getType() == 'I') {
				if (iter_cols->getPopulation() == 0) {
					cout << iter_cols->getType() << " ";
				}
				else {
				cout << iter_cols->getPopulation() << " ";
				}
			}
			else {cout << iter_cols->getType() << " ";}
        }
        cout << endl;
    }
    cout << endl << "Timestep " << loop_value << " Pollution: " << GetTotalPollution(region); //Printing the timestep and pollution
}


int main() {
    vector<vector<Hyderabad> > Region;
	vector<vector<int> > mapKey;
    int timeLimit = 0;
    int refreshRate = 0;
	int initial = 0;
    // Read in files and initialize
    Initialize(Region, timeLimit, refreshRate, mapKey);

	for (int i = 0; i <= timeLimit; i++) {
		
		if (initial % refreshRate == 0) {
			 Print(i, Region);
		}
		
		Simulation(mapKey, Region);//Calling the function 
		initial++;
	}
    return 0;
}
