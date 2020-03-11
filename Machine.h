/**
 * machine.h
 *
 *  Created on: 25 feb. 2020
 *      Author: dylan zweers & kevin selder
 */

#ifndef MACHINE_H_
#define MACHINE_H_

class Machine
{
public:
/**
 * maakt de machine aan
 * constructor
 */
	Machine();


/**
 * destructor
 */
	virtual ~Machine();

/**
 * copy constructor. het nieuwe object wordt geinitialiseerd op basis van het meegegeven object.
 * @param aMachine
 */
	Machine(const Machine &Machine);

/**
 * Getter voor de status van de machine
 * @return true als hij in gebruik is false als hij niet in gebruik is.
 */
	bool isRunning() const;

/**
 * setter voor de machine op running/niet running te zetten.
 * @param running bool
 */
	void setRunning(bool running);

private:
	bool running;

};

#endif /* MACHINE_H_ */
