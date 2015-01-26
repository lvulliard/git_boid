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
#include <string>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Scene.h"
#include "DefVal.h"
#include "bwindow.h"
#include "Prey.h"
#include "Hunter.h"
#include "Obstacle.h"



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
	nb_hunt(0),
	nb_obstacles(0),
	agents(NULL),
	borders(NULL),
	obstacles(NULL)
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
// Add an Obstacle to the scene
void Scene::addObstacle(double x, double y, double r)
{
	nb_obstacles++;
	Obstacle* new_obstacles = new Obstacle [nb_obstacles];
	memcpy(new_obstacles, obstacles, (nb_obstacles-1)*sizeof(Obstacle));
	new_obstacles[nb_obstacles-1].x = x;
	new_obstacles[nb_obstacles-1].y = y;
	new_obstacles[nb_obstacles-1].r = r;
	delete [] obstacles;
	obstacles = new_obstacles;

}

// Add random obstacles to the scene
void Scene::addObstacle(unsigned int n)
{
	n = round(2*n*((float)rand()/RAND_MAX));
	nb_obstacles += n;
	Obstacle* new_obstacles = new Obstacle [nb_obstacles];
	memcpy(new_obstacles, obstacles, (nb_obstacles-n)*sizeof(Obstacle));
	
	int i;
	for(i = 1; i <= n; i++)
	{
		new_obstacles[nb_obstacles-i].x = ((float)rand()/RAND_MAX)*DefVal::WINDOW_WIDTH;
		pow(-1,round((float)rand()/RAND_MAX))*((float)rand()/RAND_MAX);
		new_obstacles[nb_obstacles-i].y = ((float)rand()/RAND_MAX)*DefVal::WINDOW_HEIGHT;
		new_obstacles[nb_obstacles-i].r = 10 + ((float)rand()/RAND_MAX)*2*(DefVal::OBST_RADIUS - 10);
	} 
	delete [] obstacles;
	obstacles = new_obstacles;
}

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

	// Draw obstacles
	for(j=0; j<nb_obstacles; j++)
	{
		for(i=0; i<360; i += round(300/obstacles[j].r))
		{
			win.draw_point(round(obstacles[j].x +(obstacles[j].r)*cos(i*0.017453)), round(obstacles[j].y + (obstacles[j].r)*sin(i*0.017453)), 0x4D9E3A);
		}
			win.draw_point(obstacles[j].x, obstacles[j].y, 0x4D9E3A);
	}

	int count_deads = 0;
	// Draw agents
	for(j=0; j<(N); j++)
	{
		// State of the agent (has eaten, is alive or dead)
		int state = agents[j]->get_state();

		// If the agent is not dead
		if(state != 1)
		{
			if(state >= 0)
			{
				// Move the agent
				agents[j]->move(borders, nb_borders, agents,j,N, obstacles, nb_obstacles);
			}
			else
			{
				// Wait for the time to be spent
				agents[j]->wait();
			}

			// Draw the new position
			win.draw_fsquare(round(agents[j]->get_x()-1),round(agents[j]->get_y()-1),round(agents[j]->get_x()+1),round(agents[j]->get_y()+1),agents[j]->get_color());
		}
		else
		{
			count_deads++;
		}
	}

	char numstr[21]; // enough to hold all numbers up to 64-bits
	sprintf(numstr, "%d", count_deads);
	std::string count_string = " preys eaten.";
	count_string = numstr + count_string;
	win.draw_text(50,50,0x0,count_string.c_str(),count_string.size());
}

// Check-up function
void Scene::checkup()
{
	printf("Je pense que ça va.\n");
	printf("Mes paramètres sont :\n MAX_WIDTH = %d, MAX_HEIGHT = %d\n", MAX_WIDTH , MAX_HEIGHT);
	printf("NB_BORDERS = %d; NB_MAX_PREY = %d, NB_MAX_HUNT = %d\n", NB_BORDERS, NB_MAX_PREY, NB_MAX_HUNT);
	printf("nb_prey = %d, nb_hunt = %d, nb_borders = %d, nb_obstacles = %d\n", nb_prey, nb_hunt, nb_borders, nb_obstacles);
	printf("Et pour les pointeurs, on a :\n");
	//printf("%d; %d; %d", *agents, borders, obstacles);
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
