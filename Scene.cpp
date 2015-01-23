//****************************************************************************
//
//                                    Scene
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <string.h>
#include <math.h>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Scene.h"
#include "DefVal.h"
#include "bwindow.h"
#include "Prey.h"
#include "Hunter.h"




//############################################################################
//                                                                           #
//                                  Class Scene                              #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Scene::Scene(void) : MAX_WIDTH(DefVal::WINDOW_WIDTH),
	MAX_HEIGHT(DefVal::WINDOW_HEIGHT), 
	NB_BORDERS(DefVal::NB_BORDERS), 
	NB_MAX_PREY(DefVal::NB_MAX_PREY), 
	NB_MAX_HUNT(DefVal::NB_MAX_HUNT),
	nb_borders(0),
	nb_prey(0),
	nb_hunt(0)
{
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Scene::~Scene(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
// Add a Border to the scene
// The type can be 0 (upper), 1 (lower), 2 (right) or 3 (left)
void Scene::addBorder(int type, int x1, int y1, int c2)
{
	if(nb_borders < NB_BORDERS){
		
		nb_borders++;
		Border* new_borders = (Border*) malloc(nb_borders*sizeof(Border));
		memcpy(new_borders, borders, (nb_borders-1)*sizeof(Border));
		new_borders[nb_borders-1] = Border(type, x1, y1, c2);
		free(borders);
		borders = new_borders;
	}
}

// Add a Prey to the scene
void Scene::addAgent(int nb_prey_in_array, int nb_hunt_in_array)
{
	if((nb_prey_in_array <= NB_MAX_PREY) && (nb_hunt_in_array <= NB_MAX_HUNT))
	{
		delete agents;
		agents = new Agent* [(nb_prey_in_array+nb_hunt_in_array)];
		int i;
		for(i=0; i<nb_hunt_in_array; i++)
			agents[i] = new Hunter((int)round(((float)rand()/RAND_MAX)*DefVal::WINDOW_WIDTH), (int)round(((float)rand()/RAND_MAX)*DefVal::WINDOW_HEIGHT));
		for(i=0; i<nb_prey_in_array; i++)
			agents[i+nb_hunt_in_array] = new Prey((int)round(((float)rand()/RAND_MAX)*DefVal::WINDOW_WIDTH), (int)round(((float)rand()/RAND_MAX)*DefVal::WINDOW_HEIGHT));
		nb_prey = nb_prey_in_array;
		nb_hunt = nb_hunt_in_array;
	}
}

// Draw the content of the scene
void Scene::draw(bwindow& win)
{
	int i,j;
	// Total number of agents
	unsigned int N = nb_prey+nb_hunt;

	// Draw borders
	for(i = 0; i < nb_borders; i++){
		int* bordPoints = new int [4];
	    bordPoints = borders[i].get_points();
	    win.draw_line(bordPoints[0], bordPoints[1], bordPoints[2], bordPoints[3], borders[i].get_color());
		delete bordPoints;
	}

	// Draw agents
	for(j=0; j<(N); j++)
	{
		// Move the agent
		agents[j]->move(borders, nb_borders, agents,j,N);

		// Draw the new position
		win.draw_fsquare(round(agents[j]->get_x()-1),round(agents[j]->get_y()-1),round(agents[j]->get_x()+1),round(agents[j]->get_y()+1),agents[j]->get_color());
	
	}
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
