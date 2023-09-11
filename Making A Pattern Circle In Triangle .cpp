#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
class algo
{
public:
void dda_line(float x1, float y1, float x2, float y2);
void bresneham_cir(int r);
};
void algo::dda_line(float x1, float y1, float x2, float y2)
{
float x,y,dx,dy,Dx,Dy,length;
int i,c;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
length=dx;
else
length=dy;
Dx=(x2-x1)/length;
Dy=(y2-y1)/length;
x=x1+0.5;
y=y1+0.5;
i=1;
while(i<=length)
{
putpixel(320+x,240-y,4);
x=x+Dx;
y=y+Dy;
i=i+1;
delay(40);
}
}
void algo::bresneham_cir(int r)
{
int x,y,d,c;
int xc=320;
int yc=240;
x=0;
y=r;
d=3-(2*r);
do
{
putpixel(xc+x,yc+y,1);
putpixel(xc-x,yc+y,2);
putpixel(xc+x,yc-y,3);
putpixel(xc-x,yc-y,5);
putpixel(xc+y,yc+x,6);
putpixel(xc+y,yc-x,7);
putpixel(xc-y,yc+x,8);
putpixel(xc-y,yc-x,9);

if(d<=0)
{
d=d+(4*x)+6;
}
else
{
d=d+(4*(x-y))+10;
y=y-1;
}
x=x+1;
delay(50);
}
while(x<y);
}
int main()
{
	algo a1;
	int gm,gd=DETECT;
	int i;
	
	float r,ang,r1;
	cout<<"Enter Radius Of Large Circle=";
	cin>>r;
	initgraph(&gd,&gm,NULL);
	a1.bresneham_cir((int)r);
	ang=3.24/180;
	float c=r*cos(30*ang);
	float s=r*sin(30*ang);
	a1.dda_line(0,r,0-c,0-s);
	a1.dda_line(0-c,0-s,0+c,0-s);
	a1.dda_line(0+c,0-s,0,r);
	r1=s;
	a1.bresneham_cir((int)r1);
	delay(500);
	return 0;
}
