// TestGlfw.cpp : �������̨Ӧ�ó������ڵ㡣
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

//��ɫ��
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

//���ε�ɫ������ͻ������Ч��
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

//������ɫ������ͻ������Ч��
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

//����һ������
void testDrawRect() {
	//���ƾ���
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(300.0f, 400.0f, 350.0f, 450.0f);
}

//֪ͨ�ػ�
void update() {

	glutPostRedisplay(); //������������������»�ͼ,ÿ����Ӧ��Ϣ֮������ȫ���ػ�
}

void drawCNString(const char* str) {
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);

	// �����ַ��ĸ���
	// �����˫�ֽ��ַ��ģ����������ַ����������ֽڲ���һ���ַ�
	// ����һ���ֽ���һ���ַ�
	len = 0;
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}

	// ������ַ�ת��Ϊ���ַ�
	wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';

	// �������ַ�
	wchar_t ch = L'\x20';
	wglUseFontBitmapsW(hDC, ch, 1, list);
	glCallList(list);
	for (i = 0; i<len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}

	// ����������ʱ��Դ
	free(wstring);
	glDeleteLists(list, 1);
}

void testDrawString() {
	glColor3f(1.0f, 0.0f, 0.0f); //��ʾ��ɫ
	glRasterPos2f(300.0f, 550.0f); //��ʾλ��
	drawCNString(strShow.c_str());
}

void tesDrawLine() {

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f); //��ʾ��ɫ
	glLineWidth(1.0f);//ָ�����
	glVertex2f(300.0f, 500.0f);//ָ������
	glVertex2f(350.0f, 500.0f);//ָ���յ�
	glEnd();
}

//����һ������
void DrawBlock(float nX, float nY, int nType = 1) {

	//������
	glColor3f(colorTable[nType][0], colorTable[nType][1], colorTable[nType][2]);
	glRectf(0.0f + nX, 0.0f + nY,  //���½�����
		BLOCK_SIZE + nX, BLOCK_SIZE + nY);  //���Ͻ�����

	//ѡŶ�Ȼ�4����Ե��
	glBegin(GL_LINES);
	glLineWidth(1.0f);//ָ�����
	
	//��ǳɫ��
	glColor3f(lightColorTable[nType][0], lightColorTable[nType][1], lightColorTable[nType][2]);
	glVertex2f(0.0f + nX, 0.0f + nY);//ָ������
	glVertex2f(0.0f + nX, BLOCK_SIZE + nY);//ָ���յ�

	//��ǳɫ��
	glColor3f(lightColorTable[nType][0], lightColorTable[nType][1], lightColorTable[nType][2]);
	glVertex2f(0.0f + nX, BLOCK_SIZE + nY);//ָ������
	glVertex2f(BLOCK_SIZE + nX, BLOCK_SIZE + nY);//ָ���յ�

	//����ɫ��
	glColor3f(darkColorTable[nType][0], darkColorTable[nType][1], darkColorTable[nType][2]);
	glVertex2f(0.0f + nX, 0.0f + nY);//ָ������
	glVertex2f(BLOCK_SIZE + nX, 0.0f + nY);//ָ���յ�

	//����ɫ��
	glColor3f(darkColorTable[nType][0], darkColorTable[nType][1], darkColorTable[nType][2]);
	glVertex2f(BLOCK_SIZE + nX, 0.0f + nY);//ָ������
	glVertex2f(BLOCK_SIZE + nX, BLOCK_SIZE + nY);//ָ���յ�
	glEnd();

}

//��ʾ�ص�����
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);/* clear all pixels   */
	

    //���Ի�������
	testDrawString();

	//����ֱ��
	tesDrawLine();

	//���Ի��ƾ���
	testDrawRect();

	//���Ի��Ʒ���
	float fX = 0;
	float fY = SCR_HEIGHT/2;

	for (int i = 1; i < 8; i++) {
		fX = 300 + (i-1) *( BLOCK_SIZE+1);
		DrawBlock(fX, fY, i);
	}
	
	glFlush();/* start processing buffered OpenGL routines   */
}

//��ʱ���ص�����
void idle(int value)
{
	std::cout << "123" << std::endl;

	update();
	glutTimerFunc(1000, idle, 1);
}

//���̻ص�����
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 033: // ESC�� �� 'q' ���˳���Ϸ
		exit(EXIT_SUCCESS);
		break;
	case 'q':
		exit(EXIT_SUCCESS);
		break;
	case 'w':{
		std::cout << "w" << std::endl;
		strShow = "��";
	}
	break;
	case 's': {
		std::cout << "s" << std::endl;
		strShow = "��";
	}
	 break;
	case 'a': {
		std::cout << "a" << std::endl;
		strShow = "��";
	}
	break;
	case 'd': {
		std::cout << "d" << std::endl;
		strShow = "��";
	}
	break;
	case 'r': // 'r' ��������Ϸ
		break;
	}
	
	update();
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //������ʾģʽ
	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT); //���ô��ڴ�С 
	glutInitWindowPosition(200, 200); //���ô�������Ļ�ϵ�λ�� 

	glutCreateWindow("OpenGL����"); //�������ڲ��������� 
	glutDisplayFunc(display); //ע����ʾ����ʱ�ص�����
	glutTimerFunc(1000, idle, 1); //��ʱ��
	glutKeyboardFunc(keyboard); //���̻ص�����
	glOrtho(0.0f, SCR_WIDTH, 0.0f, SCR_HEIGHT, 1.0, -1.0);
	glClearColor(0.96f, 0.96f, 0.96f, 1.0f);//����
	glutMainLoop(); //��Ϣѭ�����������ϵͳ�ȵ���Ϣ��������̡�����¼��ȣ�
}