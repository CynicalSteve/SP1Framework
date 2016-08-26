#include "renderInput.h"

using namespace std;

extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern int Factfeed;
extern int reqinteraction;
extern int InPortal;
extern string Sentence;

string temp;

void renderInputScreen()
{
	COORD c;
	c.Y = 1;
	c.X = 0;

	string str, str1;

	ifstream read;
	
	switch (InPortal)
	{
	case 14:
		read.open("Text files/3_Display.txt");
		break;
	case 6:
		read.open("Text files/3_DisplayOptional.txt");
		break;
	case 7:
		read.open("Text files/4_Display.txt");
		break;
	case 9:
		read.open("Text files/5_Display.txt");
		break;
	case 10:
		read.open("Text files/5_DisplayOptional.txt");
		break;
	case 16:
		read.open("Text files/6_Display.txt");
		break;
	case 17:
		read.open("Text files/6_DisplayTrueEnd.txt");
		break;
	default:
		break;
	}

	int index = 0;
	if (read.is_open())
	{
		getline(read, str);
		while (read)
		{
			str1 += str;
			getline(read, str);
		}

		read.close();
	}

	g_Console.writeToBuffer(c, str1, 0x08);
}

void renderTyping(string checkI)
{
	if (checkI == " ")
	{
		if (temp == "merlion" && InPortal == 14)
		{
			reqinteraction = 2;
			Factfeed = 991;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else if (temp == "sorry" && InPortal == 6)
		{
			reqinteraction = 1;
			Factfeed = 992;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else if (temp == "happy" && InPortal == 7)
		{
			reqinteraction = 1;
			Factfeed = 993;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else if (temp == "134" && InPortal == 9)
		{
			reqinteraction = 1;
			Factfeed = 994;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else if (temp == "76736582" && InPortal == 10)
		{
			reqinteraction = 1;
			Factfeed = 995;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else if (temp == "impenitence" && InPortal == 16)
		{
			reqinteraction = 2;
			Factfeed = 996;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else if (temp == "repentance" && InPortal == 17)
		{
			reqinteraction = 2;
			Factfeed = 997;
			FstandsforFrustrating(9);
			Sentence = "";
			g_eGameState = S_GAME;
		}
		else
		{
			checkI = "";
		}
	}

	temp = checkI;

	COORD c;
	c.Y = 5;
	c.X = 13;

	g_Console.writeToBuffer(c, temp, 0x02);
}