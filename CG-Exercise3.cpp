#include <GL/freeglut.h>
GLfloat dx=1.0,dy=1.0,dz=1.0;
GLfloat light_pos[]={1.0,2.0,3.0,1.0};
GLfloat theta=0.0;

void renderScene(){
 theta+=2.0;
 if(theta>360) 
  theta-=360;
  glutPostRedisplay();
}
void init(){
    glEnable(GL_LIGHTING);
    glEnable (GL_LIGHT0);
   }
   void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluPerspective(80,640/480,1,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1,2,1,0,0,0,0,1,0);
    glPushMatrix();
    glRotatef(theta,dx,dy,dz);
    glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
    /*GLfloat qaAmbientLight[]={1,0,1,1.0};
    GLfloat qaDiffuseLight[]={0,1,1,1.0};
    GLfloat qaSpecularLight[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT,qaAmbientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,qaDiffuseLight);
       glLightfv(GL_LIGHT0,GL_SPECULAR,qaSpecularLight);
       glLightfv(GL_LIGHT0,GL_POSITION,light_pos);*/
    glPopMatrix();
    glutSolidCube(1);
    glutSwapBuffers();
    
   }
   int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lighting2");
    glutDisplayFunc(display);
    glutIdleFunc(renderScene);
    init();
    glutMainLoop();
    return 0;
   }