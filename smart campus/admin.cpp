#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
#include "admin.h"
using namespace std;
//define function to validate admin login ---> sama
bool Admin_login(string inputUser_name, string inputPassword) {
	for (int i = 0; i < Number_of_Admins; i++) {
		if (admins[i].user_name == inputUser_name && admins[i].password == inputPassword)
			return true;
	}
	return false;
}



//define function to sign up new admin ---> sama

