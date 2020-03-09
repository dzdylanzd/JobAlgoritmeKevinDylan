/*
 * main.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: Dylan Zweers, Kevin Selder
 */

#include <iostream>
#include <regex>
#include "JobShop.h"
#include <fstream>

void dump_regex_matches(const std::cmatch &match)
{
	std::cout << "Matches:\n";

	for (std::size_t i = 0; i < match.size(); ++i)
	{
		std::cout << i << ": " << match.str(i) << '\n';
	}
}

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
