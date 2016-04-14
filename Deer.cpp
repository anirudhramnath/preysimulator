/**
 * Project Untitled
 */


#include "Deer.h"

/**
 * Deer implementation
 */
Deer::Deer(position_x, position_y):Herbivore(position_x, position_y){

}

Creature * Deer::getInstance(){
	return (Creature *)Deer(environment, 0, 0);
}