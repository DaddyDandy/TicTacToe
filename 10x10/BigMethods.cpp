#include "StdAfx.h"
#include "BigGame.h"
#include <time.h>

void Game::Gaming(int numberOfButton1, int numberOfButton2)
{
	if(strokes % 2 == 0) setPlayer(1);
	if(strokes % 2 != 0) setPlayer(2);
	setGameField(numberOfButton1, numberOfButton2, getPlayer() );
	strokes++;
}

int Game::WhoWin()
{
	
	int crossCounter = 0;
	int zeroCounter = 0;
	int drawCounter = 0;
	//Ничья
	for(int i = 0; i < 10; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			if(getGameField(i, j) != 0)
			{
				drawCounter++;
				if(drawCounter == 100)
				{
					ClearField();
					return 3;
				}				
			}
			if(getGameField(i, j) == 0)
			{
				drawCounter = 0;
			}
		}
	}
	//победа Х по столбцу
	for(int i = 0; i < 10; ++i,crossCounter = 0)
		for(int j = 0; j < 10; ++j)
		{
			if(getGameField(i, j) == 2 || getGameField(i, j) ==0){crossCounter=0;}
			if(getGameField(i, j) ==1)
			{
				crossCounter++;
				if(crossCounter==5){ClearField();return 1;}
			}	
		}
	//победа O по столбцу
	for(int i = 0; i < 10; ++i,zeroCounter = 0)
		for(int j = 0; j < 10; ++j)
		{
			if(getGameField(i, j) ==1 || getGameField(i, j) ==0){zeroCounter=0;}
			if(getGameField(i, j) ==2)
			{
				zeroCounter++;
				if(zeroCounter==5){ClearField();return 2;}
			}
			
		}
	//победа Х по строке
	for(int i = 0; i < 10; ++i,crossCounter = 0)
		for(int j = 0; j < 10; ++j)
		{
			if(getGameField(j, i) ==2 || getGameField(j, i) ==0){crossCounter=0;}
			if(getGameField(j, i) ==1)
			{
				crossCounter++;
				if(crossCounter==5){ClearField();return 1;}
			}
			
		}
	//победа O по строке
	for(int i = 0; i < 10; ++i,zeroCounter = 0)
		for(int j = 0; j < 10; ++j)
		{
			if(getGameField(j, i) ==1 || getGameField(j, i) ==0){zeroCounter=0;}
			if(getGameField(j, i) ==2)
			{
				zeroCounter++;
				if(zeroCounter==5){ClearField();return 2;}
			}
			
		}

	//победа Х по главной диагонали
	int p = 0;
	int k = 15;
	for(int a = 0; a < 7; ++a,crossCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = p; i < k; ++i)
			{
				if(getGameField(i, i - p) != 1) {crossCounter = 0;}//---------------------------------
				if(getGameField(i, i - p) == 1)//всегда начинает проверять с Р-й строки
				{
					crossCounter++;
					if(crossCounter==5){ClearField(); return 1;}	
				}
			}
			p++;
			k--;
		}
	}
	//победа О по главной диагонали
	p = 0;
	k = 15;
	for(int a = 0; a < 7; ++a,zeroCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = p; i < k; ++i)//всегда начинает проверять с Р-й строки
			{
				if(getGameField(i, i - p) != 2){zeroCounter = 0;}
				if(getGameField(i, i - p) == 2)
				{
					zeroCounter++;
					if(zeroCounter==5){ClearField();return 2;}	
				}
			}
			p++;
			k--;
		}
	}
	//победа Х по главной диагонали 2
	p = 0;
	k = 15;
	for(int a = 0; a < 7; ++a,crossCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = 0; i < k; ++i)//всегда начинает проверять с 0й строки
			{
				if(getGameField(i, i + p) != 1){crossCounter=0;}
				if(getGameField(i, i + p) == 1)
				{
					crossCounter++;
					if(crossCounter==5){ClearField();return 1;}	
				}
			}
			p++;
			k--;
		}
	}
	//победа О по главной диагонали 2
	p = 0;
	k = 15;
	for(int a = 0; a < 7; ++a,zeroCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = 0; i < k; ++i)//всегда начинает проверять с 0й строки
			{
				if(getGameField(i, i + p) != 2){zeroCounter=0;}
				if(getGameField(i, i + p) == 2)
				{
					zeroCounter++;
					if(zeroCounter==5){ClearField();return 2;}	
				}
			}
			p++;
			k--;
		}
	}

	//победа Х по побочной диагонали
	p = 0;
	k = 15;
	for(int a = 0; a < 7; ++a,crossCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = 0; i < k; ++i)
			{
				if(getGameField(i, 10 - 1 - i - p) != 1){crossCounter=0;}
				if(getGameField(i, 10 - 1 - i - p) == 1)
				{
					crossCounter++;
					if(crossCounter==5){ClearField();return 1;}
				}
			}
			p++;
			k--;
		}
	}
	//победа О по побочной диагонали
	p = 0;
	k = 15;
	for(int a = 4; a < 10; ++a,zeroCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = p; i < k; ++i)
			{
				if(getGameField(i, 10 - 1 - i + p) != 2){zeroCounter=0;}
				if(getGameField(i, 10 - 1 - i + p) == 2)
				{
					zeroCounter++;
					if(zeroCounter==5){ClearField();return 2;}	
				}
			}
			p++;
			k--;
		}
	}
	//победа Х по побочной диагонали 2
	p = 0;
	k = 15;
	for(int a = 0; a < 7; ++a,crossCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = p; i < k; ++i)
			{
				if(getGameField(i, 10 - 1 - i + p) != 1){crossCounter=0;}
				if(getGameField(i, 10 - 1 - i + p) == 1)
				{
					crossCounter++;
					if(crossCounter==5){ClearField();return 1;}	
				}
			}
			p++;
			k--;
		}
	}
	//победа О по побочной диагонали 2
	p = 0;
	k = 15;
	for(int a = 4; a < 10; ++a,zeroCounter = 0) 
	{
		if(p == 7){p = 0;break;}
		else
		{
			for(int i = 0; i < k; ++i)
			{
				if(getGameField(i, 10 - 1 - i - p) != 2){zeroCounter=0;}
				if(getGameField(i, 10 - 1 - i - p) == 2)
				{
					zeroCounter++;
					if(zeroCounter==5){ClearField();return 2;}
				}
			}
			p++;
			k--;
		}
	}
}

void Game::ClearField()
{
	for (int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j)
		{ 
			setGameField(i, j, 0); 		
		}
	strokes = 2; //важно(номер хода(тот, который %2==0))
}
