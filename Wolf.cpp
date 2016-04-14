/**
 * Project Untitled
 */


#include "Wolf.h"

/**
 * Wolf implementation
 */
Creature * Wolf::getInstance(){
	return (Creature *)Wolf(environment, 0, 0);
}