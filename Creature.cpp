/**
 * Project Untitled
 */


#include "Creature.h"
#include "CreatureFactory.h"
/**
 * Creature implementation
 */
Creature::Creature(Environment * environment, int position_x, int position_y){
	current_food_level = min_food_level;
	is_alive = true;
	Creature::position_x = position_x;
	Creature::position_y = position_y;
	Creature::environment = environment;
}
/**
 * @param food_count
 */
void setPosition(int position_x, int position_y){
	Creature::position_x = position_x;
	Creature::position_y = position_y;
}
void Creature::addFoodLevel(int food_points) {
	current_food_level += food_points;
	if(current_food_level < 0)
		current_food_level = 0;
	else if (current_food_level>max_food_level)
		current_food_level = max_food_level;
}

Creature * Creature::getInstance(){
	return Creature(environment, 0, 0);
}
void Creature::reproduce(){
	if((float)current_food_level/(float)max_food_level*100 > reproduction_treshold){
		environment->addChild(getInstance(), position_x, position_y);
	}
}

void Creature::metabolize() {
	addFoodLevel(rate_of_metabolism);
}
void Creature::routine()=0;