#include "CheckColi.h"
#include "Map.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];

extern int Areanum;
extern int EssentialFragment;

int Collision(int check)
{
	char whatever[150][150];
	int height = 1;
	int width = 0;

	std::ifstream file;

	// file.open("Text files/Area 1.txt");

	if (Areanum == 1)
	{
		file.open("Text files/Area 1.txt");
	}
	else if (Areanum == 2)
	{
    	file.open("Text files/Area 2 & 3.txt");
	}
	else if (Areanum == 3)
	{
    	file.open("Text files/Area 4 & 5.txt");
	}
	else if (Areanum == 4)
	{
    	file.open("Text files/Area 6 & 7.txt");
	}
	else if (Areanum == 5)
	{
    	file.open("Text files/Area 8 & 9 & 10.txt");
	}
	else if (Areanum == 6)
	{
	    file.open("Text files/Area 11.txt");
	}

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
		else if ((whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '#') && (EssentialFragment >= Areanum))
		{
			Areanum++;
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '%')
		{
			Areanum--;
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
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '.')
		{
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T')
		{
			return 1;
		}
		else if ((whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '#') && (EssentialFragment >= Areanum))
		{
			Areanum++;
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '%')
		{
			Areanum--;
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
		else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '.')
		{
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T')
		{
			return 1;
		}
		else if ((whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '#') && (EssentialFragment >= Areanum))
		{
			Areanum++;
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '%')
		{
			Areanum--;
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
		else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '.')
		{
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T')
		{
			return 1;
		}
		else if ((whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '#') && (EssentialFragment >= Areanum))
		{
			Areanum++;
			return 1;
		}
		else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '%')
		{
			Areanum--;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}