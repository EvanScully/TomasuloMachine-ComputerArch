#include <iostream>
#include <fstream>
#include <string>

#include "RegisterAllocationTable.h"

#define RF_SIZE 8

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
        for(int i = 0; i < RF_SIZE; i++){
            std::cout << "r" << i << " : ";
            if(RAT[i] == 0)
                std::cout << "\n";
            else
                std::cout << RAT[i] << std::endl;
        }
    }
