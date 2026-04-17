#include "admin.h"
#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
using namespace std;


//define function to sign up new admin ---> sama
void admin_signup(Admin admins[], int& current_admin_numbers, string newuser, string newpass) {
    if (current_admin_numbers < Number_of_Admins) {
        admins[current_admin_numbers].Admin_ID = current_admin_numbers + 1;
        admins[current_admin_numbers].user_name = newuser;
        admins[current_admin_numbers].password = newpass;
        current_admin_numbers++;
        cout << " Admin created successfully" << endl;
    }
    else 
        cout << " sorry! Admin database is full " << endl;
}
//define function to validate admin login ---> sama
string answer;
bool Admin_login(Admin admins[], int& current_admin_numbers) {
    cout << "Welcome to smart campus energy consumption monitor!!" << endl;
    cout << "Do you have an account?";
    cin >> answer;
    if (answer == "yes" || answer == "y" || answer == "Y") {
        string inputUser_name, inputPassword;
        cout << "Enter your username and password";
        cin >> inputUser_name;
        cin >> inputPassword;
        for (int i = 0; i < current_admin_numbers; i++) {
            if (admins[i].user_name == inputUser_name && admins[i].password == inputPassword)
                return true;
        }
        return false;
    }

    else if (answer == "no" || answer == "n" || answer == "N") {
        string newuser, newpass;
        cout << "please enter username and password for your new account" << endl;
        cin >> newuser;
        cin >> newpass;
        admin_signup( admins, current_admin_numbers, newuser, newpass);
        return true;
    }

