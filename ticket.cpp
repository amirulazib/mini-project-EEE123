// Coder        : 
// Matrix no.   : 
// Function     : 

#include "header.hpp"

void tsystem::ticket(){
    int tic_choice;
    int adult_count = 0;
    int children_count = 0;
    int senior_count = 0;
    while (true){
        while(true){
            cout << "\n__________________________________________________" << endl;
            cout << "Please select the type of ticket you want to book:" << endl;
            cout << "   1. Adult (RM 20.00)     " << endl;
            cout << "   2. Children (RM 10.00)  " << endl;
            cout << "   3. Senior (RM 15.00)    " << endl;
            cout << "__________________________________________________" << endl;

            cout << "Select an option: " ;
            cin >> tic_choice;

            if (tic_choice < 1 || tic_choice > 3){
            cout << "Invalid selection. Please try again." << endl;
            }
            else{
            break;
            }
        }
        while(true){
        cout << "\n__________________________________________________" << endl;
        int numTickets;
        cout << "Please enter the number of tickets you wish to purchase: ";
        cin >> numTickets;

        if (numTickets <= 0) {
            cout << "Invalid input. Please enter a positive integer." << endl;
        }
        else{
        cout << "\nYou have selected " << numTickets << " tickets for ";
        switch (tic_choice) {
            case 1:
                cout << "Adult." << endl;
                adult_count = numTickets;
                break;
            case 2:
                cout << "Children." << endl;
                children_count = numTickets;
                break;
            case 3:
                cout << "Senior." << endl;
                senior_count = numTickets;
                break;
            }
            break;
            }
        }
        
        tsystem::ticket1 = adult_count;
        tsystem::ticket2 = children_count;
        tsystem::ticket3 = senior_count;

        string data;
        ifstream infile(username + "_data.txt");
        if (infile) {
            string line;
            while (getline(infile, line)) {
                if (line.find("tickets:") == 0) {
                    continue; // Skip the tickets line
                }
                data += line + "\n"; // Keep other data
            }
            infile.close();
        }

        ofstream outfile(tsystem::username + "_data.txt");
        outfile << "tickets:" << ticket1 << "," << ticket2 << "," << ticket3 << "\n";
        outfile << data;
        outfile.close();

        while (true){
        cout << "\n__________________________________________________" << endl;
        string choice;
        cout << "Do you wish to purchase more tickets? (Y/N): ";
        cin >> choice;

        if (choice == "Y" || choice == "y" ) {
        break;
        } else if (choice == "N" || choice == "n") {
        int price = 0;
        price += 20 * (adult_count) + 10 * (children_count) + 15 * (senior_count);
        cout << "The price is RM " << price << endl;
        cout << "\nReturning to the home page. Thank you!" << endl;
        return;
        } else {
        cout << "Invalid input. Please try again." << endl;
        }
    }
    }
}