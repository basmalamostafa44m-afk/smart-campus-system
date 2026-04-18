#include "admin.h"
#include<iostream>
#include<string>
#include "building.h"
#include "alert.h"
#include "reading.h"
using namespace std;

//define function to sign up new admin ---> sama
void Admin_login(Admin admins[], int& current_admin_numbers) {
    
    cout << "Do you have an account?";
	string answer;
    cin >> answer;
    if (answer == "yes" || answer == "y" || answer == "Y") {
        string inputUser_name, inputPassword;
        cout << "Enter your username: ";
		cin.ignore(); // Ignore the newline character left in the input buffer
		getline(cin, inputUser_name);
        cout << "Enter your password: ";
		cin.ignore(); 
        getline(cin, inputPassword);
		bool found = false;
        for (int i = 0; i < current_admin_numbers; i++) {
            if (admins[i].user_name == inputUser_name && admins[i].password == inputPassword) {
				found = true;
                menu();
            }
                
        }
        if (!found) {
			cout << "Invalid username or password!" << endl;
			cout << "1. Try again" << endl;
			cout << "2.Quit" << endl;
			int choice;
			cout << "Enter your choice: ";
			cin >> choice;
            if(choice == 1)
			Admin_login(admins, current_admin_numbers);
            else if (choice == 2) {
				return;
            }
        }
       
    }

    else if (answer == "no" || answer == "n" || answer == "N") {
        admin_signup(admins, current_admin_numbers);
      
    }
}


void admin_signup(Admin admins[], int& current_admin_numbers) {
   
    if (current_admin_numbers < 5) {
        string newuser, newpass;
        cout << "please enter username: "<< endl;
		cin.ignore(); 
		getline(cin, newuser);
		cout << "please enter password: " << endl;
		cin.ignore();
		getline(cin, newpass);
        admins[current_admin_numbers].Admin_ID = current_admin_numbers + 1;
        admins[current_admin_numbers].user_name = newuser;
        admins[current_admin_numbers].password = newpass;
        current_admin_numbers++;
        cout << " Admin created successfully" << endl;
		cout << " Please log in with your new account " << endl;
		Admin_login(admins, current_admin_numbers);
    }
    else 
        cout << " sorry! Admin database is full " << endl;
}
