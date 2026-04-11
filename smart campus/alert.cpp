#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to check limit ---> amal


// define function to generate alert for over usage ---> amal<
void check_alert_generate(float consumtion_value, float monthly_limit, string building_name, int building_id,string month,Alert alerts[]) {

	if (consumtion_value > monthly_limit) {
		float overusage = consumtion_value - monthly_limit;
		// generating alert

		cout << "-----------ALERT !!-----------" << endl
			 << "there is an overusage of energy in building named" << building_name << endl
			 << "whose id is" << building_id << endl
			 << "the over usage amount= " << overusage;

		alerts[alert_counter].AlertID = alert_counter;
		alerts[alert_counter].BuildingID = building_id;
		alerts[alert_counter].over_usage_amount = overusage;
		alerts[alert_counter].month = month;
		alert_counter++;

	}
}


// define function to resolve alert ---> judy



// define function to show all unresolved alerts ---> aya