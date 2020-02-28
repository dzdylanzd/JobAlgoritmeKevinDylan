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
	unsigned short getId() const;
	unsigned short getMachineId() const;
	unsigned short getRunningTime() const;
	unsigned short getTaskTime() const;
	void setTaskTime(unsigned short taskTime);
	void addToRuningTime(unsigned short value);
	bool isInProgress() const;
	void startTask();

private:
	unsigned short ID;
	unsigned short machineId;
	unsigned short taskTime;
	unsigned short runningTime = 0;
	bool inProgress = false;

};

#endif /* TASK_H_ */
