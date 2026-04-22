#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Order
{
    string name;
    int qty;
    int price;
};

void showItems(string items[], int price[], int size)
{
    cout << "\nPlease select an item:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << items[i] << " - Rs." << price[i] << endl;
    }
    cout << "Enter your choice: ";
}

void foodCourt()
{
    int category, choice, qty;
    float total = 0;

    vector<Order> orders;

    do
    {
        cout << "\n========== FOOD COURT ==========\n";
        cout << "Please choose a category:\n";
        cout << "--------------------------------\n";
        cout << "1. Fast Food\n";
        cout << "2. Pizza\n";
        cout << "3. Drinks\n";
        cout << "4. Cafe\n";
        cout << "5. Indian Food\n";
        cout << "0. Generate Bill & Exit\n";
        cout << "--------------------------------\n";
        cout << "Enter your choice: ";

        cin >> category;

        switch (category)
        {

        case 1:
        {
            string items[] = {"Burger", "Fries", "Sandwich", "Hot Dog", "Wrap", "Nuggets", "Pasta", "Maggi", "Spring Roll", "Cheese Balls"};
            int price[] = {100, 80, 120, 90, 110, 130, 140, 60, 150, 160};

            showItems(items, price, 10);
            cin >> choice;

            cout << "Enter quantity: ";
            cin >> qty;

            orders.push_back({items[choice - 1], qty, price[choice - 1]});
            total += price[choice - 1] * qty;
            cout << "Item added successfully!\n";
            break;
        }

        case 2:
        {
            string items[] = {"Margherita", "Farmhouse", "Cheese Burst", "Veg Loaded", "Paneer Pizza", "Corn Pizza", "Tandoori Pizza", "Mexican Pizza", "Deluxe Veg", "Double Cheese"};
            int price[] = {200, 300, 350, 280, 320, 260, 340, 360, 400, 450};

            showItems(items, price, 10);
            cin >> choice;

            cout << "Enter quantity: ";
            cin >> qty;

            orders.push_back({items[choice - 1], qty, price[choice - 1]});
            total += price[choice - 1] * qty;
            cout << "Item added successfully!\n";
            break;
        }

        case 3:
        {
            string items[] = {"Coke", "Pepsi", "Sprite", "Fanta", "Juice", "Lassi", "Cold Drink", "Milkshake", "Energy Drink", "Mocktail"};
            int price[] = {40, 40, 40, 40, 60, 70, 50, 120, 150, 180};

            showItems(items, price, 10);
            cin >> choice;

            cout << "Enter quantity: ";
            cin >> qty;

            orders.push_back({items[choice - 1], qty, price[choice - 1]});
            total += price[choice - 1] * qty;
            cout << "Item added successfully!\n";
            break;
        }

        case 4:
        {
            string items[] = {"Coffee", "Cold Coffee", "Tea", "Green Tea", "Cappuccino", "Latte", "Espresso", "Mocha", "Hot Chocolate", "Iced Latte"};
            int price[] = {50, 100, 30, 40, 120, 130, 110, 140, 150, 160};

            showItems(items, price, 10);
            cin >> choice;

            cout << "Enter quantity: ";
            cin >> qty;

            orders.push_back({items[choice - 1], qty, price[choice - 1]});
            total += price[choice - 1] * qty;
            cout << "Item added successfully!\n";
            break;
        }

        case 5:
        {
            string items[] = {"Thali", "Biryani", "Paneer", "Dal Rice", "Roti Sabzi", "Chole Bhature", "Rajma Rice", "Veg Pulao", "Kadhi Rice", "Butter Chicken"};
            int price[] = {150, 180, 200, 120, 130, 160, 140, 170, 150, 250};

            showItems(items, price, 10);
            cin >> choice;

            cout << "Enter quantity: ";
            cin >> qty;

            orders.push_back({items[choice - 1], qty, price[choice - 1]});
            total += price[choice - 1] * qty;
            cout << "Item added successfully!\n";
            break;
        }

        case 0:
            cout << "\nGenerating your final bill...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
        }

    } while (category != 0);

    // Bill Calculation
    float gst = total * 0.05;
    float discount = (total > 1000) ? total * 0.10 : 0;
    float finalTotal = total + gst - discount;

    // Display Bill
    cout << "\n=========== FINAL BILL ===========\n";
    for (auto &o : orders)
    {
        cout << o.name << " x " << o.qty << " = Rs." << o.qty * o.price << endl;
    }

    cout << "---------------------------------\n";
    cout << "Subtotal: Rs." << total << endl;
    cout << "GST (5%): Rs." << gst << endl;
    cout << "Discount: Rs." << discount << endl;
    cout << "Total Payable: Rs." << finalTotal << endl;

    // Save to File
    ofstream file("food.txt", ios::app);
    file << "\n--- New Order ---\n";
    for (auto &o : orders)
    {
        file << o.name << " x " << o.qty << " = " << o.qty * o.price << endl;
    }
    file << "Final Total: " << finalTotal << endl;
    file.close();

    cout << "Order saved successfully!\n";
}

#endif