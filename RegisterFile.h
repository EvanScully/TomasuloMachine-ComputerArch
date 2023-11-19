#pragma once

class RegisterFile {
private:
	int rFile[RF_SIZE];
public:
	int index;
	int value;
	RegisterFile();
	void setVal(int location, int val);
	int getVal(int location);
	int getLastIndex();
	int getLastVal();
	void clearRF();
	void printRF();
};