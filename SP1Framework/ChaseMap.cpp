#include "ChaseMap.h"
#include "game.h"

extern Console g_Console;
extern SGameChar AIAva;
extern bool restart;

char destroy[150][150];

char** chasestore(char** printchase)
{
	std::ifstream maze;

	maze.open("Text files/Maze.txt");

	if (maze.is_open())
	{
		for (int AreaY = 0; AreaY < 48; AreaY++)
		{
			printchase[AreaY] = new char[150];

			for (int AreaX = 0; AreaX < 109; AreaX++)
			{
				maze >> printchase[AreaY][AreaX];
			}
		}
		maze.close();
	}

	return printchase;
}

void chasemap(char** printchase)
{
	COORD c;

	for (int AreaY = 0; AreaY < 48; ++AreaY)
	{
		c.Y = AreaY + 1;

		for (int AreaX = 0; AreaX < 109; ++AreaX)
		{
			if (printchase[AreaY][AreaX] == 'F')
			{
				printchase[AreaY][AreaX] = ' ';
			}
			if (printchase[AreaY][AreaX] == '\n')
			{
				printchase[AreaY][AreaX] = ' ';
			}

			c.X = AreaX;

			g_Console.writeToBuffer(c, printchase[AreaY][AreaX], 0x07);
		}
	}

	for (int AreaY = 0; AreaY < 48; ++AreaY)
	{
		c.Y = AreaY;

		for (int AreaX = 0; AreaX < 109; ++AreaX)
		{
			c.X = AreaX;

			if (destroy[AreaY][AreaX] == ' ')
			{
				g_Console.writeToBuffer(c, destroy[AreaY][AreaX], 0x07);
			}
		}
	}

	if (restart)
	{
		for (int AreaY = 0; AreaY < 48; ++AreaY)
		{
			c.Y = AreaY;

			for (int AreaX = 0; AreaX < 109; ++AreaX)
			{
				c.X = AreaX;

				if (destroy[AreaY][AreaX] == ' ')
				{
					destroy[AreaY][AreaX] = 'A';
				}
			}
		}

		restart = false;
	}
}

void erase(bool replace)
{
	COORD c;

	if (replace)
	{
		destroy[AIAva.m_cLocation.Y][AIAva.m_cLocation.X] = ' ';
	}
}