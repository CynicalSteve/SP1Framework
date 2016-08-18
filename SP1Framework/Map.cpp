#include "Map.h"

extern Console g_Console;

char** mapstore(char** printmap)
{

	std::ifstream area1("Text files/Area 1.txt");

	if (area1.is_open())
	{
		for (int AreaY = 0; AreaY < 16; AreaY++)
		{
			printmap[AreaY] = new char[150];

			for (int AreaX = 0; AreaX < 109; AreaX++)
			{
				area1 >> printmap[AreaY][AreaX];
			}
		}
		area1.close();
	}

	return printmap;
}

void map(char** printmap)
{
	COORD c;

	std::ifstream area1("Text files/Area 1.txt");

	if (area1.is_open())
	{
		for (int AreaY = 0; AreaY < 16; ++AreaY)
		{
			c.Y = AreaY + 1;

			for (int AreaX = 0; AreaX < 109; ++AreaX)
			{
				if (printmap[AreaY][AreaX] == 'F')
				{
					printmap[AreaY][AreaX] = ' ';
				}
				if (printmap[AreaY][AreaX] == '\n')
				{
					printmap[AreaY][AreaX] = ' ';
				}

				c.X = AreaX;

				g_Console.writeToBuffer(c, printmap[AreaY][AreaX], 0x07);
			}
		}
		area1.close();
	}
}