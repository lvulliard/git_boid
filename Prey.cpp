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
void Prey::move(Border* borders, unsigned int nb_b, Agent** tab, int index, unsigned int nb_a)
{
	// Wind
	speed_from_borders(borders, nb_b);

	// Index and number of agents in the radius of detection
	int i,k;
	k=0;

	for(i = 0; i < nb_a; i++)
	{
		double* dv;
		if(i != index)
		{
			dv = tab[i]->speed_for_preys(x,y,dx,dy,r);
			//dv = speed_for_preys(x,y,dx,dy,r);
			if( (dv[0]!=0) && (dv[1]!= 0) )
				k++;
		
		dx += dv[0];
		dy += dv[1];
		}
	}
	
	// Move
	x += dx;
	y += dy;
}

double* Prey::speed_for_preys(double x2, double y2, double dx2, double dy2, double r2)
{
	// Returned induced speed
	double* res = new double [2];
	res[0] = 0;
	res[1] = 0;

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

double* Prey::speed_for_hunters(double x2, double y2, double dx2, double dy2, double r2)
{

}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
