#include <GL/glut.h>
GLfloat xRotated, yRotated, zRotated;
void printhead()
{
  char sap[10] = {'5','0','0','0','4','0','3','9','9'};
  char name[] = {'A','N','I','R','B','A','N'};
glRasterPos2f(-0.2,0.1);
for (int i=0;i<10;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,sap[i]);
glRasterPos2f(-0.2,0.2);
for (int i=0;i<8;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
}
void printname(float x, float y, char str[], int s)
{
glRasterPos2f(x,y);
for (int i=0;i<s;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,str[i]);
}
void redisplayFunc(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0,0.0,-5.0);
glColor3f(0.9, 0.0, 0.0);
glRotatef(xRotated,1.0,0.0,0.0);
glRotatef(yRotated,0.0,1.0,0.0);
glRotatef(zRotated,0.0,0.0,1.0);
glScalef(1.0,1.0,1.0);
glutWireCube(1.0);
glColor3f(1.0,0.0,0.0);
char name[15]={'3','-','D',' ','T','R','A','N','S','F','O','R','M'};
printname(0.5,0.8,name,15);glBegin(GL_POLYGON);
glVertex2f(-0.3,0);
glVertex2f(0.4,0);
glVertex2f(0.4,0.3);
glVertex2f(-0.3,0.3);
glEnd();
glColor3f(1.0,1.0,1.0);
printhead();
glFlush();
glutSwapBuffers();
}
void reshapeFunc(int x, int y)
{
if (y == 0 || x == 0) return;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
glMatrixMode(GL_MODELVIEW);
glViewport(0,0,x,y);
}
void idleFunc(void)
{
// rotation around x axis
xRotated += 0.03;
redisplayFunc();
}
int main (int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(350,350);
// create the window
glutCreateWindow("500040664");
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
xRotated = yRotated = zRotated = 0.0;
glClearColor(0.0,0.0,0.0,0.0);//Assign the function used in events
glutDisplayFunc(redisplayFunc);
glutReshapeFunc(reshapeFunc);
glutIdleFunc(idleFunc);
glutMainLoop();
return 0;
}
