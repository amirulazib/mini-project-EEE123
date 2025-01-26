// Coder        : LIMUZI
// Matrix no.   : 23300188
// Function     : Check what customers are buying

#include "header.hpp"

void tsystem::checkpurchases(){    
    cout << "\nOrder Summary:\n";

    ifstream final(username + "_data.txt");

    if (!final) {
    cout << "Error: Unable to open file for user " << username << ".\n";
    return;
}
    
    string line;
    while (getline(final, line)) {
        if (line.find("tickets:") == 0) {             // Finds ticket data from "username_data.txt"
            string tickets = line.substr(8); // Extract ticket data
            int adult_ticket, children_ticket, senior_ticket;
            sscanf(tickets.c_str(), "%d,%d,%d", &adult_ticket, &children_ticket, &senior_ticket); 
            cout << "\nTickets Bought:\n";
            if (adult_ticket > 0){
                cout << "  Adult: " << adult_ticket << "\n";
            }
            if (children_ticket > 0){
                cout << "  Children: " << children_ticket << "\n";
            }
            if (senior_ticket > 0){
                cout << "  Senior: " << senior_ticket << "\n";
            }
            if (adult_ticket == 0 && children_ticket == 0 && senior_ticket == 0){
                cout << "  None" << endl;
            }
        }

        else if (line.find("locker:") == 0) {        // Finds locker data from "username_data.txt"
            string lockers = line.substr(7); // Extract locker data
            int locker_amount;
            sscanf(lockers.c_str(), "%d", &locker_amount);
            cout << "\nLocker rented: ";
            if (locker > 0){
                cout << locker_amount << endl;
            }
            else{
                cout << "0" << endl;
            }
        }

        else if (line.find("order:") == 0) {        // Finds food data from "username_data.txt"
            string order = line.substr(6); // Extract order data
            stringstream ss(order);
            string quantity_str, food_name, price_str;
        
            getline(ss, quantity_str, ',');
            getline(ss, food_name, ',');
            getline(ss, price_str, ',');

            double price = stod(price_str);
            int quantity = stoi(quantity_str);

            cout << "\nFood Order:\n";
            cout << "  Name: " << food_name << "\n";
            cout << "  Price: RM " << price << "\n";
            cout << "  Quantity: " << quantity << "\n";
            
        }
    }

    final.close();

    cout << "\nPress any key to continue...";
    getch();
}
