#pragma once
#include <string>
using namespace std;

// Eman declare any functions or structs related to generating reports in this file
// if you want a reference how to write in this file 
// you can check the other header files in this project like building.h, alert.h, reading.h, admin.h
// write functions definitions in report.cpp

// declare building struct 
struct building
{
    int ID;
    string Name;
    string type;
    float Monthly_Limit;
    float Total_consumption;
    float Efficiency_Score;

};

// declare alert struct
struct Alert {
    int AlertID;
    int BuildingID;
    string month;
    float over_usage_amount;
    string status;
};

//declare function to generate monthly campus report---> Eman
void generateMonthlyCampusReport(building buildings[], Alert alerts[], const int Number_of_building,
    const int Number_of_Alerts,int numberOfUnresolvedAlerts , int numberOfResolvedAlerts);

//declare function to calculateTotalCampusConsumption--> Eman
void calculateTotalCampusConsumption(building buildings[], const int Number_of_building);

//declare function to find the most efficient building--> Eman
void findMostEfficientBuilding(building buildings[], const int Number_of_building);

//declare function to find the least efficient building--> Eman
void findLeastEfficientBuilding(building buildings[], const int Number_of_building);

