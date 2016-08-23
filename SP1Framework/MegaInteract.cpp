#include "MegaInteract.h"

extern Console g_Console;
extern SGameChar g_sChar;

extern int Areanum;
extern double g_dElapsedTime;

int Factfeed = 0;
int InPortal = 0;
int TutorialMode = 1; // Instead of doing "Y/N" for the first portal, I'm implementing this.
int tempF;
int EssentialFragment = 0; // Set to 6 to see all areas
int OptionalFragment = 0;
std::string inventory = "none";
int levelfinish = 0;
int reqinteraction = 0; // This is so we can force the player to actually read certain thingamajigs otherwise other thingamajigs wont work.
double g_dElapsedTimeTemp = 999.0;
double g_dTime = 999.0;

/*
*** *** *** CheckF *** *** ***
Sea = 1
Trees = 2
Essential Fragment = 30
Optional Fragment = 31
EF 1 = 10x
    10x -> 101 Rocks
	   -> 102 Lake
	   -> 103 Fish
	   -> 104 Box
OF 1 = 11x
    11x -> 111 Rocks
	    -> 112 Lake
		-> 113 Fish
		-> 114 Box
EF 2 = 20x
    20x -> ??
EF 3 = 30x
    30x -> ??

*** *** *** FactFeed *** *** ***
EF 1 = 1x
x corresponds with x of checkF.

Level Finish = 9Ax
A = InPortal Number
EF 1 = 91x
    91x -> 911 Lake
	    -> 912 Box
*/

int checkinteract(void)
{
	char whatever[150][150];
	int height = 1;
	int width = 0;

	std::ifstream file;

	if (Areanum > 0)
	{
		switch (Areanum)
		{
		case 1:
			file.open("Text files/Area 1.txt");
			break;
		case 2:
			file.open("Text files/Area 2 & 3.txt");
			break;
		case 3:
			file.open("Text files/Area 4 & 5.txt");
			break;
		case 4:
			file.open("Text files/Area 6 & 7.txt");
			break;
		case 5:
			file.open("Text files/Area 8 & 9 & 10.txt");
			break;
		case 6:
			file.open("Text files/Area 11.txt");
			break;
		}
	}
	
	if (Areanum == 0)
	{
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
		case 12:
			file.open("Text files/1_LakeXFish.txt");
			break;
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
		if (InPortal == 1)    //Lake EF
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
		else if (InPortal == 2 || InPortal == 12)
		{
			// UP UP UP UP UP

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '0')
			{
				return 111;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '.')
			{
				return 111;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'o')
			{
				return 111;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'O')
			{
				return 111;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '-')
			{
				return 112;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '<')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '>')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '|')
			{
				return 114;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == '_')
			{
				return 114;
			}

			// DOWN DOWN DOWN DOWN DOWN

			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '<')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '>')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '|')
			{
				return 114;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == '_')
			{
				return 114;
			}

			// LEFT LEFT LEFT LEFT LEFT

			if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '<')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '>')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 114;
			}
			else if (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 114;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '<')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '>')
			{
				return 113;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '|')
			{
				return 114;
			}
			else if (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == '_')
			{
				return 114;
			}
		}
		else if (InPortal == 3)    //Chapel EF
		{
			if(whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'W')
			{
				return 121;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'Y')
			{
				return 122;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'S')
			{
				return 123;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'P')
			{
				return 124;
			}
			else
			{
				return 0;
			}
		}
		else if (InPortal == 4)    //Chapel OF
		{
			return 0;
		}
		else if (InPortal == 5)    //Computer Room EF
		{
			if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'P')
			{
				return 131;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'C')
			{
				return 132;
			}
			else if (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'S')
			{
				return 133;
			}
		}
		else if (InPortal == 6)    //Computer Room OF
		{
			return 0;
		}
		else if (InPortal == 7)    //Street EF
		{
			return 0;
		}
		else if (InPortal == 8)    //Street OF
		{
			return 0;
		}
		else if (InPortal == 9)    //Living Room EF
		{
			return 0;
		}
		else if (InPortal == 10)   //Living Room OF
		{
			return 0;
		}
		else if (InPortal == 11)   //Funeral
		{
			return 0;
		}

		else
		{
			return 0;
		}
	}
}

void FstandsforFrustrating(int checkF)
{
	if (Factfeed == 3 && checkF == 9) // Check if user is pressing "F" and then "E" afterwards to enter it.
	{
		if (Areanum == 1)
		{
			if (tempF == 30 && EssentialFragment == 0) // !
			{
				InPortal = 1;
				Areanum = 0;
			}
			else if (tempF == 31 && OptionalFragment == 0) // ?
			{
				InPortal = 2;
				Areanum = 0;
			}
		}
		if (Areanum == 2)
		{
			if (tempF == 30 && EssentialFragment == 1) // !
			{
				InPortal = 3;
				Areanum = 0;
			}
			else if (tempF == 31 && OptionalFragment == 1) // ?
			{
				InPortal = 4;
				Areanum = 0;
			}
		}
		if (Areanum == 3)
		{
			if (tempF == 30 && EssentialFragment == 2) // !
			{
				InPortal = 5;
				Areanum = 0;
			}
			else if (tempF == 31 && OptionalFragment == 2) // ?
			{
				InPortal = 6;
				Areanum = 0;
			}
		}
		if (Areanum == 4)
		{
			if (tempF == 30 && EssentialFragment == 3) // !
			{
				InPortal = 7;
				Areanum = 0;
			}
			else if (tempF == 31 && OptionalFragment == 3) // ?
			{
				InPortal = 8;
				Areanum = 0;
			}
		}
		if (Areanum == 5)
		{
			if (tempF == 30 && EssentialFragment == 4) // !
			{
				InPortal = 9;
				Areanum = 0;
			}
			else if (tempF == 31 && OptionalFragment == 4) // ?
			{
				InPortal = 10;
				Areanum = 0;
			}
		}
		if (Areanum == 6 && EssentialFragment == 5) // !
		{
			InPortal = 11;
			Areanum = 0;
		}
		else
		{
			Factfeed = 404;
		}

		if (InPortal > 0)
		{
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;

			Factfeed = 0;
		}
	}

	if (tempF == 101 && checkF == 9 && reqinteraction == 1)
	{
		inventory = "A flat stone";
	}

	if (Factfeed == 15 && checkF == 9 && reqinteraction <= 4)
	{
		inventory = "A black flat stone";
	}

	if (tempF == 113 && checkF == 9 && reqinteraction == 3)
	{
		InPortal = 12;
		inventory = "A stone filled fish";
	}

	if (inventory == "A flat stone" && tempF == 102 && checkF == 9) // Check if user is pressing "F" and then "E" afterwards to do something.
	{
		levelfinish = 1;
		Factfeed = 911;
		inventory = "none";
	}

	if (inventory == "A black flat stone" && tempF == 113 && checkF == 9)
	{
		reqinteraction++;
		Factfeed = 17;
		inventory = "none";
	}

	if (inventory == "A stone filled fish" && tempF == 112 && checkF == 9)
	{
		levelfinish = 2;
		Factfeed = 913;
		inventory = "none";
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
	else if (checkF == 101 && reqinteraction == 1)
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
		reqinteraction = 1;
	}
	else if (checkF == 104 && levelfinish != 1)
	{
		Factfeed = 14;
	}
	else if (checkF == 104 && levelfinish == 1)
	{
		EssentialFragment = 1;
		reqinteraction = 0;
		Factfeed = 912;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}
	else if (checkF == 111 && InPortal == 2)
	{
		Factfeed = 15;
	}
	else if (checkF == 112)
	{
		Factfeed = 16;
	}
	else if (checkF == 113)
	{
		Factfeed = 17;
	}
	else if (checkF == 114 && levelfinish != 2)
	{
		Factfeed = 18;
	}
	else if (checkF == 114 && levelfinish == 2)
	{
		OptionalFragment = 1;
		reqinteraction = 0;
		Factfeed = 914;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}
	else if (checkF == 121)
	{
		Factfeed = 19;
	}
	else if (checkF == 122)
	{
		Factfeed = 20;
	}
	else if (checkF == 123)
	{
		Factfeed = 21;
	}
	else if (checkF == 124)
	{
		Factfeed = 22;
	}
	else if (checkF == 131)
	{
		Factfeed = 24;
	}
	else if (checkF == 132)
	{
		Factfeed = 25;
	}
	else if (checkF == 133)
	{
		Factfeed = 26;
	}
	else if (checkF == 0)
	{
		Factfeed = 0;

		// clear everything here
	}

	if (Factfeed == 912)
	{
		g_dTime = (g_dElapsedTime + 2.0);
	}

	tempF = checkF;
}