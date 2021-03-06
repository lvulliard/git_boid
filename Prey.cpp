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
			// If a speed is induced
			if( (dv[0]!=0) && (dv[1]!= 0) ){
				switch((int)dv[2])
				{
					// If prey in radius
					case 0 :
					k1 ++;
					dvx1 += dv[0];
					dvy1 += dv[1];	
					break;

					// If prey in radius but too close
					case 1 :
					k2 ++;
					dvx2 += dv[0];
					dvy2 += dv[1];
					break;

					// If hunter
					case 2 :
					ndx += dv[0];
					ndy += dv[1];
					break;
				}
			}
	
		}
	}

	// Compute new speeds
	if(k1 != 0)
	{
		ndx += (dvx1 / (double) k1); 
		ndy += (dvy1 / (double) k1);	 
	}
	if(k2 != 0)
	{
		ndx += (dvx2 / (double) k2); 
		ndy += (dvy2 / (double) k2); 
	}

	// Obstacles
	for(i = 0; i < nb_o; i++)
		if( ( (obs[i].x - x)*(obs[i].x - x) + (obs[i].y - y)*(obs[i].y - y) )  < (hitbox+obs[i].r)*(hitbox+obs[i].r))
		{
			// V3
			ndx += - DefVal::GAMMA3o * (obs[i].x - x);
			ndy += - DefVal::GAMMA3o * (obs[i].y - y);
		}


	// Max speed
	if (ndx*ndx > (DefVal::MAX_PREY_SPEED)*(DefVal::MAX_PREY_SPEED))
		ndx /= (abs(ndx)/DefVal::MAX_PREY_SPEED);
	if (ndy*ndy > (DefVal::MAX_PREY_SPEED)*(DefVal::MAX_PREY_SPEED))
		ndy /= (abs(ndy)/DefVal::MAX_PREY_SPEED);
}

double* Prey::speed_for_preys(double x2, double y2, double dx2, double dy2, double r2)
{
	// Returned induced speed
	double* res = new double [3];
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;

	// If the prey is alive
	if(state != 1)
	{
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

	// If the prey is alive
	if(state != 1)
	{
		double dis = sqrt((x-x2)*(x-x2) + (y - y2)*(y-y2));

		if( dis < r2)
		{
			res[0] = ((x - x2) * DefVal::HUNTING_SPEED) / dis;
			res[1] = ((y - y2) * DefVal::HUNTING_SPEED) / dis;
		}

		res[2] = dis;

		if( dis < hitbox)
		{
			state = 1;
			res[2] = -1;
		}
	}

	return res;

}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
