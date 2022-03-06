//
// Created by abdelrahmanelshahat on 19/12/2021.
//
#include "SML_exe.h"
/*fetch Instruction from the Memory And Store it in Instruction Registers*/
void Fetch(word_t *memory, registers_t *SMLRegisters){
    SMLRegisters->instructionRegister = memory[SMLRegisters->instructionCounter];
    (SMLRegisters->instructionCounter)++;

}
/*Decode The value of the instruction Registers into Operation code And Operand */
void Decode(registers_t *SMLRegisters, word_t *opCode, word_t *operand){
    *opCode = (SMLRegisters->instructionRegister)/100;
    *operand = (SMLRegisters->instructionRegister)%100;
}