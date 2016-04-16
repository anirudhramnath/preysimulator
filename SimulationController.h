/**
 * Project Untitled
 */

#ifndef _SIMULATIONCONTROLLER_H
#define _SIMULATIONCONTROLLER_H

#include <vector>
#include <map>
#include "Creature.h"
#include "CreatureFactory.h"

class Creature;

class SimulationController{
private:
	int grid_width;
	int grid_height;
    CreatureFactory creature_factory;
    std::map<int, Creature *> creature_location_map;
    std::vector<Creature *> list_of_creatures;
public:
    SimulationController();
    void start();
    void stop();
    void pause();
    std::vector<Creature *> getCreatureList();
    Creature * getCreaturesIn(std::string, int, int );
    std::vector<Creature *>* getCreaturesAround(std::string, int position_x, int position_y);
    Creature * getNearestCreature(std::string, int position_x, int position_y);
    void changePosition(Creature * creature,int position_x,int position_y);
    void addChild(Creature * child, int position_x, int position_y);
};

class NotEmpty: public std::exception{
};

#endif //_SIMULATIONCONTROLLER_H