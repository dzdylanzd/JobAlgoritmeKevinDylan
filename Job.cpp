/*
 * Job.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#include <iostream>
#include "Job.h"

Job::Job(unsigned short jobId,std::vector<unsigned short>& tasksValues)
: jobId(jobId)
{
	createTasks(tasksValues);
	// TODO Auto-generated constructor stub
	std::cout << "job Created " << jobId << std::endl;
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

void Job::createTasks(std::vector<unsigned short>& tasksValues)
{
	unsigned short taskId = 0;
	for(std::vector<unsigned short>::iterator i = tasksValues.begin(); i != tasksValues.end(); ++i)
	{
		unsigned short machineId = *i;
		unsigned short time = *(++i);
		tasks.emplace_back(taskId, machineId, time);
		taskId++;
	}
}

