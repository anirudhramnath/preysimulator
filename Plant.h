/**
 * Project Untitled
 */


#ifndef _PLANT_H
#define _PLANT_H

#include "Creature.h"


class Plant: public Creature {
public: 
    
    /**
     * @param food_level
     */
    Plant(SimulationController * , int, int);
    int getGraced(int food_level);
    int getConsumed(int);
};

#endif //_PLANT_H