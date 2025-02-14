// Coder        : Sew Heng Hou
// Matrix no.   : 23302118
// Function     : Contains the class for the system

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <limits>

using namespace std;

const int ITEMS = 30;

class tsystem {
    public:
        // Main menu section
        void display_mmenu();

        void mainmenu_choice();
        int exit = 0;

        void regis();

        void login();
        int cmenu;
        string username;

        void del();

        void checkexist(string,string);
        int exist = 0;

        // Customer menu section
        void display_cmenu();

        void customer_choice();

        void ticket();
        int ticket1;    // Adult Ticket
        int ticket2;    // Children Ticket   
        int ticket3;    // Senior Citizen Ticket

        void rentlocker(); 
        int locker;

        struct FoodItem {
        string code;
        string name;
        double price;
        };

        struct Order {
            string code;
            string name;
            double price;
            int quantity;
        };

        FoodItem foodList[ITEMS];  // Array to hold food items
        Order orderList[ITEMS];    // Array to hold user orders
        int orderCount;
        double totalPrice;

        void loadFoodData(FoodItem foodList[]);

        void displayFood(const FoodItem foodList[], int count);

        void getOrder(const FoodItem foodList[], int count, Order orderList[], int& orderCount, double& totalPrice);

        void savedata(int& orderCount, Order orderList[]);

        void checkpurchases();

        struct FoodOrder {
            string food_name;
            int quantity;
            double price;
        };

        void printreceipt();
};

