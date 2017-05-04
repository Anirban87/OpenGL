#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
float lastx, lasty;
float angle=0.0,ratio;
float x=0.0f,y=0.0f,z=0.5f;
float lx=0.0f,ly=0.0f,lz=-1.0f;
float _angle = 30.0f;
float _cameraAngle = 0.0f;
void printhead()
{
  char sap[10] = {'5','0','0','0','4','0','3','9','9'};
  char name[] = {'A','N','I','R','B','A','N'};
glRasterPos2f(-0.2,0.8);
for (int i=0;i<9;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,sap[i]);
glRasterPos2f(-0.2,0.9);
for (int i=0;i<6;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
}
void printname(float x, float y, char str[], int s){
glRasterPos2f(x,y);
for (int i=0;i<s;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,str[i]);
}void RotY(float ang) {
lx = sin(ang);
lz = -cos(ang);
glLoadIdentity();
gluLookAt(x, y, z,x + lx,y + ly,z + lz,0.0f,1.0f,0.0f);
}
void moveFB(int direction) {
x = x + direction*(lx)*0.1;
z = z + direction*(lz)*0.1;
glLoadIdentity();
gluLookAt(x, y, z,x + lx,y + ly,z + lz,0.0f,1.0f,0.0f);
}
void LookUpDown(float ang) {
ly = sin(ang);
lz = -cos(ang);
glLoadIdentity();
gluLookAt(x, y, z,x + lx,y + ly,z + lz,0,1,0);
if (angle > 360) {
angle -= 360;
}}
void initRendering() {
glEnable(GL_DEPTH_TEST);
}
void handleKeypress(unsigned char key, int x, int y) {
switch (key) {
case 27:
exit(0);
}}
void handleSpecialKey(int key, int x, int y) {
switch (key) {case GLUT_KEY_LEFT :
angle -= 0.1f;
RotY(angle);
break;
case GLUT_KEY_RIGHT :
angle +=0.1f;
RotY(angle);
break;
case GLUT_KEY_UP :
moveFB(1);
break;
case GLUT_KEY_DOWN :
moveFB(-1);
break;
case GLUT_KEY_PAGE_UP :
angle +=0.01f;
LookUpDown(angle);
break;
case GLUT_KEY_PAGE_DOWN :
angle -=0.01f;
LookUpDown(angle);
break;
}}
void motionPassive(int x, int y){
glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
cout << "Mouse moved at "<< "(" << x << "," << y << ")" << endl;
int diffx=x-lastx;
int diffy=y-lasty;
lastx=x; //set lastx to the current x position
lasty=y; //set lasty to the current y position
angle += (float) diffy;
RotY(angle/20);
angle += (float) diffx;RotY(angle/20);
}

void handleResize(int w, int h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,(double)w / (double)h,0.25,200.0);
}
void drawScene() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_COLOR_MATERIAL);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(x, y, z,x + lx,y + ly,z + lz,0.0f,1.0f,0.0f);
//glRotatef(LookUpDown,1.0,0,0);
glPushMatrix();
glTranslatef(0.0f, 0.0f, 0.0f);
glRotatef(_angle, 0.0f, 1.0f, 0.0f);
glScalef(0.01f, 0.01f, 0.01f);
glBegin(GL_QUADS);
//Cross back
glColor4f(1.0f,1.0f, 0.0f, 0.9f);
glVertex3f(-0.5, 2.5, -0.5);
glVertex3f(-0.5, -3.0, -0.5);
glVertex3f(0.5, -3.0, -0.5);
glVertex3f(0.5, 2.5, -0.5);
glVertex3f(-2.0, 1.0, -0.5);
glVertex3f(-2.0, 0.0, -0.5);
glVertex3f(2.0, 0.0, -0.5);
glVertex3f(2.0, 1.0, -0.5);//Cross front
glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
glVertex3f(-0.5, 2.5, 0.5);
glVertex3f(-0.5, -3.0, 0.5);
glVertex3f(0.5, -3.0, 0.5);
glVertex3f(0.5, 2.5, 0.5);
glVertex3f(-2.0, 1.0, 0.5);
glVertex3f(-2.0, 0.0, 0.5);
glVertex3f(2.0, 0.0, 0.5);
glVertex3f(2.0, 1.0, 0.5);
//Cross top
glVertex3f(0.5, 2.5, 0.5);
glVertex3f(-0.5, 2.5, 0.5);
glVertex3f(-0.5, 2.5, -0.5);
glVertex3f(0.5, 2.5, -0.5);
//Cross left top side
glVertex3f(-0.5, 2.5, 0.5);
glVertex3f(-0.5, 2.5, -0.5);
glVertex3f(-0.5, 1.0, -0.5);
glVertex3f(-0.5, 1.0, 0.5);
//Cross left side
glVertex3f(-0.5, 1.0, 0.5);
glVertex3f(-0.5, 1.0, -0.5);
glVertex3f(-2.0, 1.0, -0.5);
glVertex3f(-2.0, 1.0, 0.5);
//Cross left side
glVertex3f(-2.0, 1.0, 0.5);
glVertex3f(-2.0, 1.0, -0.5);
glVertex3f(-2.0, 0.0, -0.5);
glVertex3f(-2.0, 0.0, 0.5);
//Cross left side bottom
glVertex3f(-2.0, 0.0, 0.5);
glVertex3f(-0.5, 0.0, 0.5);
glVertex3f(-0.5, 0.0, -0.5);
glVertex3f(-2.0, 0.0, -0.5);//Cross left bottom side
glVertex3f(-0.5, 0.0, 0.5);
glVertex3f(-0.5, 0.0, -0.5);
glVertex3f(-0.5, -3.0, -0.5);
glVertex3f(-0.5, -3.0, 0.5);
//Cross
glVertex3f(0.5, -3.0, 0.5);
glVertex3f(0.5, -3.0, -0.5);
glVertex3f(-0.5, -3.0, -0.5);
glVertex3f(-0.5, -3.0, 0.5);
//Cross right bottom side
glVertex3f(0.5, 0.0, 0.5);
glVertex3f(0.5, -3.0, 0.5);
glVertex3f(0.5, -3.0, -0.5);
glVertex3f(0.5, 0.0, -0.5);
//Cross right side bottom
glVertex3f(0.5, 0.0, 0.5);
glVertex3f(0.5, 0.0, -0.5);
glVertex3f(2.0, 0.0, -0.5);
glVertex3f(2.0, 0.0, 0.5);
//Cross right side end
glVertex3f(2.0, 1.0, 0.5);
glVertex3f(2.0, 0.0, 0.5);
glVertex3f(2.0, 0.0, -0.5);
glVertex3f(2.0, 1.0, -0.5);
//Cross right side top
glVertex3f(0.5, 1.0, 0.5);
glVertex3f(2.0, 1.0, 0.5);
glVertex3f(2.0, 1.0, -0.5);
glVertex3f(0.5, 1.0, -0.5);
//Cross right side top
glVertex3f(0.5, 1.0, 0.5);
glVertex3f(0.5, 1.0, -0.5);
glVertex3f(0.5, 2.5, -0.5);
glVertex3f(0.5, 2.5, 0.5);glEnd();
glPopMatrix();
glPushMatrix();
glBegin(GL_QUADS);
glTranslatef(0.0f, -1.5f, 0.0f);
glRotatef(_angle,0.0,0.0,0.0);
//floor
glColor3f(0.5, 1.0, 0.0);
glVertex3f(-10.0,-0.5,10);
glVertex3f(-10.0,-0.5,-10);
glVertex3f(10.0,-0.5,-10);
glVertex3f(10.0,-0.5,10);
glEnd();
glPopMatrix();
glutSwapBuffers();
}
void update(int value) {
_angle += 4.0f;
if (_angle > 360) {
_angle -= 360;
}
glutPostRedisplay();
glutTimerFunc(25, update, 0);
}
int main(int argc, char** argv) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("Rotation Animation: Roll No.01");
initRendering();
//glutFullScreen();
glutDisplayFunc(drawScene);
glutKeyboardFunc(handleKeypress);glutSpecialFunc(handleSpecialKey);
glutReshapeFunc(handleResize);
glutTimerFunc(25,update,0);
glutPassiveMotionFunc(motionPassive);
glutMainLoop();
return 0;
}
