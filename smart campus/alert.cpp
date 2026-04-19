#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to check limit  ---> amal
void check_alert_generate(building buildings[], int& building_counter, EnergyReading readings[], int reading_counter, Alert alerts[], int& alert_counter, int& numberOfUnresolvedAlerts) {
	for (int i = 0; i < reading_counter; i++) {
		for (int j = 0; j < building_counter; j++) {
			if (readings[i].BuildingID == buildings[j].ID) {
				if (readings[i].consumption_value > buildings[j].Monthly_Limit) {
					generate_alert_for_over_usage(readings[i].consumption_value, buildings[j].Monthly_Limit, buildings[j].Name, buildings[j].ID, readings[i].month, alerts, alert_counter, numberOfUnresolvedAlerts);
				}
			}
		}
	}
	cout << "Alerts generated successfully!!" << endl;
	cout << "_________________________________" << endl;
	cout << "1. Back to menu" << endl;
	cout << "2. Quit and save" << endl;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
		menu();
	else if (choice == 2) {
		return;
	}
}


// define function to generate alert for over usage ---> amal
void generate_alert_for_over_usage(float consumtion_value, float monthly_limit, string building_name, int building_id,string month,Alert alerts[],int &alert_counter,int &numberOfUnresolvedAlerts) {

			float overusage = consumtion_value - monthly_limit;

			cout << "-----------ALERT !!-----------" << endl
				<< "there is an over usage of energy in building named " << building_name << endl
				<< "whose id is " << building_id << endl
				<< "the over usage amount = " << overusage << endl;

			alerts[alert_counter].AlertID = alert_counter + 1;
			alerts[alert_counter].BuildingID = building_id;
			alerts[alert_counter].over_usage_amount = overusage;
			alerts[alert_counter].month = month;
			alerts[alert_counter].status = "Unresolved";
			alert_counter++;
			numberOfUnresolvedAlerts++;

	
}


// define function to resolve alert ---> judy
void resolveAlert(Alert alerts[],int alert_counter,int &numberOfResolvedAlerts,int &numberOfUnresolvedAlerts) {
	do {
		if (numberOfUnresolvedAlerts == 0) {
			cout << "There are no unresolved alerts to resolve!" << endl;
			cout << "_________________________________" << endl;
			cout << "1. Back to menu" << endl;
			cout << "2. Quit and save" << endl;
			int c;
			cout << "Enter your choice: ";
			cin >> c;
			if (c == 1)
				menu();
			else if (c == 2) {
				return;
			}
		}
		int alertID;
		cout << " Please enter alert ID to resolve : ";
		cin >> alertID;
		bool ID_found = false;
		for (int i = 0; i < alert_counter; i++) {
			if (alerts[i].AlertID == alertID) {
				alerts[i].status = "Resolved";
				numberOfResolvedAlerts++;
				numberOfUnresolvedAlerts--;
				cout << "Alert resolved successfully!!";
				ID_found = true;
				break;
			}
		}
		if (ID_found == false)
			cout << "Alert ID is not found!";
		cout << "do you to try again? (y/n) : ";
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
	} while (true);
	cout << "_________________________________" << endl;
	cout << "1. Back to menu" << endl;
	cout << "2. Quit and save" << endl;
	int c;
	cout << "Enter your choice: ";
	cin >> c;
	if (c == 1)
		menu();
	else if (c == 2) {
		return;
	}
}

// define function to show all unresolved alerts ---> aya
	void displayOverconsumption(Alert alerts[], int alert_counter)
	{
		bool found = false;
		cout << "___Unresolved Alerts___" << endl;
		for (int i = 0; i < alert_counter; i++)
		{
			if (alerts[i].status == "Unresolved")
			{
				cout << "Alert ID: " << alerts[i].AlertID << endl;
				cout << "Building ID: " << alerts[i].BuildingID << endl;
				cout << "Month: " << alerts[i].month << endl;
				cout << "over_usage_amount: " << alerts[i].over_usage_amount << endl;
				cout << "-----------------------" << endl;
				found = true;
			}
		}
		if (!found)
			cout << "No unresolved alerts found." << endl;
		cout << "_________________________________" << endl;
		cout << "1. Back to menu" << endl;
		cout << "2. Quit and save" << endl;
		int c;
		cout << "Enter your choice: ";
		cin >> c;
		if (c == 1)
			menu();
		else if (c == 2) {
			return;
		}
	}
