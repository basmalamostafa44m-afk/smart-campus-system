#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to generate alert for over usage ---> amal
void check_alert_generate(float consumtion_value, float monthly_limit, string building_name, int building_id,string month,Alert alerts[],int &alert_counter,int &numberOfUnresolvedAlerts) {

	if (consumtion_value > monthly_limit) {
		float overusage = consumtion_value - monthly_limit;
		// generating alert

		cout << "-----------ALERT !!-----------" << endl
			 << "there is an over usage of energy in building named" << building_name << endl
			 << "whose id is" << building_id << endl
			 << "the over usage amount= " << overusage;

		alerts[alert_counter].AlertID = alert_counter + 1;
		alerts[alert_counter].BuildingID = building_id;
		alerts[alert_counter].over_usage_amount = overusage;
		alerts[alert_counter].month = month;
		alert_counter++;
		numberOfUnresolvedAlerts++;

	}
}


// define function to resolve alert ---> judy
#include <iostream>
#include <string>
using namespace std;
//resolve alert function declaration and defenition (before main)
void resolveAlert(Alert alerts[Number_of_Alerts]) {
	bool found = false;
	for (int i = 0; i < Number_of_Alerts; i++) {
		if (alerts[i].status == "Unresolved") {
			cout << alerts[i].AlertID << " , " << alerts[i].BuildingID << " , " << alerts[i].month << " , " << alerts[i].over_usage_amount;
			found = true;
		}
	}
	if (found == false) {
		cout << "No pending alerts to resolve" << endl;
		return;
	}

	int alertID;
	cout << " Please enter alert ID to resolve : ";
	cin >> alertID;
	bool ID_found = false;
	for (int i = 0; i < Number_of_Alerts; i++) {
		if (alerts[i].AlertID == alertID) {
			alerts[i].status = "Resolved";
			cout << "Alert resolved successfully!!";
			ID_found = true;
			break;
		}
	}
	if (ID_found == false)
		cout << "Alert ID is not found!";

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
	if(!found)
		cout<< "No unresolved alerts found." << endl;
}
