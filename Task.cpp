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
}

Task::~Task()
{
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

unsigned short Task::getTaskTime() const
{
	return taskTime;
}

void Task::setTaskTime(unsigned short ataskTime)
{
	taskTime = ataskTime;
}

void Task::addToRuningTime(unsigned short value)
{
	runningTime += value;
}

bool Task::isInProgress() const
{
	return inProgress;
}

void Task::startTask()
{
	inProgress = true;
}
