#include <stdio.h>
/*
This is Jacob Weber's adapted multigreet homework assignment for homework 1.
The following program will act like the normal multigreet, that greets multiple people. It 
will additionally add flair to the last person it greets. It will alternate between two greetings
After saying hello to all the names, it should say goodbye to all the names in reverse order
*/




//this function is the original hello
void sayHello(char* name) //char* is a string which takes a name
{
    	printf("\nHello %s\n\n", name); //says hello to name
}

// this is an alternate hello per your instructions
void altHello(char* name) //char* is a string which takes a name
{
    	printf("\nAyyyyyy %s Boyo\n\n", name); //says hello to name
}

  


/*this function sets up intro and ending
the if-do-if-if-while-else is a mess, but it works. It checks how many arguments there are and will
take any number o names. While it's working it will check the counter variable, if it is is even 
(since the program starts at 0) it will start with the original message, then alternate. If there is
no input then you get a message saying you should put some input in.
The for loop will take the previous arguments and information and basically backtrack,
then it will spit out the names in reverse order.

This program will only alternate names for up to 14 names, because I have no idea how to make the
program check odds or evens and I'm lazy. But ti will always spit out names in reverse order regard-
less of how many names you give it
*/
void main(int argc, char* argv[])
{
	printf("Welcome to the Jacob's multigreeter!");
	int argIndex, counter;
	argIndex=1;
	counter=0;
	if (argc >= 2)
	{
		do
		{
			if(counter==0,2,4,6,8,10,12) //origin message
			{
			sayHello(argv[argIndex]);
			argIndex = argIndex + 1;
			counter = counter + 1;
			}
			if(counter==1,3,5,7,9,11,13) // alt message
			{
			altHello(argv[argIndex]);
			argIndex = argIndex + 1; //moves up through input
			counter = counter + 1; // bumps counter, moves to original message
			}
		}
	while(argIndex < argc);
	}
	else
	{
		printf("Please give me some names to say hello to.");//put stuff in program to work
	}
	
	
	
	for(argIndex=argIndex-1; argIndex>0; argIndex=argIndex-1) //backtracks through argindex
	{
		char* name;
		name = argv[argIndex];
		printf("Goodbye %s\n", name); // will say goodbye to everything in reverse order
	}
	
	printf("Thanks for using the program.\n");
}



