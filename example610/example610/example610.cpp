// example610.cpp: определяет точку входа для консольного приложения.
// example61.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <iostream>

#include	"GLUT.H"
#include	"Glaux.h"
#include	<stdio.h>
#include	<math.h>

float	angle = 0.0f;
float	angle2 = 0.0f;
float	d = 3.0f / (float)sqrt(3.0f);

float	lightAmb[] = { 0,  0.3, 0 };
float	lightDif[] = { 0,  0.7, 0.5 };
float	lightPos[] = { 1,  1,   1, 0 };

unsigned	      textureId = -1;
AUX_RGBImageRec * localTexture = NULL;

unsigned	      textureId2 = -1;
AUX_RGBImageRec * localTexture2 = NULL;

unsigned	      textureId3 = -1;
AUX_RGBImageRec * localTexture3 = NULL;

void    drawBox(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, GLfloat z1, GLfloat z2)
{
	glBindTexture(GL_TEXTURE_2D, textureId);
	


	glBegin(GL_POLYGON);         // front face
	glNormal3f(0.0, 0.0, 1.0);

	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z2);

	glTexCoord2f(1, 0);
	glVertex3f(x2, y1, z2);

	glTexCoord2f(1, 1);
	glVertex3f((x2+x1)/2, y2, (z2+z1)/2);

	//glTexCoord2f(0, 1);
	//glVertex3f(x1, y2, z2);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureId2);
	glBegin(GL_POLYGON);         // back face
	glNormal3f(0.0, 0.0, -1.0);

	glTexCoord2f(1, 0);
	glVertex3f(x2, y1, z1);

	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1);

	glTexCoord2f(0, 1);
	glVertex3f((x1+x2)/2, y2, (z1+z2)/2);

	//glTexCoord2f(1, 1);
	//glVertex3f(x2, y2, z1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, textureId3);
	glBegin(GL_POLYGON);         // left face
	glNormal3f(-1.0, 0.0, 0.0);

	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1);

	glTexCoord2f(0, 1);
	glVertex3f(x1, y1, z2);

	glTexCoord2f(1, 1);
	glVertex3f((x1+x2)/2, y2, (z2+z1)/2);

	//glTexCoord2f(1, 0);
	//glVertex3f(x1, y2, z1);
	glEnd();

	glBegin(GL_POLYGON);         // right face
	glNormal3f(1.0, 0.0, 0.0);

	glTexCoord2f(0, 1);
	glVertex3f(x2, y1, z2);

	glTexCoord2f(0, 0);
	glVertex3f(x2, y1, z1);

	glTexCoord2f(1, 0);
	glVertex3f((x2+x1)/2, y2, (z1+z2)/2);

	//glTexCoord2f(1, 1);
	//glVertex3f(x2, y2, z2);
	glEnd();

//	glBegin(GL_POLYGON);         // top face
//	glNormal3f(0.0, 1.0, 0.0);

	//glTexCoord2f(0, 1);
	//glVertex3f(x1, y2, z2);

	//glTexCoord2f(1, 1);
	//glVertex3f(x2, y2, z2);

	//glTexCoord2f(1, 0);
	//glVertex3f(x2, y2, z1);

	//glTexCoord2f(0, 0);
	//glVertex3f(x1, y2, z1);
	//glEnd();

	glBegin(GL_POLYGON);         // bottom face
	glNormal3f(0.0, -1.0, 0.0);

	glTexCoord2f(1, 1);
	glVertex3f(x2, y1, z2);

	glTexCoord2f(1, 0);
	glVertex3f(x1, y1, z2);

	glTexCoord2f(0, 0);
	glVertex3f(x1, y1, z1);

	glTexCoord2f(1, 0);
	glVertex3f(x2, y1, z1);
	glEnd();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//	glShadeModel ( GL_FLAT );					
	//	glLightfv    ( GL_LIGHT0, GL_AMBIENT,  lightAmb );	// Set The Ambient Lighting For Light0
	//	glLightfv    ( GL_LIGHT0, GL_DIFFUSE,  lightDif );	// Set The Diffuse Lighting For Light0
	//	glLightfv    ( GL_LIGHT0, GL_POSITION, lightPos );	// Set The Position For Light0

	//	glEnable ( GL_LIGHT0 );								// Enable Light 0
	//	glEnable ( GL_LIGHTING );							// Enable Lighting
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}

void	animate()
{
	angle += 0.75f;	// * glutGet ( GLUT_ELAPSED_TIME );
	angle2 += 0.1f;

	glutPostRedisplay();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 3.0, 3.0,		// eye new 0
		1.5, 1.5, 1.5,		// center new 0
		0, 1, 0);		// up


	//glTranslatef(4, 4, 4);
	//glRotatef(angle2, 1, -1, 0);
	//glTranslatef(d - 1.5f, d - 1.5f, d - 1.5f);

	glTranslatef(1.5f, 1.5f, 1.5f);			// move cube from the center
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(-1.5f, -1.5f, -1.5f);		// move cube into the center

	drawBox(1, 2, 1, 2, 1, 2);

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3.0, 3.0, 3.0,		// eye new 0
		1.5, 1.5, 1.5,		// center new 0
		0.0, 1.0, 0.0);
}

void key(unsigned char key, int x, int y)
{
	if (key == 27 || key == 'q' || key == 'Q')		//quit requested
		exit(0);
}

int main(int argc, char ** argv)
{
	//initialise glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	// create window
	int	glWin = glutCreateWindow("OpenGL example 6");

	init();
	// register handlers
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutIdleFunc(animate);

	// load texture
	localTexture = auxDIBImageLoad(L"FASAD1.BMP");
	//localTexture = auxDIBImageLoad((LPCWSTR)"..\\Textures\\block.bmp");
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);							// set 1-byte alignment
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture to repeat mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, 3, localTexture->sizeX,
		localTexture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
		localTexture->data);

	// load texture
	localTexture = auxDIBImageLoad(L"FASAD2.BMP");
	//localTexture = auxDIBImageLoad((LPCWSTR)"..\\Textures\\block.bmp");
	glGenTextures(1, &textureId2);
	glBindTexture(GL_TEXTURE_2D, textureId2);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);							// set 1-byte alignment
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture to repeat mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, 3, localTexture->sizeX,
		localTexture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
		localTexture->data);

	// load texture
	localTexture = auxDIBImageLoad(L"FASAD3.BMP");
	//localTexture = auxDIBImageLoad((LPCWSTR)"..\\Textures\\block.bmp");
	glGenTextures(1, &textureId3);
	glBindTexture(GL_TEXTURE_2D, textureId3);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);							// set 1-byte alignment
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture to repeat mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	glTexImage2D(GL_TEXTURE_2D, 0, 3, localTexture->sizeX,
		localTexture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
		localTexture->data);

	glutMainLoop();

	return 0;
}

