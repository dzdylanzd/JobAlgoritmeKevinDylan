/*
 * Job.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#ifndef JOB_H_
#define JOB_H_

class Job
{
public:
	Job(unsigned short jobId);
	virtual ~Job();

private:
	unsigned long long jobId;
};

#endif /* JOB_H_ */
