#include <string>
#include "Creature.h"
#include "CreatureFactory.h"
#include "Grass.h"
#include "Deer.h"
#include "Wolf.h"

CreatureFactory::CreatureFactory(){
}

Creature * CreatureFactory::getCreature(SimulationController * environment, std::string creature_type, int position_x, int position_y)
{
	if (creature_type.compare("GRASS") == 0) {
		return new Grass(environment, position_x, position_y);
	}
	else if (creature_type.compare("DEER") == 0) {
		return new Deer(environment, position_x, position_y);
	}
	else if (creature_type.compare("WOLF") == 0) {
		return new Deer(environment, position_x, position_y);
	}

}