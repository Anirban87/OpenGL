#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#define K 0.015
void display(void);
void init(void);
int main(int argc,char**argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("500041043");
glutInitWindowPosition(10,10);
glutInitWindowSize(1024,768);
glutCreateWindow("500040399");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
void init(void)
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex3f(0,0,0);
glVertex3f(0.8,0,0);
glVertex3f(0.8,-0.6,0);
glVertex3f(0,-0.6,0);
glEnd();
//GRBox Out
glBegin(GL_LINE_LOOP);
glVertex3f(-0.05,0.05,0);
glVertex3f(0.85,0.05,0);
glVertex3f(0.85,-0.6,0);
glVertex3f(0.8,-0.6,0);
glVertex3f(0.8,0,0);
glVertex3f(0,0,0);
glVertex3f(0,-0.6,0);
glVertex3f(-0.05,-0.6,0);
glEnd();
//GRBox 16
for(float i=0;i<0.8;i+=0.2)
{
For(float j=0;j<0.6;j+=0.15)
{
glBegin(GL_LINE_LOOP);
glVertex3f(i+K,-j-K,0);
glVertex3f(i+0.2-K,-j-K,0);
glVertex3f(i+0.2-K,-j-0.15+K,0);
glVertex3f(i+K,-j-0.15+K,0);
glEnd();
}
}
//1RBox In
glBegin(GL_LINE_LOOP);
glVertex3f(-0.05,0.05,0);
glVertex3f(0.85,0.05,0);
glVertex3f(0.85,0.45,0);
glVertex3f(0.40,0.65,0);
glVertex3f(-0.05,0.45,0);
glEnd();
//1RBox Out
glBegin(GL_LINE_LOOP);
glVertex3f(0.85,0.5,0);
glVertex3f(0.85,0.45,0);
glVertex3f(0.40,0.65,0);
glVertex3f(-0.05,0.45,0);
glVertex3f(-0.05,0.5,0);
glVertex3f(0.40,0.7,0);
glEnd();
glFlush();
}
