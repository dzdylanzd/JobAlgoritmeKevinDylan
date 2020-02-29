/*
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
/*
 * Constructor
 */
	JobShop(std::string inputFile);
/*
 * Destructor
 */
	virtual ~JobShop();
/*
 * functie voor het getten van een string output.
 * @return output.str()
 */
	std::string getoutput();

private:
/*
 * Vector waar de jobs zich in bevinden.
 */
	std::vector<Job> jobList;

/*
 * unsigned long long voor het bijhouden van de tijd.
 */
	unsigned long long timer = 0;

/*
 * De string die voor komt uit het invoeren van de tekst file.
 */
	std::string inputFile;
/*
 * De map voor de machines.
 */
	std::map<unsigned short, Machine> machines;

/*
 * methode voor het berekenen van de slacktime.
 */
	void calculateSlackTime();

/*
 * bool voor het aangeven of de jobs klaar zijn.
 * @return true if done.
 */
	bool JobsFinished();

/*
 * functie bool voor het inladen van de file
 * @return true als file is ingeladen en heeft door kunnen lopen.
 */
	bool loadFile();

/*
 * functie voor het creëren van de jobs.
 * @param std::vector<std::vector<unsigned short>> input
 */

	void createJobs(std::vector<std::vector<unsigned short>> input);
/*
 * functie voor het creëren van de machines.
 * @param std::vector<std::vector<unsigned short>> input
 */
	void createMachines(std::vector<std::vector<unsigned short>> input);

/*
 * functie voor het uitvoeren van het algoritme.
 */
	void schedule();

/*
 * functie voor het schedulen van nog uit te voeren taken.
 * @param job
 */
	void scheduleTask(Job &job);


};

std::ostream& operator<<(std::ostream &os,  JobShop &ajobShop);



#endif /* JOBSHOP_H_ */
