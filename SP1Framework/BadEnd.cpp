#include "BadEnd.h"
#include "Windows.h"
#include "MMSystem.h"

extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern double g_dElapsedTime;
extern double g_dTime;

void BadEnd()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 25;
	c.X = 25;

	if (g_dElapsedTime > g_dTime && g_dElapsedTime < (g_dTime + 5.0))
	{
		g_Console.writeToBuffer(c, "\"We were supposed to escape, the kids, from their dad...\"", 0x0D);
	}
	if (g_dElapsedTime > (g_dTime + 5.0) && g_dElapsedTime < (g_dTime + 10.0))
	{
		g_Console.writeToBuffer(c, "\"How did it go so wrong?\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 10.0) && g_dElapsedTime < (g_dTime + 16.0))
	{
		g_Console.writeToBuffer(c, "\"But at least I tried to protect them, and they are now in a much", 0xD);
		c.Y++;
		g_Console.writeToBuffer(c, "happier place away from that monster.\"", 0x0D);
	}
	if (g_dElapsedTime > (g_dTime + 16.0) && g_dElapsedTime < (g_dTime + 24.0))
	{
		g_Console.writeToBuffer(c, "\"Are you ready, Ava Laurens? Are you ready to move on?\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 24.0) && g_dElapsedTime < (g_dTime + 29.0))
	{
		g_Console.writeToBuffer(c, "\"Yes. Yes, I am. Please take me to where my children are.\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 29.0) && g_dElapsedTime < (g_dTime + 33.0))
	{
		g_Console.writeToBuffer(c, "\"...\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 33.0) && g_dElapsedTime < (g_dTime + 39.0))
	{
		g_Console.writeToBuffer(c, "\"It seems that you aren't prepared yet. How many times are you going", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "to lie to yourself and pull wool over your own eyes?\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 39.0) && g_dElapsedTime < (g_dTime + 43.0))
	{
		g_Console.writeToBuffer(c, "\"What-what are you talking about?\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 43.0) && g_dElapsedTime < (g_dTime + 48.0))
	{
		g_Console.writeToBuffer(c, "\"Memories are but a jigsaw, one must have all the pieces in hand to see", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, " the full picture.\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 48.0) && g_dElapsedTime < (g_dTime + 52.0))
	{
		g_Console.writeToBuffer(c, "\"Now go...\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 52.0) && g_dElapsedTime < (g_dTime + 58.0))
	{
		g_Console.writeToBuffer(c, "An excruciating pain shot through Ava's body, rocking her to her very core.", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "It felt as though her blood had turned into molten lead and her bones were", 0x0F);
		c.Y++;
		g_Console.writeToBuffer(c, "crushed into sand.", 0x0F);
	}
	if (g_dElapsedTime > (g_dTime + 58.0) && g_dElapsedTime < (g_dTime + 63.0))
	{
		g_Console.writeToBuffer(c, "As every fibre of her being shrieked and crumbled, a blood-curdling scream", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "escaped from Ava's lips.", 0x0F);
	}
	if (g_dElapsedTime > (g_dTime + 63.0) && g_dElapsedTime < (g_dTime + 67.0))
	{
		g_Console.writeToBuffer(c, "\"...and repent.\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 72.0) && g_dElapsedTime < (g_dTime + 77.0))
	{
		g_Console.writeToBuffer(c, "And with that, everything cut to black.", 0xF);
	}
	if (g_dElapsedTime > (g_dTime + 77.0))
	{
		c.Y /= 3;
		c.X = g_Console.getConsoleSize().X / 2 - 30;

		g_Console.writeToBuffer(c, " ______              _    ______             _  _", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "(___   \            | |  (______)           | |(_)", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "  ___)   ) _____   __| |   _____   ____    __| | _  ____    ____", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "|  __  ( (____ | / _  |  |  ___) |  _ \  / _  || ||  _ \  / _  |", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "| |__)  )/ ___ |( (_| |  | |____ | | | |( (_| || || | | |( (_| |", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "|______/ \_____| \____|  |______)|_| |_| \____||_||_| |_| \___ |", 0x04);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                         (_____|", 0x04);
		c.Y += 1;
	}
}