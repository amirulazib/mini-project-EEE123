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
        cout << "Create username         > ";
        cin >> name;
        cout << "Create Password         > ";
        cin >> temp;
        cout << "Enter Password Again    > ";
        cin >> pass;



        if (temp == pass){
            tsystem::checkexist(name,pass);
            if (tsystem::exist == 1){
                cout << "Account has been registered." << endl;
                tsystem::exist = 0;
            }
            else if (tsystem::exist == 0){
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
    system ("pause");
}