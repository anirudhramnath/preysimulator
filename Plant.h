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
    Plant(SimulationController * , int, int, int);
    int getGraced(int food_level);
    int getConsumed(int);
    virtual void routine();
    virtual Creature * getInstance()=0;
};

#endif //_PLANT_H