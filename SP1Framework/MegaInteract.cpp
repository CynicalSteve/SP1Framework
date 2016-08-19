#include "MegaInteract.h"

extern Console g_Console;
extern SGameChar g_sChar;

extern int Areanum;
extern int EssentialFragment;

int Factfeed = 0;

// 1 = Sea, 2 = Trees, 3 = Portal?

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

		else
		{
			return 0;
		}
	}
}

int FstandsforFrustrating(int checkF)
{
	if (checkF == 1)
	{
		Factfeed = 1;
	}
	else if (checkF == 0)
	{
		Factfeed = 0;

		// clear everything here
	}

	return 0;
}