#include <GL/glut.h> //Provides functions that facilitate the use of gl

void display();
void reshape(int, int);
void init();
void draw();
void point(float, float, float, float, float, float);
void triangle();
void polygon();
void turtle();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);

	glutCreateWindow("Title"); //Window title
	glutDisplayFunc(display);
	init();
	glutReshapeFunc(reshape); //Window resized behavior
	glutMainLoop(); //Start the loop

	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear frame
	//glLoadIdentity(); //Resets metrics - transformations

		//Draw something
	draw();

	glFlush(); //Draw frame
}
void init()
{
	glClearColor(255, 255, 255, 1.0); //Background color
}
void reshape(int WindowWidth, int WindowHeight)
{
	//Viewport - everything will be drawn in this area
	glViewport(0, 0, WindowWidth, WindowHeight); //Position and size of the viewport relative to the bottom left corner of the window

	//Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15, 15, -15, 15); //2D cartesian plane
	glMatrixMode(GL_MODELVIEW);
}
void draw()
{

	polygon();

}
void polygon()
{
	//glTranslatef(0.5, 0.5, 0);
	glRotatef(25.0, 0, 0, 1);
	//glScalef(1.1, 1.1, 0);


	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(0, 3.5);
	glColor3f(0, 0, 1);
	glVertex2f(-2, 2);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(2, 2);
	glEnd();
}