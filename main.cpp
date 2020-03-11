/*
 * main.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: Dylan Zweers, Kevin Selder
 */

#include <iostream>
#include "JobShop.h"




int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "error" << std::endl;
		return false;
	}

	std::string input(argv[1]);
	JobShop jobshop(input);
	std::cout << jobshop << std::endl;








}
