#include "CheckColiPuzzle.h"
#include "PuzzleLevels.h"

extern Console g_Console;
extern SGameChar g_sChar;

extern int Areanum;
extern int OptionalFragment;
extern int InPortal;


int CollisionPuzzle(int checkPuzzle)
{
	char whatever[150][150];
	int height = 1;
	int width = 0;

	std::ifstream file;

	switch (InPortal)
	{
	case 1:
		file.open("Text files/1_Lake.txt");
		break;
	case 2:
		file.open("Text files/1_Lake.txt");
		break;
	case 3:
		file.open("Text files/2_Chappel.txt");
		break;
	case 4:
		file.open("Text files/2_ChappelOF.txt");
		break;
	case 5:
		file.open("Text files/3_ComputerRoom.txt");
		break;
	case 6:
		file.open("Text files/3_ComputerRoomOF.txt");
		break;
	case 7:
		file.open("Text files/4_Street.txt");
		break;
	case 8:
		file.open("Text files/4_StreetOF.txt");
		break;
	case 9:
		file.open("Text files/5_LivingRoom.txt");
		break;
	case 10:
		file.open("Text files/5_LivingRoomOF.txt");
		break;
	case 11:
		if (OptionalFragment < 5)
		{
			file.open("Text files/6_Funeral.txt");
		}
		else if (OptionalFragment == 5)
		{
			file.open("Text files/6_FuneralTrueEnd.txt");
		}
		break;
	case 12:
		file.open("Text files/1_LakeXFish.txt");
		break;
	case 13:
		file.open("Text files/2_ChappelXSphere.txt");
		break;
	case 14:
		file.open("Text files/3_ComputerRoomXBook.txt");
		break;
	case 15:
		file.open("Text files/Bedroom.txt");
		break;
	case 16:
		file.open("Text files/6_FuneralNXBook.txt");
		break;
	case 17:
		file.open("Text files/6_FuneralTrueEndNXBook.txt");
		break;
	case 18:
		file.open("Text files/Maze.txt");
		break;
	}

	if (file.is_open())
	{
		while (height < 23)
		{
			while (width < 109)
			{
				file >> whatever[width][height];
				width++;
			}
			width = 0;
			height++;
		}

		file.close();
	}

	if (checkPuzzle == 1)
	{
		switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1])
		{
		case 'F':
			return 1;
		case 'W':
			return 1;
		case 'Y':
			return 1;
		case 'P':
			return 1;
		case 'S':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 1;
		case 'D':
			return 1;
		case '-':
			if (InPortal == 7 || InPortal == 8)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		default:
			return 0;
		}
	}
	if (checkPuzzle == 2)
	{
		switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1])
		{
		case 'F':
			return 1;
		case 'W':
			return 1;
		case 'Y':
			return 1;
		case 'P':
			return 1;
		case 'S':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 1;
		case 'D':
			return 1;
		case '-':
			if (InPortal == 7 || InPortal == 8)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		default:
			return 0;
		}
	}
	if (checkPuzzle == 3)
	{
		switch (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y])
		{
		case 'F':
			return 1;
		case 'W':
			return 1;
		case 'Y':
			return 1;
		case 'P':
			return 1;
		case 'S':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 1;
		case 'D':
			return 1;
		case '-':
			if (InPortal == 7 || InPortal == 8)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		default:
			return 0;
		}
	}
	if (checkPuzzle == 4)
	{
		switch (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y])
		{
		case 'F':
			return 1;
		case 'W':
			return 1;
		case 'Y':
			return 1;
		case 'P':
			return 1;
		case 'S':
			return 1;
		case 'B':
			return 1;
		case 'C':
			return 1;
		case 'D':
			return 1;
		case '-':
			if (InPortal == 7 || InPortal == 8)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		default:
			return 0;
		}
	}
}