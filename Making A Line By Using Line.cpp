#include<graphics.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{

    int gm,gd=DETECT;
    int x,y,x1,y1,x2,y2,c;
   cout<<"\n Enter The Coordinates of pixel (x,y)=";
    cin>>x>>y;
   cout<<"\n Enter The Colour Coordinates=";
    cin>>c;
    cout<<"\n Enter The Coordinates First Point (x1,y1)=";
    cin>>x1>>y1;
    cout<<"\n Enter The Coordinates Of Last Point (x2,y2)=";
    cin>>x2>>y2;
  initgraph(&gd,&gm,NULL);
  putpixel(x,y,c);
  line(x1,y1,x2,y2);
    delay(10000);
    return 0;

}