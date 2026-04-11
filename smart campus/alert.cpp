#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to check limit ---> amal


// define function to generate alert for over usage ---> amal



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
