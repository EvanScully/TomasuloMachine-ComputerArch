#pragma once

#include <iostream>
#include <fstream>
#include <string>


class Instruction {
private:

public:
	int operation;		// operation
	int Rs;				// location of Rs
	int Rt;				// location of Rt
	int Rd;				// location of Rd

	Instruction(int oper, int regs, int regt, int regd);
};

class Register {
private:

public:
	int Loc;			// RF Location
	int val;			// Value of Location

};

class InstructionQueue {
private:

public:
	Instruction myinstr;
	int numInstr;
	void Issue();
};

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

class RegisterFile {
private:

public:

};

class RegisterAllocationTable {
private:

public:
	int callVal();
};

int toInt(std::string str);