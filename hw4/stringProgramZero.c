#include <stdio.h>
 /*
 This program will compare strings, find substrings in strings, state the length of a string.
 
 
 */

int compareStrings(char [], char []); // gets rid of implicit declaration warning
int subString(char [], char []); // gets rid of implicit declaration warning
int stringLength(char [], char []); // gets rid of implicit declaration warning
 
int main(int argc, char* argv[])
{
   char stringOne[1000], stringTwo[1000], tmp[1000]; // you use 2 strings in this
 
   printf("Hello. Welcome to Jacob Weber's String Comparer, the best comparer in all comparers, have fun with it. \n\nEnter a substring OR enter a string that you want to compare\n");
	scanf("%s",stringOne); 
	fgets(tmp,1001,stdin); // fgets to flush out anything remaining on the input line

 
   printf("Enter a string for a sub string OR enter a string that you want to compare\n");
   fgets(stringTwo, 1000, stdin);// get comparison string

 
   if (compareStrings(stringOne, stringTwo) == 1) // calls compare string function
   {
      printf("\nEqual strings. String one \n%sis equal to string two \n%s\n",stringOne, stringTwo); // states whether or not equal and says goodbye
   }
   else
   {
      printf("\nUnequal strings. String one \n%sis NOT equal to string two \n%s\n",stringOne, stringTwo);
   }
   
   printf("findSubString(): %d\n", subString(stringOne, stringTwo));// calls substring and prints 1 is the first string is a substring or 0 if the first string is not a substring of number 2
   
   
   stringLength(stringOne, stringTwo); // call string length function
   
   
   printf("\nThank you for using the string comparer.\n");
   


}
 
 
 
 
 
 
//compare the strings given to each other and confirm whether they're the same or not
int compareStrings(char *stringOne, char *stringTwo) // local stringOne and stringTwo
{
   int count = 0;
 
   while (stringOne[count] == stringTwo[count]) 
   {
      if (stringOne[count] == '\0' || stringTwo[count] == '\0')
      {
         break; //break loop if string two and string one aren't equal
      }
      count++;// if there's nothing left then go to the else, and return 0
   }
   
   if (stringOne[count] == '\0' && stringTwo[count] == '\0')
   {
      return 1;
   }
   else
   {   
      return 0;
   }
}






//find a substring in the string
int subString(char *stringOne, char * stringTwo)
{
	int check=0,balance=0,temp=0;
	while(stringTwo[check]!='\0') // when not 0
    {
        if(stringTwo[check]!=stringOne[balance]) // if they aren't equal then bump up check
        {
            check++;
        }
        else if(stringTwo[check]==stringOne[balance])// if string2 cheak and string1 balance equal then
        {
            while(stringOne[balance]!='\0')// if balance isn't 0 then
            {
                if(stringTwo[check]==stringOne[balance]) //if string2 check and string1 bal equal bump everything
                {
                    check++;
                    balance++;
                    temp++;
                }
                else
                {
                    temp=0;
                    break;
                }
            }
        }
     }
     if(temp!=0)
     {
		return 1;
     }
     else
     {
		return 0;
	 }
}

int stringLength(char* stringOne, char* stringTwo)
{
	int check, lengthOne = -1, lengthTwo = -1; // starts at -1 because the null terminator gets counted, so that counteracts the null in the counting.
	for(check = 0; stringOne[check]!='\0';check++)
	{
		lengthOne++;
	}
	
	for(check = 0; stringTwo[check]!='\0';check++)// goes through the strings
	{
		lengthTwo++;
	}
	
	// I don't know how to return two numbers, so I'm printing here.
	printf("Length of string one %d, length of string two %d\n",lengthOne, lengthTwo);
	

}

