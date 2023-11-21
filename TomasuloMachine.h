#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <array>
#include <vector>

#include "InstructionQueue.cpp"
#include "RegisterFile.cpp"
#include "ExecutionUnit.h"
#include "RegisterAllocationTable.h"
#include "ReservationStation.cpp"

#define IQ_SIZE 100
#define RF_SIZE 8


int toInt(std::string str);
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "InstructionQueue.h"
#include "RegisterFile.h"
#include "ExecutionUnit.h"
#include "RegisterAllocationTable.h"
#include "ReservationStation.h"

#ifndef TOMASULOMACHINE_H
#define TOMASULOMACHINE_H

int toInt(std::string str);

#endif 