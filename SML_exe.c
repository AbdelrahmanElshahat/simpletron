#include "SML_exe.h"
#include <stdio.h>


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
        if(checkHALT(memory) == 0){
            printf("***NO HALT INSTRUCTION****\n***Program will Terminate***\n");
            break;
        }
		Fetch(memory,&registers);
		Decode(&registers,&opCode,&operand);
		Execute(&registers,memory, opCode, operand ,&error);
        dumpMemory(memory);
        if(error !=0){
                 ErrorHandling(&error);
                    break;
		}

	}
	printf("Value of the Accumulator : %d\n",registers.accumulator);
}

void Recieve_Instructions(word_t *memory)
{
	 instruction = 0;
	 location = 0;
	while(instruction != eND)
	{
		printf("%2d >>", location);
		scanf("%d", &instruction);
		if(Istruction_Is_Valid(instruction))
		{
			memory[location] = instruction;
			location++;

		} /*else{
            printf("\t****Invalid Instruction, Please Renter The Instruction****\n");
        }*/
	}
}
int Istruction_Is_Valid(word_t instruction){
word_t opcode = instruction/100;
      switch(opcode){
      case READ :
        return 1;

              case WRITE :
        return 1;

              case LOAD :
        return 1;

              case STORE :
        return 1;

              case ADD :
        return 1;

              case SUBTRACT :
        return 1;

              case MULTIPLY :
        return 1;

              case DIVIDE:
        return 1;

              case BRANCH :
        return 1;

              case BRANCHNEG :
        return 1;

              case BRANCHZERO :
        return 1;

              case HALT :
        return 1;

              case eND :
        return 1;

              default :
         return 0;
      }
}
void Fetch(word_t *memory, registers_t *SMLRegisters){

    SMLRegisters->instructionRegister = memory[SMLRegisters->instructionCounter];
    (SMLRegisters->instructionCounter)++;

}
void Decode(registers_t *SMLRegisters, word_t *opCode, word_t *operand){
    *opCode = (SMLRegisters->instructionRegister)/100;
    *operand = (SMLRegisters->instructionRegister)%100;
}


void Execute(registers_t *SMLRegisters,word_t *memory, word_t opCode, word_t operand,word_t *error){

    switch(opCode){
        case READ : Read(memory,operand);
        break;
        case WRITE : Write(memory,operand);
        break;
        case LOAD : Load(memory,operand,SMLRegisters);
        break;
        case STORE : Store(memory,operand,SMLRegisters);
        break;
        case ADD :  Add(memory,operand,SMLRegisters,error);
        break;
        case SUBTRACT : Subtract(memory,operand,SMLRegisters);
        break;
        case DIVIDE : Divide(memory,operand,SMLRegisters,error);
        break;
        case MULTIPLY :Multiply(memory,operand,SMLRegisters,error);
        break;
        case BRANCH : Branch(memory,operand,SMLRegisters);
        break;
        case BRANCHNEG : Branchng(memory,operand,SMLRegisters);
        break;
        case BRANCHZERO : BranchZero(memory,operand,SMLRegisters);
        break;
        case HALT: Halt();
        break;

    }

}
void Read(word_t *memory,word_t operand){
    printf("console Read :");
    scanf("%d",&memory[operand]);
}
void Write(word_t *memory,word_t operand){
    printf("console Write: %d\n",memory[operand]);
}
void Load(word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator) = memory[operand];
}

void Store(word_t *memory,word_t operand,registers_t *SMLRegisters){
    memory[operand]=(SMLRegisters->accumulator);
}
void Add(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    (SMLRegisters->accumulator)+=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=1;
    }
}
void Subtract(word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator)-=memory[operand];
}
void Divide(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    if((memory[operand])==0){
        *error=2;

    } else {
        (SMLRegisters->accumulator) /= memory[operand];
    }
}
void Multiply(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    (SMLRegisters->accumulator)*=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=3;

    }
}
void Branch(word_t *memory,word_t operand,registers_t *SMLRegisters){
    SMLRegisters->instructionCounter = operand;
}
void Branchng(word_t *memory,word_t operand,registers_t *SMLRegisters){
    if((SMLRegisters->accumulator)<0){
        SMLRegisters->instructionCounter = operand;
    }
}

void BranchZero(word_t *memory,word_t operand,registers_t *SMLRegisters){
    if((SMLRegisters->accumulator)==0){
        SMLRegisters->instructionCounter = operand;
}
}
void Halt(){
	    printf("***  execution of Your Program is Finished Successfully ***\n");
}
void ErrorHandling(word_t *error){
    switch(*error){
        case 1: printf("***Overflow occurred***\n***Program will Terminate***\n");
        break;
        case 2 :printf("***Divide by Zero***\n***Program will Terminate***\n");
        break;
        case 3 : printf("***Overflow occurred***\n***Program will Terminate***\n");
        break;
        case 4:
            printf("***NO HALT INSTRUCTION****\n***Program will Terminate***\n");
            break;

    }
}
void dumpMemory(word_t *memory) {
    printf("Here is the Content of The Memory : \n");
    for (int i = 0; i <100 ; i++) {
        if(memory[i] != 0)
            printf("\tMemory[%d] : %d\n",i , memory[i]);
    }
    printf("\t****Program loading completed***\n");
    printf("\t****Program execution will begin*****\n");
}
int checkHALT(word_t *memory){
    word_t tempopcode;
    word_t i;
    for ( i = location-1 ;i<location;i++){
       tempopcode = memory[i]/100;
        }
    if(tempopcode != HALT)
        return 0;
    else{
        return 1;
    }

}




