#include <string>
#include "Creature.h"
#include "CreatureFactory.h"
#include "Grass.h"
#include "Deer.h"
#include "Wolf.h"
#include "Rabiit.h"
#include "Rat.h"
#include "Lion.h"

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
		return new Wolf(environment, position_x, position_y);
	}
    else if (creature_type.compare("RABBIT") == 0) {
        return new Rabbit(environment, position_x, position_y);
    }
    else if (creature_type.compare("RAT") == 0) {
        return new Rat(environment, position_x, position_y);
    }
    else if (creature_type.compare("LION") == 0) {
        return new Lion(environment, position_x, position_y);
    }


}