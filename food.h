#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <fstream>
using namespace std;

void foodCourt() {
    int category, choice, qty;
    float total = 0;

    do {
        cout << "\n====== FOOD COURT ======\n";
        cout << "1. Fast Food\n";
        cout << "2. Pizza\n";
        cout << "3. Drinks\n";
        cout << "4. Cafe\n";
        cout << "5. Indian Food\n";
        cout << "0. Generate Bill\n";
        cout << "Select Category: ";
        cin >> category;

        switch (category) {

        case 1: {
            string items[] = {"Burger", "Fries", "Sandwich"};
            int price[] = {100, 80, 120};

            for (int i = 0; i < 3; i++)
                cout << i+1 << ". " << items[i] << " - Rs." << price[i] << endl;

            cout << "Choice: ";
            cin >> choice;
            cout << "Qty: ";
            cin >> qty;

            cout << items[choice-1] << " x " << qty << endl;
            total += price[choice-1] * qty;
            break;
        }

        case 2: {
            string items[] = {"Margherita", "Farmhouse", "Cheese Burst"};
            int price[] = {200, 300, 350};

            for (int i = 0; i < 3; i++)
                cout << i+1 << ". " << items[i] << " - Rs." << price[i] << endl;

            cin >> choice >> qty;
            total += price[choice-1] * qty;
            break;
        }

        case 3: {
            string items[] = {"Coke", "Pepsi", "Juice"};
            int price[] = {40, 40, 60};

            for (int i = 0; i < 3; i++)
                cout << i+1 << ". " << items[i] << " - Rs." << price[i] << endl;

            cin >> choice >> qty;
            total += price[choice-1] * qty;
            break;
        }

        case 4: {
            string items[] = {"Coffee", "Cold Coffee", "Tea"};
            int price[] = {50, 100, 30};

            for (int i = 0; i < 3; i++)
                cout << i+1 << ". " << items[i] << " - Rs." << price[i] << endl;

            cin >> choice >> qty;
            total += price[choice-1] * qty;
            break;
        }

        case 5: {
            string items[] = {"Thali", "Biryani", "Paneer"};
            int price[] = {150, 180, 200};

            for (int i = 0; i < 3; i++)
                cout << i+1 << ". " << items[i] << " - Rs." << price[i] << endl;

            cin >> choice >> qty;
            total += price[choice-1] * qty;
            break;
        }

        }

    } while (category != 0);

    // GST + Discount
    float gst = total * 0.05;
    float discount = (total > 500) ? total * 0.10 : 0;

    float finalTotal = total + gst - discount;

    cout << "\n======= BILL =======\n";
    cout << "Subtotal: Rs." << total << endl;
    cout << "GST (5%): Rs." << gst << endl;
    cout << "Discount: Rs." << discount << endl;
    cout << "Total: Rs." << finalTotal << endl;

    ofstream file("food.txt", ios::app);
    file << finalTotal << endl;
    file.close();
}

#endif