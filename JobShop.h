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
	virtual ~JobShop();
	JobShop(std::string inputFile);



	/**
	 * Deze functie zorgt ervoor dat het invoer bestand goed ingelezen wordt. Daarnaast worden eventuele fouten in het bestand in deze functie afgevangen
	 */
	bool loadFile();

	/**
	 * Deze functie maakt de jobs aan, en daarbij de bijbehorende taken die in het invoer bestand staan.
	 */
	void createJobs(std::vector<std::vector<unsigned short>> input);

	/**
		 * Deze functie maakt de machines aan op basis van het aantal machines dat in de configuratie is meegegeven
		 */
	void createMachines(std::vector<std::vector<unsigned short>> input);

private:
	std::vector<Job> jobList;
	unsigned long long timer = 0;
	std::string inputFile;
	std::map<unsigned short, Machine> machines;
};

#endif /* JOBSHOP_H_ */
