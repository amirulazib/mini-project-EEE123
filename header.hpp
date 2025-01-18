#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>

using namespace std;

const int ITEMS = 30;

class tsystem {
    public:
        void display_mmenu();

        void regis();

        void login();
        int status;

        void del();

        void checkexist(string,string);
        int exist = 0;

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

        void loadFoodData(FoodItem foodList[]);
        void displayFood(const FoodItem foodList[], int count);
        void getOrder(const FoodItem foodList[], int count, Order orderList[], int& orderCount, double& totalPrice);
        
    private:
        int x;
};

