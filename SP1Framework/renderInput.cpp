#include "renderInput.h"

extern Console g_Console;

void renderInput(void)
{
	COORD c;
	c.Y = 1;
	c.X = 0;
	string display;
	display = "Kappa.";
	/* string temp; // Added this line

	ifstream file;
	file.open("1_Lake.txt");

	while (!file.eof())
	{
		getline(file, temp);
		display.append(temp); // Added this line
	} */

	g_Console.writeToBuffer(c, display, 0x02);

	// file.close();
}