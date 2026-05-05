#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int MAX_EMP = 100;

// ================= STRUCT =================
struct Employee {
    int id;
    string name;
    string post;
    string shift;
    int salary;
    int presentDays;
};

static Employee emp[MAX_EMP];
static int empCount = 0;

// ================= FIND =================
int findEmployee(string name) {
    for (int i = 0; i < empCount; i++) {
        if (emp[i].name == name)
            return i;
    }
    return -1;
}

// ================= PAYABLE =================
int getPayable(int i) {

    int perDay = emp[i].salary / 30;
    int payable = perDay * emp[i].presentDays;

    // Night Shift +25%
    if (emp[i].shift == "Night" ||
        emp[i].shift == "night") {

        payable += payable * 25 / 100;
    }

    return payable;
}

// ================= LOAD FIXED =================
void loadEmployees() {

    empCount = 0;

    ifstream file("employees.txt");

    if (!file.is_open())
        return;

    string line;

    while (getline(file, line)) {

        if (line.empty()) continue;
        if (line[0] == '=') continue;

        if (line.find("ID") != string::npos &&
            line.find("NAME") != string::npos)
            continue;

        stringstream ss(line);

        ss >> emp[empCount].id
           >> emp[empCount].name
           >> emp[empCount].post
           >> emp[empCount].shift
           >> emp[empCount].salary
           >> emp[empCount].presentDays;

        if (!ss.fail()) {
            empCount++;
        }
    }

    file.close();
}

// ================= SAVE =================
void saveEmployees() {

    ofstream file("employees.txt");

    file << "========================================================================================================\n";
    file << left
         << setw(5)  << "ID"
         << setw(18) << "NAME"
         << setw(18) << "POST"
         << setw(12) << "SHIFT"
         << setw(12) << "SALARY"
         << setw(10) << "DAYS"
         << setw(12) << "PAYABLE" << endl;

    file << "========================================================================================================\n";

    for (int i = 0; i < empCount; i++) {

        file << left
             << setw(5)  << emp[i].id
             << setw(18) << emp[i].name
             << setw(18) << emp[i].post
             << setw(12) << emp[i].shift
             << setw(12) << emp[i].salary
             << setw(10) << emp[i].presentDays
             << setw(12) << getPayable(i)
             << endl;
    }

    file << "========================================================================================================\n";

    file.close();
}

// ================= ADD =================
void addEmployee() {

    if (empCount >= MAX_EMP) {
        cout << "Employee limit reached!\n";
        return;
    }

    Employee e;
    e.id = empCount + 1;

    cout << "\nEnter Employee Name : ";
    cin >> e.name;

    if (findEmployee(e.name) != -1) {
        cout << "Employee already exists!\n";
        return;
    }

    cout << "Enter Post : ";
    cin >> e.post;

    cout << "Enter Shift (Day/Night): ";
    cin >> e.shift;

    cout << "Enter Monthly Salary : ";
    cin >> e.salary;

    e.presentDays = 0;

    emp[empCount] = e;
    empCount++;

    saveEmployees();

    cout << "\nEmployee Added Successfully!\n";
}

// ================= VIEW =================
void viewEmployees() {

    if (empCount == 0) {
        cout << "\nNo employee records found.\n";
        return;
    }

    cout << "\n========================================================================================================\n";
    cout << left
         << setw(5)  << "ID"
         << setw(18) << "NAME"
         << setw(18) << "POST"
         << setw(12) << "SHIFT"
         << setw(12) << "SALARY"
         << setw(10) << "DAYS"
         << setw(12) << "PAYABLE" << endl;

    cout << "========================================================================================================\n";

    for (int i = 0; i < empCount; i++) {

        cout << left
             << setw(5)  << emp[i].id
             << setw(18) << emp[i].name
             << setw(18) << emp[i].post
             << setw(12) << emp[i].shift
             << setw(12) << emp[i].salary
             << setw(10) << emp[i].presentDays
             << setw(12) << getPayable(i)
             << endl;
    }
}

// ================= SEARCH =================
void searchEmployee() {

    int id;

    cout << "\nEnter Employee ID : ";
    cin >> id;

    if (id <= 0 || id > empCount) {
        cout << "Employee not found!\n";
        return;
    }

    int i = id - 1;

    cout << "\n=====================================\n";
    cout << "        EMPLOYEE DETAILS\n";
    cout << "=====================================\n";
    cout << "ID       : " << emp[i].id << endl;
    cout << "Name     : " << emp[i].name << endl;
    cout << "Post     : " << emp[i].post << endl;
    cout << "Shift    : " << emp[i].shift << endl;
    cout << "Salary   : Rs." << emp[i].salary << endl;
    cout << "Days     : " << emp[i].presentDays << endl;
    cout << "Payable  : Rs." << getPayable(i) << endl;
    cout << "=====================================\n";
}

// ================= ATTENDANCE =================
void markAttendance() {

    int id;

    cout << "\nEnter Employee ID : ";
    cin >> id;

    if (id <= 0 || id > empCount) {
        cout << "Employee not found!\n";
        return;
    }

    emp[id - 1].presentDays++;

    saveEmployees();

    cout << "Attendance Marked for "
         << emp[id - 1].name << endl;
}

// ================= REPORT =================
void salaryReport() {

    if (empCount == 0) {
        cout << "\nNo employees found.\n";
        return;
    }

    cout << "\n================ SALARY REPORT ================\n";

    for (int i = 0; i < empCount; i++) {

        cout << "\nID      : " << emp[i].id;
        cout << "\nName    : " << emp[i].name;
        cout << "\nShift   : " << emp[i].shift;
        cout << "\nDays    : " << emp[i].presentDays;
        cout << "\nPayable : Rs." << getPayable(i);
        cout << "\n------------------------------------";
    }

    cout << "\n";
}

// ================= MAIN =================
void employeeMgmt() {

    loadEmployees();

    int choice;

    do {
        cout << "\n================ EMPLOYEE MANAGEMENT ================\n";
        cout << "1. Add Employee\n";
        cout << "2. View All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Mark Attendance\n";
        cout << "5. Salary Report\n";
        cout << "0. Exit\n";
        cout << "=====================================================\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {

        case 1: addEmployee(); break;
        case 2: viewEmployees(); break;
        case 3: searchEmployee(); break;
        case 4: markAttendance(); break;
        case 5: salaryReport(); break;

        case 0:
            saveEmployees();
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

#endif