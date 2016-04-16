/**
 * Project Untitled
 */


#ifndef _WOLF_H
#define _WOLF_H

#include "Carnivore.h"


class Wolf: public Carnivore {
	public:
		Wolf(SimulationController *, int, int);
		Creature * getInstance();

};

#endif //_WOLF_H