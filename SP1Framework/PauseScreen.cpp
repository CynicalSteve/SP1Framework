#include "PauseScreen.h"

extern Console g_Console;

void PauseScreen()
{
	COORD c;
	c.Y = 10;
	c.X = 52;
	g_Console.writeToBuffer(c, "PAUSE", 0x03);
	c.Y++;
	c.X = 43;
	g_Console.writeToBuffer(c, "Press 'M' to mute music", 0x09);
	c.Y++;
	c.X = 42;
	g_Console.writeToBuffer(c, "Press 'N' to unmute music", 0x09);
}