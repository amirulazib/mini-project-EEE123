// Coder        : Sew Heng Hou
// Matrix no.   : 23302118
// Function     : To allow user to login into their account

#include "header.hpp"

void tsystem::login(){
    ifstream input;
    input.open("info.txt",ios::in);
    string name, pass, rname, rpass, exit;
    int login = 0;

    if (input.fail()){
        cout << "File does not exist" << endl;
    }
    else{
        while(login == 0){

            // Input from user
            cout << "Enter username         > ";
            cin >> name;
            cout << "Enter Password         > ";
            cin >> pass;

            input.clear();
            input.seekg(0, ios::beg);

            while (input >> rname >> rpass) {
                if (name == rname && pass == rpass) {
                    cout << "Logged in." << endl;
                    login = true; // Breaks Loop
                    username = name; // Sets system's current user
                    cmenu = 1; // Allows customer menu to be initiated

                    ifstream infile(username + "_data.txt");
                    string line;
                    while (getline(infile, line)) {
                    // Parse and load user-specific data into program
                    if (line.find("tickets:") == 0) {
                        string tickets = line.substr(8); // Extract ticket data
                        sscanf(tickets.c_str(), "%d,%d,%d", &ticket1, &ticket2, &ticket3);
                    }
                    if (line.find("locker:") == 0) {
                        locker = stoi(line.substr(7)); // Extract locker data
                    }
                    infile.close();

                    break;
                    }
                }
            }
            // Code to prevent soft locks by user.
            if (!login) {
                cout << "Incorrect. Please try again." << endl;
                cout << "Do you want to exit login? (Y/N) > ";
                cin >> exit;
                if(exit == "Y" || exit == "y"){
                    cout << "Returning to main menu..." << endl;
                    login = 1;
                }
            }
        }    
    }
    input.close();
}