#include "InstructScreen.h"

extern Console g_Console;
extern EGAMESTATES g_eGameState;

void InstructScreen()
{
	COORD c;
	c.Y = 10;
	c.X = 48;
	g_Console.writeToBuffer(c, "INSTRUCTIONS", 0x03);
	c.Y++;
	c.X = 43;
	g_Console.writeToBuffer(c, "Press 'M' to mute music", 0x09);
	c.Y++;
	c.X = 42;
	g_Console.writeToBuffer(c, "Press 'N' to unmute music", 0x09);
	c.Y += 2;
	c.X = 37;
	g_Console.writeToBuffer(c, "Press 'B' to go back to menu screen", 0x08);
	if (isKeyPressed(0x42))
	{
		clearScreen();
		g_eGameState = S_SPLASHSCREEN;
	}
}