#include <stdio.h> 
#include <stdlib.h> 
/*
I have no idea how to use fopen, or any of this. I found out how to open file and output data
but not idea how to calculate winpercentage and only print the highest last. So this is 
the garbage I'm turning in. All it does is open and read the contents of a file.
No idea how to combine that with the things with did in class.


*/
  
  
  int calcWinPercent(int numWins, int numLosses) // calcs and returns a % to main
{
	int winP, high; // defining a local variable (only a variable for calcWinPercent)
	winP = numWins*100 / (numWins + numLosses);
	if(winP > high)
	{
		high = winP;
	}
	return high;
}
  
int main() 
{ 
	int high, wins, losses, x, wl;
    FILE *fptr; 

  
    char filename[100], c; // creates a string for file name
  
    printf("WELCOME TO THE JACOB'S WIN PERCENTAGE CALCUALTOR. Enter the filename to open \n"); 
    scanf("%s", filename); // takes file name and inputs it into filepointer
  
    // Open file 
    fptr = fopen(filename, "r"); // file pointer
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    c = fgetc(fptr); 
    while (c != EOF) // checks for end of file
    { 
        printf ("%c", c); // prints output of the etnire file
        c = fgetc(fptr); 

    } 
    
  
    fclose(fptr); // closes the file
    return 0; 
   

}





