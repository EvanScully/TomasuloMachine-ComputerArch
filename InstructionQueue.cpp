#include "TomasuloMachine.h"
#include "InstructionQueue.h"

#define IQ_SIZE 100
#define RF_SIZE 8

using namespace std;

//Intruction Class Functions:
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