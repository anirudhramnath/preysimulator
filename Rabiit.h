/**
 * Project Untitled
 */


#ifndef _RABIIT_H
#define _RABIIT_H

#include "Herbivore.h"


class Rabbit: public Herbivore {
public:
	Rabbit(SimulationController *, int, int);
    virtual Creature * getInstance();
};

#endif //_RABIIT_H