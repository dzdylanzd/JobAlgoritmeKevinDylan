/**
 * JobShop.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cctype>
#include "Job.h"
#include "Task.h"
#include "Machine.h"

class JobShop
{
public:
	/**
	 * constructor
	 * @param inputFile std::string de file die geimporteerd wordt
	 */
	JobShop(std::string inputFile);

	/**
	 * copy constructor
	 * inialiseert het object op basis van het meegegeven object
	 * @param JobShop
	 */
	JobShop(const JobShop &aJobShop) = delete;

	/**
	 * Destructor
	 */
	virtual ~JobShop();

	/**
	 * haalt de output op van het minimum slack algoritme
	 * @return output.str()
	 */
	std::string getoutput();

private:

	std::vector<Job> jobList;
	unsigned long long timer = 0;
	std::string inputFile;
	std::map<unsigned short, Machine> machines;

	/**
	 * methode voor het berekenen van de slacktime.
	 */
	void calculatePrority();

	/**
	 * bool voor het aangeven of de jobs klaar zijn.
	 * @return true if done.
	 */
	bool JobsFinished();

	/**
	 * functie bool voor het inladen van de file
	 * @return true als file is ingeladen en heeft door kunnen lopen.
	 */
	bool loadFile();

	/**
	 * functie voor het creëren van de jobs.
	 * @param std::vector<std::vector<unsigned short>> input
	 */

	void createJobs(std::vector<std::vector<unsigned short>> &input);
	/**
	 * functie voor het creëren van de machines.
	 * @param std::vector<std::vector<unsigned short>> input
	 */
	void createMachines(std::vector<std::vector<unsigned short>> &input);

	/**
	 * functie voor het uitvoeren van het algoritme.
	 */
	void schedule();

	/**
	 * functie voor het schedulen van nog uit te voeren taken.
	 * @param job
	 */
	void scheduleTask(Job &job);

};

std::ostream& operator<<(std::ostream &os, JobShop &ajobShop);

#endif /* JOBSHOP_H_ */
