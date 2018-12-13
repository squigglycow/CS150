#include <stdio.h>
/*
This program will take any amount of numbers, and sort them from smallest to greatest.

*/
int sortNumbersAscending(int number[], int count)
{
   int temp, amount, big, small;
   for (big = 0; big < count; ++big) // goes through each number
   {
      for (small = big + 1; small < count; ++small) //
      {
         if (number[big] > number[small])
         {
            temp = number[big]; // sets temp number (the largest) to big
            number[big] = number[small];
            number[small] = temp;
         }
      }
   }
   printf("\nNumbers from smallest to greatest:\n");
   for (amount = 0; amount < count; ++amount) // this will count how many numbers there are
      {
      printf("%d\n", number[amount]); // this will print the numbers
	  }
}

int main()
{
   int amount, count, number[20];
 
   printf("Welcome to Jacob's Number Sorter.\n"); //hello
   printf("How many numbers you are gonna enter:\n"); //prompt for input
   fscanf(stdin, "%d", &count); // stores input
   printf("\nEnter the numbers one by one:\n");
   
   for (amount = 0; amount < count; ++amount) // this will go through each number
   {
      fscanf(stdin, "%d", &number[amount]); // this sill sort the numbers
   }
 
   sortNumbersAscending(number, count);// this will print the nnumbers in ascending order
   
   printf("Thanks for using Jacob's Number Sorter.\n"); // farewell
}

