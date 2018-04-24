/*================================================================
name: edward koroteev
date: 5/6/2015
purpose: Processes are added to the queue with a priority level. 
The operating system removes the highest priority process from the 
queue and executes it for a short amount of time 
==================================================================*/
#include<iostream>
#include<queue>
#include<fstream>

using namespace std;

//struct
struct task
{
	int processID;
	int priority;
	int totalRunTime;
	int remainingRunTime;
	int currentPriority;
};

//function prototypes
void readInputFile(queue<task>myArray[]);
void executeQueueJobs(queue<task> array[], int priority, int& currentSimulationTime);
void printCompletedTask(task theTask, int proccessTime);

//gobal variables
const int TIME_SLICE = 50;

void main()
{
	task workingTask;
	queue<task>priorityQueues[5];
	int simulationTime=0;

	readInputFile(priorityQueues);

	for(int i =0; i < 5; i++)
	{
		executeQueueJobs(priorityQueues, i, simulationTime);
	}
	cin.get();
	cin.ignore();
}


/*==================================
Function name: readInputFile
parameters: queue<task>myArray[]
return: void
purpose: reads text from the text
file
===================================*/
void readInputFile(queue<task>myArray[])
{
	ifstream file;
	task myTask;
	int counter = 0;

	file.open("loading.txt");

	if(file.is_open())
	{
		while(!file.eof())
		{
			file >> myTask.priority;
			file >> myTask.totalRunTime;
			myTask.processID = counter;
			myTask.currentPriority = myTask.priority;
			myTask.remainingRunTime = myTask.totalRunTime;
			myArray[myTask.priority].push(myTask);
			counter++;
		}
	}
	file.close();
}


/*=========================================================================
Function name: executeQueueJobs
parameters: queue<task>myArray[], int priority, int& currentSimulationTime
return: void
purpose: determines the priority of a run time of a process and executes it
and calls the print function
==========================================================================*/
void executeQueueJobs(queue<task> myArray[], int priority, int& currentSimulationTime)
{
	task myTask;

	if(!myArray[priority].empty())
	myTask = myArray[priority].front();


	while(!myArray[priority].empty())
	{
		if(myTask.remainingRunTime <= TIME_SLICE)
		{
			myArray[priority].pop();
			currentSimulationTime += TIME_SLICE;
			myTask.remainingRunTime = 0;
			printCompletedTask(myTask,currentSimulationTime);
		}
		else if(myTask.remainingRunTime > TIME_SLICE)
		{
			if(priority < 4)
			{
				currentSimulationTime+= TIME_SLICE;
				myTask.remainingRunTime-= TIME_SLICE;
				myTask.currentPriority+=1;
				myArray[priority].pop();
				myArray[priority+1].push(myTask);
			}

			if(priority==4)
			{
				currentSimulationTime+=TIME_SLICE;
				myArray[priority].pop();
				myTask.remainingRunTime-=TIME_SLICE;
				myArray[priority].push(myTask);
			}
		}
	}
}


/*========================================
Function name: printCompletedTask
parameters: task theTask, int processTime
return: void
purpose: Prints all the members of the 
struct
==========================================*/
void printCompletedTask(task theTask, int proccessTime)
{
	cout << "=====================================" << endl;
	cout << "ProcessID: " << theTask.processID << endl;
	cout << "Priority: " << theTask.priority << endl;
	cout << "TotalRunTime: " << theTask.totalRunTime << endl;
	cout << "RemainingRunTime: " << theTask.remainingRunTime << endl;
	cout << "CurrentPriority: " << theTask.currentPriority << endl;
	cout << "Time At Completion: " << proccessTime << endl;
	cout << "=====================================" << endl;
}