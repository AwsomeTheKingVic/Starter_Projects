#pragma once
class Tic_Tac_Toe
{

	//variables
	char gameBoard[9] = {'1','2','3','4','5','6','7','8','9'};
	bool isPlayer1 = true;
	int choice = 0, location;

public:

	//functions
	void StartUp();
	void Restart();
	void GameSingle();
	void GameCOOP();
	void PrintArray();
	void Computer();
	void Player1();
	void Player2();
	bool WinChecker();

};

