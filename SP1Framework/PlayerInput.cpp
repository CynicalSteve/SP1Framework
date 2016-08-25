#include "PlayerInput.h"

extern bool g_abKeyPressed[K_COUNT];

string PlayerInput()
{
	string Sentence;

	g_abKeyPressed[K_BACKSPACE] = isKeyPressed(0x08);
	g_abKeyPressed[K_A] = isKeyPressed(0x61);
	g_abKeyPressed[K_B] = isKeyPressed(0x62);
	g_abKeyPressed[K_C] = isKeyPressed(0x63);
	g_abKeyPressed[K_D] = isKeyPressed(0X64);
	g_abKeyPressed[K_E] = isKeyPressed(0x65);
	g_abKeyPressed[K_F] = isKeyPressed(0x66);
	g_abKeyPressed[K_G] = isKeyPressed(0x67);
	g_abKeyPressed[K_H] = isKeyPressed(0x68);
	g_abKeyPressed[K_I] = isKeyPressed(0x69);
	g_abKeyPressed[K_J] = isKeyPressed(0x6A);
	g_abKeyPressed[K_K] = isKeyPressed(0x6B);
	g_abKeyPressed[K_L] = isKeyPressed(0x6C);
	g_abKeyPressed[K_M] = isKeyPressed(0x6D);
	g_abKeyPressed[K_N] = isKeyPressed(0x6E);
	g_abKeyPressed[K_O] = isKeyPressed(0x6F);
	g_abKeyPressed[K_P] = isKeyPressed(0x70);
	g_abKeyPressed[K_Q] = isKeyPressed(0x71);
	g_abKeyPressed[K_R] = isKeyPressed(0x72);
	g_abKeyPressed[K_S] = isKeyPressed(0x73);
	g_abKeyPressed[K_T] = isKeyPressed(0x74);
	g_abKeyPressed[K_U] = isKeyPressed(0x75);
	g_abKeyPressed[K_V] = isKeyPressed(0x76);
	g_abKeyPressed[K_W] = isKeyPressed(0x77);
	g_abKeyPressed[K_X] = isKeyPressed(0x78);
	g_abKeyPressed[K_Y] = isKeyPressed(0x79);
	g_abKeyPressed[K_Z] = isKeyPressed(0x7A);
	g_abKeyPressed[K_ESC] = isKeyPressed(0x1C);
	g_abKeyPressed[K_ENTER] = isKeyPressed(0x03);
	
	for (;;)
	{
		printf("%s", Sentence);

		if (g_abKeyPressed[K_A])
		{
			Sentence.push_back('a');
		}
		else if (g_abKeyPressed[K_B])
		{
			Sentence.push_back('b');
		}
		else if (g_abKeyPressed[K_C])
		{
			Sentence.push_back('c');
		}
		else if (g_abKeyPressed[K_D])
		{
			Sentence.push_back('d');
		}
		else if (g_abKeyPressed[K_E])
		{
			Sentence.push_back('e');
		}
		else if (g_abKeyPressed[K_F])
		{
			Sentence.push_back('f');
		}
		else if (g_abKeyPressed[K_G])
		{
			Sentence.push_back('g');
		}
		else if (g_abKeyPressed[K_H])
		{
			Sentence.push_back('h');
		}
		else if (g_abKeyPressed[K_I])
		{
			Sentence.push_back('i');
		}
		else if (g_abKeyPressed[K_J])
		{
			Sentence.push_back('j');
		}
		else if (g_abKeyPressed[K_K])
		{
			Sentence.push_back('k');
		}
		else if (g_abKeyPressed[K_L])
		{
			Sentence.push_back('l');
		}
		else if (g_abKeyPressed[K_M])
		{
			Sentence.push_back('m');
		}
		else if (g_abKeyPressed[K_N])
		{
			Sentence.push_back('n');
		}
		else if (g_abKeyPressed[K_O])
		{
			Sentence.push_back('o');
		}
		else if (g_abKeyPressed[K_P])
		{
			Sentence.push_back('p');
		}
		else if (g_abKeyPressed[K_Q])
		{
			Sentence.push_back('q');
		}
		else if (g_abKeyPressed[K_R])
		{
			Sentence.push_back('r');
		}
		else if (g_abKeyPressed[K_S])
		{
			Sentence.push_back('s');
		}
		else if (g_abKeyPressed[K_T])
		{
			Sentence.push_back('t');
		}
		else if (g_abKeyPressed[K_U])
		{
			Sentence.push_back('u');
		}
		else if (g_abKeyPressed[K_V])
		{
			Sentence.push_back('v');
		}
		else if (g_abKeyPressed[K_W])
		{
			Sentence.push_back('w');
		}
		else if (g_abKeyPressed[K_X])
		{
			Sentence.push_back('x');
		}
		else if (g_abKeyPressed[K_Y])
		{
			Sentence.push_back('y');
		}
		else if (g_abKeyPressed[K_Z])
		{
			Sentence.push_back('z');
		}
		else if (g_abKeyPressed[K_BACKSPACE])
		{
			if (Sentence.size() > 0)
			{
				Sentence.pop_back();
			}
			else
			{
				continue;
			}
		}
		else if (g_abKeyPressed[K_ESC])
		{
			break;
		}
		else if (g_abKeyPressed[K_ENTER])
		{
			return Sentence;
		}
	}
}