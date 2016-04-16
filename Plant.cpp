/**
 * Project Untitled
 */


#include "Plant.h"

/**
 * Plant implementation
 */

Plant::Plant(SimulationController * environment, int position_x, int position_y):Creature(environment, position_x, position_y)
{
}
/**
 * @param food_level
 */

int Plant::getConsumed(int food_demand){
	int return_value;
	if(current_food_level < food_demand){
		return_value = current_food_level;
	}
	else{
		return_value = food_demand;
	}
	addFoodLevel(-food_demand);
	return return_value;
}

int virtual Plant::getGraced(int food_level) {
	int consumable_amount;
	if(current_food_level > food_level){
		consumable_amount = food_level;
	}
	else{
		consumable_amount = current_food_level;
	}
	addFoodLevel(-consumable_amount);
	return consumable_amount;

}
Creature * Plant::getInstance(){
	return (Creature *)Plant(environment, 0, 0);
}

void virtual routine(){
	metabolise();
}