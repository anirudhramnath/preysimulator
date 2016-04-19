/**
 * Project Untitled
 */
#include <cstdlib>
#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include <stdexcept>

#include "SimulationController.h"
#include "CreatureFactory.h"
#include "Creature.h"
#include "Grass.h"
#include "Wolf.h"

/**
 * SimulationController implementation
 */
using namespace std;

SimulationController::SimulationController(){
	int x;
	int y;
	int random_position;
	int no_of_deer = 10;
	int no_of_wolf = 10;
	Creature * new_creature;
	grid_width = 20;
	grid_height = 20;
	creature_location_map = std::map<int, Creature *>();
	creature_factory = new CreatureFactory();
	list_of_creatures = std::vector<Creature *>();
	for(x=0;x<grid_width;x++)
	{
		for(y=0;y<grid_height;y++)
		{
			list_of_creatures.push_back(creature_factory->getCreature(this, std::string("GRASS"), x, y));
			cout<<list_of_creatures.size();
		}
	}
	cout<<"Grass Created\n";
	for(int i=0;i<no_of_deer; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("DEER"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
	cout<<"Deer Created\n";

	for(int i=0;i<no_of_wolf; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("WOLF"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
	cout<<"Wolf Created\n";
}

Creature * SimulationController::getCreaturesIn(const type_info & class_type, int position_x, int position_y){
	Creature * creature_in_cell;
	try{
		creature_in_cell = creature_location_map.at(position_x*grid_width+position_y);
		if(typeid(*creature_in_cell)==class_type){
			return creature_in_cell;
		}
	}
	catch(std::out_of_range){

	}
	creature_in_cell = list_of_creatures[position_x*grid_width+position_y];
	if(typeid(*creature_in_cell)==class_type){
		return creature_in_cell;
	}
}

std::vector<Creature *>* SimulationController::getCreaturesAround(const type_info & class_type, int position_x, int position_y){
	Creature * creature_in_cell;
	int list_of_coordinates[][2]={
		{position_x-1,position_y-1},
		{position_x-1,position_y},
		{position_x-1,position_y+1},
		{position_x,position_y-1},
		{position_x,position_y+1},
		{position_x+1,position_y-1},
		{position_x+1,position_y},
		{position_x+1,position_y+1},
	};
	vector<int> list_of_surrounding_cells = vector<int>();
	for(int i=0;i<8;i++){
		if(list_of_coordinates[i][0]>=0 && list_of_coordinates[i][0]<grid_height && list_of_coordinates[i][1]>=0 && list_of_coordinates[i][1]<grid_width)
			list_of_surrounding_cells.push_back(list_of_coordinates[i][0]*grid_width+list_of_coordinates[i][1]);
	}
	

	std::vector<Creature *>* creatures = new std::vector<Creature *>();

	for(int i = 0; i<list_of_surrounding_cells.size();i++)
	{
		try{
			creature_in_cell = creature_location_map.at(list_of_surrounding_cells[i]);
			if(typeid(*creature_in_cell)==class_type){
				creatures->push_back(creature_in_cell);
			}
		}
		catch(std::out_of_range e){

		}
		try{

			creature_in_cell = list_of_creatures.at(list_of_surrounding_cells[i]);
			if(typeid(*creature_in_cell)==class_type){
				creatures->push_back(creature_in_cell);
			}
			
		}
		catch(std::out_of_range e){

		}
	}
	cout<<creatures->size()<<"\n";
	return creatures;
}

Creature * SimulationController::getNearestCreature(const type_info & class_type, int position_x, int position_y){
	int min_distance = grid_height*grid_width - 1;
	Creature * closest_creature = 0;
	for(map<int, Creature *>::iterator it= creature_location_map.begin(); it != creature_location_map.end(); it++){
		int current_distance = abs(it->first-(position_x*grid_width + position_y));
		Creature * current_creature = it->second;
		//cout<<"Creature type"<<typeid(*current_creature).name()<<"\n";
		if(current_distance < min_distance && class_type == typeid(*current_creature)){
			min_distance = current_distance;
			closest_creature = current_creature;
		}
	}
	return closest_creature;
}

void SimulationController::changePosition(Creature * creature,int position_x,int position_y){
	try{
		if(position_x<0 || position_x>grid_height-1 || position_y<0 || position_y>grid_width-1){
			throw NotEmpty();
		}
		Creature * creature_in_position = creature_location_map.at(position_x*grid_width+position_y);
		throw NotEmpty();
	}
	catch(std::out_of_range e){
		map<int, Creature *>::iterator it = creature_location_map.find(creature->position_x*grid_width+creature->position_y);
		creature_location_map.erase(it);
		creature_location_map[position_x*grid_width+position_y] = creature;
	}
}

std::vector<Creature *> SimulationController::getCreatureList() {
	std::vector<Creature *> creatures;
	for (int i=0; i < list_of_creatures.size(); ++i) {
		creatures.push_back(list_of_creatures[i]);
	}

	std::map<int, Creature*>::iterator mapIter;
	for (mapIter = creature_location_map.begin(); mapIter != creature_location_map.end(); ++mapIter) {
       creatures.push_back(mapIter->second);
    }

    return creatures;
}

void SimulationController::addChild(Creature * child, int position_x, int position_y){
	int positions[8][2] ={
		{position_x-1, position_y-1},
		{position_x-1, position_y},
		{position_x-1, position_y+1},
		{position_x, position_y-1},
		{position_x, position_y+1},
		{position_x+1, position_y-1},
		{position_x+1, position_y},
		{position_x+1, position_y+1}
	};
	for(int i=0;i<8;i++){
		Creature * creature = creature_location_map[positions[i][0]*grid_width+positions[i][1]];
		if(creature == 0){
			creature_location_map[positions[i][0]*grid_width+positions[i][1]] = child;
		}
	}
}

void SimulationController::start() {
	
	Wolf * wolf = (Wolf *)(getNearestCreature(typeid(Wolf), 10, 10));
	cout<<wolf->position_x<<","<<wolf->position_y<<"\n";
	for(int i=0;i<25;i++){
		wolf->move();
		wolf->getFood();
		//wolf->metabolize();
		//wolf->growOld();
		cout<<"After movement ..."<<wolf->is_alive<<"\n";
		cout<<wolf->position_x<<","<<wolf->position_y<<wolf->current_food_level<<"\n";
	}
/*
	Grass * grass = (Grass *)getCreaturesIn(typeid(Grass), 0, 0);
	grass->getGraced(10);
	grass = (Grass *)getCreaturesIn(typeid(Grass), 0, 0);
	grass->getGraced(10);
	*/
}

void SimulationController::stop() {

}

void SimulationController::pause() {

}

