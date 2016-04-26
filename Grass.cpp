/**
 * Project Untitled
 */


#include "Grass.h"
#include "SimulationController.h"
/**
 * Grass implementation
 */



Grass::Grass(SimulationController * environment, int position_x, int position_y):Plant(environment, position_x, position_y, 10){
	min_food_level = 10;
	max_food_level = 50;
	reproduction_food = 301;
	rate_of_metabolism = -3;
}

Creature * Grass::getInstance(){
	return (Creature *)new Grass(environment, 0, 0);
}
