#pragma once
#include <string>
using namespace std;
// declare alert struct
struct Alert {
	int AlertID;
	int BuildingID;
	string month;
	float over_usage_amount;
	string status;
};


// declare function to generate alert for over usage ---> amal
void check_alert_generate (float consumtion_valve, float monthly_limit,string building_name ,int building_id,string month,Alert alerts[], int &alert_counter ,int & numberOfUnresolvedAlerts);


// declare function to resolve alert ---> judy

// declare function to show all unresolved alerts ---> aya
void displayOverconsumption(Alert alerts[], int alert_counter);
