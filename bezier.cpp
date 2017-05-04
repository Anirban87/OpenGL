#include <GL/glut.h>
GLfloat ctrlpoints[4][3] = {
{ -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};
void printhead()
{
  char sap[10] = {'5','0','0','0','4','0','3','9','9'};
  char name[] = {'A','N','I','R','B','A','N'};
glRasterPos2f(0,2);
for (int i=0;i<10;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,sap[i]);
glRasterPos2f(0,2.5);
for (int i=0;i<8;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
}
void printname(float x, float y, char str[], int s)
{
glRasterPos2f(x,y);
for (int i=0;i<s;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,str[i]);
}
void init(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glShadeModel(GL_FLAT);
glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
glEnable(GL_MAP1_VERTEX_3);}
void display(void)
{
int i;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINE_STRIP);
for (i = 0; i <= 30; i++)
glEvalCoord1f((GLfloat) i/30.0);
glEnd();
/* The following code displays the control points as dots. */
glPointSize(5.0);
glColor3f(1.0, 1.0, 0.0);
glBegin(GL_POINTS);
for (i = 0; i < 4; i++)
glVertex3fv(&ctrlpoints[i][0]);
glEnd();
glColor3f(0.0,0.0,1.0);
char name[15]={'B','E','Z','I','E','R',' ','C','U','R','V','E'};
printname(3,1,name,15);
glBegin(GL_POLYGON);
glVertex2f(-1,1);
glVertex2f(2,1);
glVertex2f(2,3);
glVertex2f(-1,3);
glEnd();
glColor3f(1.0,1.0,1.0);
printhead();
glFlush();
}
void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode(GL_PROJECTION);glLoadIdentity();
if (w <= h)
glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
else
glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (600, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
