#include <stdio.h>
/*
This program will take any amount of numbers, and sort them from smallest to greatest.

*/
void sort_numbers_ascending(int number[], int count)
{
   int temp, amount, big, small;
   
   //basically this takes the first number and second number, compares them and then sets them to a position, then it does the first and third, and the second and third, then it does the first and fourth and then fourth and second and then fourth and fifth and so on until it sorts all of the numbers entered.
   for (big = 0; big < count; ++big) // goes through each number
   {
      for (small = big + 1; small < count; ++small) //
      {
         if (number[big] > number[small]) // if the bigger / new number is larger than the previous it will set that new number as the biggest, otherwise it will set it as the second largest and so on
         {
            temp = number[big]; 
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

void main()
{
   int amount, count, number[20];
 
   printf("Welcome to Jacob's Number Sorter.\n"); //hello
   printf("How many numbers you are gonna enter:\n"); //prompt for input
   fscanf(stdin, "%d", &count); // stores input, this will limit how many times sort_numbers_ascending will run
   printf("\nEnter the numbers one by one:\n");
   
   for (amount = 0; amount < count; ++amount) // this will go through each number
   {
      fscanf(stdin, "%d", &number[amount]); // this will store all numbers in amount, which then will be sorted
   }
 
   sort_numbers_ascending(number, count);// this will print the nnumbers in ascending order
   
   printf("Thanks for using Jacob's Number Sorter.\n"); // farewell
}

