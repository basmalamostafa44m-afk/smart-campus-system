#include<iostream>
#include<fstream>
#include<string>
#include "building.h"
#include "alert.h"
#include "admin.h"
#include"report.h"
#include "reading.h"
#include "filehandling.h"
using namespace std;
const int Number_of_building = 10;// size of building array
const int Number_of_Energy_reading = 30;// size of reading array
const int Number_of_Alerts = 20;// size of alerts array
const int Number_of_Admins = 5;// size of admin array
building buildings[Number_of_building];// Array of building
EnergyReading Readings[Number_of_Energy_reading];// Array of energy reading
Alert alerts[Number_of_Alerts];// Array os alerts
Admin admins[Number_of_Admins];// Array of admin 
int building_counter = 2;// to keep track of the number of buildings added
int reading_counter = 3;// to keep track of the number of energy readings added
int alert_counter = 0; // to keep track of the number of alerts added
int admin_counter = 0; // to keep track of the number of admins added
int numberOfUnresolvedAlerts = 0;
int numberOfResolvedAlerts = 0;
void menu();

int main() {

	loadFiles(buildings, building_counter, Readings, reading_counter, alerts, alert_counter, admins ,admin_counter, numberOfUnresolvedAlerts, numberOfResolvedAlerts);

	menu();

}
void menu() {
	int choice;
do{
	cout << "1.Add a new energy reading" << endl;
	cout << "2.Display building information" << endl;
	cout << "3.Generate alerts for overconsumption" << endl;
	cout << "4.View unresolved alerts" << endl;
	cout << "5.Calculate efficiency score" << endl;
	cout << "6.Generate monthly campus report" << endl;
	cout << "7.Resolve alert" << endl;
	cout << "8.log out" << endl;
		cin >> choice;
		if (choice == 1) {
			AddEnergyReading(buildings,building_counter, Readings, reading_counter, alerts, alert_counter, numberOfUnresolvedAlerts);
		}
		else if (choice == 2) {
			displayBuildingInfo(buildings, building_counter);
		}
		else if (choice == 3) {
			check_alert_generate(buildings, building_counter, Readings, reading_counter, alerts, alert_counter, numberOfUnresolvedAlerts);
		}
		else if (choice == 4) {
			displayOverconsumption(alerts, alert_counter);
		}
		else if (choice == 5) {
			calculateEfficiencyScore(buildings, building_counter);
		}
		else if (choice == 6) {
			generateMonthlyCampusReport(buildings, building_counter, numberOfUnresolvedAlerts, numberOfResolvedAlerts);
		}
		else if (choice == 7) {
			resolveAlert(alerts, alert_counter, numberOfResolvedAlerts, numberOfUnresolvedAlerts);
		}
		else if (choice == 8) {
			cout << "Logging out..." << endl;
			return;
		}
		else {
			cout << "Invalid option" << endl;
			cout << "Enter valid option: ";

		}
	} while (choice <= 8 && choice >= 1);
}