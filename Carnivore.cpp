/**
 * Project Untitled
 */


#include "Carnivore.h"

/**
 * Carnivore implementation
 */


void Carnivore::chase() {

}

void Carnivore::getFood(){
	this->hunt();
}

void Carnivore::hunt(){
	vector<Creature *> list_of_animals = environment->getCreaturesAround(Deer, position_x, position_y);
	Deer * deer = (Deer *)list_of_animals[0];
	this->addFoodlevel(deer->getHunted());
}

Creature * Carnivore::getInstance(){
	return (Creature *)Carnivore(environment, 0, 0);
}

void Carnivore::move(){
	Creature * nearest_creature = environment->getNearestCreature(Grass, position_x, position_y);
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