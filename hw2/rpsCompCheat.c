#include <stdio.h>
#include <stdlib.h> //can use srand and rand functs now
#include <time.h> //lets time() functions feed into srand() functions
/*
Written by Jacob Weber
This program will play rock paper scissors and have the computer cheat by looking at your input
It will have you enter your input, then look at what you used and automatically win
It will do this periodically

*/


int choice; // I need this to be a local variable, because everytime I try to get the return value of choice in getRPSchoice() for my cheating portion of the program it recalls the entire function. So I figure if I set it to global maybe it will work. And it worked. Boom.
// ask for user input and return
int getRPSchoice()
{
	printf("What will it be? Rock (0), Paper(1), or Scissors (2). Enter your number now.");
	fscanf(stdin,"%d",&choice);
	return choice;
}



// randomly choose the computers number
int getComputerChoice()
{
// for the cheating version you can do a for loop, and make it so every third game you automatically win as the computer, but have a chance at any other time. JK too complicated. randomly generate a number (1,2,3) when called on, if one then auto win, if not then randomly pick
int maybeAutoWin;
int computerChoice; //this choice is different from getChoice and main choice, it's a local var
maybeAutoWin = rand() % 3;
	if(maybeAutoWin==1) // when func gets called it randomly generates a number, if it's 1 the computer will automatically win, otherwise it will randomly choose
	{
		if(choice==0)// if user chooses rock, comp chooses paper
		{
			computerChoice = 1;
		}
		if(choice==1)// if user chooses paper, comp chooses scissors
		{
			computerChoice = 2;
		}
		if(choice==2)// if user chooses scissors, comp chooses rock
		{
			computerChoice = 0;
		}
	}	
	else
	{
		computerChoice = rand() % 3; // creates a RNG for 0-2
	}
	return computerChoice;
}




//functon to determine winner, 0 for tie, 1 for user, 2 for comp
int whoWins(int userMove, int compMove)
{
	int winner;
		/*
		I tried to use your version for this part, but there was something off with it. I'd use
		scissors and the computer would pick rock and I would win? Or something like that.
		I looked up the syntax for multiple parameters, and I think this was much easier
		and it's much easier to read.
		
		*/
	if (userMove == 0 && compMove == 0 || userMove == 1 && compMove == 1 || userMove == 2 && compMove == 2)
    {
        winner=0;
	}
 
    else if (userMove == 0 && compMove == 1 || userMove == 1 && compMove == 2 || userMove == 2 && compMove == 0)
    { 
        winner = 2;
 	}
 
    else if (userMove == 2 && compMove == 1 || userMove == 1 && compMove == 0 || userMove == 0 && compMove == 2)
    { 
        winner = 1;
	}
	
	else
	{
	printf("\n\n********ERROR********** GET OUTTA HERE\n\n");
	exit(2);
	}
	return winner;
}
	


void printRPS(int rpsNum)
{
	//print the word rock paper or scissor
	if(rpsNum==0)
	{
		printf("Rock ");
	}
	else if(rpsNum==1)
	{
		printf("Paper ");
	}
	else if(rpsNum==2)
	{
		printf("Scissors ");
	}
	else // if only given trash then exit and error them out
	{
		printf("\n\n******ERROR******* YOU GAVE ME GARBAGE GET OUTTA HERE PUNK.");
		exit(1);
	}

}


void printWinLoseDraw(int wldNum)
{
	if(wldNum==2)
	{
		printf("\n\nComputer Wins!\n\n");
	}
	else if(wldNum==0)
	{
		printf("\n\nIt's a draw\n\n");
	}
	else if(wldNum==1)
	{
		printf("\n\nUser Wins!\n\n");
	}
	else // bullet proofing
	{
		printf("*********ERROR****** YOU GAVE ME GARBAGE GET OUTTA HERE PUNK.");
	}
}


int main(int argc, char* argv[])
{
	srand(time(NULL)); //seeding the rng
	int choice, cChoice, result, playerScore, compScore; //this choice is different, cuz local var
	unsigned char answer = 'y';//unsigned char is an integer from 0-255, we use these as ascii code for characters
	printf("\nThis is Jacob Weber's RPS game\n----------------------------\n");
	playerScore = 0;
	compScore=0;
	while(answer == 'y' || answer == 'y') // if you want literal character values put symbol inside single quotes, don't use double quotes. technically y is a number, because it's a code for ascii. you can use the ascii code andit will do the same thing
	{
		choice = getRPSchoice();
		printf("\nYour choice was: ");
		printRPS(choice);
		cChoice=getComputerChoice();
		printf("\nComputer chooses: ");
		printRPS(cChoice);
		//determinte winner
		result = whoWins(choice, cChoice);
		// printf("\nResult: %d\n,result);
		printWinLoseDraw(result);
		//this is dependent on who won
		if(result==2)
		{
			compScore++;//increments compScore
		}
		else if(result==1)
		{
			playerScore++;
		}
		printf("\nSCORE: You %d : Computer: %d\n",playerScore,compScore);
		printf("play Again? (y or n): ");
		scanf(" %c", &answer); //space in scanf format skips all invis characters
		printf("\n\nDEBUG: %u\n\n",answer);
	}
	printf("\nThank you for using Jacob's Rock Paper Scissors Game\n---------------------\n");
}
