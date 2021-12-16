#include "Simpletron_UI.h"
#include <stdio.h>

void Run_Program()
{
	Welcome_Message();
	Run();
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
           "\tHALT = 43 \n"
           "\tEnter The Instruction One by One Followed By Memory location in Two Decimal Places \n"
           "\tAfter Finishing Entering Your program Enter The Value -99999 To Start Execution ****\n"
           "\nThe Machine will start to Execute The Instructions and Show the output\n\n");
	  }
