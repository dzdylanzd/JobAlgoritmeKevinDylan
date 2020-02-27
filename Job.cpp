/*
 * Job.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#include <iostream>
#include "Job.h"

Job::Job(unsigned short jobId, std::vector<unsigned short> &tasksValues) :
		jobId(jobId)
{
	createTasks(tasksValues);
	// TODO Auto-generated constructor stub
	std::cout << "job Created " << jobId << std::endl;
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

void Job::createTasks(std::vector<unsigned short> &tasksValues)
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

unsigned long long Job::getTotalTime() const
{
	return totalTime;
}

unsigned long long Job::getTotalTimeLeft() const
{
	return totalTimeLeft;
}

unsigned long long Job::getStartTime() const
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

void Job::setStartTime(unsigned long long aStartTime)
{
	startTime = aStartTime;
}

void Job::addToTotalTime(unsigned long long amount)
{
	totalTime += amount;
}

void Job::calculateTimeLeft()
{
	totalTimeLeft = 0;
	for (Task &task : tasks)
	{
		if (task.getTaskStatus() == TaskStatus::INPROGRESS)
		{
			totalTimeLeft += (task.getTaskTime() - task.getRunningTime());
		}
		else
		{
			totalTimeLeft += task.getTaskTime();
		}
	}
}
