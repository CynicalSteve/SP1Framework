#include "BadEnd.h"
extern Console g_Console;

void BadEnd()
{
	COORD c;
	
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


}