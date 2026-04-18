#pragma once
#include<fstream>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;


void loadFiles(building buildings[], int &building_counter, EnergyReading Readings[], int &reading_counter, Alert alerts[], int &alert_counter, Admin admins[], int &admin_counter , int &numberOfUnresolvedAlerts, int &numberOfResolvedAlerts);

void saveData(building buildings[], int building_counter, EnergyReading Readings[], int reading_counter, Alert alerts[],int alert_counter ,Admin admins[], int admin_counter, int numberOfUnresolvedAlerts, int numberOfResolvedAlerts);


