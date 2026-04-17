#pragma once
#include <string>
using namespace std;
const int Number_of_Admins = 5;
// declare admin struct
struct Admin {
	int Admin_ID;
	string user_name;
	string password;
};
// declare function to validate admin login ---> sama
bool Admin_login(Admin admins[], int & current_admin_numbers);
void admin_signup(Admin admins[], int& current_admin_numbers, string newuser, string newpass);


// declare function to sign up new admin ---> sama



