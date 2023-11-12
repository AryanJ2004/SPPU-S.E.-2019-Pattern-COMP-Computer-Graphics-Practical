#include <iostream.h>
#include <process.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
int i,j,k;
class Transfn
{

	private:
		int n,Before[10][3],After[10][3];
		float T[3][3];
	public:
		void Getdata();
		void Menu();
		void Multi();
		void Drawpoly();
};
void Transfn::Getdata()
{
	cout<<"\n\nEnter The Number Of Vertices==>"<<endl;
	cin>>n;
	cout<<"\n\t Enter The Co-ordinate Of Vertices==>"<<endl;
	for (i=0;i<n;i++)
	{
		cin>>Before[i][0];
		cin>>Before[i][1];
		Before[i][2]=1;
	}
	Before[n][0]=Before[i][0];
	Before[n][1]=Before[0][1];
	Before[n][2]=1;
	cout<<"\n\n\t Matrix Representation===>\n\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n\n\t";
		for(j=0;j<3;j++)
		{
			cout<<"\t";
			cout<<Before[i][j];

		}

	}
}
void Transfn::Menu()
{
	int nCh,Tx,Ty,nC,nChoice,nChoice1;
	double X;
	float Shx,Shy,Xp,Yp,Sx,Sy;
	cout<<"\n\n\t 1. Translation \n\n\t 2.Rotation";
	cout<<"\n\n\t 3.Scaling";
	cout<<"\n\n\t 4.Exit";
	cout<<"\n\n\t Enter you Choice==>";
	cin>>nCh;
	switch(nCh)
	{
		case 1:
			cout<<"\n\t Enter The Translation Co-Ordinates Of Tx==>";
			cin>>Tx;
			cout<<"\n\t Enter The Translation Co-ordinates Of Ty==>";
			cin>>Ty;
			T[0][0]=1;
			T[0][1]=0;
			T[0][2]=0;
			T[1][0]=0;
			T[1][1]=1;
			T[1][2]=0;
			T[2][0]=Tx;
			T[2][1]=Ty;
			T[2][2]=1;
			break;
		case 2:
			cout<<"\n\t 1.Counter Clockwise";
			cout<<"\n\t 2.Clockwise";
			cout<<"\n\n Enter Your Choice:";
			cin>>nC;
			cout<<"\n\n\tEnter The Angle==>";
			cin>>X;
			X=X*(3.1432/180);
			if(nC==1)
			{

				T[0][0]=cos(X);
				T[0][1]=sin(X);
				T[0][2]=0;
				T[1][0]=(-1)*sin(X);
				T[1][1]=cos(X);
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
			}
			else
			{

				T[0][0]=cos(X);
				T[0][1]=(-1)*sin(X);
				T[0][2]=0;
				T[1][0]=sin(X);
				T[1][1]=cos(X);
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
			}
			break;

		case 3:
			cout<<"\n\n\t Enter The value Of X-Scale==>";
			cin>>Sx;

			cout<<"\n\n\t Enter The value Of Y-Scale==>";
			cin>>Sy;
				T[0][0]=Sx;
				T[0][1]=0;
				T[0][2]=0;
				T[1][0]=0;
				T[1][1]=Sy;
				T[1][2]=0;
				T[2][0]=0;
				T[2][1]=0;
				T[2][2]=1;
				break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"\n\n Invalid Choice!!!";
	}
}
void Transfn::Multi()
{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				After[i][j]=0;
				for(k=0;k<3;k++)
				{
					After[i][j]=After[i][j]+(Before[i][k]*T[k][j]);
				}
			}
		}
}
void Transfn::Drawpoly()
{
		int i;
		int Xc,Yc,Xmax,Ymax;
		int gd=DETECT,gm;
		initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
		Xmax=640;
		Ymax=480;
		Xc=Xmax/2;
		Yc=Ymax/2;

		line(0,Yc,Xmax,Yc);
		line(Xc,0,Xc,Ymax);
		outtextxy(Xc,0,"Y-Axis");
		outtextxy(0,Yc,"X-Axis");
		outtextxy(Xc,Yc,"0,0");

		cout<<"\n\n\t Before Transformation==>";
		for(i=0;i<n;i++)
		{
			line(Xc+Before[i][0],Yc-Before[i][1],Xc+Before[i+1][0],Yc-Before[i+1][1]);;
		}
		getch();
		//cleardevice();
		cout<<"\n\n\t After Transformation==>";
		for(i=0;i<n;i++)
		{
			line(Xc+After[i][0],Yc-After[i][1],Xc+After[i+1][0],Yc-After[i+1][1]);
		}

}
int main()
{

	Transfn obj;
	clrscr();
	char nAns;
	obj.Getdata();
	do
	{
		obj.Menu();
		obj.Multi();
		obj.Drawpoly();
		cout<<"\n\n\t Do You Want To Continue (Y||y)";
		cin>>nAns;
		cleardevice();
	}while(nAns== 'y'|| nAns=='Y');
	getch();
	closegraph();
	return 0;
}
