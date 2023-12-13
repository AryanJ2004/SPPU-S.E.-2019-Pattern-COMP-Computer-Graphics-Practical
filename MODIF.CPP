#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>    //I/O functions and memory allocation
void enemycar(int x, int y)
{
setcolor(15);  //sets the white colour to boundary
rectangle(x+1,y,x+49,y+100); //middle rectangle of enemy car
line(x,y+25,x+10,y); //trapezium lines
line(x+50,y+25,x+40,y);
line(x+10,y+100,x,y+75);
line(x+50,y+75,x+40,y+100);
rectangle(x+1,y+25,x+49,y+75);//outer rectangle of enemy car
setfillstyle(SOLID_FILL,YELLOW);   //fills the middle rectangle with yellow colour
floodfill((x+25),(y+50),15);//defines the border of yellow colour
setfillstyle(7,RED);
floodfill((x+25),(y+20),15); //fills upper trap of enemy car
floodfill((x+25),(y+80),15); //fills lower trap of enemy car
}

void mycar(int x, int y)
{
setcolor(15);
arc(x+25,y+26,0,180,24);//top arc of my car
setfillstyle(5,RED);
arc(x+25,y+75,180,360,24); //bottom arc of my car
rectangle(x+1,y+25,x+49,y+75);//middle rectangle of my car
floodfill((x+25),(y+50),15);
setfillstyle(5,BLUE);
floodfill((x+25),(y+20),15);
floodfill((x+25),(y+80),15);
}



void myclear(int x,int y)    //function clears the previous position of car
{
setcolor(8);
arc(x+25,y+26,0,180,24); //clears the top arc of the my arc
arc(x+25,y+75,180,360,24);
rectangle(x+1,y,x+49,y+100);
setfillstyle(SOLID_FILL,8);
floodfill((x+25),(y+50),8);
floodfill((x+25),(y+20),8);
floodfill((x+25),(y+80),8);
}


void enemyclear(int x,int y) //function clears the previous position of the enemy car
{
setcolor(8);
rectangle(x+1,y,x+49,y+100);
rectangle(x+1,y+25,x+49,y+75);
}

void main()
{
int gdriver = DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
int x=300,y=350,ch,life=1,score=0;
char choice;
cout<<"\n\n\n\n\n\t\t\t******THUNDER RACER**********";
cout<<"\n\n\t\tMade By Student Of S.E. Computer";
cout<<"\n\n\Aryan N. Jain\nPiyush V. Bedmuttha\nAtharva D. Alai\nRohak R. Bora";
delay(1500);
for(int m=1;m<25;m++)
    for(int n=1;n<80;n++) {
	gotoxy(n,m);
	cout<<" ";
	}
  setcolor(RED);
 rectangle(20,60,200,120);   //first box
 rectangle(20,300,200,420);   //last box
  gotoxy(5,21);
  cout<<"SNJB College";
  gotoxy(5,22);
  cout<<"Department Of";
  gotoxy(5,23);
  cout<<"Computer Engineering";
  gotoxy(5,24);
  cout<<"S.E.(B)-S1";
  rectangle(248,0,402,479);  //create main box
  setfillstyle(SOLID_FILL,8);//fill color of main box  GRAY ROAD
  floodfill(325,479/2,RED);//boundary for setfillstyle
  rectangle(20,200,200,250);  //esc rectangle
  setcolor(WHITE);
  line(350,0,350,479);
  setcolor(WHITE);
  line(300,0,300,479);
  delay(500);
  gotoxy(5,15); //goto specific box of esc
  cout<<"Press <Esc> to Exit";
  for(int level=1;(level<=3)&&(life>0);level++){
    if(level==1){
      gotoxy(5,5);
      cout<<"Your Game Starts Now";
      gotoxy(5,7);
      cout<<"GOOD LUCK!!!";
      delay(1500);
      gotoxy(5,5);  //triggers when game over
      cout<<"                    ";
      gotoxy(5,7);
      cout<<"               ";
      }
     else {
	 gotoxy(5,5);
	 cout<<"Next level.";
	 delay(500);
	 gotoxy(5,5);
	 cout<<"           ";
	 }
  for(int i=0;(i<15)&&(life>0);i++) {  //Increases level after 15 cars
    if((level==3)&&(i==14)){
       gotoxy(5,5);
       cout<<"You Won!!!";
       gotoxy(5,6);
       cout<<"Do You Want To Continue? <y/n>";
       choice = getch();
       if ((choice=='y')||(choice=='Y'))
	main();
       else
	exit(0);
       }
    setcolor(RED);
    rectangle(420,125,600,175);//Level Rectangle
    gotoxy(55,10);
    cout<<"Level = "<<level;
    rectangle(420,250,600,300);    //Lives Rectangle
    gotoxy(55,18);
    cout<<"Lives = "<<life;
    rectangle(420,350,600,400);  //Score Rectangle
    gotoxy(55,24);
    cout<<"Score = "<<score;
    int accident=0;
    int y1=1,x1=250+((rand()%3)*50);  //enemy car positions
    int y2=1,x2=250+((rand()%3)*50);   //divides cars on road in 3 parts
    score += 10;
    while(y1<480-1)
    {

	enemyclear(x1,y1); //clears enemy first car
	enemyclear(x2,y2); //clears enemy second car
	y1++;
	y2++;
	if(accident == 1)
	    break;
	enemycar(x1,y1);//calls first enemy car
       enemycar(x2,y2);//calls second enemy car
	mycar(x,y);
	delay(3-level);
	if(kbhit())  //it reads the keyboard keys
	{
	    mycar(x,y);
	    ch=getch();   //takes the key from user input from keyboard
	    switch(ch) {
	    case 27: exit(0);    //esc key define
	    break;
	    case 75:myclear(x,y);  //left arrow
		  if(x>250)      //allows the car to left box
		    x=x-50;
		    if((x==x1)||(x==x2)) //accident condition(Central Lane)
			if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
			{
			    accident=1;
			    goto Next1;
			}
	    break;
	    case 77:myclear(x,y);//right arrow
		if(x<350)
		    x=x+50;
		    if((x==x1)||(x==x2))
			if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
			{
			    accident=1;
			    goto Next1;
			}
	    break;
	    case 72:myclear(x,y);   //up arrow
		if(y>0)
		      y=y-10; //defines how much car displace up
	     break;
	     case 80:myclear(x,y); //down arrow
		if(y<getmaxy()-105)
		    y=y+10; //defines how much car displace down
	     break;
	    }
	}
	if((x==x1)||(x==x2))   //accident condition
	    if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
		accident=1;



      Next1:
      if(accident==1){
	life-=1;
	score -= 10;
	if(life==0) {
	 gotoxy(5,5);
	 cout<<"GAME OVER ";
	 gotoxy(5,6);
	 cout<<"Your Car Has Been";
	 gotoxy(5,7);
	 cout<<"CRASHED!!!";
	 break;
	 }
	}
	}
  }
  }
 getch();
 }