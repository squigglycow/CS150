#include <stdio.h>



void countHigh (int howHigh){
	int count;	
	for (count=1; count <= howHigh; count ++)
	{
	printf("%d \n", count);
	}
}


void countFromToBy(int From, int To, int By)
{
	int count;
	for (count=From; count <= To; count = count + By) // prints from # to $ by #
	{
	printf("%d \n", count);
	}
}


void main()
{	
countFromToBy(30,120,3); //sets from to by
}


