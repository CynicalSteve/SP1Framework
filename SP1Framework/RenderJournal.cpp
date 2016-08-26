#include "RenderJournal.h"

extern Console g_Console;
extern bool    g_abKeyPressed[K_COUNT];
string frag1, frag2, frag3, frag4, frag5, frag6 ;
ifstream file;

//--------------------------------------------------
// To select fragments in journal

void buttons()
{
	getInput();
}

//--------------------------------------------------
// Notes for buttons
/*	g_abKeyPressed[K_INVONE]    = isKeyPressed(0x31);
	g_abKeyPressed[K_INVTWO]    = isKeyPressed(0x32);
	g_abKeyPressed[K_INVTHREE]  = isKeyPressed(0x33);
	g_abKeyPressed[K_INVFOUR]   = isKeyPressed(0x34);
	g_abKeyPressed[K_INVFIVE]   = isKeyPressed(0x35);
	g_abKeyPressed[K_INVSIX]    = isKeyPressed(0x36);
	g_abKeyPressed[K_INVSEVEN]  = isKeyPressed(0x37);
	g_abKeyPressed[K_INVEIGHT]  = isKeyPressed(0x38);
	g_abKeyPressed[K_INVNINE]   = isKeyPressed(0x39);
	g_abKeyPressed[K_INVZERO]   = isKeyPressed(0x30);*/

void renJournal()
{
	COORD c = g_Console.getConsoleSize();
	
	c.Y = 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Journal", 0x03);

	c.Y = 3;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 1", 0x03);

	c.Y = 4;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 2", 0x03);

	/*c.Y = 5;
	c.X = 1;
	c.Y /= 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 3", 0x03);

	c.Y = 6;
	c.X = 1;
	c.Y /= 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 4", 0x03);

	c.Y = 7;
	c.X = 1;
	c.Y /= 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 5", 0x03);

	c.Y = 8;
	c.X = 1;
	c.Y /= 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 6", 0x03);*/

	c.Y = 6;
	c.X = g_Console.getConsoleSize().X / 2 - 50;
	g_Console.writeToBuffer(c, "Press on the number allocated to each fragment to access the memory.", 0x03);

	/*c.Y = 1;
	c.X = 1;
	c.Y /= 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Journal", 0x03);

	c.Y = 1;
	c.X = 1;
	c.Y /= 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Journal", 0x03);*/

	switch (g_abKeyPressed[K_COUNT])
	{
		case '1':
			g_abKeyPressed[K_INVONE] ==  1;

			file.open("Text files/EssFrag1.txt");
				getline(file, frag1);
				g_Console.writeToBuffer(c, frag1);
				c.Y++;
			break;

		case '2':
			g_abKeyPressed[K_INVTWO] == 1;
			
			file.open("Text files/EssFrag2.txt");

			while (!file.eof())
			{
				getline(file, frag2);
				g_Console.writeToBuffer(c, frag2);
				c.Y++;
			}
	}

		/*if (g_abKeyPressed[K_INVONE] == 1)
		{
			c.X = 3;
			c.Y = 3;

			file.open("Text files/EssFrag1.txt");

			while (!file.eof())
			{
				getline(file, fragments);
				g_Console.writeToBuffer(c, fragments);
				c.Y++;
			}
			file.close();
		}

		if (g_abKeyPressed[K_INVTWO] == 1)
		{
			c.X = 3;
			c.Y = 3;

			file.open("Text files/EssFrag2.txt");

			while (!file.eof())
			{
				getline(file, frag2);
				g_Console.writeToBuffer(c, frag2);
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
				getline(file, frag3);
				g_Console.writeToBuffer(c, frag3);
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
				getline(file, frag4);
				g_Console.writeToBuffer(c, frag4);
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
				getline(file, frag5);
				g_Console.writeToBuffer(c, frag5);
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
				getline(file, frag6);
				g_Console.writeToBuffer(c, frag6);
				c.Y++;
			}
			file.close();
		}*/
	
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

	//Ed's Method
	/*COORD c;
	c.Y = 1;
	c.X = 0;

	ifstream read("Text files/EssFrag1.txt");
	string frag, frag1;

	int index = 0;
	if (read.is_open())
	{
	getline(read, frag);
	while (read)
	{
	frag1 += frag;
	getline(read, frag);
	}
	read.close();
	}

	g_Console.writeToBuffer(c, frag1, 0x08);*/
}