#include "RenderJournal.h"

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
extern double g_dElapsedTime;
extern double g_dBounceTime;

COORD c = g_Console.getConsoleSize();
string journal, efrag, ofrag;
int toview = 0;
ifstream file;

bool JournalMenu = true;
bool FragSelect = false;
int JournalFeed;
char Jpagez[150][150];
bool smthhappened = false;
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

//-------------------------------------------------
// Edward's Code

/*void readJpage(int input)
{
	std::ifstream Jpage;
	int height = 0;
	int width = 0;

	switch (input)
	{
	case 0:
		Jpage.open("Text files/EssFragNone.txt");
		break;
	case 1:
		Jpage.open("Text files/EssFrag1.txt");
		break;
	case 2:
		Jpage.open("Text files/EssFrag2.txt");
		break;
	case 3:
		Jpage.open("Text files/EssFrag3.txt");
		break;
	case 4:
		Jpage.open("Text files/EssFrag4.txt");
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
	if (g_abKeyPressed[K_B])
	{
		smthhappened = true;

		if (JournalFeed == 0)
		{
			JournalMenu = true;
			FragSelect = false;
		}
		else
		{
			JournalFeed = 0;
		}
	}

	if (g_abKeyPressed[K_INVONE])
	{
		smthhappened = true;
		JournalFeed = 1;
	}

	if (g_abKeyPressed[K_INVTWO])
	{
		smthhappened = true;
		JournalFeed = 2;
	}

	if (g_abKeyPressed[K_INVTHREE])
	{
		smthhappened = true;
		JournalFeed = 3;
	}

	if (g_abKeyPressed[K_INVFOUR])
	{
		smthhappened = true;
		JournalFeed = 4;
	}

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

	if (g_dElapsedTime > g_dBounceTime)
	{
		readJpage(JournalFeed);
	}
}

void renJournal()
{
	if (smthhappened)
	{
		g_dBounceTime = g_dElapsedTime + 0.25;
		smthhappened = false;
	}

	if (g_dBounceTime > g_dElapsedTime)
		return;

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
			smthhappened = true;
			FragSelect = true;
			JournalMenu = false;
		}
		if (g_abKeyPressed[K_INVTWO] == 1)
		{
			smthhappened = true;
			FragSelect = true;
			//opp();
		}
	}
}*/

void Main()
{
	c.Y = 1;
	c.X = g_Console.getConsoleSize().X / 2 - 15;
	g_Console.writeToBuffer(c, "Journal");

	c.Y = 4;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Essential Fragments");

	c.Y = 6;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Optional Fragments");

	c.Y = 9;
	c.X = g_Console.getConsoleSize().X / 2 - 30;
	g_Console.writeToBuffer(c, "Press '1' to activate 'Essential Fragments'.");

	c.Y = 10;
	c.X = g_Console.getConsoleSize().X / 2 - 30;
	g_Console.writeToBuffer(c, "Press '2' to activate 'Optional Fragments'.");
}

void EssF()
{
	c.Y = 1;
	c.X = g_Console.getConsoleSize().X / 2 - 24;
	g_Console.writeToBuffer(c, "Essential Fragments");

	c.Y = 4;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 1");

	c.Y = 6;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 2");

	c.Y = 8;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 3");

	c.Y = 10;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 4");

	c.Y = 12;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 5");

	c.Y = 14;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 6");

	c.Y = 17;
	c.X = g_Console.getConsoleSize().X / 2 - 45;
	g_Console.writeToBuffer(c, "Press the number indicated to a fragment to activate a memory.");
}

void OptF()
{
	c.Y = 1;
	c.X = g_Console.getConsoleSize().X / 2 - 24;
	g_Console.writeToBuffer(c, "Optional Fragments");

	c.Y = 4;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 1");

	c.Y = 6;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 2");

	c.Y = 8;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 3");

	c.Y = 10;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 4");

	c.Y = 12;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 5");

	c.Y = 14;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Fragment 6");

	c.Y = 17;
	c.X = g_Console.getConsoleSize().X / 2 - 45;
	g_Console.writeToBuffer(c, "Press the number indicated to a fragment to activate a memory.");
}

void forJournal()
{
	if (g_abKeyPressed[K_INVONE])
	{
		toview = 1;

		if (toview == 1)
		{
			EssF();
		}
	}
	else
	{
		Main();
	}
}

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