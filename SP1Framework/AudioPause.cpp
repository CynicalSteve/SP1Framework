#include "AudioPause.h"

extern Console g_Console;

void audioPause()
{
	COORD c = g_Console.getConsoleSize();
	c.Y /= 3;
	c.X = 52;
	g_Console.writeToBuffer(c, "PAUSE", 0x03);
	c.Y++;
	c.X = 40;
	g_Console.writeToBuffer(c, "Press 'P' again to resume game", 0x09);
	c.Y++;
	c.X = 43;
	g_Console.writeToBuffer(c, "Press 'M' to mute music", 0x09);
	c.Y++;
	c.X = 42;
	g_Console.writeToBuffer(c, "Press 'N' to unmute music", 0x09);
}