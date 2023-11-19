
#include <iostream>

#include "RegisterFile.h"

using namespace std;

#define IQ_SIZE 100
#define RF_SIZE 8

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