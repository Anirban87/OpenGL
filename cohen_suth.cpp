#include <GL/glut.h>
#include <GL/freeglut.h>
#include<stdio.h>
int a=0;
int x1,y1;
int x2,y2;
int x1n,y1n;
int x2n,y2n;
int i;
int xmin=125,xmax=375;
int ymin=125,ymax=375;
float arr[4][2];
float r[4];
float max=0.0;
float t1,t2;
float min=1.0;
void drawPoint(int x,int y);
void drawLine();
void drawLineNew();

void plot(int x,int y)
{
glColor3f(1,1,1);
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
void name()
{
  char sap[10] = {'5','0','0','0','4','0','3','9','9'};
  char name[] = {'A','N','I','R','B','A','N'};
glColor3f(1.0,1.0,1.0);
glRasterPos2f(70,420);
for (int i=0;i<10;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,sap[i]);
glRasterPos2f(70,430);
for (int i=0;i<6;i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,name[i]);
}
void box(){
//glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);glColor3f(1.0,1.0,0.0);
glVertex2f(60.0,440.0);
glVertex2f(60.0,410.0);
glVertex2f(150.0,410.0);
glVertex2f(150.0,440.0);
glEnd();
//glFlush();
}
void box1(){
//glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex2f(150,440.0);
glVertex2f(150,410.0);
glVertex2f(240.0,410.0);
glVertex2f(240.0,440.0);
glEnd();
//glFlush();
}



void clipLine();
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	    glVertex2f(125,125);
	    glVertex2f(375,125);
	    glVertex2f(375,375);
	    glVertex2f(125,375);
	glEnd();
	printf("in display");
	
	box();
name(); box1();
	
	glFlush();
}
void drawPoint(int x,int y)
{
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
    glFlush();
}
void drawLine()
{
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    printf("in drawLine");
    glFlush();
}
void mouse(int btn, int state, int x, int y)
{
    if( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) 
    {   
        if(a==3)
        {   
            clipLine();
        }
        if(a==2)
        {   
            a++;
            drawLine();
        }
        else if(a==1)
        {
            x2=x;
            y2=500-y;
            printf(" %d %d ",x2,y2);
            a++;
            drawPoint(x2,y2);
        }
        else if(a==0)
        {
            x1=x;
            y1=500-y;
            printf(" %d %d ",x1,y1);
            a++;
            drawPoint(x1,y1);
        }
    }
    
}
void drawLineNew()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);
	printf("in drawline new");
	glColor3f(1,1,1);
	glBegin(GL_LINE_LOOP);
	    glVertex2f(125,125);
	    glVertex2f(375,125);
	    glVertex2f(375,375);
	    glVertex2f(125,375);
	glEnd();
	glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(x1n,y1n);
        glVertex2f(x2n,y2n);
    glEnd();
    glFlush();
}
	
void clipLine()
{
    int tep;
    arr[0][0]=x1-x2;
    arr[0][1]=x1-xmin;
    arr[1][0]=x2-x1;
    arr[1][1]=xmax-x1;
    arr[2][0]=y1-y2;
    arr[2][1]=y1-ymin;
    arr[3][0]=y2-y1;
    arr[3][1]=ymax-y1;
    
    for(int p=0;p<4;p++)
    {
        for(int t=0;t<2;t++)
        {
            printf("  %f,  ",arr[p][t]);
        }
    }
    //scanf("%d",&tep);
    if(arr[0][0]==0 || arr[1][0]==0)
    {
        if(arr[0][1]<0 || arr[1][1]<0)
        {
            display();
        }
       /* else if(arr[1][1]<0)
        {
            display();
        }*/
        else if(arr[0][1]>0 || arr[1][1]>0)
        {
            drawLine();
        }
       /* else if(arr[1][1]>0)
        {
            drawLine();
        }*/
    }
     else if(arr[2][0]==0 || arr[3][0]==0)
    {
        if(arr[2][1]<0)
        {
           display();
        }
        else if(arr[3][1]<0)
        {
            display();
        }
        else if(arr[2][1]>0)
        {
            drawLine();
        }
        else if(arr[3][1]>0)
        {
            drawLine();
        }
    }
    else if(arr[0][0]<0 || arr[1][0]<0 || arr[2][0]<0 || arr[3][0]<0)
    {
        for(i=0;i<4;i++)
        {
            if(arr[i][0]<0)
            {
                r[i]=(float)arr[i][1]/arr[i][0];
                printf("%f",r[i]);
                if(r[i]>max)
                {
                    max=r[i];
                 }
            }
                
        }
       t1=max;
       printf("*%f*",t1);
      // scanf("%d",&t1);
    }
    if(arr[0][0]>0 || arr[1][0]>0 || arr[2][0]>0 || arr[3][0]>0)
    {
        printf("********");
        for(i=0;i<4;i++)
        {
            printf(",,,,,,,,");
            if(arr[i][0]>0)
            {
                printf("in elseif");
                r[i]=(float)arr[i][1]/arr[i][0];
                if(r[i]<min)
                {
                    min=r[i];
                 }
            }
                
        }
       t2=min;
       printf("!%f!",t2);
       //scanf("%f",&t2);
       
    }
    if(t1>t2)
       {
            display();
       }
    
    if(arr[0][0]!=0 && arr[1][0]!=0 && arr[2][0]!=0 && arr[3][0]!=0)
    {
        x1n=x1+t1*(x2-x1);
        y1n=y1+t1*(y2-y1);
        x2n=x1+t2*(x2-x1);
        y2n=y1+t2*(y2-y1);
        printf(" %d %d %d %d ",x1n,y1n,x2n,y2n); 
        //scanf("%d",&tep);
    
        drawLineNew();
    }
}
    
            
int main(int argc, char** argv)
{
	glutInit(&argc, argv);           
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);    
   	glutCreateWindow("Line Clipping");
   	gluOrtho2D(0,500,0,500);
    glutDisplayFunc(display); 
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
