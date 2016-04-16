#include <string>
#include "Creature.h"
#include "CreatureFactory.h"
#include "Grass.h"
#include "Deer.h"
#include "Wolf.h"

CreatureFactory::CreatureFactory(){
}

Creature * CreatureFactory::getCreature(std::string creature_type, int position_x, int position_y)
{
	switch(creature_type)
	{
		case "GRASS":
		return new Grass(position_x, position_y);
		break;
		case "DEER":
		return new Deer(position_x, position_y);
		break;
		case "WOLF":
		return new Wolf(position_x, position_y);
		break;
	}

}