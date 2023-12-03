#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define RF_SIZE 8

#ifndef RESERVATIONALLOCATIONTABLE_H
#define RESERVATIONALLOCATIONTABLE_H
class RegisterAllocationTable {
private:
	int RAT[RF_SIZE];
public:
	RegisterAllocationTable();
	int index;
	int value;
	void setLoc(int location, int val);
	int callLoc(int location);
	void printRAT();
};

#endif // !RESERVATIONALLOCATIONTABLE_H