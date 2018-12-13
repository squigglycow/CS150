#include <stdio.h>
#include <string.h>
/*This program will read lines of text by the user and print them back with all non-letters (spaces, !, ?, etc) with the underscore character.
*/

int main(int argc, char* argv[])
{
	unsigned char userText[10000];
	printf("Welcome to the UNDERSCORER, the best program to get rid of all those pesky non-letter things. Program by Jacob Weber\n---------------------------\n");//intro
	printf("Please enter a line of text, can include spaces.\n");//query
	fgets(userText,100,stdin); // get input
	
	for(int i=0;userText[i];i++)//increments the imaginary number through each piece of input
	{
		if(userText[i]>= 65 && userText[i] <= 90 || userText[i] >= 97 && userText[i] <= 122)
		//greater than 65, less than 90, greater than 97, less than 122-these are all letters
		// so if it's a letter, leave it alone.
		{
			userText[i] = userText[i];
		
		}
		else
		// if it isn't a letter turn it into an underscore
		{
			userText[i] = '_';
		}
	}
	printf("\n%s\n",userText);// post result


	printf("\nTHANK YOU FOR USING THE underscorer, GLAD YOU LIKED IT.\n\n");//farewell
}
