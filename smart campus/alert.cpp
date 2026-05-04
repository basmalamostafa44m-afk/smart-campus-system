#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to check limit  ---> amal
void check_alert_generate(building buildings[], int& building_counter, EnergyReading readings[], int reading_counter, Alert alerts[], int& alert_counter, int& numberOfUnresolvedAlerts) {
	
	if (alert_counter < 20) {
        bool alert_generated = false;
		for (int i = 0; i < reading_counter; i++) {
			for (int j = 0; j < building_counter; j++) {
				if (readings[i].BuildingID == buildings[j].ID) {
					if (readings[i].consumption_value > buildings[j].Monthly_Limit) {
						generate_alert_for_over_usage(readings[i].consumption_value, buildings[j].Monthly_Limit, buildings[j].Name, buildings[j].ID, readings[i].month, alerts, alert_counter, numberOfUnresolvedAlerts);
						alert_generated = true;
					}
				}
			}
		}

		if (!alert_generated)
			cout << "All alerts are already generated no more alerts to generate" << endl;
	}
	else
		cout << "cannot generate alerts! alert data base is full." << endl;
        cout << "_________________________________" << endl;
		cout << "1. Back to menu" << endl;
		cout << "2. Quit and save" << endl;
		int choice;

	do {
		
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			menu();
		}
		else if (choice == 2) {
			return;
		}
		else
			cout << " Invalid choice! Please try again. " << endl;
	} while (choice != 1 && choice != 2);
}


// define function to generate alert for over usage ---> amal
void generate_alert_for_over_usage(float consumtion_value, float monthly_limit, string building_name, int building_id, string month, Alert alerts[], int& alert_counter, int& numberOfUnresolvedAlerts) {

		float overusage = consumtion_value - monthly_limit;
		bool notfound = true;
		for (int i = 0; i < alert_counter; i++) {
			if (alerts[i].month == month && alerts[i].BuildingID == building_id && overusage == alerts[i].over_usage_amount  ) {
				cout << "This alert with ID " << alerts[i].AlertID << " has already been generated in building named " << building_name
					<< " whose building id is "<< building_id <<" in the month of " << month << " with the same over usage amount = " << overusage << endl;
				notfound = false;
			}
		}
		
		if (notfound) {
			cout << "-----------NEW ALERT !!-----------" << endl
				<< "there is an over usage of energy in building named " << building_name << endl
				<< "whose id is " << building_id << " in the month of " << month << endl
				<< "the over usage amount = " << overusage << endl;

			alerts[alert_counter].AlertID = alert_counter + 1;
			alerts[alert_counter].BuildingID = building_id;
			alerts[alert_counter].over_usage_amount = overusage;
			alerts[alert_counter].month = month;
			alerts[alert_counter].status = "Unresolved";
			alert_counter++;
			numberOfUnresolvedAlerts++;
		}

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

			do {
				
				cout << "Enter your choice: ";
				cin >> c;
				if (c == 1) {
					menu();
				}
				else if (c == 2) {
					return;
				}
				else
					cout << "Invalid choice! Please try again." << endl;	
			} while (c != 1 && c != 2);
		}
		int alertID;
		cout << " Please enter alert ID to resolve : ";
		cin >> alertID;
		bool ID_found = false;
		bool IsResolved = true;
		for (int i = 0; i < alert_counter; i++) {
			if (alerts[i].AlertID == alertID) {
				ID_found = true;
				if (alerts[i].status == "Unresolved") {
					alerts[i].status = "Resolved";
					numberOfResolvedAlerts++;
					numberOfUnresolvedAlerts--;
					cout << "Alert resolved successfully!!" << endl;
					IsResolved = false ;
					break;
				}
			}
		}
		if (ID_found == false)
			cout << "Alert ID is not found!" << endl;
		else if (ID_found == true && IsResolved == true)
			cout << "Alert is already resolved!" << endl;

		cout << "do you to try again? (y/n) : ";
		char choice;
		cin >> choice;
		if (choice == 'n' || choice == 'N')
			break;
	} while (true);

        cout << "_________________________________" << endl;
		cout << "1. Back to menu" << endl;
		cout << "2. Quit and save" << endl;
    int ch;
	do {
		
		cout << "Enter your choice: ";
		cin >> ch;
		if (ch == 1) {
			menu();
		}
		else if (ch	 == 2) {
			return;
		}
		else
			cout << "Invalid choice! Please try again." << endl;
	} while (ch != 1 && ch != 2);
	
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
			int choice;
		do {
			
			cout << "Enter your choice: ";
			cin >> choice;
			if (choice == 1) {
				menu();
			}
			else if (choice == 2) {
				return;
			}
			else
				cout << "Invalid choice! Please try again." << endl;
		} while (choice != 1 && choice != 2);
	}
