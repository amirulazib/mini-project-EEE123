#include "header.hpp"

void tsystem::checkexist(string name,string pass){
    ifstream input;
    input.open("info.txt");
    string rname,rpass;
    
    input.clear();
    input.seekg(0, ios::beg);

    while (input >> rname >> rpass) {
        if (name == rname && pass == rpass) {
            tsystem::exist = 1;
            break;
        }
    }

}