/**
 * Project Untitled
 */


#ifndef _ANIMAL_H
#define _ANIMAL_H

#include "Creature.h"


class Animal: public Creature {
public: 
    
    void move();
    
    /**
     * @param food_level
     */
    void eat(void food_level);
    
    void age();
    
    void reproduce();
    
    void die();
protected: 
    void age;
    void reproduction_probability;
};

#endif //_ANIMAL_H