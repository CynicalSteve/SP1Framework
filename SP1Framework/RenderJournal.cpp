#include "RenderJournal.h"

extern Console g_Console;
extern bool g_abKeyPressed[K_COUNT];
extern double g_dElapsedTime;
extern double g_dBounceTime;

COORD c = g_Console.getConsoleSize();

bool JournalMenu = true;
bool FragSelect;
int JournalFeed;
char Jpagez[150][150];
bool smthhappened = false;

/*string journal, efrag, ofrag;
ifstream file;
int toview = 0;*/

//--------------------------------------------------
// To select fragments in journal

void readJpage(int input)
{
	std::ifstream Fpage;
	int height = 0;
	int width = 0;

	switch (input)
	{
	case 0:
		Fpage.open("Text files/EssFragNone.txt");
		break;
	case 1:
		Fpage.open("Text files/EssFrag1.txt");
		break;
	case 2:
		Fpage.open("Text files/EssFrag2.txt");
		break;
	case 3:
		Fpage.open("Text files/EssFrag3.txt");
		break;
	case 4:
		Fpage.open("Text files/EssFrag4.txt");
		break;
	case 5:
		Fpage.open("Text files/EssFrag5_1.txt");
		break;
	case 6:
		Fpage.open("Text files/EssFrag6_1_1.txt");
		break;
	}

	if (Fpage.is_open())
	{
		while (height < 40)
		{
			while (width < 109)
			{
				Fpage >> Jpagez[height][width];
				width++;
			}
			width = 0;
			height++;
		}

		Fpage.close();
	}
}

void readOpage(int input)
{
	std::ifstream Opage;
	int height = 0;
	int width = 0;

	switch (input)
	{
	case 0:
		Opage.open("Text files/EssFragNone.txt");
		break;
	case 1:
		Opage.open("Text files/OppFrag1.txt");
		break;
	case 2:
		Opage.open("Text files/OppFrag2.txt");
		break;
	case 3:
		Opage.open("Text files/OppFrag3.txt");
		break;
	case 4:
		Opage.open("Text files/OppFrag4.txt");
		break;
	case 5:
		Opage.open("Text files/OppFrag5.txt");
		break;
	case 6:
		Opage.open("Text files/OppFrag6_2_1.txt");
		break;
	}

	if (Opage.is_open())
	{
		while (height < 40)
		{
			while (width < 109)
			{
				Opage >> Jpagez[height][width];
				width++;
			}
			width = 0;
			height++;
		}

		Opage.close();
	}
}

void renderJpage()
{
	COORD c;

	for (int AreaY = 0; AreaY < 40; ++AreaY)
	{
		c.Y = AreaY + 2;

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


void ef()
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

	if (g_abKeyPressed[K_INVFIVE])
	{
		smthhappened = true;
		JournalFeed = 5;
	}

	if (g_abKeyPressed[K_INVSIX])
	{
		smthhappened = true;
		JournalFeed = 6;
	}

	if (JournalFeed != 0)
	{
		renderJpage();
	}
	else
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

		c.Y = 18;
		c.X = g_Console.getConsoleSize().X / 2 - 24;
		g_Console.writeToBuffer(c, "Press 'b' to go back.");
	}

	if (g_dElapsedTime > g_dBounceTime)
	{
		readJpage(JournalFeed);
	}
}

void of()
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
		JournalFeed = 7;
	}

	if (g_abKeyPressed[K_INVTWO])
	{
		smthhappened = true;
		JournalFeed = 8;
	}

	if (g_abKeyPressed[K_INVTHREE])
	{
		smthhappened = true;
		JournalFeed = 9;
	}

	if (g_abKeyPressed[K_INVFOUR])
	{
		smthhappened = true;
		JournalFeed = 10;
	}

	if (g_abKeyPressed[K_INVFIVE])
	{
		smthhappened = true;
		JournalFeed = 11;
	}

	if (g_abKeyPressed[K_INVSIX])
	{
		smthhappened = true;
		JournalFeed = 12;
	}

	if (JournalFeed != 0)
	{
		renderJpage();
	}
	else
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

		c.Y = 18;
		c.X = g_Console.getConsoleSize().X / 2 - 24;
		g_Console.writeToBuffer(c, "Press 'b' to go back.");
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

	if (JournalMenu == false)
	{
		if (FragSelect == true)
		{
			ef();
		}
		else if (FragSelect == false)
		{
			of();
		}
	}
	else
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


		if (g_abKeyPressed[K_INVONE])
		{
			smthhappened = true;
			FragSelect = true;
			JournalMenu = false;
		}
		if (g_abKeyPressed[K_INVTWO])
		{
			smthhappened = true;
			FragSelect = false;
			JournalMenu = false;
		}
	}
}

/*void Main()
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

void EF()
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

	c.Y = 18;
	c.X = g_Console.getConsoleSize().X / 2 - 24;
	g_Console.writeToBuffer(c, "Press 'b' to go back.");
}

void OF()
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

	c.Y = 18;
	c.X = g_Console.getConsoleSize().X / 2 - 24;
	g_Console.writeToBuffer(c, "Press 'b' to go back.");
}

void OpenEF()
{
	c.X = 1;
	c.Y = 2;

	file.open("Text files/EF1.txt");
	while (getline(file, efrag))
	{
		g_Console.writeToBuffer(c, efrag);
		c.Y++;
	}
	file.close();
}

void forJournal()
{
	bool bSomethingHappened = false;

	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_INVONE] == true && toview == 1)
	{
		toview = 3;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_INVONE] == true && toview == 0)
	{
		toview = 1;
		bSomethingHappened = true;
	}
	if (g_abKeyPressed[K_INVTWO])
	{
		if (toview == 0)
			toview = 2;
	}
	if (g_abKeyPressed[K_B])
	{
		if (toview == 1)
			toview = 0;
		if (toview == 3)
			toview = 1;
		bSomethingHappened = true;
	}

	if (toview == 1)
	{
		EF();
	}
	if (toview == 2)
	{
		OF();
	}
	if (toview == 3)
	{
		OpenEF();
	}
	if (toview == 0)
	{
		Main();
	}
	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.25;
	}
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