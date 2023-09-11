#include<graphics.h>
#include<iostream>
using namespace std;
int main()
{
	int gm,gd=DETECT;
	int x,y,d,r;
	int xc=320;
	int yc=240;
	cout<<"\n Enter The Radius of Circle:";
	cin>>r;

	initgraph(&gd,&gm,NULL);

x=0;
y=r;
d=3-2*r;
do
{
putpixel(xc+x,yc+y,15);
putpixel(xc-x,yc-y,15);
putpixel(xc+x,yc-y,15);
putpixel(xc-x,yc+y,15);
putpixel(xc+y,yc-x,15);
putpixel(xc-y,yc-x,15);
putpixel(xc+y,yc+x,15);
putpixel(xc-y,yc+x,15);

if(d<0)
{
y=y;
d=d+4*x+6;
}
else
{
d=d+4*(x-y)+10;
y=y-1;
}
x=x+1;
delay(200);
}
while(x<=y);
  delay(5000);
  return 0;
}

