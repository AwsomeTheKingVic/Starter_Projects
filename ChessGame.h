#pragma once
#include <iostream>
#include <array>
#include <vector>

class ChessGame
{

	//variables
	int flipFlop = 1, row = 8, column = 8, choice = 0, direction = 0;
	bool endGame = false, turn = 0;
	char gameBoard[8][8];
	enum pieceType {pawn = 0, bishop, knight, rook, queen, king};
	enum pieceColor {white = 0, black};

	struct GamePiece {

		pieceType type = pawn;
		pieceColor color = white;
		char gamePieceChar = 'Z';
		int Xlocation = 0, Ylocation = 0;
		bool pawnFirstMove = true;
		
	};

	GamePiece gamePieceInfo;
	std::vector<GamePiece> whitePlayablePieces;
	std::vector<GamePiece> blackPlayablePieces;

public:

	//functions
	void StartUp();

private:

	//functions
	void PrintBoard();
	void BoardSetUP();
	void AddGamePieces();
	void Player();
	void PlayerOne();
	void PlayerTwo();
	void CheckPawn(GamePiece);
	std::tuple<bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool, bool> CanWhitePiecesMove(GamePiece);
	void PawnMovement(GamePiece, int);
	void WhitePawnMovement(GamePiece, int);
	void BlackPawnMovement(GamePiece, int);

};

