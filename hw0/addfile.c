#include <stdio.h>

// program to add up numbers the user enters on the command line
// ex ./addemup 5 77 99



void main(int argc, char* argv[])
{
	int total; // defines variable to store the total
	int lineNumber, x;
	total = 0; // initialize
	// use return value of feof() function to be true/false whether the end of file is there
	lineNumber = 1;

	/* to use a file in your program you need a file pointer variable to track file
	to delcare a file this way: "FILE*"*/
	FILE* dataFile;
	
	/* you must open the file before you use it, file pointer file tracks it
	example     variable = fopen("filename.type","mode"); */
	dataFile = fopen(argv[1],"r");
	if(dataFile != NULL )
		{
		
		
		//repeat for each number in the list, add that number to total
		fscanf(dataFile,"%d", &x);
		while(!feof(dataFile)) //(!feof(dataFile)) and (feof(dataFile)==0) mean same thing
		{
			//won't get #s from comprompt, getting from file sscanf(argv[argIndex],"%d",&x);
			//fscanf with filepointer, format string, and &variable to read from file

				/*original if statement
			fscanf(dataFile,"%d", &x);
				if(feof(dataFile)==0)
				{
					total = total + x;
					printf("\nadding %d currently %d\n",x, total);
					lineNumber = lineNumber + 1; //increment 
				}*/
				if(feof(dataFile)==0)
				{
					total = total + x;
					printf("\nadding %d currently %d\n",x, total);
					lineNumber = lineNumber + 1; //increment 
					fscanf(dataFile,"%d", &x);
				}
		}
		printf("==========================\nFinal: %d\n",total);
		fclose(dataFile);
		}
	else
	{
	printf("%s does not exist",argv[1]);
	}
}	





