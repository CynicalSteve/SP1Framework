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
#include "Windows.h"
#include "MMSystem.h"

using namespace std;

double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];

<<<<<<< HEAD
int Areanum = 1;
int Levelnum = 0;          // Odd numbers = EF, Even numbers = OF. In code later for last 2 "IF OF = 5, then take player to the 2nd ending instead"
=======
int Areanum = 5;
int Levelnum = 5;          // Odd numbers = EF, Even numbers = OF. In code later for last 2 "IF OF = 5, then take player to the 2nd ending instead"
>>>>>>> d4f318def8020a7c5059eef5ca3197a94aa388cc
int checkF;                // Checking what the player is interacting with

extern int EssentialFragment;
extern int OptionalFragment;
extern string inventory;
extern double g_dTime;

// Game specific variables here
SGameChar   g_sChar;
Menu		MenuArrow;
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

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 16, L"Consolas");

	// sets the arrow in the menu screen
	MenuArrow.Arrow_Location.X = g_Console.getConsoleSize().X - 68;
	MenuArrow.Arrow_Location.Y = g_Console.getConsoleSize().Y - 26;
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
	if (g_eGameState != S_INPUT)
	{
		g_abKeyPressed[K_UP] = isKeyPressed(0x57);
		g_abKeyPressed[K_DOWN] = isKeyPressed(0x53);
		g_abKeyPressed[K_LEFT] = isKeyPressed(0x41);
		g_abKeyPressed[K_RIGHT] = isKeyPressed(0x44);
		g_abKeyPressed[K_INTERACT] = isKeyPressed(0x46);
		g_abKeyPressed[K_INVENTORY] = isKeyPressed(0x49);
		g_abKeyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
		g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
		g_abKeyPressed[K_ENTER] = isKeyPressed(0x45);
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
		g_abKeyPressed[K_PAUSE] = isKeyPressed(0x50);
		g_abKeyPressed[K_JOURNAL] = isKeyPressed(0x4A);
		g_abKeyPressed[A_UP] = isKeyPressed(VK_UP);
		g_abKeyPressed[A_DOWN] = isKeyPressed(VK_DOWN);
	}
	else if (g_eGameState == S_INPUT)
	{
		g_abKeyPressed[K_BACKSPACE] = isKeyPressed(0x08);
		g_abKeyPressed[K_A] = isKeyPressed(0x41);
		g_abKeyPressed[K_B] = isKeyPressed(0x42);
		g_abKeyPressed[K_C] = isKeyPressed(0x43);
		g_abKeyPressed[K_D] = isKeyPressed(0X44);
		g_abKeyPressed[K_E] = isKeyPressed(0x45);
		g_abKeyPressed[K_F] = isKeyPressed(0x46);
		g_abKeyPressed[K_G] = isKeyPressed(0x47);
		g_abKeyPressed[K_H] = isKeyPressed(0x48);
		g_abKeyPressed[K_I] = isKeyPressed(0x49);
		g_abKeyPressed[K_J] = isKeyPressed(0x4A);
		g_abKeyPressed[K_K] = isKeyPressed(0x4B);
		g_abKeyPressed[K_L] = isKeyPressed(0x4C);
		g_abKeyPressed[K_M] = isKeyPressed(0x4D);
		g_abKeyPressed[K_N] = isKeyPressed(0x4E);
		g_abKeyPressed[K_O] = isKeyPressed(0x4F);
		g_abKeyPressed[K_P] = isKeyPressed(0x50);
		g_abKeyPressed[K_Q] = isKeyPressed(0x51);
		g_abKeyPressed[K_R] = isKeyPressed(0x52);
		g_abKeyPressed[K_S] = isKeyPressed(0x53);
		g_abKeyPressed[K_T] = isKeyPressed(0x54);
		g_abKeyPressed[K_U] = isKeyPressed(0x55);
		g_abKeyPressed[K_V] = isKeyPressed(0x56);
		g_abKeyPressed[K_W] = isKeyPressed(0x57);
		g_abKeyPressed[K_X] = isKeyPressed(0x58);
		g_abKeyPressed[K_Y] = isKeyPressed(0x59);
		g_abKeyPressed[K_Z] = isKeyPressed(0x5A);
		g_abKeyPressed[K_ESC] = isKeyPressed(0x1B);
		g_abKeyPressed[K_ENTER] = isKeyPressed(0x0D);

		g_abKeyPressed[K_ONE] = isKeyPressed(0x31);
		g_abKeyPressed[K_TWO] = isKeyPressed(0x32);
		g_abKeyPressed[K_THREE] = isKeyPressed(0x33);
		g_abKeyPressed[K_FOUR] = isKeyPressed(0x34);
		g_abKeyPressed[K_FIVE] = isKeyPressed(0x35);
		g_abKeyPressed[K_SIX] = isKeyPressed(0x36);
		g_abKeyPressed[K_SEVEN] = isKeyPressed(0x37);
		g_abKeyPressed[K_EIGHT] = isKeyPressed(0x38);
		g_abKeyPressed[K_NINE] = isKeyPressed(0x39);
		g_abKeyPressed[K_ZERO] = isKeyPressed(0x30);
	}
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
        case S_GAME: gameplay(); // gameplay logic when we are in the game
			break;
		case S_PAUSE: gameplay();
			break;
		case S_JOURNAL: gameplay();
			break;
		case S_INPUT: gameplay();
			break;
		case S_INSTRUCTIONS: gameplay();
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
	case S_GAME: renderGame();
		break;
	case S_PAUSE: pause();
		break;
	case S_JOURNAL: renderJournal();
		break;
	case S_INPUT: renderInput();
		break;
	case S_INSTRUCTIONS: instructions();
		break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	// Draw the location of the arrow
	if (g_abKeyPressed[K_SPACE] && MenuArrow.Arrow_Location.Y == g_Console.getConsoleSize().Y - 26)
	{
		//enter game
		g_eGameState = S_GAME;
		g_dTime = (g_dElapsedTime + 2.0);
	}
	if (g_abKeyPressed[K_SPACE] && MenuArrow.Arrow_Location.Y == g_Console.getConsoleSize().Y - 25)
	{
		//enter instructions screen
		g_eGameState = S_INSTRUCTIONS;

	}
	if (g_abKeyPressed[A_DOWN] && MenuArrow.Arrow_Location.Y == g_Console.getConsoleSize().Y - 26)
	{
		MenuArrow.Arrow_Location.Y++;
	}
	if (g_abKeyPressed[A_UP] && MenuArrow.Arrow_Location.Y == g_Console.getConsoleSize().Y - 25)
	{
		MenuArrow.Arrow_Location.Y--;
	}
}

void gameplay()            // gameplay logic
{
    processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	if (g_eGameState == S_GAME)
	{
		moveCharacter();    // moves the character, collision detection, physics, etc
							// sound can be played here too.
	}
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
		bSomethingHappened = true;

		if (Areanum > 0)
		{
			if (Collision(1) == 1)
			{
				g_sChar.m_cLocation.Y--;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(1) == 1)
			{
				g_sChar.m_cLocation.Y--;
			}
		}
    }
	if (g_abKeyPressed[K_DOWN] && (g_sChar.m_cLocation.Y < (g_Console.getConsoleSize().Y - 1)))
	{
		bSomethingHappened = true;

		if (Areanum > 0)
		{
			if (Collision(2) == 1)
			{
				g_sChar.m_cLocation.Y++;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(2) == 1)
			{
				g_sChar.m_cLocation.Y++;
			}
		}
	}
    if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
    {
		bSomethingHappened = true;

		if (Areanum > 0)
		{
			if (Collision(3) == 1)
			{
				g_sChar.m_cLocation.X--;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(3) == 1)
			{
				g_sChar.m_cLocation.X--;
			}
		}
    }
	if (g_abKeyPressed[K_RIGHT] && (g_sChar.m_cLocation.X < (g_Console.getConsoleSize().X - 1)))
    {
		bSomethingHappened = true;

		if (Areanum > 0)
		{
			if (Collision(4) == 1)
			{
				g_sChar.m_cLocation.X++;
			}
		}
		else if (Areanum == 0)
		{
			if (CollisionPuzzle(4) == 1)
			{
				g_sChar.m_cLocation.X++;
			}
		}
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

	if (g_eGameState != S_INPUT)
	{
		// quits the game if player hits the escape key
		if (g_abKeyPressed[K_ESCAPE])
		{
			g_bQuitGame = true;
		}

		if (g_abKeyPressed[K_INTERACT])
		{
			bSomethingHappened = true;

			checkF = checkinteract();

			FstandsforFrustrating(checkF);
		}

		if (g_abKeyPressed[K_PAUSE])
		{
			bSomethingHappened = true;

			if (g_eGameState != 4)
			{
				g_eGameState = S_PAUSE;
			}
			else if (g_eGameState == 4)
			{
				clearScreen();

				g_eGameState = S_GAME;
			}
		}

		if (g_abKeyPressed[K_JOURNAL])
		{
			bSomethingHappened = true;

			if (g_eGameState != 3)
			{
				g_eGameState = S_JOURNAL;
			}
			else if (g_eGameState == 3)
			{
				clearScreen();

				g_eGameState = S_GAME;
			}
		}

		if (g_abKeyPressed[K_ENTER])
		{
			bSomethingHappened = true;

			FstandsforFrustrating(9);
		}

		if (isKeyPressed(0x4D))
		{
			PlaySound(NULL, 0, 0);
		}

		if (isKeyPressed(0x4E))
		{
			PlaySound(TEXT("HappyMusic.wav"), NULL, SND_SYNC | SND_LOOP | SND_ASYNC);
		}
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
	c.X = 44;
	g_Console.writeToBuffer(c, "Welcome to Fragments!", 0x03);
	c.Y++;
	c.X = 20;
	g_Console.writeToBuffer(c, "Use the arrow keys to navigate the menu, and press <space> to select them", 0x3);
	c.Y++;
	c.X = 49;
	g_Console.writeToBuffer(c, "Start game", 0x09);
	c.Y++;
	c.X = 45;
	g_Console.writeToBuffer(c, "View instructions", 0x09);

	char Arrow = '>';
	g_Console.writeToBuffer(MenuArrow.Arrow_Location, Arrow);
}

void renderGame()
{
	renderMap();        // renders the map to the buffer first
	renderFeed();		// renders the activity feed to the buffer
	renderCharacter();  // renders the character into the buffer
}

void renderMap()
{
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
    WORD charColor = 0x0A;
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
	g_Console.writeToBuffer(c, "Item in Hand:", 0x07); // for selecting items
	c.X += 15;
	g_Console.writeToBuffer(c, inventory, 0x06);
	c.X = 0; // Reset X to 0 so writing to buffer is normal again.
	c.Y += 1;                                                                                                                       
	g_Console.writeToBuffer(c, "=============================================================================================================", 0x07);
	c.Y += 1;

	actfeed();
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

void pause()
{
	PauseScreen();
}

void renderJournal()
{
	renJournal();
}

void renderInput()
{
	renderInputScreen();
	renderTyping(PlayerInput());
}

void instructions()
{
	InstructScreen();
}