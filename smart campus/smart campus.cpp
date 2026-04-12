#include<iostream>
#include<fstream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
#include"report.h"
using namespace std;
int main() {
	const int Number_of_building = 10;
	const int Number_of_Energy_reading = 30;
	const int Number_of_Alerts = 20;
	const int Number_of_Admins = 2;
	building buildings[Number_of_building];// Array of building
	buildings[0] = { 101, "HallOne_cs", "Academic", 500.5, 0.0, 100.0 };
	buildings[1] = { 102, "physics_Lab", "Lab", 800.0, 0.0, 100.0 };
	int building_counter = 2;// to keep track of the number of buildings added
	EnergyReading Readings[Number_of_Energy_reading];// Array of energy reading
	Readings[0] = { 1, 101, "January", 450.5 };
	Readings[1] = { 2, 101, "February", 550.0 };
	Readings[2] = { 3, 102, "January", 700.0 };
	int reading_counter = 3;// to keep track of the number of energy readings added
	Alert alerts[Number_of_Alerts];// Array os alerts
	Admin admins[Number_of_Admins];// Array of admin 
	int numberOfUnresolvedAlerts = 0 ;
	int numberOfResolvedAlerts = 0;
	int alert_counter = 0;
	
	
}