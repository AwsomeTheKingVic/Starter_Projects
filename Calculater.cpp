#include <iostream>
#include "Calculater.h"
/*
-add a vector to allow the user to keep adding numbers with the ability to do math between two numbers nothing more for now
-polish
*/

//is the start up for this class
void Calculater::StartUp() {

    //gettings user input
    std::cout << "Type First Number in\n";
    std::cin >> userInPut1;
    std::cout << "Type Second Number\n";
    std::cin >> userInPut2;

    std::cout << "What would you like to do\n";
    std::cout << "ADD(1), Subtract(2), Multiply(3), Divide(4)\n";

    std::cin >> choice;

    //user choice goes through a switch
    switch (choice) {

    case 1:

        Add();

        break;

    case 2:

        Subtract();

        break;

    case 3:

        Multiply();

        break;

    case 4:

        Divide();

        break;

    }

    //displayes information
    std::cout << '\n' << userInPut1 << " " << symbol << " " << userInPut2 << " = " << userTotal << '\n';

};

//handles adding
void Calculater::Add() {

	userTotal = userInPut1 + userInPut2;

    symbol = '+';

};

//handles Subtraction
void Calculater::Subtract() {

	userTotal = userInPut1 - userInPut2;

    symbol = '-';

};

//handles Multiplication
void Calculater::Multiply() {

	userTotal = userInPut1 * userInPut2;

    symbol = '*';

};

//handles Division
void Calculater::Divide() {

	userTotal = userInPut1 / userInPut2;

    symbol = '/';

};