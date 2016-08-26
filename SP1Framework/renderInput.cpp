#include "renderInput.h"

using namespace std;

extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern int Factfeed;
extern int reqinteraction;

string temp;

void renderInputScreen()
{
	COORD c;
	c.Y = 1;
	c.X = 0;

	ifstream read("Text files/3_Display.txt");
	string str, str1;

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
		if (temp == "merlion")
		{
			reqinteraction = 2;
			Factfeed = 991;
			FstandsforFrustrating(9);
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