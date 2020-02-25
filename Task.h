/*
 * Task.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
	Task(unsigned short taskId, unsigned short machineId, unsigned short time);
	virtual ~Task();

private:
	unsigned short ID;
	unsigned short machineId;
	unsigned short taskTime;
};

#endif /* TASK_H_ */
