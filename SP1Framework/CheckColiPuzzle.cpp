#include "CheckColiPuzzle.h"
#include "PuzzleLevels.h"

extern Console g_Console;
extern SGameChar g_sChar;

extern int Areanum;
extern int EssentialFragment;
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
		file.open("Text files/6_Funeral.txt");
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
		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (checkPuzzle == 2)
	{
		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (checkPuzzle == 3)
	{
		if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (checkPuzzle == 4)
	{
		if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'F')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}