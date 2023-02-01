#include "MenuItem.h"


class Parking {
private:
	char file[50];

	MenuItem selection[6];
	int indent = 0;
	bool state = 1;

public:
	Parking(const char str[] = "") {

		if ( str == NULL || str[0] == '\0') {
			//cout << "Error in data file" << endl;
			state = 0;
			return;
		}
		strcpy_s(file, str);

		selection[0] = "1- Park Vehicle";
		selection[1] = "2- Return Vehicle";
		selection[2] = "3- List Parked Vehicles";
		selection[3] = "4- Find Vehicle";
		selection[4] = "5- Close Parking (End of Day)";
		selection[5] = "6- Exit Program";
	}

	void run() {

		if (!state) {
			cout << "Error in data file" << endl;
			return;
		}

		bool count = false;
		if (!state) { return; }

		int choice;
		char permit = 'n';
		do {

			if (count) { 
				cout << endl; 
			}
			count = true;
			cout << "****** Valet Parking ******" << endl;
			cout << "Parking Menu, select an action: " << endl;

			for (int i = 0; i < 6; i++)
			{
				cout << this->selection[i].title << endl;
			}

			cout << ">";
			cin >> choice;
			validateChoice(choice, 1, 6);

			//showSelection(choice, indent);
			indent++;


			switch (choice) {
			case 1: {

				for (int i = 0; i < 4; i++) { cout << " "; }
				cout << "Select Type of The Vehicle: " << endl;
				for (int i = 0; i < 4; i++) { cout << " "; }
				cout << "1- Car" << endl;
				for (int i = 0; i < 4; i++) { cout << " "; }
				cout << "2- Motorcycle" << endl;
				for (int i = 0; i < 4; i++) { cout << " "; }
				cout << "3- Cancel" << endl;

				for (int i = 0; i < 4; i++) { cout << " "; }
				cout << "> ";
				cin >> choice;
				validateChoice(choice, 1, 3);

				switch (choice) {
				case 1: {
					message("parking Car");
					continue;
				}
				case 2: {
					message("parking MotorCycle");
					continue;
				}
				case 3: {
					message("Cancelled Parking");
					continue;
				}
				}

			}
			case 2: {
				message("Returning Vehicle");
				continue;
			}
			case 3: {
				message("Listing parked Vehicles");
				continue;
			}
			case 4: {
				message("Finding a Vehicle");
				continue;
			}
			case 5: {

				cout << "This will close the parking : All the vehicles will be removed!" << endl;
				cout << "Are you Sure? (Y)es/(N)o: " << endl;
				cout << "> ";
				cin >> permit;
				while (permit != 'y' && permit != 'Y' && permit != 'N' && permit != 'n') {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> permit;
				}

				break;
			}
			case 6: {
				cout << "This will terminate the application and save the data!" << endl;
				cout << "Are you Sure? (Y)es/(N)o: ";
				cin >> permit;
				while (permit != 'y' && permit != 'Y' && permit != 'N' && permit != 'n') {
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> permit;
				}
				count = false;
				break;
			}
			}
		} while (permit != 'y' && permit != 'Y');
		cout << "Ending application!" << endl;
		message("Saving data into ParkingData.csv");
	}

	void message(const char str[]) {

		cout << "----------------------------------" << endl;
		cout << str << endl;
		cout << "---------------------------------" << endl;
	}
	void validateChoice(int &choice, int a, int b) {
		
		while (choice < a || choice > b) {

			cout << "Invalid selection, try again: " << endl;
			cout << ">";
			cin >> choice;
		}
	}
};