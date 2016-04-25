/**
 * Project Untitled
 */


#ifndef _DEER_H
#define _DEER_H

#include "Herbivore.h"
#include "SimulationController.h"


class Deer: public Herbivore {
	public:
	Deer(SimulationController *, int, int);
	virtual Creature * getInstance();
};

#endif //_DEER_H