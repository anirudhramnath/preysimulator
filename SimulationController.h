/**
 * Project Untitled
 */

#ifndef _SIMULATIONCONTROLLER_H
#define _SIMULATIONCONTROLLER_H

#include <vector>
#include <map>
#include "Creature.h"
#include "CreatureFactory.h"

using namespace std;

class Creature;

class SimulationController{
private:
	int grid_width;
	int grid_height;
    CreatureFactory * creature_factory;
    std::map<int, Creature *> creature_location_map;
    std::vector<Creature *> list_of_creatures;
public:
    SimulationController();
    void start();
    void stop();
    void pause();
    std::vector<Creature *> getCreatureList();
    Creature * getCreaturesIn(const type_info&, int, int );
    std::vector<Creature *>* getCreaturesAround(const type_info&, int position_x, int position_y);
    Creature * getNearestCreature(const type_info&, int position_x, int position_y);
    void changePosition(Creature * creature,int position_x,int position_y);
    void addChild(Creature * child, int position_x, int position_y);
    void removeCreature(Creature *);
    std::vector<std::pair<int, int> > * SimulationController::getPointsAround(int position_x, int position_x);
};

class NotEmpty: public std::exception{
};

#endif //_SIMULATIONCONTROLLER_H