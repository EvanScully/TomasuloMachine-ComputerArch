
#include <iostream>
#include <fstream>
#include <string>


#include "ReservationStation.h"


Station::Station() {
	pos = 1;
	Busy = 0;
	Opcode = 5;
	Qj = 0;
	Qk = 0;
	Vj = 0;
	Vk = 0;
	Disp = 0;
}

ReservationStation::ReservationStation() {
	int i = 0;
	
	for (i = 0; i < 5; i++) {
		stat[i].pos = i + 1;
	}
}
bool ReservationStation::isBusy(int loc) {
	return (stat[loc].Busy == 1);
}
bool ReservationStation::isFull(Instruction instr) {
	int op = instr.operation;
	if (op <= 2) {
		int j = 0;
		for (int i = 0; i < 3; i++) {
			if (isBusy(i))
				j++;
		}
		if (j == 3)
			return 1;
	}
	if (op > 2 && op < 4) {
		int j = 0;
		for (int i = 3; i < 5; i++) {
			if (isBusy(i))
				j++;
		}
		if (j == 2)
			return 1;
	}
	else
		return 0;
}
bool ReservationStation::isVReady() {
	return 0;
}
bool ReservationStation::isQReady() {
	return 0;
}
void ReservationStation::setOpcode(int loc, int op) {

}
void ReservationStation::setQj(int loc, int q) {

}
void ReservationStation::setQk(int loc, int q) {

}
void ReservationStation::setVj(int loc, RegisterFile rFile) {

}
void ReservationStation::setVk(int loc, RegisterFile rFile) {

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
void ReservationStation::printRS() {

}
void ReservationStation::Issue(Instruction instr) {
	
}
Station ReservationStation::Dispatch(int loc, int cc) {
	stat[loc].Disp = cc;
	stat[loc].Busy = 0;
	return stat[loc];

}





