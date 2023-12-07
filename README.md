# TomasuloMachine-ComputerArch

This project simulates a Tomasulo Machine in C++.

Jackob Koshiol and Evan Scully were the only contributors to this project.

Our input is pulled directly from the Instructions.txt file. The format of the input is as follows:

 - The number of instructions
 - The number of clock cycles to simulate
 - The instructions
 - Then, the values for the registered file

The instructions are written in the format of operation, destination register, source register 1, source register 2
where the operations were 0 for addition, 1 for subtraction, 2 for multiplication, and 3 for division (if you look closely
at the code, you can see that there is sometimes a 4; this value is used as a base case/NOP operation). After our input file
is pulled, the program initially places the instructions into the Instruction Queue, the register values into the Register
File and stores the clock cycle and number of instruction values into io integers.

We then run through a pipeline where we first broadcast the values from the execution unit. We then pull the dispatched stations
from the reservation station into the execution unit. We are then able to issue from the Instruction Queue to the Reservation
Station. 

Our final clock cycle output can be seen below (using the Instruction.txt file)

![alt text](/images/TomasuloOutput.png)


