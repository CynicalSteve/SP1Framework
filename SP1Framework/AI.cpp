#include "AI.h"
#include "CheckColiChaseAI.h"

SGameChar AIAva;

extern Console g_Console;

bool restart = false;
int AIcordX, AIcordY, differenceX, differenceY;

double  g_chaseBounceTime;
double  g_chaseElapsedTime;

void renderAI()
{
	// Draw the location of the character
	WORD AIColor = 0x04;
	g_Console.writeToBuffer(AIAva.m_cLocation, (char)64, AIColor);
}

void AImovement(int cordX, int cordY)
{
	bool AIHappened = false;
	if (g_chaseBounceTime > g_chaseElapsedTime)
		return;

	AIcordX = AIAva.m_cLocation.X;
	AIcordY = AIAva.m_cLocation.Y;
	differenceX = cordX - AIcordX;
	differenceY = cordY - AIcordY;

	if ((AIcordX == cordX) && (AIcordY == cordY))
	{
		restart = true;

		AIAva.m_cLocation.X = g_Console.getConsoleSize().X - 109;
		AIAva.m_cLocation.Y = g_Console.getConsoleSize().Y - 29;
	}
	else
	{
		if ((differenceX > 0) && (CollisionChaseAI(4) == 1))
		{
			AIHappened = true;
			AIAva.m_cLocation.X++;
		}
		else if ((differenceX < 0) && (CollisionChaseAI(3) == 1))
		{
			AIHappened = true;
			AIAva.m_cLocation.X--;
		}

		if ((differenceY > 0) && (CollisionChaseAI(2) == 1))
		{
			AIHappened = true;
			AIAva.m_cLocation.Y++;
		}
		else if ((differenceY < 0) && (CollisionChaseAI(1) == 1))
		{
			AIHappened = true;
			AIAva.m_cLocation.Y--;
		}
	}


	if (AIHappened)
	{
		g_chaseBounceTime = g_chaseElapsedTime + 0.15;
	}
}