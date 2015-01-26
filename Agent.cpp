//****************************************************************************
//
//                                    Agent
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <math.h> 


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Agent.h"
#include "DefVal.h"


//############################################################################
//                                                                           #
//                                  Class Agent                              #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(double x, double y, double h, double r, unsigned int c)
{
    this->x = x;
    this->y = y;
    dx = pow(-1,round((float)rand()/RAND_MAX))*((float)rand()/RAND_MAX);
    dy = pow(-1,round((float)rand()/RAND_MAX))*((float)rand()/RAND_MAX);
    color = c;
    hitbox = h;
    this->r = r;
    state = 0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
double Agent::speed_from_borders(Border* borders, unsigned int nb)
{
	int i; // Index
	for(i = 0; i < nb; i++)
	{
		switch(borders[i].get_orientation())
		{
			// Upper border
			case 0:
				// If above upper border
				if(y > (borders[i].get_points())[1] ) 
					// Go progressively downward
					dy -= DefVal::BORDER_STRENGTH;
				break;

			// Lower border
			case 1:
				// If below lower border
				if(y <  (borders[i].get_points())[1] )
					// Go progressively upward
					dy += DefVal::BORDER_STRENGTH;
				break;

			// right border
			case 2:
				// If left to the right border
				if(x >  (borders[i].get_points())[0] )
					// Go progressively left
					dx -= DefVal::BORDER_STRENGTH;
				break;

			// left border
			case 3:
				// If right to the left border
				if(x < (borders[i].get_points())[0] )
					// Go progressively right
					dx += DefVal::BORDER_STRENGTH;
				break;
		}
	}
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
