#include "ActFeed.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern std::string inventory;
extern int Factfeed;
extern double g_dElapsedTime;
extern double g_dElapsedTimeTemp;
extern double g_dTime;
extern int InPortal;
extern int Areanum;
extern int levelfinish;
extern int EssentialFragment;
extern int reqinteraction;

void actfeed()
{
	int tempcoords;            // Used to hold the value of c.Y in activity feed

	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 31;

	if (Areanum == 1 && EssentialFragment == 0)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "\"Wha-What is this place?\"", 0x02);
		c.Y += 1;

		if (g_dElapsedTime > 5.0) // wait for 5 seconds to display next message
		{
			g_Console.writeToBuffer(c, "I looked about confused and wide-eyed.", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 7.0) // wait for 7 seconds to display next message
		{
			g_Console.writeToBuffer(c, "A verdant grassy plain laid out before me while the sea behind me rolled and crashed into the shores of the", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 7.0) // wait for 7 seconds to display next message
		{
			g_Console.writeToBuffer(c, "beach I was standing in.", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 11.0) // wait for 11 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Trees which bordered the plains crackled as a cold breeze blew across the island. Seagulls overhead screamed", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 11.0) // wait for 11 seconds to display next message
		{
			g_Console.writeToBuffer(c, "in response.", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 15.0) // wait for 15 seconds to display next message
		{
			g_Console.writeToBuffer(c, "", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 15.0) // wait for 15 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Despite so much looking around, my surroundings didn't provide a single clue as to where I am or how I got", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 15.0) // wait for 15 seconds to display next message
			g_Console.writeToBuffer(c, "here... or who I was.", 0x02);
		c.Y += 1;
		if (g_dElapsedTime > 19.0) // wait for 19 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Wait a minute, I think I got something...", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 21.0) // wait for 21 seconds to display next message
		{
			g_Console.writeToBuffer(c, "A...Av...Ava? Ava...Laurens?", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 23.0) // wait for 23 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Is that my name?", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 25.0) // wait for 25 seconds to display next message
		{
			g_Console.writeToBuffer(c, "\"Ava Laurens.\" The name sounds much clearer now, it has to be mine.", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 28.0) // wait for 28 seconds to display next message
		{
			g_Console.writeToBuffer(c, "I should take a look around, since being a sitting duck here would do me no good.", 0x02);
			c.Y += 1;
		}
		if (g_dElapsedTime > 30.0) // wait for 30 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Use WASD keys to move around, F key to interact and E to enter/use.", 0x05);
			c.Y += 1;
		}
	}

	if (InPortal == 1)
	{
		c.Y = 31;

		if (inventory == "A flat stone")
		{
			g_Console.writeToBuffer(c, "Flat Stone has been added to your inventory.", 0x03);
			c.Y++;
		}
	}

	if (InPortal == 2 || InPortal == 12)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "No matter how strong one is, with too heavy a burden they will     .", 0x06);
		c.X += 63;
		g_Console.writeToBuffer(c, "sink", 0x05);
		c.Y++;

		c.X = 0;

		if (inventory == "a stone filled fish")
		{
			g_Console.writeToBuffer(c, "A stone filled fish has been added to your inventory.", 0x03);
		}

		if (levelfinish == 2)
		{
			g_Console.writeToBuffer(c, "\"Easy, isn't it? After all, you've had a lot of practice...\".", 0x06);
		}
	}

	if (Factfeed == 912)
	{
		c.Y = 31;
		g_Console.writeToBuffer(c, "\"First, you get the flattest rock you can find like this one,\" he said, brandishing the stone he just", 0x03);
		c.Y++; //32
		g_Console.writeToBuffer(c, "picked up from the ground.", 0x03);
		c.Y++; //33
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Next, you aim it at an angle like so...\", he continued, \"while adding a little spin to it, you throw", 0x03);
			c.Y++; //34
			g_Console.writeToBuffer(c, "as hard as you can.\"", 0x03);
			c.Y++; //35
		}
		if (g_dElapsedTime > (g_dTime + 3.0))
		{
			g_Console.writeToBuffer(c, "At the last word of his sentence, he hurled the stone towards the lake.", 0x03);
			c.Y++; //36
		}
		if (g_dElapsedTime > (g_dTime + 5.0))
		{
			g_Console.writeToBuffer(c, "It skipped five times across the surface of the water before plopping into the depths below.", 0x03);
			c.Y += 2; //38
		}
		if (g_dElapsedTime > (g_dTime + 8.0))
		{
			g_Console.writeToBuffer(c, "\"Now you try it,\" he said with a proud look on his face.", 0x03);
			c.Y++; //39
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "I wrinkled my nose at him, before grabbing a stone from the ground and tossed it at the lake.", 0x03);
			c.Y++; //40
		}
		if (g_dElapsedTime > (g_dTime + 14.0))
		{
			g_Console.writeToBuffer(c, "It skipped eight times on the surface before sinking.", 0x03);
			c.Y += 2; //42
		}
		if (g_dElapsedTime > (g_dTime + 16.0))
		{
			g_Console.writeToBuffer(c, "He stared at me in disbelief, \"Damn Ava, nice throw!\"", 0x03);
			c.Y++; //43
		}
		if (g_dElapsedTime > (g_dTime + 18.0))
		{
			g_Console.writeToBuffer(c, "\"Or maybe you're just bad at it,\" I snorted.", 0x03);
			c.Y++; //44
		}
		if (g_dElapsedTime > (g_dTime + 20.0))
		{
			g_Console.writeToBuffer(c, "His eyes twinkled mysteriously.", 0x03);
			c.Y++; //45
		}
		if (g_dElapsedTime > (g_dTime + 21.0))
		{
			g_Console.writeToBuffer(c, "\"Oh yeah? I'll show you something I'm good at!\"", 0x03);
			c.Y++; //46
		}
		if (g_dElapsedTime > (g_dTime + 23.0))
		{
			g_Console.writeToBuffer(c, "He raced towards me and slung me over his shoulder. He then ran towards the treeline with us both,", 0x03);
			c.Y++; //47
		}
		if (g_dElapsedTime > (g_dTime + 23.0))
		{
			g_Console.writeToBuffer(c, "laughing the whole time.", 0x03);
			c.Y += 2; //49
		}
		if (g_dElapsedTime > (g_dTime + 27.0))
		{
			g_Console.writeToBuffer(c, "Startled, I jumped backwards.", 0x02);
			c.Y++; //50
		}
		if (g_dElapsedTime > (g_dTime + 28.0))
		{
			g_Console.writeToBuffer(c, "\"What in the world was that?\"", 0x02);
			c.Y++; //51
		}
		if (g_dElapsedTime > (g_dTime + 29.0))
		{
			g_Console.writeToBuffer(c, "That man seemed so familiar, as if I've known him for all my life.", 0x02);
			c.Y++; //52
		}
		if (g_dElapsedTime > (g_dTime + 31.0))
		{
			g_Console.writeToBuffer(c, "Perhaps that was some kind of memory? If I enter more of those portals, will I get my memory back?", 0x02);
			c.Y++; //53
		}
		if (g_dElapsedTime > (g_dTime + 34.0))
		{
			g_Console.writeToBuffer(c, "I guess I better find out.", 0x02);
		}
	}

	/* Template for MX
	if (c.Y == 54)
	{
	c.Y = 31;
	}
	if (g_dElapsedTime > 9.0)
	{
	g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
	g_Console.writeToBuffer(c, "Name", 0x04);
	c.Y += 1;
	}
	*/


	if (Factfeed > 0)
	{
		tempcoords = c.Y;
		c.Y = 24;

		switch (Factfeed)
		{
		case 1:
			g_Console.writeToBuffer(c, "Theres a wooden boat in the distance leaning against a couple rocks.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Theres a giant hole in its hull so I doubt its usability.", 0x02);
			break;
		case 2:
			g_Console.writeToBuffer(c, "The trees are swaying in harmony with the wind.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Their leaves seem to have a weird shade of dark green.", 0x02);
			break;
		case 3:
			g_Console.writeToBuffer(c, "It looks and feels like some sort of portal. It pulsates with a strange light-blue energy but oddly enough", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I don't feel intimidated by it at all. Instead, it feels like it's drawing me in. Should I enter it?", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to enter the portal.", 0x05);
			break;
		case 11: // Lake Stones
			g_Console.writeToBuffer(c, "A stack of stones. Having one of them may come in handy.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to pick a stone up.", 0x05);
			break;
		case 12: // Lake water
			g_Console.writeToBuffer(c, "Unlike the sea, the water here is calm and clear.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I can see something metallic barely breaking the surface.", 0x02);
			c.Y++;
			if (inventory == "A Flat Stone")
			{
				g_Console.writeToBuffer(c, "I wonder if I can hit it with the rock I picked up.", 0x05);
			}
			break;
		case 13: // Lake Fish
			g_Console.writeToBuffer(c, "If I'm not wrong, that fish looks like a red herring.", 0x02);
			break;
		case 14: // Lake Box
			g_Console.writeToBuffer(c, "There is a red chest here locked with a padlock.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A note atop of it reads 'AXJPODBCOPWBVU'.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I can't seem to make any sense of it.", 0x05);
			break;
		case 15: // Lake Stone (OF)
			g_Console.writeToBuffer(c, "They feel like stones yet they are as black as coal. I'll take one just in case.", 0x02);
			c.Y++;
			if (levelfinish != 2)
			{
				g_Console.writeToBuffer(c, "Press the E key to pick a stone up.", 0x05);
			}
			break;
		case 16: // Lake Water (OF)
			g_Console.writeToBuffer(c, "The water is blood-red and muddy.", 0x02);
			c.Y++;
			if (inventory == "A stone filled fish")
			{
				g_Console.writeToBuffer(c, "The fish trashes wildly as I bring it toward the lake. Its unsettling, but I don't freak out.", 0x05);
			}
			break;
		case 17: // Lake Fish (OF)
			g_Console.writeToBuffer(c, "A red herring.", 0x02);

			if (inventory == "A black flat stone")
			{
				c.Y++;
				g_Console.writeToBuffer(c, "The fishes mouth opens by itself as I approach it with the black stone. Creepy.", 0x05);
			}

			if (reqinteraction == 1)
			{
				c.Y++;
				g_Console.writeToBuffer(c, "I've put 1 stone into the fish.", 0x02);
			}
			else if (reqinteraction == 2)
			{
				c.Y++;
				g_Console.writeToBuffer(c, "I've put 2 stones into the fish. It feels noticably heavier.", 0x02);
			}
			else if (reqinteraction == 3)
			{
				c.Y++;
				g_Console.writeToBuffer(c, "I've put 3 stones into the fish.                            It is heavy.", 0x02);
				c.X += 33;
				g_Console.writeToBuffer(c, "There is no room for more.", 0x05);
				c.X = 0;
			}
			break;
		case 18: // Lake Box (OF)
			g_Console.writeToBuffer(c, "A locked chest.", 0x02);
			break;
		case 19: //Chapel Window
			g_Console.writeToBuffer(c, "I can’t see anything through the window. It’s stained glass after all.", 0x02);
			break;
		case 20: //Chapel Box
			g_Console.writeToBuffer(c, "There’s a black box here with no lid or cover.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Perhaps I should just grab the black sphere thing instead?", 0x02);
			break;
		case 21:  //Chapel Pews
			g_Console.writeToBuffer(c, "I've got no time for prayers right now.");
			break;
		case 22: //Chapel Podium
			g_Console.writeToBuffer(c, "There's some sort of black orb on the podium. Should I take it?", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press E to take black orb.", 0x05);
			break;
		case 24 : //Computer Room Bookshelf
			g_Console.writeToBuffer(c, "Hmmm...this book seems interesting. It’s a biography of Julius Caesar.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Wait a minute...that’s strange, a page is torn from the book. I’ll keep it just in case.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "History Book has been added to your inventory.", 0x05);
			break;
		case 25 :  //Computer Room computer
			g_Console.writeToBuffer(c, "Username: 1.1C4431, 103.552D10", 0x08);  //text is gray in colour
			c.Y++;
			g_Console.writeToBuffer(c, "Password:", 0x08);
			break;
		case 26 :  //Computer Room Map
			g_Console.writeToBuffer(c, "I believe it’s a map of Singapore. A red circle is drawn at the southern tip of the island.", 0x02);
			break;
		case 27 :  //Street Buildings
			g_Console.writeToBuffer(c, "All the buildings look the same.", 0x02);
			break;
		case 28 : //Street Lamposts
			g_Console.writeToBuffer(c, "Just your typical lamppost.", 0x02);
			break;
		case 29 : //Street Box
			g_Console.writeToBuffer(c, "There’s a code scratched above the lock of this red box.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "01001000  01000001  01010000  01010000  01011001", 0x08);
			break;
		case 911:
			g_Console.writeToBuffer(c, "The stone hit the metallic object with a pleasant 'ding'.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A sound came from the red chest to my right.", 0x02);
			break;
		case 912: // Solve EF1 Box
			g_Console.writeToBuffer(c, "As I thought, the chest was unlocked as soon as the stone hit the metal object.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I lifted the cover and found a note inside. It reads:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "'Memories are but a jigsaw, one must have all pieces in hand to see the full picture.'", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "As soon as my eyes landed on the last word, a blinding white light exploded around me.", 0x02);
			break;
		case 913: // Solve OF1 Lake
			g_Console.writeToBuffer(c, "After waiting for a short while, a sound came from the red chest to my right.", 0x02);
			break;
		case 914: // Solve OF1 Box
			g_Console.writeToBuffer(c, "The sinister voice that spoke when I had first entered the portal spoke again.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A blinding white light exploded around me as it said its last word.", 0x02);
			break;
		case 404: // Error 404. Just kidding.
			g_Console.writeToBuffer(c, "An unknown force prevents me from proceeding.", 0x03);
			break;
		case 999: // Testing purposes only, pls take out on release build danke.
			g_Console.writeToBuffer(c, "Whatever you are doing,", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "it bloody works!", 0x02);
			break;
		}
		c.Y = tempcoords;
	}

	if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 1)
	{
		InPortal = 0;
		Areanum = 1;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 88;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 45;
	}

	if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 2)
	{
		InPortal = 0;
		Areanum = 1;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 74;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 48;
	}
}