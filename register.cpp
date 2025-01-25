// Coder        : Sew Heng Hou
// Matrix no.   : 23302118
// Function     : To register user's username and password into the system

#include "header.hpp"


void tsystem::regis(){
    ofstream output;
    output.open("info.txt", ios::app);
    if (!output.is_open()) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return;
    }
    
    string name, temp, pass;

    while (true){
        // User input
        cout << "Create username         > ";
        cin >> name;
        cout << "Create Password         > ";
        cin >> temp;
        cout << "Enter Password Again    > ";
        cin >> pass;



        if (temp == pass){
            // Checks existence of registered account
            tsystem::checkexist(name,pass);
            if (tsystem::exist == 1){
                cout << "Account has been registered." << endl;
                tsystem::exist = 0;
            }
            else if (tsystem::exist == 0){
                // Creates "username_data.txt" file to store future data
                ofstream outfile(name + "_data.txt");
                outfile << "username:" << name << endl;
                outfile << "tickets:0,0,0\n";  // Default ticket data
                outfile << "locker:0\n";       // Default locker data
                outfile << "orders:\n";        // Default order data
                outfile.close();
                cout << "Success! Your account has been created!" << endl;
                break;
            }
        }
        else{
            cout << "Invalid! Please Try Again!" << endl;
        }
    }

    output << name << " " << pass << endl;
    output.close();
}