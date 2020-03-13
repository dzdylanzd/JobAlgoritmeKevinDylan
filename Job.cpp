/*
 * Job.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers & kevin selder
 */

#include <iostream>
#include "Job.h"

Job::Job(unsigned short jobId,const std::vector<unsigned short> &tasksValues) :
		jobId(jobId)
{
	createTasks(tasksValues);
}

Job::~Job()
{
}

Job::Job(const Job &aJob)
:jobId(aJob.jobId),tasks(aJob.tasks),totalTime(aJob.totalTime),totalTimeLeft(aJob.totalTimeLeft),startTime(aJob.startTime),isStarted(aJob.isStarted)
{

}

void Job::createTasks(const std::vector<unsigned short> &tasksValues)
{
	unsigned short taskId = 0;
	for (unsigned int i = 0; i < tasksValues.size(); ++i)
	{
		unsigned short machineId = tasksValues[i];
		unsigned short time = tasksValues[++i];
		tasks.emplace_back(taskId, machineId, time);
		taskId++;
	}
}

bool Job::getIsStarted() const
{
	return isStarted;
}

unsigned short Job::getJobId() const
{
	return jobId;
}

unsigned long Job::getTotalTime() const
{
	return totalTime;
}

unsigned long Job::getTotalTimeLeft() const
{
	return totalTimeLeft;
}

unsigned long Job::getStartTime() const
{
	return startTime;
}

void Job::taskFinished()
{
	if (tasks.size() > 0)
	{
		tasks.erase(tasks.begin());
	}
}

Task& Job::getFirstTask()
{
	return tasks.front();
}

void Job::startJob()
{
	isStarted = true;
}

void Job::setStartTime(unsigned long aStartTime)
{
	startTime = aStartTime;
}

void Job::addToTotalTime(unsigned long amount)
{
	totalTime += amount;
}


void Job::calculateTimeLeft()
{
	totalTimeLeft = 0;
	for (Task &task : tasks)
	{
		if (task.isInProgress())
		{
			totalTimeLeft += task.getTaskTime() - task.getRunningTime();
		}
		else
		{
			totalTimeLeft += task.getTaskTime();
		}
	}
}
