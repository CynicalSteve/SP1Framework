// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include "Map.h"
#include "CheckColi.h"
#include "MegaInteract.h"
#include "Windows.h"
#include "MMSystem.h"

double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];

int Areanum = 1;
int Levelnum = 0;          // Odd numbers = EF, Even numbers = OF. In code later for last 2 "IF OF = 5, then take player to the 2nd ending instead"
int checkF;                // Checking what the player is interacting with
int tempcoords;            // Used to hold the value of c.Y in activity feed

extern int Factfeed;
extern int InPortal;
extern int EssentialFragment;
extern int OptionalFragment;
extern std::string inventory;
extern double g_dElapsedTimeTemp;
extern int levelfinish;

// Game specific variables here
SGameChar   g_sChar;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(110, 55, "SP1 Framework");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_SPLASHSCREEN;

	// sets the music for the game
	PlaySound(TEXT("HappyMusic.wav"), NULL, SND_SYNC | SND_LOOP | SND_ASYNC);

	// sets where the character spawns when game starts
	g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 87;
	g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 43;
	g_sChar.m_bActive = true;
    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{    
    g_abKeyPressed[K_UP]        = isKeyPressed(0x57);
    g_abKeyPressed[K_DOWN]      = isKeyPressed(0x53);
    g_abKeyPressed[K_LEFT]      = isKeyPressed(0x41);
    g_abKeyPressed[K_RIGHT]     = isKeyPressed(0x44);
	g_abKeyPressed[K_INTERACT]  = isKeyPressed(0x46);
	g_abKeyPressed[K_INVENTORY] = isKeyPressed(0x49);
    g_abKeyPressed[K_SPACE]     = isKeyPressed(VK_SPACE);
    g_abKeyPressed[K_ESCAPE]    = isKeyPressed(VK_ESCAPE);
	g_abKeyPressed[K_ENTER]     = isKeyPressed(0x45);
	g_abKeyPressed[K_INVONE]    = isKeyPressed(0x30);
	g_abKeyPressed[K_INVTWO]    = isKeyPressed(0x31);
	g_abKeyPressed[K_INVTHREE]  = isKeyPressed(0x32);
	g_abKeyPressed[K_INVFOUR]   = isKeyPressed(0x33);
	g_abKeyPressed[K_INVFIVE]   = isKeyPressed(0x34);
	g_abKeyPressed[K_INVSIX]    = isKeyPressed(0x35);
	g_abKeyPressed[K_INVSEVEN]  = isKeyPressed(0x36);
	g_abKeyPressed[K_INVEIGHT]  = isKeyPressed(0x37);
	g_abKeyPressed[K_INVNINE]   = isKeyPressed(0x38);
	g_abKeyPressed[K_INVZERO]   = isKeyPressed(0x39);
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
		case S_INVENTORY: gameplay(); // Enables input checking for turning off inventory
			break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
			break;
    }
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
        case S_SPLASHSCREEN: renderSplashScreen();
            break;
		case S_INVENTORY: renderUI(); // is Inventory open?
			break;
        case S_GAME: renderGame();
            break;
    }
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
        g_eGameState = S_GAME;
}

void gameplay()            // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
    moveCharacter();    // moves the character, collision detection, physics, etc
                        // sound can be played here too.
}

void moveCharacter()
{
    bool bSomethingHappened = false;
    if (g_dBounceTime > g_dElapsedTime)
        return;

    // Updating the location of the character based on the key press
    // providing a beep sound whenver we shift the character
    if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
    {
		if (Areanum > 0)
		{
			if (Collision(1) == 1)
			{
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(1) == 1)
			{
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
    }
	if (g_abKeyPressed[K_DOWN] && (g_sChar.m_cLocation.Y < (g_Console.getConsoleSize().Y - 1)))
	{
		if (Areanum > 0)
		{
			if (Collision(2) == 1)
			{
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(2) == 1)
			{
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
	}
    if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
    {
		if (Areanum > 0)
		{
			if (Collision(3) == 1)
			{
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(3) == 1)
			{
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
    }
	if (g_abKeyPressed[K_RIGHT] && (g_sChar.m_cLocation.X < (g_Console.getConsoleSize().X - 1)))
    {
		if (Areanum > 0)
		{
			if (Collision(4) == 1)
			{
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(4) == 1)
			{
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
			}
			else
			{
				bSomethingHappened = true;
			}
		}
    }
    if (g_abKeyPressed[K_SPACE])
    {
        g_sChar.m_bActive = !g_sChar.m_bActive;
        bSomethingHappened = true;
    }

    if (bSomethingHappened)
    {
        // set the bounce time to some time in the future to prevent accidental triggers
        g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
    }

}
void processUserInput()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

    // quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}

	if (g_abKeyPressed[K_INTERACT])
	{
		checkF = checkinteract();

		FstandsforFrustrating(checkF);
	}

	if (g_abKeyPressed[K_INVENTORY])
	{
		bSomethingHappened = true;

		if (g_eGameState != 2)
		{
			g_eGameState = S_INVENTORY;
		}
		else if (g_eGameState == 2)
		{
			clearScreen();

			g_eGameState = S_GAME;
		}
	}

	if (g_abKeyPressed[K_ENTER])
	{
		FstandsforFrustrating(9);
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x00);
}

void renderSplashScreen()  // renders the splash screen
{
	COORD c = g_Console.getConsoleSize();
	c.Y /= 3;
	c.X = g_Console.getConsoleSize().X / 2 - 30;
	g_Console.writeToBuffer(c, " _______", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, "(_______)                                         _", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, " _____  ____  _____   ____  ____   _____  ____  _| |_   ___", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, "|  ___)/ ___)(____ | / _  ||    \\ | ___ ||  _ \\(_   _) / __)", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, "| |   | |    / ___ |( (_| || | | || ____|| | | | | |_ |___ |", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, "|_|   |_|    \\_____| \\___ ||_|_|_||_____)|_| |_|  \\__)(___/", 0x03);
	c.Y += 1;
	g_Console.writeToBuffer(c, "                    (_____|  ", 0x03);
	c.Y += 1;

	c.Y += 2;
	c.X = g_Console.getConsoleSize().X / 2 - 10;
	g_Console.writeToBuffer(c, "Welcome to Fragments", 0x03);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 20;
	g_Console.writeToBuffer(c, "Press <Space> to change character colour", 0x09);
	c.Y += 1;
	c.X = g_Console.getConsoleSize().X / 2 - 9;
	g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);
}

void renderGame()
{
    renderMap();        // renders the map to the buffer first
	renderFeed();		// renders the activity feed to the buffer
    renderCharacter();  // renders the character into the buffer
}

void renderMap()
{
	const WORD colors[] = {
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};
	
	if (Areanum > 0)
	{
		char** printmap = new char*[150];
		printmap = mapstore(printmap);
		map(printmap);
	}
	else if (Areanum == 0)
	{
		char** printlevel = new char*[150];
		printlevel = puzzlestore(printlevel);
		puzzlemap(printlevel);
	}
}

void renderCharacter()
{
    // Draw the location of the character
    WORD charColor = 0x0C;
    if (g_sChar.m_bActive)
    {
        charColor = 0x0A;
    }
    g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
}

void renderFeed()
{
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 28;
	g_Console.writeToBuffer(c, "=============================================================================================================", 0x07);
	c.Y += 1;
	g_Console.writeToBuffer(c, "Essential Fragments Obtained:", 0x07);
	c.X += 30;
	g_Console.writeToBuffer(c, EssentialFragment + 48, 0x06);
	c.X += 5;
	g_Console.writeToBuffer(c, "Optional Fragments Obtained:", 0x07);
	c.X += 30;
	g_Console.writeToBuffer(c, OptionalFragment + 48, 0x06);
	c.X += 5;
	g_Console.writeToBuffer(c, "Item in Hand:", 0x07);
	c.X += 15;
	g_Console.writeToBuffer(c, inventory, 0x06);
	c.X = 0; // Reset X to 0 so printing is normal again.
	c.Y += 1;                                                                                                                       
	g_Console.writeToBuffer(c, "=============================================================================================================", 0x07);
	c.Y += 1;
	g_Console.writeToBuffer(c, "\"Wha-What is this place?\"", 0x02);
	c.Y += 1;

	if (g_dElapsedTime > 5.0) // wait for 5 seconds to display next message
	{
		g_Console.writeToBuffer(c, "I looked about confused and wide-eyed.", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 7 seconds to display next message
	{
		g_Console.writeToBuffer(c, "A verdant grassy plain laid out before me while the sea behind me rolled and crashed into the shores of the", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 7 seconds to display next message
	{
		g_Console.writeToBuffer(c, "beach I was standing in.", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 11 seconds to display next message
	{
		g_Console.writeToBuffer(c, "Trees which bordered the plains crackled as a cold breeze blew across the island. Seagulls overhead screamed", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 11 seconds to display next message
	{
		g_Console.writeToBuffer(c, "in response.", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 15 seconds to display next message
	{
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 15 seconds to display next message
	{
		g_Console.writeToBuffer(c, "Despite so much looking around, my surroundings didn't provide a single clue as to where I am or how I got", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 15 seconds to display next message
		g_Console.writeToBuffer(c, "here... or who I was.", 0x02);
	c.Y += 1;
	if (g_dElapsedTime > 5.0) // wait for 19 seconds to display next message
	{
		g_Console.writeToBuffer(c, "Wait a minute, I think I got something...", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 21 seconds to display next message
	{
		g_Console.writeToBuffer(c, "A...Av...Ava? Ava...Laurens?", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 23 seconds to display next message
	{
		g_Console.writeToBuffer(c, "Is that my name?", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 25 seconds to display next message
	{
		g_Console.writeToBuffer(c, "\"Ava Laurens.\" The name sounds much clearer now, it has to be mine.", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 28 seconds to display next message
	{
		g_Console.writeToBuffer(c, "I should take a look around, since being a sitting duck here would do me no good.", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 30 seconds to display next message
	{
		g_Console.writeToBuffer(c, "Use WASD keys to move around, F key to interact and E to enter/use.", 0x05);
		c.Y += 1;
	}
	if (g_dElapsedTime > 5.0) // wait for 30 seconds to display next message
	{
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y += 1;
	}
	if (g_dElapsedTime > 6.0) 
	{
		g_Console.writeToBuffer(c, "Wake", 0x04);
		c.Y += 1;
	}
	if (g_dElapsedTime > 6.0) 
	{
		g_Console.writeToBuffer(c, "Me", 0x04);
		c.Y += 1;
	}
	if (g_dElapsedTime > 6.0) 
	{
		g_Console.writeToBuffer(c, "Up", 0x04);
		c.Y += 1;
	}
	if (g_dElapsedTime > 7.0) 
	{
		g_Console.writeToBuffer(c, "Wake", 0x04);
		c.Y += 1;
	}
	if (g_dElapsedTime > 7.0) 
	{
		g_Console.writeToBuffer(c, "Me", 0x04);
		c.Y += 1;
	}
	if (g_dElapsedTime > 7.0)
	{
		g_Console.writeToBuffer(c, "Up", 0x04);
		c.Y += 1;
	}
	if (g_dElapsedTime > 7.0) 
	{
		g_Console.writeToBuffer(c, "Inside", 0x04);
		c.Y += 1;
	}

	if (c.Y == 54)
	{
		c.Y = 31;
	}

	if (g_dElapsedTime > 8.0) 
	{
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		g_Console.writeToBuffer(c, "Save", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
	}

	if (g_dElapsedTime > 8.0)
	{
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		g_Console.writeToBuffer(c, "Me", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		
	}
	if (g_dElapsedTime > 9.0) 
	{
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		g_Console.writeToBuffer(c, "Call", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		
	}
	if (g_dElapsedTime > 9.0)
	{
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		g_Console.writeToBuffer(c, "My", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		
	}
	if (g_dElapsedTime > 9.0) 
	{
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
		g_Console.writeToBuffer(c, "Name", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
	}

	if (Factfeed == 1)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "Theres a wooden boat in the distance leaning against a couple rocks.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "Theres a giant hole in its hull so I doubt its usability.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);

		c.Y = tempcoords;
	}
	else if (Factfeed == 2)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "The trees are swaying in harmony with the wind.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "Their leaves seem to have a weird shade of dark green.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);

		c.Y = tempcoords;
	}
	else if (Factfeed == 3)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "It looks and feels like some sort of portal. It pulsates with a strange light-blue energy but oddly enough", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "I don't feel intimidated by it at all. Instead, it feels like it's drawing me in. Should I enter it?", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "Press the E key to enter the portal.", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 11) // Rocks
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "A stack of stones. Having one of them may come in handy.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "Press the E key to pick a rock up.", 0x05);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 12) // Lake
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "Unlike the sea, the water here is calm and clear.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "I can see something metallic barely breaking the surface.", 0x02);
		c.Y++;
		if (inventory == "A flat rock")
		{
			g_Console.writeToBuffer(c, "I wonder if I can hit it with the rock I picked up.", 0x05);
		}
		else
		{
			g_Console.writeToBuffer(c, "", 0x05);
		}

		c.Y = tempcoords;
	}
	else if (Factfeed == 13) // Fish
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "If I'm not wrong, that fish looks like a red herring.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);
			
		c.Y = tempcoords;
	}
	else if (Factfeed == 14) // Box
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "There is a red chest here locked with a padlock.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "A note atop of it reads 'AXJPODBCOPWBVU'.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "I can't seem to make any sense of it.", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 15) //Stone (Opt frag)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "They feel like stones yet they are as black as coal. I'll take one just in case.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 16) //Lake (Opt frag)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "The water is blood-red and muddy.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 17) //Fish (Opt frag)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "A red herring.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 18) //Box (Opt frag)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "A locked box.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (InPortal == 2)
	{
		tempcoords = c.Y;

		g_Console.writeToBuffer(c, "No matter how strong one is, with too heavy a burden they will sink.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 911)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "The stone hit the metallic object with a pleasant 'ding'.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "A sound came from the red chest to my right.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	else if (Factfeed == 912)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "As I thought, the chest was unlocked as soon as the stone hit the metal object.", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "I lifted the cover and found a note inside. It reads:", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "'Memories are but a jigsaw, one must have all pieces in hand to see the full picture.'", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "As soon as my eyes landed on the last word, a blinding white light exploded around me.", 0x02);

		c.Y = tempcoords;
	}
	else if (Factfeed == 999) // THIS IS JUST TO TEST WHETHER A FUNCTION WORKS LOL
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "Whatever you are doing,", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "it bloody works!", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}

	if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 1)
	{
		InPortal = 0;
		Areanum = 1;
		levelfinish = 0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 88;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 45;
	}

	/*
	TEMPLATE FOR ME TO COPY AND PASTE CAUSE IM LAZY

		else if (Factfeed == 11)
	{
		tempcoords = c.Y;

		c.Y = 24;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x02);
		c.Y++;
		g_Console.writeToBuffer(c, "", 0x05);

		c.Y = tempcoords;
	}
	*/
}


void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

    // displays the elapsed time
    ss.str("");
    ss << g_dElapsedTime << "secs";
    c.X = 0;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str(), 0x59);
}
void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

void renderUI() // items - Flat Stone, History Book
{
	COORD c = g_Console.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	g_Console.writeToBuffer(c, "-Inventory Opened-", 0x03); // at the moment this does jack shit aside from show a new screen saying inventory is open

	c.Y += 2;
	c.X = g_Console.getConsoleSize().X / 2 - 5;
	g_Console.writeToBuffer(c, "Flat Stone", 0x09);

	c.Y += 2;
	c.X = g_Console.getConsoleSize().X / 2 - 5;
	g_Console.writeToBuffer(c, "History Book", 0x09);
}