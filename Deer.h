/**
 * Project Untitled
 */


#ifndef _DEER_H
#define _DEER_H

#include "Herbivore.h"


class Deer: public Herbivore {
	public:
	Deer(SimulationController *, int, int);
};

#endif //_DEER_H