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
    const double HUNTING_SPEED = 2.5;
    const unsigned int HUNTER_COLOR = 0xFF0000;
    const unsigned int PREY_COLOR = 0x0000FF;
    const unsigned int WINDOW_WIDTH = 640;
    const unsigned int WINDOW_HEIGHT = 480;
    const unsigned int NB_BORDERS = 4;
    const unsigned int NB_MAX_PREY = 200;
    const unsigned int NB_MAX_HUNT = 100;
}

#endif // __DefVal_H__