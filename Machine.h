#include <iostream>
using namespace std;
#include "Task.h"
#pragma once


class Machine {
private:
	Task* firstTask; //private
public:

	int id;
	Machine* nextMachine;
	Machine* tail;
	void addTask(Task* t);
	Machine();
	void setFirstTask(Task *t);
	Task* getFirstTask();
	void createnewmachine();
	friend ostream& operator<<(ostream& o, const Machine& m);

};


















//friend ostream& operator<<(ostream& o, const Machine& task);
