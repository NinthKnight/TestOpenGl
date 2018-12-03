#pragma once

#include "Imagebuf.h"
#include "glut\glut.h"








class CMapHelper
{
public:
	CMapHelper();
	~CMapHelper();

	void drawMap();
	void testDraw();

	void MixPic(int x, int y, int w, int h, unsigned char *buf);

	//���ƻ���Ԫ�أ� nType = 1 ��ʾש  2 �� 3 ǳ������ 4 �������� 5 �� 
	void DrawElement(int x, int y, int nType);

	//���Ʊ�ըЧ�� nType = 0-5 ��ʾ6�ֱ�ըЧ����Ч���𽥵���
	void DrawBoom(int x, int y, int nType);

	//����̹�� nType = 0-3 ��ʾ4��̹�����ͣ�nRotate��ʾ��ת�ķ���
	void DrawTank(int x, int y, int nType, int nRotate);

	//���ƻ���
	void DrawHomeBase(int x, int y);

	//�����ӵ� nType = 0 ��ʾ��ɫ�ӵ� =1 ��ʾ��ɫ�ӵ�
	void DrawBullet(int x, int y, int nType);

	//check
	bool CheckImpact(int x, int y);

	int nCurTankX;     //��ǰ̹��X����
	int nCurTankY;     //��ǰ̹��Y����
	int nCurRotate;    //��ǰ̹����ת��λ

private:
	unsigned  char *MapPic[6];                //ָ���������ݵ�ָ��  ���Լ�¼ש��������
	unsigned char *BoomPic[6];              //��ըЧ��6��
	unsigned char *TankPic[4][4];           //̹�ˣ��������� 4��
	unsigned char* HomeBase;               //����
	unsigned char * BulletPic[2];             //�����ӵ�

	char MapData[24][26];                      //��ʾ��ͼ����


};

