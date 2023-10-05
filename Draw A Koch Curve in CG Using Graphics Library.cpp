#include<iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
void koch(int x1,int y1,int x2,int y2,int it)
{
	float angle=60*M_PI/180;
	int x3=(2*x1+x2)/3;
	int y3=(2*y1+y2)/3;

	int x4=(x1+2*x2)/3;
	int y4=(y1+2*y2)/3;
	int x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	int y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);
	if(it>1)
	{
		koch(x1,y1,x3,y3,it-1);
		koch(x3,y3,x,y,it-1);
		koch(x,y,x4,y4,it-1);
		koch(x4,y4,x2,y2,it-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
		delay(100);
	}
}
	int main()
	{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int x1=50,y1=350,x2=500,y2=350;
	koch(x1,y1,x2,y2,5);
	return 0;
	delay(50000);
}
