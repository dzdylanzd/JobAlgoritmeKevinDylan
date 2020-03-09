/**
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
/**
 * constructor
 */
	Machine();

/**
 * destructor
 */
	virtual ~Machine();

/**
 * copy constructor. het nieuwe object wordt geinitialiseerd op basis van het meegegeven object.
 *
 * @param aMachine
 */
	Machine(const Machine &Machine);

/**
 * Getter voor de status van de machine
 * @return true = running.
 */
	bool isRunning() const;

/**
 * setter voor de machine op running/niet running te zetten.
 * @param true/false
 */
	void setRunning(bool running);

private:
/**
 * bool voor het bijhouden of de machine runt.
 */
	bool running;

};

#endif /* MACHINE_H_ */
