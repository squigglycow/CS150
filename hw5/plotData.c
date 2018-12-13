#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
write a function that takes a float point number parameter, x
prints a number of '*' on a line equal to rounded up/down
if x is 8.3 then it would print ********
if it was 8.8 then it would print *********




NOTES:
while programming I tried to create a plotData function, but found it really difficult to program.
I tried to jusy copy paste the code from earlier and put in numDays and dailyTemps for the parameters, but that didn't work


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


int readData(char* dataFile, float* data, int maxSize)
{
	int count;
	float dataValue;
	
	//open the file for reading and save filepointer of file
	FILE* filePointer = fopen(dataFile,"r");
	//optional bulletproofing -  make sure file was successfully opened
	
	
	
	//bullet proofing
	if(filePointer == 0)
	{
		printf("file not found 403 error\n");
		exit(0);
	}
	else
	{
		//read the file, soring numbers in data array
		count=0;
		fscanf(filePointer, "%f", &dataValue); // attempt to read first number
		while(count<maxSize && !feof(filePointer))
		{
			//if were get here, then we've read a number, so store it in array
			data[count] = dataValue;
			fscanf(filePointer, "%f", &dataValue);
			count++; // increment count
		
		}
	}
	
	//close file
	fclose(filePointer);
	
	//return count
	return count;
}





int main(int argc, char* argv[])
{
	/*printf("-------------\n");
	printStars(2.1);
	printf("-------------\n");
	printStars(30);
	printf("-------------\n");
	printStars(3.3);
	printf("-------------\n");
	printStars(5);
	printf("-------------\n");
	printStars(9.8);
	printf("-------------\n");
	printStars(0.0); 
	this was for earlier tests*/
	
	
	
	float dailyTemps[1000];
	int i, numDays, maxNumDays = 1000; // declare variables
	
	printf("Hello, WELCOME TO JACOB'S PLOT DATA thingamajig, it will plot and label your data. Enter a file in the command line.\n-----------------------------------------------------------\n\n"); // introduction
	
	numDays = readData(argv[1], dailyTemps, maxNumDays);
	

	// print out list of temps before graphing the data
	for(i=0;i<numDays;i++)
	{
		printf("Day: %d Temp: %10.2f\n", i, dailyTemps[i]);
		
	}
	
	printf("\n"); // separating list of temps and graphing
	
	//"graph the data with printstars
	for(i=0;i<numDays;i++)
	{
		printStars(dailyTemps[i]);
	
	}
	
	printf("\n--------------------------------------------------\nThanks for plotting some data, have a day.\n"); //farewell

}
