#include <stdio.h>
/*
Welcome to Jacob's Temperature Converter where we take C and turn it in F, like magic. But not
magic. Here we use math.

*/

//This function will convert F to C using user input and an equation
int f2c()
{
	float Fahrenheit, Celsius;
	Celsius = 0;
	Fahrenheit = 0;
	printf("\nHow hot or cold is it in Fahrenheit? Enter your number here: ");
	scanf("%f", &Fahrenheit);
	Celsius = (Fahrenheit - 32)*0.555;
	printf("%f Fahrenheit is converted to approximately %f Celsius.\n", Fahrenheit, Celsius);
	return Celsius;
}




//This func will convert C to F using user input and an equation
int c2f()
{
	float Fahrenheit, Celsius;
	Celsius = 0;
	Fahrenheit = 0;
	printf("\nHow hot or cold is it in Celsius? Enter your number here: ");
	scanf("%f", &Celsius);
	Fahrenheit = Celsius * 1.8 + 32;
	printf("%f Celsius is converted to approximately %f Fahrenheit.\n", Celsius, Fahrenheit);
	return Fahrenheit;
}



void askType() // just dialogue I didn't feel like copa pastaing, JK didn't need to copa pasta
{
	printf("\nPlease enter whether you would like to convert from F to C by typing 1, or whether you would like to convert from C to F by typing 2. F is Fahrenheit and C is Celsius. F to C (1), C to F (2)\n\n");
}


int main(int argc, char* argv[])
{
	int choice;
	unsigned char answer = 'y';//unsigned char is an integer from 0-255, we use these as ascii code for characters
	printf("\nHELLO TO JACOB'S MAGICAL TEMPERATURE CONVERTER, HAVE A BLAST WOULD YOU?\n");

	while(answer == 'y' || answer == 'y') // if you want literal character values put symbol inside single quotes, don't use double quotes. technically y is a number, because it's a code for ascii. you can use the ascii code andit will do the same thing. Can do as many types as you want.
	{
		askType();
		scanf("%d",&choice);
		if(choice==1)
		{
			f2c();
		}
		else if(choice==2)
		{
			c2f();
		}
		else
		{
			printf("\n***************ERROR*******************\n");
		}
	printf("\nWould you like to enter another conversion? (y or n): ");
	scanf(" %c", &answer); //space in scanf format skips all invis characters
	}

	printf("\nTHANKS FOR USING THE PROGRAM!!!!!\n-------------------------------------\n\n");
}

