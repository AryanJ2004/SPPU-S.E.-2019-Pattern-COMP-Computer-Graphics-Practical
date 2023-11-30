#include <GL/glut.h>
#include <math.h>
void myinit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	gluOrtho2D(0,640,0,480);
}
void line(int x1,int y1,int x2,int y2)
{
	glBegin(GL_LINES);
			glVertex2i(x1,y1);
			glVertex2i(x2,y2);
	glEnd();
	glFlush();
}
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
	}
}

void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x1=100,y1=100,x2=400,y2=400;
	koch(x1,y1,x2,y2,4);
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);

	glutInitWindowPosition(0,0);

	glutCreateWindow("Koch Curve");

	glutDisplayFunc(mydisplay);

	myinit();
	glutMainLoop();
}
