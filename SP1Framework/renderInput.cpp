#include "renderInput.h"

extern Console g_Console;

using namespace std;

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
	COORD c;
	c.Y = 5;
	c.X = 13;

	g_Console.writeToBuffer(c, checkI, 0x02);
}