#include<iostream>
#include<string>
#include "building.h"
#include"reading.h"
#include "alert.h"
#include "admin.h"
using namespace std;
// define function to add new energy reading --> basmala
void menu();
void AddEnergyReading(building buildings[], int& building_counter, EnergyReading readings[], int& reading_counter,Alert alerts[],int &alert_counter,int &numberOfUnresolvedAlerts) {
	do {
		cout << "select building ID: ";
		int id;
		cin >> id;
		cout << "select building name: ";
		string name;
		cin.ignore(); // Ignore the newline character left in the input buffer
		getline(cin, name);
		bool building_found = false;

		for (int i = 0; i < building_counter; i++) {
			if (buildings[i].ID == id && buildings[i].Name == name) {
				building_found = true;
				break;
			}
		}

		if (!building_found) {
			cout << "Building not found!" << endl;
			cout << "Do you want to add this building? (y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				AddBuilding(buildings, building_counter);
			}
		}
		else {
			cout << "Enter month: ";
			string month;
			cin >> month;
			cout << "Enter consumption value: ";
			float consumption_value;
			cin >> consumption_value;

			// Add the new reading
			readings[reading_counter].ReadingID = reading_counter + 1;
			readings[reading_counter].BuildingID = id;
			readings[reading_counter].month = month;
			readings[reading_counter].consumption_value = consumption_value;
			reading_counter++;

			// Update building's total consumption
			for (int i = 0; i < building_counter; i++) {
				if (buildings[i].ID == id && buildings[i].Name == name) {
					// Calculate total consumption for the month by summing all readings for the building and month
					float total_consumption_per_month = 0.0;
					for(int j = 0; j < reading_counter; j++) {
						if (readings[j].BuildingID == id && readings[j].month == month) {
							total_consumption_per_month += readings[j].consumption_value;
						}
					}
					//check if the new total consumption exceeds the monthly limit and generate alert if necessary
					if (total_consumption_per_month > buildings[i].Monthly_Limit) {
						generate_alert_for_over_usage(total_consumption_per_month, buildings[i].Monthly_Limit, buildings[i].Name, buildings[i].ID, month, alerts, alert_counter, numberOfUnresolvedAlerts);
					}
					// Update the building's total consumption by summing all readings for the building
					buildings[i].Total_consumption += consumption_value;
					break;
				}
			}

			cout << "Energy reading added successfully!" << endl;
			cout << "Do you want to calculate efficiency score for all buildings? (y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				// Recalculate efficiency scores for all buildings after adding the new reading
				calculateEfficiencyScore(buildings, building_counter);
				return;
			}
			cout << "_________________________________" << endl;
		}
		cout << "1. add another energy reading " << endl;
		cout << "2. return to main menu " << endl;
		cout << "3. Quit and save data " << endl;
		int continue_choice;
		cin >> continue_choice;
		if (continue_choice == 2) {
			menu();
			break;
		}
		else if (continue_choice == 3) {
			return;
		}
	} while (true);
}
