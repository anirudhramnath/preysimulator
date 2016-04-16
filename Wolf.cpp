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
	reproduction_treshold = 50;
	rate_of_metabolism = 50;

}
Creature * Wolf::getInstance(){
	return (Creature *) new Wolf(environment, 0, 0);
}