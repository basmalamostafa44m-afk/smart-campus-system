#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
//define function to validate admin login ---> sama

bool Admin_login(Admin admins[], int current_admin_numbers, string inputUser_name, string inputPassword) {
		for (int i = 0; i < current_admin_numbers; i++) {
			if (admins[i].user_name == inputUser_name && admins[i].password == inputPassword)
				return true;
	}
	return false;
}


void admin_signup(Admin admins[], int & current_admin_numbers, string newuser, string newpass) {
    if (current_admin_numbers < Number_of_Admins) {
        admins[current_admin_numbers].Admin_ID = current_admin_numbers + 1;
        admins[current_admin_numbers].user_name = newuser;
        admins[current_admin_numbers].password = newpass;
        current_admin_numbers++;
        cout << " Admin created successfully" << endl;
    }
    else {
        cout << " sorry! Admin database is full " << endl;
    }
}

//define function to sign up new admin ---> sama

