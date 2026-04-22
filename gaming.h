#ifndef GAMING_H
#define GAMING_H
#include <iostream>
#include <fstream>
using namespace std;

void gamingZone() {
    int choice;
    cout << "\n1. Tic-Tac-Toe\n2. Snake Game\n";
    cin >> choice;

    cout << "Session Fee Rs.50\n";

    ofstream file("gaming.txt", ios::app);
    file << 50 << endl;
    file.close();

    if (choice == 1) {
        cout << "Tic Tac Toe Started!\n";
    } else {
        cout << "Snake Game Started!\n";
    }
}

#endif