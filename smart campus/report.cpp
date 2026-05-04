#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
#include "report.h"
using namespace std;

// define any functions related to generating reports in this file ---> Eman

//define function to generate monthly campus report
void generateMonthlyCampusReport(building buildings[], int building_counter , EnergyReading reading[] ,int reading_counter ,Alert alerts[],int alert_counter) {
    string target_month;
    cout << "Enter Month Name : ";
    cin >> target_month;

    float total_consumption = 0.0;
    string most_efficient_building = "N/A";
    string least_efficient_building = "N/A";

    float min_consumption = 0.0;
    float max_consumption = 0.0;
    bool first_record = true;
    float curr_efficiency_score = 0.0;
    for (int i = 0; i < reading_counter; i++) {
        if (reading[i].month == target_month) {
            total_consumption += reading[i].consumption_value;

            string currentBuildingName = "Unknown";
            for (int j = 0; j < building_counter; j++) {
                if (buildings[j].ID == reading[i].BuildingID) { 
                    currentBuildingName = buildings[j].Name;
                    curr_efficiency_score = calcEfficiencyFormonth( buildings,  building_counter, reading[j].consumption_value,currentBuildingName);
                    break;
                }
            }

            if (first_record) {
                min_consumption = curr_efficiency_score;
                max_consumption = curr_efficiency_score;
                most_efficient_building = currentBuildingName;
                least_efficient_building = currentBuildingName;
                first_record = false;
            }
            else {
                if (curr_efficiency_score < min_consumption) {
                    min_consumption = curr_efficiency_score;
                    least_efficient_building = currentBuildingName;
                }
                if (curr_efficiency_score > max_consumption) {
                    max_consumption = curr_efficiency_score;
                    most_efficient_building = currentBuildingName;
                }
            }
        }
    }

    int unresolved = 0, resolved = 0;
    for (int i = 0; i < alert_counter; i++) {
        if (alerts[i].month == target_month) {
            if (alerts[i].status == "Resolved") resolved++;
            else unresolved++;
        }
    }


    cout << "___________________________________" << endl;
    cout << " ______MONTHLY CAMPUS REPORT______ " << endl;
    cout << "The total campus consumption : " << total_consumption << "KWh" << endl;
    cout << "The most efficient building is " << most_efficient_building << endl;
    cout << "The least efficient building is " << least_efficient_building << endl;
    cout << "Number of unresolved alerts: " << unresolved << endl;
    cout << "Number of resolved alerts: " << resolved << endl;
    cout << "-----------------------------" << endl;

        cout << "1. Back to menu" << endl;
        cout << "2. Quit and save" << endl;
    int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
            menu();
        else if (choice == 2) {
            return;
        }
        else
            cout << "Invalid choice! Please try again." << endl;

    } while (choice != 1 && choice != 2 );

}

