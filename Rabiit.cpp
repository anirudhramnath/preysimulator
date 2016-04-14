/**
 * Project Untitled
 */


#include "Rabiit.h"

/**
 * Rabiit implementation
 */

Creature * Rabiit::getInstance(){
	return (Creature *)Rabiit(environment, 0, 0);
}