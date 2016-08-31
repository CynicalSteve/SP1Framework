#include "AI.h"

SGameChar AIAva;

extern Console g_Console;
extern double g_dElapsedTime;
extern double g_dBounceTime;

void renderAI()
{
	// Draw the location of the character
	WORD AIColor = 0x04;
	g_Console.writeToBuffer(AIAva.m_cLocation, (char)64, AIColor);
}

void AImovement(int cordX, int cordY)
{
	bool AIHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	


	if (AIHappened)
	{
		g_dBounceTime = g_dElapsedTime + 0.25;
	}
}