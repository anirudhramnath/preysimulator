/**
 * Project Untitled
 */


#include "Animal.h"

/**
 * Animal implementation
 */

void Animal::Animal(SimulationController * environment, int position_x, int position_y):Creature(environment, position_x, position_y){
	age = 0;
	is_alive = 1;
}



/**
 * @param food_level
 */


int Animal::getConsumed(){
	if(current_food_level < evading_treshold)
		die();
		return current_food_level;
	else
		return 0;
}

void Animal::growOld() {
    if(age == max_age){
    	die();
    }
}

void virtual Animal::getFood()=0;

void Animal::reproduce() {

}


Creature * Animal::getInstance(){
	return (Creature *)Animal(environment, 0, 0);
}

void setPosition(int position_x, int position_y){
	environment->changePosition(position_x, position_y);
	Creature::position_x = position_x;
	Creature::position_y = position_y;
}

void Animal::die() {
	is_alive = 0;
}
