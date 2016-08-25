#include "RenderJournal.h"

extern Console g_Console;
extern SGameChar g_sChar;

void renJournal()
{
	COORD c;
	c.X = 1;
	c.Y = 1;
	string str;
	ifstream file;
	file.open("Text files/EssFrag1.txt");
	//for (int i = 0; i < 18; i++)
	while (!file.eof())
	{
		getline(file, str);
		g_Console.writeToBuffer(c, str);
		c.Y++;
	}
	file.close();
}