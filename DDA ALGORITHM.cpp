#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{	
	int gd,gm=DETECT;
	float x1,x2,y1,y2,x,y,c,dx,dy,Dx,Dy,length;
	int i;

	cout<<"\n enter the coordinates(x1,y1)=";
	cin>>x1>>y1;
	cout<<"\n enter the coordinates(x2,y2)=";
	cin>>x2>>y2;
	initgraph(&gm,&gd,NULL);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>=dy)
	{
		length=dx;
		}
	else
	{
		length=dy;
	}
	Dx=(x2-x1)/length;
	Dy=(y2-y1)/length;
	x=x1+0.5;
	y=y1+0.5;
	i=0;
	
	while(i<=length)
	{
		putpixel(x,y,15);
		x=x+Dx;
		y=Dy+y;
		i=i+1;
			delay(100);
	}
	delay(5000);
}
