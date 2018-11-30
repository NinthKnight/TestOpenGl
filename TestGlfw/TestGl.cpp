// TestGlfw.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
#include "glut\glut.h"

#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glew32.lib")

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const unsigned int BLOCK_SIZE = SCR_HEIGHT /20;

std::string strShow= "";

//颜色表
static const float colorTable[8][4] = {
	{ 0,0,0,1 },
	{ 0.8,0.4,0.4,1 },
	{ 0.4,0.8,0.4,1 },
	{ 0.4,0.4,0.8,1 },
	{ 0.8,0.8,0.4,1 },
	{ 0.8,0.4,0.8,1 },
	{ 0.4,0.8,0.8,1 },
	{ 0.85,0.66,0,1 },
};

//矩形淡色，用于突出立体效果
static const float lightColorTable[8][4] = {
	{ 0,0,0,1 },
	{ 255 / 255.0,178 / 255.0,178 / 255.0,1 },
	{ 178 / 255.0,255 / 255.0,178 / 255.0,1 },
	{ 178 / 255.0,178 / 255.0,255 / 255.0,1 },
	{ 255 / 255.0,255 / 255.0,178 / 255.0,1 },
	{ 255 / 255.0,178 / 255.0,255 / 255.0,1 },
	{ 178 / 255.0,255 / 255.0,255 / 255.0,1 },
	{ 255 / 255.0,215 / 255.0,72 / 255.0,1 },
};

//矩形深色，用于突出立体效果
static const float darkColorTable[8][4] = {
	{ 0,0,0,1 },
	{ 102 / 255.0,51 / 255.0,51 / 255.0,1 },
	{ 51 / 255.0,102 / 255.0,51 / 255.0,1 },
	{ 51 / 255.0,51 / 255.0,102 / 255.0,1 },
	{ 102 / 255.0,102 / 255.0,51 / 255.0,1 },
	{ 102 / 255.0,51 / 255.0,102 / 255.0,1 },
	{ 51 / 255.0,102 / 255.0,102 / 255.0,1 },
	{ 109 / 255.0,85 / 255.0,0 / 255.0,1 },
};

//绘制一个矩形
void testDrawRect() {
	//绘制矩形
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(300.0f, 400.0f, 350.0f, 450.0f);
}

//通知重绘
void update() {

	glutPostRedisplay(); //调用这个函数可以重新绘图,每次相应消息之后，所有全部重绘
}

void drawCNString(const char* str) {
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);

	// 计算字符的个数
	// 如果是双字节字符的（比如中文字符），两个字节才算一个字符
	// 否则一个字节算一个字符
	len = 0;
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}

	// 将混合字符转化为宽字符
	wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';

	// 逐个输出字符
	wchar_t ch = L'\x20';
	wglUseFontBitmapsW(hDC, ch, 1, list);
	glCallList(list);
	for (i = 0; i<len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}

	// 回收所有临时资源
	free(wstring);
	glDeleteLists(list, 1);
}

void testDrawString() {
	glColor3f(1.0f, 0.0f, 0.0f); //表示颜色
	glRasterPos2f(300.0f, 550.0f); //表示位置
	drawCNString(strShow.c_str());
}

void tesDrawLine() {

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); //表示颜色
	glLineWidth(1.0f);//指定宽度
	glVertex2f(300.0f, 500.0f);//指定顶点
	glVertex2f(350.0f, 500.0f);//指定终点
	glEnd();
}

//绘制一个方块
void DrawBlock(float nX, float nY, int nType = 1) {

	//画矩形
	glColor3f(colorTable[nType][0], colorTable[nType][1], colorTable[nType][2]);
	glRectf(0.0f + nX, 0.0f + nY,  //左下角坐标
		BLOCK_SIZE + nX, BLOCK_SIZE + nY);  //右上角坐标

	//选哦先画4条边缘线
	glBegin(GL_LINES);
	glLineWidth(1.0f);//指定宽度
	
	//画浅色线
	glColor3f(lightColorTable[nType][0], lightColorTable[nType][1], lightColorTable[nType][2]);
	glVertex2f(0.0f + nX, 0.0f + nY);//指定顶点
	glVertex2f(0.0f + nX, BLOCK_SIZE + nY);//指定终点

	//画浅色线
	glColor3f(lightColorTable[nType][0], lightColorTable[nType][1], lightColorTable[nType][2]);
	glVertex2f(0.0f + nX, BLOCK_SIZE + nY);//指定顶点
	glVertex2f(BLOCK_SIZE + nX, BLOCK_SIZE + nY);//指定终点

	//画深色线
	glColor3f(darkColorTable[nType][0], darkColorTable[nType][1], darkColorTable[nType][2]);
	glVertex2f(0.0f + nX, 0.0f + nY);//指定顶点
	glVertex2f(BLOCK_SIZE + nX, 0.0f + nY);//指定终点

	//画深色线
	glColor3f(darkColorTable[nType][0], darkColorTable[nType][1], darkColorTable[nType][2]);
	glVertex2f(BLOCK_SIZE + nX, 0.0f + nY);//指定顶点
	glVertex2f(BLOCK_SIZE + nX, BLOCK_SIZE + nY);//指定终点
	glEnd();

}

//显示回调函数
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);/* clear all pixels   */
	

    //测试绘制文字
	testDrawString();

	//绘制直线
	tesDrawLine();

	//测试绘制矩形
	testDrawRect();

	//测试绘制方块
	float fX = 0;
	float fY = SCR_HEIGHT/2;

	for (int i = 1; i < 8; i++) {
		fX = 300 + (i-1) *( BLOCK_SIZE+1);
		DrawBlock(fX, fY, i);
	}
	
	glFlush();/* start processing buffered OpenGL routines   */
}

//定时器回调函数
void idle(int value)
{
	std::cout << "123" << std::endl;

	update();
	glutTimerFunc(1000, idle, 1);
}

//键盘回调函数
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 033: // ESC键 和 'q' 键退出游戏
		exit(EXIT_SUCCESS);
		break;
	case 'q':
		exit(EXIT_SUCCESS);
		break;
	case 'w':{
		std::cout << "w" << std::endl;
		strShow = "上";
	}
	break;
	case 's': {
		std::cout << "s" << std::endl;
		strShow = "下";
	}
	 break;
	case 'a': {
		std::cout << "a" << std::endl;
		strShow = "左";
	}
	break;
	case 'd': {
		std::cout << "d" << std::endl;
		strShow = "右";
	}
	break;
	case 'r': // 'r' 键重启游戏
		break;
	}
	
	update();
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //设置显示模式
	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT); //设置窗口大小 
	glutInitWindowPosition(200, 200); //设置窗口在屏幕上的位置 

	glutCreateWindow("OpenGL测试"); //创建窗口并给出标题 
	glutDisplayFunc(display); //注册显示窗口时回调函数
	glutTimerFunc(1000, idle, 1); //定时器
	glutKeyboardFunc(keyboard); //键盘回调函数
	glOrtho(0.0f, SCR_WIDTH, 0.0f, SCR_HEIGHT, 1.0, -1.0);
	glClearColor(0.96f, 0.96f, 0.96f, 1.0f);//清屏
	glutMainLoop(); //消息循环（处理操作系统等的消息，例如键盘、鼠标事件等）
}