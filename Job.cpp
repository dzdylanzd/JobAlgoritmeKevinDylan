/*
 * Job.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#include <iostream>
#include "Job.h"

Job::Job(unsigned short jobId)
: jobId(jobId)
{
	// TODO Auto-generated constructor stub
	std::cout << "job Created " << jobId << std::endl;
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

