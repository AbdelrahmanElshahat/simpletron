#include <stdio.h>
#include <string.h>
#ifndef _SML_EXE_h
#define _SML_EXE_h
#define MEMORY_SIZE 100


FILE *pFile;
typedef int word_t;
//word_t instruction;
int location;

typedef enum _istruction_set_t{
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
void Subtract(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Divide(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Multiply(word_t *memory,word_t operand,registers_t *SMLRegisters,word_t *error);
void Branch(word_t *memory,word_t operand,registers_t *SMLRegisters);
void Branchng(word_t *memory,word_t operand,registers_t *SMLRegisters);
void BranchZero(word_t *memory,word_t operand,registers_t *SMLRegisters);
void ErrorHandling(word_t *error);
void Halt();
void dumpMemory(word_t *memory);
int checkHALT(word_t *memory);
int choice();
#endif
