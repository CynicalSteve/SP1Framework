#include "CheckColi.h"

bool Collision(int check, int CordX, int CordY)
{
	if (check == 1)
	{
		if (arrmap[CordX][CordY + 1] == ('_' || ',' || '-' || '"' || '`' || '|' || ':' || '/' || '(' || ')' || '\\'))
		{
			return false;
		}
	}

	return true;
}

/*
false = there is collision
true = no collision

g_abKeyPressed[K_UP]     = 1
g_abKeyPressed[K_DOWN]   = 2
g_abKeyPressed[K_LEFT]   = 3
g_abKeyPressed[K_RIGHT]  = 4
*/