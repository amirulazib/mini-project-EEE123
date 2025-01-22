// Coder        : Sew Heng Hou
// Matrix no.   : 23302118
// Function     : To check existence of username and password

#include "header.hpp"

void tsystem::checkexist(string name,string pass){
    ifstream input;
    input.open("info.txt");
    string rname,rpass;
    
    // clear any error flags in cin stream and seek arbitary position in the .txt file
    input.clear();
    input.seekg(0, ios::beg);

    // if account exists, exist will change so that it can be detected in register()
    while (input >> rname >> rpass) {
        if (name == rname && pass == rpass) {
            tsystem::exist = 1;
            break;
        }
    }
}
