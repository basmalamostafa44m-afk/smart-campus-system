#pragma once
#include <string>
using namespace std;
// declare admin struct
struct Admin {
	int Admin_ID;
	string user_name;
	string password;
};
void menu();
// declare function to validate admin login ---> sama
void Admin_login(Admin admins[], int & current_admin_numbers);
void admin_signup(Admin admins[], int& current_admin_numbers);


// declare function to sign up new admin ---> sama



