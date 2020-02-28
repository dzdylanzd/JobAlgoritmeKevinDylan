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
	}else{
		calculateSlackTime();
				schedule();
				print();
	}

//	for (const auto& [id, machine] : machines)
//	{
//		std::cout << id << " "<< machine.isRunning() << std::endl;
//	}
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

void JobShop::calculateSlackTime()
{
	for (Job &job : jobList)
	{
		job.calculateTimeLeft();
	}
	std::sort(jobList.begin(), jobList.end(), [](Job &a, Job &b) -> bool
	{
		return (a.getTotalTimeLeft() > b.getTotalTimeLeft())
		|| (a.getTotalTimeLeft() == b.getTotalTimeLeft() // als de totale tijd van a en b gelijk is, en niet gelijk aan 0:
			&& a.getTotalTimeLeft() != 0// kleinste job id heeft voorrang.
			&& a.getJobId() < b.getJobId());
});
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
				if (job.getFirstTask().getTaskStatus() == TaskStatus::INPROGRESS)
				{
					job.getFirstTask().addToRuningTime(1);
					if (job.getFirstTask().getRunningTime()
							== job.getFirstTask().getTaskTime())
					{
						machines[job.getFirstTask().getMachineId()].setRunning(false);
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

