// #include loads up library files, the order can matter
// generally load glut.h last
#include <stdio.h>  // this library is for standard input and output
#include <math.h>
#include <stdlib.h>
#include "glut.h"
#include <functional>

int refreshmill = 1;
float angle1 = 0.0;
float angle2 = 0.0;
float xt = 0.0;
float man = 0;
int counter = 0;

float sx1 = 0.02; //scale box
float sy1 = 0.02;

int frame = 0;
int first[20][2];
int roof[20][2];
int roof2[7][2];

int sq[10][2];
int D[16][2];
int tweenPoly[20][2];
int arrow[10][2];
int tweenCar[30][2];
float proportion = 0.0;
//int mode;
void init() {
	glClearColor(0.196078, 0.6, 0.8, 1.0);
	// set what colour you want the background to be
	glMatrixMode(GL_PROJECTION); // set the matrix mode, we will look at this later
								 // set the projection window size in x an y. Window will then
								 // be mapped to the window created in the main function
	gluOrtho2D(0.0, 800, 0.0, 600.0);
	//FINAL CAR
	first[0][0] = 300;
	first[0][1] = 150;
	first[1][0] = 2;
	first[1][1] = 150;
	first[2][0] = 2;
	first[2][1] = 150;
	first[3][0] = 2;
	first[3][1] = 200;
	first[4][0] = 2;
	first[4][1] = 200;
	first[5][0] = 300;
	first[5][1] = 200;
	first[6][0] = 300;
	first[6][1] = 200;
	first[7][0] = 300;
	first[7][1] = 150;
	//TOP CAR ROOF
	roof2[0][0] = 100;
	roof2[0][1] = 200;
	roof2[1][0] = 100;
	roof2[1][1] = 220;
	roof2[2][0] = 120;
	roof2[2][1] = 250;
	roof2[3][0] = 180;
	roof2[3][1] = 250;
	roof2[4][0] = 200;
	roof2[4][1] = 220;
	roof2[5][0] = 200;
	roof2[5][1] = 200;
	roof2[6][0] = 100;
	roof2[6][1] = 200;

	tweenCar[0][0] = 300;
	tweenCar[0][1] = 150;
	tweenCar[1][0] = 2;
	tweenCar[1][1] = 150;
	tweenCar[2][0] = 2;
	tweenCar[2][1] = 200;
	tweenCar[3][0] = 100;
	tweenCar[3][1] = 200;
	tweenCar[4][0] = 100;
	tweenCar[4][1] = 220;
	tweenCar[5][0] = 120;
	tweenCar[5][1] = 250;
	tweenCar[6][0] = 180;
	tweenCar[6][1] = 250;
	tweenCar[7][0] = 200;
	tweenCar[7][1] = 220;
	tweenCar[8][0] = 200;
	tweenCar[8][1] = 200;
	tweenCar[9][0] = 300;
	tweenCar[9][1] = 200;

	arrow[0][0] = 50;
	arrow[0][1] = 200;
	arrow[1][0] = 150;
	arrow[1][1] = 100;
	arrow[2][0] = 150;
	arrow[2][1] = 180;
	arrow[3][0] = 400;
	arrow[3][1] = 180;
	arrow[4][0] = 450;
	arrow[4][1] = 100;
	arrow[5][0] = 425;
	arrow[5][1] = 200;
	arrow[6][0] = 450;
	arrow[6][1] = 300;
	arrow[7][0] = 400;
	arrow[7][1] = 220;
	arrow[8][0] = 150;
	arrow[8][1] = 220;
	arrow[9][0] = 150;
	arrow[9][1] = 300;
	arrow[0][0] = 50;
	arrow[0][1] = 200;
}

GLfloat vertices[8][3] =
{ { 150.0, 150.0, 0.0 },{ 150.0, 150.0, 0.0 },{ 150.0, 150.0, 0.0 },{ 150.0, 150.0, 0.0 },//Back
{ 100.0, 100.0, 100.0 },{ 200.0, 100.0, 100.0 },{ 200.0, 200.0, 100.0 },{ 100.0, 200.0, 100.0 } };

GLfloat colors[8][3] =
{ { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },
{ 1.00, 0.11, 0.68 },{ 0.0, 1.0, 0.0 },{ 0.0, 0.0, 1.0 },
{ 1.0, 0.0, 1.0 },{ 1.0, 0.5, 0.0 },{ 0.0, 1.0, 1.0 } };
GLfloat theta[3] = { 0.0, 0.0, 0.0 };
GLfloat delta = 2.0;
GLint axis = 2;
void drawcar() {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <20; i++) {
		glVertex2i(tweenCar[i][0], tweenCar[i][1]);// scene 1
	}
	glEnd();
}


void face(int a, int b, int c, int d)
{
	//glClearColor(0.0, 1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	//cube
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}

////3D  draw a 3d cube with differnet couopured faces
void colorcube(void)
{
	/* map vertices to faces */
	/* note consistent orientation */
	glColor3fv(colors[1]);
	face(0, 3, 2, 1);
	glColor3fv(colors[2]);
	face(2, 3, 7, 6);
	glColor3fv(colors[3]);
	face(0, 4, 7, 3);
	glColor3fv(colors[4]);
	face(1, 2, 6, 5);
	glColor3fv(colors[5]);
	face(4, 5, 6, 7);
	glColor3fv(colors[6]);
	face(0, 1, 5, 4);
}

// this is the initialisation function, called once only
void circle(double radius, double xc, double yc)
{
	int i;
	double angle = 2 * 3.1415 / 20; // circle is drawn using 20 line.
	double circle_xy[40][2];
	circle_xy[0][0] = radius + xc;
	circle_xy[0][1] = yc;

	glBegin(GL_POLYGON);
	for (i = 1; i < 20; i++)
	{
		circle_xy[i][0] = radius * cos(i *angle) + xc;
		circle_xy[i][1] = radius * sin(i * angle) + yc;
		glVertex2f(circle_xy[i - 1][0], circle_xy[i - 1][1]);
		glVertex2f(circle_xy[i][0], circle_xy[i][1]);
	}
	glEnd();
}
void wheel1() {
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glLineWidth(5.0);
	glColor3f(0.0, 0.1, 0.0);
	glLineWidth(2.0);
	circle(30, 95, 150); // how big/small, pos x, pos y
}
void wheel2() {
	glColor3f(0.0, 0.1, 0.0);
	glLineWidth(2.0);
	circle(30, 200, 150);// how big/small, pos x, pos y
}

void floor()
{
	//Floor
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);// road color scene 1
	glVertex3i(-2400, 0, 0);
	glVertex3i(3600, 0, 0);
	glVertex3i(3600, 0, 500);
	glVertex3i(-2400, 0, 500);
	glColor3f(0.4, 0.4, 0.4);// door color scene 2
	glVertex3i(-1200, 120, 0);
	glVertex3i(2480, 120, 0);
	glVertex3i(2480, 160, 0);
	glVertex3i(-1200, 160, 0);
	glEnd();
}

void axle()
{
	glBegin(GL_LINES);
	glVertex2d(210.0, 170.0);//new front square
	glVertex2d(220.0, 170.0);
	glVertex2d(220.0, 170.0);
	glVertex2d(220.0, 160.0);
	glVertex2d(220.0, 160.0);
	glVertex2d(210.0, 160.0);
	glVertex2d(210.0, 160.0);
	glVertex2d(210.0, 170.0);
	glVertex2d(195.0, 155.0);//middle front square
	glVertex2d(205.0, 155.0);//Top line
	glVertex2d(205.0, 155.0);
	glVertex2d(205.0, 145.0);
	glVertex2d(205.0, 145.0);
	glVertex2d(195.0, 145.0);
	glVertex2d(195.0, 145.0);
	glVertex2d(195.0, 155.0);
	glEnd();
}

void axle2()
{
	glBegin(GL_LINES);
	glVertex2d(90.0, 155.0);//back square
	glVertex2d(100.0, 155.0);
	glVertex2d(100.0, 155.0);
	glVertex2d(100.0, 145.0);
	glVertex2d(100.0, 145.0);
	glVertex2d(90.0, 145.0);
	glVertex2d(90.0, 145.0);
	glVertex2d(90.0, 155.0);

	glVertex2d(105.0, 170.0);
	glVertex2d(115.0, 170.0);
	glVertex2d(115.0, 170.0);
	glVertex2d(115.0, 160.0);
	glVertex2d(115.0, 160.0);
	glVertex2d(105.0, 160.0);
	glVertex2d(105.0, 160.0);
	glVertex2d(105.0, 170.0);
	glEnd();
}

void face(float ref) {
	glColor3f(0.0, 0.1, 0.0);
	glLineWidth(2.0);
	circle(10, 150 + ref, 250);
}

void body1(float ref) { //wave down
	glBegin(GL_LINES);
	//down wave body
	glVertex2d(150.0 + ref, 225.0);//mid 
	glVertex2d(130.0 + ref, 200.0);
	glVertex2d(150.0 + ref, 225.0);//mid
	glVertex2d(170.0 + ref, 200.0);//left leg and arm
	glVertex2d(150.0 + ref, 200.0);//line
	glVertex2d(150.0 + ref, 240.0);// joining line to circle
	glVertex2d(150.0 + ref, 200.0);//left leg
	glVertex2d(140.0 + ref, 160.0);
	glVertex2d(150.0 + ref, 200.0);
	glVertex2d(160.0 + ref, 160.0);
	glEnd();
}

void body2(float ref) {//wave up
	glBegin(GL_LINES);
	//up wave body
	glVertex2d(150.0 + ref, 225.0);//mid 
	glVertex2d(130.0 + ref, 250.0);
	glVertex2d(150.0 + ref, 225.0);//mid
	glVertex2d(170.0 + ref, 200.0);
	glVertex2d(150.0 + ref, 200.0);//line
	glVertex2d(150.0 + ref, 240.0);// joining line to circle
	glVertex2d(150.0 + ref, 200.0);//right leg
	glVertex2d(140.0 + ref, 160.0);
	glVertex2d(150.0 + ref, 200.0);
	glVertex2d(160.0 + ref, 160.0);
	glEnd();
}
void bodywalk(float ref) {
	glBegin(GL_LINES);

	glVertex2d(150.0 + ref, 225.0);//left arm 
	glVertex2d(145.0 + ref, 200.0);
	glVertex2d(150.0 + ref, 225.0);//right arm
	glVertex2d(155.0 + ref, 200.0);//left leg and arm
	glVertex2d(150.0 + ref, 200.0);//line
	glVertex2d(150.0 + ref, 240.0);// joining line to circle
	glVertex2d(150.0 + ref, 200.0);//right leg
	glVertex2d(145.0 + ref, 160.0);
	glVertex2d(150.0 + ref, 200.0);//left leg
	glVertex2d(155.0 + ref, 160.0);
	glEnd();
}
void boxsq() {
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2d(400.0, 150.0);
	glVertex2d(400.0, 300.0);
	glVertex2d(500.0, 300.0);
	glVertex2d(500.0, 150.0);
	glEnd();
}

void scene3() {
	glColor3f(0.0, 0.1, 0.0);// line color scene 3
	glLineWidth(2.0);
	circle(10, 150, 250);
	glBegin(GL_LINES);
	glVertex2i(150, 225);//mid 
	glVertex2i(130, 200);
	glVertex2i(150, 225);//mid
	glVertex2i(170, 200);
	glVertex2i(150, 200);//line
	glVertex2i(150, 240);// joining line to circle
	glEnd();
}
void star() {
	glColor3f(0.0, 0.0, 0.0);// line star scene 3
	glLineWidth(4.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(100, 250);//0
	glVertex2i(200, 400);//1
	glVertex2i(100, 550);//2
	glVertex2i(250, 550);//3
	glVertex2i(300, 700);//4
	glVertex2i(350, 550);//5
	glVertex2i(550, 550);//6
	glVertex2i(400, 400);//7
	glVertex2i(500, 250);//8
	glVertex2i(300, 350);//9
	glVertex2i(100, 250);//10
	glEnd();
	glColor3f(1.0, 1.0, 0.1);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 250);//0
	glVertex2i(200, 400);//1
	glVertex2i(300, 350);//9
	glEnd();
	glColor3f(1.0, 1.0, 0.1);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(100, 550);//2
	glVertex2i(250, 550);//3
	glVertex2i(200, 400);//1
	glEnd();
	glColor3f(1.0, 1.0, 0.1);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(300, 700);//4
	glVertex2i(350, 550);//5
	glVertex2i(250, 550);//3
	glEnd();
	glColor3f(1.0, 1.0, 0.1);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(550, 550);//6
	glVertex2i(400, 400);//7
	glVertex2i(350, 550);//5
	glEnd();
	glColor3f(1.0, 1.0, 0.1);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(500, 250);//8
	glVertex2i(300, 350);//9
	glVertex2i(400, 400);//7
	glEnd();
	glColor3f(1.0, 1.0, 0.1);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(400, 400);//7
	glVertex2i(300, 350);//9
	glVertex2i(200, 400);//1
	glVertex2i(250, 550);//3
	glVertex2i(350, 550);//5
	glEnd();
}
void scalebox() {
	glPushMatrix();
	glTranslatef(150.0, 225.0, 0.0);
	glScalef(sx1, sy1, 0.0);
	glTranslatef(-150.0, -225.0, 0.0);
	star();
	glPopMatrix();
	sx1 = sx1 * 1.01;//scaling scene 3
	sy1 = sy1 * 1.01;
}
void viewports() {
	glViewport(-300, 0, 550, 500);//scene 3 viewport
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);//left human 2.2
	scalebox();
	scene3();
	glPopMatrix();
	glViewport(200, 0, 550, 500);
	glPushMatrix();
	glScalef(1.5, 1.5, 1.5);//right human 2.2
	scalebox();
	scene3();
	glPopMatrix();
}
void tween(int source[10][2], int destination[10][2], int numPoints, double proportion, int tweenPoly[10][2])
{
	for (int p = 0; p < numPoints; p++)
	{
		// get the source point
		double sourceX = source[p][0];
		double sourceY = source[p][1];
		// get the destination point
		double destinationX = destination[p][0];
		double destinationY = destination[p][1];
		// get the difference between source and destination
		double differenceX = (destinationX - sourceX);
		double differenceY = (destinationY - sourceY);
		// tween point is source position + proportion
		// of distance between source and destination
		double tweenX = sourceX + (differenceX * proportion);
		double tweenY = sourceY + (differenceY * proportion);
		// create point with tween co-ordinates in tween array
		tweenPoly[p][0] = int(tweenX);
		tweenPoly[p][1] = int(tweenY);
	}

}
void renderSpacedBitmapString(float x, float y, void *font, char *string) {
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
		glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c);
	}
}

void init3D(int w, int h)
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	///3d these parameters are left, right bottom, top, Znear clipping  distance , zfar clipping distance
	glOrtho(-200.0, 200.0, -200.0, 200.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}
void main1() {
	//perform the GLUT initialization
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	init(); // call init function defined above
	glDisable(GL_DEPTH_TEST);
}
void main2()
{
	////3D this turns on double buffereing and depth testing
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	init3D(500, 500);
	glEnable(GL_DEPTH_TEST);

}
void bodyMove() {
	glLoadIdentity();
	glTranslatef(xt, 0.0, 0.0);
	//glTranslatef(move, 0.0, 0.0);
	glPushMatrix();
	//glTranslatef(200.0, 150.0, 0.0);
	glRotatef(3, 0.0, 0.0, 1.0);//front square
	glTranslatef(-200.0, -150.0, 0.0);
	body2(250 - xt);
	glPopMatrix();
	glPushMatrix();
	//glTranslatef(95.0, 150.0, 0.0);
	glRotatef(3, 0.0, 0.0, 1.0);//back square
	glTranslatef(150.0, 200.0, 0.0);
	body2(250 - xt);
	glPopMatrix();
}
void car(float speed) {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <20; i++) {
		glVertex2i(first[i][0], first[i][1]);// scene 1
	}
	glEnd();
	wheel1();//back tyre
	wheel2();//front tyre
	glLoadIdentity();
	glTranslatef(speed, 0.0, 0.0);
	//glTranslatef(move, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(200.0, 150.0, 0.0);
	glRotatef(angle1, 0.0, 0.0, 1.0);//front square
	glTranslatef(-200.0, -150.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	axle();//Front tyre squares
	glPopMatrix();
	glPushMatrix();
	glTranslatef(95.0, 150.0, 0.0);
	glRotatef(angle1, 0.0, 0.0, 1.0);//back square
	glTranslatef(-95.0, -150.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	axle2();//Back tyre squares
	glPopMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 7; i++) {
		glVertex2i(roof2[i][0], roof2[i][1]);
	}
	glEnd();
}
void scene3car(float speed) {

	glEnd();
	wheel1();//back tyre
	wheel2();//front tyre
	glLoadIdentity();
	glTranslatef(speed, 0.0, 0.0);
	//glTranslatef(move, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(200.0, 150.0, 0.0);
	glRotatef(angle1, 0.0, 0.0, 1.0);//front square
	glTranslatef(-200.0, -150.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	axle();//Front tyre squares
	glPopMatrix();
	glPushMatrix();
	glTranslatef(95.0, 150.0, 0.0);
	glRotatef(angle1, 0.0, 0.0, 1.0);//back square
	glTranslatef(-95.0, -150.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	axle2();//Back tyre squares
	glPopMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glEnd();
}

// This is the display function it is called when ever you want to draw something
// all drawing should be called form here
void display(/*float move*/) {
	//int i;
	frame++;
	angle1 = angle1 - 7.0;// "-" to spin the wheels forward and "+" to move backward
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT); // clear the screen using the background colour
	glMatrixMode(GL_MODELVIEW); //glColor3f(0.0, 0.1, 0.0); // set colour to white
	if (frame < 100) {
		glViewport(0, 0, 800, 800);//Viewport 1
		glColor3f(0.0, 0.1, 0.0);
		xt += 7;
		floor();
		car(xt);
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Need Uber?"); // Add text on the scene
	}
	else if ((frame >= 100) && (frame < 125)) {
		if (frame == 100) {//in the next frame the car starts from 0 again
			xt = 0.0;
		}
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt);
		body1(300 - xt);//wave down (1)
						//body1();//wave down (1)
		floor();
		xt += 2.2;
		//floor();
		car(xt);
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Give us a call now!"); // Add text on the scene
	}
	else if ((frame >= 125) && (frame < 150)) {//150

		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt);
		body1(300 - xt);//wave down
						//car(xt);
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		//glTranslatef(move, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		//glRotatef(angle1, 0.0, 0.0, 1.0);//front square
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		//glRotatef(angle1, 0.0, 0.0, 1.0);//back square
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		//floor();
		//square();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 1.0);
		//drawcar();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "We will arrive to your destination fast!");
	}
	else if ((frame >= 150) && (frame < 175)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt);
		body2(300 - xt);// wave up
						//car(xt);
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		//glTranslatef(move, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		//glRotatef(angle1, 0.0, 0.0, 1.0);//front square
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		//glRotatef(angle1, 0.0, 0.0, 1.0);//back square
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		//floor();
		//square();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Choose the location you want to go to.");
	}
	else if ((frame >= 175) && (frame < 190)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		bodywalk(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		//glTranslatef(move, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		//glRotatef(angle1, 0.0, 0.0, 1.0);//front square
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		//glRotatef(angle1, 0.0, 0.0, 1.0);//back square
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		//floor();
		//square();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "We will take you there!");
	}
	//===========================
	else if ((frame >= 190) && (frame < 205)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		body1(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "We will take you there!");
	}
	else if ((frame >= 205) && (frame < 220)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		bodywalk(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "We will take you there!");
	}
	else if ((frame >= 220) && (frame < 235)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		body1(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "We will take you there!");
	}
	else if ((frame >= 235) && (frame < 250)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		bodywalk(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
	}
	else if ((frame >= 250) && (frame < 265)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		body1(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
	}
	else if ((frame >= 265) && (frame < 280)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		bodywalk(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
	}
	else if ((frame >= 280) && (frame < 300)) {
		glColor3f(0.0, 0.1, 0.0);
		face(300 - xt - frame + 175);
		body1(300 - xt - frame + 175);//wave down
		floor();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i <20; i++) {
			glVertex2i(first[i][0], first[i][1]);// scene 1
		}
		glEnd();
		wheel1();
		wheel2();
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);
		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 7; i++) {
			glVertex2i(roof2[i][0], roof2[i][1]);
		}
		glEnd();
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
	}
	//===============================
	else if ((frame >= 300) && (frame < 450)) {
		if (frame == 300) {//in the next fram the car starts from 0 again
			xt = 90.0;
		}
		glColor3f(0.0, 0.1, 0.0);
		floor();
		xt += 2.2;
		car(xt);
		glBegin(GL_LINES);
		for (int i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();
		glColor3f(0.0, 0.0, 0.0);
		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Comfortable Journey...");
	}
	else if ((frame > 450) && (frame < 550)) {
		glColor3f(0.0, 0.1, 0.0);
		viewports();
		glColor3f(0.0, 0.0, 1.0);
		tween(arrow, tweenCar, 10, proportion, tweenPoly);

		glBegin(GL_LINE_LOOP);
		scene3car(xt);
		for (int i = 0; i<10; i++)
			glVertex2i(tweenPoly[i][0], tweenPoly[i][1]);	// Morphing arrow into car.*/
		glColor3f(0.0, 0.0, 0.0);
		tween(arrow, tweenCar, 10, proportion, tweenPoly);

		glBegin(GL_LINE_LOOP);
		for (int i = 0; i<10; i++)
			glVertex2i(tweenPoly[i][0], tweenPoly[i][1]);
		glEnd();
		renderSpacedBitmapString(-50, 400, GLUT_BITMAP_HELVETICA_18, "G r e a t    F e e d b a c k !");


		proportion += 0.01;//third scene

		if (proportion > 1.0) proportion = 0.0;
	}
	else if (frame == 550) main2();

	else if ((frame > 550) && (frame < 1000))
	{
		/* clear frame buffer and z buffer,
		rotate cube and draw, swap buffers */
		glViewport(0, 0, 800.0, 800.0);
		glColor3fv(colors[1]);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		theta[axis] += delta;// 3D Pyramid spinning animation
		if (theta[axis] > 360.0) theta[axis] -= 360.0;

		renderSpacedBitmapString(-110, 10, GLUT_BITMAP_TIMES_ROMAN_24, "Check out the uber app!");
		glLoadIdentity();

		glRotatef(-100.0, -1.0, 0.0, 0.0);// -10
		glRotatef(-10, 0.0, -1.0, 0.0);
		glPushMatrix();
		//	///3D we can have a seperate rotation for each axis
		glRotatef(theta[0], 1.0, 0.0, 0.0);
		glRotatef(theta[1], 0.0, 1.0, 0.0);
		glRotatef(theta[2], 0.0, 0.0, 1.0);
		//	// translate object back to origin so it will rotate around its center
		glTranslatef(0.0, 0.0, 0.0);
		colorcube();
		glPopMatrix();
	}
	fprintf(stdout, "Frame number= %i\n", frame);
	glFlush();
	glutSwapBuffers();
}
void Timer(int value)
{
	if (value) glutPostRedisplay();
	glutTimerFunc(40, Timer, value);// the time of each animation scene
}
void visibility(int state)
{
	switch (state)
	{
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default:
		break;
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);  //perform the GLUT initialization
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // more initialisation
												 //float move = 0.0;
	glutInitWindowSize(800, 600); // set window position
								  //glutInitWindowPosition(100, 100); // set window size
	glutCreateWindow("Uber Advert"); // create a display with a given caption for the title bar
	init(); // call init function defined above
	glutDisplayFunc(display);
	glutVisibilityFunc(visibility);
	glutMainLoop();
	return 0;
}