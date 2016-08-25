#include "RenderJournal.h"

extern Console g_Console;

void renJournal()
{
	
	COORD c;
	c.X = 1;
	c.Y = 1;
	string fragments;
	ifstream file;
	file.open("\Text files//EssFrag1.txt");
	//for (int i = 0; i < 18; i++)
	while (!file.eof())
	{
		getline(file, fragments);
		g_Console.writeToBuffer(c, fragments);
		c.Y++;
	}
	file.close();
}