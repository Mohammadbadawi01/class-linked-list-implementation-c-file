#include <iostream>
using namespace std;
#include "Task.h"
Task::Task()
{
	strcpy(TaskName, " ");
	ST = ET = 0;
	nextTask = NULL;
}

Task::Task(char TaskName[32], int st, int et)
{
	strcpy(this->TaskName, TaskName);
	this ->ST = st;
	this->ET = et;
	this->nextTask = NULL;
}

void Task::insert(char Taskname[32], int st, int et)
{
	Task* n = new Task(Taskname, st, et);


	if (nextTask == NULL) {
		nextTask = n;
		n->nextTask = NULL;
		return;
	}
	if (n->ST < nextTask->ST) {
		n->nextTask = nextTask;
		nextTask = n;
		return;
	}
	Task* p = nextTask;
	Task* pre = nextTask;
	while (p != NULL) {
		if (p->ST > n->ST) {
			pre->nextTask = n;
			n->nextTask = p;
			return;
		}
		pre = p;
		p = p->nextTask;
	}
	pre->nextTask = n;
	n->nextTask = NULL;
	
}

void Task::print()
{
	Task* p = nextTask;
	cout << "\n";
	while (p != NULL) {
		cout << *p<<"\n";
		p = p->nextTask;
	}
}

ostream& operator<<(ostream& o, const Task& task)
{
	o << task.TaskName <<" " << task.ST <<" " << task.ET;
	return o;
}

iostream& operator>>(iostream& i, Task& task)
{
	i >> task.TaskName >> task.ST >> task.ET;
	return i;
}
