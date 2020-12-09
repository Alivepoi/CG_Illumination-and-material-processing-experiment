// spmulight.cpp : 定义控制台应用程序的入口点。
//
//在示例代码中加上光源

//#include "stdafx.h"

#include <windows.h>
#include <glut.h>

void myinit(void);
void myReshape(GLsizei w, GLsizei h);
void display(void);

static GLfloat spin = 0.0;
static GLfloat spin1 = 0.0;
//  初始化材质特性、光源、光照模型和深度缓冲区
void myinit(void)
{
	GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	GLfloat light0_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat light0_position[] = { 1.0, 1.0, 1.0, 0.0 };

	//聚光灯
	GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light1_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light1_specular[] = { 1.0, 0.6, 0.6, 1.0 };
	GLfloat light1_position[] = { -3.0, -3.0, 3.0, 1.0 };

	//2
	GLfloat light2_ambient[] = { 0.0, 1.0, 0.0, 1.0 }; //绿色
	GLfloat light2_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light2_specular[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat light2_position[] = { -3.0, 3.0, 3.0, 1.0 };

	GLfloat spot_direction[] = { 3.0,3.0,-3.0 };
	GLfloat spot_direction_[] = { 3.0,-3.0,-3.0 }; //


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	//聚光灯
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);//位置

	//2
	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, light2_position);//位置
	//1
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);

	//2
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction_);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//1
	glEnable(GL_LIGHT1);
	//2
	glEnable(GL_LIGHT2);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

}
void spinDisplay(void)
{
	spin = spin + 0.1;
	if (spin > 360.0)
		spin = 0;
	glutPostRedisplay();  //屏幕重绘
}
void spinDisplay1(void)
{
	spin1 = spin1 + 0.1;
	if (spin1 > 360.0)
		spin1 = 0;
	glutPostRedisplay();  //屏幕重绘
}
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(spinDisplay);  //设备空闲时调用的函数
			//glutIdleFunc(spinDisplay1);
		}

		break;
	case GLUT_MIDDLE_BUTTON:
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay1);
		break;
	default:
		break;
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslated(-3.0, -3.0, 3.0);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(0.1f, 50.0f, 50.0f);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.0, 2.0, 2.0);
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidSphere(0.1f, 50.0f, 50.0f);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3.0, 3.0, 3.0);
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 1.0, 0.0);
	glutSolidSphere(0.1f, 50.0f, 50.0f);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glTranslated(0.6, 0, 0);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glTranslated(0, 0, -0.6);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(1, 0, 0.1);
	glTranslated(0.6, 0, -0.6);
	glScaled(1, 6, 1); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glTranslated(0.3, 0.7, -0.3);
	glScaled(5, 0.9, 5); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
	glRotated(spin, 1, 1, 0);
	glRotated(spin1, 0, 1, 0);
	glColor3d(0.1, 0.5, 0.1);
	glTranslated(0.28, 1.3, -0.8);
	glRotated(-90, 1, 0, 0);
	glScaled(5, 0.6, 6); // big cube at (0.5, 0.5, 0.5)
	glutSolidCube(0.2);
	glPopMatrix();


	//glutSolidSphere(2.0f, 50.0f, 50.0f);
	glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.5, 5.5, -5.5 * (GLfloat)h / (GLfloat)w,
			5.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-5.5 * (GLfloat)w / (GLfloat)h,
			5.5 * (GLfloat)w / (GLfloat)h, -5.5, 5.5, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//  主函数，初始化窗口大小、RGBA显示模式和处理输入事件
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("位置光源和多光源演示");
	glutReshapeFunc(myReshape); //glutReshapeFunc注册当前窗口的形状变化回调函数。
								//当改变窗口大小时，该窗口的形状改变回调函数将被调用。
								//在此例中就是myReshape指定形状变化函数。

	glutDisplayFunc(display);
	myinit();
	glEnable(GL_NORMALIZE);//法向量单位化
	glutMouseFunc(mouse); //注册鼠标动作函数
	glutMainLoop();
	return 0;
}

