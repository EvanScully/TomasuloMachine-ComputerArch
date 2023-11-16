#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define IQ_SIZE 100
#define RF_SIZE 8

class ReservationStation {
private:

public:
	void Dispatch();
};

class ExecutionUnit {
private:

public:
	void Broadcast();
};

class RegisterAllocationTable {
private:

public:
	int callVal();
};

class Instruction {
private:

public:
	int operation;		// operation
	int Rs;				// location of Rs
	int Rt;				// location of Rt
	int Rd;				// location of Rd

	Instruction();
	Instruction(int oper, int regs, int regt, int regd);
	void printInstr();
};

class InstructionQueue {
private:
	Instruction myqueue[IQ_SIZE];
	int front, rear;
public:
	InstructionQueue();
	bool isFull();
	bool isEmpty();
	void enQueue(Instruction value);
	Instruction Issue();
	void displayQueue();

};
class RegisterFile {
private:
	int rFile[RF_SIZE];
public:
	int index;
	int value;
	RegisterFile();
	void setVal(int location, int val);
	int getVal(int location);
	int getLastIndex();
	int getLastVal();
	void clearRF();
	void printRF();
};

int toInt(std::string str);