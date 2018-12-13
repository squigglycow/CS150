#include <stdio.h>
#include "gfx2.h"
#include <unistd.h>
#include <stdlib.h> 														// for rand
#include <time.h>															// for rand

#define maxX 800
#define maxY 500

void graphics_setup()
{
	int ysize = 500;
	int xsize = 800;
	srand(time(NULL));
	gfx_open(maxX, maxY, "My Awesome Green Triangle");
}

void drawSpiral(int xStart, int yStart, int lenStart, int lineGrowth, int numSteps, int Red, int Green, int Blue)
{
	int i, xNext, yNext;
	int x = xStart, y = yStart, length=lenStart;
	gfx_color(Red, Green, Blue);
	
	
	for(i=0;i<numSteps;i++)
	{
		if(i%4==0)
		{
			yNext = y;
			xNext = x + length;
		}
		else if(i%4==1)
		{
			yNext = y - length;
			xNext = x;
		}
		else if(i%4==2)
		{
			yNext = y;
			xNext = x - length;
		}
		else
		{
			yNext = y + length;
			xNext = x;
		}
		// darw one line of spiral
		gfx_line(x,y,xNext,yNext);
		gfx_flush();														//forces undrawn lines to appear
		x = xNext;
		y = yNext;
		length = length + lineGrowth;	
		//usleep(50000);
	}
}


int main(int argc, char* argv[])
{
	graphics_setup();
	double x, y, xChange, yChange;
	char c = 'a';
	x = maxX / 2;
	y = maxY / 2;
	yChange = 4;
	xChange = 7; 															//rand() % 10 + 1
	drawSpiral(x,y,5,5,20,255,255,255);
	while(1)
	{
		x = x + xChange;
		y = y + yChange;
		gfx_clear();
		drawSpiral(x,y,5,5,20,255,255,255);
		usleep(40000);
		
		//gravity
		y = yChange + .2;
		
		if(x >= maxX) {xChange = -xChange;}
		if(x <= 0) {xChange = -xChange;}
		if(x >= maxX) {yChange = -yChange;}
		if(x <= 0) {yChange = -yChange;}
		
		
		if(gfx_event_waiting())
		{
			c = gfx_wait();
			if(c=='q')break;
			/* absolute speed
			if(c=='w'){yChange=yChange-5;}
			if(c=='a'){xChange=xChange-0;}
			if(c=='s'){yChange=yChange+5;}
			if(c=='d'){xChange=xChange+0;}
			*/
			
			//acceleration/deceleration
			if(c=='w'){yChange=yChange-1;}
			if(c=='a'){xChange=xChange-1;}
			if(c=='s'){yChange=yChange+1;}
			if(c=='d'){xChange=xChange+1;}
		}
		
		//gfx_clear();
		//drawSpiral(300,400,10,3,50,255,0,0);
		//drawSpiral(600,150,2,2,100,255,255,0);
		
		return 0;
	}
	
}
