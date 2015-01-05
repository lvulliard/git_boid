//****************************************************************************
//
//                                    Prey
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Prey.h"




//############################################################################
//                                                                           #
//                                  Class Prey                               #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Prey::Prey(double x, double y) : Agent(x,y,0x0000ff)
{
}

Prey::Prey(double x, double y, unsigned int c) : Agent(x,y,c)
{
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Prey::~Prey(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
