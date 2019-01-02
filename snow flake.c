#include <GL/glut.h>
#include <math.h>

float oldx=-0.7,oldy=0.5;

void drawkoch(float angle,float len,int iter) {
	double angleRad = 0.0174533 * angle;  
	float newX = oldx + len * cos(angleRad);
	float newY = oldy + len * sin(angleRad);
	if (iter==0) {
		glVertex2f(oldx, oldy);
		glVertex2f(newX, newY);
		oldx = newX;
		oldy = newY;
	}
	else {
		iter--;
		//draw the four parts of the side _/\_ 
		drawkoch(angle, len, iter);
		angle += 60.0;
		drawkoch(angle, len, iter);
		angle -= 120.0;
		drawkoch(angle, len, iter);
		angle += 60.0;
		drawkoch(angle, len, iter);
	}
}

void mydisplay(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 1.0, 1.0); 
	 
	 
	//  drawkoch(0.0,0.5,1);
	//  drawkoch(-120.0, 0.5, 1);
	//  drawkoch(120.0,0.5,1);
	
	//  drawkoch(0.0,0.15,2);
	//  drawkoch(-120.0, 0.15, 2);
	//  drawkoch(120.0,0.15,2);
	
	 
	 drawkoch(0.0,0.05,3);
	 drawkoch(-120.0, 0.05, 3);
	 drawkoch(120.0,0.05,3);
	
	 glEnd();
	 glFlush(); 
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);      
	glutInitWindowSize(500,500);    	
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Koch Snowflake");     
	glutDisplayFunc(mydisplay);  
	glutMainLoop();
}
