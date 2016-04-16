/**
 * Project Untitled
 */


#include "Animal.h"
#include "SimulationController.h"

/**
 * Animal implementation
 */

Animal::Animal(SimulationController * environment, int position_x, int position_y):
Creature(environment, position_x, position_y){
	age = 0;
	is_alive = 1;
}



/**
 * @param food_level
 */


int Animal::getConsumed(int temp){
	if(current_food_level < evading_treshold) {
		die();
		return current_food_level;
	}
	else
		return 0;
}

void Animal::growOld() {
    if(age == max_age){
    	die();
    }
}


void Animal::reproduce() {

}


/*Creature * Animal::getInstance(){
	return (Creature *)new Animal(environment, 0, 0);
}*/

void Animal::setPosition(int position_x, int position_y){
	environment->changePosition(this, position_x, position_y);
	Creature::position_x = position_x;
	Creature::position_y = position_y;
}

void Animal::die() {
	is_alive = 0;
}
