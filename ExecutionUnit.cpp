
#include <iostream>
#include <fstream>
#include <string>


#include "ExecutionUnit.h"
#include "ReservationStation.cpp"

ExecutionUnit::ExecutionUnit() {
    busy = false;
    ready = false;
    startClock = 0;
    clockDifference = 0;
    broadcast = Station();;
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
    if (station.Opcode == 0) {
        clockDifference = 2;
        broadcast.Broad = station.Vj + station.Vk;
    }
    if (station.Opcode == 1) {
        clockDifference = 2;
        broadcast.Broad = station.Vj - station.Vk;
    }
    if (station.Opcode == 2) {
        clockDifference = 10;
        broadcast.Broad = station.Vj * station.Vk;
    }
    if (station.Opcode == 3) {
        clockDifference = 40;
        broadcast.Broad = station.Vj / station.Vk;
    }
}

Station ExecutionUnit::Broadcast() {
    busy = 0;
    return broadcast;
}
