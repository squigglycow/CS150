#include <stdio.h>

// program to add up numbers the user enters on the command line
// ex ./addemup 5 77 99



void main(int argc, char* argv[])
{
	int total; // defines variable to store the total
	int lineNumber, x, limit, max;
	total = 0; 
	lineNumber = 0;
	max = 0;


	/* to use a file in your program you need a file pointer variable to track file
	to delcare a file this way: "FILE*"*/
	FILE* dataFile;
	
	/* you must open the file before you use it, file pointer file tracks it
	example     variable = fopen("filename.type","mode"); */
	dataFile = fopen(argv[1],"r");
	
	printf("This program will add up numbers. Please enter how many numbers you are going to enter now: \n");
	fscanf(stdin,"%d",&limit);
	 // printf askes for how many numbers, fscanf reads the input, stores as limit
	
	if(dataFile != NULL )
		{
		while(lineNumber < limit) //(!feof(dataFile)) and (feof(dataFile)==0) mean same thing
		{
		
				if(feof(stdin)==0)
				{					
					fscanf(stdin,"%d", &x);
					total = total + x;
					printf("\nadding %d currently %d\n",x, total);
					lineNumber = lineNumber + 1; //increment 
						if(x > max)
							{
							max = x;
							}

				}
		}
		printf("==========================\nFinal: %d, and max: %d \n",total, max);
		fclose(dataFile);
		}
	else
	{
	printf("%s does not exist",argv[1]);
	}
}	

// control d to exit program





