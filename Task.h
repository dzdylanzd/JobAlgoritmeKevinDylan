/**
 * Task.h
 *
 *  Created on: 20 feb. 2020
 *      Author: Dylan Zweers
 */

#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
/**
 * constructor
 * @param taskId
 * @param machineId
 * @param time
 */
	Task(unsigned short taskId, unsigned short machineId, unsigned short time);
/**
 * copy constructor
 * inialiseert het object op basis van het meegegeven object
 * @param aTask
 */
	Task(const Task &aTask);

	/**
	 * destructor
	 */
	virtual ~Task();

	//getters
	/**
	 * getter voor het opvragen of de task nog bezig is.
	 * @return inProgress true if in progress
	 */
	bool isInProgress() const;

	/**
	 * getter voor het opvragen van het task id.
	 * @return ID
	 */
	unsigned short getId() const;

	/**
	 * getter voor het opvragen van het machine id.
	 * @return machineId
	 */
	unsigned short getMachineId() const;

	/**
	 * getter voor het opvragen van de runtime.
	 * @return runningTime
	 */
	unsigned short getRunningTime() const;

	/**
	 * getter voor het opvragen van de taak tijd.
	 * @return taskTime
	 */
	unsigned short getTaskTime() const;

	//settters
	/**
	 * pre taak is nog niet gestart.
	 * functie voor he starten van een taak.
	 */
	void startTask();

/**
 *
 * functie voor tijd toe tevoegen aan de variabelen runningTime
 * @param value
 */
	void addToRuningTime(unsigned short value);

private:
	unsigned short ID;
	unsigned short machineId;
	unsigned short taskTime;
	unsigned short runningTime = 0;
	/**
	 * bool voor het opslaan of een taak bezig is true = bezig.
	 */
	bool inProgress = false;

};

#endif /** TASK_H_ */
