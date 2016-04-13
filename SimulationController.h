/**
 * Project Untitled
 */
#include <vector>
#include <map>

#include "CreatureFactory.h"

#ifndef _SIMULATIONCONTROLLER_H
#define _SIMULATIONCONTROLLER_H

class SimulationController {
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
};

#endif //_SIMULATIONCONTROLLER_H