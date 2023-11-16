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