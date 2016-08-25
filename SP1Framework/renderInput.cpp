#include "renderInput.h"

extern Console g_Console;

void renderInput(void)
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