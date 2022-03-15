#include <iostream>
using namespace std;
#include <fstream>
#include "Task.h"
#include "Machine.h"
int main()
{
	char fileName[32];
	cout << "\nEnter the name of the file like <input.txt>: ";
	cin >> fileName; // Ask the user to enter the name of the input file

	fstream file(fileName, ios::in); //Open the file and read the required information, using C++ files
	if (!file) {
		cout << "\nCant open the file !!!\n";
		exit(1);
	}
	int count = 0;
	file >> count;

	Task  generalLinked;//Construct a general linked list of tasks to store the information about the different tasks(The tasks in the lists should be sorted according to their start times).
	Machine MACHINE; //Create an object of MACHINE class, mainly to store required machines

	
	for (int i = 0; i < count; i++) {
		file >> generalLinked;
		generalLinked.insert(generalLinked.TaskName, generalLinked.ST, generalLinked.ET);
	}
	generalLinked.print();
	cout << "\n";

	Task* p = generalLinked.nextTask;
	while (p!=NULL) {
		
		MACHINE.addTask(p); //Try to assign the task to one of the available machines without overlapping

		Task* del = p; //Remove the first node from the general list.
		p = p->nextTask;
		delete del;
	}
	cout << "\n";
	cout << MACHINE; //print the assigned tasks as well as the starting and ending time for each task.Using the overloading operator for MACHINE class.
	cout << "\n";
	return 0;
}
