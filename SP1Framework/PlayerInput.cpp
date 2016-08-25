#include "PlayerInput.h"
extern bool g_abKeyPressed[K_COUNT];

void PlayerInput()
{
	string Sentence;

	g_abKeyPressed[K_BACKSPACE] = isKeyPressed(0x08);
	g_abKeyPressed[K_A] = isKeyPressed(0x97);
	g_abKeyPressed[K_B] = isKeyPressed(0x98);
	g_abKeyPressed[K_C] = isKeyPressed(0x99);
	g_abKeyPressed[K_D] = isKeyPressed(0X100);
	g_abKeyPressed[K_E] = isKeyPressed(0x101);
	g_abKeyPressed[K_F] = isKeyPressed(0x102);
	g_abKeyPressed[K_G] = isKeyPressed(0x103);
	g_abKeyPressed[K_H] = isKeyPressed(0x104);
	g_abKeyPressed[K_I] = isKeyPressed(0x105);
	g_abKeyPressed[K_J] = isKeyPressed(0x106);
	g_abKeyPressed[K_K] = isKeyPressed(0x107);
	g_abKeyPressed[K_L] = isKeyPressed(0x108);
	g_abKeyPressed[K_M] = isKeyPressed(0x109);
	g_abKeyPressed[K_N] = isKeyPressed(0x110);
	g_abKeyPressed[K_O] = isKeyPressed(0x111);
	g_abKeyPressed[K_P] = isKeyPressed(0x112);
	g_abKeyPressed[K_Q] = isKeyPressed(0x113);
	g_abKeyPressed[K_R] = isKeyPressed(0x114);
	g_abKeyPressed[K_S] = isKeyPressed(0x115);
	g_abKeyPressed[K_T] = isKeyPressed(0x116);
	g_abKeyPressed[K_U] = isKeyPressed(0x117);
	g_abKeyPressed[K_V] = isKeyPressed(0x118);
	g_abKeyPressed[K_W] = isKeyPressed(0x119);
	g_abKeyPressed[K_X] = isKeyPressed(0x120);
	g_abKeyPressed[K_Y] = isKeyPressed(0x121);
	g_abKeyPressed[K_Z] = isKeyPressed(0x122);


	{
	case K_A:
		return 0;
	}
}