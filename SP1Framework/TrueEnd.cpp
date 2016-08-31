#include "TrueEnd.h"
extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern double g_dElapsedTime;
extern double g_dTime;

void TrueEnd()
{
	PlaySound(TEXT("TrueEndMusic.wav"), NULL, SND_SYNC | SND_LOOP | SND_ASYNC);
	COORD c = g_Console.getConsoleSize();

	c.Y = 25;
	c.X = 25;

	if (g_dElapsedTime > g_dTime && g_dElapsedTime < (g_dTime + 4.0))
	{
		g_Console.writeToBuffer(c, "Ava dropped to her knees in complete shock.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 4.0) && g_dElapsedTime < (g_dTime + 8.0))
	{
		g_Console.writeToBuffer(c, "\"I...killed him. I killed Terence...\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 8.0) && g_dElapsedTime < (g_dTime + 12.0))
	{
		g_Console.writeToBuffer(c, "\"Aye. You struck him in the pterion. He died from epidural hematoma hours", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "later in a hospital bed.\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 12.0) && g_dElapsedTime < (g_dTime + 16.0))
	{
		g_Console.writeToBuffer(c, "\"No…\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 16.0) && g_dElapsedTime < (g_dTime + 20.0))
	{
		g_Console.writeToBuffer(c, "\"But before Terrence succumbed to it, you had already taken another", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "two innocent lives with you, haven't you?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 20.0) && g_dElapsedTime < (g_dTime + 24.0))
	{
		g_Console.writeToBuffer(c, "\"Sasha...Jonathan…\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 24.0) && g_dElapsedTime < (g_dTime + 28.0))
	{
		g_Console.writeToBuffer(c, "The coffin suddenly burst open with water which crashed into the ground.", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "The room was starting to fill with water.", 0x0F);
	}
	if (g_dElapsedTime >(g_dTime + 28.0) && g_dElapsedTime < (g_dTime + 32.0))
	{
		g_Console.writeToBuffer(c, "\"Do you know what his family underwent?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 32.0) && g_dElapsedTime < (g_dTime + 36.0))
	{
		g_Console.writeToBuffer(c, "\"Yes, I do.\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 36.0) && g_dElapsedTime < (g_dTime + 40.0))
	{
		g_Console.writeToBuffer(c, "\"Then why, Ava? Why did you become the monster you so detest?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 40.0) && g_dElapsedTime < (g_dTime + 44.0))
	{
		g_Console.writeToBuffer(c, "\"I don't know, why I turned into the splitting image of my father,", 0xD);
		c.Y++;
		g_Console.writeToBuffer(c, "the man so feared and hated.\"", 0x0D);
	}
	if (g_dElapsedTime >(g_dTime + 44.0) && g_dElapsedTime < (g_dTime + 48.0))
	{
		g_Console.writeToBuffer(c, "\"I didn't want this to happen. You are God, right? You can undo all of this right?\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 48.0) && g_dElapsedTime < (g_dTime + 52.0))
	{
		g_Console.writeToBuffer(c, "\"Woe to him who betrays the Son of Man, but salvation to him who seeks penitence.\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 52.0))
	{
		g_Console.writeToBuffer(c, "\"AVA LAURENS, DO YOU REPENT?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 56.0))
	{
		g_Console.writeToBuffer(c, "\"I do.\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 60.0))
	{
		g_Console.writeToBuffer(c, "\"Then thou shalt not be fettered any longer!", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "Leave this hell, and thrust forward unto the light fades!\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 64.0))
	{
		g_Console.writeToBuffer(c, "A white light started to fill Ava’s vision, but it wasn't blinding or intimidating.", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "It was warm, in fact, one that Ava has never felt in a long time.", 0x0F);
	}
	if (g_dElapsedTime >(g_dTime + 68.0))
	{
		g_Console.writeToBuffer(c, "\"Sin, and darkness falls onto thee; Repent, and light will welcome thee into its embrace again!\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 72.0))
	{
		g_Console.writeToBuffer(c, "The warmth spread throughout her body, numbing yet pleasant.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 76.0))
	{
		g_Console.writeToBuffer(c, "The light was getting brighter and brighter. For once, Ava smiled.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 80.0))
	{
		g_Console.writeToBuffer(c, "...", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 84.0))
	{
		g_Console.writeToBuffer(c, "\"Congratulations, it's a girl.\"", 0x03);
	}
	if (g_dElapsedTime >(g_dTime + 88.0))
	{
		g_Console.writeToBuffer(c, "\"Look, Ethan! Here, hold her.\"", 0xC);
	}
	if (g_dElapsedTime >(g_dTime + 92.0))
	{
		g_Console.writeToBuffer(c, "\"She's beautiful, Diana, just like her mother.\"", 0x09);
	}
	if (g_dElapsedTime >(g_dTime + 96.0))
	{
		g_Console.writeToBuffer(c, "The newcomer ceased wailing as her father cradled her in his arms.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 100.0))
	{
		g_Console.writeToBuffer(c, "\"What should we call her, Ethan?\"", 0xC);
	}
	if (g_dElapsedTime >(g_dTime + 104.0))
	{
		g_Console.writeToBuffer(c, "\"...\"", 0x09);
	}
	if (g_dElapsedTime >(g_dTime + 108.0))
	{
		g_Console.writeToBuffer(c, "\"Let's call her...\"", 0x09);
	}
	if (g_dElapsedTime >(g_dTime + 112.0))
	{
		g_Console.writeToBuffer(c, "\"...Ava.\"", 0x09);
	}

}