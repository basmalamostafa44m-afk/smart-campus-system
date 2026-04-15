#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
//define function to validate admin login ---> sama


bool Admin_login(Admin admins[], int current_count, string inputUser_name, string inputPassword) {
    for (int i = 0; i < current_count; i++) {
        if (admins[i].user_name == inputUser_name && admins[i].password == inputPassword) {
            return true;
        }
    }
    return false;
}


void admin_signup(Admin admins[], int &current_count, string newuser, string newpass) {
    if (current_count < Number_of_Admins) { 
        admins[current_count].Admin_ID = current_count + 1;
        admins[current_count].user_name = newuser;
        admins[current_count].password = newpass;
        current_count++; 
        cout << " Admin created successfully" << endl;
    }
    else {
        cout << " sorry! Admin database is full " << endl;
    }
}

//define function to sign up new admin ---> sama
