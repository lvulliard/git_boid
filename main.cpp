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

    // Obj declarations
	Prey p1(5,3);
	Hunter h1(1,5);
	Prey p2(6,4,20);
	Hunter h2(2,6,60);

	Border* b1 = new Border(0, 20, 20, 450, 0xBB0000);

    Obstacle obs1;
	obs1.x = 30;
	obs1.y = 450;
	obs1.r = 28;

   	Obstacle obs2;
	obs2.x = 300;
	obs2.y = 450;
	obs2.r = 10;

	//printf("p1 : x %f, y %f, dx %f, dy %f, color %d\n", p1.get_x(), p1.get_y(), p1.get_dx(), p1.get_dy(), p1.get_color());
	//printf("h1 : x %f, y %f, dx %f, dy %f, color %d\n", h1.get_x(), h1.get_y(), h1.get_dx(), h1.get_dy(), h1.get_color());
	//printf("p2 : x %f, y %f, dx %f, dy %f, color %d\n", p2.get_x(), p2.get_y(), p2.get_dx(), p2.get_dy(), p2.get_color());
	//printf("h2 : x %f, y %f, dx %f, dy %f, color %d\n", h2.get_x(), h2.get_y(), h2.get_dx(), h2.get_dy(), h2.get_color());

	// Scene declaration
	Scene* s1 = new Scene ();

	// Add borders
	s1->addBorder(0,20,20,(DefVal::WINDOW_WIDTH)-20);
	s1->addBorder(1,20,(DefVal::WINDOW_HEIGHT)-20,(DefVal::WINDOW_WIDTH)-20);
	s1->addBorder(2,(DefVal::WINDOW_WIDTH)-20,(DefVal::WINDOW_HEIGHT)-20,20);
	s1->addBorder(3,20,(DefVal::WINDOW_HEIGHT)-20,20);

	// Add obstacle
	s1->addObstacle(DefVal::NB_OBST);

	// Add preys
	s1->addAgent(150,20);


	// Paint loop
    for(;;)
    {
		int ev = win.parse_event();
		usleep(7500); // time step in microseconds

		// Comment to see trajectories
		win.draw_fsquare(0,0,DefVal::WINDOW_WIDTH,DefVal::WINDOW_HEIGHT,0x77B5FE);

		s1->draw(win);
		//must be >10ms (depending on the system)
		/*switch(ev)
		{
		    case BKPRESS :
			printf("keypressed\n"); 
			printf("key : %s\n",win.get_lastkey());
			break;
		    case BBPRESS:
			printf("buttonpressed\n"); break;
		    case BEXPOSE:
			printf("expose\n"); break;
		    case BCONFIGURE:
			printf("configure\n"); break;
		}*/

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

    delete b1;

    return 0;
}
