#include "header.hpp"

void tsystem::checkpurchases(){
    tsystem data;

    int adult_ticket = data.ticket1;
    int children_ticket = data.ticket2;
    int senior_ticket = data.ticket3;

    int locker_amount = data.locker;

    cout << "\nOrder Summary:\n";

    if (adult_ticket > 0){
        cout << "Adult Tickets Bought: " << adult_ticket << endl;
    }
    if (children_ticket > 0){
        cout << "Children Tickets Bought: " << children_ticket << endl;
    }
    if (senior_ticket > 0){
        cout << "Senior Citizen Tickets Bought: " << senior_ticket << endl;
    }
    if (locker_amount > 0){
        cout << "Lockers Rented: " << locker_amount << endl;
    }

    for (int i = 0; i < orderCount; i++) {
        cout << orderList[i].quantity << "x " << orderList[i].name << " - RM "<< fixed << setprecision(2) << orderList[i].price
        << " = RM " << orderList[i].quantity * orderList[i].price << endl;
    }
    cout << "Total Price: RM " << fixed << setprecision(2) << totalPrice << endl;
}