// Coder        : Nur Amirul Azib Bin Nazri
// Matrix no.   : 22306893
// Function     : To display food items and get users' food orders

#include "header.hpp"

using namespace std;

// Load food data into the array
void tsystem::loadFoodData(FoodItem foodList[]) {
    ifstream file("food.txt");
    if (file.fail()) {
        cout << "Error: Could not open food.txt" << endl;
        return;
    }

    for (int i = 0; i < ITEMS; i++) {
        getline(file, foodList[i].code);  // Read code
        getline(file, foodList[i].name); // Read name
        file >> foodList[i].price;       // Read price
        file.ignore();                   // Ignore newline after price
    }

    file.close();
}

// Display food menu
void tsystem::displayFood(const FoodItem foodList[], int count) {
    cout << left << setw(5) << "No" << setw(20) << "Code" << setw(50) << "Food" << setw(30) << "Price (RM)" << endl;

    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << (i + 1) << setw(20) << foodList[i].code << setw(50) << foodList[i].name
             << "RM " << fixed << setprecision(2) << setw(30) << foodList[i].price << endl;
    }
}

// Get user orders
void tsystem::getOrder(const FoodItem foodList[], int count, Order orderList[], int& orderCount, double& totalPrice) {
    string code;
    int quantity;
    bool state;

    totalPrice = 0.0;  
    orderCount = 0;    

    cout << "\nEnter the food code and quantity (type 'done' to finish):\n";

    while (true) {
        cout << "\nFood code: ";
        cin >> code;
        if (code == "done") break;

        state = false;

        // Check if the item is already in the order list
        for (int j = 0; j < orderCount; j++) {
            if (orderList[j].code == code) {
                state = true;
                cout << "Quantity: ";
                cin >> quantity;

                while (cin.fail() || quantity <= 0) {
                    cout << "\nInvalid input. Enter a positive integer." << endl;
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input in the buffer
                    cout << "Quantity: ";
                    cin >> quantity;
                }

                
                orderList[j].quantity += quantity;
                totalPrice += foodList[j].price * quantity; 
                cout << "Updated quantity for " << code << ": " << orderList[j].quantity << endl;
                break;
            }
        }

        // If the item is not already in the order list
        if (!state) {
            for (int i = 0; i < count; i++) {
                if (foodList[i].code == code) {
                    state = true;
                    cout << "Quantity: ";
                    cin >> quantity;

                    while (cin.fail() || quantity <= 0) {
                        cout << "\nInvalid input. Enter a positive integer." << endl;
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input in the buffer
                        cout << "Quantity: ";
                        cin >> quantity;
                    }


                    orderList[orderCount].code = foodList[i].code;
                    orderList[orderCount].name = foodList[i].name;
                    orderList[orderCount].price = foodList[i].price;
                    orderList[orderCount].quantity = quantity;
                    orderCount++;

                    totalPrice += foodList[i].price * quantity;
                    break;
                }
            }
        }

        if (!state) {
            cout << "Invalid code. Please try again.\n";
        }
    }
}

void tsystem::savedata(int& orderCount, Order orderList[]){
    ofstream outfile(tsystem::username + "_data.txt", ios::app);
    for (int i = 0; i < orderCount; i++) {
        outfile << "order:" << orderList[i].quantity << "," << orderList[i].name << "," << fixed << setprecision(2) << orderList[i].price
        << endl;
    }
    outfile.close();
}