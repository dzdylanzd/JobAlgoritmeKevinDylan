/**
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
/**
 * Constructor
 */
	Job(unsigned short jobId,std::vector<unsigned short>& tasksValues);

/**
 * Destructor
 */
	virtual ~Job();
/**
 * Rekent tijd uit wat over is ten opzichte van de langste duur
 */
	void calculateTimeLeft();

	// getters

/**
 * bool getter te kijken of de taak gestart is.
 * @return isStarted
 */
	bool getIsStarted() const;
/**
 * unsigned short getter voor het id van een job.
 * @return jobId
 */
	unsigned short getJobId() const;
/**
 * unsigned long long voor het getten van de totaletijd van een job.
 * @return totalTime
 */
	unsigned long long getTotalTime() const;
/**
 * unsigned long long voor het getten van de totale tijd die over is.
 * @return totalTimeLeft
 */
	unsigned long long getTotalTimeLeft() const;
/**
 * unsigned long long voro het getten van de start tijd.
 * @return startTime
 */
	unsigned long long getStartTime() const;
/**
 * Task& voor het getten van de first task.
 * @return tasks.front()
 */
	Task& getFirstTask();


	//setters
/**
 * voor de taak op finished te zetten.
 */
	void taskFinished();
/**
 * voor het starten van een taak.
 */
	void startJob();
/**
 * voor het zetten van de tijd
 * @param startTime
 */
	void setStartTime(unsigned long long startTime);
/**
 * Voor het toevoegen aan totalTime
 * @param totalTime
 */
	void addToTotalTime(unsigned long long amount);

private:
	unsigned short jobId;
	std::vector<Task> tasks;
	unsigned long long totalTime = 0;
	unsigned long long totalTimeLeft = 0;
	unsigned long long startTime = 0;
	bool isStarted = false;

/**
 * Voor een de tasks te creeren aan de hand van de meegegeven vector.
 * @param taskValues
 */
	void createTasks(std::vector<unsigned short>& tasksValues);
};

#endif /* JOB_H_ */
