#include "ChessGame.h"
#include <iostream>
#include <tuple>

void ChessGame::StartUp()
{

	endGame = false;
	turn = 0;

	BoardSetUP();
	AddGamePieces();

	while (!endGame) {

		Player();

		//std::cout << "White Player turn\n";

		//PlayerOne();

		//std::cout << "black player turn\n";

		//PlayerTwo();

	}

}

//displays the board intot he console
void ChessGame::PrintBoard()
{

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < column; c++) {

			std::cout << gameBoard[r][c] << " ";

		}

		std::cout << std::endl;

	}

}

//fills the board with x later a pattern
void ChessGame::BoardSetUP()
{
	for (int r = 0; r < row; r++) {

		for (int c = 0; c < column; c++) {

			gameBoard[r][c] = 'X';

			/*
			if (flipFlop == 1) {

				gameBoard[r][c] = 'O';

				flipFlop = flipFlop * (-1);

			}
			else {

				gameBoard[r][c] = 'X';

				flipFlop = flipFlop * (-1);

			}
			*/

		}

		//flipFlop = flipFlop * (-1);

	}

}

//adds the pieces into the game 
void ChessGame::AddGamePieces()
{

	blackPlayablePieces.clear();

	for (int i = 0; i < 16; i++) {

		blackPlayablePieces.push_back(gamePieceInfo);

		//first top row of black player pieces
		//===========================================================================================================
		if (i == 0) {

			blackPlayablePieces[i] = { rook, black,'R',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 1) {

			blackPlayablePieces[i] = { knight, black,'H',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 2) {

			blackPlayablePieces[i] = { bishop, black,'B',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 3) {

			blackPlayablePieces[i] = { queen, black,'Q',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 4) {

			blackPlayablePieces[i] = { king, black,'K',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 5) {

			blackPlayablePieces[i] = { bishop, black,'B',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 6) {

			blackPlayablePieces[i] = { knight, black,'H',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		else if (i == 7) {

			blackPlayablePieces[i] = { rook, black,'R',i,0 };

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		//===========================================================================================================

		//Pawns for the black Player
		//===========================================================================================================
		else if (i >= 8 && i < 16) {

			blackPlayablePieces[i] = { pawn, black,'T',(i - 8),1};

			gameBoard[blackPlayablePieces[i].Ylocation][blackPlayablePieces[i].Xlocation] = blackPlayablePieces[i].gamePieceChar;

		}
		//===========================================================================================================

	}

	whitePlayablePieces.clear();

	for (int i = 0; i < 16; i++) {

		whitePlayablePieces.push_back(gamePieceInfo);

		//bottom white player pieces
		//===========================================================================================================
		if (i == 0) {

			whitePlayablePieces[i] = { rook, white,'r',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 1) {

			whitePlayablePieces[i] = { knight, white,'h',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 2) {

			whitePlayablePieces[i] = { bishop, white,'b',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 3) {

			whitePlayablePieces[i] = { queen, white,'q',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 4) {

			whitePlayablePieces[i] = { king, white,'k',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 5) {

			whitePlayablePieces[i] = { bishop, white,'b',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 6) {

			whitePlayablePieces[i] = { knight, white,'h',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		else if (i == 7) {

			whitePlayablePieces[i] = { rook, white,'r',(i),7 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		//===========================================================================================================

		//pawns for white player pieces
		//===========================================================================================================
		if (i >= 8 && i < 16) {

			whitePlayablePieces[i] = { pawn, white,'p',(i - 8),6 };

			gameBoard[whitePlayablePieces[i].Ylocation][whitePlayablePieces[i].Xlocation] = whitePlayablePieces[i].gamePieceChar;

		}
		//===========================================================================================================

	}

	PrintBoard();

}

/*



// Divider Remove later 



*/

/*this function as stated the player function it will handle the turning of players and giving them the options of picking their corisponding pieces*/
void ChessGame::Player()
{
	choice = 0;

	if (!turn) {

		std::cout << "White Player" << '\n';

		for (int i = 0; i < whitePlayablePieces.size(); i++) {

			std::cout << "Symbol: " << whitePlayablePieces[i].gamePieceChar << '\t' << "Number: " << (i + 1) << '\t' << "X: " << (whitePlayablePieces[i].Xlocation + 1) << '\t' << "y: " << (whitePlayablePieces[i].Ylocation + 1) << "\n";

		}

	}
	else {

		std::cout << "Black Player" << '\n';

		for (int i = 0; i < blackPlayablePieces.size(); i++) {

			std::cout << "Symbol: " << blackPlayablePieces[i].gamePieceChar << '\t' << "Number: " << (i + 1) << '\t' << "X: " << (blackPlayablePieces[i].Xlocation + 1) << '\t' << "y: " << (blackPlayablePieces[i].Ylocation + 1) << "\n";

		}

	}

	std::cout << "pick a game piece by number \n";

	std::cin >> choice;

	if (!turn) {

		PawnMovement(whitePlayablePieces[(choice - 1)], (choice - 1));

		turn = 1;

	}else{
	
		PawnMovement(blackPlayablePieces[(choice - 1)], (choice - 1));

		turn = 0;

	}

	std::cout << std::endl;
	PrintBoard();
	std::cout << std::endl;

}

//older player turn functions
/*
void ChessGame::PlayerOne()
{

	choice = 0;

	for (int i = 0; i < whitePlayablePieces.size(); i++) {

		std::cout << "Symbol: " << whitePlayablePieces[i].gamePieceChar << '\t' << "Number: " << (i + 1) << '\t' << "X: " << (whitePlayablePieces[i].Xlocation + 1 ) << '\t' << "y: " << (whitePlayablePieces[i].Ylocation + 1) << "\n";

	}

	std::cout << "pick a game piece by number \n";

	std::cin >> choice;

	//CanWhitePiecesMove(whitePlayablePieces[(choice - 1)]);

	WhitePawnMovement(whitePlayablePieces[(choice - 1)], (choice - 1));

	PrintBoard();

}

void ChessGame::PlayerTwo()
{

	choice = 0;

	for (int i = 0; i < blackPlayablePieces.size(); i++) {

		std::cout << "Symbol: " << blackPlayablePieces[i].gamePieceChar << '\t' << "Number: " << (i + 1) << '\t' << "X: " << (blackPlayablePieces[i].Xlocation + 1) << '\t' << "y: " << (blackPlayablePieces[i].Ylocation + 1) << "\n";

	}

	std::cout << "pick a game piece by number \n";

	std::cin >> choice;

	BlackPawnMovement(blackPlayablePieces[(choice - 1)], (choice - 1));

	PrintBoard();

}
*/


void ChessGame::CheckPawn(GamePiece PickedGamePiece) {

	switch (PickedGamePiece.type) {

		//pawn checks
		case 0:

			//white pieces
			if (!turn) {

				if (gameBoard[PickedGamePiece.Ylocation - 1][PickedGamePiece.Xlocation] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 0;
					Player();

				}

			//black pieces
			}else{

				if (gameBoard[PickedGamePiece.Ylocation + 1][PickedGamePiece.Xlocation] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 1;
					Player();

				}

			}

			break;

		case 1:

			//white pieces
			if (!turn) {

				//checks top left
				if (gameBoard[PickedGamePiece.Ylocation - 1][PickedGamePiece.Xlocation - 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 0;
					Player();

				}

				//checks top right
				if (gameBoard[PickedGamePiece.Ylocation - 1][PickedGamePiece.Xlocation + 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 0;
					Player();

				}

				//checks bottom left
				if (gameBoard[PickedGamePiece.Ylocation + 1][PickedGamePiece.Xlocation - 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 0;
					Player();

				}

				//checks bottom right
				if (gameBoard[PickedGamePiece.Ylocation + 1][PickedGamePiece.Xlocation + 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 0;
					Player();

				}

			//black pieces
			}else {

				//checks top left
				if (gameBoard[PickedGamePiece.Ylocation + 1][PickedGamePiece.Xlocation + 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 1;
					Player();

				}

				//checks top right
				if (gameBoard[PickedGamePiece.Ylocation + 1][PickedGamePiece.Xlocation - 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 1;
					Player();

				}

				//checks bottome left
				if (gameBoard[PickedGamePiece.Ylocation - 1][PickedGamePiece.Xlocation + 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 1;
					Player();

				}

				//checks bottom right
				if (gameBoard[PickedGamePiece.Ylocation - 1][PickedGamePiece.Xlocation - 1] == 'X') {

					std::cout << "Can Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';

				}
				else {

					std::cout << "Can't Move\n";
					std::cout << "location  X = " << PickedGamePiece.Xlocation << '\t' << "Y = " << PickedGamePiece.Ylocation << '\n';
					turn = 1;
					Player();

				}

			}

			break;

	}

	return;

}

//older pawn check
//==========================================
/*
std::tuple<bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool> ChessGame::CanWhitePiecesMove(GamePiece pickedGamePiece)
{
	// Front, Back, Left, Right, topleft, topright, bottomleft, bottomright
	//topleft/topright, bottomleft/bottomright, lefttop/leftbottom, righttop/rightbottom
	bool Front = 0, Back = 0, Left = 0 ,Right = 0, topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0, leftTop = 0, leftBottom = 0, rightTop = 0, rightBottom = 0;

	//check if something is blocking the pieces making it unable to move
	switch (pickedGamePiece.type)
	{

		//pawn
		case 0:

			if (gameBoard[pickedGamePiece.Ylocation - 1][pickedGamePiece.Xlocation] == 'X') {

				std::cout << "Can Move\n";
				std::cout << "location " << pickedGamePiece.Xlocation << '\t' << pickedGamePiece.Ylocation << '\n';

				Front = 1;

			}

			return { Front, Back, Left, Right, topLeft, topRight, bottomLeft, bottomRight, leftTop, leftBottom, rightTop, rightBottom };

			break;

		//bishop
		case 1:

			if(gameBoard[pickedGamePiece.Ylocation - 1][pickedGamePiece.Xlocation - 1] == 'X') {

				std::cout << "can move (topLeft)" << '\n';

				topLeft = 1;

			}else{

				std::cout << "can't move (topLeft)" << '\n';

			}

			if (gameBoard[pickedGamePiece.Ylocation - 1][pickedGamePiece.Xlocation + 1] == 'X') {

				std::cout << "can move (topRight)" << '\n';

				topRight = 1;

			}else{

				std::cout << "can't move (topRight)" << '\n';

			}

			if (gameBoard[pickedGamePiece.Ylocation + 1][pickedGamePiece.Xlocation - 1] == 'X') {

				std::cout << "can move (bottomLeft)" << '\n';

				bottomLeft = 1;

			}else {

				std::cout << "can't move (bottomLeft)" << '\n';

			}

			if (gameBoard[pickedGamePiece.Ylocation + 1][pickedGamePiece.Xlocation + 1] == 'X') {

				std::cout << "can move (bottomRight)" << '\n';

				bottomRight = 1;

			}else {

				std::cout << "can't move (bottomRight)" << '\n';

			}

			if (!topLeft && !topRight && !bottomLeft && !bottomRight) {

				std::cout << "can't move GamePiece try picking another one" << '\n';

				Player();

			}

			return { Front, Back, Left, Right, topLeft, topRight, bottomLeft, bottomRight, leftTop, leftBottom, rightTop, rightBottom};

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			break;

	}

}
*/
//==========================================


//this functions hold all the code for the movement of the gamepieces
void ChessGame::PawnMovement(GamePiece pickedGamePiece, int gamePieceVectorLocation) {

	std::cout << pickedGamePiece.gamePieceChar << '\t' << "X = " << pickedGamePiece.Xlocation + 1 << '\t' << "Y = " << pickedGamePiece.Ylocation + 1 << '\n';

	switch (pickedGamePiece.type)
	{

		//pawn movement
		//===============================PAWN_MOVEMENT======================================================================================
		case 0:

			choice = 0;

			CheckPawn(pickedGamePiece);

			//first move either one or two
			if (pickedGamePiece.pawnFirstMove == true) {

				std::cout << "would you like to move once(1) or twice(2) for the first move\n";

				std::cin >> choice;

				switch (choice)
				{

					//moves pieces to the front of its location
					case 1:

						gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

						if (!turn) {

							pickedGamePiece.Ylocation -= 1;
							whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						}
						else {

							pickedGamePiece.Ylocation += 1;
							blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						}

						gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;
	

						break;

					//moves pieces 2 to the front of its location
					case 2:

						gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

						if (!turn) {

							pickedGamePiece.Ylocation -= 2;
							whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

							whitePlayablePieces[gamePieceVectorLocation].pawnFirstMove = false;

						}
						else {

							pickedGamePiece.Ylocation += 2;
							blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

							blackPlayablePieces[gamePieceVectorLocation].pawnFirstMove = false;

						}

						gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

						break;

				}

			//plays moves one after that
			}else{

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				if (!turn) {

					pickedGamePiece.Ylocation -= 1;
					whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

				}
				else {

					pickedGamePiece.Ylocation += 1;
					blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

				}

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;
	
			}

			break;
		//============================PAWN_MOVEMENT==========================================================================================

		//bishop movement
		//========================================================BISHOP_MOVEMENT===================================================================================
		case 1:

			choice = 0;
			direction = 0;

			CheckPawn(pickedGamePiece);

			std::cout << "which direction would you like to go topleft(1), topright(2), bottomleft(3), bottomright(4)\n";

			std::cin >> direction;

			std::cout << "how many times would you like to move\n";

			std::cin >> choice;

			switch (direction)
			{

				//moves the piece to the topleft of its location
				case 1:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;
				
				//moves the piece to the top right of its location
				case 2:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves the piece to the bottom left of its location
				case 3:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves the piece to the bottom right of its location
				case 4:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

			}

			break;
		//=======================================================BISHOP_MOVEMENT==================================================================================================================

		//Knight Movement
		//======================================================KNIGHT_MOVEMENT====================================================================================================
		case 2:

			direction = 0;

			std::cout << "which direction would you like to go topleft(1)/topright(2), bottomleft(3)/bottomright(4), lefttop(5)/leftbottom(6), righttop(7)/rightbottom(8)\n";

			std::cin >> direction;

			switch (direction)
			{

				//moves piece to the top left of its location
				case 1:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 2;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += 2;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the top right of its location
				case 2:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 2;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += 2;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the bottom left of its location
				case 3:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 2;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= 2;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the bottom right of its location
				case 4:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 2;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= 2;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the left top of its location
				case 5:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 2;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 2;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves peice to the left bottom of its location
				case 6:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 2;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 2;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the right top of its location
				case 7:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 2;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 2;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;
				
				//moves piece to the right bottom of its location
				case 8:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 2;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;
	
						pickedGamePiece.Xlocation -= 2;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

			}

			break;
		//===================================================KNIGHT_MOVEMENT=========================================================================================================================

		//rook movement
		//========================================ROOK_MOVEMENT==============================================================================================================
		case 3:

			choice = 0;
			direction = 0;

			std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4)\n";

			std::cin >> direction;

			std::cout << "how many times would you like to move\n";

			std::cin >> choice;

			switch (direction)
			{

				//moves piece to the front of its location
				case 1:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}else {

						pickedGamePiece.Ylocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the back of its location
				case 2:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}
					else {

						pickedGamePiece.Ylocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the left of its location
				case 3:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Xlocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}
					else {

						pickedGamePiece.Xlocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the right of its location
				case 4:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Xlocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}
					else {

						pickedGamePiece.Xlocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;
	
			}

			break;
		//========================================ROOK_MOVEMENT====================================================================================================================================

		//queen movement
		//===========================================QUEEN_MOVEMENT===================================================================================================================
		case 4:

			choice = 0;
			direction = 0;

			std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4), topleft(5), topright(6), bottomleft(7), bottomright(8)\n";

			std::cin >> direction;

			std::cout << "how many times would you like to move\n";

			std::cin >> choice;

			switch (direction)
			{

				//moves pieces to the front of its location
				case 1:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}else {

						pickedGamePiece.Ylocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the back of its location
				case 2:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}
					else {

						pickedGamePiece.Ylocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the left of its location
				case 3:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Xlocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}else {

						pickedGamePiece.Xlocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the right of its location
				case 4:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Xlocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}else {

						pickedGamePiece.Xlocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the top left of its location
				case 5:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}else {

						pickedGamePiece.Ylocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the top right of its location
				case 6:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the bottom left of its location
				case 7:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the bottom right of its location
				case 8:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += choice;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= choice;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

			}

			break;
		//==========================QUEEN_MOVEMENT==================================================================================================================================================

		//King movement
		//===========================================KING_MOVEMENT====================================================================================================================
		case 5:

			direction = 0;

			std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4), topleft(5), topright(6), bottomleft(7), bottomright(8)\n";

			std::cin >> direction;

			switch (direction)
			{

				//moves piece to the front of its location
				case 1:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}else {

						pickedGamePiece.Ylocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the back of its location
				case 2:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}
					else {

						pickedGamePiece.Ylocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece of the left of its location
				case 3:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Xlocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Xlocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the right of its location
				case 4:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Xlocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Xlocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				//moves piece to the top left of its location
				case 5:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}else {

						pickedGamePiece.Ylocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				case 6:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				case 7:
	
					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				case 8:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					if (!turn) {

						pickedGamePiece.Ylocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation += 1;
						whitePlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}
					else {

						pickedGamePiece.Ylocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Ylocation = pickedGamePiece.Ylocation;

						pickedGamePiece.Xlocation -= 1;
						blackPlayablePieces[gamePieceVectorLocation].Xlocation = pickedGamePiece.Xlocation;

					}

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

			}

			break;
		//============================================================================================================================================================================

		default:
			break;
	}



}


//white game pieces movement
//======================================================================================
/*
void ChessGame::WhitePawnMovement(GamePiece pickedGamePiece, int gamePieceLocation)
{

	bool Front = 0, Back = 0, Left = 0, Right = 0, topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0, leftTop = 0, leftBottom = 0, rightTop = 0, rightBottom = 0;
	

	std::cout << "hello" << '\n';

	std::tie(Front, Back, Left, Right, topLeft, topRight, bottomLeft, bottomRight, leftTop, leftBottom, rightTop, rightBottom) = CanWhitePiecesMove(pickedGamePiece);

	std::cout << gamePieceLocation << '\n';

	if (!Front && !Back && !Left && !Right && !topLeft && !topRight && !bottomLeft && !bottomRight && !leftTop && !leftBottom && !rightTop && !rightBottom) {

		std::cout << "Can't move GamePiece Pick another" << '\n';
		std::cout << Front << '\n';
		Player();

	}

	std::cout << pickedGamePiece.gamePieceChar << '\t' << pickedGamePiece.Xlocation + 1 << '\t' << pickedGamePiece.Ylocation + 1 << '\n';

	switch (pickedGamePiece.type)
	{

		//pawn movement
		//===============================PAWN_MOVEMENT======================================================================================
		case 0:

			choice = 0;

			//first move either one or two
			if (pickedGamePiece.pawnFirstMove == true) {

				std::cout << "would you like to move once(1) or twice(2) for the first move\n";

				std::cout << pickedGamePiece.pawnFirstMove << '\n';
	
				std::cin >> choice;

				switch (choice)
				{

				case 1:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					pickedGamePiece.Ylocation = pickedGamePiece.Ylocation - 1;

					whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;


					break;

				case 2:

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

					pickedGamePiece.Ylocation = pickedGamePiece.Ylocation - 2;

					whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

					gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

					break;

				}

				whitePlayablePieces[gamePieceLocation].pawnFirstMove = false;

			}
			else
			{

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation = pickedGamePiece.Ylocation - 1;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			}

			break;
		//=========================================================================================================================================================================

		//bishop movement
		//========================================================BISHOP_MOVEMENT===================================================================================
		case 1:

			choice = 0;
			direction = 0;

			std::cout << "which direction would you like to go topleft(1), topright(2), bottomleft(3), bottomright(4)\n";

			std::cin >> direction;

			std::cout << "how many times would you like to move\n";

			std::cin >> choice;

			switch (direction)
			{

			case 1:

				if (!topLeft) {

					WhitePawnMovement(pickedGamePiece, gamePieceLocation);

				}

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 2:

				if (!topRight) {

					WhitePawnMovement(pickedGamePiece, gamePieceLocation);

				}

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 3:

				if (!bottomLeft) {

					WhitePawnMovement(pickedGamePiece, gamePieceLocation);

				}

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 4:

				if (!bottomRight) {

					WhitePawnMovement(pickedGamePiece, gamePieceLocation);

				}

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;
	
				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			}

			break;
		//=========================================================================================================================================================================

		//Knight Movement
		//======================================================KNIGHT_MOVEMENT====================================================================================================
		case 2:

			direction = 0;

			std::cout << "which direction would you like to go topleft(1)/topright(2), bottomleft(3)/bottomright(4), lefttop(5)/leftbottom(6), righttop(7)/rightbottom(8)\n";

			std::cin >> direction;

			switch (direction)
			{

			case 1:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 2;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 2:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 2;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 3:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 2;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 4:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 2;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 5:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= 2;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 6:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= 2;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 7:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += 2;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 8:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += 2;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			}

			break;
		//============================================================================================================================================================================

		//rook movement
		//========================================ROOK_MOVEMENT==============================================================================================================
		case 3:
			
			choice = 0;
			direction = 0;

			std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4)\n";

			std::cin >> direction;

			std::cout << "how many times would you like to move\n";

			std::cin >> choice;

			switch (direction)
			{

			case 1:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= choice;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 2:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += choice;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 3:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Xlocation -= choice;

				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 4:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Xlocation += choice;

				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			}
			
			break;
		//============================================================================================================================================================================

		//queen movement
		//===========================================QUEEN_MOVEMENT===================================================================================================================
		case 4:

			choice = 0;
			direction = 0;

			std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4), topleft(5), topright(6), bottomleft(7), bottomright(8)\n";

			std::cin >> direction;

			std::cout << "how many times would you like to move\n";

			std::cin >> choice;

			switch (direction)
			{

			case 1:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= choice;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 2:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += choice;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 3:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Xlocation -= choice;

				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 4:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Xlocation += choice;

				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;
			case 5:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 6:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 7:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 8:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += choice;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += choice;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			}

			break;
		//============================================================================================================================================================================

		//King movement
		//===========================================KING_MOVEMENT====================================================================================================================
		case 5:

			direction = 0;

			std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4), topleft(5), topright(6), bottomleft(7), bottomright(8)\n";

			std::cin >> direction;

			switch (direction)
			{

			case 1:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 1;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 2:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 1;

				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 3:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Xlocation -= 1;

				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 4:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Xlocation += 1;

				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;
			case 5:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 6:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation -= 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 7:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation -= 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			case 8:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation += 1;
				whitePlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				pickedGamePiece.Xlocation += 1;
				whitePlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			}

			break;
			//============================================================================================================================================================================

	}

}

//======================================================================================

//black game pieces movement
//======================================================================================
void ChessGame::BlackPawnMovement(GamePiece pickedGamePiece, int gamePieceLocation)
{

	std::cout << pickedGamePiece.gamePieceChar << '\t' << pickedGamePiece.Xlocation + 1 << '\t' << pickedGamePiece.Ylocation + 1 << '\n';

	switch (pickedGamePiece.type)
	{

	//pawn movement
	//===============================PAWN_MOVEMENT======================================================================================
	case 0:

		choice = 0;

		//first move either one or two
		if (pickedGamePiece.pawnFirstMove == true) {

			std::cout << "would you like to move once(1) or twice(2) for the first move\n";

			std::cin >> choice;

			switch (choice)
			{

			case 1:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation = pickedGamePiece.Ylocation + 1;

				blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;


				break;

			case 2:

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

				pickedGamePiece.Ylocation = pickedGamePiece.Ylocation + 2;

				blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

				gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

				break;

			}

			blackPlayablePieces[gamePieceLocation].pawnFirstMove = false;

		}
		else
		{

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation = pickedGamePiece.Ylocation + 1;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

		}

		break;
	//=========================================================================================================================================================================

	//bishop movement
	//========================================================BISHOP_MOVEMENT===================================================================================
	case 1:

		choice = 0;
		direction = 0;

		std::cout << "which direction would you like to go topleft(1), topright(2), bottomleft(3), bottomright(4)\n";

		std::cin >> direction;

		std::cout << "how many times would you like to move\n";

		std::cin >> choice;

		switch (direction)
		{

		case 1:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 2:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;
			
			pickedGamePiece.Xlocation -= choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 3:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 4:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		}

		break;
		//=========================================================================================================================================================================

		//Knight Movement
		//======================================================KNIGHT_MOVEMENT====================================================================================================
	case 2:

		direction = 0;

		std::cout << "which direction would you like to go topleft(1)/topright(2), bottomleft(3)/bottomright(4), lefttop(5)/leftbottom(6), righttop(7)/rightbottom(8)\n";

		std::cin >> direction;

		switch (direction)
		{

		case 1:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 2;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 2:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 2;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 3:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 2;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 4:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 2;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 5:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += 2;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 6:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += 2;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 7:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= 2;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 8:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= 2;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		}

		break;
		//============================================================================================================================================================================

		//rook movement
		//========================================ROOK_MOVEMENT==============================================================================================================
	case 3:

		choice = 0;
		direction = 0;

		std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4)\n";

		std::cin >> direction;

		std::cout << "how many times would you like to move\n";

		std::cin >> choice;

		switch (direction)
		{

		case 1:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += choice;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 2:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= choice;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 3:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Xlocation += choice;

			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 4:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Xlocation -= choice;

			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		}

		break;
		//============================================================================================================================================================================

		//queen movement
		//===========================================QUEEN_MOVEMENT===================================================================================================================
	case 4:

		choice = 0;
		direction = 0;

		std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4), topleft(5), topright(6), bottomleft(7), bottomright(8)\n";

		std::cin >> direction;

		std::cout << "how many times would you like to move\n";

		std::cin >> choice;

		switch (direction)
		{

		case 1:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += choice;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 2:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= choice;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 3:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Xlocation += choice;

			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 4:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Xlocation -= choice;

			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;
		case 5:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 6:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 7:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 8:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= choice;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= choice;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		}

		break;
		//============================================================================================================================================================================

		//King movement
		//===========================================KING_MOVEMENT====================================================================================================================
	case 5:

		direction = 0;

		std::cout << "which direction would you like to go Front(1), Back(2), Left(3), Right(4), topleft(5), topright(6), bottomleft(7), bottomright(8)\n";

		std::cin >> direction;

		switch (direction)
		{

		case 1:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 1;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 2:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 1;

			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 3:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Xlocation += 1;

			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 4:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Xlocation -= 1;

			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;
		case 5:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 6:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation += 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 7:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation += 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		case 8:

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = 'X';

			pickedGamePiece.Ylocation -= 1;
			blackPlayablePieces[gamePieceLocation].Ylocation = pickedGamePiece.Ylocation;

			pickedGamePiece.Xlocation -= 1;
			blackPlayablePieces[gamePieceLocation].Xlocation = pickedGamePiece.Xlocation;

			gameBoard[pickedGamePiece.Ylocation][pickedGamePiece.Xlocation] = pickedGamePiece.gamePieceChar;

			break;

		}

		break;
		//============================================================================================================================================================================

	}

}
*/
//======================================================================================