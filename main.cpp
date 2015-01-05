// Std lib
#include <stdio.h>
#include <math.h>

// Graphic lib
#include "bwindow.h"

// Boid struct
#include "Obstacle.h"

// Boid classes
#include "Border.h"
#include "Agent.h"
#include "Prey.h"
#include "Hunter.h"


int main()
{
    bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();

    // Obj declarations
	Prey p1(5,3);
	Agent a1(2,4);
	Hunter h1(1,5);
	Prey p2(6,4,20);
	Agent a2(1,5,40);
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

	printf("a1 : x %f, y %f, dx %f, dy %f, color %d\n", a1.get_x(), a1.get_y(), a1.get_dx(), a1.get_dy(), a1.get_color());
	printf("p1 : x %f, y %f, dx %f, dy %f, color %d\n", p1.get_x(), p1.get_y(), p1.get_dx(), p1.get_dy(), p1.get_color());
	printf("h1 : x %f, y %f, dx %f, dy %f, color %d\n", h1.get_x(), h1.get_y(), h1.get_dx(), h1.get_dy(), h1.get_color());
	printf("a2 : x %f, y %f, dx %f, dy %f, color %d\n", a2.get_x(), a2.get_y(), a2.get_dx(), a2.get_dy(), a2.get_color());
	printf("p2 : x %f, y %f, dx %f, dy %f, color %d\n", p2.get_x(), p2.get_y(), p2.get_dx(), p2.get_dy(), p2.get_color());
	printf("h2 : x %f, y %f, dx %f, dy %f, color %d\n", h2.get_x(), h2.get_y(), h2.get_dx(), h2.get_dy(), h2.get_color());

	// Paint loop
    for(;;)
    {
		int ev = win.parse_event();
		switch(ev)
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
		}

		int i;
		for(i=0; i<200; i++)
			win.draw_point(i,88,0xFF00);
		win.draw_line(100,100,200,200,0xFF0000);
		win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
		win.draw_square(200,200,220,220,0xFF00);
		win.draw_fsquare(400,400,440,440,0xFF00);

	    
	    // This script will be the method used to draw a border
	    // Begin here
	    
	    int* bordPoints = new int [4];
	    bordPoints = b1->get_points();
	    win.draw_line(bordPoints[0], bordPoints[1], bordPoints[2], bordPoints[3], b1->get_color());
		delete bordPoints;

	    // End here

	    // This script will be the method used to draw an obstacle
	    // Begin here
		for(i=0; i<360; i += round(300/obs1.r))
		{
			win.draw_point(round(obs1.x +(obs1.r)*cos(i*0.017453)), round(obs1.y + (obs1.r)*sin(i*0.017453)), 0);
		}

	    // End here

	    // This script will be the method used to draw an obstacle
	    // Begin here
		for(i=0; i<360; i += round(300/obs2.r))
		{
			win.draw_point(round(obs2.x +(obs2.r)*cos(i*0.017453)), round(obs2.y + (obs2.r)*sin(i*0.017453)), 0);
		}

	    // End here


		


    }

    delete b1;

    return 0;
}
