#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

const int ROWS = 10;
const int COLS = 11;

// 🔥 static to avoid multiple definition
static int seats[ROWS][COLS] = {0};

int ticketPrice = 200;

// 🔹 Load saved seats
void loadSeats() {
    ifstream file("cinemaSeats.txt");

    if (file.is_open()) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!(file >> seats[i][j])) {
                    seats[i][j] = 0;
                }
            }
        }
        file.close();
    }
}

// 🔹 Save seats
void saveSeats() {
    ofstream file("cinemaSeats.txt");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            file << seats[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}

// 🔹 Show seat map
void showSeats() {
    cout << "\n=========== CINEMA SEAT MAP ===========\n";

    cout << "     ";
    for (int j = 1; j <= COLS; j++)
        cout << j << " ";

    cout << "\n----------------------------------------\n";

    for (int i = 0; i < ROWS; i++) {
        cout << char('A' + i) << "  | ";
        for (int j = 0; j < COLS; j++) {
            cout << (seats[i][j] == 0 ? "O " : "X ");
        }
        cout << endl;
    }

    cout << "\nO = Available | X = Booked\n";
}

// 🔹 Convert row
int getRowIndex(char r) {
    return r - 'A';
}

// 🔹 Main cinema function
void cinemaHall() {

    loadSeats();

    char row;
    int col;
    int bookedCount = 0;
    int choice;

    do {
        cout << "\n========== CINEMA HALL ==========\n";
        cout << "1. View Seat Map\n";
        cout << "2. Book Seat\n";
        cout << "0. Exit & Save\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            showSeats();
            break;
        }

        case 2: {
            showSeats();

            cout << "\nEnter Row (A-J): ";
            cin >> row;
            row = toupper(row);

            cout << "Enter Seat Number (1-11): ";
            cin >> col;

            int r = getRowIndex(row);
            int c = col - 1;

            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
                cout << "Invalid seat selection!\n";
                break;
            }

            if (seats[r][c] == 1) {
                cout << "Seat already booked ❌\n";
            } else {
                seats[r][c] = 1;
                bookedCount++;

                cout << "Seat " << row << col << " booked successfully ✅\n";

                ofstream log("cinema_log.txt", ios::app);
                log << "Booked Seat: " << row << col << endl;
                log.close();
            }

            break;
        }

        case 0: {
            saveSeats();
            cout << "Data saved successfully!\n";
            break;
        }

        default: {
            cout << "Invalid choice!\n";
        }

        }

    } while (choice != 0);

    // 🎟 BILL
    if (bookedCount > 0) {
        int total = bookedCount * ticketPrice;

        cout << "\n=========== BILL ===========\n";
        cout << "Seats booked: " << bookedCount << endl;
        cout << "Price per ticket: Rs." << ticketPrice << endl;
        cout << "Total amount: Rs." << total << endl;

        ofstream file("cinema.txt", ios::app);
        file << "Tickets: " << bookedCount << " Total: " << total << endl;
        file.close();

        cout << "Booking saved successfully!\n";
    } else {
        cout << "\nNo new bookings made.\n";
    }
}

#endif