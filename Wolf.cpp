/**
 * Project Untitled
 */


#include "Wolf.h"

/**
 * Wolf implementation
 */


	
Wolf::Wolf(SimulationController * environment, int position_x, int position_y):Carnivore(environment, position_x, position_y){
	min_food_level = 500;
	max_food_level = 5000;
	max_age = 50;
	reproduction_treshold = 50;
	evading_treshold = 2500;
	rate_of_metabolism = 50;

}
Creature * Wolf::getInstance(){
	return (Creature *) new Wolf(environment, 0, 0);
}