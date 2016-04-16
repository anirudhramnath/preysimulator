
#ifndef _CreatureFactory_H
#define _CreatureFactory_H
#include "Creature.h"
#include "SimulationController.h"
#include <string>

class Creature;
class SimulationController;

class CreatureFactory
{
public:
	CreatureFactory();
	Creature* getCreature(SimulationController * environment, std::string creature_type, int position_x, int position_y);
};
#endif 