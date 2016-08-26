#include "ActFeed.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern std::string inventory;
extern int Factfeed;
extern double g_dElapsedTime;
extern double g_dElapsedTimeTemp;
extern double g_dTime;
extern int InPortal;
extern int Areanum;
extern int levelfinish;
extern int OptionalFragment;
extern int EssentialFragment;
extern int reqinteraction;

void actfeed()
{
	int tempcoords;            // Used to hold the value of c.Y in activity feed

	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 31;


	if (Areanum == 1 && EssentialFragment == 0 && OptionalFragment == 0)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "Use WASD keys to move around, F key to interact and E to enter/use.", 0x05);
		c.Y++;
		g_Console.writeToBuffer(c, "\"Wha-What is this place?\"", 0x02);
		c.Y++;

		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "I looked about confused and wide-eyed.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 2.0))
		{
			g_Console.writeToBuffer(c, "A verdant grassy plain laid out before me while the sea behind me rolled and crashed into the shores of the", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "beach I was standing in.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 6.0))
		{
			g_Console.writeToBuffer(c, "Trees which bordered the plains crackled as a cold breeze blew across the island. Seagulls overhead screamed", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "in response.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Despite so much looking around, my surroundings didn't provide a single clue as to where I am or how I got", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "here... or who I was.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 14.0))
		{
			g_Console.writeToBuffer(c, "Wait a minute, I think I got something...", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 16.0))
		{
			g_Console.writeToBuffer(c, "A...Av...Ava? Ava...Laurens?", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 18.0)) 
		{
			g_Console.writeToBuffer(c, "Is that my name?", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 20.0))
		{
			g_Console.writeToBuffer(c, "\"Ava Laurens.\" The name sounds much clearer now, it has to be mine.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 23.0))
		{
			g_Console.writeToBuffer(c, "I should take a look around, since being a sitting duck here would do me no good.", 0x02);
			c.Y++;
		}
	}

	if (InPortal == 1)
	{
		c.Y = 31;

		if (inventory == "A flat stone")
		{
			g_Console.writeToBuffer(c, "Flat Stone has been added to your inventory.", 0x03);
			c.Y++;
		}
	}

	if (InPortal == 2 || InPortal == 12)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "No matter how strong one is, with too heavy a burden they will     .", 0x06);
		c.X += 63;
		g_Console.writeToBuffer(c, "sink", 0x05);
		c.Y++;

		c.X = 0;

		if (inventory == "a stone filled fish")
		{
			g_Console.writeToBuffer(c, "A stone filled fish has been added to your inventory.", 0x03);
		}

		if (levelfinish == 2)
		{
			g_Console.writeToBuffer(c, "\"Easy, isn't it? After all, you've had a lot of practice...\".", 0x06);
		}
	}

	if (InPortal == 3 || InPortal == 13)
	{
		c.Y = 31;

		if (inventory == "Odd black sphere")
		{
			g_Console.writeToBuffer(c, "Odd black sphere has been added to your inventory.", 0x03);
		}

		if (inventory == "A ring")
		{
			g_Console.writeToBuffer(c, "A ring has been added to your inventory.", 0x03);
		}
	}

	if (InPortal == 4)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "You blame your problems on the past, so why not come back to where it all began and reverse your actions?", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Change the negative present, into a positive yesterday.", 0x05);
	}

	if (InPortal == 6)
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "\"You’ve always resented him for this. Doubting his intentions.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Do you know how it feels to be doubted despite having good intentions? It feels horrible.\"", 0x06);
		c.Y++;

		if (levelfinish == 6)
		{
			g_Console.writeToBuffer(c, "\"Maybe you are. But does it really matter? The scars are still there.\"", 0x06);
		}
	}

	if (InPortal == 15) // TBD what we do with this
	{
		c.Y = 31;

		g_Console.writeToBuffer(c, "A familiar place. It has been quite a tiring journey, hasn't it?", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Oh, sorry Ava, I'm not talking about you. The box, on your bed, is tired.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Why don't you tuck it in? You could even care for this box more than your actual children.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "You can even put hearts over it and name it the companion cube.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Oh, your first act of defiance. I guess showing you your old bedroom brought your maturity back too.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Alright then, you don't want to tuck a box in, I'll turn it into a replica of you.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Its a replica of when you were lashing out at Terrence and broke a bottle to cut him.", 0x06);
		c.Y++;
		g_Console.writeToBuffer(c, "Oh, and she thinks you're Terrence. Have fun!", 0x06);
	}

	if (Factfeed == 912) // EF 1
	{
		c.Y = 31;
		g_Console.writeToBuffer(c, "\"First, you get the flattest rock you can find like this one,\" he said, brandishing the stone he just", 0x03);
		c.Y++;
		g_Console.writeToBuffer(c, "picked up from the ground.", 0x03);
		c.Y++;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Next, you aim it at an angle like so...\", he continued, \"while adding a little spin to it, you throw", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "as hard as you can.\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 3.0))
		{
			g_Console.writeToBuffer(c, "At the last word of his sentence, he hurled the stone towards the lake.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 5.0))
		{
			g_Console.writeToBuffer(c, "It skipped five times across the surface of the water before plopping into the depths below.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 8.0))
		{
			g_Console.writeToBuffer(c, "\"Now you try it,\" he said with a proud look on his face.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "I wrinkled my nose at him, before grabbing a stone from the ground and tossed it at the lake.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 14.0))
		{
			g_Console.writeToBuffer(c, "It skipped eight times on the surface before sinking.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 16.0))
		{
			g_Console.writeToBuffer(c, "He stared at me in disbelief, \"Damn Ava, nice throw!\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 18.0))
		{
			g_Console.writeToBuffer(c, "\"Or maybe you're just bad at it,\" I snorted.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 20.0))
		{
			g_Console.writeToBuffer(c, "His eyes twinkled mischievously.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 21.0))
		{
			g_Console.writeToBuffer(c, "\"Oh yeah? I'll show you something I'm not bad at!\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 23.0))
		{
			g_Console.writeToBuffer(c, "He raced towards me and slung me over his shoulder. He then ran towards the treeline with us both,", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "laughing the whole time.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 27.0))
		{
			g_Console.writeToBuffer(c, "Startled, I jumped backwards.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 28.0))
		{
			g_Console.writeToBuffer(c, "\"What in the world was that?\"", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 29.0))
		{
			g_Console.writeToBuffer(c, "That man seemed so familiar, as if I've known him for all my life.", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 31.0))
		{
			g_Console.writeToBuffer(c, "Perhaps that was some kind of memory? If I enter more of those portals, will I get my memory back?", 0x02);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 34.0))
		{
			g_Console.writeToBuffer(c, "I guess I better find out.", 0x02);
		}
	}

	if (Factfeed == 914) // OF 1
	{
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
		if (g_dElapsedTime > (g_dTime + 5.0))
		{
			g_Console.writeToBuffer(c, "\"Oh really?\" Ava said, glaring at the direction the girl went. \"Don't speak to her ever again.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 8.0))
		{
			g_Console.writeToBuffer(c, "\"What? But-\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "\"If you love me, never talk to her again. You do love me, right?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 11.0))
		{
			g_Console.writeToBuffer(c, "\"...Yes, I do.\"", 0x03);
		}
	}

	if (Factfeed == 923) // EF 2
	{
		c.Y = 31;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Terence, do you take Ava as your lawfully wedded wife, to have and to hold, from this day forward, for", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "better or for worse, for richer or for poorer, in sickness and in health, to love and cherish until", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "death do you part?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "\"I do.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "\"Ava, do you take Terence as your lawfully wedded husband, to have and to hold, from this day forward, for", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "better or for worse, for richer or for poorer, in sickness and in health, to love and cherish until", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "death do you part?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 19.0))
		{
			g_Console.writeToBuffer(c, "\"I do.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 20.0))
		{
			g_Console.writeToBuffer(c, "\"Bride and Groom, you have heard the words about love and marriage, have exchanged your vows and made", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "your promises, and celebrated your union with the giving and receiving of rings. Therefore, it is my", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "pleasure at this time that I now pronounce you Man and Wife. You may now kiss the bride.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 30.0))
		{
			g_Console.writeToBuffer(c, "And thus our lips met to the roar of applause from our families. Happiness would be an understatement!", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 34.0))
		{
			g_Console.writeToBuffer(c, "Finally, my mother would stop nagging me about getting married!", 0x03);
		}
	}


	if (Factfeed == 926) //OF 2
	{
		c.Y = 34;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Hey babe,\" Terence whispered, wrapping a warm arm around Ava.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 3.0))
		{
			g_Console.writeToBuffer(c, "\"Yeah?\" Ava responded.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 4.0))
		{
			g_Console.writeToBuffer(c, "\"So um, I'm thinking of joining a startup tech company. It's set up by a friend and he's reaching out", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "to me for a place there.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 8.0))
		{
			g_Console.writeToBuffer(c, "\"What's wrong with your current job?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "\"Well, you know I can't say no babe, he's my friend.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 11.0))
		{
			g_Console.writeToBuffer(c, "\"We'll have to move, don't we?\" Ava sighed.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 12.0))
		{
			g_Console.writeToBuffer(c, "\"Yeah, and I've already found a nice place downtown. It's got a nice view and-\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 15.0))
		{
			g_Console.writeToBuffer(c, "\"Yeah, yeah whatever. You're such a pansy Terence. Learn to say no, you idiot.\"", 0x03);
		}
	}

	if (Factfeed == 991) //EF 3
	{
		c.Y = 34;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Have you ever seen a creature this bizarre? I mean it's pretty much a mermaid lion,\" Terence said as", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "he snapped a picture of the merlion statue.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 5.0))
		{
			g_Console.writeToBuffer(c, "\"Singapore's a pretty superstitious country after all, or at least in the past it used to be,\" I said,", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "glancing at the hoards of tourists around us.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, "\"But it's a beautiful country. I wonder what it takes to raise our children in such a place.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 13.0))
		{
			g_Console.writeToBuffer(c, "As I stroked my protruding belly, I could've sworn I felt the little one kick in agreement.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 14.0))
		{
			g_Console.writeToBuffer(c, "Terence chuckled as he took more photos. He always had an interest in photography.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 15.0))
		{
			g_Console.writeToBuffer(c, "\"I would like to,\" he responded, \"if only the prices here weren't as high as its skyscrapers.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 19.0))
		{
			g_Console.writeToBuffer(c, "\"How long are you gonna keep taking those photos?\" I said, furiously fanning myself with the pamphlets", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "and maps I was holding.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 23.0))
		{
			g_Console.writeToBuffer(c, "\"Hang on, just one more picture...\" he replied, aiming the camera at me.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 26.0))
		{
			g_Console.writeToBuffer(c, "\"SNAP!", 0x03);
		}
	}

	if (Factfeed == 992) //OF 3
	{
		c.Y = 31;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Where have you been?\" Ava asked impatiently, her arms crossed and her eyebrows stitched into a frown.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 3.0))
		{
			g_Console.writeToBuffer(c, "Overtime down at the company.\" Terence replied while grabbing a beer from the refrigerator.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 6.0))
		{
			g_Console.writeToBuffer(c, "\"You sure? You sure you're not humping some colleague while everyone's gone?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "Terence froze, startled by her accusation.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 11.0))
		{
			g_Console.writeToBuffer(c, "\"What are you-why would you say something like that, Ava?\" Terence asked, obviously hurt by her words.", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 15.0))
		{
			g_Console.writeToBuffer(c, "Ava merely scoffed, before returning back to their bedroom.", 0x03);
		}
	}


	if (Factfeed == 993) // EF 4
	{
		c.Y = 31;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"Ah, Mrs Laurens! Fancy meeting you here!\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 2.0))
		{
			g_Console.writeToBuffer(c, "It was our neighbour, Mrs Lindow.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 4.0))
		{
			g_Console.writeToBuffer(c, "\"Mrs Lindow, so great to see you here! How have you been?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 7.0))
		{
			g_Console.writeToBuffer(c, "\"Good! Are you walking your kids home from the grocery store?\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 10.0))
		{
			g_Console.writeToBuffer(c, " \"Yes,\" I said, \"this is Sasha, 11, and her brother Jonathan, 9. Say hi to Mrs Lindow, children.\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 15.0))
		{
			g_Console.writeToBuffer(c, "They remained silent however, with their eyes glued to the ground.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 18.0))
		{
			g_Console.writeToBuffer(c, "\"Ah, pardon their rudeness. They must be shy meeting someone new after moving here.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 21.0))
		{
			g_Console.writeToBuffer(c, "\"Ohohoho, nothing to worry,\" she said. \"I must get going now, see you later!\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 25.0))
		{
			g_Console.writeToBuffer(c, "\"Bye,\" I said, waving as she continued down the pavement.", 0x03);
		}
	}



	if (Factfeed == 994) // EF 5
	{
		c.Y = 31;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "\"So Ava, I heard that the company Terence was working in became bankrupt. Are you two holding up", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "alright?\" Matilda Lindow, the neighbour, asked.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 4.0))
		{
			g_Console.writeToBuffer(c, "\"I-um, well, uh...\" I stuttered. \"We owe a few people some money, that's all. No big deal, Matilda\".", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "\"Sweetie.\" Matilda said, cupping my hands in hers. \"I know a liar when I see one. How do you think", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "I can keep Danny as my husband all these years? Please, tell me what's wrong.\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 17.0))
		{
			g_Console.writeToBuffer(c, "My eyes went misty as tears formed in the corner of my eyes. \"It-It's just that recently Terence has", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "been coming home really late drunk, and then he just starts yelling and screaming. One night, I smelt", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "perfume on him and... and...\"", 0x03);
			c.Y++;
		}
		if (g_dElapsedTime > (g_dTime + 27.0))
		{
			g_Console.writeToBuffer(c, "The tears had already cascaded down my cheeks, but I wiped them off with my forearm and regained", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "my composure.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 32.0))
		{
			g_Console.writeToBuffer(c, "\"It's nothing,\" I said, smiling.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 34.0))
		{
			g_Console.writeToBuffer(c, "Matilda had been staring at me intensely. \"Dear, if you need anything... Good Lord, are those..?!\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 37.0))
		{
			g_Console.writeToBuffer(c, "I realised that she had spotted the bruises and burn marks on my right thigh, so I swiftly pulled down", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "the hem of my skirt.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 42.0))
		{
			g_Console.writeToBuffer(c, "\"I-um, really have to get going now,\" I said quickly while standing up from the sofa just as fast.", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "\"Thank you for having me he-\"", 0x03);
			c.Y += 2;
		}
		if (c.Y >= 54)
		{
			c.Y = 31;
		}
		if (g_dElapsedTime > (g_dTime + 48.0))
		{
			g_Console.writeToBuffer(c, "\"Ava,\" Matilda interrupted, her eyes burning with anger. \"If that man dares to lay a finger on you", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "or your children, promise that you'll holler. I'll send the cops on his ass so fast that he won't even", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "see it coming\"", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 55.0))
		{
			g_Console.writeToBuffer(c, "I feigned a smile.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 56.0))
		{
			g_Console.writeToBuffer(c, "\"I will.\"", 0x03);
		}
	}

	if (Factfeed == 995) // OF 5
	{
		c.Y = 31;
		if (g_dElapsedTime > g_dTime)
		{
			g_Console.writeToBuffer(c, "As Ava sat on the couch in her living room, she grabbed some makeup accessories and went to work with", 0x03);
			c.Y++;
			g_Console.writeToBuffer(c, "them, drawing what looks like bruises and burn marks on her thighs.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 6.0))
		{
			g_Console.writeToBuffer(c, "Perfect, she thought, Now all I need is an idiot for me to become a \"victim\".", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 9.0))
		{
			g_Console.writeToBuffer(c, "Ava picked up the telephone and punched in some numbers.", 0x03);
			c.Y += 2;
		}
		if (g_dElapsedTime > (g_dTime + 12.0))
		{
			g_Console.writeToBuffer(c, "\"Hi Matilda? Are you free this afternoon?\"", 0x03);
		}
	}

	/* Template for MX
	if (c.Y == 54)
	{
	c.Y = 31;
	}
	if (g_dElapsedTime > 9.0)
	{
	g_Console.writeToBuffer(c, "                                                                                                             ", 0x02);
	g_Console.writeToBuffer(c, "Name", 0x04);
	c.Y += 1;
	}
	*/


	if (Factfeed > 0)
	{
		tempcoords = c.Y;
		c.Y = 24;

		switch (Factfeed)
		{
		case 1:
			g_Console.writeToBuffer(c, "Theres a wooden boat in the distance leaning against a couple rocks.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Theres a giant hole in its hull so I doubt its usability.", 0x02);
			break;
		case 2:
			g_Console.writeToBuffer(c, "The trees are swaying in harmony with the wind.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Their leaves seem to have a weird shade of dark green.", 0x02);
			break;
		case 3:
			g_Console.writeToBuffer(c, "It looks and feels like some sort of portal. It pulsates with a strange light-blue energy but oddly enough", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I don't feel intimidated by it at all. Instead, it feels like it's drawing me in. Should I enter it?", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to enter the portal.", 0x05);
			break;
		case 11: // Lake Stones
			g_Console.writeToBuffer(c, "A stack of stones. Having one of them may come in handy.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to pick a stone up.", 0x05);
			break;
		case 12: // Lake water
			g_Console.writeToBuffer(c, "Unlike the sea, the water here is calm and clear.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I can see something metallic barely breaking the surface.", 0x02);
			c.Y++;
			if (inventory == "A Flat Stone")
			{
				g_Console.writeToBuffer(c, "I wonder if I can hit it with the rock I picked up.", 0x05);
			}
			break;
		case 13: // Lake Fish
			g_Console.writeToBuffer(c, "If I'm not wrong, that fish looks like a red herring.", 0x02);
			break;
		case 14: // Lake Box
			g_Console.writeToBuffer(c, "There is a red chest here locked with a padlock.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A note atop of it reads 'AXJPODBCOPWBVU'.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I can't seem to make any sense of it.", 0x05);
			break;
		case 15: // Lake Stone (OF)
			g_Console.writeToBuffer(c, "They feel like stones yet they are as black as coal. I'll take one just in case.", 0x02);
			c.Y++;
			if (levelfinish != 2)
			{
				g_Console.writeToBuffer(c, "Press the E key to pick a stone up.", 0x05);
			}
			break;
		case 16: // Lake Water (OF)
			g_Console.writeToBuffer(c, "The water is blood-red and muddy.", 0x02);
			c.Y++;
			if (inventory == "A stone filled fish")
			{
				g_Console.writeToBuffer(c, "The fish trashes wildly as I bring it toward the lake. Its unsettling, but I manage not to freak out.", 0x05);
			}
			break;
		case 17: // Lake Fish (OF)
			g_Console.writeToBuffer(c, "A red herring.", 0x02);

			if (inventory == "A black flat stone")
			{
				c.Y++;
				g_Console.writeToBuffer(c, "The fishes mouth opens by itself as I approach it with the black stone. Creepy.", 0x05);
			}

			if (reqinteraction == 1)
			{
				c.Y++;
				g_Console.writeToBuffer(c, "I've put 1 stone into the fish.", 0x02);
			}
			else if (reqinteraction == 2)
			{
				c.Y++;
				g_Console.writeToBuffer(c, "I've put 2 stones into the fish. It feels noticably heavier.", 0x02);
			}
			else if (reqinteraction == 3)
			{
				c.Y++;
				g_Console.writeToBuffer(c, "I've put 3 stones into the fish.                            It is heavy.", 0x02);
				c.X += 33;
				g_Console.writeToBuffer(c, "There is no room for more.", 0x05);
				c.X = 0;
			}
			break;
		case 18: // Lake Box (OF)
			g_Console.writeToBuffer(c, "A locked chest.", 0x02);
			break;
		case 19: //Chapel Window
			g_Console.writeToBuffer(c, "I can't see anything through the window. It's stained glass after all.", 0x02);

			if (inventory == "Odd black sphere")
			{
				c.Y++;
				g_Console.writeToBuffer(c, "The black sphere seems to react to the light from the window. Should I hold it closer?", 0x05);
			}
			break;
		case 20: //Chapel Table
			g_Console.writeToBuffer(c, "It's a table with nothing on it. This table is useless.", 0x02);
			break;
		case 21:  //Chapel Pews
			g_Console.writeToBuffer(c, "I've got no time for prayers right now.", 0x02);
			break;
		case 22: //Chapel Podium
			if (reqinteraction == 0)
			{
				g_Console.writeToBuffer(c, "There's a black box sitting on the podium beside a black sphere of some sort. The box has no lid or cover.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Maybe I should just take the black sphere thing instead?", 0x05);
				c.Y++;
				g_Console.writeToBuffer(c, "Press the E key to take black orb.", 0x05);
			}
			else if (reqinteraction == 1)
			{
				g_Console.writeToBuffer(c, "There's a black box sitting on the podium. The box has no lid or cover.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "There's no way it will open just by me staring at it and doing nothing.", 0x02);
			}
			else if (reqinteraction == 2)
			{
				g_Console.writeToBuffer(c, "There's a black box sitting on the podium. A part of it lies on the floor.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "The revealed section of the box shows a ring-shaped hole.", 0x02);
			}
			break;
		case 23: // Chappel Button (OF)
			g_Console.writeToBuffer(c, "It's a button. I really shouldn't be pressing random buttons, but what other option do I have?", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to push the button.", 0x05);
			break;
		case 24 : //Computer Room Bookshelf
			if (inventory == "none")
			{
				g_Console.writeToBuffer(c, "Hmmm...this book seems interesting. It's a biography of Julius Caesar.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "It doesn't seem to be useful in deciphering the password on the computer.", 0x05);
				c.Y++;
				g_Console.writeToBuffer(c, "Wait a minute...that's strange, a page is torn from the book. I'll keep it just in case.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Press the E key to take the history book.", 0x05);
			}
			else if (inventory == "A History Book")
			{
				g_Console.writeToBuffer(c, "I've taken the History Book from the bookshelf.", 0x03);
				c.Y++;
				g_Console.writeToBuffer(c, "The other books don't interest me.", 0x02);
			}
			break;
		case 25 :  //Computer Room computer
			if (reqinteraction == 1)
			{
				g_Console.writeToBuffer(c, "Username: 1.1C4431, 103.552D10", 0x08);  //text is gray in colour
				c.Y++;
				g_Console.writeToBuffer(c, "Password:", 0x08);
				c.Y++;
				g_Console.writeToBuffer(c, "What an odd username. Perhaps I can figure out the password through it?", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Press the E key to type in the password.", 0x05);
			}
			else
			{
				g_Console.writeToBuffer(c, "It's a computer that requires authentication to access it.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Perhaps that book I saw on the bookshelf can help?", 0x05);
			}
			break;
		case 26 :  //Computer Room Map
			g_Console.writeToBuffer(c, "I believe it's a map of Singapore. A red circle is drawn at the southern tip of the island.", 0x02);
			break;
		case 27 :  //Street Buildings
			g_Console.writeToBuffer(c, "All the buildings look the same.", 0x02);
			break;
		case 28 : //Street Lamposts
			g_Console.writeToBuffer(c, "Just your typical lamppost.", 0x02);
			break;
		case 29 : //Street Box
			g_Console.writeToBuffer(c, "There's a code scratched above the lock of this red box.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "01001000  01000001  01010000  01010000  01011001", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to type in the word it forms.", 0x05);
			break;
		case 201: // Chappel Window (OF)
			g_Console.writeToBuffer(c, "I can't see anything through the window.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "It's pitch black. No light seems to be coming through it.", 0x02);
			break;
		case 202: // Chappel Table (OF)
			g_Console.writeToBuffer(c, "There's a black box sitting on the table. The box has no lid or cover.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "There's no way it will open just by me staring at it and doing nothing.", 0x02);
			break;
		case 203: // Chappel Podium (OF)
			g_Console.writeToBuffer(c, "The podium top is clear. I can see 3 buttons on the front side of it.", 0x02);
			break;
		case 30 :   //Chapel Podium (OF)
			g_Console.writeToBuffer(c, "The podium is empty", 0x02);
			break;
		case 31:   //Street Box (OF)
			g_Console.writeToBuffer(c, "A red box is lying on the ground in the middle of the street.", 0x02);
			break;
		case 32:  //Street Door (OF)
			g_Console.writeToBuffer(c, "A door to one of the buildings is open. I should get closer if I want to go inside.", 0x02);
			break;
		case 401:
			g_Console.writeToBuffer(c, "Should I enter the building?", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to enter the building.", 0x05);
			break;
		case 33:   //Living Room Window
			g_Console.writeToBuffer(c, "As far as I can see, there's only a void of white outside the window.", 0x02);
			break;
		case 34:  //Living Room Phone
			g_Console.writeToBuffer(c, "A grey typical push-button telephone. A note beside it reads:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "This requires a BIT of thinking. Perhaps a clue lies in the word between Caps Lock and LEFT Control.", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "What's the number that replaces the question mark? (Press the E key to input)", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "13 26 52 | 104 208 161 | 67 ? 13", 0x08);
			break;
		case 35:  //Living Room Sofa
			g_Console.writeToBuffer(c, "It looks comfortable, but whoever bought it must have horrible taste. The patterns on it look absolutely dreadful.", 0x02);
			break;
		case 36:  //Living Room Window (OF)
			g_Console.writeToBuffer(c, "There is nothing but red fog outside.", 0x02);
			break;
		case 37:  //Living Room Phone (OF)
			g_Console.writeToBuffer(c, "Nothing but a long, monotonous tone comes through the handset speaker.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "There's something on the baby cot, maybe that can help.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to Interact.", 0x02);
			break;
		case 38:   //Living Room sofa
			g_Console.writeToBuffer(c, "This sofa is so ugly that I do not know if I should laugh at or pity its owner.", 0x02);
			break;
		case 39:  //Living Room Baby's cot
			g_Console.writeToBuffer(c, "A baby cot with a word burnt into the wood:", 0x05);
			c.Y++;
			g_Console.writeToBuffer(c, "LIAR", 0x04);   //Text red in colour
			break;
		case 40:   //Funeral Bookshelf (Bad End)
			if (inventory == "A History Book")
			{
				g_Console.writeToBuffer(c, "There's an single empty space in between two books. Should I place the history book I acquired in there?", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Press the E key to place History Book.", 0x05);
			}
			else
			{
				g_Console.writeToBuffer(c, "I've placed the History Book in. I have nothing else to do here.", 0x02);
			}
			break;
		case 41:  //Funeral Pews   (Bad End)
			g_Console.writeToBuffer(c, "The pews are all empty, but soft sobbing sounds can be heard from them.", 0x02);
			break;
		case 42:  //Funeral Coffin (Bad End)
			g_Console.writeToBuffer(c, "A closed coffin. This looks like a funeral wake. There's a piece of paper on top of the coffin that reads:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "\"...to protect messages of military significance, Julius Caesar devised an encryption technique now widely", 0x08);
			c.Y++;
			g_Console.writeToBuffer(c, "known as the \"Caesar Cipher\". This substitution cipher was employed during...\"", 0x08);
			if (reqinteraction == 1)
			{
				c.X = 79;
				g_Console.writeToBuffer(c, "(Press the E key to interact)", 0x05);
				c.X = 0;
				c.Y++;
				g_Console.writeToBuffer(c, "This must be the page torn from the history book. Crudely carved on the coffin's cover is \"lpshqlwhqfh\"", 0x02);
			}
			break;
		case 43:  //Funeral Bookshelf (True End)
			if (inventory == "A History Book")
			{
				g_Console.writeToBuffer(c, "There's an single empty space in between two books. Should I place the history book I acquired in there?", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "Press the E key to place History Book.", 0x05);
			}
			else
			{
				g_Console.writeToBuffer(c, "I've placed the History Book in. I have nothing else to do here.", 0x02);
			}
			break;
		case 44:  //Funeral Pews (True End)
			g_Console.writeToBuffer(c, "The pews are all empty. A deafening silence hung amongst the air.", 0x02);
			break;
		case 45:  //Funeral Coffin (True End)
			g_Console.writeToBuffer(c, "A closed coffin. This looks like a funeral wake.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "There's a piece of paper on top of the coffin that reads:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Here lies Ava Laurens, where her body shall ROT FOR eternity.", 0x08);
			if (reqinteraction == 1)
			{
				c.X = 62;
				g_Console.writeToBuffer(c, "(Press the E key to interact)", 0x05);
				c.X = 0;
				c.Y++;
				g_Console.writeToBuffer(c, "Crudely carved into the coffin's cover is a code \"vitirxergi\".", 0x02);
			}
			break;
		case 46:  //Computer Room Bookshelf (OF)
			g_Console.writeToBuffer(c, "An empty bookshelf caked with dust.", 0x02);
			break;
		case 47:  //Computer Room Computer (OF)
			g_Console.writeToBuffer(c, "The screen of the computer shows:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "\"What's the missing word?\"", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "Press the E key to type in the missing word.", 0x05);
			break;
		case 49:  //Computer Room Picture (OF)
			g_Console.writeToBuffer(c, "It's a picture of a kid getting bullied by someone. Behind it is another picture, depicting the bully", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "standing next to the same kid. There's a speech bubble partially torn off.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I didn't mean to do all those things to you in the past. I know that my apologies will not help you heal,", 0x05);
			c.Y++;
			g_Console.writeToBuffer(c, "but... I feel like there is a need for me to say that I am-", 0x05);
			break;
		case 911:   //Lake EF Complete
			g_Console.writeToBuffer(c, "The stone hit the metallic object with a pleasant 'ding'.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A sound came from the red chest to my right.", 0x02);
			break;
		case 912: // Solve EF1 Box
			g_Console.writeToBuffer(c, "As I thought, the chest was unlocked as soon as the stone hit the metal object.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I lifted the cover and found a note inside. It reads:", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "'Memories are but a jigsaw, one must have all pieces in hand to see the full picture.'", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "As soon as my eyes landed on the last word, a blinding white light exploded around me.", 0x02);
			break;
		case 913: // Solve OF1 Lake
			g_Console.writeToBuffer(c, "After waiting for a short while, a sound came from the red chest to my right.", 0x02);
			break;
		case 914: // Solve OF1 Box
			g_Console.writeToBuffer(c, "The sinister voice that spoke when I had first entered the portal spoke again.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A blinding white light exploded around me as it said its last word.", 0x02);
			break;
		case 921: // Solve EF2 Sphere
			g_Console.writeToBuffer(c, "Once it touched the light emanating from the windows, the sphere melted away.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "A ring was all that's left from it.", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "I heard a \"thunk\". A section of the box fell off and plopped to the ground.", 0x02);
			break;
		case 922: // Solve EF2 Ring
			g_Console.writeToBuffer(c, "The ring should fit right here...", 0x02);
			break;
		case 923: // Solve EF2 Box
			g_Console.writeToBuffer(c, "It worked. The box is opened. White light begins to fill my vision again.", 0x02);
			break;
		case 924: // Solve/Not OF2 Buttons
			if (reqinteraction == 1)
			{
				g_Console.writeToBuffer(c, "Light suddenly burst through the left window, as if a curtain that was blocking it had fallen.", 0x02);
			}
			else if (reqinteraction == 2)
			{
				g_Console.writeToBuffer(c, "Light suddenly burst through the middle window, as if a curtain that was blocking it had fallen.", 0x02);
			}
			else if (reqinteraction == 3)
			{
				g_Console.writeToBuffer(c, "Light suddenly burst through the right window, as if a curtain that was blocking it had fallen.", 0x02);
			}
			else if (reqinteraction == 4)
			{
				g_Console.writeToBuffer(c, "The light emanating from the left window disappeared once I pressed the button.", 0x02);
			}
			else if (reqinteraction == 5)
			{
				g_Console.writeToBuffer(c, "The light emanating from the middle window disappeared once I pressed the button.", 0x02);
			}
			else if (reqinteraction == 6)
			{
				g_Console.writeToBuffer(c, "The light emanating from the right window disappeared once I pressed the button.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "I heard a \"thunk\". A section of the box fell off and plopped to the ground.", 0x02);
			}
			else if (reqinteraction == 0)
			{
				g_Console.writeToBuffer(c, "The lights from all the windows went out, and with it came a short vibration from the ground.", 0x02);
				c.Y++;
				g_Console.writeToBuffer(c, "I might have pressed the wrong button.", 0x05);
			}
			break;
		case 926: // Solve OF2 Box
			g_Console.writeToBuffer(c, "It worked. The box is opened. White light begins to fill my vision again.", 0x02);
			break;
		case 404: // Error 404. Just kidding.
			g_Console.writeToBuffer(c, "An unknown force prevents me from proceeding.", 0x03);
			break;
		case 991:
			g_Console.writeToBuffer(c, "Upon my successful log in, the computer loaded up a video on the screen.", 0x02);
			break;
		case 992:
			g_Console.writeToBuffer(c, "Upon successfully guessing the missing word, the computer loaded up a video on the screen.", 0x02);
			break;
		case 993:
			g_Console.writeToBuffer(c, "I decoded the numbers and it spells out \"happy\" The box opens, to reveal to me another memory.", 0x02);
			break;
		case 994:
			g_Console.writeToBuffer(c, "After successfully inputting the right number, I put the phone to my ear, and heard the following:", 0x02);
			break;
		case 995:
			g_Console.writeToBuffer(c, "After successfully inputting the right number, I put the phone to my ear, and heard the following.", 0x02);
			break;
		case 999: // Testing purposes only, pls take out on release build danke.
			g_Console.writeToBuffer(c, "Whatever you are doing,", 0x02);
			c.Y++;
			g_Console.writeToBuffer(c, "it bloody works!", 0x02);
			break;
		}
		c.Y = tempcoords;
	}

	if (levelfinish > 0)
	{
		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 1)
		{
			InPortal = 0;
			Areanum = 1;
			levelfinish = 0;
			g_dElapsedTimeTemp = 999.0;

			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 88;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 45;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 2)
		{
			InPortal = 0;
			Areanum = 1;
			levelfinish = 0;
			g_dElapsedTimeTemp = 999.0;

			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 74;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 48;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 3)
		{
			InPortal = 0;
			Areanum = 2;
			levelfinish = 0;
			g_dElapsedTimeTemp = 999.0;

			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 43;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 4)
		{
			InPortal = 0;
			Areanum = 2;
			levelfinish = 0;
			g_dElapsedTimeTemp = 999.0;

			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 85;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 51;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 5)
		{
		InPortal = 0;
		Areanum = 3;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 86;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 46;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 6)
		{
		InPortal = 0;
		Areanum = 3;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 48;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 7)
		{
		InPortal = 0;
		Areanum = 4;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 76;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 44;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 8) // *** *** *** *** *** MIGHT NOT BE USED, REMOVE IF THATS THE CASE *** *** *** *** ***
		{
		InPortal = 0;
		Areanum = 4;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 84;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 36;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 9)
		{
		InPortal = 0;
		Areanum = 5;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 96;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 48;
		}

		if (g_dElapsedTime >= g_dElapsedTimeTemp && levelfinish == 10)
		{
		InPortal = 0;
		Areanum = 5;
		levelfinish = 0;
		g_dElapsedTimeTemp = 999.0;

		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 87;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 41;
		}
	}
}