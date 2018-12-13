#include <stdio.h>
 /*
This program will repeatedly ask the user for two strings as lines of text. The program will report the length of both lines and print them back in lexical order. Then determine if they are substrings or not. The only way to leave the program is to say "please**" for the substring and "quit**" for the comparison string.
 
 
 */

int compareStrings(char [], char []); // gets rid of implicit declaration warning
int subString(char [], char []); // gets rid of implicit declaration warning
int stringLengthOne(char []); // gets rid of implicit declaration warning
int stringLengthTwo(char []); // gets rid of implicit declaration warning
int printLexicallyOne(char []); // gets rid of implicit declaration warning
int printLexicallyTwo(char []); // gets rid of implicit declaration warning
 
int main(int argc, char* argv[])
{
   char stringOne[1000], stringTwo[1000], tmp[1000]; // you use 2 strings in this
   int quit=1,i,j,k;
   while(quit==1) // separates functions from getting strings, which means you quit automatically after saying please** quit**
   {
       int tempOne=0,tempTwo=0;
       printf("-------------------------------------------------------------------------------\nHello. Welcome to Jacob Weber's String Comparer, the best comparer in all comparers, have fun with it. \n\nEnter a substring.\n");
	   fgets(stringOne, 1000, stdin);// get substring
	   printf("Enter a string you wish to compare.\n");
	   fgets(stringTwo, 1000, stdin);// get comparison string
	   
	   for(i=0;stringOne[i];i++)//increments the imaginary number through each piece of input
	   {
	   tempOne = stringOne[i] + tempOne;
	   //printf("temp one%d",tempOne); //debugging;
		   if(tempOne==718) // if user puts please** as the substring
		   {  
			   for(j=0;stringTwo[j];j++)
			   {
			   tempTwo = stringTwo[j] + tempTwo;
			   //printf("temp two%d",tempTwo); // debugging
			       if(tempTwo==535) // if user puts quit** as comparison string
			   	   {
			   	        quit=0; 
			   	   }
			   }
		   }
	   }
	   
	   tempOne=0; //temp one was saving values from earlier?
	   
	   for(k=0;stringOne[k];k++)//search for keywords in substring
	   {
	   tempOne = stringOne[k] + tempOne;
		   if(tempOne==451||tempOne==442||tempOne==696||tempOne==425) // if user puts exit or quit or get out or help as the string
		   {  
		       printf("\nCANT STOP WONT STOP\nYou have to say please** in substring, and quit** in string comparison.\n");
		   }
	   }
	   
	   for(j=0;stringTwo[j];j++)//searches for keywords in comparison string
	   {
	   tempTwo = stringTwo[j] + tempTwo;
		   if(tempTwo==451||tempTwo==442||tempTwo==696||tempTwo==425) // if user puts exit or quit or get out or help as the string
		   {  
		       printf("\nCANT STOP WONT STOP.\nYou have to say please** in substring, and quit** in string comparison.\n");
		   }
	   }

	   while(quit==1)
	   {
		   if(compareStrings(stringOne, stringTwo) == 1) // calls compare string function
		   {
			  printf("\nThe substring comes lexically before the second string.\n\n"); 
		   }
		   if(compareStrings(stringOne, stringTwo) == 0) // calls compare string function
		   {
		   	  printf("\nThe two strings are identical lexically.\n\n");
		   }
		   if(compareStrings(stringOne, stringTwo) == -1) // calls compare string function
		   {
			  printf("\nThe substring comes lexically after the second string.\n\n");
		   }
		   
		   printf("findSubString(): %d!!!!! if 0 then not a substring, if 1 then it is a sub string \n", subString(stringOne, stringTwo));// calls substring and prints 1 is the first string is a substring or 0 if the first string is not a substring of number 2
		   
		   
		   printf("\nThe length of the substring is %d. ",stringLengthOne(stringOne)); // call string length1 function
		   printf("The length of the comparison string is %d\n",stringLengthTwo(stringTwo)); // call string length2 function
		   
		   printLexicallyOne(stringOne);//call print lexically function
		   printLexicallyTwo(stringTwo);//call print lexically function for string 2
		   break;
		}
	}
   
   printf("\nTo be honest I thought we'd never get out. \nThank you for using the string comparer.\n------------------------------------------------------\n");
}
 
 
 
 
 
 
//compare the strings given to each other and confirm whether they're the same or not
int compareStrings(char *stringOne, char *stringTwo) // local stringOne and stringTwo
{
   int count = 0, i, j, asciiSumST=0, asciiSumSO=0;//ST is for string two, SO for string one
 
   for(i=0;stringOne[i];i++)//increments the imaginary number through each piece of input
   {
       for(j=0;stringTwo[j];j++)
       {
			if(stringOne[i]==stringTwo[j] && stringOne[i] != 32 && stringTwo[j] != 32 && stringOne[i] != 255 && stringTwo[j] != 255)
			//greater than 65, less than 90, greater than 97, less than 122-these are all letters
			// so if it's a letter, leave it alone.
			{
				asciiSumSO = asciiSumSO + stringOne[i];
				asciiSumST = asciiSumST + stringTwo[j];
			}
			if(stringOne[i]<stringTwo[j] && stringOne[i] != 32 && stringTwo[j] != 32 && stringOne[i] != 255 && stringTwo[j] != 255)
			// if it isn't a letter turn it into an underscore
			{
				asciiSumSO = asciiSumSO + stringOne[i];
				asciiSumST = asciiSumST + stringTwo[j];
			}
			if(stringOne[i]>stringTwo[j] && stringOne[i] != 32 && stringTwo[j] != 32 && stringOne[i] != 255 && stringTwo[j] != 255)
			{
				asciiSumSO = asciiSumSO + stringOne[i];
				asciiSumST = asciiSumST + stringTwo[j];
			}
		}
	}
	if(asciiSumSO==asciiSumST)
	{
		return 0;
	}
		if(asciiSumSO>asciiSumST)
	{
		return -1;
	}
	if(asciiSumSO<asciiSumST)
	{
		return 1;
	}
}






//find a substring in the string
int subString(char *stringOne, char * stringTwo)
{
	int i, k, foundMatch;

	foundMatch = 0; // example of a "flag" variable...
	for(i=0; stringTwo[i] != 0 && foundMatch==0; i++ ) // think of i as the potential starting position of a match
	{
    	if ( stringTwo[i] == stringOne[0] )
    	{
        	foundMatch = 1;
        	// aha! we have a match of initial letters... now check the rest
        	for(k=1; stringOne[k] != 0; k++) // k is the position in the search we need to check for a match...
        	{
            	if ( stringTwo[i+k] != stringOne[k] )
                	// i+k gives the position in searchLine that should match position k in the searchWord
            	{
                 	foundMatch = 0;
            	}
        	}
    	}  
	}

 

	if (foundMatch==1) 
	{
    	return 1;
	}
	else
	{
    	return 0;
	}
}





int stringLengthOne(char* stringOne)
{
	int check, lengthOne = -1; // starts at -1 because the null terminator gets counted, so that counteracts the null in the counting.
	for(check = 0; stringOne[check]!='\0';check++)
	{
		lengthOne++;
	}
	
	return lengthOne;
	
}

int stringLengthTwo(char* stringTwo)
{
	int check, lengthTwo = -1; // starts at -1 because the null terminator gets counted, so that counteracts the null in the counting.
	
	for(check = 0; stringTwo[check]!='\0';check++)// goes through the strings
	{
		lengthTwo++;
	}
	
	// I don't know how to return two numbers, so I'm printing here.
	return lengthTwo;
	
}




int printLexicallyOne(char* stringOne) // I'm getting a warning, but IDC because it works and I'm tired. 
{
	int i, j;
	char * temp;
	
	for(i=0;i<stringLengthOne(stringOne);i++) // goes through entire string
	{
		for(j=i+1;j<stringLengthOne(stringOne);j++)
		{
			if(stringOne[i] > stringOne[j])// if all previous ascii characters are smaller then set new to first
			{
				temp = stringOne[i];
				stringOne[i] = stringOne[j];
				stringOne[j] = temp;
			}
		}
	}
	
	printf("\nSub string in legixographical order: %s",stringOne); // dunno how to make this a return value
	
}


int printLexicallyTwo(char* stringTwo)
{
	int i, j;
	char * temp;
	
	for(i=0;i<stringLengthTwo(stringTwo);i++)
	{
		for(j=i+1;j<stringLengthTwo(stringTwo);j++)
		{
			if(stringTwo[i] > stringTwo[j])
			{
				temp = stringTwo[i];
				stringTwo[i] = stringTwo[j];
				stringTwo[j] = temp;
			}
		}
	}
	
	printf("\nComparison string in legixographical order: %s",stringTwo);
  
  
 

}
