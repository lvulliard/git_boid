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
	srand (time (NULL));
    bwindow win(DefVal::WINDOW_WIDTH,DefVal::WINDOW_HEIGHT);
    printf("%d\n",win.init());
    win.map();
	
    int i;

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
	s1->addAgent(5,10);
	//s1->addHunter();
	//s1->addPrey();
	//s1->addHunter();
	//s1->addPrey();
	
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

		/*win.draw_line(100,100,200,200,0xFF0000);
		win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
		win.draw_square(200,200,220,220,0xFF00);
		win.draw_fsquare(400,400,440,440,0xFF00);*/

	    
	    // This script will be the method used to draw a border
	    // Begin here
	    
	    /*int* bordPoints = new int [4];
	    bordPoints = b1->get_points();
	    win.draw_line(bordPoints[0], bordPoints[1], bordPoints[2], bordPoints[3], b1->get_color());
		delete bordPoints;*/

	    // End here

	    // This script will be the method used to draw an obstacle
	    // Begin here
		/*for(i=0; i<360; i += round(300/obs1.r))
		{
			win.draw_point(round(obs1.x +(obs1.r)*cos(i*0.017453)), round(obs1.y + (obs1.r)*sin(i*0.017453)), 0);
		}*/

	    // End here

	    // This script will be the method used to draw an obstacle
	    // Begin here
		/*for(i=0; i<360; i += round(300/obs2.r))
		{
			win.draw_point(round(obs2.x +(obs2.r)*cos(i*0.017453)), round(obs2.y + (obs2.r)*sin(i*0.017453)), 0);
		}*/

	    // End here

    }

    return 0;
}
