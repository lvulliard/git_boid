// Std lib
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctime>

// For Linux/Mac
#include <unistd.h>

// For Windows
// #include <windows.h>
// You also need to replace "sleep()" by "Sleep()"

// Graphic lib
#include "bwindow.h"

// Constants
#include "DefVal.h"

// Boid struct
#include "Obstacle.h"

// Boid classes
#include "Border.h"
#include "Agent.h"
#include "Prey.h"
#include "Hunter.h"
#include "Scene.h"


int main()
{
	// Seed for the random variables
	srand (time (NULL));

	// Window set-up
    bwindow win(DefVal::WINDOW_WIDTH,DefVal::WINDOW_HEIGHT);
    printf("%d\n",win.init());
    win.map();

	// Scene declaration
	Scene* s1 = new Scene ();

	// Add borders
	s1->addBorder(0,20,20,(DefVal::WINDOW_WIDTH)-20);
	s1->addBorder(1,20,(DefVal::WINDOW_HEIGHT)-20,(DefVal::WINDOW_WIDTH)-20);
	s1->addBorder(2,(DefVal::WINDOW_WIDTH)-20,(DefVal::WINDOW_HEIGHT)-20,20);
	s1->addBorder(3,20,(DefVal::WINDOW_HEIGHT)-20,20);

	// Add obstacle
	s1->addObstacle(DefVal::NB_OBST);

	// Add agents
	s1->addAgent(20,20);
	
	// Paint loop
    for(;;)
    {
		int ev = win.parse_event();
		usleep(DefVal::TIME_STEP); // time step in microseconds

		// Comment to see trajectories
		win.draw_fsquare(0,0,DefVal::WINDOW_WIDTH,DefVal::WINDOW_HEIGHT,0xE2BD40);

		s1->draw(win);
		//must be >10ms (depending on the system)
		switch(ev)
		{
		    case BKPRESS :
			if(!strcmp(win.get_lastkey(), "space"))
				// Sleep for 1s
				usleep(1000000);
			break;
		}

    }

    return 0;
}
