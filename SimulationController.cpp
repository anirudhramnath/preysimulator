/**
 * Project Untitled
 */
#include <cstdlib>
#include <vector>
#include <string>

#include "SimulationController.h"
#include "CreatureFactory.h"


/**
 * SimulationController implementation
 */

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
void SimulationController::start() {

}

void SimulationController::stop() {

}

void SimulationController::pause() {

}