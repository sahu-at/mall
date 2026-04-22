#include <iostream>
#include "admin.h"
#include "food.h"
#include "cinema.h"
#include "parking.h"
#include "gaming.h"
#include "customer.h"
#include "employee.h"
#include "fileio.h"

using namespace std;

int main() {

    if (!adminLogin()) return 0;

    int choice;

    do {
        cout << "\n==== MALL MANAGEMENT SYSTEM ====\n";
        cout << "1. Shop (Food Court)\n";
        cout << "2. Gaming Zone\n";
        cout << "3. Cinema Hall\n";
        cout << "4. Parking\n";
        cout << "5. Customer\n";
        cout << "6. Employee\n";
        cout << "7. Revenue Report\n";
        cout << "0. Exit\n";

        cin >> choice;

        switch (choice) {
            case 1: foodCourt(); break;
            case 2: gamingZone(); break;
            case 3: cinemaHall(); break;
            case 4: parkingZone(); break;
            case 5: customerMgmt(); break;
            case 6: employeeMgmt(); break;
            case 7: showReport(); break;
        }

    } while (choice != 0);

    return 0;
}