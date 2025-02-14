// Coder        : CHEAH CHEE KANG//
// Matrix no.   : 23302124//
// Function     : ABBLE TO USE THIS .CPP FOR RENT LOCKERS AND PRINT OUT THE TOTAL PRICE OF LOCKERS//

#include "header.hpp"

using namespace std;

//To getting information of locker by customer//
void tsystem::rentlocker(){
    char choice;
    const double pricePerLocker = 10.0; 
    int numberOfLockers;
    double totallockerPrice;
    cout << "Welcome to the Locker Rental System!" << endl;
    do {
    cout << "Price per Locker: RM10.00";
    cout << "\nEnter the number of lockers you want to rent: ";
    cin >> numberOfLockers;
    if (numberOfLockers < 0) {
    cerr << "Error: Number of lockers must be a positive value!" << endl;
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
    cout << "\nDo you want to change number of lockers? (y/n): ";
    cin >> choice;}

    } while (choice == 'y' || choice == 'Y');
    
    cout << "Thank you for using our locker rental service!" << endl;

    tsystem::locker = numberOfLockers;

    string data;
    ifstream infile(username + "_data.txt");
    if (infile) {
        string line;
        while (getline(infile, line)) {
            if (line.find("locker:") == 0) {
                continue; // Skip the locker line
            }
            data += line + "\n"; // Keep other data
        }
        infile.close();
    }

    ofstream outfile(tsystem::username + "_data.txt");
    outfile << "locker:" << locker << "\n";
    outfile << data;
    outfile.close();
}

