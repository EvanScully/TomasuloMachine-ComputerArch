#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "RegisterFile.h"
#include "RegisterAllocationTable.h"
#include "InstructionQueue.h"

#ifndef RESERVATIONSTATION_H
#define RESERVATIONSTATION_H

class Station {
public:
	Station();
	int pos;
	bool Busy;
	int Opcode;
	int Vj;
	int Vk;
	int Qj;
	int Qk;
	int Disp;
};

class ReservationStation {
private:
	Station stat[5];
public:
	ReservationStation();
	bool isBusy(int loc);
	bool isFull(Instruction instr);
	bool isVReady();
	bool isQReady();
	void setOpcode(int loc, int oper);
	void setVj(int loc, RegisterFile rFile);
	void setVk(int loc, RegisterFile rFile);
	void setQj(int loc, int q);
	void setQk(int loc, int q);
	int getOpcode(int loc);
	int getVj(int loc);
	int getVk(int loc);
	int getQj(int loc);
	int getQk(int loc);
	void printRS();
	void Issue(Instruction instr);
	Station Dispatch(int loc, int cc);
};




#endif // !RESERVATIONSTATION_H