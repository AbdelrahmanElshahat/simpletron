#include "Simpletron_UI.h"

void Run_Program()
{
    int choose = 0;
	Welcome_Message();
    do{
        Run();
        printf("\n\nEnter 1 to Run Another program:");
        scanf("%d",&choose);
    }while(choose==1);

}

void Welcome_Message()
{
    printf("\t**** Welcome to Our Simple Machine\n"
           "\tOur Program simulates A Machine with this Digital Instruction Set\n"
           "\tREAD = 10,\n"
           "\tWRITE = 11,\n"
           "\tLOAD = 20,\n"
           "\tSTORE = 21,\n"
           "\tADD = 30,\n"
           "\tSUBTRACT = 31,\n"
           "\tDIVIDE = 32,\n"
           "\tMULTIPLY = 33,\n"
           "\tBRANCH = 40,\n"
           "\tBRANCHNEG = 41,\n"
           "\tBRANCHZERO = 42,\n"
           "\tAND = 53,\n"
           "\tOR = 54,\n"
           "\tHALT = 43, \n"
           "\tADD_I = 56,\n"
           "\tSUB_I = 57,\n"
           "\tDIVIDE_I=58,\n"
           "\tMULTIPLY_I=59,\n"
           "\tINCREMENT = 60,\n"
           "\tCLEAR = 61,\n"
           "\tEND = -99999.\n"
           "\tEnter The Instruction One by One Followed By Memory location in Two Decimal Places \n"
           "\tAfter Finishing Entering Your program Enter The Value -99999 To Start Execution ****\n"
           "\nThe Machine will start to Execute The Instructions and Show the output\n\n");
	  }
      /*Let the user  choose  the operating mode */
int Choice() {
    printf("0- To Enter Your program\n1- To parse A File\n");
    int choice;
    do {
        printf("Your Choice :");
        scanf("%d",&choice);
        if (choice == 0) {
            return 0;
        } else if(choice == 1)
            return 1;
        printf("Invalid Choice \n0- To Enter Your program\n1- To parse A File\n");
    }
    while (choice != 0 || choice != 1);

}
/*Prints the contents of Memory and Registers*/
void DumpMemory(word_t *memory, registers_t *registers)
{
    int i; /* counter */

    printf( "\n%s\n%-23s%+05d\n%-23s%5.2d\n%-23s%+05d\n%-23s%5.2d\n%-23s%5.2d", "REGISTERS:", "accumulator", registers->accumulator, "instructioncounter",
            registers->instructionCounter, "instructionregister", registers->instructionRegister,  "operationcode", (registers->instructionRegister)/100, "operand", (registers->instructionRegister)%100 );

    printf("\n\nMEMORY:\n    ");


    //print column headers
    for(i = 0; i <= 9; i++)
    {
        printf("%5d ", i);
    }//end for


    //printf row headers and memory contents
    for(i = 0; i < MEMORY_SIZE; i++)
    {
        //print in increments of 10
        if(i % 10 == 0)
        {
            printf("\n%2d ", i);
        }//end if
        printf("%+05d ", memory[i]);
    }//end for
    printf("\n");
}//end DumpMemory
