#include "Map.h"

extern Console g_Console;

extern int Areanum;

char** mapstore(char** printmap)
{
	std::ifstream area;

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

	if (area.is_open())
	{
		for (int AreaY = 0; AreaY < 23; AreaY++)
		{
			printmap[AreaY] = new char[150];

			for (int AreaX = 0; AreaX < 109; AreaX++)
			{
				area >> printmap[AreaY][AreaX];
			}
		}
		area.close();
	}

	return printmap;
}

void map(char** printmap)
{
	COORD c;

	for (int AreaY = 0; AreaY < 23; ++AreaY)
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
}