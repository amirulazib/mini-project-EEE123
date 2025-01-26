//==============================================================================================================================================//
//Project Title
//Group Members: 1. WAN YAZAFRIANA BINTI WAN YAZAIRI    (23303506)
//               2. SEW HENG HOU                        (23302118)
//               3. CHEAH CHEE KANG                     (23302124)
//               4. CHOONG JUN JIE                      (23302160)
//               5. NUR AMIRUL AZIB BIN NAZRI           (22306893)
//               6. LIMUZI                              (23300188)
//
//Project Description:  The program helps visitors register and log into their accounts to buy tickets, 
//                      rent storage lockers and buy food. The special thing is that visitors can check 
//                      their purchases and get electronic invoices
//
//==============================================================================================================================================//


// Coder        : Sew Heng Hou
// Matrix no.   : 23302118
// Function     : Initiates main menu loop

#include "header.hpp"

int main(){

    tsystem sys;

    while (sys.exit == 0){

        sys.display_mmenu();

        sys.mainmenu_choice();
                
    }
    return 0;
}
