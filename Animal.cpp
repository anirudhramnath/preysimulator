/**
 * Project Untitled
 */


#include "Animal.h"

/**
 * Animal implementation
 */

void Animal::Animal(int position_x, int position_y):Creature(position_x, position_y){
	age = 0;
	is_alive = 1;
}
void Animal::grow(void food_count) {
	addFoodLevel(food_count);
}
void Animal::move(Direction direction_x, Direction direction_y) {
	switch direction_x:
	{
		case LEFT:
		position_x -= 1;
		break;
		case RIGHT:
		position_x += 1;
		break;
	}
	switch direction_y:
	{
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

void Animal::reproduce() {

}

void Animal::die() {
	is_alive = 0;
}
