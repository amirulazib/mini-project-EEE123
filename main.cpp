#include "header.hpp"

int main(){

    tsystem sys;

    while (sys.exit == 0){

        sys.display_mmenu();

        sys.mainmenu_choice();
                
    }
    return 0;
}