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

unsigned short Task::getId() const
{
	return ID;
}

unsigned short Task::getMachineId() const
{
	return machineId;
}

unsigned short Task::getRunningTime() const
{
	return runningTime;
}

TaskStatus Task::getTaskStatus() const
{
	return taskStatus;
}

unsigned short Task::getTaskTime() const
{
	return taskTime;
}

void Task::setTaskTime(unsigned short taskTime)
{
	this->taskTime = taskTime;
}

void Task::addToRuningTime(unsigned short value)
{
	runningTime += value;
}

void Task::setTaskStatus(TaskStatus taskStatus)
{
	this->taskStatus = taskStatus;
}
