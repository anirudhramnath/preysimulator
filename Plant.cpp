/**
 * Project Untitled
 */


#include "Plant.h"

/**
 * Plant implementation
 */

Plant::Plant(int position_x, int position_y):Creature(position_x, position_y)
{
}
/**
 * @param food_level
 */
int virtual Plant::getGraced(int food_level) {
	int consumable_amount;
	if(current_food_level > food_level){
		consumable_amount = food_level;
	}
	else{
		consumable_amount = current_food_level;
	}
	addFoodLevel(-consumable_amount);
	return consumable_amount

}
Creature * Plant::getInstance(){
	return (Creature *)Plant(environment, 0, 0);
}

void virtual routine(){
	metabolise();
}