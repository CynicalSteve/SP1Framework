#include "MegaInteract.h"

extern Console g_Console;
extern SGameChar g_sChar;

extern int Areanum;

int Factfeed = 0;
int InPortal = 0;
int TutorialMode = 1; // Instead of doing "Y/N" for the first portal, I'm implementing this.
int tempF;
int EssentialFragment = 0;
int OptionalFragment = 0;
std::string inventory = "none";

/*
Sea = 1
Trees = 2
Essential Fragment = 30
Optional Fragment = 31
EF 1 = 10x
    10x -> 101 Rocks
	   -> 102 Fish
	   -> 103 Box
EF 2 = 20x
    20x -> ??
EF 3 = 30x
    30x -> ??
*/

int checkinteract(void)
{
	char whatever[150][150];
	int height = 1;
	int width = 0;

	std::ifstream file;

	if (Areanum > 0)
	{
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
	}
	else if (Areanum == 0)
	{
		if (InPortal == 1 || InPortal == 2)
		{
			file.open("Text files/1_Lake.txt");
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
	else if (Areanum == 0)
	{
		if (InPortal == 1)
		{
			// UP UP UP UP UP

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '0')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '.')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'o')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'O')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '-')
			{
				return 102;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '_')
			{
				return 104;
			}

			// DOWN DOWN DOWN DOWN DOWN

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '_')
			{
				return 104;
			}

			// LEFT LEFT LEFT LEFT LEFT

			if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 104;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 104;
			}
		}
		else if (InPortal == 2) // **********EDIT THIS LATER************
		{
			// UP UP UP UP UP

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '0')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '.')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'o')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'O')
			{
				return 101;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '-')
			{
				return 102;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '_')
			{
				return 104;
			}

			// DOWN DOWN DOWN DOWN DOWN

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '_')
			{
				return 104;
			}

			// LEFT LEFT LEFT LEFT LEFT

			if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 104;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '<')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '>')
			{
				return 103;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 104;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 104;
			}
		}
		else if (InPortal == 3)
		{
			return 0;
		}
		else if (InPortal == 4)
		{
			return 0;
		}
		else if (InPortal == 5)
		{
			return 0;
		}
		else if (InPortal == 6)
		{
			return 0;
		}
		else if (InPortal == 7)
		{
			return 0;
		}
		else if (InPortal == 8)
		{
			return 0;
		}
		else if (InPortal == 9)
		{
			return 0;
		}
		else if (InPortal == 10)
		{
			return 0;
		}
		else if (InPortal == 11)
		{
			return 0;
		}

		else
		{
			return 0;
		}
	}
}

int FstandsforFrustrating(int checkF)
{
	if (Factfeed == 3 && checkF == 9) // Check if user is pressing "F" and then "E" afterwards to enter it.
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

	if (tempF == 101 && checkF == 9)
	{
		inventory = "A flat rock";
	}

	if (inventory == "A flat rock" && tempF == 102 && checkF == 9) // Check if user is pressing "F" and then "E" afterwards to do something.
	{
		EssentialFragment += 1;
		Areanum = 1;
		InPortal = 0;
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
	else if (checkF == 101)
	{
		Factfeed = 11;
	}
	else if (checkF == 102)
	{
		Factfeed = 12;
	}
	else if (checkF == 103)
	{
		Factfeed = 13;
	}
	else if (checkF == 104)
	{
		Factfeed = 14;
	}
	else if (checkF == 0)
	{
		Factfeed = 0;

		// clear everything here
	}

	tempF = checkF;

	return 0;
}