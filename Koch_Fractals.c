#include <GL/glut.h>
#include <windows.h>
#include <gl/gl.h>
#include<math.h>

GLfloat oldx=-0.7;
GLfloat oldy=0.5;

void drawKoch(GLfloat dir,GLfloat len,GLint iter){
GLdouble dirRad=0.01174533*dir;
GLfloat newX=oldx+len*cos(dirRad);
GLfloat neewY=oldy+len*sin(dirRad);

if(iter==0){
    glVertex2f(oldx,oldy);
    glVertex2f(newX,newY);
    oldx=newX;
    oldy=newY;
}
else {
    iter--;
    drawKoch(dir,len,iter);
    dir+=60.0;
    drawKoch(dir,len,iter);
    dir-=120.0;
    drawKoch(dir,len,iter);
    dir+=60.0;
    drawKoch(dir,len,iter);
}
}
void myDisplay(){
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glColor3f(1.0f,0.0f,0.0f);

drawKoch(0.0,0.05,3);
drawKoch(-120.0,0.05,3);
drawKoch(120.0,0.05,3);
glEnd();
glFlush();
}

int main(argc,char** argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Koch Snowflake");
glutDisplayFunc(myDisplay);
glutMainLoop();
}

