#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define IQ_SIZE 100
#define RF_SIZE 8

#ifndef INSTRUCTIONQUEUE_H
#define INSTRUCTIONQUEUE_H

class Instruction {
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

#endif //!INSTRUCTIONQUEUE_H