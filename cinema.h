#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
using namespace std;

const int ROWS = 10;
const int COLS = 11;

static int seats[ROWS][COLS] = {0};

int normalPrice = 200;
int vipPrice = 300;

// 🔹 Load Seats
void loadSeats() {
    ifstream file("cinemaSeats.txt");

    if (file.is_open()) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (!(file >> seats[i][j]))
                    seats[i][j] = 0;
            }
        }
        file.close();
    }
}

// 🔹 Save Seats
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

// 🔹 Row convert
int getRowIndex(char row) {
    return row - 'A';
}

// 🔹 Show Timings
void showTimings() {
    cout << "\n========= SHOW TIMINGS =========\n";
    cout << "1. Morning Show   (10:00 AM)\n";
    cout << "2. Evening Show   (3:00 PM)\n";
    cout << "3. Night Show     (8:00 PM)\n";
}

// 🔹 Seat Type
string getSeatType(int row) {
    if (row <= 2)
        return "VIP";
    return "Normal";
}

// 🔹 Seat Price
int getSeatPrice(int row) {
    if (row <= 2)
        return vipPrice;
    return normalPrice;
}

// 🔹 Show Seat Map
void showSeats() {

    cout << "\n============= SEAT MAP =============\n";
    cout << "     ";

    for (int j = 1; j <= COLS; j++)
        cout << setw(3) << j;

    cout << endl;

    for (int i = 0; i < ROWS; i++) {

        cout << char('A' + i) << " | ";

        for (int j = 0; j < COLS; j++) {

            if (seats[i][j] == 0)
                cout << setw(3) << "O";
            else
                cout << setw(3) << "X";
        }

        if (i <= 2)
            cout << "   VIP";
        else
            cout << "   Normal";

        cout << endl;
    }

    cout << "\nO = Available   X = Booked\n";
}

// 🔹 Cancel Seat
void cancelSeat() {

    char row;
    int col;

    showSeats();

    cout << "\nEnter Row to Cancel (A-J): ";
    cin >> row;
    row = toupper(row);

    cout << "Enter Seat Number (1-11): ";
    cin >> col;

    int r = getRowIndex(row);
    int c = col - 1;

    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
        cout << "Invalid seat!\n";
        return;
    }

    if (seats[r][c] == 0) {
        cout << "Seat already empty!\n";
    } else {
        seats[r][c] = 0;
        saveSeats();
        cout << "Booking Cancelled Successfully!\n";
    }
}

// 🔹 Main Cinema
void cinemaHall() {

    loadSeats();

    int choice;
    int bookedCount = 0;
    int totalBill = 0;
    int showChoice = 0;

    showTimings();
    cout << "Select Show: ";
    cin >> showChoice;

    do {
        cout << "\n=========== CINEMA HALL ===========\n";
        cout << "1. View Seat Map\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Seat\n";
        cout << "0. Exit & Save\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            showSeats();
            break;
        }

        case 2: {

            char row;
            int col;

            showSeats();

            cout << "\nEnter Row (A-J): ";
            cin >> row;
            row = toupper(row);

            cout << "Enter Seat Number (1-11): ";
            cin >> col;

            int r = getRowIndex(row);
            int c = col - 1;

            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
                cout << "Invalid seat!\n";
                break;
            }

            if (seats[r][c] == 1) {
                cout << "Seat already booked!\n";
            } else {

                seats[r][c] = 1;

                int price = getSeatPrice(r);

                bookedCount++;
                totalBill += price;

                cout << "\nSeat " << row << col
                     << " Booked Successfully!\n";

                cout << "Seat Type : "
                     << getSeatType(r) << endl;

                cout << "Price     : Rs." << price << endl;

                ofstream log("cinema_log.txt", ios::app);
                log << "Seat " << row << col
                    << " Price " << price << endl;
                log.close();
            }

            break;
        }

        case 3: {
            cancelSeat();
            break;
        }

        case 0: {
            saveSeats();
            cout << "Saving Data...\n";
            break;
        }

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    // 🔹 Final Bill
    if (bookedCount > 0) {

        cout << "\n=========== FINAL BILL ===========\n";
        cout << "Show Selected : ";

        if (showChoice == 1)
            cout << "Morning Show\n";
        else if (showChoice == 2)
            cout << "Evening Show\n";
        else
            cout << "Night Show\n";

        cout << "Tickets Booked : " << bookedCount << endl;
        cout << "Total Amount   : Rs." << totalBill << endl;

        ofstream file("cinema.txt", ios::app);
        file << "Show " << showChoice
             << " Tickets " << bookedCount
             << " Total " << totalBill << endl;
        file.close();

        cout << "Bill Saved Successfully!\n";
    }
    else {
        cout << "\nNo New Booking Done.\n";
    }
}

#endif