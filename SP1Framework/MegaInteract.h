#ifndef _MEGAINTERACT_H
#define _MEGAINTERACT_H

#include "Framework\console.h"
#include "game.h"
#include "BadEnd.h"
#include "TrueEnd.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <Windows.h>

int checkinteract(void);

void FstandsforFrustrating(int checkF);

extern double g_dElapsedTime;
extern double g_dTime;

#endif // _MEGAINTERACT_H