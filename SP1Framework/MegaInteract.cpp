#include "MegaInteract.h"
#include "PlayerInput.h"
extern Console g_Console;
extern SGameChar g_sChar;
extern EGAMESTATES g_eGameState;

extern int Areanum;


int Factfeed = 0;
int InPortal = 0;
int tempF;
int EssentialFragment = 0; // Change this to access certain areas.
int OptionalFragment = 0;  // Change this to access certain areas.
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

			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1])
			{
			case '|':
				return 1;
			case ':':
				return 1;
			case '\\':
				return 1;
			case '/':
				return 1;
			case ',':
				return 1;
			case '"':
				return 1;
			case '-':
				return 1;
			case '`':
				return 1;
			case '_':
				return 1;
			}

			// DOWN DOWN DOWN DOWN DOWN

			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1])
			{
			case '|':
				return 1;
			case ':':
				return 1;
			case '\\':
				return 1;
			case '/':
				return 1;
			case ',':
				return 1;
			case '"':
				return 1;
			case '-':
				return 1;
			case '`':
				return 1;
			case '_':
				return 1;
			}

			// LEFT LEFT LEFT LEFT LEFT

			switch (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y])
			{
			case '|':
				return 1;
			case ':':
				return 1;
			case '\\':
				return 1;
			case '/':
				return 1;
			case ',':
				return 1;
			case '"':
				return 1;
			case '-':
				return 1;
			case '`':
				return 1;
			case '_':
				return 1;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			switch (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y])
			{
			case '|':
				return 1;
			case ':':
				return 1;
			case '\\':
				return 1;
			case '/':
				return 1;
			case ',':
				return 1;
			case '"':
				return 1;
			case '-':
				return 1;
			case '`':
				return 1;
			case '_':
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

			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1])
			{
			case '0':
				return 101;
			case '.':
				return 101;
			case 'o':
				return 101;
			case 'O':
				return 101;
			case '-':
				return 102;
			case '<':
				return 103;
			case '>':
				return 103;
			case '|':
				return 104;
			case '_':
				return 104;
			}

			// DOWN DOWN DOWN DOWN DOWN


			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1])
			{
			case '<':
				return 103;
			case '>':
				return 103;
			case '|':
				return 104;
			case '_':
				return 104;
			}

			// LEFT LEFT LEFT LEFT LEFT

			switch (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y])
			{
			case '<':
				return 103;
			case '>':
				return 103;
			case '|':
				return 104;
			case '_':
				return 104;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			switch (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y])
			{
			case '<':
				return 103;
			case '>':
				return 103;
			case '|':
				return 104;
			case '_':
				return 104;
			}

			return 0;
		}
		else if (InPortal == 2 || InPortal == 12) // Lake OF
		{
			// UP UP UP UP UP

			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1])
			{
			case '0':
				return 111;
			case '.':
				return 111;
			case 'o':
				return 111;
			case 'O':
				return 111;
			case '-':
				return 112;
			case '<':
				return 113;
			case '>':
				return 113;
			case '|':
				return 114;
			case '_':
				return 114;
			}
			// DOWN DOWN DOWN DOWN DOWN

			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1])
			{
			case '<':
				return 113;
			case '>':
				return 113;
			case '|':
				return 114;
			case '_':
				return 114;
			}

			// LEFT LEFT LEFT LEFT LEFT

			switch (whatever[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y])
			{
			case '<':
				return 113;
			case '>':
				return 113;
			case '|':
				return 114;
			case '_':
				return 114;
			}

			// RIGHT RIGHT RIGHT RIGHT RIGHT

			switch (whatever[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y])
			{
			case '<':
				return 113;
			case '>':
				return 113;
			case '|':
				return 114;
			case '_':
				return 114;
			}

			return 0;
		}
		else if (InPortal == 3 || InPortal == 13)    //Chapel EF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'W':
				return 121;
			case 'Y':
				return 122;
			case 'P':
				return 123;
			case 'S':
				return 124;
			}

			return 0;
		}
		else if (InPortal == 4)    //Chapel OF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'W':
				return 126;
			case 'Y':
				return 127;
			case 'P':
				return 123;
			case 'S':
				return 128;
			case 'B':
				return 1251;
			case 'C':
				return 1252;
			case 'D':
				return 1253;
			}

			return 0;
		}
		else if (InPortal == 5 || InPortal == 14)    //Computer Room EF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'P':
				return 131;
			case 'C':
				return 132;
			case 'S':
				return 133;
			}

			return 0;
		}
		else if (InPortal == 6)    //Computer Room OF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'P':
		        return 231;
			case 'C':
				return 232;
			case 'W':
				return 234;
			}
		}
		else if (InPortal == 7)    //Street EF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'S':
				return 141;
			case 'P':
				return 142;
			case 'B':
				return 143;
			}

			return 0;
		}
		else if (InPortal == 8)    //Street OF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'S':
				return 141;
			case 'P':
				return 142;
			case 'B':
				return 151;
			case 'W':
				return 152;
			case 'D':
				return 153;
			}
		}
		else if (InPortal == 9)    //Living Room EF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'W':
				return 161;
			case 'P':
				return 162;
			case 'S':
				return 163;
			}
		}
		else if (InPortal == 10)   //Living Room OF
		{
			switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
			{
			case 'W':
				return 261;
			case 'P':
				return 262;
			case 'S':
				return 263;
			case 'B':
				return 264;
			}
		}
		else if (InPortal == 11 || InPortal == 16 || InPortal == 17)   //Funeral
		{
			if (OptionalFragment < 5)   //Funeral Ending 1 (Bad Ending)
			{
				switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
				{
				case 'B':
					return 171;
				case 'P':
					return 172;
				case 'S':
					return 173;
				}
			}
			else         //Funeral Ending (True ending)
			{
				switch (whatever[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y])
				{
				case 'B':
					return 271;
				case 'P':
					return 272;
				case 'S':
					return 273;
				}
			}
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

	if (Factfeed == 22 && checkF == 9 && reqinteraction == 0)
	{
		InPortal = 13;
		inventory = "Odd black sphere";
		reqinteraction = 1;
	}

	if (Factfeed == 24 && checkF == 9 && inventory == "none")
	{
		InPortal = 14;
		inventory = "A History Book";
		reqinteraction = 1;
	}

	if (tempF == 173 && checkF == 9 && reqinteraction == 1)
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (tempF == 273 && checkF == 9 && reqinteraction == 1)
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (Factfeed == 25 && checkF == 9 && reqinteraction == 1) // LEVEL 5
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (Factfeed == 991 && reqinteraction == 2)
	{
		levelfinish = 5;
		reqinteraction = 0;
		EssentialFragment = 3;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}

	if (Factfeed == 47 && checkF == 9) // LEVEL 6
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (Factfeed == 992 && reqinteraction == 1)
	{
		levelfinish = 6;
		reqinteraction = 0;
		OptionalFragment = 3;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}

	if (Factfeed == 29 && checkF == 9) // LEVEL 7
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (Factfeed == 993 && reqinteraction == 1)
	{
		levelfinish = 7;
		reqinteraction = 0;
		EssentialFragment = 4;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}

	if (Factfeed == 34 && checkF == 9) // LEVEL 9
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (Factfeed == 994 && reqinteraction == 1)
	{
		levelfinish = 9;
		reqinteraction = 0;
		EssentialFragment = 5;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}

	if (Factfeed == 37 && checkF == 9) // LEVEL 10
	{
		Factfeed = 0;
		g_eGameState = S_INPUT;
	}

	if (Factfeed == 995 && reqinteraction == 1)
	{
		levelfinish = 10;
		reqinteraction = 0;
		OptionalFragment = 5;
		g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
	}

	if (Factfeed == 401 && checkF == 9)
	{
		InPortal = 15;
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 107;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 42;
		Factfeed = 402;
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

	if (inventory == "Odd black sphere" && tempF == 121 && checkF == 9)
	{
		reqinteraction = 2;
		Factfeed = 921;
		inventory = "A ring";
	}

	if (inventory == "A ring" && tempF == 124 && checkF == 9)
	{
		levelfinish = 3;
		Factfeed = 922;
		inventory = "none";
	}

	if (inventory == "A History Book" && tempF == 171 && checkF == 9)
	{
		InPortal = 16;
		reqinteraction = 1;
		inventory = "none";
	}

	if (inventory == "A History Book" && tempF == 271 && checkF == 9)
	{
		InPortal = 17;
		reqinteraction = 1;
		inventory = "none";
	}

	if (InPortal == 4)
	{
		if (tempF == 1251 && checkF == 9)
		{
			if (reqinteraction == 0)
			{
				reqinteraction = 1;
			}
			else if (reqinteraction == 3)
			{
				reqinteraction = 4;
			}
			else
			{
				reqinteraction = 0;
			}

			Factfeed = 924;
		}

		if (tempF == 1252 && checkF == 9)
		{
			if (reqinteraction == 1)
			{
				reqinteraction = 2;
			}
			else if (reqinteraction == 4)
			{
				reqinteraction = 5;
			}
			else
			{
				reqinteraction = 0;
			}

			Factfeed = 924;
		}

		if (tempF == 1253 && checkF == 9)
		{
			if (reqinteraction == 2)
			{
				reqinteraction = 3;
			}
			else if (reqinteraction == 5)
			{
				levelfinish = 4;
				reqinteraction = 6;
			}
			else
			{
				reqinteraction = 0;
			}

			Factfeed = 924;
		}
	}

	switch (checkF)
	{
	case 1:
		Factfeed = 1;
		break;
	case 2:
		Factfeed = 2;
		break;
	case 30:
		Factfeed = 3;
		break;
	case 31:
		Factfeed = 3;
		break;
	case 101:
		if (reqinteraction == 1)
		{
			Factfeed = 11;
		}
		break;
	case 102:
		Factfeed = 12;
		break;
	case 103:
		Factfeed = 13;
		reqinteraction = 1;
		break;
	case 104:
		if (levelfinish != 1)
		{
			Factfeed = 14;
		}
		else if (levelfinish == 1)
		{
			EssentialFragment = 1;
			reqinteraction = 0;
			Factfeed = 912;
			g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
		}
		break;
	case 111:
		if (InPortal == 2)
		{
			Factfeed = 15;
		}
		break;
	case 112:
		Factfeed = 16;
		break;
	case 113:
		Factfeed = 17;
		break;
	case 114:
		if (levelfinish != 2)
		{
			Factfeed = 18;
		}
		else if (levelfinish == 2)
		{
			OptionalFragment = 1;
			reqinteraction = 0;
			Factfeed = 914;
			g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
		}
		break;
	case 121:
		Factfeed = 19;
		break;
	case 122:
		Factfeed = 20;
		break;
	case 123:
		Factfeed = 21;
		break;
	case 124: // Podium
		if (levelfinish != 3)
		{
			Factfeed = 22;
		}
		else if (levelfinish == 3)
		{
			EssentialFragment = 2;
			reqinteraction = 0;
			Factfeed = 923;
			g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
		}
		break;
	case 1251: // Button 1
		Factfeed = 23;
		break;
	case 1252: // Button 2
		Factfeed = 23;
		break;
	case 1253: // Button 3
		Factfeed = 23;
		break;
	case 126: // Window OF
		Factfeed = 201; // Unintended jump, but 24+ is already taken.
		break;
	case 127: // Table OF
		if (levelfinish != 4)
		{
			Factfeed = 202; // Unintended jump, but 24+ is already taken.
		}
		else if (levelfinish == 4)
		{
			OptionalFragment = 2;
			reqinteraction = 0;
			Factfeed = 926;
			g_dElapsedTimeTemp = (g_dElapsedTime + 10.0);
		}
		break;
	case 128: // Podium OF
		Factfeed = 203;  // Unintended jump, but 24+ is already taken.
		break;
	case 131: // Bookshelf
		Factfeed = 24;
		break;
	case 132: // Computer
		if (EssentialFragment != 3)
		{
			Factfeed = 25;
		}
		break;
	case 133: // Map
		Factfeed = 26;
		break;
	case 141:
		Factfeed = 27;
		break;
	case 142:
		Factfeed = 28;
		break;
	case 143:
		if (EssentialFragment != 4)
		{
			Factfeed = 29;
		}	
		break;
	case 151:
		Factfeed = 31;
		break;
	case 152:
		Factfeed = 32;
		break;
	case 153:
		Factfeed = 401;  // Unintended jump, but 33+ is already taken.
		break;
	case 161:
		Factfeed = 33;
		break;
	case 162:
		if (EssentialFragment != 5)
		{
			Factfeed = 34;
		}
		break;
	case 163:
		Factfeed = 35;
		break;
	case 261:
		Factfeed = 36;
		break;
	case 262:
		if (OptionalFragment != 5)
		{
			Factfeed = 37;
		}
		break;
	case 263:
		Factfeed = 38;
		break;
	case 264:
		Factfeed = 39;
		break;
	case 171:
		Factfeed = 40;
		break;
	case 172:
		Factfeed = 41;
		break;
	case 173:
		Factfeed = 42;
		break;
	case 271:
		Factfeed = 43;
		break;
	case 272:
		Factfeed = 44;
		break;
	case 273:
		Factfeed = 45;
		break;
	case 231:
		Factfeed = 46;
		break;
	case 232:
		if (OptionalFragment != 3)
		{
			Factfeed = 47;
		}
		break;
	case 234:
		Factfeed = 49;
		break;
	case 0:
		Factfeed = 0;
		break;
	}
	if (Factfeed == 912 || Factfeed == 914 || Factfeed == 923 || Factfeed == 926 || Factfeed == 991 || Factfeed == 992 || Factfeed == 993 || Factfeed == 994 || Factfeed == 996)
	{
		g_dTime = (g_dElapsedTime + 2.0);
	}

	tempF = checkF;
}