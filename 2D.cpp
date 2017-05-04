#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
void initGL() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void printhead()
{
  char sap[10] = {'5','0','0','0','4','0','3','9','9'};
  char name[] = {'A','N','I','R','B','A','N'};
glRasterPos2f(0.0,0.4);
for (int i=0;i<10;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,sap[i]);
glRasterPos2f(0.0,0.5);
for (int i=0;i<8;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
}
void printname(float x, float y, char str[], int s)
{
glRasterPos2f(x,y);
for (int i=0;i<s;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,str[i]);
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(-0.5f, 0.4f, 0.0f);glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f);
glVertex2f(-0.3f, -0.3f);
glVertex2f( 0.3f, -0.3f);
glVertex2f( 0.3f, 0.3f);
glVertex2f(-0.3f, 0.3f);
glEnd();
glTranslatef(0.1f, -0.7f, 0.0f); // Translate right and down
glBegin(GL_QUADS);
// Each set of 4 vertices form a quad
glColor3f(0.0f, 1.0f, 0.0f); // Green
glVertex2f(-0.3f, -0.3f);
glVertex2f( 0.3f, -0.3f);
glVertex2f( 0.3f, 0.3f);
glVertex2f(-0.3f, 0.3f);
glEnd();
glTranslatef(-0.3f, -0.2f, 0.0f); // Translate left and down
glBegin(GL_QUADS);
// Each set of 4 vertices form a quad
glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
glVertex2f(-0.2f, -0.2f);
glColor3f(1.0f, 1.0f, 1.0f); // White
glVertex2f( 0.2f, -0.2f);
glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
glVertex2f( 0.2f,
0.2f);
glColor3f(1.0f, 1.0f, 1.0f); // White
glVertex2f(-0.2f,
0.2f);
glEnd();
glTranslatef(1.1f, 0.2f, 0.0f); // Translate right and up
glBegin(GL_TRIANGLES);
// Each set of 3 vertices form a triangle
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glVertex2f(-0.3f, -0.2f);
glVertex2f( 0.3f, -0.2f);
glVertex2f( 0.0f,
0.3f);glEnd();
glTranslatef(0.2f, -0.3f, 0.0f);
// Translate right and down
glRotatef(180.0f, 0.0f, 0.0f, 1.0f); // Rotate 180 degree
glBegin(GL_TRIANGLES);
// Each set of 3 vertices form a triangle
glColor3f(1.0f, 0.0f, 0.0f); // Red
glVertex2f(-0.3f, -0.2f);
glColor3f(0.0f, 1.0f, 0.0f); // Green
glVertex2f( 0.3f, -0.2f);
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glVertex2f( 0.0f,
0.3f);
glEnd();
glRotatef(-180.0f, 0.0f, 0.0f, 1.0f); // Undo previous rotate
glTranslatef(-0.1f, 1.0f, 0.0f); // Translate right and down
glBegin(GL_POLYGON); // The vertices form one closed polygon
glColor3f(1.0f, 1.0f, 0.0f); // Yellow
glVertex2f(-0.1f, -0.2f);
glVertex2f( 0.1f, -0.2f);
glVertex2f( 0.2f, 0.0f);
glVertex2f( 0.1f, 0.2f);
glVertex2f(-0.1f, 0.2f);
glVertex2f(-0.2f, 0.0f);
glEnd();
glColor3f(1.0,0.0,0.0);
char name[15]={'2','-','D',' ','T','R','A','N','S','F','O','R','M'};
printname(0.3,0.1,name,15);
glBegin(GL_POLYGON);
glVertex2f(-0.3,0.3);
glVertex2f(0.3,0.3);
glVertex2f(0.3,0.7);
glVertex2f(-0.3,0.7);
glEnd();
glColor3f(1.0,1.0,1.0);
printhead();glFlush();
}
void reshape(GLsizei width, GLsizei height) {
if (height == 0) height = 1;
GLfloat aspect = (GLfloat)width / (GLfloat)height;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (width >= height) {
gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
} else {
gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
}
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitWindowSize(640, 480);
glutInitWindowPosition(50, 50);
glutCreateWindow("2D Transformation");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
initGL();
glutMainLoop();
return 0;}
