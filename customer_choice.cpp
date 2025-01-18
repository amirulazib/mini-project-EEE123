#include "header.hpp"

void tsystem::customer_choice(){
    FoodItem foodList[ITEMS];  // Array to hold food items
    Order orderList[ITEMS];    // Array to hold user orders
    int orderCount;
    double totalPrice;
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
            loadFoodData(foodList);
            cout << "Food Menu: \n" << string(90, '-') << endl;
            displayFood(foodList, ITEMS);

            getOrder(foodList, ITEMS, orderList, orderCount, totalPrice);

            cout << "\nOrder Summary:\n";
            for (int i = 0; i < orderCount; i++) {
                cout << orderList[i].quantity << "x " << orderList[i].name << " - RM "<< fixed << setprecision(2) << orderList[i].price
                << " = RM " << orderList[i].quantity * orderList[i].price << endl;
            }
            cout << "Total Price: RM " << fixed << setprecision(2) << totalPrice << endl;
            break;
        }
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout << "Logout successful!" << endl;
            break;
    }
    system("pause");
}
