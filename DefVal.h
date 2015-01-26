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
    const unsigned int WINDOW_WIDTH = 1000;
    const unsigned int WINDOW_HEIGHT = 800;
    const unsigned int NB_BORDERS = 4;
    const unsigned int NB_MAX_PREY = 2000;
    const unsigned int NB_MAX_HUNT = 1000;
    const unsigned int NB_OBST = 10;
    const unsigned int TIME_STEP = 7500;
    const unsigned int WAITING_STEPS = 200;

    const double HUNTING_SPEED = 0.99;
    const double BORDER_STRENGTH = 0.06;
    const double HUNTER_HITBOX = 7.0;
    const double PREY_HITBOX = 6.0;
    const double HUNTER_RADIUS = 40.0;
    const double PREY_RADIUS = 30.0;
    const double OBST_RADIUS = 15;
    const double GAMMA1 = 0.055;
    const double GAMMA2 = 0.0001;
    const double GAMMA3 = 0.05;
    const double GAMMA3o = 0.016;
    const double GAMMA4 = 0.07;
    const double MU = 0.1;
    const double MAX_PREY_SPEED = 1.2;
    const double MAX_HUNT_SPEED = 1.1;
    const double HUNTER_DRUNKENNESS = 0.02;
}

#endif // __DefVal_H__