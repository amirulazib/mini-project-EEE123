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

        void ticket();
        int ticket1;    // Adult Ticket
        int ticket2;    // Children Ticket   
        int ticket3;    // Senior Citizen Ticket

        void rentlocker();

    private:
        int x;
};