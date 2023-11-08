
#include "TomasuloMachine.h"

int main()
{
	// Read Instruction File

	std::ifstream myfile("Instructions.txt");
	if (myfile.is_open()) {
		char mychar;
		while (myfile) {
			mychar = myfile.get();
			std::cout << mychar << "";
		}
	}

	return 0;

}