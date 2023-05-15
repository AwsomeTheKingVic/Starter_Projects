#include <iostream>
#include "Calculater.h"
#include "RandomNumberGame.h"
#include "HangMan.h"
#include "Tic_Tac_Toe.h"
#include "LibraryManagementSystem.h"
#include "ATM.h"

/*
-go back through and rework and add something new to code
-polish
*/

int main()
{

    //classes being added
    Calculater Calculater;
    RandomNumberGame RandomNumberGame;
    HangMan HangMan;
    Tic_Tac_Toe Tic_Tac_Toe;
    LibraryManagementSystem LibraryManagementSystem;
    ATM ATM;

    //main class variables
    bool exit = false;
    int choice = 0;

    //Menu
    while (!exit) {

        //system("cls");

        //askes for user choice to pick between clasess
        std::cout << "What would you like to do\n";
        std::cout << "Use Calculater(1), RandomNumberGame(2), HangMan(3), Tic-Tac-Toe(4), LibrarySystem(5)\n";
        std::cout << "ATM(6), (7), (8), (9), (10), Exit(11)\n";

        std::cin >> choice;

        switch (choice)
        {
        
            case 1:

                Calculater.StartUp();

                break;

            case 2:

                RandomNumberGame.StartUp();

                break;

            case 3:

                HangMan.StartUp();

                break;

            case 4:

                Tic_Tac_Toe.StartUp();

                break;

            case 5:

                LibraryManagementSystem.StartUp();

                break;

            case 6:

                ATM.StartUp();

                break;

            case 7:



                break;

            case 8:



                break;

            case 9:



                break;

            case 10:

                

                break;

            case 11:

                //allows the user to leave or keep goin
                std::cout << "Would you like to go exit(0 = false | 1 = true)\n";

                std::cin >> exit;

                break;

            default:

                std::cout << "I guess it was nothing\n";

                break;

        }

    }
    

}
