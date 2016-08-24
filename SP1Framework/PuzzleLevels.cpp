#include "PuzzleLevels.h"

extern Console g_Console;

extern int Areanum;
extern int InPortal;

char** puzzlestore(char** printlevel)
{
	std::ifstream puzzle;
	
	switch (InPortal)
	{
	case 1:
		puzzle.open("Text files/1_Lake.txt");
		break;
	case 2:
		puzzle.open("Text files/1_Lake.txt");
		break;
	case 3:
		puzzle.open("Text files/2_Chappel.txt");
		break;
	case 4:
		puzzle.open("Text files/2_ChappelOF.txt");
		break;
	case 5:
		puzzle.open("Text files/3_ComputerRoom.txt");
		break;
	case 6:
		puzzle.open("Text files/3_ComputerRoomOF.txt");
		break;
	case 7:
		puzzle.open("Text files/4_Street.txt");
		break;
	case 8:
		puzzle.open("Text files/4_StreetOF.txt");
		break;
	case 9:
		puzzle.open("Text files/5_LivingRoom.txt");
		break;
	case 10:
		puzzle.open("Text files/5_LivingRoomOF.txt");
		break;
	case 11:
		puzzle.open("Text files/6_Funeral.txt");
		break;
	case 12:
		puzzle.open("Text files/1_LakeXFish.txt");
		break;
	case 13:
		puzzle.open("Text files/2_ChappelXSphere.txt");
		break;
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
			if (printlevel[AreaY][AreaX] == 'W')
			{
				printlevel[AreaY][AreaX] = ' ';
			}
			if (printlevel[AreaY][AreaX] == 'Y')
			{
				printlevel[AreaY][AreaX] = ' ';
			}
			if (printlevel[AreaY][AreaX] == 'P')
			{
				printlevel[AreaY][AreaX] = ' ';
			}
			if (printlevel[AreaY][AreaX] == 'S')
			{
				printlevel[AreaY][AreaX] = ' ';
			}
			if (printlevel[AreaY][AreaX] == 'B')
			{
				printlevel[AreaY][AreaX] = ' ';
			}
			if (printlevel[AreaY][AreaX] == 'C')
			{
				printlevel[AreaY][AreaX] = ' ';
			}
			if (printlevel[AreaY][AreaX] == 'D')
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
