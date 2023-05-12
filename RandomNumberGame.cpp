#include <iostream>
#include <stdexcept>
#include "RandomNumberGame.h"

//is the startup for the random game
void RandomNumberGame::StartUp()
{

	//gets user input for the starting and ending number for random number selection
	//find a way to fix instant crash on endingNumber being less than startingNumber
    std::cout << "Enter the numbers you want to guess between\n";
	std::cout << "Starting Number\n";
	std::cin >> startingNumber;
	std::cout << "Ending Number\n";
	std::cin >> endingNumber;

	//sets the random number between user given numbers
	std::random_device randomNumber;
	std::uniform_int_distribution<int> dist(startingNumber, endingNumber);

	theRandomNumber = dist(randomNumber);

	std::cout << "Number have been choosen\n";

	//keeps the game running while numbers are not equal
	while (theRandomNumber != userInPut) {

		std::cout << "Type Guessed Number Here\n";

		std::cin >> userInPut;

		//checks if the userinput is greater than or less then the choosen number
		if (userInPut > theRandomNumber) {

			std::cout << "Number is greater then the number choosen\n";

		}
		else if (userInPut < theRandomNumber) {
		
			std::cout << "Number is Less then the number choosen\n";
		
		}
		else {

			std::cout << "You got it\n";

		}

	}

}
