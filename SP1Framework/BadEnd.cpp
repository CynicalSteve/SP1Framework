#include "BadEnd.h"
extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern double g_dElapsedTime;
extern double g_dTime;

void BadEnd()
{
	PlaySound(TEXT("BadEndMusic.wav"), NULL, SND_SYNC | SND_LOOP | SND_ASYNC);
	COORD c = g_Console.getConsoleSize();

	c.Y = 25;
	c.X = 25;
	if (g_dElapsedTime > g_dTime && g_dElapsedTime < (g_dTime + 4.0))
	{
		g_Console.writeToBuffer(c, "\"We were supposed to escape, the kids, from their dad…\"", 0x0D);
	}
	if (g_dElapsedTime > (g_dTime + 4.0) && g_dElapsedTime < (g_dTime + 8.0))
	{
		g_Console.writeToBuffer(c, "\"How did it go so wrong?\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 8.0) && g_dElapsedTime < (g_dTime + 12.0))
	{
		g_Console.writeToBuffer(c, "\"But at least I tried to protect them, and they are now in a much happier place away from that monster.\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 12.0) && g_dElapsedTime < (g_dTime + 16.0))
	{
		g_Console.writeToBuffer(c, "\"Are you ready, Ava Laurens? Are you ready to move on?\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 16.0) && g_dElapsedTime < (g_dTime + 20.0))
	{
		g_Console.writeToBuffer(c, "\"Yes. Yes, I am. Please take me to where my children are.\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 20.0) && g_dElapsedTime < (g_dTime + 24.0))
	{
		g_Console.writeToBuffer(c, "\"...\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 24.0) && g_dElapsedTime < (g_dTime + 28.0))
	{
		g_Console.writeToBuffer(c, "\"It seems that you aren’t prepared yet. How many times are you going to lie to yourself and pull wool over your own eyes?\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 28.0) && g_dElapsedTime < (g_dTime + 32.0))
	{
		g_Console.writeToBuffer(c, "\"What-what are you talking about?\"", 0xD);
	}
	if (g_dElapsedTime > (g_dTime + 32.0) && g_dElapsedTime < (g_dTime + 36.0))
	{
		g_Console.writeToBuffer(c, "\"Memories are but a jigsaw, one must have all the pieces in hand to see the full picture.\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 36.0) && g_dElapsedTime < (g_dTime + 40.0))
	{
		g_Console.writeToBuffer(c, "\"Now go...\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 40.0) && g_dElapsedTime < (g_dTime + 44.0))
	{
		g_Console.writeToBuffer(c, "An excruciating pain shot through Ava’s body, rocking her to her very core.It felt as though her blood had turned into molten lead and her bones were crushed into sand.", 0xF);
	}
	if (g_dElapsedTime > (g_dTime + 44.0) && g_dElapsedTime < (g_dTime + 48.0))
	{
		g_Console.writeToBuffer(c, "As every fibre of her being shrieked and crumbled, a blood-curdling scream escaped from Ava’s lips.", 0xF);
	}
	if (g_dElapsedTime > (g_dTime + 48.0) && g_dElapsedTime < (g_dTime + 52.0))
	{
		g_Console.writeToBuffer(c, "\"...and repent.\"", 0x04);
	}
	if (g_dElapsedTime > (g_dTime + 52.0))
	{
		g_Console.writeToBuffer(c, "And with that, everything cut to black.", 0xF);
	}
}