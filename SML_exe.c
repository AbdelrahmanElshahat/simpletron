#include "SML_exe.h"


void Run()
{
	word_t memory[MEMORY_SIZE] = {0};
    registers_t registers = {0, 0, 0};
	word_t opCode = 0;
	word_t operand = 0;
    word_t error = 0;
	Recieve_Instructions(memory);
    dumpMemory(memory);

    while(opCode != HALT)
	{
      if(checkHALT(memory) == 0 ){
            printf("***NO HALT INSTRUCTION****\n***Program Terminated***\n");
            break;
        }
		Fetch(memory,&registers);
		Decode(&registers,&opCode,&operand);
		Execute(&registers,memory, opCode, operand ,&error);
        if(opCode != HALT) {
            printf("The Conent of Memory at Instruction %d : \n", registers.instructionCounter);
           /* dumpMemory(memory);
            printf("\n\n\nValue of the Accumulator : %d\n",registers.accumulator);
            printf("Value of the Instruction Counter : %d\n",registers.instructionCounter);
            printf("Value of the Instruction Register : %d\n\n\n\n",registers.instructionRegister);*/
           dump(memory,&registers);
        }
        if(error !=0){
                 ErrorHandling(&error);
                    break;
		}

	}
	//printf("Value of the Accumulator : %d\n",registers.accumulator);
    dump(memory,&registers);
    fclose(pFile);
}
void dumpMemory(word_t *memory) {
   // printf("Here is the Content of The Memory : \n");
    for (int i = 0; i <MEMORY_SIZE ; i++) {
        if(memory[i] != 0)
            printf("Memory[%d] : %d\n",i , memory[i]);
    }
   /* printf("\t****Program loading completed***\n");
    printf("\t****Program execution will begin*****\n");*/
}
int checkHALT(word_t *memory) {

    if ((memory[location-1 ] / 100) == HALT){
        return 1;
    }
    else{

        return 0;
    }
}




