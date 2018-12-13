#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
This program will run through a morally compromising role playing game, where you will have to make choices based on a situation. It doesn't have anything to morals, it's ust a RPG.

The program will tally up your actions: good, neutral, bad, and the actions you take will decide the ending you get.

*/

int good, bad, neutral, crew=8, money=0; 									 
//Global variables for simplicity sake. I know they're bad, but I don't feel like passing half a dozen variables on every function incase I decide I want to use them later. They're bad because in actual code that is used for servers and other things they don't stick, that's why they're bad.



int printStars(float x) 											//prints asterisks equal to value passed
{
	printf("   ");
	while(x>=0.5)
	{
		printf("*");
		x--;
		
	}
}




int endGame()
{
	printf("\n\nThe results of this game are:\nGood points: %d \nBad points: %d \nNeutral points: %d \nMoney left: %d\nCrew left: %d\n", good, bad, neutral, money, crew); 			 // troubleshooting/counting to ensure the program is following script -- create a function for this, where it tells you you're stats and how good/bad you did
	money = money / 100;
	printf("\nRepresentation of points:\nG:");printStars(good);
	printf("\nB:");printStars(bad);
	printf("\nN:");printStars(neutral);
	printf("\nM:");printStars(money);
	printf(" (ast for money represents 100s)\nC:");printStars(crew);printf("\n");
	
	if(good>=3 || money>899)
	{
		printf("\nThis was a strong win.\n");
	}
	if(neutral>=3 || bad<=6)
	{
		printf("\nThis was a normal win.\n");
	}
	else
	{
		printf("\nThis was a weak win.\n");
	}
}

void quitProgram()
{
	endGame();
	exit(1);
}


int crewSize()
{
	if(crew<4)
	{
		printf("\nYou've lost an engineer, a pilot, your thug, and your explosive guy. Your remaining crew has told you to land on the closest planet so they can get away from you, because you're awful at this whole pirate thing. You lose.\n");
		quitProgram();
	}
}


// bunch of roleplay which determines where you're going. it's the illusion of choice, you either have neutral where you go where you end up regardless, bad where you do something outside parameters, or good where you read the text and enter the good location. this may have consequences later
int decisionOnePirates()
{
	int goodDecision = 0, badDecision = 0, neutralDecision = 0, noDecision=0; // each function will have this
	char pirateString[1000];
	char Mastrami[]="Mastrami"; 											  //neutral
	char mastrami[]="mastrami";											  	  //neutral
	char goodOne[]="9 Caliber",goodTwo[]="safe harbor";						  //good strings

	printf("\nPlease type where you want to go:\n\n");
	fgets(pirateString, 1000, stdin);										  // get user input
	pirateString[strcspn(pirateString, "\r\n")] = 0;						  //strcspn is a buffer, gbye newline from fgets
	
	
	// all the choices pigeon hole you in to going to Mastrami, it's just whether they're "good", "bad", or "neutral" decision.
	if(strstr(pirateString,Mastrami) != NULL || strstr(pirateString,mastrami)) // neutral decision
	{
		neutralDecision++;
		noDecision=10;
		printf("Mastrami it is! A few hours of light speed later you arrive, exhausted from the series of events that led you here. You land safely and find a place to refuel and retire. The refueling takes most of your money, and you have debts to pay. You should look for an opportunity soon, or you will have more than Guild bounty hunters and the Guards after you.\n\nYou land on Mastrami safely.");

	}
	if(strstr(pirateString,goodOne) != NULL || strstr(pirateString,goodTwo) != NULL ) // good decision
	{
		goodDecision++;
		noDecision=10;
		printf("To headquarters?... To the Star Admiral it is.\n\nWhen you arrive, or are told that you have arrived, you are puzzled as you stare out from your console, after all there was nothing but the expanse of the void. Then the void rippled, like an electrical storm in front of you, and you can't help but feel astonished. The ripple continues in the shape of a sphere and spreads outwards like a pulse wave. A planet is before you, most of it is covered in ice except for the poles of planet, which are green and resplendent. It reminds you of home.\n\nA belt of machinery and satellites circle the planet. It looks impressive, you say this to your pilot, Jimmy, who now owes you two-hundred credits. You hope he pays soon, you have debts to pay too. Too soon, to be honest. You should get that sorted out soon.\n\nA transmission comes to your attention and you accept it. After a brief conversation with an insectoid, you find out you are being provisioned with fuel and supples: weapons for your crew and ship; food, EVAC suits, and more.\n\nYou are given this aid on the condition that when called in the future you will help to the best of your ability in return you will continue getting aid.\nAfter replenishing your ship and resting for a day, you are approached by a moon-sized battle ship. You receive a transmission from them, which bypasses the request somehow. A sludge-beast with furry arms and a dozen eyes introduces itself as The Admiral. He thanks you for your service, and tells you to go to Mastrami and await for further instructions. Then he cuts transmission and the ship enters light speed.\n\nYou don't like Mr. Admiral Sludge Beast you decide. Then tell Johnny or Jimmy, whatever your pilot's name is, to head to Mastrami. Y\n\nYou land on Mastrami safely.\n\n");
	}
	
	if(noDecision==0) 												// no decision or unknown decision = bad decision
	{ 
		badDecision++;
		bad = bad + 3;
		crew --;
		printf("\nI am an AI, I do not recognize that place. You may try to go there... it won't go well. Goodbye.\n\nYour attempts to go to '%s' do not go well. You are set upon by another crew of space pirates. They deal quite a bit of damage to your newly acquired ship, and Jimmy, your pilot is sucked out into vacuum during the fight. He owed you a hundred and fifty, and you have debts to pay. You have no choice but to flee to Mastrami at this point; for repairs, fuel, and some much needed rest. Some of your crew is beginning to think this was a bad idea...\n\nYou land on Mastrami intact later that day. After the mess earlier, you definitely would not call that a safe travel.",pirateString);
	}
	
	if(goodDecision>badDecision && goodDecision>neutralDecision) 
																	// most functions will have this, this controls the counters for the finale. not sure if I will come back to this decision and make it have more consequences. we'll see.
	{
		good++;
		return 1;
	}
	if(badDecision>goodDecision && badDecision>neutralDecision)
	{
		bad++;
		return -1;
	}
	if(neutralDecision>goodDecision && neutralDecision>badDecision)
	{
		neutral++;
		return 0;
	}
}







int game(char [], char [], int gameNumber, int numOfGames); 								// get an implicit declaration without this

//it generates a word for hangman and triggers the function for checking for your input
int hangman(int gameNumber,int numOfGames)
{
	int randWord; 												
	srand(time(NULL));																						//init time
	char guessed[20];
	
	randWord = rand();
	randWord = 1+(randWord % 6);
	
	if(randWord==6)
	{
    	char wordFive[] = "spicy";
        game(wordFive,guessed,gameNumber,numOfGames); 
    }
	if(randWord==1)
	{
    	char wordOne[] = "duck";
        game(wordOne,guessed,gameNumber,numOfGames); 
    }
    if(randWord==2)
	{
    	char wordTwo[] = "orange";
    	game(wordTwo,guessed,gameNumber,numOfGames); 
    }
    if(randWord==3)
	{
    	char wordThree[] = "money";
        game(wordThree,guessed,gameNumber,numOfGames); 
    }
    if(randWord==4)
	{
    	char wordFour[] = "ship";
        game(wordFour,guessed,gameNumber,numOfGames); 
    }
    if(randWord==5)
	{
    	char wordFive[] = "space";
        game(wordFive,guessed,gameNumber,numOfGames); 
    }
     
} 




// this is the function for the actual hangman game, it runs through the word with your letter which you insert when prompted. if found then it adds a counter to the correct, when you have the counter for corrent equal to the length of the word you get money.
int game(char word[], char guess[], int gameNumber, int numOfGames)
{
    char letter;
    int gameResult=0, correct=0, len, x=0, notFound; 

	printf("\n\nWELCOME TO EXTREME HANGMAN, EACH GAME IS ONE HUNDRED MONIES. GUESS THE WORD FOR THE FULL MONIES, THREE-QUARTERS FOR HALF, IF YOU CAN'T DO THAT YOU LOSE! Buy in is 10 monies. Each game of hangman is a single word, with no duplicate letters-words are chosen randomly. You are on game %d and you need to play %d games to completion.\n", gameNumber+1,numOfGames);

	len = strlen(word);
	     
    while (x<6) 
    {
    	while(x<6) 														   // extra bulletproof, for some reason it wasn't ending the loop on successful word guesses
		{
		printf("\nPlease say a letter for the puzzle.\n");
	    scanf(" %c",&letter);
	   	notFound=0; 													   //resets the counter each round
			for(int i=0;i<len;i++)
			{
				if(letter == word[i])
				{
				    printf("You got that letter right. The letter was %c. You have guessed %d of %d letters right.\n",letter, correct+1, len);
				    correct++; 												
				    word[i] = 7;
				}
				else
				{
					notFound++;
					//printf("notFound%d",notFound); //testing
					if(notFound==len) 										//increments if wrong
					{
						++x;
				    	printf("\nYou said %c. Wrong letter. You have %d attempts left\n",letter, 6-x);
					}
					if(x==6) 												//after all attempts spent, it tells user the word
					{
						printf("\nYou did not find the word. It was %s.\n",word);
						money = money -25;									// you also lose monies
						neutral--;											//losing affects end score
					}
				}
		    }     
		    if(correct==len) 												//if guesses are correct and equal to the length of the word, then you win a game of hangman
		    {
		    	x=10;
		    	money = money + 100; 										//you won, this means you got money yay
		    	printf("\nYou guessed the word right, it was: %s\n", word);
		    	break;
		    }
        }
    } 
}






// roleplay and generates 5 games of the hangman game, which in return will cause consequences dependent on how many times you win/lose because you need money. the amount of money results in a good consequence (if you win more than 500 monies. if less than 200 then bad, otherwise neutral.
int debt(int choiceOne)
{	
	int gameNumber, numOfGames;
	if(choiceOne==-1) 															// you killed your pilot by your poor choices and now you're stealing his credits
	{
		printf("\nYou decided to go through Jimmy's things earlier, and found a negative tab for the Crowned Goose, it seems he was a frequent visitor and must have been good for something other than flying. When you get to the Crowned Goose you go to the bar and ask the tender about, he askes if you're with James or whatever. You say yes, he pulls out a hundred monies and tells you to give it to Jimmy. How trusting. Now you're earning money: %d. You scurry away to go play your game.\n", money);
		money = money + 100; 
	}
	if(choiceOne==1) 															// you went to safe harbor
	{
		printf("\nYou were able to save some money on fuel because it was restocked by Sludge Admiral. You have %d.\n", money);
		money = money + 50; 
	}
	
	printf("\nSo, you've landed on Mastrami. You're in debt to some rather questionable fellahs who require constant tracking and communication to ensure their debt is paid. And it's coming in due soon. You're thinking to yourself, Mastrami is a questionable place, with a lot of questionable things. Like gambling. Now that might have gotten you into this situation, but it can get you out. You tell your crew that you're going out to do captain-yy things and the %d crew members are say they're going out too.\nSo you walk through the crowded streets of the capital, passing all sorts of things and people and peoplethings, when you spot it. The Crowned Goose. It looks reputable. You go in.\nYou sit down for a game of high-stakes Hang Man.", crew);
	printf("\nPlease enter how many games of Hang Man you want to play (I recommend at least 4.\n");
	scanf("%d", &numOfGames);
	if(numOfGames>15 || numOfGames<1)													//bullet proofing, max of 15 games, letters have values of 31387318473189+, and you don't want to play more than 15
	{
		numOfGames=5;
	}
	printf("\nYou have chosen to play %d games.\n",numOfGames);
	
	for(int gameNumber = 0; gameNumber<numOfGames; gameNumber++) 						// numOfGames games of high stakes hangman
	{
		hangman(gameNumber,numOfGames);
	}
	
	if(money>=400)																		// win 4 games or 3 if pilot dead
	{
		good = good + 3;
	}
	if(money<=150&&money>=0)															// if you win only 1
	{
		bad++;
	}
	if(money>150&&money<500)
	{
		neutral = neutral + 3;
	}
	if(money<0)
	{
		printf("\nYou lost all your money and owe the games masters monies. You tell them you have no monies on you, and that you need to go to you ship to get it (you don't have any money on the ship, but they don't know that. You'll just leave once you get there). They say no. Then they cuff you and you are never seen again. You lost the game.\n");
		quitProgram();
	}
}




//act three, you see guards and choose an action
int inspection()
{
	char inspectionDecision[1000], other[1200], answer[100];
	char shoot[]="shoot", kill[]="kill", assassinate[]="assassinate", distract[]="distract", bribe[]="bribe", ambush[]="ambush";
    int tempOne=0, tempTwo=0, len, done=0, x=0;
    int i;
	i=0;
	printf("\n\nAfter gambling and wasting the day away, you walk away from the table to go back to the ship. When you return to the ship you find two humanoids equipped in bulky power armor with giant cannons waiting by the ship, and on their crests the symbol for the Imperator. What do you do? Quickly make a decision and type only a single character. \nA.) Wait for them to leave. \nB.) Confront them. \nC.) Contact your crew and tell them what's up, and plan an attack to take them out. \nD.) Other. \nYou choose what to do. Enter choice now:\n");
	
	scanf("%s", inspectionDecision);
	//fgets(inspectionDecision, 1000, stdin);										  // get user input
	//inspectionDecision[strcspn(inspectionDecision, "\r\n")] = 0;				  //strcspn is a buffer, gbye newline from fgets

	for(i=0;inspectionDecision[i];i++)
	{
	       tempOne = inspectionDecision[i] + tempOne;

	       if(i>=2)																	// if you don't follow the instructions you lose
		   {
		   	   printf("\nYou didn't make a decision quickly, the guards saw you and immediately burst into action. They charge their cannons and call for your surrender. As they do, a squad of four more come out of your ship. You try to run, but are thrown in the air by a concussive blast. You've been captured and will spend the rest of your life in a cell. Oops. You lose.\n");
		   	   quitProgram();
		   }
	       if(tempOne==68 || tempOne==100) 											// other
		   {  
			   printf("\nYou want to do something else. \nEnter what you want to try now in a single word (use your verbs man, and don't use -ing or -ed, just the verb):\n");
			   char tmp[15];
			   scanf("%s", tmp);
			   fgets(other, 100, stdin);
			   other[strcspn(other, "\r\n")] = 0;
			   len = 0;				
			   len = strlen(other);
			   len = strlen(tmp); 
			   /*testing for the tmp and other and len variables and chars - printf("%s %s",tmp, other);
			   printf("%d",len);*/
			   if(len>50)															// type too much and you lose
			   {
			   		printf("\nYou spent too long thinking, and are seen by imperial guards and immediately burst into action. They charge their cannons and call for your surrender. As they do, a squad of four more come out of your ship. You try to run, but are thrown in the air by a concussive blast. You've been captured and will spend the rest of your life in a cell. Oops. You lose.\n"); 
			   		quitProgram();
			   }
			   if(len<50)
			   {
			   			if(strstr(other, kill) != NULL || strstr(other, shoot) != NULL || strstr(other, assassinate) != NULL || strstr(other, ambush) != NULL || strstr(tmp, kill) != NULL || strstr(tmp, shoot) != NULL || strstr(tmp, assassinate) != NULL || strstr(tmp, ambush) != NULL) // kill the guards in some way
			   			{
			   				done ++;
			   				printf("\nYeah, that idea could work. '%s%s' is a bold strategy. You spend a couple of minutes planning it out and setting it up then do it. It works with a small stroke of luck. Unluckily, your friend was on the ship when the guards searched it. He didn't quite make it. Your actions have also gained the attention of some other indviduals in the bay, and they ask to join. It's two alien bounty hunters and they are willing to join you if keep this up. \nAllow them to join? y/n\n",tmp, other);
			   				scanf("%s", answer);
							tempTwo = answer[x];
			   				if(tempTwo==121 || tempTwo==89)
			   				{
			   					printf("The two join your crew. ");
			   					crew = crew + 2;
			   					good = good + 3;
			   				}
			   				else
			   				{
			   					printf("The two bounty hunters thank you regardlessly, and one of them gives you some monies for a job well done.");
			   					money = money +50;
			   					good = good + 1;
			   				}
			   				printf("You decide that now is the time to leave and tell your crew that.\n");
			   				crew--;

			   			}
			   			if(strstr(other, bribe) != NULL || strstr(other, distract) != NULL || strstr(tmp, bribe) != NULL || strstr(tmp, distract) != NULL) 								// bribe or distract
			   			{
			   				printf("\nYeah, that idea could work. '%s' is a solid strategy. You spend a couple of minutes planning it out and setting it up and do it. It works with a small stroke of luck. Unluckily, your friend was on the ship when the guards searched it. He didn't quite make it. You decide that now is the time to leave and tell your crew.\n", other);
			   				crew --;
			   				done ++;
			   			}
			   			if(len<50 && done == 0) 									// just wait it out put in the A option for this
			   			{
			   				printf("\nThat won't work you decide after a second of thought. Instead, you've decided to wait out the imperial guards. You go to the of the busy ship bay, and begin to sift through your datapad while watching the guards out of the corner of your eye. The two guards stand there silently and umoving. After a few moments, you see one of your friends (they were barely more than a thug) get dragged out by four more guards all in power armor with gear. They leave, and you send an emergency ping to your ship. It's time to leave. You hope they did nothing to the ship because you can't stay here. You leave Mastrami shortly after and go into the expanse of space.\n");
			  				 crew --;
			   			
			   			}
			   }
			   // if you say more than 10 words or 50 characters (strlen) you get spotted trying to make up your mind, if shoot or kill or distract or bribe or assassinate are detected you ambush them and succeed, anything else and you just wait for them to leave with some bs excuse like that wouldn't work. if you don't detect kill and are under 50 characters then you default to a / temp == 65
		   }
		   if(tempOne==65 || tempOne==97) 											// wait for them to leave-lose 1
		   {  
			   printf("\nYou've decided to wait out the imperial guards. You go to the of the busy ship bay, and begin to sift through your datapad while watching the guards out of the corner of your eye. The two guards stand there silently and umoving. After a few moments, you decide to leave the scene and watch through the ship's cameras. You see one of your friends (they were barely more than a thug) get dragged out by four more guards all in power armor with gear a few hours later. They leave, and you send an emergency ping to your ship. It's time to leave. You hope they did nothing to the ship because you can't stay here. You leave Mastrami shortly after and go into the expanse of space.\n");
			   crew --;
			   neutral = neutral + 2;
		   }
		   if(tempOne==66 || tempOne==98) 											// confront them - you die/lose
		   {  
			   printf("\nYou've decided to confront the guards. You stroll up to them, weapon in hand and casually greet them. They stare at you, grounded and unmoving. You hear footsteps from inside the ship, and then the guards in front of you move. You shot the first one in the head, and throw a grenade at the second one when you get shot by the guards who were walking out of the ship. The grenade blows up and destroys part of your ship and the guard. Still, you are wounded and captured. You lose.\n");
			   quitProgram();
		   }
		   if(tempOne==67 || tempOne==99) 											// contact your crew then fight-lose 4 crew an3 but gain 800 money because they have power armor
		   {  
			   printf("\nYou've decided to call your crew and have them meet with whatever weapons you have. You explain the situation, and after waiting for them to leave decide that you're done waiting. You ambush the first guard while your crew is in the crowd of the ship bay, and he goes down. The second guard reacts inhumanly fast and blasts your engineer with his cannon. You have to go get another engineer because that one isn't coming back.\n");
			   crew = crew - 1;
			   printf("Your group of %d celebrates. This is okay, no one liked your engineer K anyway, she stole food out of your food generator and used up all the chocolate at least three times. Then your thug Charlie disappears in an electric mist.\n", crew);
			   crew = crew - 1;
			   printf("Your crew of %d now sees the four imperial guards that must have been checking your ship, and spread out all the while shooting. You duck behind another ship and shoot frantically. Soon enough it's all over, and explosives guy is no where to be see. (why did you get one in the first place you try to think). Oh well, time to get off this planet. You say that to your crew and they agree. You leave the planet in a hurry after this whole debacle.",crew);
			   crew = crew -1;
			   bad = bad + 3;
			   money = money + 800;
		   }	  
		   if(tempOne < 65 || tempOne > 68 && tempOne < 97|| tempOne > 100) 		// if you did not pick u lose
		   {
		   	   printf("\nYou could not think of anything good and are spotted and then captured. (AKA, didn't follow the directions)\nYou lose.\n");
		   	   quitProgram();
		   } 
		   
	}
	bad ++;
}

// act 4 fight, it's kind of like a butchered version of rock paper scissors except with numbers   
int fight()															//function to fight in confrontation
{
	int life = 10, enemyLife = 10, time=0;
	life = life + crew;												//elife is 10, yours is crew + 10
	char fightChoice[100], trap[5]="trap", shoot[10]="shoot", cover[10]="cover";
	if(money > 400) 												//if you have money you have more stuffs/life
	{
		life = life + 10;
	}
	printf("\nNobody does spaceship fights because it's mutually assured destruction, you shoot a thousands of bullets at their hull, they shoot thousands of bullets at your hull, everyone dies. That's bad. Instead people just board each others ships because technology. You've been boarded, and your crew of %d will defend the ship. \nNow that they're on you're ship you only have three options: trap, shoot, and cover.\nShoot does mild damage immediately, trap does heavy damage later, and cover will reduce your damage taken. It's kind of like rock, paper, scissors.\n",crew);
	while(life > 0 && enemyLife > 0)
	{
		printf("\nCombat continues Please enter 'shoot', 'trap', or 'cover'.\n");
		scanf("%s", fightChoice);
		printf("Your choice is: %s.",fightChoice);
		if(time >= 1) 														//trap damage first, so not immediate
		{
			printf("\nTraps go off.\n");
			enemyLife = enemyLife - time;
		}
		if(strstr(fightChoice, shoot) != NULL)								//your action shoot
		{
			printf("\nYou shoot the enemy.\n");
			enemyLife--;
		}
		if(strstr(fightChoice, trap) != NULL)								//your action trap
		{
			printf("\nYou have set some traps.\n");
			time++;
		}
		if(strstr(fightChoice, cover) != NULL)	 							//take cover					
		{
			printf("\nYou take cover and take less damage.");
			life++;
		}
		life = life - 2;												// enemy turn, always does 2
		printf("\nYour life is at %d. Enemy life is at %d.\n", life, enemyLife);
	}
	// depending on how dominant you are tehre's consequences
	if(life <= 0)
	{
		printf("\nYou died, so you lose.\n");
		quitProgram();
    }
     if(life <= 6)
    {
    	crew--;
    	printf("You lost a crew member in the fight. You have %d crew members left.\n",crew);
    }
    if(life <= 3)
    {
    	crew--;
    	printf("\nUnfortunately, your crew took more than just some damage. You now have %d crew members left.\n", crew);
    }
}   
   
   
// make this into a shooter mini game? 3 options: recover, evade, shoot, if you win you live, if you lose you lose. if you have enough monies then you don't have to fight. FINAL ACT, you meet debtors, if you don't have money you fight, if you do have money game ends
int confrontation()
{
	char choice[15], y[]="y", Y[]="Y", n[]="n", N[]="N";
	printf("\nYou are floating in space near by Mastrami when you are hailed by a familar name. Mihajenistsamonilsais, your debtors, are calling. You answer and they say this: \nWe are going to board you, if you have our 200 money we will take it and leave. If you do not we will take your ship and push you out the hatch with no suits. \nThat is bad. You currently have %d.\n",money);
	if(money>=200)
	{
		printf("That is plenty of money. Now you have a choice, do you let them take the money or do you fight? Keep in mind that you have %d crew members left. If you fight you may lose, if you give them the money you'll survive for sure, but be down on cash. Do you fight? y/n",crew);
		scanf("%s", choice);
		if(strstr(choice, y) != NULL || strstr(choice, Y) != NULL)
		{
			printf("You have chosen to fight.");
			fight();
		}
		else
		{
			printf("They board your ship and take your money then they leave and you never hear from them again. Smooth sailing from here.\n");
			money = money - 200;
			good = good + 2;		
		}
	}
	else if(money<200)
	{
		printf("You don't have enough money so you will be forced to fight.");
		fight();
	}

}





// main function does intro rules and roleplay, then calls functions. occasionally interacts between the functions for consequences later
int main(int argc, char* argv[])
{
	good = 0; 																	  //reset counters at start of the game
	bad = 0;
	neutral = 0;
	int choiceOne,conv=121;
	char userRe[2], difficulty[150], easy[10]="easy", hard[10]="hard";
	sscanf(argv[1],"%s",difficulty);
	difficulty[100] = argv[1];	
	if(strstr(argv[1], easy) != NULL) 											//easy mode
	{
		printf("\nYou are on easy mode. Have fun.\n");
		good = 5;
		bad = -2;
		crew = crew + 5;
		money = money + 100;
	}
	if(strstr(argv[1], hard) != NULL)											//hard mode
	{
		printf("\nYOU ARE ON HARD MODE. HAVE FUN LOSING.\n");
		bad = +3;
		crew = crew - 2;
		money = money - 100;
	}
	
	while(conv==121 || conv == 89)
	{
		printf("Welcome to Jacob Weber's RPG.\nRules: Please type only in lower case and use no punctuation because the program uses ASCII to determine what you say, only CAPITALIZE PROPER NAMES AND PLACES, for exmaple-like i want ice cream because its delicious i want dinosaurs to walk the earth but i also want to see Bob etc etc- unless you wish to throw everything to fate.\nSome decisions will be preset, where you either take action A, B, C, or D, and others you can type what you want to do. The program will pick up keywords and dependent on the words will choose a the scenario for you. Do your best to follow these rules and the game should run properly. When answering always leave spaces at the end of your answer. Your actions have rewards and consequences, and there are some rewards you don't want and some consequences you do want, do your best to succeed and you will find glory and wealthy. Good luck and have fun!\nAlso, there is a hard and easy mode, type hard or easy into the command land to access it.\n\n"); 																				// the intro/rules

		printf("\nGreetings, you have recently joined the Confederacy of Galactic Piracy on the basis that you pilfered a ship from the Imperial Guard. (You stole the ship with a small crew of 8. A few imperial grunts were bashed around and looted, but no one has been killed. Yet.) Congratualations. You are now being hunted across the galaxy, seeing that you have a bounty; such as it is, this will be interesting. \n\nLucky for you, we were able to communicate with you before things went too far. You have many choices to make in the future. Currently, there is one safe harbor within a few light years, you can make your way there and create a few alliances. The safe harbor is the Admiral's headquarters, often it's called 9 Caliber. Or you may go adventuring on your own, there are several planets close by. I would highly suggest you make a few allies, as the journey would be extremely difficult otherwise. If you decide against this course of action, I'd recommend going to Mastrami, there are many opportunities for an individual of your skill. \n\nDecide your destiny now.\n"); 			// who are, where are you, what will you do?

		choiceOne = decisionOnePirates(); 											 // your first decision - act one
		//printf("%d 1 is good -1 is bad 0 is neutral", choiceOne); 				 // test for choiceOne, which impacts debt
		
		// you've landed on Mastrami because illusion of choice. Here you want to try to pay off your debts, you will have an option of three games essentially, and they'll all be gambling. then dependent on what happens will lead to you next desination and so on
		
		debt(choiceOne);															// act two
		crewSize();
		printf("\n\nThe amount of money you have has changed. You now have %d.", money); // the amount of money you have will matter later when you meet your debtors. If you get that far. Muahahahahahhahaha.
		

		//imperial guards inspect your ship, u have to make some decisions and depending on your decisions will determine if you survive/take off. when you take off you fly into the expanse of space where you do some more pirating
		
		inspection();																// act three
		crewSize();
		printf("\nYou are now leaving Mastrami because of extenuating circumstances, and your crew is increasingly growing worried. You have not expected so many problems. \n"); // imp guards have found your crew, they've been missed up and ow you're running again. you're going to run into your debtors and they've going to blow up the imps following you, but then you have to pay up, if you can't then you play a game, if you lose that game you lose the game
		
		confrontation();															//act four/final
		crewSize();
		// imperial guards found your ship, you may or may not have crew problems soon, you also have debts to pay off, and if you went to the admiral you have something else coming to ya
		money = money + 800;
		neutral = neutral + 3;
		good++;
		printf("\nAfter that skirmish you decide that the best choice is to quit pirating. It's not for you. It also helps that you were able to take the debtor's ship and all their supplies. Maybe you can try to get your own cut of a planet. YOU WIN!\n");
		
		
		endGame();																	//shows results of game
		
		printf("\nWould you like to restart (if you do, game starts at normal) y/n\n");
		scanf("%s", userRe);
		conv = userRe[0];
		good = 0; bad = 0; neutral = 0; crew = 8; money = 0; 						//reset to normal game
		if(conv!=121)
		{
			printf("\nThank you for playing space pirates, I hope you enjoyed it.\n");
			exit(2);
		}	
	}	
}



