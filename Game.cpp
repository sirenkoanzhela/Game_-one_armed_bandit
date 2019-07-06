#include "Game.h"

Game::Game() : Q_SIZE(6), points(0),stopRound(false),counter(0)
{
	for (int i = 0; i < Q_SIZE; i++)
	{
		obj1.Add(i);
		obj2.Add(i);
		obj3.Add(i);
	}
}

void Game::Lever() {
	srand(time(0));

	int key;
	int item = 0;
	char element1, element2, element3;
	std::cout << "PRESS ENTER - NEW ROUND" << std::endl;
	std::cout << "PRESS ESCAPE - EXIT" << std::endl;

	do {
		key = _getch();
		if (key == VK_RETURN)
		{
			SetConsole(0, 5);
			std::cout << "                       " << std::endl;
			for (int i = 0; i < Q_SIZE; i++)
			{
				Sleep(200);

				for (int i = 0; i < rand() % 10 + 1; i++)
				{
					obj1.Remove(item);
					element1 = item;
				}
				for (int i = 0; i < rand() % 10 + 1; i++)
				{
					obj2.Remove(item);
					element2 = item;
				}
				for (int i = 0; i < rand() % 10 + 1; i++)
				{
					obj3.Remove(item);
					element3 = item;
				}


				SetConsole(0, 3);
				std::cout << element1 << std::endl;

				SetConsole(4, 3);
				std::cout << element2 << std::endl;

				SetConsole(8, 3);
				std::cout << element3 << std::endl;


			}
			if (element1 == element2 || element1 == element3 || element2 == element3)
			{
				SetConsole(0, 5);
				std::cout << "YOU'VE GOT 100 POINTS!" << std::endl;
				points += 100;
			}
		}

		else if (key == VK_ESCAPE)
		{
			std::cout << "EXIT" << std::endl;
			exit(0);
		}
		counter++;
		if (counter == Q_SIZE) { stopRound = true; }
		if (stopRound) { EndGame(); }
	} while (true);

}

void Game::EndGame()

{
	SetConsole(0, 7);
	if (points >= 600) { std::cout << "SCORE: " << points << "   CONGRATULATION! YOU ARE WINNER!" << std::endl; }
	else if (points >= 300 && points <= 500) { std::cout << "SCORE: " << points << "   YOU'GOT SECOND PLACE!" << std::endl; }
	else if (points < 300) std::cout << "SCORE: " << points << "   BETTER LUCK NEXT TIME" << std::endl;
	exit(0);
}

void Game::SetConsole(int x, int y)
{
	cPosition.X = x;
	cPosition.Y = y;
	SetConsoleCursorPosition(hConsole, cPosition);
}