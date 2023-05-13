#include "HangMan.h"
#include <iostream>

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

		for (int i = 0; i < word.size(); ++i) {

			if (letter.compare(word.substr(i, 1)) == 0) {

				std::cout << letter << '\t' << word.substr(i, 1) << '\n';

				wordDisplay.replace(i, 1, letter);

			}

		}

		attemptCNTR++;
		
	}

	std::cout << "you got it\n";
	std::cout << wordDisplay << " took you: " << attemptCNTR << " Attempts\n";

}
