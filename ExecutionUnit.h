#pragma once

#include <iostream>
#include <fstream>
#include <string>


class ExecutionUnit {
private:

public:
	bool busy;
	bool ready;
	int startClock;
	int clockDifference;
	Station broadcast;
	Station Broadcast();
	bool isBusy();
	bool isReady(int currentClock);
	void execute(Station station, int startClock);
};