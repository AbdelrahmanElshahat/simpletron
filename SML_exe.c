#include "SML_exe.h"

/*Start of Program Execution */
void Run()
{
	word_t memory[MEMORY_SIZE] = {0};
    registers_t registers = {0, 0, 0};
	word_t opCode = 0;
	word_t operand = 0;
    word_t error = 0;
	Recieve_Instructions(memory);
    DumpInstruction(memory);

    while(opCode != HALT)
	{
      if(CheckHALT(memory) == 0 ){
            printf("***NO HALT INSTRUCTION****\n***Program Terminated***\n");
            break;
        }
		Fetch(memory,&registers);
		Decode(&registers,&opCode,&operand);
		Execute(&registers,memory, opCode, operand ,&error);
        if(opCode != HALT) {
            printf("The Content of Memory at Instruction %d : \n", registers.instructionCounter);
            DumpMemory(memory, &registers);
        }
        if(error !=0){
                 ErrorHandling(&error);
                    break;
		}

	}

    DumpMemory(memory, &registers);
    fclose(pFile);/*close the program file*/
}
/*prints Program Instructions*/
void DumpInstruction(word_t *memory) {

    for (int i = 0; i <MEMORY_SIZE ; i++) {
        if(memory[i] != 0)
            printf("Memory[%d] : %d\n",i , memory[i]);
    }

}
/*Checks the Halt Instruction*/
int CheckHALT(word_t *memory) {

    if ((memory[location-1 ] / 100) == HALT){
        return 1;
    }
    else{

        return 0;
    }
}




