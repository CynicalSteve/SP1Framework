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
			if (Areanum == 1)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 87;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}
			else if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 103;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 36;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 93; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 90; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 71; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 47;
			}

			Areanum++;
			return 0;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '%') 
		{
			if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 77; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 45; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 53; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 38;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 33;
			}
			else if (Areanum == 6)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 105; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}

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
			if (Areanum == 1)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 87;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}
			else if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 103;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 36;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 93; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 90; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 71; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 47;
			}

			Areanum++;
			return 0;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '%') 
		{
			if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 77; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 45; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 53; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 38;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 33;
			}
			else if (Areanum == 6)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 105; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}

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
			if (Areanum == 1)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 87;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}
			else if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 103;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 36;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 93; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 90; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 71; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 47;
			}

			Areanum++;
			return 0;
		}
		else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '%') 
		{
			if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 77; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 45; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 53; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 38;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 33;
			}
			else if (Areanum == 6)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 105; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}

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
			if (Areanum == 1)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 87;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}
			else if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 103;
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 36;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 93; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 90; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 53;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 71; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 47;
			}

			Areanum++;
			return 0;
		}
		else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '%') 
		{
			if (Areanum == 2)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 77; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 3)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 45; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 50;
			}
			else if (Areanum == 4)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 53; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 38;
			}
			else if (Areanum == 5)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 33;
			}
			else if (Areanum == 6)
			{
				g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 105; 
				g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
			}

			Areanum--;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}