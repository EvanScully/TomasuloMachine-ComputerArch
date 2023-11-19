#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Instruction.h"

#define IQ_SIZE 100
#define RF_SIZE 8

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