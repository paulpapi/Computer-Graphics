#include <GL/freeglut.h>
#include<iostream>
using namespace std;
void cube();
void polygon(int , int , int ,int );
float roty=0;
float rotx=0;
float rotz=0;
GLfloat vertices[][3]={{-1.0,-1.0,1.0},{-1.0,1.0,1.0},
{1.0,1.0,1.0},{1.0,-1.0,1.0},{-1.0,-1.0,-1.0},{-1.0,1.0,-1.0},
{1.0,1.0,-1.0},{1.0,-1.0,-1.0}};
GLfloat colors[][3]={{1,0,0},{0,1,1},{1,1,0},{0,1,0},
{0,0,1},{1,0,1}};
void keypress(int key, int x, int y){
 if(key==GLUT_KEY_UP){
  roty+=10;
 }
    if(key==GLUT_KEY_RIGHT){
  rotx+=5;
 }
  if(key==GLUT_KEY_LEFT){
  rotz+=5;
 }
 glutPostRedisplay();
}
void myinit()
{
    glClearColor(0.0,0.0,0.0,0.0);
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,1,1,0,0,0,0.0,-1.0,0.0);
   // glRotatef(-roty,0,1,0);
// glRotatef(rotz,0,0,1);
    cube();
    glutSwapBuffers();
}
void polygon(int a, int b, int c,int d){
  glColor3fv(colors[a]);
  glBegin(GL_POLYGON); 
  glVertex3fv(vertices[a]);
  glVertex3fv(vertices[b]);
  glVertex3fv(vertices[c]);
  glVertex3fv(vertices[d]);
 glEnd();
}
void cube()
{
  glRotatef(rotx,1,0,0);
 glRotatef(-roty,0,1,0);
 glRotatef(rotz,0,0,1);
    polygon(0,3,2,1);
  polygon(2,3,7,6);
  polygon(3,0,4,7);
  polygon(1,2,6,5);
 polygon(4,5,6,7);
  polygon(5,4,0,1);
}
void reshape(int w, int h){
 glViewport(0,0,w,h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-5.0,5.0,-5.0,5.0,-10.0,10.0);

}
int main(int argc, char** argv) {
    glutInit( &argc, argv );
       glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
       
       glutInitWindowSize( 500, 500 );
       glutCreateWindow( "CUBE" );
       glutReshapeFunc(reshape);
       glutDisplayFunc( display );
       glutSpecialFunc(keypress);
       glEnable(GL_DEPTH_TEST);
       myinit();
       glutMainLoop();
    return 0;
    }
#include <GL/glut.h>
void display();
float T;
void  MyInit();
void Spin(){
    T=T+0.5;
    if(T>360)
     T=0;
       glutPostRedisplay();
   }
   int main(int argc, char* argv[]){
       glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
       glutInitWindowSize(640, 480);
       glutCreateWindow("Animation");
      MyInit();
   
       glutDisplayFunc(display);
       
     glutIdleFunc(Spin);
   glutMainLoop();    
   }
   void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(1,2,3,0,0,0,0,1,0);
glutSolidCube(1);
    glTranslatef(0.2,0.7,0.2);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void MyInit(){
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   }