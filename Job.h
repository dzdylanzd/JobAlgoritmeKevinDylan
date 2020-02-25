/*
 * Job.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#ifndef JOB_H_
#define JOB_H_

#include "Task.h"
#include <deque>
#include <vector>
#include <utility>
#include <iostream>

class Job
{
public:
	Job(unsigned short jobId,std::vector<unsigned short>& tasksValues);
	virtual ~Job();
	void createTasks(std::vector<unsigned short>& tasksValues);

private:
	unsigned long long jobId;
	std::deque<Task> tasks;
};

#endif /* JOB_H_ */
