//
// Created by abdelrahmanelshahat on 19/12/2021.
//
#include "SML_exe.h"
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
        case SHIFTRIGHT : ShiftRight(memory,operand,SMLRegisters);
            break;
        case SHIFTLEFT :ShiftLift(memory,operand,SMLRegisters);
            break;
        case AND : And(memory,operand,SMLRegisters);
            break;
        case OR : Or(memory,operand,SMLRegisters);
            break;
        case COMPLEMENT : Complement(SMLRegisters);
            break ;
        case ADD_I: Add_I(memory,operand,SMLRegisters,error);
            break;
        case SUB_I: Sub_I(memory,operand,SMLRegisters);
            break;
        case DIVIDE_I:Divide_I(memory,operand,SMLRegisters,error);
            break;
        case MULTIPLY_I:Mlutiply_I(memory,operand,SMLRegisters,error);
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
    printf("\n\n\n\t\t\t\tconsole Write: %d\n\n\n\n",memory[operand]);
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
void Subtract(const word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator)-=memory[operand];
}
void Divide(const word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    if((memory[operand])==0){
        *error=2;

    } else {
        (SMLRegisters->accumulator) /= memory[operand];
    }
}
void Multiply(const word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
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
void ShiftRight(word_t *memory ,word_t operand ,registers_t *SMLRegisters)
{
    SMLRegisters->accumulator = SMLRegisters->accumulator>> operand;
}
void ShiftLift(word_t *memory , word_t operand , registers_t *SMLRegisters)
{
    SMLRegisters->accumulator = SMLRegisters->accumulator<< operand;
}
void And(word_t *memory , word_t operand , registers_t *SMLRegisters)
{
    SMLRegisters->accumulator &= memory[operand];
}
void Or(word_t *memory , word_t operand , registers_t *SMLRegisters)
{
    SMLRegisters->accumulator |= memory[operand];
}
void Complement (registers_t *SMLRegisters)
{
    SMLRegisters->accumulator =~SMLRegisters->accumulator;
}
void Add_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    SMLRegisters->accumulator+=operand;
    if((SMLRegisters->accumulator)>9999){
        *error=1;
    }
}
void Sub_I(word_t *memory,word_t operand,registers_t *SMLRegisters){
    SMLRegisters->accumulator-=operand;
}
void Divide_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    if((memory[operand])==0){
        *error=2;

    } else {
        (SMLRegisters->accumulator) /= operand;
    }
}
void Mlutiply_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    (SMLRegisters->accumulator)*=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=3;

    }
}
void Halt(){
    printf("\n\n\n***  execution of Your Program is Finished Successfully ***\n");
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
