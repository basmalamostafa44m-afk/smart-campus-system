#include<iostream>
#include<fstream>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
#include "filehandling.h"
using namespace std;

void loadFiles(building buildings[], int &building_counter, EnergyReading Readings[], int &reading_counter, Alert alerts[], int &alert_counter, Admin admins[], int &admin_counter,int &numberOfUnresolvedAlerts, int &numberOfResolvedAlerts){
    ifstream read("campusData.txt");

	// Loading the counters and number of alerts from file
    read >> building_counter >> reading_counter >> alert_counter >> admin_counter >> numberOfUnresolvedAlerts >> numberOfResolvedAlerts;

    for (int i = 0; i < building_counter;i++) {
        // Loading data from file into building array
        read >> buildings[i].ID;
        read.ignore(); 
        getline(read, buildings[i].Name);
        getline(read, buildings[i].type);
        read >> buildings[i].Monthly_Limit >> buildings[i].Total_consumption >> buildings[i].Efficiency_Score;
    }

    for (int i = 0; i < reading_counter; i++) {
        // Loading data from file into Readings array
        read >> Readings[i].ReadingID >> Readings[i].BuildingID >> Readings[i].month >> Readings[i].consumption_value;
    }

    for (int i = 0; i < alert_counter; i++) {
        //  Loading data from file into alerts array
        read >> alerts[i].AlertID >> alerts[i].BuildingID >> alerts[i].month >> alerts[i].over_usage_amount >> alerts[i].status;
    }

    for (int i = 0; i < admin_counter; i++) {
        // Loading data from file into admins array
        read >> admins[i].Admin_ID;
        read.ignore();
        getline(read, admins[i].user_name);
        getline(read, admins[i].password);

    }
    
   // Closing the file after loading
    read.close();
}


void saveData(building buildings[], int building_counter, EnergyReading Readings[], int reading_counter, Alert alerts[], int alert_counter, Admin admins[], int admin_counter , int numberOfUnresolvedAlerts, int numberOfResolvedAlerts){
    ofstream saveFile("campusData.txt");
    if (saveFile) {//Check if this file was opened

            // Saving the counters and number of alerts into file
            saveFile << building_counter << " " << reading_counter << " " << alert_counter << " " << admin_counter << " " << numberOfUnresolvedAlerts << " " << numberOfResolvedAlerts << endl;


            for (int i = 0; i < building_counter; i++) {
				// Saving data from building array into file
                saveFile << buildings[i].ID << endl;;
                saveFile << buildings[i].Name << endl;
                saveFile << buildings[i].type << endl;
                saveFile << buildings[i].Monthly_Limit << " " << buildings[i].Total_consumption << " " << buildings[i].Efficiency_Score << endl;

            }

            for (int i = 0; i < reading_counter; i++) {
				// Saving data from Readings array into file
                saveFile << Readings[i].ReadingID << " " << Readings[i].BuildingID << " " << Readings[i].month << " " << Readings[i].consumption_value << endl;
            }

            for (int i = 0; i < alert_counter; i++) {
				// Saving data from alerts array into file
                saveFile << alerts[i].AlertID << " " << alerts[i].BuildingID << " " << alerts[i].month << " " << alerts[i].over_usage_amount << " " << alerts[i].status << endl;
            }

            for (int i = 0; i < admin_counter; i++) {
				// Saving data from admins array into file
                saveFile << admins[i].Admin_ID << endl;
                saveFile << admins[i].user_name << endl;
                saveFile << admins[i].password << endl;
            }
            
			

			// Closing the file after saving
			saveFile.close();

    }
    else {
        cout << " This file does not exist " << endl;
    }
}
