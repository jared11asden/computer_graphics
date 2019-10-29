#include "SDL.h"
#include <windows.h>   // use as needed for your system
#include <gl/Gl.h>
#include <gl/glu.h>
#include <gl/glut.h>

Scene scn;	// the scene object

float screenWidth = 640, screenHeight = 480;
float R = screenWidth / screenHeight;  // Global Aspect Ratio

void myDisplay()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt = 1.0;
	glOrtho(-winHt * 64 / 48, winHt * 64 / 48, -winHt, winHt, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3, 1.3, 2, 0, 0.25, 0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scn.drawSceneOpenGL();
	glEnd();
	glFlush();

}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("castle");
	glutDisplayFunc(myDisplay);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glViewport(0, 0, 640, 480);

	scn.read("myScene.DAT");
	glEnable(GL_LIGHTING);
	scn.makeLightsOpenGL();
	glutMainLoop();
}





