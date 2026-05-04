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
void menu();// define menu function
void start();// define the function that gonna be our start point

int main() {
	loadFiles(buildings, building_counter, Readings, reading_counter, alerts, alert_counter, admins ,admin_counter, numberOfUnresolvedAlerts, numberOfResolvedAlerts);
	start();
	cout << "                  ___ Thank you for using smart campus energy consumption monitor, goodbye!___     " << endl;
	saveData(buildings, building_counter, Readings, reading_counter, alerts, alert_counter, admins, admin_counter, numberOfUnresolvedAlerts, numberOfResolvedAlerts);

}
void start() {
	cout << "                   <-------- Welcome to smart campus energy consumption monitor -------->         " << endl;
	cout << "Do you have an account?(y/n)";
	string answer;
	cin >> answer;
	cin.ignore();// Ignore the newline character left in the input buffer
	if (answer == "y" || answer == "Y") {
		Admin_login(admins, admin_counter);
	}
	else {
		cout << "ok let's create one for you" << endl;
		admin_signup(admins, admin_counter);
	}
}
void menu() {
	int choice;
	cout << "____________MAIN MENU______________" << endl;
	cout << "1.Add a new energy reading" << endl;
	cout << "2.Display building information" << endl;
	cout << "3.Generate alerts for overconsumption" << endl;
	cout << "4.View unresolved alerts" << endl;
	cout << "5.Calculate efficiency score" << endl;
	cout << "6.Generate monthly campus report" << endl;
	cout << "7.Resolve alert" << endl;
	cout << "8.Add new building" << endl;
	cout << "9.log out" << endl;
	cout << "Enter your choice: ";
	do {
		cin >> choice;
		if (choice == 1) {
			AddEnergyReading(buildings, building_counter, Readings, reading_counter, alerts, alert_counter, numberOfUnresolvedAlerts);
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
			generateMonthlyCampusReport(buildings, building_counter,Readings, reading_counter, alerts, alert_counter);
		}
		else if (choice == 7) {
			resolveAlert(alerts, alert_counter, numberOfResolvedAlerts, numberOfUnresolvedAlerts);
		}
		else if (choice == 8) {
			AddBuilding(buildings, building_counter);
		}
		else if (choice == 9) {
			cout << "Logging out..." << endl;
			start();
		}
		else {
			cout << "Invalid option" << endl;
			cout << "Enter valid option: ";

		}
	} while (choice < 1 || choice > 9);
}