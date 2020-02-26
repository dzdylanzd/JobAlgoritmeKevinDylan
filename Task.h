/*
 * Task.h
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#ifndef TASK_H_
#define TASK_H_

enum TaskStatus
{
	TODO, INPROGRESS, DONE
};

class Task
{
public:
	Task(unsigned short taskId, unsigned short machineId, unsigned short time);
	virtual ~Task();
	unsigned short getId() const;
	unsigned short getMachineId() const;
	unsigned short getRunningTime() const;
	TaskStatus getTaskStatus() const;
	unsigned short getTaskTime() const;
	void setTaskTime(unsigned short taskTime);
	void addToRuningTime(unsigned short value);

private:
	unsigned short ID;
	unsigned short machineId;
    TaskStatus taskStatus = TODO;
	unsigned short taskTime;
	unsigned short runningTime = 0;

};

#endif /* TASK_H_ */
