//Must Be Implemented In TurboC

#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>

void main()
{
int gd=DETECT,gm;
int rhx,rhy,j,i;
initgraph(&gd,&gm, "C:\\Turboc3\\BGI");
for(i=0;i<500;i+=5)
{

line(20,380,580,380);

if(i%2==0)
{
line(25+i,380,35+i,340);
line(45+i,380,35+i,340);
line(35+i,310,25+i,330);
delay(20);
}
else
{
line(35+i,380,35+i,340);
line(35+i,310,40+i,330);
delay(20);
}
line(35+i,340,35+i,310);
circle(35+i,300,10);
line(35+i,310,50+i,330);
line(50+i,330,50+i,280);
line(15+i,280,85+i,280);

arc(50+i,280,0,180,35);
arc(55+i,330,180,360,5);
setcolor(YELLOW);
rhx=getmaxx();
rhy=getmaxy();
for(j=0;j<100;j++)
{
	outtextxy(random(rhx),random(rhy-50),".");

setcolor(WHITE);
}
delay(150);
cleardevice();
}
getch();
closegraph();
}
