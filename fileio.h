#ifndef FILEIO_H
#define FILEIO_H
#include <iostream>
#include <fstream>
using namespace std;

int readTotal(string filename) {
    ifstream file(filename);
    int x, sum = 0;

    while (file >> x) sum += x;

    return sum;
}

void showReport() {
    int total =
        readTotal("food.txt") +
        readTotal("cinema.txt") +
        readTotal("parking.txt") +
        readTotal("gaming.txt");

    cout << "\n--- Revenue Report ---\n";
    cout << "Total Revenue: Rs." << total << endl;
}

#endif