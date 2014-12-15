#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <X11/keysymdef.h>
#include <X11/keysym.h>

#define ERR_BAD_FONT -10
#define ERR_BAD_DISPLAY -5
#define MIN_WIDTH 350
#define MIN_HEIGHT 250

#define BBPRESS 1
#define BKPRESS 2
#define BEXPOSE 3
#define BCONFIGURE 4

class bwindow
{
    Display * display;
    int screen;
    Window win;
    unsigned int width;
    unsigned int height;
    unsigned int display_width;
    unsigned int display_height;
    int	x;
    int y;
    unsigned int border_width ;
    unsigned int line_width;

    char window_name [100];
    char icon_name[100];
    char fontname[100];
    XSizeHints size_hints;
    XEvent report;
    XFontStruct *font_info;
    char lastkey[100];
    GC gc;
// private internal function 

// ***** clean_up() : cleans all the stuff (called in destructor
    void clean_up();
// ***** load_font() : prepare the font to be loaded. font_name attributes must have been initialised  (called in init() function
    int load_font();
// ***** get_gc() :  prerare the graphic context : internal Xlib stuff (called in init() function 
    int get_gc();
 public:

// object handling function 
// ***** default constructor make a minimum widht and height window and a default name and font
    bwindow();
// ****** constructor with width and height  and a default name and font
    bwindow(int w,int h);
// *****  as above but with the window name 
    bwindow(int w,int h, char * name);
// ***** as above plus the fontname 
    bwindow(int w,int h,char * name,char * fontname);
// ***** destructor (calls clean_up()
    ~bwindow();

// admin and system function    
// ***** reload_font : takes the font name in argument; sets it and load the font send: ERR_BAD_FONT if it did not work and 0 otherwise
    int reload_font(char *);
// ***** init() makes all the initialisation and calls load_font and get_gc; throws back ERR_BAD_FONT from the font function and ERR_BAS_DISPLAY if there is no display sends 0 otherwise
    int init();
// ***** map(); map actually the window to the screen. The window is displayed if the event function handler is called 
    void map();
// ****** parse_even(); verify all the captured event by default (expose, configure, mousebutton and key) return the actual type of the event 
    int parse_event();

// drawing functions 

// ***** draw_text(); print some text at the screen; the text is a string of length len; it is printed at coordinates x,y and with color color
    void draw_text(int x, int y, unsigned int color, char * text, int len);
// ****** draw_line() : display a line from point (x1,y1) to (x2,y2) with color color 
    void draw_line(int x1, int y1, int x2, int y2, unsigned int color);
// ****** draw_square(): draw a rectangle from point (x1,y1) to (x2,y2) with color color fsquare is a filled rectangle
    void draw_square(int x1, int y1, int x2, int y2, unsigned int color);
    void draw_fsquare(int x1, int y1, int x2, int y2, unsigned int color);
// ***** draw_point(): put a pixel at x1,y1 with color color
    void draw_point(int x1, int y1, unsigned int color);
 
    

//   getters
    char * get_lastkey();
    unsigned int get_width();
    unsigned int get_height();

};
