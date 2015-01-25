//****************************************************************************
//
//                                    Hunter
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <math.h> 


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Hunter.h"
#include "DefVal.h"




//############################################################################
//                                                                           #
//                                  Class Hunter                              #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Hunter::Hunter(double x, double y) : HUNTING_SPEED(DefVal::HUNTING_SPEED), 
	Agent(x,y,DefVal::HUNTER_HITBOX,DefVal::HUNTER_RADIUS,DefVal::HUNTER_COLOR)
{
}

Hunter::Hunter(double x, double y, unsigned int c) :  HUNTING_SPEED(DefVal::HUNTING_SPEED), 
	Agent(x,y,DefVal::HUNTER_HITBOX,DefVal::HUNTER_RADIUS,c)
{
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Hunter::~Hunter(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
void Hunter::move(Border* borders, unsigned int nb_b, Agent** tab, int index, unsigned int nb_a, Obstacle* obs, unsigned int nb_o)
{
	// Wind
	speed_from_borders(borders, nb_b);

	// Isotropic motion
	dx += DefVal::HUNTER_DRUNKENNESS * pow(-1,round((float)rand()/RAND_MAX))*((float)rand()/RAND_MAX);
	dy += DefVal::HUNTER_DRUNKENNESS * pow(-1,round((float)rand()/RAND_MAX))*((float)rand()/RAND_MAX);

	// Max speed
	if (dx*dx > (DefVal::MAX_HUNT_SPEED)*(DefVal::MAX_HUNT_SPEED))
		dx /= (abs(dx)/DefVal::MAX_HUNT_SPEED);
	if (dy*dy > (DefVal::MAX_HUNT_SPEED)*(DefVal::MAX_HUNT_SPEED))
		dy /= (abs(dy)/DefVal::MAX_HUNT_SPEED);

	x += dx;
	y += dy;
}

double* Hunter::speed_for_preys(double x2, double y2, double dx2, double dy2, double r2)
{
	// Returned induced speed
	double* res = new double [2];
	res[0] = 0;
	res[1] = 0;

	return res;

}
double* Hunter::speed_for_hunters(double x2, double y2, double dx2, double dy2, double r2)
{

}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
