#include<iostream>
#include<fstream>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
#include "filehandling.h"
using namespace std;

void loadFiles(building buildings[], int building_counter, EnergyReading Readings[], int reading_counter, Alert alerts[], int alert_counter, Admin admins[], int current_admin_numbers){
    ifstream read("campusData.txt");

    for (int i = 0; i < building_counter;i++) {
        // loading data from file into building array
        read >> buildings[i].ID;
        read.ignore(); 
        getline(read, buildings[i].Name);
        getline(read, buildings[i].type);
        read >> buildings[i].Monthly_Limit >> buildings[i].Total_consumption >> buildings[i].Efficiency_Score;
    }

    for (int i = 0; i < reading_counter; i++) {
        // loading data from file into Readings array
        read >> Readings[i].ReadingID >> Readings[i].BuildingID >> Readings[i].month >> Readings[i].consumption_value;
    }

    for (int i = 0; i < alert_counter; i++) {
        //  loading data from file into alerts array
        read >> alerts[i].AlertID >> alerts[i].BuildingID >> alerts[i].month >> alerts[i].over_usage_amount >> alerts[i].status;
    }

    for (int i = 0; i < current_admin_numbers; i++) {
        // loading data from file into admins array
        read >> admins[i].Admin_ID;
        read.ignore();
        getline(read, admins[i].user_name);
        getline(read, admins[i].password);

    }
    read.close();
}

void saveData(building buildings[], int building_counter, EnergyReading Readings[], int reading_counter, Alert alerts[], int alert_counter, Admin admins[], int current_admin_numbers){
    ofstream saveFile("campusData.txt");
    if (saveFile) {//Check if this file was opened

            for (int i = 0; i < building_counter; i++) {
                saveFile << buildings[i].ID << endl;;
                saveFile << buildings[i].Name << endl;
                saveFile << buildings[i].type << endl;
                saveFile << buildings[i].Monthly_Limit << " " << buildings[i].Total_consumption << " " << buildings[i].Efficiency_Score << endl;

            }

            for (int i = 0; i < reading_counter; i++) {
                saveFile << Readings[i].ReadingID << " " << Readings[i].BuildingID << " " << Readings[i].month << " " << Readings[i].consumption_value << endl;
            }

            for (int i = 0; i < alert_counter; i++) {
                saveFile << alerts[i].AlertID << " " << alerts[i].BuildingID << " " << alerts[i].month << " " << alerts[i].over_usage_amount << " " << alerts[i].status << endl;
            }

            for (int i = 0; i < current_admin_numbers; i++) {
                saveFile << admins[i].Admin_ID << endl;
                saveFile << admins[i].user_name << endl;
                saveFile << admins[i].password << endl;
            }
			saveFile.close();
    }
    else {
        cout << " This file does not exist " << endl;
    }
}
