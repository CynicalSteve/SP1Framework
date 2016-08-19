#include "PuzzleLevels.h"

extern Console g_Console;

extern int Areanum;

char** puzzlestore(char** printlevel)
{
	std::ifstream area;
	
	/*

	if (Areanum == 1)
	{
		area.open("Text files/Area 1.txt");
	}
	else if (Areanum == 2)
	{
		area.open("Text files/Area 2 & 3.txt");
	}
	else if (Areanum == 3)
	{
		area.open("Text files/Area 4 & 5.txt");
	}
	else if (Areanum == 4)
	{
		area.open("Text files/Area 6 & 7.txt");
	}
	else if (Areanum == 5)
	{
		area.open("Text files/Area 8 & 9 & 10.txt");
	}
	else if (Areanum == 6)
	{
		area.open("Text files/Area 11.txt");
	}

	*/

	if (area.is_open())
	{
		for (int AreaY = 0; AreaY < 31; AreaY++)
		{
			printlevel[AreaY] = new char[150];

			for (int AreaX = 0; AreaX < 69; AreaX++)
			{
				area >> printlevel[AreaY][AreaX];
			}
		}
		area.close();
	}

	return printlevel;
}

void puzzlemap(char** printlevel)
{
	COORD c;

	std::ifstream area1("Text files/Area 1.txt");

	if (area1.is_open())
	{
		for (int AreaY = 0; AreaY < 23; ++AreaY)
		{
			c.Y = AreaY + 1;

			for (int AreaX = 0; AreaX < 109; ++AreaX)
			{
				if (printlevel[AreaY][AreaX] == 'F')
				{
					printlevel[AreaY][AreaX] = ' ';
				}
				if (printlevel[AreaY][AreaX] == '\n')
				{
					printlevel[AreaY][AreaX] = ' ';
				}

				c.X = AreaX;

				g_Console.writeToBuffer(c, printlevel[AreaY][AreaX], 0x07);
			}
		}
		area1.close();
	}
}