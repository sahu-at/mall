#ifndef CINEMA_H
#define CINEMA_H
#include <iostream>
#include <fstream>
using namespace std;

bool seats[5][10] = {false};

void cinemaHall() {
    int row, col;

    cout << "\n--- Seat Map ---\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            cout << (seats[i][j] ? "X " : "O ");
        }
        cout << endl;
    }

    cout << "Enter row(0-4): ";
    cin >> row;
    cout << "Enter col(0-9): ";
    cin >> col;

    if (!seats[row][col]) {
        seats[row][col] = true;
        cout << "Booked! Rs.200\n";

        ofstream file("cinema.txt", ios::app);
        file << 200 << endl;
        file.close();
    } else {
        cout << "Seat already booked!\n";
    }
}

#endif