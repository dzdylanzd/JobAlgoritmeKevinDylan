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

Task::Task(const Task &aTask)
:ID(aTask.ID), machineId(aTask.machineId), taskTime(aTask.taskTime),runningTime(aTask.runningTime),inProgress(aTask.inProgress)
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


