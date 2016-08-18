#include "CheckColi.h"
#include "Map.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];

int Collision(int check)
{
	char whatever[150][150];

	std::ifstream file;

	file.open("Text files/Area 1.txt");
	int height = 1;
	int width = 0;

	if (file.is_open())
	{
		while (height < 16)
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

	if (check == 1)
	{
		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'F')
		{
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '.')
		{
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (check == 2)
	{
		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'F')
		{
			return 1;
		}
		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '.')
		{
			return 1;
		}
		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (check == 3)
	{
		if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'F')
		{
			return 1;
		}
		if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '.')
		{
			return 1;
		}
		if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (check == 4)
	{
		if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'F')
		{
			return 1;
		}
		if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '.')
		{
			return 1;
		}
		if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


}

/*
false = there is collision
true = no collision

g_abKeyPressed[K_UP]     = 1
g_abKeyPressed[K_DOWN]   = 2
g_abKeyPressed[K_LEFT]   = 3
g_abKeyPressed[K_RIGHT]  = 4
*/