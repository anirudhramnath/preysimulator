/**
 * Project Untitled
 */


#ifndef _RABIIT_H
#define _RABIIT_H

#include "Herbivore.h"


class Rabbit: public Herbivore {
	static{
		min_food_level = 50;
		max_food_level = 500;
		reproduction_treshold = 150;
		rate_of_metabolism = 5;
	}
	Rabbit(SimulationController *, int, int);
};

#endif //_RABIIT_H