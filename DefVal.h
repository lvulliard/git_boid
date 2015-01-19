//****************************************************************************
//
//                                    DefVal
//
//****************************************************************************
#ifndef __DefVal_H__
#define __DefVal_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>


// ===========================================================================
//                             Struct declaration
// ===========================================================================
namespace DefVal
{
    const unsigned int BORDER_COLOR = 0xBB0000;
    const unsigned int HUNTER_COLOR = 0xFF0000;
    const unsigned int PREY_COLOR = 0x0000FF;
    const unsigned int WINDOW_WIDTH = 800;
    const unsigned int WINDOW_HEIGHT = 600;
    const unsigned int NB_BORDERS = 4;
    const unsigned int NB_MAX_PREY = 2000;
    const unsigned int NB_MAX_HUNT = 1000;

    const double HUNTING_SPEED = 2.5;
    const double BORDER_STRENGTH = 0.015;
    const double HUNTER_HITBOX = 5.0;
    const double PREY_HITBOX = 3.0;
    const double HUNTER_RADIUS = 20.0;
    const double PREY_RADIUS = 12.0;
    const double GAMMA1 = 0.03;
    const double GAMMA2 = 0.1;
    const double GAMMA3 = 0.1;
    const double GAMMA4 = 0.1;
    const double MU = 0.1;
}

#endif // __DefVal_H__