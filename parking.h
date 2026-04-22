#ifndef PARKING_H
#define PARKING_H
#include <iostream>
#include <fstream>
using namespace std;

int slots = 20;

void parkingZone() {
    int choice;
    cout << "\n1. Check-In\n2. Check-Out\n";
    cin >> choice;

    if (choice == 1) {
        if (slots > 0) {
            slots--;
            cout << "Vehicle Parked!\n";
        } else {
            cout << "Parking Full!\n";
        }
    } else {
        int hours;
        cout << "Enter hours: ";
        cin >> hours;

        int fee = hours * 20;
        slots++;

        cout << "Fee: Rs." << fee << endl;

        ofstream file("parking.txt", ios::app);
        file << fee << endl;
        file.close();
    }
}

#endif