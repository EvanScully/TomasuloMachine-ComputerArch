
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
	int order;
	int pos;
	bool Busy;
	int Opcode;
	int Vj;
	int Vk;
	int Qj;
	int Qk;
	int Disp;
	int Dest;
	int Broad;
	int isBroadcasting;
	int getPos();
};

class ReservationStation {
private:
	Station stat[5];
public:
	ReservationStation();
	bool isBusy(int loc);
	void setBusy(int loc, bool val);
	bool isFull(Instruction instr);
	bool isVReady();
	bool isQReady();
	void setOrder(int loc, int order);
	void setOpcode(int loc, int oper);
	void setVj(int loc, RegisterFile rFile);
	void setVk(int loc, RegisterFile rFile);
	void setQj(int loc, int q);
	void setQk(int loc, int q);
	void setDisp(int loc, int disp);
	void setDest(int loc, int dest);
	void setBroad(int loc, int broad);
	void setIsBroadcasting(int loc, int val);
	void clearStation(int loc);
	int getOrder(int loc);
	int getOpcode(int loc);
	int getVj(int loc);
	int getVk(int loc);
	int getQj(int loc);
	int getQk(int loc);
	int getDest(int loc);
	int getBroad(int loc);
	bool isBroadcasting(int loc);
	void printRS();
	void Issue(Instruction instr);
	Station DispatchAS();
	Station DispatchMD();
};




#endif // !RESERVATIONSTATION_H