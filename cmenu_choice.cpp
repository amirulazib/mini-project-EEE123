#include "header.hpp"

void tsystem::customer_choice(){
    string choice;
    cout << "Select an option        > ";
    cin >> choice;
    if (choice == "1"){
            tsystem::ticket();
    }
    else if (choice == "2"){
            tsystem::rentlocker();
    }
    else if (choice == "3"){
            tsystem::loadFoodData(foodList);
            cout << "Food Menu: \n" << string(90, '-') << endl;
            tsystem::displayFood(foodList, ITEMS);

            tsystem::getOrder(foodList, ITEMS, orderList, orderCount, totalPrice);

            tsystem:savedata(orderCount,orderList);
    }
    else if (choice == "4"){
            tsystem::checkpurchases();
    }
    else if (choice == "5"){

    }
    else if (choice == "6"){
            cout << "Logout successful!" << endl;
            tsystem::cmenu = 0;
    }
    else{
        cout << "Invalid, Please Try Again.\n" << endl;
    }
    system("pause");
}
