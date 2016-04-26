/**
 * Project Untitled
 */


#include "Rat.h"

/**
 * Rat implementation
 */



Rat::Rat(SimulationController * environment,int position_x,int position_y)
:Herbivore(environment, position_x, position_y, 50)
{

    Rat::min_food_level = 50;
    Rat::max_food_level = 150;
    Rat::max_age =10;
    Rat::reproduction_food = 70;
    Rat::reproduction_age = 8;
    Rat::reproduction_probability = 70;
    Rat::evading_treshold = 2500;
    Rat::rate_of_metabolism = 5;
    
}

Creature * Rat::getInstance(){
    return (Creature *) new Rat(environment, 0, 0);
}