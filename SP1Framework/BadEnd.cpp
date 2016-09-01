#include "BadEnd.h"
#include "Windows.h"
#include "MMSystem.h"

extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern double g_dElapsedTime;
extern double g_dTime;
extern double g_dElapsedTimeTemp;
extern int InPortal;
extern int EssentialFragment;
extern int OptionalFragment;
extern int Factfeed;
extern int reqinteraction;

int finishedgame = 0;

void BadEnd()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 25;
	c.X = 25;

	if (g_dElapsedTime > g_dTime && g_dElapsedTime < (g_dTime + 5.0))
	{
		g_Console.writeToBuffer(c, "\"We were supposed to escape, the kids, from their dad...\"", 0x0D);
	}
	if (g_dElapsedTime > (g_dTime + 5.0) && g_dElapsedTime < (g_dTime + 9.0))
	{
		g_Console.writeToBuffer(c, "\"How did it go so wrong?\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 9.0) && g_dElapsedTime < (g_dTime + 18.0))
	{
		g_Console.writeToBuffer(c, "\"But at least I tried to protect them, and they are now in a much", 0xD);
		c.Y++;
		g_Console.writeToBuffer(c, "happier place away from that monster.\"", 0x0D);
	}
	if (g_dElapsedTime > (g_dTime + 18.0) && g_dElapsedTime < (g_dTime + 23.0))
	{
		g_Console.writeToBuffer(c, "\"Are you ready, Ava Laurens? Are you ready to move on?\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 23.0) && g_dElapsedTime < (g_dTime + 28.0))
	{
		g_Console.writeToBuffer(c, "\"Yes. Yes, I am. Please take me to where my children are.\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 28.0) && g_dElapsedTime < (g_dTime + 31.0))
	{
		g_Console.writeToBuffer(c, "\"...\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 31.0) && g_dElapsedTime < (g_dTime + 39.0))
	{
		g_Console.writeToBuffer(c, "\"It seems that you aren't prepared yet. How many times are you going", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "to lie to yourself and pull wool over your own eyes?\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 39.0) && g_dElapsedTime < (g_dTime + 44.0))
	{
		g_Console.writeToBuffer(c, "\"What-what are you talking about?\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 44.0) && g_dElapsedTime < (g_dTime + 51.0))
	{
		g_Console.writeToBuffer(c, "\"Memories are but a jigsaw, one must have all the pieces in hand to see", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "the full picture.\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 51.0) && g_dElapsedTime < (g_dTime + 54.0))
	{
		g_Console.writeToBuffer(c, "\"Now go...\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 54.0) && g_dElapsedTime < (g_dTime + 65.0))
	{
		g_Console.writeToBuffer(c, "An excruciating pain shot through Ava's body, rocking her to her very core.", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "It felt as though her blood had turned into molten lead and her bones were", 0x0F);
		c.Y++;
		g_Console.writeToBuffer(c, "crushed into sand.", 0x0F);
	}
	if (g_dElapsedTime > (g_dTime + 65.0) && g_dElapsedTime < (g_dTime + 72.0))
	{
		g_Console.writeToBuffer(c, "As every fibre of her being shrieked and crumbled, a blood-curdling scream", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "escaped from Ava's lips.", 0x0F);
	}
	if (g_dElapsedTime > (g_dTime + 72.0) && g_dElapsedTime < (g_dTime + 75.0))
	{
		g_Console.writeToBuffer(c, "\"...and repent.\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 79.0) && g_dElapsedTime < (g_dTime + 84.0))
	{
		g_Console.writeToBuffer(c, "And with that, everything cut to black.", 0xF);
	}
	if (g_dElapsedTime > (g_dTime + 86.0))
	{
		g_Console.writeToBuffer(c, " ______              _    ______             _  _", 0x0C);
		c.Y += 1;
		g_Console.writeToBuffer(c, "(___   \\            | |  (______)           | |(_)", 0x0C);
		c.Y += 1;
		g_Console.writeToBuffer(c, " ___)   ) _____   __| |   _____   ____    __| | _  ____    ____", 0x0C);
		c.Y += 1;
		g_Console.writeToBuffer(c, "|  __  ( (____ | / _  |  |  ___) |  _ \\  / _  || ||  _ \\  / _  |", 0x0C);
		c.Y += 1;
		g_Console.writeToBuffer(c, "| |__)  )/ ___ |( (_| |  | |____ | | | |( (_| || || | | |( (_| |", 0x0C);
		c.Y += 1;
		g_Console.writeToBuffer(c, "|______/ \\_____| \\____|  |______)|_| |_| \\____||_||_| |_| \\___ |", 0x0C);
		c.Y += 1;
		g_Console.writeToBuffer(c, "                                                         (_____|", 0x0C);
		c.Y += 5;
		g_Console.writeToBuffer(c, "Press 'R' to restart game", 0x06);
		if (isKeyPressed(0x52))
		{
			clearScreen();
			finishedgame = 1;
			reqinteraction = 0;
			Factfeed = 0;
			InPortal = 0;
			g_dTime = 999.0;
			g_dElapsedTimeTemp = 999.0;
			EssentialFragment = 0;
			OptionalFragment = 0;
			init();
		}
		c.Y = 48;
		c.X = 1;
		g_Console.writeToBuffer(c, "<Fragments>", 0x09);
		c.Y++;
		g_Console.writeToBuffer(c, "Done By Group 8", 0x09);
		c.Y++;
		g_Console.writeToBuffer(c, "Steven", 0x09);
		c.Y++;
		g_Console.writeToBuffer(c, "Joanne", 0x09);
		c.Y++;
		g_Console.writeToBuffer(c, "Edward", 0x09);
		c.Y++;
		g_Console.writeToBuffer(c, "Mingxiu", 0x09);
	}
}