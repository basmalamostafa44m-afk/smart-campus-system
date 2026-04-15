#pragma once
#include <string>
using namespace std;
// declare admin struct
struct Admin {
	int Admin_ID;
	string user_name;
	string password;
};
// declare function to validate admin login ---> sama
bool Admin_login(Admin admins[], int current_count, string inputUser_name, string inputPassword);


// declare function to sign up new admin ---> sama



