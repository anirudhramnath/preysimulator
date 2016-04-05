/**
 * Project Untitled
 */


#ifndef _CREATURE_H
#define _CREATURE_H

class Creature {
public: 
    
    /**
     * @param food_count
     */
    void grow(void food_count);
    
    void metabolize();
protected: 
    void min_food_level;
    void max_food_level;
    void current_food_level;
    void rate_of_metabolism;
    void is_alive;
};

#endif //_CREATURE_H