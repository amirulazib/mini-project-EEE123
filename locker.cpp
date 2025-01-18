#include <iostream>
#include <iomanip>
#include "locker.hpp"

using namespace std;

//To getting information of locker by customer//
void rentlocker(){
    char choice;
    const double pricePerLocker = 10.0; 
    int numberOfLockers;
    double totallockerPrice;
    cout << "Welcome to the Locker Rental System!" << endl;
    do {
    cout << "Price per Locker: RM10.00";
    cout << "\nEnter the number of lockers you want to rent: ";
    cin >> numberOfLockers;
    if (numberOfLockers <= 0) {
    cerr << "Error: Number of lockers must be greater than 0!" << endl;
    }
    else {
    totallockerPrice = numberOfLockers * pricePerLocker;
    cout << fixed << setprecision(2);
    cout << "\n--- Rental Summary ---" << endl;
    cout << "Number of Lockers: " << numberOfLockers << endl;
    cout << "Price per Locker: RM" << pricePerLocker << endl;
    cout << "Total Price: RM" << totallockerPrice << endl;
    cout << "-----------------------" << endl;
    cout << "Locker rental details saved successfully!" << endl;
    cout << "\nDo you want to rent lockers again? (y/n): ";
    cin >> choice;}

    } while (choice == 'y' || choice == 'Y');
    
    cout << "Thank you for using our locker rental service!" << endl;

}

