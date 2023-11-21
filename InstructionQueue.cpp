

#include <iostream>

#include "InstructionQueue.h"

using namespace std;

//Instruction Queue Class Functions:
//---------------------------------------------------------------//
InstructionQueue::InstructionQueue() {
	front = -1;
	rear = -1;
}
bool InstructionQueue::isFull() {
	if (front == 0 && rear == IQ_SIZE - 1) {
		return true;
	}
	return false;
}
bool InstructionQueue::isEmpty() {
	if (front == -1) return true;
	else return false;
}
void InstructionQueue::enQueue(Instruction value) {
	if (isFull()) {
		cout << endl << "Queue is full!!";
	}
	else {
		if (front == -1) front = 0;
		rear++;
		myqueue[rear] = value;

	}
}
Instruction InstructionQueue::Issue() {
	Instruction value = Instruction();
	if (isEmpty()) {
		cout << "Queue is empty, You get a NOP!!" << endl; return(value);
	}
	else {
		value = myqueue[front]; if (front >= rear) {      //only one element in queue
			front = -1;
			rear = -1;
		}
		else {
			front++;
		}

		return(value);
	}
}
void InstructionQueue::displayQueue()
{
	int i;
	if (isEmpty()) {
		cout << endl << "Instrcution Queue is Empty!!" << endl;
	}
	else {
		cout << "Instructions:\n";
		for (i = front; i <= rear; i++)
			myqueue[i].printInstr();
	}
}
//---------------------------------------------------------------//

// Intruction Class Functions :
//----------------------------------------------------------------//
Instruction::Instruction(int oper, int regs, int regt, int regd) {
	operation = oper;
	Rs = regs;
	Rt = regt;
	Rd = regd;
}
Instruction::Instruction() {	//Essentially a NOP
	operation = 5;
	Rs = RF_SIZE;
	Rt = RF_SIZE;
	Rd = RF_SIZE;
}
void Instruction::printInstr() {
	if (operation == 5) {
		cout << "NOP";
		return;
	}
	else {
		cout << "r" << Rd << " = r" << Rs;
		switch (operation) {
		case 0:
			cout << " + r" << Rt << endl;
			break;
		case 1:
			cout << " - r" << Rt << endl;
			break;
		case 2:
			cout << " * r" << Rt << endl;
			break;
		case 3:
			cout << " / r" << Rt << endl;
			break;
		default:
			break;
		}
	}
}
//---------------------------------------------------------------//
