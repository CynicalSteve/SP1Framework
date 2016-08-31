#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Map.h"
#include "CheckColi.h"
#include "MegaInteract.h"
#include "PuzzleLevels.h"
#include "CheckColiPuzzle.h"
#include "ActFeed.h"
#include "renderInput.h"
#include "PlayerInput.h"
#include "PauseScreen.h"
#include "InstructScreen.h"
#include "AI.h"
#include "AudioPause.h"
#include "BadEnd.h"
#include "TrueEnd.h"
#include "RenderJournal.h"

using namespace std;

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;
void systempause();

// Enumeration to store the control keys that your game will have
enum EKEYS
{
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_INTERACT,
	K_INVENTORY,
	K_ESCAPE,
	K_SPACE,
	K_ENTER,
	K_INVONE,
	K_INVTWO,
	K_INVTHREE,
	K_INVFOUR,
	K_INVFIVE,
	K_INVSIX,
	K_INVSEVEN,
	K_INVEIGHT,
	K_INVNINE,
	K_INVZERO,
	K_PAUSE,
	A_UP,
	A_DOWN,
	A_LEFT,
	A_RIGHT,

	K_BACKSPACE,
	K_ESC,
	K_B,
	K_A,
	K_C,
	K_D,
	K_E,
	K_F,
	K_G,
	K_H,
	K_I,
	K_J,
	K_K,
	K_L,
	K_M,
	K_N,
	K_O,
	K_P,
	K_Q,
	K_R,
	K_S,
	K_T,
	K_U,
	K_V,
	K_W,
	K_X,
	K_Y,
	K_Z,

	K_ONE,
	K_TWO,
	K_THREE,
	K_FOUR,
	K_FIVE,
	K_SIX,
	K_SEVEN,
	K_EIGHT,
	K_NINE,
	K_ZERO,

	K_JOURNAL,
	K_COUNT
};

// Enumeration for the different screen states
enum EGAMESTATES
{
	S_SPLASHSCREEN,
	S_GAME,
	S_INVENTORY,
	S_JOURNAL,
	S_PAUSE,
	S_INPUT,
	S_COUNT,
	S_INSTRUCTIONS,
	S_BADEND,
	S_TRUEEND
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
};

struct Menu
{
	COORD Arrow_Location;
};

void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void renderFeed();			// renders the activity feed
void pause();
void renderJournal();
void renderInput();
void instructions();

#endif // _GAME_H