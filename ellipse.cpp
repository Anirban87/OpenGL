#include<stdio.h>
#include<GL/glut.h>
#include <stdlib.h>
#include<math.h>
using namespace std;
int h,k;
float a,b;
void box()
{
glBegin(GL_POLYGON);
glVertex2f(50,70);
glVertex2f(50,30);
glVertex2f(20,30);
glVertex2f(20,70);
glEnd();
}
void printhead()
{
  char sap[10] = {'5','0','0','0','4','0','3','9','9'};
  char name[] = {'A','N','I','R','B','A','N'};
glRasterPos2f(-10,70);
for (int i=0;i<10;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,sap[i]);
glRasterPos2f(-10,80);
for (int i=0;i<6;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
}
void printname(float x, float y, char str[], int s)
{
glRasterPos2f(x,y);
for (int i=0;i<s;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,str[i]);
}
void display(void)
{
double I,J;
int i,j;
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0,0,0);
glBegin(GL_POINTS);
glVertex2s(h,k);
for( i=0 ; i<=a ; i+=1)
{
J=sqrt(1 - (i*i)/(a*a))*b;
j=(int)(J);glVertex2s(h+i,k+j);
glVertex2s(h-i,k+j);
glVertex2s(h-i,k-j);
glVertex2s(h+i,k-j);
}
glColor3f (0,0,0);
for(int i=-50 ; i<=50 ; i++)
{
glVertex2s(i,0);
glVertex2s(0,i);
}
for(int i=-2; i<=2 ; i++)
{
glVertex2s(95+i,4+i);
glVertex2s(95-i,4+i);
}
for(int i=0; i<=2 ; i++)
{
glVertex2s(4+i,95+i);
glVertex2s(4-i,95+i);
glVertex2s(4,95-i);
}
glColor3f(0,0,0);
char name[]={"Ellipse"};
printname(20,50,name,8);
box();
glColor3f(0,0,0);
printhead();
glEnd();
glFlush();
}
void init(void)
{
glClearColor (1,1,1,0);
glMatrixMode(GL_PROJECTION);
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
printf("Enter the center of ellipse:\n");
scanf("%d %d",&h,&k);
printf("Enter the parameters a & b:\n");
scanf("%f %f",&a,&b);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400,400);
glutInitWindowPosition(0,0);
glutCreateWindow("500040045");
init();
glutDisplayFunc(display);
glutMainLoop();
}
