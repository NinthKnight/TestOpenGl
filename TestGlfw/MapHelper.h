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

	//绘制基本元素， nType = 1 表示砖  2 铁 3 浅蓝方块 4 深蓝方块 5 草 
	void DrawElement(int x, int y, int nType);

	//绘制爆炸效果 nType = 0-5 表示6种爆炸效果，效果逐渐递增
	void DrawBoom(int x, int y, int nType);

	//绘制坦克 nType = 0-3 表示4种坦克类型，nRotate表示旋转的方向
	void DrawTank(int x, int y, int nType, int nRotate);

	//绘制基地
	void DrawHomeBase(int x, int y);

	//绘制子弹 nType = 0 表示蓝色子弹 =1 表示红色子弹
	void DrawBullet(int x, int y, int nType);

	//check
	bool CheckImpact(int x, int y);

	int nCurTankX;     //当前坦克X坐标
	int nCurTankY;     //当前坦克Y坐标
	int nCurRotate;    //当前坦克旋转方位

private:
	unsigned  char *MapPic[6];                //指向像素数据的指针  用以记录砖、铁……
	unsigned char *BoomPic[6];              //爆炸效果6张
	unsigned char *TankPic[4][4];           //坦克，上下左右 4张
	unsigned char* HomeBase;               //基地
	unsigned char * BulletPic[2];             //两种子弹

	char MapData[24][26];                      //表示地图数据


};

