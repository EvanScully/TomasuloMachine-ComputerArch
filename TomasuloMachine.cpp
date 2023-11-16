
#include "TomasuloMachine.h"

#include "InstructionQueue.h"
#include "Instruction.h"
#include "RegisterFile.h"
#include "ExecutionUnit.h"
#include "RegisterAllocationTable.h"
#include "ReservationStation.h"

#define IQ_SIZE 100
#define RF_SIZE 8

using namespace std;

// Main Function:
//---------------------------------------------------------------//
int main()
{
	// Read Instruction File

	/*	ASCII		Val
		48			0
		49			1
		50			2
		51			3
		52			4
		53			5
		54			6
		55			7
		56			8
		57			9
	*/
	int numInstr = 0;
	int numClockCycles = 0;
	int posInstr = 0;
	int queuePos = 0;
	int instr[4] = { 0, 0, 0, 0 };
	InstructionQueue iQueue = InstructionQueue();
	RegisterFile regFile = RegisterFile();
	//iQueue.Issue();

	std::ifstream myfile("Instructions.txt");
	if (myfile.is_open()) {
		char mychar;
		int line = 1;
		int temp = 0;
		bool mystrEOL = 0;
		string mystr = "";
		while (myfile) {
			mystrEOL = 0;
			mychar = myfile.get();
			
			if (mychar == '\n' || mychar == ' ') {
				
				int val = toInt(mystr);
				if (line == 1) {
					numInstr = val;
					//cout << " Line " << line << " :";
				}
				if (line == 2) {
					numClockCycles = val;
				}
				if ((line > 2) && (line <= (2 + numInstr))) {
					instr[posInstr] = val;
					if (posInstr == 3) {
						Instruction temp(instr[0], instr[1], instr[2], instr[3]);
						iQueue.enQueue(temp);
						//cout << " Instruction: " << temp.operation << temp.Rs << temp.Rt << temp.Rd;
						
					}
					posInstr = (posInstr + 1) % 4;
				}
				if ((line > (2 + numInstr))) {
					int loc = line - (3 + numInstr);
					regFile.setVal(loc, val);
				}

				mystrEOL = 1;
				mystr = "";
			}
			if (mychar == '\n') {

				line++;
				//cout << "\n Line " << line << " :";
				
			}
				
			if (!mystrEOL) {
				mystr += mychar;
			}
			
			//cout << mychar << "";
		}
	}
	iQueue.displayQueue();
	regFile.printRF();
	return 0;

}

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


//Register File Class Functions:
//---------------------------------------------------------------//
RegisterFile::RegisterFile() {
	int i = 0;
	for (i = 0; i < RF_SIZE; i++) {
		rFile[i] = 0;
	}
	index = i;
	value = rFile[i];
}
void RegisterFile::setVal(int location, int val) {
	if (location < RF_SIZE) {
		index = location;
		value = val;
		rFile[location] = val;
	}
	else {
		cout << "Unable to set " << val << " to register " << location << " because register DNE \n";
	}
}
int RegisterFile::getVal(int location) {
	if (location < RF_SIZE) {
		index = location;
		return(rFile[location]);
	}
	else {
		cout << "Unable to get a value from register " << location << " because register DNE \n";
		return(0);
	}
}
int RegisterFile::getLastIndex() {
	return(index);
}
int RegisterFile::getLastVal() {
	return(value);
}
void RegisterFile::clearRF() {
	int i = 0;
	for (i = 0; i < RF_SIZE; i++) {
		rFile[i] = 0;
	}
}
void RegisterFile::printRF() {
	cout << "Register File: \n";
	for (int i = 0; i < RF_SIZE; i++) {
		cout << "r" << i << " : ";
		if (rFile[i] == 0)
			cout << "\n";
		else
			cout << rFile[i] << endl;
	}
}
//---------------------------------------------------------------//

// toInt Function
int toInt(string str) {
	int len = str.length();
	int val = 0;
	for (int i = 0; i < len; i++) {
		char a = str[i];
		for (int j = 0; j < 10; j++) {
			if (a == (j + 48)) {
				val = val + (j * pow(10,len - i - 1));
			}
		}
	}
	return val;
}