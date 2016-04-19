/**
 * Project Untitled
 */
#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "Herbivore.h"
#include "Grass.h"
using namespace std;
/**
 * Herbivore implementation
 */

Herbivore::Herbivore(SimulationController * environment, int position_x,int position_y, int min_food):Animal(environment, position_x, position_y, min_food){
	
}

void Herbivore::getFood(){
	this->grace();
}

void Herbivore::grace(){
	Grass * grass = (Grass *)environment->getCreaturesIn(typeid(Grass), position_x, position_y);
	this->addFoodLevel(grass->getGraced(10)); // dont need appetite. we can impl it in Grass class. more grass = more food grazed
}

void Herbivore::move(){
	vector<Creature *>* grasses_around = environment->getCreaturesAround(typeid(Grass), position_x, position_y);
	int max_grass_food = -1;
	Grass * max_grass;
	cout<<"NO OF CANDIDATES"<<grasses_around->size()<<"\n";
	for(int i=0;i<grasses_around->size();i++){
		cout<<"grass at:"<<grasses_around->at(i)->position_x<<","<<grasses_around->at(i)->position_y<<"has:"<<grasses_around->at(i)->current_food_level<<"\n";
		if(grasses_around->at(i)->current_food_level > max_grass_food){
			max_grass = (Grass *)grasses_around->at(i);
			max_grass_food = grasses_around->at(i)->current_food_level;

		}
	}
	cout<<"max grass position"<<max_grass->position_x<<","<<max_grass->position_y<<"\n";
	if(max_grass_food != 0){
		try{
			if(position_x-max_grass->position_x > 0)
			{
				setPosition(position_x-1, position_y);
				return;
			}
			else if(position_x-max_grass->position_x < 0) {
				
				setPosition(position_x+1, position_y);
				return;
			}
			else{
				if(position_y-max_grass->position_y > 0)
				{
					setPosition(position_x, position_y-1);
					return;
				}
				else if(position_y-max_grass->position_y < 0) {
					setPosition(position_x, position_y+1);
					return;
				}	
			}
		}
		catch(NotEmpty){
			cout<<"hit";
		}
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
