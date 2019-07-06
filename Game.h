#pragma once
#include <iostream>
#include "Queue.h"
#include <windows.h>
#include <conio.h>
#include <ctime>




class Game
{
private:
	Queue<int> obj1, obj2, obj3;
	const int Q_SIZE;
	int points;
	bool stopRound;
	int counter;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cPosition;

public:
	Game();
	void Lever();
private:
	void EndGame();
	void SetConsole(int x, int y);
	int getPoints() { return points; }

};