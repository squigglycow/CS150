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

    if ( argc >= 2)
    {
    sayHello(argv[1]); 
        if ( argc >= 3)
       {
        sayHello(argv[2]); 
        }
            if ( argc >= 4)
            { 
            sayHello(argv[3]); 
            }
                if ( argc >= 5)
                {
                sayHello(argv[4]); 
                }
                    if ( argc >= 6)
                    {
                    sayHello(argv[5]); 
                    }
    }
}


/*
Challenge: modify the program to handle 1, 2,3, or 4 names properly with no garbage output
Tips:
    ifs within ifs are possible
    ifs separate and sequentially are possible
    == to check equality
    <= to check less than or equal to 
    ifs after else to chain them together




*/
