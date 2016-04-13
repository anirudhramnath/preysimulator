/**
 * Project Untitled
 */


#include "Animal.h"

/**
 * Animal implementation
 */

void Animal::Animal(Environment * environment, int position_x, int position_y):Creature(environment, position_x, position_y){
	age = 0;
	is_alive = 1;
}
void Animal::grow(void food_count) {
	addFoodLevel(food_count);
}
void Animal::changePosition(Direction direction) {
	switch direction:
	{
		case LEFT:
		position_x -= 1;
		break;
		case RIGHT:
		position_x += 1;
		break;
		case UP:
		position_y -= 1;
		break;
		case DOWN:
		position_y += 1;
		break;
	}
}

/**
 * @param food_level
 */
void Animal::eat(int food_level) {
    current_food_level += food_level;
}

int Animal::getHunted(){
	if(current_food_level < evading_treshold)
		die();
		return current_food_level;
	else
		return 0;
}

void Animal::age() {
    if(age == max_age){
    	die();
    }
}

void virtual Animal::getFood()=0;

void Animal::reproduce() {

}

void virtual Animal::Routine(){

}

void setPosition(int position_x, int position_y){
	environment->changePosition(position_x, position_y);
	Creature::position_x = position_x;
	Creature::position_y = position_y;
}

void Animal::die() {
	is_alive = 0;
}
