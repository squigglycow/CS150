#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
This program is dice generator, it will generate dice based on user input then create a file that you assign it. Then you can use that file for other programs where numbers are generated in a range. It's useful!

input should be: programname, file name, size of dice(d6,d20,etc), number of dice per roll, number of rolls-file name

*/


int main(int argc, char * argv[])
{
	int i, count, dieSize, dicePerRoll, numberOfRolls, result, die=0, r, total, counter;					//initialize vars
	srand(time(NULL));																						//init time
	sscanf(argv[2],"%d",&dieSize);
	sscanf(argv[3],"%d",&dicePerRoll);
	sscanf(argv[4],"%d",&numberOfRolls);
	
	printf("Welcome to Jacob Weber's Dice Roller, which iwll roll dice based on what your command line arguments are. Then it will throw those dice rolls into a new file, which you then use in histogramer.\n");     				    //greeting
	
	printf("\n\nYou have created the file %s\n\n",argv[1]);												//testing

	
	printf("\n*****Your new file is in proc/11385/cwd after running this, or just search for the file name that you entered in the command line.*****\n"); 

	
	FILE* filePointer = fopen(argv[1],"w");						  //open the file for writing and save filepointer of file
	
	
	// for the number of rolls roll for x many dice that are size x, print each roll of the dice total
	for(int i=0; i <= numberOfRolls; i++)
	{
		while(counter < dicePerRoll)
		{
			r=rand();
			die = 1+(r % dieSize);
			r=0;
			result=die;
			total=total+result;
			result=0;
			die=0;
			counter++;
		}
		fprintf(filePointer, "%d\n", total);											//this writes the number to the file
		total=0;
		counter=0;

	}
	printf("\ndie size %d dice per roll %d number of rolls %d\n",dieSize, dicePerRoll, numberOfRolls);																		// spits back what you entered for the dice
	
	fclose(filePointer);																					 //close file
	printf("\nThank you for using the DICER, which creates documents of dice rolls after rolling dice.\n");  //farewell
}
