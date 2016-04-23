/**
 * Project Untitled
 */


#ifndef _RABIIT_H
#define _RABIIT_H

#include "Herbivore.h"


class Rabbit: public Herbivore {
	static const int min_food_level = 50;
    static const int max_food_level = 500;
    static const int reproduction_treshold = 150;
    static const int rate_of_metabolism = 5;
public:
	Rabbit(SimulationController *, int, int);
    virtual Creature * getInstance();
};

#endif //_RABIIT_H