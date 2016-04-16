/**
 * Project Untitled
 */


#include "Grass.h"
#include "SimulationController.h"
/**
 * Grass implementation
 */



Grass::Grass(SimulationController * environment, int position_x, int position_y):Plant(environment, position_x, position_y){
	min_food_level = 0;
	max_food_level = 500;
	reproduction_treshold = 101;
	rate_of_metabolism = -10;
}

Creature * Grass::getInstance(){
	return (Creature *)new Grass(environment, 0, 0);
}