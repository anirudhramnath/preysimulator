/**
 * Project Untitled
 */
#include <cstdlib>
#include <iostream>
#include "Creature.h"

/**
 * Creature implementation
 */

Creature::Creature(SimulationController * environment, int position_x, int position_y, int min_food){
	current_food_level = min_food;
	is_alive = true;
	Creature::position_x = position_x;
	Creature::position_y = position_y;
	Creature::environment = environment;
}
/**
 * @param food_count
 */
void Creature::setPosition(int position_x, int position_y){
	this->position_x = position_x;
	this->position_y = position_y;
}
void Creature::addFoodLevel(int food_points) {
	//cout<<"Before adding"<<current_food_level<<"\n";
	current_food_level += food_points;
	if(current_food_level < 0)
		current_food_level = 0;
	else if (current_food_level>max_food_level)
		current_food_level = max_food_level;
	//cout<<"after adding"<<food_points<<current_food_level<<"\n";
}


void Creature::reproduce(){
	if(current_food_level >= reproduction_food && 
		age >= reproduction_age && 
		rand()%100 <= reproduction_probability){
		environment->addChild(getInstance(), position_x, position_y);
	}
}

void Creature::metabolize() {
	addFoodLevel(-rate_of_metabolism);
}

// write destructor
