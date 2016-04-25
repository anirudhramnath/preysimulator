/**
 * Project Untitled
 */


#include "Wolf.h"

/**
 * Wolf implementation
 */


	
Wolf::Wolf(SimulationController * environment, int position_x, int position_y):
Carnivore(environment, position_x, position_y, 500){
	min_food_level = 500;
	max_food_level = 5000;
	max_age = 50;
	reproduction_treshold = 50;
	evading_treshold = 2500;
	rate_of_metabolism = 100;

}
Creature * Wolf::getInstance(){
    Creature * wolf = new Wolf(environment, 0, 0);
	return wolf;
}