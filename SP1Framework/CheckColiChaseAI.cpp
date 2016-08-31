#include "CheckColiChaseAI.h"

extern Console g_Console;
extern SGameChar AIAva;

int CollisionChaseAI(int checkChaseAI)
{
	char chasearrAI[150][150];
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
				mazestore >> chasearrAI[width][height];
				width++;
			}
			width = 0;
			height++;
		}

		mazestore.close();
	}

	if (checkChaseAI == 1)
	{
		switch (chasearrAI[AIAva.m_cLocation.X][AIAva.m_cLocation.Y - 1])
		{
		case 'F':
			return 1;
		case '_':
			return 2;
		case 'I':
			return 2;
		default:
			return 0;
		}
	}
	if (checkChaseAI == 2)
	{
		switch (chasearrAI[AIAva.m_cLocation.X][AIAva.m_cLocation.Y + 1])
		{
		case 'F':
			return 1;
		case '_':
			return 2;
		case 'I':
			return 2;
		default:
			return 0;
		}
	}
	if (checkChaseAI == 3)
	{
		switch (chasearrAI[AIAva.m_cLocation.X - 1][AIAva.m_cLocation.Y])
		{
		case 'F':
			return 1;
		case '_':
			return 2;
		case 'I':
			return 2;
		default:
			return 0;
		}
	}
	if (checkChaseAI == 4)
	{
		switch (chasearrAI[AIAva.m_cLocation.X + 1][AIAva.m_cLocation.Y])
		{
		case 'F':
			return 1;
		case '_':
			return 2;
		case 'I':
			return 2;
		default:
			return 0;
		}
	}
}