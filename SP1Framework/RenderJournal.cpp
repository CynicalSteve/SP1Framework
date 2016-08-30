#include "RenderJournal.h"

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
extern double g_dElapsedTime;
extern double g_dBounceTime;

COORD c = g_Console.getConsoleSize();
string EFrag = "Essential Fragments";
string OFrag = "Optional Fragments";
string efrag1, efrag2, efrag3, efrag4, efrag5, efrag6 ;
string ofrag1, ofrag2, ofrag3, ofrag4, ofrag5, ofrag6;
//string j1, j2, j3;
ifstream file;

bool JournalMenu = true;
bool FragSelect = false;
int JournalFeed;
char Jpagez[150][150];
//--------------------------------------------------
// To select fragments in journal
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
g_abKeyPressed[A_LEFT] = isKeyPressed(VK_LEFT);
g_abKeyPressed[A_RIGHT] = isKeyPressed(VK_RIGHT);
*/

void readJpage(int input)
{
	std::ifstream Jpage;
	int height = 0;
	int width = 0;

	switch (input)
	{
	case 1:
		Jpage.open("Text files/EssFrag1.txt");
		break;
	}

	if (Jpage.is_open())
	{
		while (height < 23)
		{
			while (width < 109)
			{
				Jpage >> Jpagez[height][width];
				width++;
			}
			width = 0;
			height++;
		}

		Jpage.close();
	}
}

void renderJpage()
{
	COORD c;

	for (int AreaY = 0; AreaY < 23; ++AreaY)
	{
		c.Y = AreaY + 1;

		for (int AreaX = 0; AreaX < 109; ++AreaX)
		{
			if (Jpagez[AreaY][AreaX] == '+')
			{
				Jpagez[AreaY][AreaX] = ' ';
			}

			c.X = (AreaX - 3);

			g_Console.writeToBuffer(c, Jpagez[AreaY][AreaX], 0x07);
		}
	}
}

void ess()
{
	bool SmthHappened = false;

	if (g_abKeyPressed[K_B])
	{
		SmthHappened = true;
		JournalMenu = true;
		FragSelect = false;
	}

	if (g_abKeyPressed[K_INVONE])
	{
		SmthHappened = true;

		if (JournalFeed == 1)
		{
			JournalFeed = 0;
		}
		else
		{
			JournalFeed = 1;
		}
	}

	if (SmthHappened)
	{
		g_dBounceTime = g_dElapsedTime + 0.25;
	}

	if (g_dBounceTime > g_dElapsedTime)
		return;

	readJpage(JournalFeed);

	if (JournalFeed != 0)
	{
		renderJpage();
	}
	else
	{
		c.Y = 3;
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
		g_Console.writeToBuffer(c, "Fragment 6", 0x03);
	}
}

void renJournal()
{
	if (!JournalMenu)
	{
		JournalMenu = false;
		FragSelect = true;
		ess();
	}
	else
	{

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

		if (g_abKeyPressed[K_INVONE])
		{
			FragSelect = true;
			JournalMenu = false;
			ess();
		}
		if (g_abKeyPressed[K_INVTWO] == 1)
		{
			FragSelect = true;
			//opp();
		}
	}
}

/*void Main()
{
	c.X = 3;
	c.Y = 3;

	file.open("Text files/Journal_1.txt");

	while (!file.eof())
	{
		getline(file, j1);
		g_Console.writeToBuffer(c, j1);
		c.Y++;
	}
	file.close();
}*/

//-----------------------------------------------------
// For notes
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