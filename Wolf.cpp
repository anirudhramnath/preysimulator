/**
 * Project Untitled
 */


#include "Wolf.h"
#include "Deer.h"

/**
 * Wolf implementation
 */


	
Wolf::Wolf(SimulationController * environment, int position_x, int position_y):
Carnivore(environment, position_x, position_y, 150){
	min_food_level = 150;
	max_food_level = 300;
	max_age = 25;
    reproduction_age = 10;
	reproduction_food = 200;
    reproduction_probability = 40;
	evading_treshold = 2500;
	rate_of_metabolism = 10;

}
void Wolf::move(){
    Carnivore::moveTowards(typeid(Deer));
}
Creature * Wolf::getInstance(){
    Creature * wolf = new Wolf(environment, 0, 0);
	return wolf;
}