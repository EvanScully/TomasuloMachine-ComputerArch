#pragma once

#include <iostream>

#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#define IQ_SIZE 100
#define RF_SIZE 8

using namespace std;

class RegisterFile {
public:
	int index;
	int value;
	RegisterFile();
	RegisterFile(int num);
	void setVal(int location, int val);
	int getVal(int location);
	int getLastIndex();
	int getLastVal();
	void clearRF();
	void printRF();
private:
	int rFile[RF_SIZE];
};

#endif