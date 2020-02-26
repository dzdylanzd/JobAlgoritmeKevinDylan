/*
 * JobShop.cpp
 *
 *  Created on: 20 feb. 2020
 *      Author: dylan zweers
 */

#include "JobShop.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>
#include <iomanip>

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

JobShop::JobShop(std::string inputFile) :
		inputFile(inputFile)
{
	// TODO Auto-generated constructor stub
	if(!loadFile()){
		std::cout << "Er ging iets mis met het laden van het bestand" << std::endl;
	}

	for (const auto& [id, machine] : machines)
	{
		std::cout << id << " "<< machine.isRunning() << std::endl;
	}
}

bool JobShop::loadFile()
{
	std::vector<std::vector<unsigned short>> input;
	std::ifstream ifs(inputFile, std::ifstream::in);
	if (ifs.good())
	{
		char c;
		std::string buffer;
		std::vector<unsigned short> jobTasks;
		while (ifs.good())
		{
			c = ifs.get();
			if (c != ' ' && c != '\t' && c != '\n' && c != EOF)
			{
				if (!isdigit(c))
					return false;
				buffer += c;
			}
			else if (buffer.size() > 0)
			{
				jobTasks.insert(jobTasks.end(), std::stoi(buffer));
				buffer.clear();
			}
			if (c == '\n' || c == '\0' || ifs.eof())
			{
				input.insert(input.end(), jobTasks);
				jobTasks.clear();
			}
		}
		for (unsigned int i = 0; i < input.size(); ++i)
		{
			for (unsigned int j = 0; j < input[i].size(); ++j)
			{
				std::cout << input[i][j] << " ";
			}
			std::cout << " " << std::endl;
		}
		createMachines(input);
		createJobs(input);
		return true;
	}
	return false;
}

void JobShop::createJobs(std::vector<std::vector<unsigned short>> input)
{
	for (unsigned short i = 0; i < input[0][0]; i++)
	{
		jobList.emplace_back(i,input[i + 1]);
	}
}

void JobShop::createMachines(std::vector<std::vector<unsigned short>> input)
{
	for (unsigned short i = 0; i < input[0][1]; i++)
	{

		machines.emplace(std::make_pair(i,Machine())) ;
	}
}

