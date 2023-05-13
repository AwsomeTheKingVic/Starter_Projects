#include <iostream>
#include <random>
#include "Calculater.h"
#include "RandomNumberGame.h"
#include "HangMan.h"

int main()
{

    //classes being added
    Calculater Calculater;
    RandomNumberGame RandomNumberGame;
    HangMan HangMan;

    //main class variables
    bool exit = false;
    int choice = 0;

    //Menu
    while (!exit) {

        //askes for user choice to pick between clasess
        std::cout << "What would you like to do\n";
        std::cout << "Use Calculater(1), RandomNumberGame(2), HangMan(3)\n";

        std::cin >> choice;

        switch (choice)
        {
        
            //calculater
            case 1:

                Calculater.StartUp();

                break;

            case 2:

                RandomNumberGame.StartUp();

                break;

            case 3:

                HangMan.StartUp();

                break;

            default:

                std::cout << "I guess it was nothing\n";

                break;

        }

        //allows the user to leave or keep goin
        std::cout << "Would you like to go exit(0 = false | 1 = true)\n";

        std::cin >> exit;

    }
    

}
