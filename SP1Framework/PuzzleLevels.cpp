#include "PuzzleLevels.h"

extern Console g_Console;

extern int Areanum;
extern int InPortal;

char** puzzlestore(char** printlevel)
{
	std::ifstream puzzle;
	
	if (InPortal == 1)
	{
		puzzle.open("Text files/1_Lake.txt");
	}
	else if (InPortal == 2)
	{
		puzzle.open("Text files/1_LakeOF.txt");
	}
	else if (InPortal == 3)
	{
		puzzle.open("Text files/2_Chappel.txt");
	}
	else if (InPortal == 4)
	{
		puzzle.open("Text files/2_ChappelOF.txt");
	}
	else if (InPortal == 5)
	{
		puzzle.open("Text files/3_ComputerRoom.txt");
	}
	else if (InPortal == 6)
	{
		puzzle.open("Text files/3_ComputerRoomOF.txt");
	}
	else if (InPortal == 7)
	{
		puzzle.open("Text files/4_Street.txt");
	}
	else if (InPortal == 8)
	{
		puzzle.open("Text files/4_StreetOF.txt");
	}
	else if (InPortal == 9)
	{
		puzzle.open("Text files/5_LivingRoom.txt");
	}
	else if (InPortal == 10)
	{
		puzzle.open("Text files/5_LivingRoomOF.txt");
	}
	else if (InPortal == 11)
	{
		puzzle.open("Text files/6_Funeral.txt");
	}
	/*

	else if (InPortal == 11 && OptionalFragment < 5)
	{
	    puzzle.open("Text files/6_Funeral.txt");
	}
	else if (InPortal == 11 && OptionalFragment == 5)
	{
		puzzle.open("Text files/6_FuneralTrueEnd.txt");
	}

	*/


	if (puzzle.is_open())
	{
		for (int AreaY = 0; AreaY < 23; AreaY++)
		{
			printlevel[AreaY] = new char[150];

			for (int AreaX = 0; AreaX < 109; AreaX++)
			{
				puzzle >> printlevel[AreaY][AreaX];
			}
		}
		puzzle.close();
	}

	return printlevel;
}

void puzzlemap(char** printlevel)
{
	COORD c;

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
}
