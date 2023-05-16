#include "ChessGame.h"
#include <iostream>

void ChessGame::StartUp()
{

	BoardSetUP();
	AddGamePieces();
	Playerone();

}

void ChessGame::PrintBoard()
{

	for (int r = 0; r < row; r++) {

		for (int c = 0; c < column; c++) {

			std::cout << gameBoard[r][c] << " ";

		}

		std::cout << std::endl;

	}

}

//sets up the board
void ChessGame::BoardSetUP()
{
	for (int r = 0; r < row; r++) {

		for (int c = 0; c < column; c++) {

			if (flipFlop == 1) {

				gameBoard[r][c] = 'O';

				flipFlop = flipFlop * (-1);

			}
			else {

				gameBoard[r][c] = 'X';

				flipFlop = flipFlop * (-1);

			}

		}

		flipFlop = flipFlop * (-1);

	}

}

void ChessGame::AddGamePieces()
{

	//it gets the top row its bad but ill fix it later
	//black piece top row
	for (int c = 0; c < 8; c++) {

		playablePieces.push_back(gamePieceInfo);

		if (c == 0) {

			playablePieces[c] = { rook, black,'R',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 1) {

			playablePieces[c] = { knight, black,'H',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 2) {

			playablePieces[c] = { bishop, black,'B',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 3) {

			playablePieces[c] = { queen, black,'Q',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 4) {

			playablePieces[c] = { king, black,'K',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 5) {

			playablePieces[c] = { bishop, black,'B',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 6) {

			playablePieces[c] = { knight, black,'H',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 7) {

			playablePieces[c] = { rook, black,'R',c,0 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}

	}

	//black playable pieces
	for (int c = 8; c < 16; c++) {

		playablePieces.push_back(gamePieceInfo);

		playablePieces[c] = {pawn, black,'P',c,1};

		gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

	}

	//white piece bottom row
	for (int c = 16; c < 24; c++) {

		playablePieces.push_back(gamePieceInfo);

		if (c == 16) {

			playablePieces[c] = { rook, white,'R',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 17) {

			playablePieces[c] = { knight, white,'H',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 18) {

			playablePieces[c] = { bishop, white,'B',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 19) {

			playablePieces[c] = { queen, white,'Q',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 20) {

			playablePieces[c] = { king, white,'K',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 21) {

			playablePieces[c] = { bishop, white,'B',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 22) {

			playablePieces[c] = { knight, white,'H',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}
		else if (c == 23) {

			playablePieces[c] = { rook, white,'R',c,7 };

			gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		}

	}

	//white playable pieces
	for (int c = 24; c < 32; c++) {

		playablePieces.push_back(gamePieceInfo);

		playablePieces[c] = {pawn, white,'P',c,6};

		gameBoard[playablePieces[c].Ylocation][playablePieces[c].Xlocation] = playablePieces[c].gamePieceChar;

		

	}

	PrintBoard();

	//std::cout << playablePieces.size();

	//std::cout << playablePieces[c].type << '\t' << playablePieces[c].color << '\t' << playablePieces[c].gamePieceChar << '\t' << playablePieces[c].Xlocation << '\t' << playablePieces[c].Ylocation << '\t' << "\n";

}

void ChessGame::Playerone()
{

	for (int i = 0; i < playablePieces.size(); i++) {

		if (playablePieces[i].color == 0) {

			std::cout << playablePieces[i].gamePieceChar << '\t' << (i) << "\n";

		}

		//std::cout << playablePieces[i].type << '\t' << playablePieces[i].color << '\t' << playablePieces[i].gamePieceChar << '\t' << playablePieces[i].Xlocation << '\t' << playablePieces[i].Ylocation << '\t' << "\n";

	}

}
