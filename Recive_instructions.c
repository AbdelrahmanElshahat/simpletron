//
// Created by abdelrahmanelshahat on 19/12/2021.
//
#include "SML_exe.h"
/*Recives Instruction From The Users*/
void Recieve_Instructions(word_t *memory)
{

    char f_name[50];
    word_t instruction = 0;
    location = 0;
    if(Choice() == 0) {
        while (instruction != eND ) {/*User Enters the instructions from terminal */
            printf("%2d >>", location);
            scanf("%d", &instruction);
            if (Istruction_Is_Valid(instruction)) {
                memory[location] = instruction;
                location++;

            } else if(instruction !=-99999){
                printf("\t****Invalid Instruction, Please Renter The Instruction****\n");
            }
        }
    } else
    {/*User Enters The file Name Which contains The Program*/
        printf("Enter The file Name : ");
        scanf("%s",f_name);
        /*opens the program file*/
        pFile = fopen(f_name, "r");
        while ( fscanf(pFile, "%d",&instruction)>0)
        {

            if (Istruction_Is_Valid(instruction)) {
                memory[location] = instruction;
                location++;

            } else if(instruction !=-99999){
                printf("\t****Invalid Instruction, Please Renter The Instruction****\n");
                break;
            }

        }

    }
}
/*Checks whether the instruction is valid or not*/
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
        case SHIFTRIGHT :
            return  1;
        case SHIFTLEFT :
            return 1;
        case AND :
            return 1 ;
        case OR :
            return 1 ;
        case COMPLEMENT :
            return 1;
        case ADD_I:
            return 1;
        case SUB_I:
            return 1;
        case DIVIDE_I:
            return 1;
        case MULTIPLY_I:
            return 1;
        case eND:
            return 1;
        case CLEAR:
            return 1;
        case INCREMENT:
            return 1;
        default :
            return 0;
    }
}
