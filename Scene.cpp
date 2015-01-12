//****************************************************************************
//
//                                    Scene
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <string.h>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Scene.h"
#include "DefVal.h"
#include "bwindow.h"



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
		printf("Et la?\n");
		free(borders);
		printf("Bah alors !\n");
		borders = new_borders;
		printf("Impossible.\n");
	}
}

// Draw the content of the scene
void Scene::draw(bwindow& win)
{
	int i;
	for(i = 0; i < nb_borders; i++){
		int* bordPoints = new int [4];
	    bordPoints = borders[i].get_points();
	    win.draw_line(bordPoints[0], bordPoints[1], bordPoints[2], bordPoints[3], borders[i].get_color());
		delete bordPoints;
	}
		
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
