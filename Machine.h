/*
 * machine.h
 *
 *  Created on: 25 feb. 2020
 *      Author: dylan zweers
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine
{
public:
	Machine();
	virtual ~Machine();
	Machine(const Machine &Machine);
	bool isRunning() const;
	void setRunning(bool running);

private:
	bool running;

};

#endif /* MACHINE_H_ */
