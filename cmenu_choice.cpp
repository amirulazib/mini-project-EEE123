// Coder        : Sew Heng Hou
// Matrix no.   : 23302118
// Function     : Choice menu for customers after they are logged in

#include "header.hpp"

void tsystem::customer_choice(){
    string choice;
    cout << "Select an option        > ";
    cin >> choice;
    if (choice == "1"){
            tsystem::ticket();                  // Calls ticket booking function
    }
    else if (choice == "2"){
            tsystem::rentlocker();              // Calls locker renting function
    }
    else if (choice == "3"){
        // Functions to load food data, display food, get food order and saves the data
            tsystem::loadFoodData(foodList);    
            cout << "Food Menu: \n" << string(90, '-') << endl;
            tsystem::displayFood(foodList, ITEMS);

            tsystem::getOrder(foodList, ITEMS, orderList, orderCount, totalPrice);

            tsystem::savedata(orderCount,orderList);  
    }
    else if (choice == "4"){
            tsystem::checkpurchases();          // Check purchases
    }
    else if (choice == "5"){
        tsystem::printreceipt();                // Prints Receipt

    }
    else if (choice == "6"){
            cout << "Logout successful!" << endl;
            tsystem::cmenu = 0;                 // Returns to main menu by breaking customer menu loop
    }
    else{
        cout << "Invalid, Please Try Again.\n" << endl;
    }
}
