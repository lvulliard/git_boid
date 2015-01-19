//****************************************************************************
//
//                                    Agent
//
//****************************************************************************



#ifndef __Agent_H__
#define __Agent_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>


// ===========================================================================
//                                Project Files
// ===========================================================================
#include "DefVal.h"
#include "Border.h"


// ===========================================================================
//                              Class declarations
// ===========================================================================






class Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(double x, double y, unsigned int c);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline double get_x () const;
    inline double get_dx () const;
    inline double get_y () const;
    inline double get_dy () const;
    inline unsigned int get_color () const;

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    virtual void move(Border* borders, unsigned int nb, Agent** tab, int index) =0;
    virtual void set_speed() = 0;
    double speed_from_borders(Border* borders, unsigned int nb);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    Agent(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };

    Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    //
    unsigned int color, state;
    // Agent view range "r"
    // Hitbox sometimes called "c"
    double x, y, dx, dy, r, hitbox;
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
double Agent::get_x() const
{
    return x;
}

double Agent::get_y() const
{
    return y;
}

double Agent::get_dx() const
{
    return dx;
}

double Agent::get_dy() const
{
    return dy;
}

unsigned int Agent::get_color() const
{
    return color;
}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __Agent_H__

