#include <iostream>
#include "stdafx.h"

using namespace std;

class Game
{
private:
	const static int DEFAULT_FIELD_SIZE = 10;
private:
	int fieldSize;	
	int player;
	int strokes;		
	int gameField[DEFAULT_FIELD_SIZE][DEFAULT_FIELD_SIZE];	

public:

	Game(){}

	void setGameField (int line, int row, int newValue)
	{
		this->gameField[line][row] = newValue;
	}
	int getGameField (int line, int row) const
	{
		return gameField[line][row];
	}

	void setPlayer (int newPlayer)
	{
		this->player = newPlayer;
	}
	int getPlayer() const
	{
		return player;
	}
	
	void Gaming(int,int);
	int WhoWin();
	void ClearField();
};