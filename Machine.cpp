#include "Machine.h"
#include <iostream>
using namespace std;
#include "Task.h"
Machine::Machine()
{
	id = 0;
	firstTask = NULL;
	nextMachine = NULL;
	tail = NULL;
}
void Machine::setFirstTask(Task* t)
{
	firstTask = t;
}
Task* Machine::getFirstTask()
{
	return firstTask;
}
void Machine::createnewmachine()
{
	id = id;
	firstTask = NULL;
	nextMachine = NULL;
}
bool check(Machine* m, Task* t) {
	Task* p = m->getFirstTask();

	bool f = true;
	while (p != NULL) {
		if (t->ST > p->ST && t->ET > p->ET)
			f = true;
		else
			return false;

		p = p->nextTask;
	}
	return f;
}

void Machine::addTask(Task* t)
{
	if (nextMachine == NULL) {

		nextMachine = new Machine;
		nextMachine->id = 1;
		nextMachine->firstTask = new Task(t->TaskName, t->ST, t->ET);
		nextMachine->firstTask->insert(t->TaskName,t->ST,t->ET);
		nextMachine->nextMachine = NULL;
		nextMachine->firstTask->nextTask = NULL;
		tail = nextMachine;
		return;
	}
	Machine* p = nextMachine;
	while (p!=NULL)
	{
		if (check(p, t)) {
			p->firstTask->insert(t->TaskName, t->ST, t->ET);
			return;
		}
		p = p->nextMachine;
	}

	Machine* mm = new Machine;
	mm->id = 2;
	mm->firstTask = new Task;
	mm->firstTask->insert(t->TaskName, t->ST, t->ET);
	mm->firstTask = new Task(t->TaskName, t->ST, t->ET);
	
	tail->nextMachine = mm;

}


ostream& operator<<(ostream& o, const Machine& m)
{
	Machine* p = m.nextMachine;
	while (p != NULL) {
		o << "Machine # " << p->id << ": ";
		Task* h = p->firstTask;
		while (h->nextTask != NULL) {
			o << h->TaskName << "(" << h->ST << " - " << h->ET << ")-- -";
			h = h->nextTask;
		}
		p = p->nextMachine;
		o << "\n";
	}
	return o;
}
