// Coder        : 
// Matrix no.   : 
// Function     : 

#include "header.hpp"


void tsystem::printreceipt() {
    ifstream final(username + "_data.txt");
    int adult_ticket = 0, children_ticket = 0, senior_ticket = 0, locker_amount = 0;
    vector<FoodOrder> food_orders;

    if (!final) {
        cout << "Error: Unable to open file for user " << username << ".\n";
        return;
    }

    string line;
    while (getline(final, line)) {
        if (line.find("tickets:") == 0) {
            string tickets = line.substr(8);
            if (sscanf(tickets.c_str(), "%d,%d,%d", &adult_ticket, &children_ticket, &senior_ticket) != 3) {
                cout << "Error: Invalid ticket data format in the file.\n";
                return;
            }
        } else if (line.find("locker:") == 0) {
            string lockers = line.substr(7);
            if (sscanf(lockers.c_str(), "%d", &locker_amount) != 1) {
                cout << "Error: Invalid locker data format in the file.\n";
                return;
            }
        } else if (line.find("order:") == 0) {
            string order = line.substr(6);
            stringstream ss(order);
            string quantity_str, price_str, food_name;

            getline(ss, quantity_str, ',');
            getline(ss, food_name, ',');
            getline(ss, price_str, ',');

            FoodOrder food;
            food.quantity = stoi(quantity_str);
            food.food_name = food_name;
            food.price = stod(price_str);

            food_orders.push_back(food);
        }
    }

    final.close();

    // Receipt Header
    cout << "\n==================================================================================" << endl;
    cout << "                                    RECEIPT                            " << endl;
    cout << "==================================================================================" << endl;

    cout << "BILL TO: " << username << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    // Table Header
    cout << setw(8) << left << "QTY"
         << setw(40) << "DESCRIPTION"
         << setw(20) << "UNIT PRICE"
         << setw(15) << "AMOUNT" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;

    // Locker Details
    double locker_total = locker_amount * 10.0;
    if (locker_amount > 0) {
        cout << setw(8) << left << locker_amount
             << setw(40) << "Locker Rental"
             << setw(21) << "RM 10.00" 
             << "RM " << fixed << setprecision(2) << locker_total << endl;
    }

    // Ticket Details
    double adult_total = adult_ticket * 20.0;
    if (adult_ticket > 0) {
        cout << setw(8) << left << adult_ticket
             << setw(40) << "Adult Ticket"
             << setw(21) << "RM 20.00"
             << "RM " << fixed << setprecision(2) << adult_total << endl;
    }
    double children_total = children_ticket * 10.0;
    if (children_ticket > 0) {
        cout << setw(8) << left << children_ticket
             << setw(40) << "Children Ticket"
             << setw(21) << "RM 10.00"
             << "RM " << fixed << setprecision(2) << children_total << endl;
    }
    double senior_total = senior_ticket * 15.0;
    if (senior_ticket > 0) {
        cout << setw(8) << left << senior_ticket
             << setw(40) << "Senior Ticket"
             << setw(21) << "RM 15.00"
             << "RM " << fixed << setprecision(2) << senior_total << endl;
    }

    // Food Orders
    double food_total = 0.0;
    for (const auto& food : food_orders) {
        double item_total = food.quantity * food.price;
        cout << setw(8) << left << food.quantity
             << setw(40) << food.food_name
             << "RM " << setw(18) << fixed << setprecision(2) << food.price
             << "RM " << item_total << endl;
        food_total += item_total;
    }

    // Subtotals and Total
    double ticket_total = (adult_ticket * 20.0) + (children_ticket * 10.0) + (senior_ticket * 15.0);
    double total_price = ticket_total + locker_total + food_total;

    cout << "----------------------------------------------------------------------------------" << endl;
    cout << setw(68) << left << "Subtotal:" << "RM " << fixed << setprecision(2) << total_price << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    cout << setw(68) << left << "Grand Total:" << "RM " << total_price << endl;
    cout << "==================================================================================" << endl;
    cout << "Thank you for using our service!" << endl;
    cout << "==================================================================================" << endl;

    cout << "\nPress any key to continue...";
    getch();
}
