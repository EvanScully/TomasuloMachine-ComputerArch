#include <iostream>
#include <cmath>

#include "TomasuloMachine.h"

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	int numInstr = 0;
	int numClockCycles = 0;
	int posInstr = 0;
	int queuePos = 0;
	std::vector<std::array<int,4>> instructionsTxt;
	std::string tempString;
	InstructionQueue iQueue = InstructionQueue();
	RegisterFile regFile = RegisterFile();

	std::ifstream myfile("Instructions.txt");
	if (myfile.is_open()) {
		char mychar;
		int line = 0;
		int temp = 0;
		std::string mystr;
		
		while (std::getline(myfile, mystr)) {
			
			int val = std::stoi(mystr);
			//Get line 1 (number of instructions) and put them in the list
			if (line == 0) {
				instructionsTxt.push_back({val, 0, 0, 0});
				numInstr = val;
				cout << instructionsTxt[line][0] << "\n";
			}
			//Get line 2 (number of clock cycles) and put them in the list
			if (line == 1) {
				instructionsTxt.push_back({val, 0, 0, 0});
				numClockCycles = val;
				cout << instructionsTxt[line][0] << "\n";
			}
			//Get instructions and put them in the list
			if ((line > 1) && (line <= numInstr + 1)) {
				posInstr = 0;
				instructionsTxt.push_back({0,0,0,0});
				for(int k = 0; k < mystr.length(); k++) {
					if(mystr[k] == ' ') {
						posInstr++;
					} else {
						tempString = mystr[k];
						auto it = std::next(instructionsTxt.begin(), line);
						(*it)[posInstr] = ((*it)[posInstr] * 10) + std::stoi(tempString);
					}
				}
				Instruction temp(instructionsTxt[line][0], instructionsTxt[line][1], instructionsTxt[line][2], instructionsTxt[line][3]);
				iQueue.enQueue(temp);
				cout << instructionsTxt[line][0] << " " << instructionsTxt[line][1] << " " << instructionsTxt[line][2] << " " << instructionsTxt[line][3] << "\n";
			}
			//Get initial RF values and put them in the list
			if ((line > numInstr + 1)) {
				int loc = line - (3 + numInstr);
				regFile.setVal(loc, val);
				instructionsTxt.push_back({val, 0, 0, 0});
				cout << instructionsTxt[line][0] << "\n";
			}

			line++;
			mystr = "";
			
		}
	} //End array Creation
}