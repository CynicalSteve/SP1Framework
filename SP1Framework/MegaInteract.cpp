#include "MegaInteract.h"

extern Console g_Console;
extern SGameChar g_sChar;

extern int Areanum;
extern int EssentialFragment;

int Factfeed = 0;
int InPortal = 0;
int TutorialMode = 1; // Instead of doing "Y/N" for the first portal, I'm implementing this.
int tempF;

// 1 = Sea, 2 = Trees, 3 = Portal, 9 = Enter Portal

int checkinteract(void)
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

	if (Areanum > 0)
	{
		if (Areanum == 1)
		{
			// UP UP UP UP UP

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '|')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == ':')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '\\')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '/')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == ',')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '"')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '-')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '`')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '_')
			{
				return 1;
			}

			// DOWN DOWN DOWN DOWN DOWN

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '|')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == ':')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '\\')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '/')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == ',')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '"')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '-')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '`')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '_')
			{
				return 1;
			}

			// LEFT LEFT LEFT LEFT LEFT

			if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == ':')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '\\')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '/')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == ',')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '"')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '-')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '`')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 1;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == ':')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '\\')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '/')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == ',')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '"')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '-')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '`')
			{
				return 1;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 1;
			}
		}

		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'T')
		{
			return 2;
		}

		if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '!')
		{
			return 30;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '!')
		{
			return 30;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '?')
		{
			return 31;
		}
		else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '?')
		{
			return 31;
		}

		else
		{
			return 0;
		}
	}
}

int FstandsforFrustrating(int checkF)
{
	if (Factfeed == 3 && checkF == 9)
	{
		if (Areanum == 1)
		{
			if (tempF == 30) // !
			{
				InPortal = 1;
				Areanum = 0;
			}
			else if (tempF == 31) // ?
			{
				InPortal = 2;
				Areanum = 0;
			}
		}
		if (Areanum == 2)
		{
			if (tempF == 30) // !
			{
				InPortal = 3;
				Areanum = 0;
			}
			else if (tempF == 31) // ?
			{
				InPortal = 4;
				Areanum = 0;
			}
		}
		if (Areanum == 3)
		{
			if (tempF == 30) // !
			{
				InPortal = 5;
				Areanum = 0;
			}
			else if (tempF == 31) // ?
			{
				InPortal = 6;
				Areanum = 0;
			}
		}
		if (Areanum == 4)
		{
			if (tempF == 30) // !
			{
				InPortal = 7;
				Areanum = 0;
			}
			else if (tempF == 31) // ?
			{
				InPortal = 8;
				Areanum = 0;
			}
		}
		if (Areanum == 5)
		{
			if (tempF == 30) // !
			{
				InPortal = 9;
				Areanum = 0;
			}
			else if (tempF == 31) // ?
			{
				InPortal = 10;
				Areanum = 0;
			}
		}
		if (Areanum == 6) // !
		{
			InPortal = 11;
			Areanum = 0;
		}

		if (InPortal > 0)
		{
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;

			Factfeed = 0;
		}
	}

	if (checkF == 1)
	{
		Factfeed = 1;
	}
	else if (checkF == 2)
	{
		Factfeed = 2;
	}
	else if (checkF == 30 || checkF == 31)
	{
		Factfeed = 3;
	}
	else if (checkF == 0)
	{
		Factfeed = 0;

		// clear everything here
	}

	tempF = checkF;

	return 0;
}