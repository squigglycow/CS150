#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*
create a variation of the plotData program, where it uses the sin() function from math.h
to fill data into the ata array and plot that data
for decent credit make it so it graphs positive numbers and give a min and max value for x and then the umber of data values
for max/extra do that negative values too

*/

int printStars(float x)
{
	while(x>=0.5)
	{
		printf("*");
		x--;
		
	}
	printf("\n");

}


int main(int argc, char* argv[])
{
	int a,c,d, x[10000], q, i, answer; // gives a sin of 50
	float b;

	printf("Hello, WELCOME TO JACOB'S PLOT sine DATA thingamajig, it will plot and label your data. Enter a file in the command line.\n-----------------------------------------------------------\n\n"); // introduction	
	
	printf("\nThe program requires that you put in the variables: a, b, c, d, and x[max]. Please enter here: \n");
	
	
	fscanf(stdin, "%d", &a); printf("\na is %d", a); // each of these is double sided, reads the input then tells user that it was set correctly.
	fscanf(stdin, "%f", &b);printf("\nb is %f", b);
	fscanf(stdin, "%d", &c);printf("\nc is %d", c);
	fscanf(stdin, "%d", &d);printf("\nd is %d", d);
	fscanf(stdin, "%d", &q);printf("\nq is %d\n", q); // q is the quit/max point
	
	
	

	for(i=q;i<answer;i++) // assign x the array number, then print the number of asterisks assigned to x
	{
		x[i]=i;
		answer = (a*sin(b*i+c)+d);
		printStars(x[i]);
		//printf("%d",x[i]); // seeing if it does go up to sin 50-testing. goes to 49 + beginning[0], so there is 50
	}
	
	for(i=q;i>answer;i--)
	{
		x[i]=i;
		answer = (a*sin(b*i+c)+d);
		printStars(x[i]);
		//printf("%d",x[i]); // seeing if it does go up to sin 50-testing. goes to 49 + beginning[0], so there is 50
	}

	printf("\n--------------------------------------------------\nThanks for plotting some data, have a day.\n"); //farewell      */

	
}
