#include "header.hpp"

//IM NOT DONE WITH THE CODING YETTT (PLS DONT JUDGE TT)

void tsystem::printreceipt() {

    ifstream final(username + "_data.txt");
    int adult_ticket, children_ticket, senior_ticket, locker_amount, quantity;
    double price;
    string food_name;

    if (!final) {
    cout << "Error: Unable to open file for user " << username << ".\n";
    return;
    }   
    
    string line;
    while (getline(final, line)) {
        if (line.find("tickets:") == 0) {
            string tickets = line.substr(8);
            sscanf(tickets.c_str(), "%d,%d,%d", &adult_ticket, &children_ticket, &senior_ticket);
        }
        else if (line.find("locker:") == 0) {
            string lockers = line.substr(7);
            sscanf(lockers.c_str(), "%d", &locker_amount);
        }

        else if (line.find("order:") == 0) {
            string order = line.substr(6); // Extract order data
            stringstream ss(order);
            string quantity_str, price_str;
        
            getline(ss, quantity_str, ',');
            getline(ss, food_name, ',');
            getline(ss, price_str, ',');

            price = stod(price_str);
            quantity = stoi(quantity_str);
        }
    }

    final.close();

    cout << "\n==================== Receipt ====================" << endl;
    cout << fixed << setprecision(2);

    // Locker details
    cout << "Locker Rental:" << endl;
    cout << "  Number of Lockers: " << locker_amount << endl;
    cout << "  Price per Locker: RM10.00" << endl;
    cout << "  Total Locker Price: RM" << locker_amount * 10.0 << endl;

    // Ticket details
    cout << "\nTickets Purchased:" << endl;
    cout << "  Adults:    " << adult_ticket << " x RM20.00 = RM" << adult_ticket * 20.0 << endl;
    cout << "  Children:  " << children_ticket << " x RM10.00 = RM" << children_ticket * 10.0 << endl;
    cout << "  Seniors:   " << senior_ticket << " x RM15.00 = RM" << senior_ticket * 15.0 << endl;

    // Calculate total
   
    cout << "\n-----------------------------------------------" << endl;
    cout << "Total Price: RM" << totalPrice << endl;
    cout << "================================================" << endl;
    cout << "Thank you for using our service!" << endl;
}
