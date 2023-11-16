#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Instruction.cpp"

class InstructionQueue {
private:

public:
	Instruction myinstr;
	int numInstr;
	void Issue();
};