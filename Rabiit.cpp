/**
 * Project Untitled
 */


#include "Rabiit.h"

/**
 * Rabiit implementation
 */
Rabbit::Rabbit(SimulationController * environment, int position_x, int position_y): 
Herbivore(environment, position_x, position_y, 10){
    Rabbit::min_food_level = 10;
    Rabbit::max_food_level = 45;
    Rabbit::max_age =25;
    Rabbit::reproduction_food = 40;
    Rabbit::reproduction_age = 10;
    Rabbit::reproduction_probability = 50;
    Rabbit::evading_treshold = 2500;
    Rabbit::rate_of_metabolism = 3;
}
Creature * Rabbit::getInstance(){
    Creature * rabbit = new Rabbit(environment, 0, 0);
	return rabbit;
}