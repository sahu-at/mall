#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;

bool adminLogin() {
    string user, pass;

    cout << "\n--- Admin Login ---\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if (user == "admin" && pass == "mall123") {
        cout << "Login Successful!\n";
        return true;
    } else {
        cout << "Access Denied!\n";
        return false;
    }
}

#endif