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
extern int OptionalFragment;
extern int EssentialFragment;
extern int reqinteraction;

void actfeed()
{
	int tempcoords;            // Used to hold the value of c.Y in activity feed

	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 31;


	if (Areanum == 1 && EssentialFragment == 0 && OptionalFragment == 0)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "Use WASD keys to move around, F key to interact and E to enter/use.", 0x05);
		c.Y++;
		g_Console.writeToBuffer(c, "\"Wha-What is this place?\"", 0x02);
		c.Y++;

		if (g_dElapsedTime > 5.0) // wait for 5 seconds to display next message
		{
			g_Console.writeToBuffer(c, "I looked about confused and wide-eyed.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 7.0) // wait for 7 seconds to display next message
		{
			g_Console.writeToBuffer(c, "A verdant grassy plain laid out before me while the sea behind me rolled and crashed into the shores of the", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "beach I was standing in.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 11.0) // wait for 11 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Trees which bordered the plains crackled as a cold breeze blew across the island. Seagulls overhead screamed", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "in response.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 15.0) // wait for 15 seconds to display next message
		{
			g_Console.writeToBuffer(c, "", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Despite so much looking around, my surroundings didn't provide a single clue as to where I am or how I got", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "here... or who I was.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 19.0) // wait for 19 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Wait a minute, I think I got something...", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 21.0) // wait for 21 seconds to display next message
		{
			g_Console.writeToBuffer(c, "A...Av...Ava? Ava...Laurens?", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 23.0) // wait for 23 seconds to display next message
		{
			g_Console.writeToBuffer(c, "Is that my name?", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 25.0) // wait for 25 seconds to display next message
		{
			g_Console.writeToBuffer(c, "\"Ava Laurens.\" The name sounds much clearer now, it has to be mine.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > 28.0) // wait for 28 seconds to display next message
		{
			g_Console.writeToBuffer(c, "I should take a look around, since being a sitting duck here would do me no good.", 0x02);
			c.Y++;
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

	if (InPortal == 3)
	{
		c.Y = 31;

		if (inventory == "Odd black sphere")
		{
			g_Console.writeToBuffer(c, "Odd black sphere has been added to your inventory.", 0x03);
		}

		if (inventory == "A ring")
		{
			g_Console.writeToBuffer(c, "A ring has been added to your inventory.", 0x03);
		}
	}

	if (Factfeed == 912) // EF 1
	{
		c.Y = 31;
		g_Console.writeToBuffer(c, "\"First, you get the flattest rock you can find like this one,\" he said, brandishing the stone he just", 0x03);
		c.Y++;
		g_Console.writeToBuffer(c, "picked up from the ground.", 0x03);
		c.Y++;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Next, you aim it at an angle like so...\", he continued, \"while adding a little spin to it, you throw", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "as hard as you can.\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 3.0))
		{
			g_Console.writeToBuffer(c, "At the last word of his sentence, he hurled the stone towards the lake.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 5.0))
		{
			g_Console.writeToBuffer(c, "It skipped five times across the surface of the water before plopping into the depths below.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 8.0))
		{
			g_Console.writeToBuffer(c, "\"Now you try it,\" he said with a proud look on his face.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "I wrinkled my nose at him, before grabbing a stone from the ground and tossed it at the lake.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 14.0))
		{
			g_Console.writeToBuffer(c, "It skipped eight times on the surface before sinking.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 16.0))
		{
			g_Console.writeToBuffer(c, "He stared at me in disbelief, \"Damn Ava, nice throw!\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 18.0))
		{
			g_Console.writeToBuffer(c, "\"Or maybe you're just bad at it,\" I snorted.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 20.0))
		{
			g_Console.writeToBuffer(c, "His eyes twinkled mysteriously.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 21.0))
		{
			g_Console.writeToBuffer(c, "\"Oh yeah? I'll show you something I'm good at!\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 23.0))
		{
			g_Console.writeToBuffer(c, "He raced towards me and slung me over his shoulder. He then ran towards the treeline with us both,", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "laughing the whole time.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 27.0))
		{
			g_Console.writeToBuffer(c, "Startled, I jumped backwards.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 28.0))
		{
			g_Console.writeToBuffer(c, "\"What in the world was that?\"", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 29.0))
		{
			g_Console.writeToBuffer(c, "That man seemed so familiar, as if I've known him for all my life.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 31.0))
		{
			g_Console.writeToBuffer(c, "Perhaps that was some kind of memory? If I enter more of those portals, will I get my memory back?", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 34.0))
		{
			g_Console.writeToBuffer(c, "I guess I better find out.", 0x02);
		}
	}

	if (Factfeed == 914) // OF 1
	{
		c.Y = 34;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Who was that girl just now? Did you know her?\" Ava asked jealously.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 3.0))
		{
			g_Console.writeToBuffer(c, "\"Yeah, she was my friend from high school.\" Terence replied.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 5.0))
		{
			g_Console.writeToBuffer(c, "\"Oh really?\" Ava said, glaring at the direction the girl went. \"Don't speak to her ever again.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 8.0))
		{
			g_Console.writeToBuffer(c, "\"What? But-\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "\"If you love me, never talk to her again. You do love me, right?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 11.0))
		{
			g_Console.writeToBuffer(c, "\"...Yes, I do.\"", 0x03);
		}
	}

	if (Factfeed == 923) // EF 2
	{
		c.Y = 31;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Terence, do you take Ava as your lawfully wedded wife, to have and to hold, from this day forward, for", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "better or for worse, for richer or for poorer, in sickness and in health, to love and cherish until", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "death do you part?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "\"I do.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "\"Ava, do you take Terence as your lawful husband, to have and to hold, from this day forward, for", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "better or for worse, for richer or for poorer, in sickness and in health, to love and cherish until", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "death do you part?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 19.0))
		{
			g_Console.writeToBuffer(c, "\"I do.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 20.0))
		{
			g_Console.writeToBuffer(c, "\"Bride and Groom, you have heard the words about love and marriage, have exchanged your vows and made", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "your promises, and celebrated your union with the giving and receiving of rings. Therefore, it is my", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "pleasure at this time that I now pronounce you Man and Wife. You may now kiss the bride.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 30.0))
		{
			g_Console.writeToBuffer(c, "And thus our lips met to the roar of applause from our families. Happiness would be an understatement!", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 34.0))
		{
			g_Console.writeToBuffer(c, "Finally, my mother would stop nagging me about getting married!", 0x03);
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
			g_Console.writeToBuffer(c, "I can't see anything through the window. It's stained glass after all.", 0x02);

			if (inventory == "Odd black sphere")
			{
				c.Y++;
				g_Console.writeToBuffer(c, "The black sphere seems to react to the light from the window. Should I hold it closer?", 0x05);
			}
			break;
		case 20: //Chapel Table
			g_Console.writeToBuffer(c, "It's a table with nothing on it. This table is useless.", 0x02);
			break;
		case 21:  //Chapel Pews
			g_Console.writeToBuffer(c, "I've got no time for prayers right now.", 0x02);
			break;
		case 22: //Chapel Podium
			if (reqinteraction == 0)
			{
				g_Console.writeToBuffer(c, "There's a black box sitting on the podium beside a black sphere of some sort. The box has no lid or cover.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Maybe I should just take the black sphere thing instead?", 0x05);
				c.Y++;
				g_Console.writeToBuffer(c, "Press the E key to take black orb.", 0x05);
			}
			else if (reqinteraction == 1)
			{
				g_Console.writeToBuffer(c, "There's a black box sitting on the podium. The box has no lid or cover.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "There's no way it will open just by me staring at it and doing nothing.", 0x02);
			}
			else if (reqinteraction == 2)
			{
				g_Console.writeToBuffer(c, "There's a black box sitting on the podium. A part of it lies on the floor.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "The revealed section of the box shows a ring-shaped hole.", 0x02);
			}
			break;
		case 23:  //Chapel Button (OF)
			g_Console.writeToBuffer(c, "I pressed the button.", 0x02);
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
		case 30 :   //Chapel Podium (OF)
			g_Console.writeToBuffer(c, "The podium is empty", 0x02);
			break;
		case 31:   //Street Box (OF)
			g_Console.writeToBuffer(c, "A red box is lying on the ground in the middle of the street.", 0x02);
			break;
		case 32:  //Street Door (OF)
			g_Console.writeToBuffer(c, "A door to one of the buildings is open. Should I enter it?", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press E to enter building", 0x05);
			break;
		case 33:   //Living Room Window
			g_Console.writeToBuffer(c, "As far as I can see, there’s only a void of white outside the window", 0x02);
			break;
		case 34:  //Living Room Phone
			g_Console.writeToBuffer(c, "A grey typical push-button telephone. A note beside it reads:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "This requires a BIT of thinking. Perhaps a clue lies in the word between Caps Lock and LEFT Control.What’s the number that replaces the question mark?", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "13 26 52", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "104 208 161", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "67 ? 13", 0x08);
			break;
		case 35:  //Living Room Sofa
			g_Console.writeToBuffer(c, "It looks comfortable, but whoever bought it must have horrible taste. The patterns on it look absolutely dreadful.", 0x08);
			break;
		case 36:  //Living Room Window (OF)
			g_Console.writeToBuffer(c, "There is nothing but red fog outside.", 0x02);
			break;
		case 37:  //Living Room Phone (OF)
			g_Console.writeToBuffer(c, "Nothing but a long, monotonous tone comes through the handset speaker", 0x02);
			break;
		case 38:   //Living Room sofa
			g_Console.writeToBuffer(c, "This sofa is so ugly that I do not know if I should laugh at or pity its owner.", 0x02);
			break;
		case 39:  //Living Room Baby's cot
			g_Console.writeToBuffer(c, "A baby cot with a word burnt into the wood:", 0x05);
			c.Y++;
			g_Console.writeToBuffer(c, "LIAR", 0x04);
			break;
		case 911:   //Lake EF Complete
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
		case 921: // Solve EF2 Sphere
			g_Console.writeToBuffer(c, "Once it touched the light emanating from the windows, the sphere melted away.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A ring was all that's left from it.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I heard a \"thunk\". A section of the box fell off and plopped to the ground.", 0x02);
			break;
		case 922: // Solve EF2 Ring
			g_Console.writeToBuffer(c, "The ring should fit right here...", 0x02);
			break;
		case 923: // Solve EF2 Box
			g_Console.writeToBuffer(c, "It worked. The box is opened. White light begins to fill my vision again.", 0x02);
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

	if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 3)
	{
		InPortal = 0;
		Areanum = 2;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 43;
	}
}