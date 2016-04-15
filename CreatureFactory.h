
#ifndef _CreatureFactory_H
#define _CreatureFactory_H
#include "Creature.h"
#include <string>

class CreatureFactory
{
public:
	CreatureFactory();
	Creature* getCreature(std::string creature_type, int position_x, int position_y);
};
#endif 