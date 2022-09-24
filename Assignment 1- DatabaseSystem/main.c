#include "function.h"

int main()
{
	// The first menu
	
	InitQueue();
	menu_function(1,"\0");
	char ch[100];
	printf("Your choice:");
	scanf_s("%s", &ch, sizeof(ch));
	puts("");
	
	// Check if a filename has been specified in the command 
	if (strcmp("Stop", ch) == 0 || strcmp("2", ch) == 0 || strcmp("STOP", ch) == 0)
	{
		printf("Thank you for your time! \n");
		return(0);
	}
	else
	{
		Start_Stopfunction();
	}
	return(0);

	char str[100];			// variable to hold the input from users
	

}