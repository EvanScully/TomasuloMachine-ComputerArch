#include <iostream>
#include <cmath>

#include "TomasuloMachine.h"


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int clockCycle = 0;

class ExecutionUnit;

//---------------------------------------------------------------//
//                 Station Class Functions:
//---------------------------------------------------------------//
Station::Station() {
	pos = 1;
	Busy = 0;
	Opcode = 4;
	Qj = 0;
	Qk = 0;
	Vj = 0;
	Vk = 0;
	Disp = 0;
	Dest = 0;
	Broad = 0;
	isBroadcasting = 0;
}
int Station::getPos() {
	return pos;
}
//---------------------------------------------------------------//

//---------------------------------------------------------------//
//Reservation Station Class Functions:
//---------------------------------------------------------------//
ReservationStation::ReservationStation() {
	int i = 0;
	
	for (i = 0; i < 5; i++) {
		stat[i].pos = i;
	}
}
bool ReservationStation::isBusy(int loc) {
	return (stat[loc].Busy);
}
void ReservationStation::setBusy(int loc, bool val) {
	stat[loc].Busy = val;
}
bool ReservationStation::isFull(Instruction instr) {
	int op = instr.operation;
	if (op == 1 || op == 0) {
		int j = 0;
		for (int i = 0; i < 3; i++) {
			if (isBusy(i))
				j++;
		}
		if (j == 3)
			return 1;
	}
	if (op == 2 || op == 3) {
		int j = 0;
		for (int i = 3; i < 5; i++) {
			if (isBusy(i))
				j++;
		}
		if (j == 2)
			return 1;
	}
	return 0;
}
bool ReservationStation::isVReady() {
	return 0;
}
bool ReservationStation::isQReady() {
	return 0;
}
void ReservationStation::setOrder(int loc, int order) {
	stat[loc].order = order;
}
void ReservationStation::setOpcode(int loc, int op) {
	stat[loc].Opcode = op;
}
void ReservationStation::setQj(int loc, int q) {
	stat[loc].Qj = q;
}
void ReservationStation::setQk(int loc, int q) {
	stat[loc].Qk = q;
}
void ReservationStation::setVj(int loc, RegisterFile rFile) {
	stat[loc].Vj = rFile.getVal(stat[loc].Qj);
}
void ReservationStation::setVk(int loc, RegisterFile rFile) {
	stat[loc].Vk = rFile.getVal(stat[loc].Qk);
}
void ReservationStation::setDisp(int loc, int disp) {
	stat[loc].Disp = disp;
}
void ReservationStation::setDest(int loc, int dest) {
	stat[loc].Dest = dest;
}
void ReservationStation::setBroad(int loc, int broad) {
	stat[loc].Broad = broad;
}
void ReservationStation::setIsBroadcasting(int loc, int val) {
	stat[loc].isBroadcasting = val;
}
int ReservationStation::getOpcode(int loc) {
	return stat[loc].Opcode;
}
int ReservationStation::getQj(int loc) {
	return stat[loc].Qj;
}
int ReservationStation::getQk(int loc) {
	return stat[loc].Qk;
}
int ReservationStation::getVj(int loc) {
	return stat[loc].Vj;
}
int ReservationStation::getVk(int loc) {
	return stat[loc].Vk;
}
int ReservationStation::getDest(int loc) {
	return stat[loc].Dest;
}
int ReservationStation::getBroad(int loc) {
	return stat[loc].Broad;
}
bool ReservationStation::isBroadcasting(int loc) {
	return stat[loc].isBroadcasting;
}
void ReservationStation::clearStation(int loc) {
	stat[loc].pos = 1;
	stat[loc].Busy = 0;
	stat[loc].Opcode = 4;
	stat[loc].Qj = 0;
	stat[loc].Qk = 0;
	stat[loc].Vj = 0;
	stat[loc].Vk = 0;
	stat[loc].Disp = 0;
	stat[loc].Dest = 0;
	stat[loc].Broad = 0;
	stat[loc].isBroadcasting = 0;
}

void ReservationStation::printRS() {
	cout << "Reservation Station:"  << "\n";
	cout << "      Busy    Op    Vj    Vk    Qj    Qk    Disp \n";
	std::string opString = "   ";
	for (int i = 0; i < 5; i++) {
		if (stat[i].Opcode == 0) {
			opString = "Add";
		} else if (stat[i].Opcode == 1) {
			opString = "Sub";
		} else if (stat[i].Opcode == 2) {
			opString = "Mul";
		} else if (stat[i].Opcode == 3) {
			opString = "Div";
		} else if (stat[i].Opcode == 4) {
			opString = "   ";
		}
		cout << "RS" << i+1 << "    " << stat[i].Busy << "     " << opString << "    " << stat[i].Vj	<< "     " << stat[i].Vk << "     " << stat[i].Qj << "     " << stat[i].Qk << "      " << stat[i].Disp << "\n";
	}
	cout << "\n";
}

Station ReservationStation::DispatchAS() {
	if (stat[0].Opcode != 4) {
		for (int i = 0; i < 5; i++) {
			if (stat[0].order > stat[i].order) {
				if (stat[0].Qj == stat[i].Dest || stat[0].Qk == stat[i].Dest) {
					return Station();
				} 
			}
		}
		return stat[0];
	} else if (stat[1].Opcode != 4) {
		for (int i = 0; i < 5; i++) {
			if (stat[1].order > stat[i].order) {
				if (stat[1].Qj == stat[i].Dest || stat[1].Qk == stat[i].Dest) {
					return Station();
				} 
			}
		}
		return stat[1];
	} else if (stat[2].Opcode != 4) {
		for (int i = 0; i < 5; i++) {
			if (stat[2].order > stat[i].order) {
				if (stat[2].Qj == stat[i].Dest || stat[2].Qk == stat[i].Dest) {
					return Station();
				} 
			}
		}
		return stat[2];
	}
	return Station();
}

Station ReservationStation::DispatchMD() {
	if (stat[3].Opcode != 4) {
		for (int i = 0; i < 5; i++) {
			if (stat[3].order > stat[i].order) {
				if (stat[3].Qj == stat[i].Dest || stat[3].Qk == stat[i].Dest) {
					return Station();
				} 
			}
		}
		return stat[3];
	} else if (stat[4].Opcode != 4) {
		for (int i = 0; i < 5; i++) {
			if (stat[4].order > stat[i].order) {
				if (stat[4].Qj == stat[i].Dest || stat[4].Qk == stat[i].Dest) {
					return Station();
				} 
			}
		}
		return stat[4];
	}
	return Station();
}
//---------------------------------------------------------------//

//---------------------------------------------------------------//
//             Execution Unit Class Functions:
//---------------------------------------------------------------//
ExecutionUnit::ExecutionUnit() {
    busy = false;
    ready = false;
    startClock = 0;
    clockDifference = 0;
    broadcast = Station();
}

bool ExecutionUnit::isBusy() {
    return busy;
}

bool ExecutionUnit::isReady(int currentClock) {
    if ((currentClock - startClock) == clockDifference) {
        ready = true;
    } else {
        ready = false;
    }
    return ready;
}

void ExecutionUnit::execute(Station station, int currentClock) {
    startClock = currentClock;
    busy = 1;
    broadcast = station;
	if (broadcast.Opcode == 0) {
        clockDifference = 2;
    }
    if (broadcast.Opcode == 1) {
        clockDifference = 2;
    }
    if (broadcast.Opcode == 2) {
        clockDifference = 10;
    }
    if (broadcast.Opcode == 3) {
        clockDifference = 40;
    }
}

Station ExecutionUnit::Broadcast() {
    busy = 0;
    if (broadcast.Opcode == 0) {
        broadcast.Broad = broadcast.Vj + broadcast.Vk;
    }
    if (broadcast.Opcode == 1) {
        broadcast.Broad = broadcast.Vj - broadcast.Vk;
    }
    if (broadcast.Opcode == 2) {
        broadcast.Broad = broadcast.Vj * broadcast.Vk;
    }
    if (broadcast.Opcode == 3) {
        broadcast.Broad = broadcast.Vj / broadcast.Vk;
    }
    return broadcast;
}
//---------------------------------------------------------------//

//---------------------------------------------------------------//
//             Register File Class Functions:
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
		cout << "R" << i << " : ";
		cout << rFile[i] << endl;
	}
	cout << "\n";
}
//---------------------------------------------------------------//

//---------------------------------------------------------------//
//           Instruction Queue Class Functions:
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
		//cout << "Queue is empty, You get a NOP!!" << endl; return(value);
		return(value);
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
	cout << "Instruction Queue:" << "\n";
	if (isEmpty()) {
		cout << "Empty!!" << "\n";
	}
	else {
		for (i = front; i <= rear; i++)
			myqueue[i].printInstr();
	}
	cout << "\n";
}
//---------------------------------------------------------------//

//---------------------------------------------------------------//
//              Intruction Class Functions :
//---------------------------------------------------------------//
Instruction::Instruction(int oper, int regd, int regs, int regt) {
	operation = oper;
	Rs = regs;
	Rt = regt;
	Rd = regd;
}
Instruction::Instruction() {	//Essentially a NOP
	operation = 4;
	Rs = RF_SIZE;
	Rt = RF_SIZE;
	Rd = RF_SIZE;
}
void Instruction::printInstr() {
	if (operation == 4) {
		cout << "NOP";
		return;
	}
	else {
		cout << "R" << Rd << " = R" << Rs;
		switch (operation) {
		case 0:
			cout << " + R" << Rt << endl;
			break;
		case 1:
			cout << " - R" << Rt << endl;
			break;
		case 2:
			cout << " * R" << Rt << endl;
			break;
		case 3:
			cout << " / R" << Rt << endl;
			break;
		default:
			break;
		}
	}
}
//---------------------------------------------------------------//

//---------------------------------------------------------------//
//         Register Allocation Table Class Functions :
//---------------------------------------------------------------//
RegisterAllocationTable::RegisterAllocationTable(){
    for (int i = 0; i < RF_SIZE; i++){
        RAT[i] = -1;
    }
}	
void RegisterAllocationTable::setLoc(int location, int val){
    RAT[location] = val;
}
int RegisterAllocationTable::callLoc(int location){
	return RAT[location];
}
void RegisterAllocationTable::printRAT(){
	cout << "Register Allocation Table:" << "\n";
    for(int i = 0; i < RF_SIZE; i++){
        std::cout << "R" << i << ": ";
        if(RAT[i] == -1)
            std::cout << "\n";
        else
            std::cout << "RS" << RAT[i]+1 << std::endl;
    }
}
//---------------------------------------------------------------//

int main() {
	int numInstr = 0;
	int numClockCycles = 0;
	int order = 0;
	int posInstr = 0;
	int queuePos = 0;
	int rfSize = 0;
	std::vector<std::array<int,4>> instructionsTxt;
	std::string tempString;
	InstructionQueue iQueue = InstructionQueue();
	RegisterFile regFile = RegisterFile();
	Instruction issue = Instruction(); 
	ReservationStation reservationStation = ReservationStation();
	Station dispatchAS = Station();
	Station dispatchMD = Station();
	ExecutionUnit executionUnitAS = ExecutionUnit();
	ExecutionUnit executionUnitMD = ExecutionUnit();
	Station broadcast = Station();
	RegisterAllocationTable rat = RegisterAllocationTable();

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
				int loc = line - (2 + numInstr);
				regFile.setVal(loc,val);
				instructionsTxt.push_back({val, 0, 0, 0});
				cout << instructionsTxt[line][0] << "\n";
			}


			line++;
			mystr = "";
			
		}
	} //End array Creation

	//Clock Cycle 0 Printout
	cout << "\n";
	cout << "Clock Cycle: 0" << "\n";
	cout << "\n";
	iQueue.displayQueue();
	regFile.printRF();
	reservationStation.printRS();
	rat.printRAT();

	for(int i=0; i < numClockCycles; i++) {
		clockCycle++;
		//cout << "Clock Cycle: " << clockCycle << "\n";
		//cout << "\n";
		
		//Broadcast
		if (executionUnitMD.isReady(clockCycle)) {
			broadcast = executionUnitMD.Broadcast();
			broadcast.isBroadcasting = 1;
		}
		if (broadcast.isBroadcasting == 0) {
			if (executionUnitAS.isReady(clockCycle)) {
				broadcast = executionUnitAS.Broadcast();
				broadcast.isBroadcasting = 2;
			}
		}

		if (broadcast.isBroadcasting) {
			regFile.setVal(broadcast.Dest, broadcast.Broad);
			for (int i = 0; i < 5; i++) {
				if (reservationStation.getQj(i) == broadcast.Dest) {
					reservationStation.setVj(i, regFile);
				}
				if (reservationStation.getQk(i) == broadcast.Dest) {
					reservationStation.setVk(i, regFile);
				}
			}
			//Set ReservationStation
		}

		//Dispatch
		dispatchAS = reservationStation.DispatchAS();
		dispatchMD = reservationStation.DispatchMD();

		if (dispatchAS.Opcode != 4) {
			if (!executionUnitAS.isBusy()) {
				executionUnitAS.execute(dispatchAS, clockCycle);
				reservationStation.setDisp(dispatchAS.getPos(), clockCycle);
			}
		}
		if (dispatchMD.Opcode != 4) {
			if (!executionUnitMD.isBusy()) {
				executionUnitMD.execute(dispatchMD, clockCycle);
				reservationStation.setDisp(dispatchMD.getPos(), clockCycle);
			}
		}

		//Broadcast free the Reservation Station
		if (broadcast.isBroadcasting == 1) {
			reservationStation.setBusy(dispatchMD.getPos(), 0);
			reservationStation.clearStation(dispatchMD.getPos());
			executionUnitMD.busy = 0;
			broadcast.isBroadcasting = 0;
		}
		if (broadcast.isBroadcasting == 2) {
			reservationStation.setBusy(dispatchAS.getPos(), 0);
			reservationStation.clearStation(dispatchAS.getPos());
			executionUnitAS.busy = 0;
			broadcast.isBroadcasting = 0;
		}
		
		//Issue
		if (reservationStation.isFull(issue) == 0) {
			issue = iQueue.Issue();

			if (issue.operation == 0 || issue.operation == 1) {
				if (!reservationStation.isBusy(0)) {
					reservationStation.setBusy(0, true);
					reservationStation.setOpcode(0, issue.operation);
					reservationStation.setDest(0, issue.Rd);
					reservationStation.setQj(0, issue.Rs);
					reservationStation.setQk(0, issue.Rt);
					reservationStation.setVj(0, regFile);
					reservationStation.setVk(0, regFile);
					order++;
					reservationStation.setOrder(0, order);
					rat.setLoc(issue.Rd, 0);
				} else if (!reservationStation.isBusy(1)) {
					reservationStation.setBusy(1, true);
					reservationStation.setOpcode(1, issue.operation);
					reservationStation.setDest(1, issue.Rd);
					reservationStation.setQj(1, issue.Rs);
					reservationStation.setQk(1, issue.Rt);
					reservationStation.setVj(1, regFile);
					reservationStation.setVk(1, regFile);
					order++;
					reservationStation.setOrder(1, order);
					rat.setLoc(issue.Rd, 1);
				} else if (!reservationStation.isBusy(2)) {
					reservationStation.setBusy(2, true);
					reservationStation.setOpcode(2, issue.operation);
					reservationStation.setDest(2, issue.Rd);
					reservationStation.setQj(2, issue.Rs);
					reservationStation.setQk(2, issue.Rt);
					reservationStation.setVj(2, regFile);
					reservationStation.setVk(2, regFile);
					order++;
					reservationStation.setOrder(2, order);
					rat.setLoc(issue.Rd, 2);
				}
			}
			if (issue.operation == 2 || issue.operation == 3) {
				if (!reservationStation.isBusy(3)) { 
					reservationStation.setBusy(3, true);
					reservationStation.setOpcode(3, issue.operation);
					reservationStation.setDest(3, issue.Rd);
					reservationStation.setQj(3, issue.Rs);
					reservationStation.setQk(3, issue.Rt);
					reservationStation.setVj(3, regFile);
					reservationStation.setVk(3, regFile);
					order++;
					reservationStation.setOrder(3, order);
					rat.setLoc(issue.Rd, 3);
				} else if (!reservationStation.isBusy(4)) {
					reservationStation.setBusy(4, true);
					reservationStation.setOpcode(4, issue.operation);
					reservationStation.setDest(4, issue.Rd);
					reservationStation.setQj(4, issue.Rs);
					reservationStation.setQk(4, issue.Rt);
					reservationStation.setVj(4, regFile);
					reservationStation.setVk(4, regFile);
					order++;
					reservationStation.setOrder(4, order);
					rat.setLoc(issue.Rd, 4);
				}
			}
		}
		
	}
	cout << "-----------------" << endl << "Clock Cycle: " << clockCycle << endl << endl;
	iQueue.displayQueue();
	regFile.printRF();
	reservationStation.printRS();
	rat.printRAT();
}