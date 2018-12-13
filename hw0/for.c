#include <stdio.h>

// define function greet which will print "hello" to the given name
void sayHello(char* name) // you use char* for strings (this is a parameter) - string is a word in double quotes 
{
    printf("Hello %s\n", name); // this will print "Hello" then the given name in the function greet

}


void main(int argc, char* argv[] )
{
int argIndex; // this declares a variable of the class int

argIndex = 1; // this sets the variable argIndex to 1


	for (argIndex =1; argIndex < argc; argIndex = argIndex + 1)
	{
	printf("%d. ",argIndex); //subsitute argIndex for %d, printed as an integer
	sayHello(argv[argIndex]);
	}

	if (argc < 2)
	{
	printf("\nNeed more words man\n");
	}


}



