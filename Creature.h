/**
 * Project Untitled
 */


#ifndef _CREATURE_H
#define _CREATURE_H

class Creature {

protected: 
    static const int min_food_level;
    static const int max_food_level;
    static const int rate_of_metabolism;
    int current_food_level;
    int position_x;
    int position_y;
    Environment * environment;

public: 
    
    /**
     * @param food_count
     */
    Creature();
    void Creature::addFoodLevel(int food_points);
    void metabolize();
    void routine();

};

#endif //_CREATURE_H