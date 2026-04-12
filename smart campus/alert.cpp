#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to generate alert for over usage ---> amal
void check_alert_generate(float consumtion_value, float monthly_limit, string building_name, int building_id,string month,Alert alerts[],int &alert_counter) {

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

	}
}


// define function to resolve alert ---> judy



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
