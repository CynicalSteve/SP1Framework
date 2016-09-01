#include "TrueEnd.h"
extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern double g_dElapsedTime;
extern double g_dTime;

void TrueEnd()
{
	COORD c = g_Console.getConsoleSize();

	c.Y = 25;
	c.X = 25;

	if (g_dElapsedTime > g_dTime && g_dElapsedTime < (g_dTime + 4.0))
	{
		g_Console.writeToBuffer(c, "Ava dropped to her knees in complete shock.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 4.0) && g_dElapsedTime < (g_dTime + 10.0))
	{
		g_Console.writeToBuffer(c, "\"I...killed him. I killed Terence...\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 10.0) && g_dElapsedTime < (g_dTime + 16.0))
	{
		g_Console.writeToBuffer(c, "\"Aye. You struck him in the pterion. He died from epidural hematoma hours", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "later in a hospital bed.\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 16.0) && g_dElapsedTime < (g_dTime + 20.0))
	{
		g_Console.writeToBuffer(c, "\"No...\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 20.0) && g_dElapsedTime < (g_dTime + 25.0))
	{
		g_Console.writeToBuffer(c, "\"But before Terrence succumbed to it, you had already taken another", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "two innocent lives with you, haven't you?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 25.0) && g_dElapsedTime < (g_dTime + 30.0))
	{
		g_Console.writeToBuffer(c, "\"Sasha...Jonathan...\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 30.0) && g_dElapsedTime < (g_dTime + 36.0))
	{
		g_Console.writeToBuffer(c, "The coffin suddenly burst open with water which spilled onto the ground.", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "The room was starting to fill with water.", 0x0F);
	}
	if (g_dElapsedTime >(g_dTime + 36.0) && g_dElapsedTime < (g_dTime + 41.0))
	{
		g_Console.writeToBuffer(c, "\"Do you know what his family underwent?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 41.0) && g_dElapsedTime < (g_dTime + 45.0))
	{
		g_Console.writeToBuffer(c, "\"Yes, I do.\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 45.0) && g_dElapsedTime < (g_dTime + 51.0))
	{
		g_Console.writeToBuffer(c, "\"Then why, Ava? Why did you become the monster you so detest?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 51.0) && g_dElapsedTime < (g_dTime + 57.0))
	{
		g_Console.writeToBuffer(c, "\"I don't know, why I turned into the splitting image of my father,", 0xD);
		c.Y++;
		g_Console.writeToBuffer(c, "the man I so feared and hated.\"", 0x0D);
	}
	if (g_dElapsedTime >(g_dTime + 57.0) && g_dElapsedTime < (g_dTime + 63.0))
	{
		g_Console.writeToBuffer(c, "\"I didn't want this to happen! You are God, right? You can undo all of this right?\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 63.0) && g_dElapsedTime < (g_dTime + 69.0))
	{
		g_Console.writeToBuffer(c, "\"Woe to him who betrays the Son of Man, but salvation to him who seeks penitence.\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 69.0) && g_dElapsedTime < (g_dTime + 73.0))
	{
		g_Console.writeToBuffer(c, "\"AVA LAURENS, DO YOU REPENT?\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 73.0) && g_dElapsedTime < (g_dTime + 77.0))
	{
		g_Console.writeToBuffer(c, "\"I do.\"", 0xD);
	}
	if (g_dElapsedTime >(g_dTime + 77.0) && g_dElapsedTime < (g_dTime + 83.0))
	{
		g_Console.writeToBuffer(c, "\"Then thou shalt not be fettered any longer!", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "Leave this hell, and thrust forward unto the light fades!\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 83.0) && g_dElapsedTime < (g_dTime + 89.0))
	{
		g_Console.writeToBuffer(c, "A white light started to fill Ava's vision, but it wasn't blinding or intimidating.", 0xF);
		c.Y++;
		g_Console.writeToBuffer(c, "It was warm, in fact, one that Ava has never felt in a long time.", 0x0F);
	}
	if (g_dElapsedTime >(g_dTime + 89.0) && g_dElapsedTime < (g_dTime + 95.0))
	{
		g_Console.writeToBuffer(c, "\"Sin, and darkness falls onto thee;", 0x04);
		c.Y++;
		g_Console.writeToBuffer(c, "Repent, and light will welcome thee into its embrace again!\"", 0x04);
	}
	if (g_dElapsedTime >(g_dTime + 95.0) && g_dElapsedTime < (g_dTime + 100.0))
	{
		g_Console.writeToBuffer(c, "The warmth spread throughout her body, numbing yet pleasant.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 100.0) && g_dElapsedTime < (g_dTime + 105.0))
	{
		g_Console.writeToBuffer(c, "The light was getting brighter and brighter. For once, Ava smiled.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 105.0) && g_dElapsedTime < (g_dTime + 110.0))
	{
		g_Console.writeToBuffer(c, "...", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 110.0) && g_dElapsedTime < (g_dTime + 115.0))
	{
		g_Console.writeToBuffer(c, "\"Congratulations, it's a girl.\"", 0x03);
	}
	if (g_dElapsedTime >(g_dTime + 115.0) && g_dElapsedTime < (g_dTime + 120.0))
	{
		g_Console.writeToBuffer(c, "\"Look, Ethan! Here, hold her.\"", 0xC);
	}
	if (g_dElapsedTime >(g_dTime + 120.0) && g_dElapsedTime < (g_dTime + 126.0))
	{
		g_Console.writeToBuffer(c, "\"Oh, she's beautiful Diana! Just like her mother!\"", 0x09);
	}
	if (g_dElapsedTime >(g_dTime + 126.0) && g_dElapsedTime < (g_dTime + 132.0))
	{
		g_Console.writeToBuffer(c, "The newcomer ceased her wailing as her father cradled her in his arms.", 0xF);
	}
	if (g_dElapsedTime >(g_dTime + 132.0) && g_dElapsedTime < (g_dTime + 137.0))
	{
		g_Console.writeToBuffer(c, "\"What should we call her, Ethan?\"", 0xC);
	}
	if (g_dElapsedTime >(g_dTime + 137.0) && g_dElapsedTime < (g_dTime + 142.0))
	{
		g_Console.writeToBuffer(c, "\"...\"", 0x09);
	}
	if (g_dElapsedTime >(g_dTime + 142.0) && g_dElapsedTime < (g_dTime + 146.0))
	{
		g_Console.writeToBuffer(c, "\"Let's call her...\"", 0x09);
	}
	if (g_dElapsedTime >(g_dTime + 146.0) && g_dElapsedTime < (g_dTime + 152.0))
	{
		g_Console.writeToBuffer(c, "\"...Ava.\"", 0x09);
	}
	if (g_dElapsedTime > (g_dTime + 152.0))
	{
		g_Console.writeToBuffer(c, " _______                      ______             _  _", 0x0B);
		c.Y++;
		g_Console.writeToBuffer(c, "(_______)                    (______)           | |(_)", 0x0B);
		c.Y++;
		g_Console.writeToBuffer(c, "    _    ___  _   _  _____    _____   ____    __| | _  ____    ____", 0x0B);
		c.Y++;
		g_Console.writeToBuffer(c, "   | |  / __)| | | || ___ |  |  ___) |  _ \\  / _  || ||  _ \\  / _  |", 0x0B);
		c.Y++;
		g_Console.writeToBuffer(c, "   | | | |   | |_| || ____|  | |____ | | | |( (_| || || | | |( (_| |", 0x0B);
		c.Y++;
		g_Console.writeToBuffer(c, "   |_| |_|   |____/ |_____)  |______)|_| |_| \\____||_||_| |_| \\___ |", 0x0B);
		c.Y++;
		g_Console.writeToBuffer(c, "                                                             (_____|", 0x0B);
	}
}