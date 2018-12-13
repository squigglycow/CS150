#include <stdio.h>
#include <string.h>
/* This is Jacob's Word Reversal program, it will take the input from a user and enter it backwards. 
It will print backwards until it runs out of lines of text to read.
*/


int main()
{ 
	printf("\nWelcome to Jacob's Word Reversal have at it.\n---------------------\n"); //intro
	
	
    char words[1000],input[1000];
    int start=0,end=0;
    printf("Enter a grocery list, put any items that have multiple words with a - like rice-crispy:\n");
    fgets(words,1000,stdin);
    
//Character reversing starts    
	while(words[start]!='\0') // if there's still input keep incrementing ie keep goign though input
	{
		start++;
	}
	
	while(start>0)
	{
	
		input[end]=words[--start];
		++end;
	
	}
	input[end]='\0';
//Character reversing ends

	printf("\nReversed grocery list:\n\n");
    for(start=0;input[start]!='\0';start++) // basically it goes from the end of the original text and prints that last thing first until there's nothing left to print
    {
    
       if(input[start+1]==' ' || input[start+1]==NULL) // getting a warning here, dunno how to fix without breaking
       {
	   
           for(end=start;end>=0 && input[end]!=' ';end--)
           {
           		printf("%c",input[end]);

           	}
			printf(" "); // messed up in the for loop, either the first word starts on a separate line or it starts with a space, dunno why, I'm not that smart to figure it out.
		}

    }
    
    
	printf("\n\nThanks for using the word reversal program\n"); // farewell
}

