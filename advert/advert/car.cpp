// #include loads up library files, the order can matter
// generally load glut.h last
#include <stdio.h>  // this library is for standard input and output
#include <math.h>

#include <stdlib.h>
#include "glut.h"

//GLfloat angle = 45.0f;
int refreshmill = 1;
float angle1 = 0.0;
float angle2 = 0.0;
float xt = 0.0;


int counter = 0;
//int counterbreak = 100;
float tx = 0.0;
float ty = 0.0;
float sx = 1.0;
float sy = 1.0;
float sx1 = 0.3; //scale box
float sy1 = 0.3;
float rx = 0.0;
float ry = 0.0;
//int theta = 0;
int frame = 0;


int first[10][2];
int sq[10][2];
int D[16][2];
int tweenPoly[10][2];
float proportion = 0.0;

int mode;


void init() {
	glClearColor(0.0, 1.0, 1.0, 0.0); // set what colour you want the background to be
	glMatrixMode(GL_PROJECTION); // set the matrix mode, we will look at this later
								 // set the projection window size in x an y. Window will then
								 // be mapped to the window created in the main function
	gluOrtho2D(0.0, 800, 0.0, 600.0);

	first[0][0] = 200;
	first[0][1] = 150;

	first[1][0] = 95;
	first[1][1] = 150;

	first[2][0] = 200;
	first[2][1] = 150;

	first[3][0] = 200;
	first[3][1] = 210;

	first[4][0] = 195;
	first[4][1] = 210;

	first[5][0] = 210;
	first[5][1] = 210;

	sq[0][0] = 400;
	sq[0][1] = 150;

	sq[1][0] = 400;
	sq[1][1] = 300;

	sq[2][0] = 400;
	sq[2][1] = 300;

	sq[3][0] = 500;
	sq[3][1] = 300;

	sq[4][0] = 500;
	sq[4][1] = 300;

	sq[5][0] = 500;
	sq[5][1] = 150;

	sq[6][0] = 500;
	sq[6][1] = 150;

	sq[7][0] = 400;
	sq[7][1] = 150;



	D[0][0] = 400;
	D[0][1] = 500;

	D[1][0] = 350;
	D[1][1] = 350;

	D[2][0] = 350;
	D[2][1] = 350;

	D[3][0] = 300;
	D[3][1] = 300;

	D[4][0] = 300;
	D[4][1] = 300;

	D[5][0] = 350;
	D[5][1] = 300;

	D[6][0] = 350;
	D[6][1] = 300;

	D[7][0] = 400;
	D[7][1] = 200;

	D[8][0] = 400;
	D[8][1] = 200;

	D[9][0] = 450;
	D[9][1] = 300;

	D[10][0] = 450;
	D[10][1] = 300;

	D[11][0] = 500;
	D[11][1] = 300;

	D[12][0] = 500;
	D[12][1] = 300;

	D[13][0] = 450;
	D[13][1] = 350;

	D[14][0] = 450;
	D[14][1] = 350;

	D[15][0] = 400;
	D[15][1] = 500;

}



GLfloat vertices[8][3] =
{ { 100.0, 100.0, 0.0 },{ 200.0, 100.0, 0.0 },{ 200.0, 200.0, 0.0 },{ 100.0, 200.0, 0.0 },
{ 100.0, 100.0, 100.0 },{ 200.0, 100.0,100.0 },{ 200.0, 200.0, 100.0 },{ 100.0, 200.0, 100.0 } };

/* colors to be assigned to edges */
GLfloat colors[8][3] =
{ { 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },
{ 1.0, 1.0, 0.0 },{ 0.0, 1.0, 0.0 },{ 0.0, 0.0, 1.0 },
{ 1.0, 0.0, 1.0 },{ 1.0, 1.0, 1.0 },{ 0.0, 1.0, 1.0 } };

GLfloat theta[3] = { 0.0, 0.0, 0.0 };
GLfloat delta = 10.0;
GLint axis = 2;


void face(int a, int b, int c, int d)
{
	//glClearColor(0.0, 1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
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
	double angle = 2 * 3.1415 / 20;	// circle is drawn using 20 line.
	double circle_xy[40][2];

	circle_xy[0][0] = radius + xc;
	circle_xy[0][1] = yc;


	glBegin(GL_LINE_LOOP);
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
	circle(30, 95, 150);

}

void wheel2() {
	glColor3f(0.0, 0.1, 0.0);
	glLineWidth(2.0);
	circle(30, 200, 150);

}



void flash() {

	if (counter % 2 == 0)
		glClearColor(1.0, 1.0, 1.0, 0.0);
	else
		glClearColor(0.0, 0.0, 0.0, 0.0);

}


void floor()
{
	//Floor
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.4, 0.2);
	glVertex3i(-2400, 0, 0);
	glVertex3i(3600, 0, 0);
	glVertex3i(3600, 0, 500);
	glVertex3i(-2400, 0, 500);

	glColor3f(0.4, 0.4, 0.4);
	glVertex3i(-1200, 120, 0);
	glVertex3i(2480, 120, 0);
	glVertex3i(2480, 160, 0);
	glVertex3i(-1200, 160, 0);

	glEnd();

}



void axle()
{
	glBegin(GL_LINES);
	glVertex2d(210.0, 170.0);//new
	glVertex2d(220.0, 170.0);
	glVertex2d(220.0, 170.0);
	glVertex2d(220.0, 160.0);

	glVertex2d(220.0, 160.0);
	glVertex2d(210.0, 160.0);
	glVertex2d(210.0, 160.0);
	glVertex2d(210.0, 170.0);

	glVertex2d(195.0, 155.0);
	glVertex2d(205.0, 155.0);
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
	glVertex2d(90.0, 155.0);
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

void first1() {
	glBegin(GL_LINES);

	glVertex2d(200.0, 150.0);
	glVertex2d(95.0, 150.0);

	glVertex2d(200.0, 150.0);
	glVertex2d(200.0, 210.0);

	glVertex2d(195.0, 210.0);
	glVertex2d(210.0, 210.0);



	glEnd();
}

void face() {
	glColor3f(0.0, 0.1, 0.0);
	glLineWidth(2.0);
	circle(10, 150, 250);
}


void body1() {
	glBegin(GL_LINES);

	glVertex2d(150.0, 225.0);//mid	
	glVertex2d(130.0, 200.0);
	glVertex2d(150.0, 225.0);//mid
	glVertex2d(170.0, 200.0);
	glVertex2d(150.0, 200.0);//line
	glVertex2d(150.0, 240.0);// joining line to circle

	glVertex2d(150.0, 200.0);//leg
	glVertex2d(140.0, 160.0);
	glVertex2d(150.0, 200.0);
	glVertex2d(160.0, 160.0);

	glEnd();
}



void body2() {
	glBegin(GL_LINES);

	glVertex2d(150.0, 225.0);//mid	
	glVertex2d(130.0, 250.0);
	glVertex2d(150.0, 225.0);//mid
	glVertex2d(170.0, 250.0);
	glVertex2d(150.0, 200.0);//line
	glVertex2d(150.0, 240.0);// joining line to circle

	glVertex2d(150.0, 200.0);//leg
	glVertex2d(140.0, 160.0);
	glVertex2d(150.0, 200.0);
	glVertex2d(160.0, 160.0);

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
	glColor3f(0.0, 0.1, 0.0);
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



void bag() {

	glColor3f(0.0, 0.1, 0.0);

	glLineWidth(2.0);


	glBegin(GL_LINES);
	glVertex2i(150, 240);//delivery bag
	glVertex2i(95, 240);

	glVertex2i(150, 225);
	glVertex2i(95, 225);

	glVertex2i(95, 240);
	glVertex2i(95, 225);


	glEnd();
}



void scalebox() {

	glPushMatrix();
	glTranslatef(150.0, 225.0, 0.0);
	glScalef(sx1, sy1, 0.0);
	glTranslatef(-150.0, -225.0, 0.0);
	bag();
	glPopMatrix();

	sx1 = sx1 * 1.001;
	sy1 = sy1 * 1.01;

}

void viewports() {

	glViewport(0, 0, 300, 400);
	glPushMatrix();
	glScalef(2.2, 2.2, 2.2);
	scalebox();
	scene3();
	glPopMatrix();
	glViewport(200, 0, 300, 400);
	glPushMatrix();
	glScalef(2.2, 2.2, 2.2);
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
	//glutInit(&argc, argv);  //perform the GLUT initialization

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // more initialisation
												 //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
												 //glutInitWindowSize(800, 600); // set window position
												 //glutInitWindowPosition(100, 100); // set window size
												 //glutCreateWindow("Hello"); // create a display with a given caption for the title bar
	init(); // call init function defined above
			//glutIdleFunc(idle); //  define what function to call when the program is idle
			//init3D(500, 500);
			//glutDisplayFunc(display); // define what function to call to draw 

			//glutVisibilityFunc(visibility);
	glDisable(GL_DEPTH_TEST);
	//glutTimerFunc(0, Timer, 0);

	//glutTimerFunc(0, Timer, 0);
	//glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 0.0);
	//glutMainLoop();

	//return 0;
}




void main2()
{
	//glutInit(&argc, argv);

	////3D this turns on double buffereing and depth testing
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	//glutInitWindowSize(500, 500);
	//glutInitWindowPosition(300, 300);
	//glutCreateWindow("cube");
	init3D(500, 500);
	//glutDisplayFunc(display);
	//glutVisibilityFunc(visibility);

	//printf("%s", "Press mouse buttons to change rotation axis");
	/* enable hidden-surface removal */
	////3D thus turns on depth testing to do hidden surface removal
	glEnable(GL_DEPTH_TEST);
	//glutMainLoop();
	//return(0);
}




// This is the display function it is called when ever you want to draw something
// all drawing should be called form here
void display() {
	int i;
	frame++;
	angle1 = angle1 + 1.0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT); // clear the screen using the background colour
	glMatrixMode(GL_MODELVIEW); //	
								//glColor3f(0.0, 0.1, 0.0); // set colour to white

	if ((frame >= 0) && (frame < 100))
	{
		glViewport(0, 0, 800, 800);

		glColor3f(0.0, 0.1, 0.0);
		floor();
		wheel1();
		wheel2();


		xt = xt + 2.2;
		glLoadIdentity();
		glTranslatef(xt, 0.0, 0.0);

		glPushMatrix();
		glTranslatef(200.0, 150.0, 0.0);
		glRotatef(angle1, 0.0, 0.0, 1.0);
		glTranslatef(-200.0, -150.0, 0.0);
		axle();

		glPopMatrix();

		glPushMatrix();
		glTranslatef(95.0, 150.0, 0.0);
		glRotatef(angle1, 0.0, 0.0, 1.0);
		glTranslatef(-95.0, -150.0, 0.0);
		axle2();
		glPopMatrix();



		glBegin(GL_LINES);

		for (i = 0; i < 10; i++)
			glVertex2i(first[i][0], first[i][1]);


		glEnd();

		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "We are Deliveroo"); // Add text on the scene
	}


	else if ((frame >= 100) && (frame < 125))

	{

		glColor3f(0.0, 0.1, 0.0);

		face();
		body1();
		floor();
		//square();

		glBegin(GL_LINES);
		for (i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();

		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Fast Delivery"); // Add text on the scene
	}

	else if ((frame >= 125) && (frame < 150)) {
		glColor3f(0.0, 0.1, 0.0);
		face();
		body2();
		floor();
		//square();
		glBegin(GL_LINES);
		for (i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();

		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Fast Delivery");
	}

	else if ((frame >= 150) && (frame < 175))

	{
		glColor3f(0.0, 0.1, 0.0);
		face();
		body1();
		floor();


		glBegin(GL_LINES);
		for (i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();

		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Fast Delivery");
	}

	else if ((frame >= 175) && (frame < 200)) {
		glColor3f(0.0, 0.1, 0.0);
		face();
		body2();
		floor();
		//square();

		glBegin(GL_LINES);
		for (i = 0; i < 10; i++)
			glVertex2i(sq[i][0], sq[i][1]);
		glEnd();

		renderSpacedBitmapString(50, 400, GLUT_BITMAP_HELVETICA_18, "Fast Delivery");
	}

	else if ((frame >= 200) && (frame < 250)) {
		glColor3f(0.0, 0.1, 0.0);

		viewports();
		tween(sq, D, 10, proportion, tweenPoly);

		glBegin(GL_LINE_LOOP);
		for (i = 0; i < 10; i++)
			glVertex2i(tweenPoly[i][0], tweenPoly[i][1]);
		glEnd();

		renderSpacedBitmapString(50, 600, GLUT_BITMAP_HELVETICA_18, "  ");


		proportion += 0.01;

		if (proportion > 1.0) proportion = 0.0;
	}
	else if (frame == 250) main2();

	else if ((frame > 250) && (frame < 350))
	{
		/* clear frame buffer and z buffer,
		rotate cube and draw, swap buffers */
		glViewport(0, 0, 800.0, 600.0);
		glColor3fv(colors[1]);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		theta[axis] += delta;
		if (theta[axis] > 360.0) theta[axis] -= 360.0;


		glLoadIdentity();
		glRotatef(45.0, 1.0, 0.0, 0.0);
		glRotatef(45.0, 0.0, -1.0, 0.0);


		glPushMatrix();
		//	///3D we can have a seperate rotation for each axis
		glRotatef(theta[0], 1.0, 0.0, 0.0);
		glRotatef(theta[1], 0.0, 1.0, 0.0);
		glRotatef(theta[2], 0.0, 0.0, 1.0);
		//	// translate object back to origin so it will rotate around its center
		glTranslatef(0.0, 0.0, 0.0);
		colorcube();
		glPopMatrix();

		//	
		//	/// this is double buffering, as we turned it on in main we have to swap buffers after gl flush

	}

	//else if (frame > 400)
	//{
	//	//main1();

	//	glViewport(0, 0, 800, 600);
	//	refreshmill = 1;
	//	angle1 = 0.0;
	//	angle2 = 0.0;
	//	xt = 0.0;
	//	frame = 0;
	//	tx = 0.0;
	//	ty = 0.0;
	//	sx = 1.0;
	//	sy = 1.0;
	//	sx1 = 0.3; //scale box
	//	sy1 = 0.3;
	//	rx = 0.0;
	//	ry = 0.0;
	//	proportion = 0.0;
	//	main1();
	//}
	fprintf(stdout, "Frame number= %i\n", frame);
	glFlush();
	glutSwapBuffers();

}


void Timer(int value)
{
	if (value) glutPostRedisplay();
	glutTimerFunc(40, Timer, value);
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






// This is the idle function it is called whenever the program is idle
// This has the effect of repeatedly calling the display function
//void idle() {
//display();
//}

// As with many programming languages the main() function
// is the entry point for execution of the program
int main(int argc, char** argv) {
	glutInit(&argc, argv);  //perform the GLUT initialization

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // more initialisation
												 //glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600); // set window position
	glutInitWindowPosition(100, 100); // set window size
	glutCreateWindow("Delivery"); // create a display with a given caption for the title bar
	init(); // call init function defined above
			//glutIdleFunc(idle); //  define what function to call when the program is idle
			//init3D(500, 500);
	glutDisplayFunc(display); // define what function to call to draw 

	glutVisibilityFunc(visibility);
	//glEnable(GL_DEPTH_TEST);
	//glutTimerFunc(0, Timer, 0);
	//glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 0.0);
	glutMainLoop();

	return 0;
}

