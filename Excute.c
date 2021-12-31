//
// Created by abdelrahmanelshahat on 19/12/2021.
//
#include "SML_exe.h"
/*this function lets the control code apply the operations according to the operand and operator */
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
        case AND : And(memory,operand,SMLRegisters);
            break;
        case OR : Or(memory,operand,SMLRegisters);
            break;
        case ADD_I: Add_I(memory,operand,SMLRegisters,error);
            break;
        case SUB_I: Sub_I(memory,operand,SMLRegisters);
            break;
        case DIVIDE_I:Divide_I(memory,operand,SMLRegisters,error);
            break;
        case INCREMENT:Increment(memory,operand,SMLRegisters);
            break;
        case CLEAR:Clear(SMLRegisters);
            break;
        case MULTIPLY_I:Mlutiply_I(memory,operand,SMLRegisters,error);
            break;
        case HALT: Halt();
            break;

    }

}
/*Reads The instruction from the user*/
void Read(word_t *memory,word_t operand){
    printf("console Read :");
    scanf("%d",&memory[operand]);
}
/*Prints the value from Memory Location*/
void Write(word_t *memory,word_t operand){
    printf("\n\n\n\t\t\t\tconsole Write: %d\n\n\n\n",memory[operand]);
}
/*Loads value from Specific location into The Accumulator*/
void Load(word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator) = memory[operand];
}
/*Store The value of Accumulator into specific location*/
void Store(word_t *memory,word_t operand,registers_t *SMLRegisters){
    memory[operand]=(SMLRegisters->accumulator);
}
/*Add value from specific location to The Accumulator and Store The value in the Accumulator */
void Add(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    (SMLRegisters->accumulator)+=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=1;
    }
}
/*Subtract value from specific location From The Accumulator and Store The value in the Accumulator */
void Subtract(const word_t *memory,word_t operand,registers_t *SMLRegisters){
    (SMLRegisters->accumulator)-=memory[operand];
}
/*Divide value from specific location By The Accumulator and Store The value in the Accumulator */
void Divide(const word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    if((memory[operand])==0){
        *error=2;

    } else {
        (SMLRegisters->accumulator) /= memory[operand];
    }
}
/*Multiply value from specific location by The Accumulator and Store The value in the Accumulator */
void Multiply(const word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    (SMLRegisters->accumulator)*=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=3;

    }
}
/*Jump to Specific Location in Memory */
void Branch(word_t *memory,word_t operand,registers_t *SMLRegisters){
    SMLRegisters->instructionCounter = operand;
}
/*Jump to Specific Location in Memory if the Value of Accumulator is Negative */
void Branchng(word_t *memory,word_t operand,registers_t *SMLRegisters){
    if((SMLRegisters->accumulator)<0){
        SMLRegisters->instructionCounter = operand;
    }
}
/*Jump to Specific Location in Memory if the Value of Accumulator is Zero*/
void BranchZero(word_t *memory,word_t operand,registers_t *SMLRegisters){
    if((SMLRegisters->accumulator)==0){
        SMLRegisters->instructionCounter = operand;
    }
}
/*And value from specific location to The Accumulator and Store The value in the Accumulator */
void And(word_t *memory , word_t operand , registers_t *SMLRegisters)
{
    SMLRegisters->accumulator &= memory[operand];
}
/*Or value from specific location to The Accumulator and Store The value in the Accumulator */
void Or(word_t *memory , word_t operand , registers_t *SMLRegisters)
{
    SMLRegisters->accumulator |= memory[operand];
}
/*Add value from Effective Address from specific location to The Accumulator and Store The value in the Accumulator */
void Add_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    operand = memory[operand];
    operand %=100;
    SMLRegisters->accumulator+=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=1;
    }
}
/*Subtract value from Effective Address from specific location from The Accumulator and Store The value in the Accumulator */
void Sub_I(word_t *memory,word_t operand,registers_t *SMLRegisters){
    operand = memory[operand];
    operand %=100;
    SMLRegisters->accumulator-=memory[operand];
}
/*Divide value from Effective Address from specific location By The Accumulator and Store The value in the Accumulator */
void Divide_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    operand = memory[operand];
    operand %=100;
    if((memory[operand])==0){
        *error=2;

    } else {

        (SMLRegisters->accumulator) /= memory[operand];
    }
}
/*Multiply value from Effective Address from specific location to The Accumulator and Store The value in the Accumulator */
void Mlutiply_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error){
    operand = memory[operand];
    operand %=100;
    (SMLRegisters->accumulator)*=memory[operand];
    if((SMLRegisters->accumulator)>9999){
        *error=3;

    }
}
/*Increments The value of the specific Location*/
void Increment(word_t *memory,word_t operand,registers_t *SMLRegisters){
    memory[operand]++;
}
/*Clears the Accumulator*/
void Clear(registers_t *SMLRegisters){
    SMLRegisters->accumulator = 0;
}
/*End of Program Execution*/
void Halt(){
    printf("\n\n\n***  execution of Your Program is Finished Successfully ***\n");
}
/*Checks the Errors in Accumulator*/
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
