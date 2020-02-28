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
	if (!loadFile())
	{
		std::cout << "Er ging iets mis met het laden van het bestand"
				<< std::endl;
	}
	else
	{
		calculateSlackTime();
		schedule();

	}
}

bool JobShop::loadFile()
{
	std::vector<std::vector<unsigned short>> FileInput;
	std::ifstream inputFileData(inputFile, std::ifstream::in);
	if (inputFileData.good())
	{
		std::string characterBuffer;
		std::vector<unsigned short> jobTasksBuffer;
		while (inputFileData.good())
		{
			char character = inputFileData.get();
			if (character
					!= ' '&& character != '\t' && character != '\n' && character != EOF)
			{
				if (!isdigit(character))
				{
					return false;
				}
				else
				{
					characterBuffer += character;
				}
			}
			else if (characterBuffer.size() > 0)
			{
				jobTasksBuffer.insert(jobTasksBuffer.end(),
						std::stoi(characterBuffer));
				characterBuffer.clear();
			}
			if (character == '\n' || character == '\0' || inputFileData.eof())
			{
				FileInput.insert(FileInput.end(), jobTasksBuffer);
				jobTasksBuffer.clear();
			}
		}
		createMachines(FileInput);
		createJobs(FileInput);
		return true;
	}
	return false;
}

void JobShop::createJobs(std::vector<std::vector<unsigned short>> input)
{
	for (unsigned short i = 0; i < input[0][0]; i++)
	{
		jobList.emplace_back(i, input[i + 1]);
	}
}

void JobShop::createMachines(std::vector<std::vector<unsigned short>> input)
{
	for (unsigned short i = 0; i < input[0][1]; i++)
	{
		machines.emplace(std::make_pair(i, Machine()));
	}
}

void JobShop::calculateSlackTime()
{
	for (Job &job : jobList)
	{
		job.calculateTimeLeft();
	}

	auto calculatePriority =
			[](Job &a,
					Job &b)
					{
						return (a.getTotalTimeLeft() > b.getTotalTimeLeft())||
						(a.getTotalTimeLeft() == b.getTotalTimeLeft() && a.getTotalTimeLeft() != 0 && a.getJobId() < b.getJobId()
						);
					};

	std::sort(jobList.begin(), jobList.end(), calculatePriority);
}

bool JobShop::JobsFinished()
{
	for (Job &job : jobList)
	{
		if (job.getTotalTimeLeft() != 0)
		{
			return false;
		}
	}
	return true;
}

void JobShop::schedule()
{
	while (!JobsFinished())
	{
		for (Job &job : jobList) // check alle jobs en add time
		{
			if (job.getTotalTimeLeft() != 0)
			{
				if (job.getIsStarted())
				{
					job.addToTotalTime(1);
					if (job.getFirstTask().isInProgress())
					{
						job.getFirstTask().addToRuningTime(1);
						if (job.getFirstTask().getRunningTime()
								== job.getFirstTask().getTaskTime())
						{
							machines[job.getFirstTask().getMachineId()].setRunning(
									false);
							job.taskFinished();
						}
					}
				}

			}
		}

		calculateSlackTime();

		for (Job &job : jobList) // deze loop is om de nieuwe taken te schedulen
		{
			if (job.getTotalTimeLeft() != 0)
			{
				if (!job.getFirstTask().isInProgress()
						&& !machines[job.getFirstTask().getMachineId()].isRunning())
				{
					scheduleTask(job);
				}
			}
		}

		timer++;
	}
}

void JobShop::scheduleTask(Job &job)
{
	if (!job.getIsStarted())
	{
		job.startJob();
		job.setStartTime(timer);
	}

	machines[job.getFirstTask().getMachineId()].setRunning(true);
	job.getFirstTask().startTask();
}

std::string JobShop::getoutput()
{
	std::stringstream output;
	std::sort(jobList.begin(), jobList.end(), [](Job &a, Job &b){return a.getJobId() < b.getJobId();});
	for (Job &job : jobList)
	{
		output << job.getJobId() << "  " << job.getStartTime() << "  "
				<< job.getStartTime() + job.getTotalTime() << "\n";
	}

	return output.str();
}



std::ostream& operator <<(std::ostream &os,  JobShop &ajobShop)
{
     os << ajobShop.getoutput();
	return os;
}
