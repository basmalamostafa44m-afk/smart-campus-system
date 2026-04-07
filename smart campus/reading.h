#pragma once
#include <string>
using namespace std;
// declare reading struct
struct EnergyReading {
	int ReadingID;
	int BuildingID;
	string month;
	float consumption_value;
};
// declare function to add new energy reading --> basmala
void AddEnergyReading(building buildings[],EnergyReading readings[]);

