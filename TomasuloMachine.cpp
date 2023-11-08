
#include "TomasuloMachine.h"

int main()
{
	// Read Instruction File

	/*	ASCII		Val
		30			0
		31			1
		32			2
		33			3
		34			4
		35			5
		36			6
		37			7
		38			8
		39			9
	*/
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