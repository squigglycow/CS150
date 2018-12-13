#include <stdio.h>

// program to add up numbers the user enters on the command line
// ex ./addemup 5 77 99



void main(int argc, char* argv[])
{
	int total; // defines variable to store the total
	//total = argv[1] + argv [2];  strings are text data and you can't treat text like num data
	int argIndex, x;
	argIndex = 1; // initialize
	total = 0; // initialize

	
	//repeat for each number in the list, add that number to total
	while(argIndex < argc)
	{
			sscanf(argv[argIndex],"%d",&x);
			total = total + x;
			argIndex = argIndex + 1; //increment argIndex
			
	}
	printf("\nThe sum is %d\n",total);
}	


/* challenge: add up all the numbers a user inputs, aka if just 0 then outputs 0, 
if they input 5 1 9 8 4 0 12 943 then add those up, and etc. */
