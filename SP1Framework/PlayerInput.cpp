#include "PlayerInput.h"

using namespace std;

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern double g_dElapsedTime;
extern double g_dBounceTime;

string Sentence;

string PlayerInput(void)
{
	bool SomethangHappund = false;
	if (g_dBounceTime > g_dElapsedTime)
		return Sentence;

		if (g_abKeyPressed[K_A])
		{
			Sentence.push_back('a');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_B])
		{
			Sentence.push_back('b');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_C])
		{
			Sentence.push_back('c');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_D])
		{
			Sentence.push_back('d');
			SomethangHappund = true;
		}

	    if (g_abKeyPressed[K_E])
		{
			Sentence.push_back('e');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_F])
		{
			Sentence.push_back('f');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_G])
		{
			Sentence.push_back('g');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_H])
		{
			Sentence.push_back('h');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_I])
		{
			Sentence.push_back('i');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_J])
		{
			Sentence.push_back('j');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_K])
		{
			Sentence.push_back('k');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_L])
		{
			Sentence.push_back('l');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_M])
		{
			Sentence.push_back('m');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_N])
		{
			Sentence.push_back('n');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_O])
		{
			Sentence.push_back('o');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_P])
		{
			Sentence.push_back('p');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_Q])
		{
			Sentence.push_back('q');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_R])
		{
			Sentence.push_back('r');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_S])
		{
			Sentence.push_back('s');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_T])
		{
			Sentence.push_back('t');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_U])
		{
			Sentence.push_back('u');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_V])
		{
			Sentence.push_back('v');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_W])
		{
			Sentence.push_back('w');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_X])
		{
			Sentence.push_back('x');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_Y])
		{
			Sentence.push_back('y');
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_Z])
		{
			Sentence.push_back('z');
			SomethangHappund = true;
		}

		if ((g_abKeyPressed[K_BACKSPACE]) && (Sentence.size() > 0))
		{
			Sentence.pop_back();
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_ESC])
		{
			g_eGameState = S_GAME;
			SomethangHappund = true;
		}

		if (g_abKeyPressed[K_ENTER])
		{
			return " ";
		}

		if (SomethangHappund)
		{
			g_dBounceTime = g_dElapsedTime + 0.125;
		}

		return Sentence;
}