#include "HangMan.h"
#include <iostream>
/*
-Add FileReader and Writer
allow the user to basically save their words into txt file to call back later
-change letter into char to allow only one letter to be sent to the program
-polish
*/

//start up for the hangman
void HangMan::StartUp()
{

	//clears the worddisplay for every start up
	wordDisplay.clear();

	std::cout << "Enter the Word the Player may guess\n";

	//set the guess word
	std::cin >> word;

	//fills
	wordDisplay.insert(wordDisplay.begin(), word.size(), '_');

	//clears the screen for players dont see the word
	system("cls");

	//will not end stop until all letters in the word have been selected
	while (word.compare(wordDisplay) != 0) {

		//shows the player how many letters the word is
		std::cout << wordDisplay << '\n';

		std::cout << "Type a letter\n";

		std::cin >> letter;

		//for the size of the string checks every letters to see if it matches user letter
		for (int i = 0; i < word.size(); ++i) {

			//if statement to compare letter string with substring and replace location with letter if needed
			if (letter.compare(word.substr(i, 1)) == 0) {

				wordDisplay.replace(i, 1, letter);

			}

		}

		//adds to counter every time the code run
		attemptCNTR++;
		
	}

	//winning display
	std::cout << "you got it\n";
	std::cout << "the word was: " << wordDisplay << " took you: " << attemptCNTR << " Attempts\n";

}
