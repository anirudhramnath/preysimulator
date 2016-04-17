/**
 * Project Untitled
 */
#include <typeinfo>

#include "Carnivore.h"
#include "Deer.h"
/**
 * Carnivore implementation
 */


Carnivore::Carnivore(SimulationController * environment, int position_x, int position_y):Animal(environment, position_x, position_y){
	
}
void Carnivore::chase() {

}

void Carnivore::getFood(){
	hunt();
}

void Carnivore::hunt(){
	vector<Creature *> list_of_animals = environment->getCreaturesAround(typeid(Deer), position_x, position_y);
	Deer * deer = (Deer *)list_of_animals[0];
	this->addFoodLevel(deer->getConsumed());
}

Creature * Carnivore::getInstance(){
	return (Creature *)Carnivore(environment, 0, 0);
}

void Carnivore::move(){
	Creature * nearest_creature = environment->getNearestCreature(typeid(Deer), position_x, position_y);
	try{
		if(nearest_creature != 0){
			if(abs(position_x-nearest_creature->position_x)>abs(position_y-nearest_creature->position_y){
				if(position_x-nearest_creature->position_x>0){
	                setPosition(position_x-1, position_y);
	                return;
				}
				else if(position_x-nearest_creature->position_x<0){
					setPosition(position_x+1, position_y);
					return;
				}
			}
			else{
				if(position_y-nearest_creature->position_y>0){
	                setPosition(position_x, position_y-1);
	                return;
				}
				else if(position_y-nearest_creature->position_y<0){
					setPosition(position_x, position_y+1);
					return;
				}	
			}
		}
	}
	catch(NotEmpty){

	}
		
	int positions[4][2] = {
		{position_x-1, position_y},
		{position_x+1, position_y},
		{position_x, position_y-1},
		{position_x, position_y+1}
	}
	for(int i =0;i<4;i++){
		try{
			setPosition(positions[i][0], positions[i][1]);
			return;
		}
		catch(NotEmpty){

		}
	}
				
	
}