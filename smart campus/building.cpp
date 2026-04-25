#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to calculate efficiency score --> sondus
void calculateEfficiencyScore(building buildings[],int building_counter) {
	for (int i = 0; i < building_counter; i++) {
		if (buildings[i].Monthly_Limit > 0) {

			buildings[i].Efficiency_Score = ((buildings[i].Monthly_Limit - buildings[i].Total_consumption) / buildings[i].Monthly_Limit) * 100;
		}
		else {
			buildings[i].Efficiency_Score = 0;
		}
	}
	cout << "Efficiency score updated successfully" << endl;
	cout << "_________________________________" << endl;
    cout << "1. Back to menu" << endl;
	cout << "2. Quit and save" << endl;
	int choice;

	do {
		
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
			menu();
		else if (choice == 2) {
			return;
		}
		else
			cout << "Invalid choice! Please try again." << endl;

	} while (choice != 1 && choice != 2);
	

}

//define function to add new building ---> basmala
void AddBuilding(building buildings[], int& building_counter)
{

	if (building_counter < 10) {
		int id;
		string name;
		string type;
		float monthly_limit;
		cout << "Enter building ID: ";
		cin >> id;
		for (int i = 0; i < building_counter; i++) {
			if (id == buildings[i].ID) {
				cout << "A building with this ID already exists!" << endl;
				AddBuilding(buildings, building_counter);
				return;
			}
		}
		cout << "Enter building name: ";
		cin.ignore(); // Ignore the newline character left in the input buffer 
		getline(cin, name);
		for (int i = 0; i < building_counter; i++) {
			if (name == buildings[i].Name) {
				cout << "A building with this name already exists!" << endl;
				AddBuilding(buildings, building_counter);
				return;
			}
		}
		cout << "Enter building type: ";
		getline(cin, type);
		cout << "Enter monthly limit: ";
		cin >> monthly_limit;

		buildings[building_counter].ID = id;
		buildings[building_counter].Name = name;
		buildings[building_counter].type = type;
		buildings[building_counter].Monthly_Limit = monthly_limit;
		buildings[building_counter].Total_consumption = 0.0; // Initialize total consumption to 0
		buildings[building_counter].Efficiency_Score = 100.0; // Initialize efficiency score to 100
		building_counter++; // Increment the building counter
		cout << "Building added successfully!" << endl;
	}
	else {
		cout << "Building limit reached! Cannot add more buildings." << endl;	
	}

	
}
// define function to display building information ---> basmala
void displayBuildingInfo(building buildings[], int building_counter) {
	int id;
	cout << "Enter building ID: ";
	cin >> id;
	cin.ignore();
	string building_name;
	cout << "Enter building name: ";
	getline(cin, building_name);
	bool found = false;
	for (int i = 0; i < building_counter; i++) {
		if (buildings[i].ID == id && buildings[i].Name == building_name) {
		    found = true;
			cout << "Building ID: " << buildings[i].ID << endl;
			cout << "Building Name: " << buildings[i].Name << endl;
			cout << "Building Type: " << buildings[i].type << endl;
			cout << "Monthly Limit: " << buildings[i].Monthly_Limit << " kWh" << endl;
			cout << "Total Consumption: " << buildings[i].Total_consumption << " kWh" << endl;
			cout << "Efficiency Score: " << buildings[i].Efficiency_Score << "%" << endl;
			cout << "-----------------------------" << endl;
			break;
		}
	}

	if(!found) {
		cout << "Building not found!" << endl;
	}
        cout << "1. Back to menu" << endl;
		cout << "2. Quit and save" << endl;
		int choice;

	do {
		
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1)
			menu();
		else if (choice == 2) {
			return;
		}
		else
			cout << "Invalid choice! Please try again." << endl;
	} while (choice != 1 && choice != 2);
	

}
