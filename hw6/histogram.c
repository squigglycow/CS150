#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
This program is a histogramer. It will take command line arguments such as the file argv[1], min bin argv[2], bin size argv[3] (the increment of the bins), and the number of bins argv[4]. Then it will plot a fashionable histogram with the bin range, the amount of values in the bin range, with asterisks to depicts the amount of values in said bin.

*/


int printStars(float x) 											//prints asterisks equal to value passed
{
	printf("               ");
	while(x>=0.5)
	{
		printf("*");
		x--;
		
	}


}


int plotHistogram(char * dataFile, float binMin, float binRange, int binAmount)
{
	int i, count=0, numberOfValues, binNumber=1, countValue[1000];
	float dataValue, binMax, newBinMin;
	
	/* testing 
	printf("bin min%f\n",binMin);
	printf("bin range%f\n",binRange);
	printf("how many bin%d\n",binAmount);*/
	printf("\n-------Historgram------\n\n\nBin              	 Count\n"); 	  // break
	
	FILE* filePointer = fopen(dataFile,"r");							  //open the file for reading and save filepointer of file

	if(filePointer == 0)												  //bullet proofing
	{
		printf("file not found 403 error\n");
		exit(0);
	}
	else 																  // if we get here then it has opened the file
	{	
		for(i=0;i<binAmount;i++)
		{
			FILE* filePointer = fopen(dataFile,"r");							  //open the file for reading and save filepointer of file
			binMax = binMin + binRange*binNumber;							// creates max bin number
			newBinMin = binMin + binRange*binNumber-binRange; 						//creates new bin min
			printf("\n[%.2f - %.2f]", newBinMin, binMax);
			while(!feof(filePointer))
			{
				fscanf(filePointer, "%f", &dataValue);						// read the number
				if(dataValue>=newBinMin && dataValue<=binMax)
				{
					numberOfValues++;
					//printf("%.2f ",dataValue);

				}			
			}
			binNumber++;
			printf("			%d", numberOfValues);
			printStars(numberOfValues);
			numberOfValues = 0;
			fclose(filePointer);
				
		}
	}
	
	
	printf("\n\n--------------------------\n");						 		 //break
	fclose(filePointer);													 //close file
}









int main(int argc, char * argv[])
{
	int i, binAmount, count; 
	float binMin, binRange;
	printf("Welcome to Jacob Weber's Historgramer, which will plot your specified bins based on a file full of numbers that you supply.\n"); 																									//greeting
	
	printf("\n*****If you have not entered the file, then the bin min, then the bin range, and then the amount of bins you want to count then the program will not work properly. Please re-enter your information if you did not.*****\n"); 
	// file, binMin, binRange, binAmount-file name, the first bin, the bin range, and how many bins you want to count
	
	sscanf(argv[2],"%f",&binMin);
	sscanf(argv[3],"%f",&binRange);
	sscanf(argv[4],"%d",&binAmount);
	

	
	count = plotHistogram(argv[1],binMin,binRange,binAmount);
	
	for(i=0;i<count;i++)
	{
		printStars(binAmount);
	
	}
	
	

	printf("\nThank you for using the Histogramer.\n");													 //farewell
}
