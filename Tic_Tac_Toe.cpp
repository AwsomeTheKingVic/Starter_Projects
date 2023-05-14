#include "Tic_Tac_Toe.h"
#include <iostream>
#include <array>
#include <random>

/*
-rework code
-polish
*/

void Tic_Tac_Toe::StartUp()
{

	choice = 0;

	std::cout << "Single(1), Co-op(2)\n";

	std::cin >> choice;

	switch (choice)
	{
	
		case 1:

			GameSingle();

			break;

		case 2:

			GameCOOP();

			break;

	}

}

//allows the player to keep playing
void Tic_Tac_Toe::Restart()
{

	for (int i = 0; i < sizeof(gameBoard); i++) {

		//char number starts at 48 to 57
		gameBoard[i] = 49 + i;

	}

}

//player plays against the computer
void Tic_Tac_Toe::GameSingle()
{

	Restart();

	bool gameOver = false;

	while (!gameOver) {

		system("cls");

		PrintArray();

		if (!isPlayer1) {

			Computer();

		}
		else {

			Player1();

		}

		gameOver = WinChecker();

	}

	PrintArray();

}

//player plays against another player
void Tic_Tac_Toe::GameCOOP()
{

	Restart();

	bool gameOver = false;

	while (!gameOver) {

		system("cls");

		PrintArray();

		if (!isPlayer1) {

			Player2();
		
		}
		else {
		
			Player1();
		
		}

		gameOver = WinChecker();

	}

	PrintArray();

}

//well prints the array to screen
void Tic_Tac_Toe::PrintArray()
{

	std::cout << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << '\n';
	std::cout << "_________\n";
	std::cout << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << '\n';
	std::cout << "_________\n";
	std::cout << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << '\n';

}

//the computer 
void Tic_Tac_Toe::Computer()
{
	
	//set found location to false
	bool foundLocation = false;

	//gets random number between zero and size of array
	std::random_device randomNumber;
	std::uniform_int_distribution<int> dist(0, sizeof(gameBoard));

	//keeps going until it finds a place to mark
	while (!foundLocation) {

		location = dist(randomNumber);

		//find location placed mark and leaves loop
		if (gameBoard[location] != 'X' && gameBoard[location] != 'O') {

			gameBoard[location] = 'O';

			foundLocation = true;

		}

	}

	isPlayer1 = true;

}

//player chooses what location to place their mark
void Tic_Tac_Toe::Player1()
{

	//fix to make only one player function

	choice = 0;

	std::cout << "Player 1\n";

	std::cout << "what location would you like to place (1-9)\n";

	std::cin >> choice;

	switch (choice)
	{
		
		case 1:

			if (gameBoard[0] == 'O') {

				Player1();

			}
			else {
			
				gameBoard[0] = 'X';

			}

			break;

		case 2:

			if (gameBoard[1] == 'O') {

				Player1();

			}
			else {

				gameBoard[1] = 'X';

			}

			break;

		case 3:

			if (gameBoard[2] == 'O') {

				Player1();

			}
			else {

				gameBoard[2] = 'X';

			}

			break;

		case 4:

			if (gameBoard[3] == 'O') {

				Player1();

			}
			else {

				gameBoard[3] = 'X';

			}

			break;

		case 5:

			if (gameBoard[4] == 'O') {

				Player1();

			}
			else {

				gameBoard[4] = 'X';

			}

			break;

		case 6:

			if (gameBoard[5] == 'O') {

				Player1();

			}
			else {

				gameBoard[5] = 'X';

			}

			break;

		case 7:

			if (gameBoard[6] == 'O') {

				Player1();

			}
			else {

				gameBoard[6] = 'X';

			}

			break;

		case 8:

			if (gameBoard[7] == 'O') {

				Player1();

			}
			else {

				gameBoard[7] = 'X';

			}

			break;

		case 9:

			if (gameBoard[8] == 'O') {

				Player1();

			}
			else {

				gameBoard[8] = 'X';

			}

			break;

	}

	isPlayer1 = false;

}

//player chooses what location to place their mark
void Tic_Tac_Toe::Player2()
{

	choice = 0;

	std::cout << "Player 2\n";

	std::cout << "what location would you like to place (1-9)\n";

	std::cin >> choice;

	switch (choice)
	{

	case 1:

		if (gameBoard[0] == 'X') {

			Player2();

		}
		else {

			gameBoard[0] = 'O';

		}

		break;

	case 2:

		if (gameBoard[1] == 'X') {

			Player2();

		}
		else {

			gameBoard[1] = 'O';

		}

		break;

	case 3:

		if (gameBoard[2] == 'X') {

			Player2();

		}
		else {

			gameBoard[2] = 'O';

		}

		break;

	case 4:

		if (gameBoard[3] == 'X') {

			Player2();

		}
		else {

			gameBoard[3] = 'O';

		}

		break;

	case 5:

		if (gameBoard[4] == 'X') {

			Player2();

		}
		else {

			gameBoard[4] = 'O';

		}

		break;

	case 6:

		if (gameBoard[5] == 'X') {

			Player2();

		}
		else {

			gameBoard[5] = 'O';

		}

		break;

	case 7:

		if (gameBoard[6] == 'X') {

			Player2();

		}
		else {

			gameBoard[6] = 'O';

		}

		break;

	case 8:

		if (gameBoard[7] == 'X') {

			Player2();

		}
		else {

			gameBoard[7] = 'O';

		}

		break;

	case 9:

		if (gameBoard[8] == 'X') {

			Player2();

		}
		else {

			gameBoard[8] = 'O';

		}

		break;

	}

	isPlayer1 = true;

}

//checks if the player won or draw
bool Tic_Tac_Toe::WinChecker()
{

	//left to right
	if (gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2]) {

		return true;

	}
	else if (gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5]) {
	
		return true;

	}
	else if (gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8]) {

		return true;

	}

	//top to bottom
	else if (gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6]) {

		return true;

	}
	else if (gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7]) {

		return true;

	}
	else if (gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8]) {

		return true;

	}

	//diagonal
	else if (gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8]) {

		return true;

	}
	else if (gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6]) {

		return true;

	}

	//draw
	else if (gameBoard[0] != '1' && gameBoard[1] != '2' && gameBoard[2] != '3' && 
			 gameBoard[3] != '4' && gameBoard[4] != '5' && gameBoard[5] != '6' &&
			 gameBoard[6] != '7' && gameBoard[7] != '8' && gameBoard[8] != '9') 
	{

		return true;

	}

	//if no conditions have been meet
	else {
	
		return false;
	
	}

}
