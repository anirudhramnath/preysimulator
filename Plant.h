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
    int getGraced(void food_level);
};

#endif //_PLANT_H