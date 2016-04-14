/**
 * Project Untitled
 */


#include "Grass.h"

/**
 * Grass implementation
 */
Grass::Grass(int position_x, int position_y):Plant(position_x, position_y)
{
}

Creature * Grass::getInstance(){
	return (Creature *)Grass(environment, 0, 0);
}