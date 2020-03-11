/**
 * Job.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers & kevin selder
 */

#ifndef JOB_H_
#include "Task.h"
#include <vector>
#include <iostream>
#define JOB_H_



class Job
{
public:

	/**
	 * constructor
	 * @param jobId op basis van input file
	 * @param tasksValues  op basis van input file
	 */
	Job(unsigned short jobId, std::vector<unsigned short> &tasksValues);

	Job(const Job &aJob);

	/**
	 * Destructor
	 */
	virtual ~Job();

	/**
	 * Rekent tijd uit wat over is ten opzichte van alle task die running zijn of nog niet begonnnen zijn
	 */
	void calculateTimeLeft();

////////////////////////getters///////////////////////////////////////////////

	/**
	 * bool getter isStarted
	 * @return isStarted true if started false if not started
	 */
	bool getIsStarted() const;

	/**
	 * unsigned short getter voor het id van een job.
	 * @return jobId
	 */
	unsigned short getJobId() const;

	/**
	 * unsigned long voor het getten van de totaletijd van de job.
	 * @return totalTime
	 */
	unsigned long getTotalTime() const;

	/**
	 * unsigned long voor het getten van de totale tijd die over is van de job.
	 * @return totalTimeLeft
	 */
	unsigned long getTotalTimeLeft() const;

	/**
	 * unsigned long voor het getten van de start tijd van de job.
	 * @return startTime
	 */
	unsigned long getStartTime() const;

	/**
	 * Task& voor het getten van de first task.
	 * @return tasks.front()
	 */
	Task& getFirstTask();

	//////////////////////////////setters////////////////////////////////////
	/**
	 * Pre job moet klaar zijn
	 * haalt de job die klaar is uit de tasks lijst
	 */
	void taskFinished();

	/**
	 * Pre de job moet niet al gestart zijn
	 * zet isStarted op true
	 */
	void startJob();

	/**
	 * set de startTime van de job
	 * @param startTime unsigned long
	 */
	void setStartTime(unsigned long startTime);

	/**
	 * Voegt de meegegeven waarde toe aan de totale tijd
	 * @param amount unsigned long
	 */
	void addToTotalTime(unsigned long amount);

private:
	unsigned short jobId;
	std::vector<Task> tasks;
	unsigned long totalTime = 0;
	unsigned long totalTimeLeft = 0;
	unsigned long startTime = 0;
	bool isStarted = false;

	/**
	 * Maakt alle task op basis van de input file.
	 * @param taskValues
	 */
	void createTasks(std::vector<unsigned short> &tasksValues);
};

#endif /* JOB_H_ */
