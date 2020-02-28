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
	std::string getoutput();

private:
	std::vector<Job> jobList;
	unsigned long long timer = 0;
	std::string inputFile;
	std::map<unsigned short, Machine> machines;


	void calculateSlackTime();
	bool JobsFinished();
	bool loadFile();
	void createJobs(std::vector<std::vector<unsigned short>> input);
	void createMachines(std::vector<std::vector<unsigned short>> input);
	void schedule();
	void scheduleTask(Job &job);


};

std::ostream& operator<<(std::ostream &os,  JobShop &ajobShop);



#endif /* JOBSHOP_H_ */
