#include "CheckColiChase.h"
#include "ChaseMap.h"

extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern SGameChar g_sChar;
extern SGameChar AIAva;
extern int levelfinish;

int CollisionChase(int checkChase)
{
	char chasearr[150][150];
	int height = 1;
	int width = 0;

	std::ifstream mazestore;

	mazestore.open("Text files/Maze.txt");

	if (mazestore.is_open())
	{
		while (height < 48)
		{
			while (width < 109)
			{
				mazestore >> chasearr[width][height];
				width++;
			}
			width = 0;
			height++;
		}

		mazestore.close();
	}

	if (checkChase == 1)
	{
		switch (chasearr[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1])
		{
		case 'F':
			return 1;
		case '|':
			g_eGameState = S_GAME;
			levelfinish = 8;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;
			break;
		default:
			return 0;
		}
	}
	if (checkChase == 2)
	{
		switch (chasearr[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1])
		{
		case 'F':
			return 1;
		case '|':
			g_eGameState = S_GAME;
			levelfinish = 8;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;
			break;
		default:
			return 0;
		}
	}
	if (checkChase == 3)
	{
		switch (chasearr[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y])
		{
		case 'F':
			return 1;
		case '|':
			g_eGameState = S_GAME;
			levelfinish = 8;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;
			break;
		default:
			return 0;
		}
	}
	if (checkChase == 4)
	{
		switch (chasearr[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y])
		{
		case 'F':
			return 1;
		case '|':
			g_eGameState = S_GAME;
			levelfinish = 8;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;
			break;
		default:
			return 0;
		}
	}
}