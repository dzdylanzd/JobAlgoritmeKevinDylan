/**
 * JobShop.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers & kevin selder
 */

#ifndef JOBSHOP_H_
#include <iostream>
#include <vector>
#include <map>
#include "Job.h"
#include "Task.h"
#include "Machine.h"
#define JOBSHOP_H_



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
	 * sorteerd de jobs op prioritijd op basis van TimeLeft en jobID
	 * als 2 jobs de zelfde TimeLeft hebben heeft degene met het laagste job ID eerst
	 */
	void calculatePrority();

	/**
	 * checkt of alle jobs klaar zijn.
	 * @return true als alle jobs klaar zijn.
	 */
	bool JobsFinished();

	/**
	 * functie bool voor het inladen van de file
	 * @return true als file is ingeladen en heeft door kunnen lopen.
	 * false als er iets fout gegaan is.
	 */
	bool loadFile();

	/**
	 * pre file moet geladen zijn
	 * maakt de jobs op basis van de input file
	 * @param std::vector<std::vector<unsigned short>> input
	 */
	void createJobs(std::vector<std::vector<unsigned short>> &input);

	/**
	 * pre file moet geladen zijn
	 * maakt de machines op basis van de input file
	 * @param std::vector<std::vector<unsigned short>> input
	 */
	void createMachines(std::vector<std::vector<unsigned short>> &input);

	/**
	 * functie voor het uitvoeren van het minim slack algoritme.
	 */
	void schedule();

	/**
	 * pre file moet geladen zijn
	 * pre machines,jobs en task moeten aangemaakt zijn
	 * functie voor het schedulen van nog uit te voeren taken.
	 * @param job
	 */
	void scheduleTask(Job &job);

};

/**
 * output opperator
 * @param os wat er uitgeprint wordt
 * @param ajobShop jobShop waar de informatie van geprint wordt.
 * @return
 */
std::ostream& operator<<(std::ostream &os, JobShop &ajobShop);

#endif /* JOBSHOP_H_ */
