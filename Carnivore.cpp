/**
 * Project Untitled
 */
#include <cstdlib>
#include <typeinfo>
#include <iostream>

#include "Carnivore.h"
#include "Deer.h"
/**
 * Carnivore implementation
 */


Carnivore::Carnivore(SimulationController * environment, int position_x, int position_y, int min_food):Animal(environment, position_x, position_y, min_food){
	
}
void Carnivore::chase() {

}

void Carnivore::getFood(){
	hunt();
}

void Carnivore::hunt(){
	vector<Creature *>* list_of_animals = environment->getCreaturesAround(typeid(Deer), position_x, position_y);
	cout<<list_of_animals->size()<<"count\n";
	if(list_of_animals->size() !=0){
		Deer * deer = (Deer *)(list_of_animals->at(0));
		this->addFoodLevel(deer->getConsumed(0));
	}	
}


void Carnivore::move(){
	Creature * nearest_creature = environment->getNearestCreature(typeid(Deer), position_x, position_y);
	cout<<"position of animal being chased"<<nearest_creature->position_x<<", "<<nearest_creature->position_y<<"\n";
	try{
		if(nearest_creature != 0){
			if(abs(position_x-nearest_creature->position_x)>abs(position_y-nearest_creature->position_y)){
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
		cout<<"Standard Chase Failed\n";
	}
		
	std::vector<std::pair<int, int> > positions = std::vector<std::pair<int, int> >();
	positions.push_back(std::pair<int, int>(position_x-1, position_y));
	positions.push_back(std::pair<int, int>(position_x+1, position_y));
	positions.push_back(std::pair<int, int>(position_x, position_y-1));
	positions.push_back(std::pair<int, int>(position_x, position_y+1));

	while(positions.size() > 0){
		try{
			int selected_index = rand()%positions.size();
			std::pair<int, int> selected_position = positions[selected_index];
			setPosition(selected_position.first, selected_position.second);
			positions.erase(positions.begin()+selected_index);
			return;
		}
		catch(NotEmpty){

		}
	}
				
	
}

