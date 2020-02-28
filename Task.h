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

	//getters
	bool isInProgress() const;
	unsigned short getId() const;
	unsigned short getMachineId() const;
	unsigned short getRunningTime() const;
	unsigned short getTaskTime() const;

	//settters
	void startTask();
	void addToRuningTime(unsigned short value);

private:
	unsigned short ID;
	unsigned short machineId;
	unsigned short taskTime;
	unsigned short runningTime = 0;
	bool inProgress = false;

};

#endif /* TASK_H_ */
