/*
 * machine.cpp
 *
 *  Created on: 25 feb. 2020
 *      Author: dylan zweers
 */

#include "Machine.h"

Machine::Machine():
running(false)
{
	// TODO Auto-generated constructor stub

}

Machine::~Machine()
{
	// TODO Auto-generated destructor stub
}

Machine::Machine(const Machine &aMachine):
running(aMachine.isRunning())
{

}

bool Machine::isRunning() const
{
	return running;
}

void Machine::setRunning(bool running)
{
	this->running = running;
}
