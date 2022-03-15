#include <iostream>
using namespace std;
#include <ostream>
#pragma once

class Task {
private:

public:
	char TaskName[32];
	int ST;
	int ET;
	Task* nextTask;

	Task();
	Task(char TaskName[32], int st, int et);
	void insert(char Taskname[32], int st, int et);
	void print();
	friend ostream& operator<<(ostream& o, const Task& task);
	friend iostream& operator >>(iostream& i,Task& task);

};
