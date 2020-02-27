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
	void calculateTimeLeft();

	 // getters

	bool getIsStarted() const;
	unsigned short getJobId() const;
	unsigned long long getTotalTime() const;
	unsigned long long getTotalTimeLeft() const;
	unsigned long long getStartTime() const;
	Task& getFirstTask();


	//setters
	void taskFinished();
	void startJob();
	void setStartTime(unsigned long long startTime);
	void addToTotalTime(unsigned long long amount);

private:
	unsigned short jobId;
	std::vector<Task> tasks;
	unsigned long long totalTime = 0;
	unsigned long long totalTimeLeft = 0;
	unsigned long long startTime = 0;
	bool isStarted = false;
};

#endif /* JOB_H_ */
