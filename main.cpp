/*
 * main.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: Dylan Zweers, Kevin Selderij
 */

#include <iostream>
#include "JobShop.h"

std::string getFileName()
{
	std::string file;
	std::cout << "typ hier de file naam : ";
	std::cin >> file;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return file;
}

int main(int argc, char **argv)
{
	while (true) //loop
	{
		JobShop jobshop(getFileName());
		std::cout << jobshop << std::endl;
	}
}
