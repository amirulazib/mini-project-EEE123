#include "header.hpp"

void tsystem::customer_choice(){
    int choice;
    cout << "Select an option        > ";
    cin >> choice;
    switch(choice){
        case 1:
            tsystem::ticket();
            break;
        case 2:
            tsystem::rentlocker();
            break;
        case 3:{
            tsystem::loadFoodData(foodList);
            cout << "Food Menu: \n" << string(90, '-') << endl;
            tsystem::displayFood(foodList, ITEMS);

            tsystem::getOrder(foodList, ITEMS, orderList, orderCount, totalPrice);

            tsystem:savedata(orderCount,orderList);
            break;
        }
        case 4:
            tsystem::checkpurchases();
            break;
        case 5:
            break;
        case 6:
            cout << "Logout successful!" << endl;
            tsystem::cmenu = 0;
            break;
    }
    system("pause");
}
