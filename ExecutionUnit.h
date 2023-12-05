#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Station;

class ExecutionUnit {
private:

public:
	ExecutionUnit();
	bool busy;
	bool ready;
	int startClock;
	int clockDifference;
	Station broadcast;
	Station Broadcast();
	bool isBusy();
	bool isReady(int currentClock);
	void execute(Station broadcast, int startClock);
};