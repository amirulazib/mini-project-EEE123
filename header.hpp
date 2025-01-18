#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>

using namespace std;

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

    private:
        int x;
};