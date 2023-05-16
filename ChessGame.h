#pragma once
#include <array>
#include <vector>

class ChessGame
{

	//variables
	int flipFlop = 1, row = 8, column = 8;
	char gameBoard[8][8];
	enum pieceType {pawn = 0, bishop, knight, rook, queen, king};
	enum pieceColor {white = 0, black};

	struct GamePiece {

		pieceType type = pawn;
		pieceColor color = white;
		char gamePieceChar = type;
		int Xlocation = 0, Ylocation = 0;

	};
	GamePiece gamePieceInfo;
	std::vector<GamePiece> playablePieces;
	//maybe
	std::vector<GamePiece> whitePlayablePieces;

public:

	//functions
	void StartUp();
	void PrintBoard();
	void BoardSetUP();
	void AddGamePieces();
	void Playerone();

};

