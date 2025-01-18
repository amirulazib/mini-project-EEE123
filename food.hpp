#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <string>
using namespace std;

const int ITEMS = 30;

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


#endif