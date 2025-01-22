// Coder        : 
// Matrix no.   : 
// Function     : 

#include "header.hpp"

// Used Chatgpt for this cuz its complicated :)

void tsystem::del() {
    ifstream input;
    ofstream output;
    input.open("info.txt", ios::in);

    if (!input) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string name, pass, rname, rpass, confirm;
    vector<pair<string, string>> entries;

    cout << "Enter username     > ";
    cin >> name;
    cout << "Enter password     > ";
    cin >> pass;

    cout << "Are you sure you want to delete this account? (Y/N): ";
    cin >> confirm;

    if (confirm == "N" || confirm == "n"){
        cout << "Returning to main menu..." << endl;
        return;
    }else if (confirm == "Y" || confirm == "y"){
        // Read the file and store entries in memory
        bool found = false;
        while (input >> rname >> rpass) {
            if (name == rname && pass == rpass) {
                found = true; // Mark the record for deletion
            } else {
                entries.push_back({rname, rpass}); // Keep other entries
            }
        }

        input.close();

        if (found) {
            // Overwrite the file with remaining entries
            output.open("info.txt", ios::out | ios::trunc);
            if (!output) {
                cerr << "Error: Unable to write to file." << endl;
                return;
            }

            for (const auto& entry : entries) {
                output << entry.first << " " << entry.second << endl;
            }
            remove((name + "_data.txt").c_str()) == 0;
            
            output.close();
            cout << "User deleted successfully." << endl;
        } else {
            cout << "Account does not exists. Please try again." << endl;
        }
    }
}