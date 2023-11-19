
#include "TomasuloMachine.h"

#include <iostream>
#include <fstream>
#include <string>

#include "InstructionQueue.h"
#include "RegisterFile.h"
#include "ExecutionUnit.h"
#include "RegisterAllocationTable.h"
#include "ReservationStation.h"

using namespace std;

// Main Function:
//---------------------------------------------------------------//
int main()
{
	int numInstr = 0, numClockCycles = 0, posInstr = 0, queuePos = 0;
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
	Instruction inst = iQueue.Issue();
	return 0;

}


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