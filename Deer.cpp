/**
 * Project Untitled
 */


#include "Deer.h"

/**
 * Deer implementation
 */



Deer::Deer(SimulationController * environment,int position_x,int position_y):Herbivore(environment, position_x, position_y){
	Deer::min_food_level = 500;
	Deer::max_food_level = 5000;
	Deer::reproduction_treshold = 50;
	Deer::rate_of_metabolism = 50;
}

Creature * Deer::getInstance(){
	return (Creature *)Deer(environment, 0, 0);
}