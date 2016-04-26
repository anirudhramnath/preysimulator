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
#include "Rabiit.h"
#include "Lion.h"

/**
 * SimulationController implementation
 */
using namespace std;

SimulationController::SimulationController(){
	int x;
	int y;
	int random_position;
	int no_of_deer = 5;
    int no_of_wolf = 3;
    int no_of_rabbit = 10;
    int no_of_rat = 5;
    int no_of_lion = 2;
	Creature * new_creature;
	grid_width = 30;
	grid_height = 30;
	creature_location_map = std::map<int, Creature *>();
	creature_factory = new CreatureFactory();
	list_of_creatures = std::vector<Creature *>();
	for(x=0;x<grid_width;x++)
	{
		for(y=0;y<grid_height;y++)
		{
			list_of_creatures.push_back(creature_factory->getCreature(this, std::string("GRASS"), x, y));
			//cout<<list_of_creatures.size();
		}
	}
	//cout<<"Grass Created\n";
	for(int i=0;i<no_of_deer; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				//cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				//cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("DEER"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
	//cout<<"Deer Created\n";

	for(int i=0;i<no_of_rabbit; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				//cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				//cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("RABBIT"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
	//cout<<"Rabbit Created\n";

	for(int i=0;i<no_of_rat; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				//cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				//cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("RAT"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
	//cout<<"Rat Created\n";

	for(int i=0;i<no_of_wolf; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				//cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				//cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("WOLF"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
	//cout<<"Wolf Created\n";
	for(int i=0;i<no_of_lion; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;
			try{
				creature_location_map.at(random_position);
				//cout<<"Location Not Empty\n";
			}
			catch(const std::out_of_range & e){
				//cout<<"Empty Location Found\n";
				new_creature = creature_factory->getCreature(this, std::string("LION"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
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
			if(creature_in_cell != 0)
			{
			if(typeid(*creature_in_cell)==class_type){
				creatures->push_back(creature_in_cell);
			}
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
	//cout<<creatures->size()<<"\n";
	return creatures;
}

Creature * SimulationController::getNearestCreature(const type_info & class_type, int position_x, int position_y){
	int min_distance = grid_height*grid_width - 1;
	Creature * closest_creature = 0;
	for(map<int, Creature *>::iterator it= creature_location_map.begin(); it != creature_location_map.end(); it++){
		////cout<<"IT first "<<it->first<<endl;
		if(it->second != 0){
		int current_distance = abs(it->second->position_x-position_x) + abs(it->second->position_y-position_y);
		Creature * current_creature = it->second;
		////cout<<"Creature type in NearestCreature"<<typeid(*current_creature).name()<<"\n";
		if(current_distance < min_distance && class_type == typeid(*current_creature)){
			min_distance = current_distance;
			closest_creature = current_creature;
		}
	}
	else{
		//cout<<"MAp has null value"<<endl;
	}
	}
	//cout<<"returning getNearestCreature"<<endl;
	return closest_creature;
}

void SimulationController::changePosition(Creature * creature,int position_x,int position_y){
	//cout<<"Position hange syuir&&&&&"<<endl;

	try{
		if(position_x<0 || position_x>grid_height-1 || position_y<0 || position_y>grid_width-1){
			throw NotEmpty();
		}
		Creature * creature_in_position = creature_location_map.at(position_x*grid_width+position_y);
		throw NotEmpty();
	}
	catch(std::out_of_range e){

		//cout<<"Position cahnge check success 111111111"<<endl;
		map<int, Creature *>::iterator it = creature_location_map.find(creature->position_x*grid_width+creature->position_y);
		//cout<<"Position cahnge check success 2222222"<<endl;
		creature_location_map[position_x*grid_width+position_y] = creature;
		//cout<<"Position cahnge check success 3333333!"<<endl;
		creature_location_map.erase(creature->position_x*grid_width+creature->position_y);
		//cout<<"Position cahnge check success !!!!!!!"<<endl;
		
	}
}

std::vector<Creature *> * SimulationController::getCreatureList() {
	std::vector<Creature *> * creatures = new std::vector<Creature *>();
	for (int i=0; i < list_of_creatures.size(); ++i) {
		creatures->push_back(list_of_creatures[i]);
	}

	std::map<int, Creature*>::iterator mapIter;
	for (mapIter = creature_location_map.begin(); mapIter != creature_location_map.end(); ++mapIter) {
       creatures->push_back(mapIter->second);
    }

    return creatures;
}

void SimulationController::addChild(Creature * child, int position_x, int position_y){
	std::vector<std::pair<int, int> > * positions = getPointsAround(position_x, position_y);
	//cout <<endl<< "List of possible points around "<<position_x<<","<<position_y<<endl;
	for(std::vector<pair<int, int> >::iterator item=positions->begin();item!=positions->end();item++){
		//cout <<endl<< "ITEM first, second "<<item->first<<","<<item->second<<endl;
		try{
		Creature * creature = creature_location_map.at(item->first*grid_width+item->second);
		//cout<<"got list of child"<<endl;
		}
		catch(std::out_of_range e){
			if(child != 0){
			child->setPosition(item->first, item->second);
			creature_location_map[item->first*grid_width+item->second] = child;
			//cout<<"CHild added KKKKKKKKKK"<<endl;
			return;
		}
		else{
			//cout<<"child null *****"<<endl;
		}
		}
	}
}
void SimulationController::removeCreature(Creature * creature){
	std::map<int, Creature*>::iterator mapIter;
	/*for (mapIter = creature_location_map.begin(); mapIter != creature_location_map.end(); ++mapIter) {
		if(creature == mapIter->second){
			creature_location_map.erase(mapIter);
			//cout<<"DELETING *********55555555555"<<endl;
		}
    }*/
	creature_location_map.erase(creature->position_x*grid_width+creature->position_y);
	//cout<<"DELETING *********55555555555"<<endl;

}

void SimulationController::printMap (){
	std::map<int, Creature*>::iterator mapIter;
	//cout<<"PRINTING MAP"<<endl;
	for (mapIter = creature_location_map.begin(); mapIter != creature_location_map.end(); ++mapIter) {
		//cout<<mapIter->first<<typeid(* mapIter->second).name()<<endl;
		
	}
}

std::vector<std::pair<int, int> > * SimulationController::getPointsAround(int position_x, int position_y){
	int list_of_coordinates[8][2] ={
		{position_x-1, position_y-1},
		{position_x-1, position_y},
		{position_x-1, position_y+1},
		{position_x, position_y-1},
		{position_x, position_y+1},
		{position_x+1, position_y-1},
		{position_x+1, position_y},
		{position_x+1, position_y+1}
	};
	std::vector<std::pair<int, int> > * positions = new std::vector<std::pair<int, int> >();
	for(int i=0;i<8;i++){
		if(list_of_coordinates[i][0]>=0 && list_of_coordinates[i][0]<grid_height && list_of_coordinates[i][1]>=0 && list_of_coordinates[i][1]<grid_width)
			positions->push_back(std::pair<int, int>(list_of_coordinates[i][0], list_of_coordinates[i][1]));
	}
	return positions;
}

void SimulationController::start() {
	vector<Creature *> * creatures = getCreatureList();
    for (int i = 0; i < creatures->size(); ++i) {
        creatures->at(i)->routine();
    }
    /*
	Wolf * wolf = (Wolf *)(getNearestCreature(typeid(Wolf), 10, 10));
	//cout<<wolf->position_x<<","<<wolf->position_y<<"\n";
	
		wolf->routine();

		//wolf->metabolize();
		//wolf->growOld();
		//cout<<"After movement ..."<<wolf->is_alive<<"\n";
		//cout<<wolf->position_x<<","<<wolf->position_y<<wolf->current_food_level<<"\n";
	
	
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

