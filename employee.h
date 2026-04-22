#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <fstream>
using namespace std;

void employeeMgmt() {
    string name;
    int salary;

    cout << "Enter employee name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;

    ofstream file("employee.txt", ios::app);
    file << name << " " << salary << endl;
    file.close();

    cout << "Employee Added!\n";
}

#endif