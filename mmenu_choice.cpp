#include "header.hpp"

void tsystem::mainmenu_choice(){
    string choice;
    int exit = 0;
    tsystem sys;

    cout << "Select an option > ";
    cin >> choice;

    if (choice == "1"){
        sys.regis();
    }
    else if (choice == "2"){
        sys.login();
        if (sys.status == 1){
            while(sys.cmenu == 1){
            sys.display_cmenu();
            sys.customer_choice();
            }
            sys.cmenu = 1;
        }
    }
    else if (choice == "3"){
        sys.del();
    }
    else if (choice == "4"){
        cout << "Thank you!" << endl;
        exit = 1;
    }
    else{
        cout << "Invalid option, please try again!" << endl;
    }
}