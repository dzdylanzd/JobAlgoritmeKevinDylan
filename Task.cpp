/*
 * Task.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#include "Task.h"
#include <iostream>

Task::Task(unsigned short taskId, unsigned short machineId, unsigned short time) :
		ID(taskId), machineId(machineId), taskTime(time)
{
	// TODO Auto-generated constructor stub
	std::cout << "task Created id: "  << ID << " machine id: "<< machineId<< " time: " << time<< " " << std::endl;
}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

