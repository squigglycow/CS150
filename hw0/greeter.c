#include <stdio.h>

// define function greet which will print "hello" to the given name
void sayHello(char* name) // you use char* for strings (this is a parameter) - string is a word in double quotes 
{
    printf("\nHello %s\n\n", name); // this will print "Hello" then the given name in the function greet

}


/*
Notes:
argc -> a count of how many arguments there are (type: int)
argv -> is a list(array) of the args themselves. these are strings / list of strings
you can pick things out of the list by putting a number in sq brackets [] after the name of the list / array
*/


void main(int argc, char* argv[] )
{
    // example of using the greet function
    sayHello(argv[0]); // a string is a word in double quotes

}
