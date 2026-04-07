#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
// define function to calculate efficiency score --> sondus

//define function to add new building ---> basmala
void AddBuilding(building &buildings,int &building_counter)
{
	int id;
	string name;
	string type;
	float monthly_limit;
	cout << "Enter building ID: ";
	cin >> id;
	cout << "Enter building name: ";
	cin >> name;
	cout << "Enter building type: ";
	cin >> type;
	cout << "Enter monthly limit: ";
	cin >> monthly_limit;
	buildings.ID = id;
	buildings.Name = name;
	buildings.type = type;
	buildings.Monthly_Limit = monthly_limit;
	buildings.Total_consumption = 0.0; // Initialize total consumption to 0
	buildings.Efficiency_Score = 100.0; // Initialize efficiency score to 100
	building_counter++; // Increment the building counter
}
