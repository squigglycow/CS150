#include <stdio.h>

// define function greet which will print "hello" to the given name
void greet(char* name) // you use char* for strings - string is a word in double quotes
{
    printf("\nHello %s\n\n", name); // this will print "Hello" then the given name in the function greet

}



void main()
{
    // example of using the greet function
    greet("Frodo"); // a string is a word in double quotes
    greet("Samwise");
    greet("Bob");

}
