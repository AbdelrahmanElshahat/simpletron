#include <stdio.h>
#include <string.h>
#ifndef _SML_EXE_h
#define _SML_EXE_h
#define MEMORY_SIZE 100


FILE *pFile;
typedef int word_t;
int location;
typedef enum istruction_set_t{
	READ = 10,
	WRITE = 11,
	LOAD = 20,
	STORE = 21,
	ADD = 30,
	SUBTRACT = 31,
	DIVIDE = 32,
	MULTIPLY = 33,
	BRANCH = 40,
	BRANCHNEG = 41,
	BRANCHZERO = 42,
	HALT = 43,
    SHIFTRIGHT = 51,
    SHIFTLEFT = 52,
    AND = 53,
    OR = 54,
    COMPLEMENT =55,
    ADD_I = 56,
    SUB_I = 57,
    DIVIDE_I=58,
    MULTIPLY_I=59,
    INCREMENT = 60,
    CLEAR = 61,
    eND = -99999
}instruction_set_t;




typedef struct _registers_t{
	word_t accumulator;
	word_t instructionCounter;
	word_t instructionRegister;
}registers_t;


void Run();
int Istruction_Is_Valid(word_t instruction);
void Recieve_Instructions(word_t *memory);
void Fetch(word_t *memory, registers_t *SMLRegisters);
void Decode(registers_t *SMLRegisters, word_t *opCode, word_t *operand);
void Execute(registers_t *SMLRegisters,word_t *memory, word_t opCode, word_t operand,word_t *error);
void Read(word_t *memory,word_t operand);
void Write(word_t *memory,word_t operand);
void Load(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Store(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Add(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Subtract(const word_t *memory,word_t operand,registers_t *SMLRegisters);
void Divide(const word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Multiply(const word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Branch(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Branchng(word_t *memory,word_t operand,registers_t *SMLRegisters);
void BranchZero(word_t *memory,word_t operand,registers_t *SMLRegisters);
void And(word_t *memory , word_t operand , registers_t *SMLRegisters);
void Or(word_t *memory , word_t operand , registers_t *SMLRegisters);
void ErrorHandling(word_t *error);
void Halt();
void DumpInstruction(word_t *memory);
int CheckHALT(word_t *memory);
int Choice();
void DumpMemory(word_t *memory, registers_t *registers);
void Add_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Sub_I(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Increment(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Divide_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Mlutiply_I(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Clear(registers_t *SMLRegisters);
#endif
