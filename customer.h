#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <fstream>
using namespace std;

void customerMgmt() {
    string name;
    cout << "Enter customer name: ";
    cin >> name;

    ofstream file("customer.txt", ios::app);
    file << name << endl;
    file.close();

    cout << "Customer Registered!\n";
}

#endif