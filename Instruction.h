#pragma once

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
