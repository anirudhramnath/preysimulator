/**
 * Project Untitled
 */

#include "EnvironmentInterfaces.h"
#include "Herbivore.h"

/**
 * Herbivore implementation
 */

Herbivore::Herbivore(Environment * environment, int position_x,int position_y):Animal(environment, position_x, position_y){
	
}

void Herbivore::getFood(){
	this.grace();
}

void Herbivore::grace(){
	Grass * grass = (Grass *)environment.getCreaturesIn(Grass, position_x, position_y);
	this.addFoodLevel(grass.getGraced(this.currentAppetite()));
}

void Herbivore::move(){
	Creature * nearest_creature = environment->getNearestCreature(Grass, position_x, position_y);
	if(nearest_creature != 0){
		if(abs(position_x-nearest_creature->position_x)>abs(position_y-nearest_creature->position_y){
			if(position_x-nearest_creature->position_x>0){
                changePosition(LEFT);
			}
			else if(position_x-nearest_creature->position_x<0){
				changePosition(RIGHT);
			}
		}
		else{
			if(position_y-nearest_creature->position_y>0){
                changePosition(UP);
			}
			else if(position_y-nearest_creature->position_y<0){
				changePosition(DOWN);
			}	
		}
	}
}

void Herbivore::evade() {

}