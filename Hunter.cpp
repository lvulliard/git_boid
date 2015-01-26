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

	int i;

	// Minimum distance between a hunter and its prey
	double min_dist = DefVal::WINDOW_HEIGHT + DefVal::WINDOW_WIDTH;

	// Hunt
	for(i = 0; i < nb_a; i++)
	{
		double* dv;
		if(i != index)
		{
			dv = tab[i]->speed_for_hunters(x,y,r);
			if( (dv[0]!=0) || (dv[1]!= 0) ){
				if(dv[2] < min_dist)
				dx = dv[0];
				dy = dv[1];	
				min_dist = dv[2];
			}
		}
	}

	// Obstacles
	for(i = 0; i < nb_o; i++)
		if( ( (obs[i].x - x)*(obs[i].x - x) + (obs[i].y - y)*(obs[i].y - y) )  < (hitbox+obs[i].r)*(hitbox+obs[i].r))
		{
			// V3
			dx += - DefVal::GAMMA3o * (obs[i].x - x);
			dy += - DefVal::GAMMA3o * (obs[i].y - y);
		}

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
	double* res = new double [3];
	res[0] = 0;
	res[1] = 0;
	res[2] = 2;

	double dis = sqrt((x-x2)*(x-x2) + (y - y2)*(y-y2));

	if( dis < r2)
	{
		res[0] = - ((x - x2) * DefVal::GAMMA4) / dis;
		res[1] = - ((y - y2) * DefVal::GAMMA4) / dis;
	}

	return res;

}

double* Hunter::speed_for_hunters(double x2, double y2, double r2)
{	
	// Returned induced speed
	double* res = new double [3];
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;

	return res;
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
