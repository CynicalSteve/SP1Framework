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

	if (InPortal == 1)
	{
		file.open("Text files/1_Lake.txt");
	}
	else if (InPortal == 2)
	{
		file.open("Text files/1_LakeOF.txt");
	}
	else if (InPortal == 3)
	{
		file.open("Text files/2_Chappel.txt");
	}
	else if (InPortal == 4)
	{
		file.open("Text files/2_ChappelOF.txt");
	}
	else if (InPortal == 5)
	{
		file.open("Text files/3_ComputerRoom.txt");
	}
	else if (InPortal == 6)
	{
		file.open("Text files/3_ComputerRoomOF.txt");
	}
	else if (InPortal == 7)
	{
		file.open("Text files/4_Street.txt");
	}
	else if (InPortal == 8)
	{
		file.open("Text files/4_StreetOF.txt");
	}
	else if (InPortal == 9)
	{
		file.open("Text files/5_LivingRoom.txt");
	}
	else if (InPortal == 10)
	{
		file.open("Text files/5_LivingRoomOF.txt");
	}
	else if (InPortal == 11)
	{
		file.open("Text files/6_Funeral.txt");
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