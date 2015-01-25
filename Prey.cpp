//****************************************************************************
//
//                                    Prey
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <math.h>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Prey.h"
#include "DefVal.h"



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
Prey::Prey(double x, double y) : 	
	Agent(x,y,DefVal::PREY_HITBOX,DefVal::PREY_RADIUS,DefVal::PREY_COLOR)
{
}

Prey::Prey(double x, double y, unsigned int c) : Agent(x,y,DefVal::PREY_HITBOX,DefVal::PREY_RADIUS,c)
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
void Prey::move(Border* borders, unsigned int nb_b, Agent** tab, int index, unsigned int nb_a, Obstacle* obs, unsigned int nb_o)
{
	// Wind
	speed_from_borders(borders, nb_b);

	// Index and number of agents in the radius of detection and in his hitbox
	int i,k1 = 0, k2 = 0;

	// Global change of speed
	double dvx1 = 0, dvx2 = 0, dvy1 = 0, dvy2 = 0;

	for(i = 0; i < nb_a; i++)
	{
		double* dv;
		if(i != index)
		{
			dv = tab[i]->speed_for_preys(x,y,dx,dy,r);
			if( (dv[0]!=0) && (dv[1]!= 0) ){
				// If in radius but too close
				if (dv[2])
				{
					k2 ++;
					dvx2 += dv[0];
					dvy2 += dv[1];	
				}
				else
				{
					k1 ++;
					dvx1 += dv[0];
					dvy1 += dv[1];	
				}
			}
	
		}
	}

	// Compute new speeds
	if(k1 != 0)
	{
		dx += (dvx1 / (double) k1); 
		dy += (dvy1 / (double) k1);	 
	}
	if(k2 != 0)
	{
		dx += (dvx2 / (double) k2); 
		dy += (dvy2 / (double) k2); 
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
	if (dx*dx > (DefVal::MAX_PREY_SPEED)*(DefVal::MAX_PREY_SPEED))
		dx /= (abs(dx)/DefVal::MAX_PREY_SPEED);
	if (dy*dy > (DefVal::MAX_PREY_SPEED)*(DefVal::MAX_PREY_SPEED))
		dy /= (abs(dy)/DefVal::MAX_PREY_SPEED);

	// Move
	x += dx;
	y += dy;
}

double* Prey::speed_for_preys(double x2, double y2, double dx2, double dy2, double r2)
{
	// Returned induced speed
	double* res = new double [3];
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;

	// Distance between the 2 points
	double dis = (x-x2)*(x-x2) + (y - y2)*(y-y2);

	
	if(dis < hitbox*hitbox)
	{
		// V3
		res[0] = - DefVal::GAMMA3 * (dx - dx2);
		res[1] = - DefVal::GAMMA3 * (dy - dy2);

		// V2
		res[0] += DefVal::GAMMA2 * (x - x2);
		res[1] += DefVal::GAMMA2 * (y - y2);

		res[2] = 1;
	}
	else
	{
		if(dis < r2*r2)
		{
			// V1
			res[0] = DefVal::GAMMA1 * (dx - dx2);
			res[1] = DefVal::GAMMA1 * (dy - dy2);

			// V2
			res[0] += DefVal::GAMMA2 * (x - x2);
			res[1] += DefVal::GAMMA2 * (y - y2);
		}

	}

	return res;
}

double* Prey::speed_for_hunters(double x2, double y2, double r2)
{
	// Returned induced speed
	double* res = new double [3];
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;

	double dis = sqrt((x-x2)*(x-x2) + (y - y2)*(y-y2));

	if( dis < r2)
	{
		res[0] = ((x - x2) * DefVal::HUNTING_SPEED) / dis;
		res[1] = ((y - y2) * DefVal::HUNTING_SPEED) / dis;
	}

	res[2] = dis;

	return res;

}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
