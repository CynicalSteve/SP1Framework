#include "AI.h"

SGameChar AIAva;

extern Console g_Console;

void renderAI()
{
	// Draw the location of the character
	WORD AIColor = 0x04;
	g_Console.writeToBuffer(AIAva.m_cLocation, (char)64, AIColor);
}

void AImovement(int cordX, int cordY)
{

}