#include "renderInput.h"

extern Console g_Console;

void renderInput(void)
{
	COORD c;
	string display;
	string temp; // Added this line

	ifstream file;
	file.open("test_text.txt");

	while (!file.eof())
	{
		getline(file, temp);
		display.append(temp); // Added this line
	}

	g_Console.writeToBuffer(c, display, 0x02);

	file.close();
}