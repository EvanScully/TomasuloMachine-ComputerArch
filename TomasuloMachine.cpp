
#include "TomasuloMachine.h"

using namespace std;

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
					cout << " Line " << line << " :";
				}
				if (line == 2) {
					numClockCycles = val;
				}
				if ((line > 2) && (line <= (2 + numInstr))) {
					instr[posInstr] = val;
					if (posInstr == 3) {
						Instruction temp(instr[0], instr[1], instr[2], instr[3]);
						cout << " Instruction: " << temp.operation << temp.Rs << temp.Rt << temp.Rd;
						
					}
					posInstr = (posInstr + 1) % 4;
				}

				mystrEOL = 1;
				mystr = "";
			}
			if (mychar == '\n') {

				line++;
				cout << "\n Line " << line << " :";
				
			}
				
			if (!mystrEOL) {
				mystr += mychar;
			}
			
			//cout << mychar << "";
		}
	}
	return 0;

}

Instruction::Instruction(int oper, int regs, int regt, int regd) {
	operation = oper;
	Rs = regs;
	Rt = regt;
	Rd = regd;
}



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