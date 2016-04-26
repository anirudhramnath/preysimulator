/**
 * Project Untitled
 */


#include "Deer.h"

/**
 * Deer implementation
 */



Deer::Deer(SimulationController * environment,int position_x,int position_y)
:Herbivore(environment, position_x, position_y, 50)
{

	Deer::min_food_level = 50;
	Deer::max_food_level = 150;
	Deer::max_age =10;
	Deer::reproduction_food = 70;
    Deer::reproduction_age = 8;
    Deer::reproduction_probability = 70;
	Deer::evading_treshold = 2500;
	Deer::rate_of_metabolism = 5;
	
}

Creature * Deer::getInstance(){
	return (Creature *) new Deer(environment, 0, 0);
}