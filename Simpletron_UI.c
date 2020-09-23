#include "Simpletron_UI.h"

void Run_Program()
{
	Welcome_Message();
	Run();
}

void Welcome_Message()
{
 printf("*** Welcome to the Simpletron! ***\n"
	  "*** Please enter your program one instruction ***\n"
	  "*** (or data word) at a time. I will type the ***\n"
	  "*** location number and a question mark (??).  ***\n"
	  "*** You then type the word for that location. ***\n"
	  "*** Type the sentinel -99999 to stop entering ***\n"
	  "*** your program. ***\n\n");
	  }
