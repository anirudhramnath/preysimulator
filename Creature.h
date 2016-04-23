/**
 * Project Untitled
 */


#ifndef _CREATURE_H
#define _CREATURE_H

#include "SimulationController.h"

class SimulationController;

class Creature {

protected: 
    

public:
    int reproduction_treshold;
    int min_food_level;
    int max_food_level;
    int rate_of_metabolism;
    int current_food_level;
    SimulationController * environment;
    int position_x;
    int position_y;
    bool is_alive;
    /**
     * @param food_count
     */
    Creature(SimulationController * , int, int, int);
    void setPosition(int position_x, int position_y);
    void addFoodLevel(int food_points);
    void virtual metabolize();
    void virtual routine()=0;
    void reproduce();
    virtual Creature * getInstance();
    virtual int getConsumed(int )=0;
};

#endif //_CREATURE_H