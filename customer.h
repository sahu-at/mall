#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_CUSTOMERS = 100;

// ================= STRUCT =================
struct Customer {
    int id;
    string name;
    string phone;
    int visits;
    int points;
};

static Customer customers[MAX_CUSTOMERS];
static int customerCount = 0;

// ================= FIND =================
int findCustomer(string name, string phone) {
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].name == name &&
            customers[i].phone == phone)
            return i;
    }
    return -1;
}

// ================= LOAD =================
void loadCustomers() {

    customerCount = 0;

    ifstream file("customers.txt");

    if (file.is_open()) {

        Customer temp;

        while (file >> temp.id
                    >> temp.name
                    >> temp.phone
                    >> temp.visits
                    >> temp.points) {

            int index = findCustomer(temp.name, temp.phone);

            if (index == -1) {
                customers[customerCount] = temp;
                customerCount++;
            }
            else {
                customers[index].visits += temp.visits;
                customers[index].points += temp.points;
            }
        }

        file.close();
    }
}

// ================= SAVE CLEAN BILL STYLE =================
void saveCustomers() {

    ofstream file("customers.txt");

    file << "==============================================================\n";
    file << left
         << setw(6)  << "ID"
         << setw(18) << "NAME"
         << setw(18) << "PHONE"
         << setw(10) << "VISITS"
         << setw(10) << "POINTS" << endl;

    file << "==============================================================\n";

    for (int i = 0; i < customerCount; i++) {

        file << left
             << setw(6)  << i + 1
             << setw(18) << customers[i].name
             << setw(18) << customers[i].phone
             << setw(10) << customers[i].visits
             << setw(10) << customers[i].points
             << endl;
    }

    file << "==============================================================\n";

    file.close();
}

// ================= REGISTER =================
void registerCustomer() {

    string name, phone;

    cout << "\nEnter Customer Name  : ";
    cin >> name;

    cout << "Enter Phone Number   : ";
    cin >> phone;

    int index = findCustomer(name, phone);

    // Existing
    if (index != -1) {

        customers[index].visits++;
        customers[index].points += 100;

        saveCustomers();

        cout << "\n=====================================\n";
        cout << "         WELCOME BACK\n";
        cout << "=====================================\n";
        cout << "Customer ID   : " << index + 1 << endl;
        cout << "Visit Count   : " << customers[index].visits << endl;
        cout << "Bonus Added   : 100 Points\n";
        cout << "Total Points  : " << customers[index].points << endl;
        cout << "=====================================\n";

        return;
    }

    // New
    Customer c;

    c.id = customerCount + 1;
    c.name = name;
    c.phone = phone;
    c.visits = 1;
    c.points = 50;

    customers[customerCount] = c;
    customerCount++;

    saveCustomers();

    cout << "\n=====================================\n";
    cout << "     NEW CUSTOMER REGISTERED\n";
    cout << "=====================================\n";
    cout << "Customer ID   : " << customerCount << endl;
    cout << "Visit Count   : 1\n";
    cout << "Bonus Added   : 50 Points\n";
    cout << "=====================================\n";
}

// ================= VIEW =================
void viewCustomers() {

    if (customerCount == 0) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\n==============================================================\n";
    cout << left
         << setw(6)  << "ID"
         << setw(18) << "NAME"
         << setw(18) << "PHONE"
         << setw(10) << "VISITS"
         << setw(10) << "POINTS" << endl;

    cout << "==============================================================\n";

    for (int i = 0; i < customerCount; i++) {

        cout << left
             << setw(6)  << i + 1
             << setw(18) << customers[i].name
             << setw(18) << customers[i].phone
             << setw(10) << customers[i].visits
             << setw(10) << customers[i].points
             << endl;
    }

    cout << "==============================================================\n";
}

// ================= SEARCH =================
void searchCustomer() {

    int id;

    cout << "\nEnter Customer ID : ";
    cin >> id;

    if (id <= 0 || id > customerCount) {
        cout << "Customer not found!\n";
        return;
    }

    int i = id - 1;

    cout << "\n=====================================\n";
    cout << "        CUSTOMER DETAILS\n";
    cout << "=====================================\n";
    cout << "ID       : " << id << endl;
    cout << "Name     : " << customers[i].name << endl;
    cout << "Phone    : " << customers[i].phone << endl;
    cout << "Visits   : " << customers[i].visits << endl;
    cout << "Points   : " << customers[i].points << endl;
    cout << "=====================================\n";
}

// ================= REDEEM =================
void redeemPoints() {

    int id, redeem;

    cout << "\nEnter Customer ID : ";
    cin >> id;

    if (id <= 0 || id > customerCount) {
        cout << "Customer not found!\n";
        return;
    }

    int i = id - 1;

    cout << "Available Points : "
         << customers[i].points << endl;

    cout << "Enter Points To Redeem : ";
    cin >> redeem;

    if (redeem <= 0 || redeem > customers[i].points) {
        cout << "Invalid points!\n";
        return;
    }

    customers[i].points -= redeem;

    saveCustomers();

    cout << "\n=====================================\n";
    cout << "        REDEEM SUCCESSFUL\n";
    cout << "=====================================\n";
    cout << "Points Used      : " << redeem << endl;
    cout << "Discount Value   : Rs." << redeem << endl;
    cout << "Remaining Points : " << customers[i].points << endl;
    cout << "=====================================\n";
}

// ================= MAIN =================
void customerMgmt() {

    loadCustomers();

    int choice;

    do {
        cout << "\n============== CUSTOMER MANAGEMENT ==============\n";
        cout << "1. Register / Visit Customer\n";
        cout << "2. View All Customers\n";
        cout << "3. Search Customer\n";
        cout << "4. Redeem Points\n";
        cout << "0. Exit\n";
        cout << "=================================================\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {

        case 1:
            registerCustomer();
            break;

        case 2:
            viewCustomers();
            break;

        case 3:
            searchCustomer();
            break;

        case 4:
            redeemPoints();
            break;

        case 0:
            saveCustomers();
            cout << "Returning to Main Menu...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);
}

#endif