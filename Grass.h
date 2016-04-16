/**
 * Project Untitled
 */


#ifndef _GRASS_H
#define _GRASS_H

#include "Plant.h"


class Grass: public Plant {
public:
	Grass(SimulationController *, int, int);
    virtual Creature * getInstance();
};

#endif //_GRASS_H