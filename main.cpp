// Std lib
#include <stdio.h>

// Graphic lib
#include "bwindow.h"

// Boid struct
#include "Obstacle.h"

// Boid classes
#include "Border.h"


int main()
{
    bwindow win(640,480);
    printf("%d\n",win.init());
    win.map();
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
		for(i=0;i<200;i++)
			win.draw_point(i,88,0xFF00);
		win.draw_line(100,100,200,200,0xFF0000);
		win.draw_text(10,10,0x0,"Hello World",strlen("Hello World"));
		win.draw_square(200,200,220,220,0xFF00);
		win.draw_fsquare(400,400,440,440,0xFF00);

	    Border* b1 = new Border(0, 20, 20, 450, 0xDD0000);

	    // This script will be the method used to draw a border
	    // Begin here
	    
	    int* bordPoints = new int [4];
	    bordPoints = b1->get_points();
	    win.draw_line(bordPoints[0], bordPoints[1], bordPoints[2], bordPoints[3], b1->get_color());

	    // End here

	    delete bordPoints;
	    delete b1;

    }





    return 0;
}
