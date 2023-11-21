<<<<<<< HEAD
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <array>
#include <vector>

#include "InstructionQueue.h"
#include "Instruction.h"
#include "RegisterFile.h"
#include "ExecutionUnit.h"
#include "RegisterAllocationTable.h"
#include "ReservationStation.h"

#define IQ_SIZE 100
#define RF_SIZE 8


int toInt(std::string str);
=======
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

>>>>>>> 58e39b6d21926b6dee40983366fa9cf8807b9b41
