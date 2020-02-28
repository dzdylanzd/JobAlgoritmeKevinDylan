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
		print();
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



bool JobShop::finished()
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

bool JobShop::isMachineRunning(unsigned short machineId)
{
	return machines[machineId].isRunning();
}

void JobShop::schedule()
{
	while (!finished())
	{
		for (Job &job : jobList) // deze loop is om te checken welke taken er klaar zijn
		{
			if (job.getTotalTimeLeft() != 0)
			{
				if (job.getIsStarted())
				{
					job.addToTotalTime(1);
				}
				if (job.getFirstTask().getTaskStatus()
						== TaskStatus::INPROGRESS)
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

		calculateSlackTime();

		for (Job &job : jobList) // deze loop is om de nieuwe taken te schedulen
		{
			if (job.getTotalTimeLeft() != 0)
			{
				if (job.getFirstTask().getTaskStatus() != TaskStatus::INPROGRESS
						&& !isMachineRunning(job.getFirstTask().getMachineId()))
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
	job.getFirstTask().setTaskStatus(TaskStatus::INPROGRESS);
}

void JobShop::print()
{
	std::sort(jobList.begin(), jobList.end(), [](Job &a, Job &b) -> bool
	{
		return a.getJobId() < b.getJobId();
	});
	for (Job &job : jobList)
	{
		std::cout << job.getJobId() << "  " << job.getStartTime() << "  "
				<< job.getStartTime() + job.getTotalTime() << std::endl;
	}
}

