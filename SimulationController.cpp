/**
 * Project Untitled
 */
#include <cstdlib>
#include <vector>
#include <string>
#include <typeinfo>

#include "SimulationController.h"
#include "CreatureFactory.h"

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
	creature_factory = CreatureFactory();
	std::vector<Creature *> list_of_creatures = std::vector<Creature *>();
	for(x=0;x<grid_width;x++)
	{
		for(y=0;y<grid_height;y++)
		{
			list_of_creatures.push_back(creature_factory.getCreature(std::string("GRASS"), x, y));
		}
	}

	for(int i=0;i<no_of_deer; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;

			if(creature_location_map.at(random_position) == NULL){
				new_creature = creature_factory.getCreature(std::string("DEER"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}

	for(int i=0;i<no_of_wolf; i++){
		do{
			random_position = rand()%(grid_width*grid_height);
			x = random_position/grid_width;
			y = random_position%grid_width;

			if(creature_location_map.at(random_position) == NULL){
				new_creature = creature_factory.getCreature(std::string("WOLF"), x, y);
				std::pair<int, Creature *> created_creature = std::pair<int, Creature *>(random_position, new_creature);
				creature_location_map.insert(created_creature);
				break;
			}
			random_position ++;
		}while(true);
	}
}

Creature * SimulationController::getCreaturesIn(string class_type, int position_x, int position_y){
	Creature * creature_in_cell = creature_location_map.at(position_x*grid_width+position_y);
	if(typeid(creature_in_cell)==typeid(class_type)){
		return creature_in_cell;
	}
	creature_in_cell = list_of_creatures[position_x*grid_width+position_y];
	if(typeid(creature_in_cell)==typeid(class_type)){
		return creature_in_cell;
	}
}

std::vector<Creature *>* SimulationController::getCreaturesAround(string class_type, int position_x, int position_y){
	int list_of_surrounding_cells[] = {
		(position_x-1)*grid_width+(position_y-1),
		(position_x-1)*grid_width+(position_y),
		(position_x-1)*grid_width+(position_y+1),
		(position_x)*grid_width+(position_y-1),
		(position_x)*grid_width+(position_y+1),
		(position_x+1)*grid_width+(position_y-1),
		(position_x+1)*grid_width+(position_y),
		(position_x+1)*grid_width+(position_y+1)
	};

	std::vector<Creature *>* list_of_creatures = new std::vector<Creature *>();
	for(int i = 0; i<8;i++)
	{
		Creature * creature_in_cell = creature_location_map.at(list_of_surrounding_cells[i]);
		if(typeid(creature_in_cell)==typeid(class_type)){
			list_of_creatures->push_back(creature_in_cell);
		}
		creature_in_cell = list_of_creatures->at(list_of_surrounding_cells[i]);
		if(typeid(creature_in_cell)==typeid(class_type)){
			list_of_creatures->push_back(creature_in_cell);
		}
	}
	return list_of_creatures;
}

Creature * SimulationController::getNearestCreature(string, int position_x, int position_y){
	int min_distance = grid_height*grid_width - 1;
	Creature * closest_creature = 0;
	for(map<int, Creature *>::iterator it= creature_location_map.begin(); it != creature_location_map.end(); it++){
		int current_distance = abs(it->first()-(position_x*grid_width + position_y));
		Creature * current_creature = it->second();
		if(current_distance < min_distance && typeid(class_type) == typeid(current_creature)){
			min_distance = current_distance;
			closest_creature = current_creature;
		}
	}
	return closest_creature;
}

void SimulationController::changePosition(Creature * creature,int position_x,int position_y){
	Creature * creature_in_position = creature_location_map.get(position_x*grid_width+position_y);
	if(creature_in_position == 0){
		map<int, Creature *>::iterator it = creature_location_map.at(creature->position_x*grid_width+creature->position_y);
		creature_location_map.erase(it);
		creature_location_map[position_x*grid_width+position_y] = creature;
	}
	else{
		throw NotEmpty();
	}
}

std::vector<Creature *> SimulationController::getCreatureList() {
	std::vector<Creature *> creatures;
	for (int i=0; i < list_of_creatures.size(); ++i) {
		creatures.push_back(list_of_creatures[i]);
	}

	std::map<std::int, Creature*>::iterator mapIter;
	for (mapIter = creature_location_map.begin(); mapIter != creature_location_map.end(); ++mapIter) {
       creatures.push_back(append(mapIter->second));
    }

    return creatures;
}

void addChild(Creature * child, int position_x, int position_y){
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

}

void SimulationController::stop() {

}

void SimulationController::pause() {

}
class NotEmpty: public std::exception{
};
