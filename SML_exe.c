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
	while(opCode != HALT)
	{
		Fetch(memory,&registers);
		Decode(&registers,&opCode,&operand);
		Execute(&registers,memory, opCode, operand ,&error);
				if(error !=0){
ErrorHandling(&error);
		}

	}
	//printf("%d\n",registers.accumulator);
}

void Recieve_Instructions(word_t *memory)
{
	word_t instruction = 0;
	int location = 0;
	while(instruction != -99999)
	{
		printf("%2d ??", location);
		scanf("%d", &instruction);
		if(Istruction_Is_Valid(instruction))
		{
			memory[location] = instruction;
			location++;
		}
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

        default : return 0;

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
        case ADD :  Add(memory,operand,SMLRegisters,&error);
        break;
        case SUBTRACT : Subtract(memory,operand,SMLRegisters);
        break;
        case DIVIDE : Divide(memory,operand,SMLRegisters,&error);
        break;
        case MULTIPLY :Multiply(memory,operand,SMLRegisters,&error);
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
    printf("console Writ : %d\n",memory[operand]);
}
void Load(word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator) = memory[operand];
}

void Store(word_t *memory,word_t operand,registers_t *SMLRegisters){
    memory[operand]=(SMLRegisters->accumulator);
}
void Add(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
   // printf("%d\n",(SMLRegisters->accumulator));
   // printf("%d\n",memory[operand]);

    (SMLRegisters->accumulator)+=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=1;
    }
}
void Subtract(word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator)-=memory[operand];
}
void Divide(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    (SMLRegisters->accumulator)/=memory[operand];
    if((memory[operand])==0){
                *error=2;

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
	    printf("*** Simpletron execution terminated ***\n");
}
void ErrorHandling(word_t *error){
    switch(*error){
        case 1: printf("***Overflow occurred***\n***Simpletron will Terminate***\n");
        break;
        case 2 :printf("***Divide by Zero***\n***Simpletron will Terminate***\n");
        break;
        case 3 : printf("***Overflow occurred***\n***Simpletron will Terminate***\n");
        break;

    }
}




