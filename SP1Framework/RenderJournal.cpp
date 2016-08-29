#include "RenderJournal.h"

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
COORD c = g_Console.getConsoleSize();
string EFrag = "Essential Fragments";
string OFrag = "Optional Fragments";
string efrag1, efrag2, efrag3, efrag4, efrag5, efrag6 ;
string ofrag1, ofrag2, ofrag3, ofrag4, ofrag5, ofrag6;
ifstream file;
bool toview = false;
//--------------------------------------------------
// To select fragments in journal

void buttons()
{
	getInput();
}

//--------------------------------------------------
// Notes for buttons
/*
g_abKeyPressed[K_INVONE] = isKeyPressed(0x31);
g_abKeyPressed[K_INVTWO] = isKeyPressed(0x32);
g_abKeyPressed[K_INVTHREE] = isKeyPressed(0x33);
g_abKeyPressed[K_INVFOUR] = isKeyPressed(0x34);
g_abKeyPressed[K_INVFIVE] = isKeyPressed(0x35);
g_abKeyPressed[K_INVSIX] = isKeyPressed(0x36);
g_abKeyPressed[K_INVSEVEN] = isKeyPressed(0x37);
g_abKeyPressed[K_INVEIGHT] = isKeyPressed(0x38);
g_abKeyPressed[K_INVNINE] = isKeyPressed(0x39);
g_abKeyPressed[K_INVZERO] = isKeyPressed(0x30);
*/

/*void thingy(char input)
{
	switch (input)
	{
	case '1':
			c.X = 3;
			c.Y = 3;

			file.open("Text files/EssFrag1.txt");

			while (!file.eof())
			{
				getline(file, efrag1);
				g_Console.writeToBuffer(c, efrag1);
				c.Y++;
			}
			file.close();
			break;
	case '2':
		c.X = 3;
		c.Y = 3;

		file.open("Text files/EssFrag2.txt");

		while (!file.eof())
		{
			getline(file, efrag2);
			g_Console.writeToBuffer(c, efrag2);
			c.Y++;
		}
		file.close();
		break;
	case '3':
		c.X = 3;
		c.Y = 3;

		file.open("Text files/EssFrag3.txt");

		while (!file.eof())
		{
			getline(file, efrag3);
			g_Console.writeToBuffer(c, efrag3);
			c.Y++;
		}
		file.close();
		break;
	case '4':
		c.X = 3;
		c.Y = 3;

		file.open("Text files/EssFrag4.txt");

		while (!file.eof())
		{
			getline(file, efrag4);
			g_Console.writeToBuffer(c, efrag4);
			c.Y++;
		}
		file.close();
		break;
	case '5':
		c.X = 3;
		c.Y = 3;

		file.open("Text files/EssFrag5_1.txt");

		while (!file.eof())
		{
			getline(file, efrag5);
			g_Console.writeToBuffer(c, efrag5);
			c.Y++;
		}
		file.close();

		if (g_abKeyPressed[K_ENTER])
		{
			file.open("Text files/EssFrag5_2.txt");

			while (!file.eof())
			{
				getline(file, efrag5);
				g_Console.writeToBuffer(c, efrag5);
				c.Y++;
			}
			file.close();
		}
		break;
	case '6':
		c.X = 3;
		c.Y = 3;

		file.open("Text files/EssFrag6_1_1.txt");

		while (!file.eof())
		{
			getline(file, efrag6);
			g_Console.writeToBuffer(c, efrag6);
			c.Y++;
		}
		file.close();

		if (g_abKeyPressed[K_ENTER])
		{
			file.open("Text files/EssFrag6_1_2.txt");

			while (!file.eof())
			{
				getline(file, efrag6);
				g_Console.writeToBuffer(c, efrag6);
				c.Y++;
			}
			file.close();
		}
		break;
	}
}*/

void ess()
{
	/*c.Y = 3;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, EFrag, 0x03);

	c.Y = 5;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 1", 0x03);

	c.Y = 7;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 2", 0x03);

	c.Y = 9;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 3", 0x03);

	c.Y = 11;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 4", 0x03);

	c.Y = 13;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 5", 0x03);

	c.Y = 15;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 6", 0x03);*/
}

void renJournal()
{
	bool pressed = false;

	c.Y = 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Journal", 0x03);
	
	c.Y = 4;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, EFrag, 0x03);

	c.Y = 6;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, OFrag, 0x03);

	c.Y = 8;
	c.X = g_Console.getConsoleSize().X / 2 - 50;
	g_Console.writeToBuffer(c, "Press on the number allocated to each fragment to access the memory.", 0x03);

	if (isKeyPressed(0x45))
		ess();
	/*if (g_abKeyPressed[K_INVTWO] == 1)
	{
		c.X = 3;
		c.Y = 3;

		file.open("Text files/EssFrag2.txt");

		while (!file.eof())
		{
			getline(file, efrag2);
			g_Console.writeToBuffer(c, efrag2);
			c.Y++;
		}
		file.close();
	}

	if (g_abKeyPressed[K_INVTHREE] == 1)
	{
		c.X = 3;
		c.Y = 3;
		file.open("Text files/EssFrag3.txt");

		while (!file.eof())
		{
			getline(file, efrag3);
			g_Console.writeToBuffer(c, efrag3);
			c.Y++;
		}
		file.close();
	}

	if (g_abKeyPressed[K_INVFOUR] == 1)
	{
		c.X = 3;
		c.Y = 3;
		file.open("Text files/EssFrag4.txt");

		while (!file.eof())
		{
			getline(file, efrag4);
			g_Console.writeToBuffer(c, efrag4);
			c.Y++;
		}
		file.close();
	}

	if (g_abKeyPressed[K_INVFIVE] == 1)
	{
		c.X = 3;
		c.Y = 3;
		file.open("Text files/EssFrag5.txt");

		while (!file.eof())
		{
			getline(file, efrag5);
			g_Console.writeToBuffer(c, efrag5);
			c.Y++;
		}
		file.close();
	}

	if (g_abKeyPressed[K_INVSIX] == 1)
	{
		c.X = 3;
		c.Y = 3;
		file.open("Text files/EssFrag6.txt");

		while (!file.eof())
		{
			getline(file, efrag6);
			g_Console.writeToBuffer(c, efrag6);
			c.Y++;
		}
		file.close();
	}
	
	//if ()
	/*c.X = 1;
	c.Y = 1;
	
	string fragments;
	ifstream file;
	file.open("Text files/EssFrag2.txt");
	
	while (!file.eof())
	{
		getline(file, fragments);
		g_Console.writeToBuffer(c, fragments);
		c.Y++;
	}
	file.close();

	c.X = 1;
	c.Y = 1;
	
	string fragments;
	ifstream file;
	file.open("Text files/EssFrag3.txt");
	
	while (!file.eof())
	{
		getline(file, fragments);
		g_Console.writeToBuffer(c, fragments);
		c.Y++;
	}
	file.close();

	c.X = 1;
	c.Y = 1;
	
	string fragments;
	ifstream file;
	file.open("Text files/EssFrag4.txt");
	
	while (!file.eof())
	{
		getline(file, fragments);
		g_Console.writeToBuffer(c, fragments);
		c.Y++;
	}
	file.close();*/
}