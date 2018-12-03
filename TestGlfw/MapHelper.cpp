#include "stdafx.h"
#include "MapHelper.h"


unsigned char g_mapData[26][26] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x01, 0x01, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x01,  0x01,
	0x02, 0x02, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x00, 0x00, 0x02,  0x02,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00,	0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00,  0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x00, 0x01, 0x00,	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00,
};


CMapHelper::CMapHelper()
{
	//从pcx文件种加载坦克图片素材
	CImageBuf ImageBuf;
	ImageBuf.LoadPcx("data\\object.pcx");

	//获取砖，草等元素
	for (int i = 1; i <= 5; i++) {
		ImageBuf.CopyImage(0 + (i - 1) * 25, 256, 25, 25, MapPic[i]);
	}

	for (int i = 0; i < 4; i++){
		ImageBuf.CopyImage(150 + (i + 1) * 50, 50, 50, 49, TankPic[0][i]);             //拷贝上、下、左、右朝向tank
	}

	for (int i = 0; i < 4; i++){
		ImageBuf.CopyImage(150 + (i + 1) * 50, 0, 50, 49, TankPic[1][i]);             //拷贝上、下、左、右朝向tank
	}

	for (int i = 0; i < 4; i++){
		ImageBuf.CopyImage(0 + (i) * 50, 0, 50, 49, TankPic[2][i]);             //拷贝上、下、左、右朝向tank
	}

	for (int i = 0; i < 4; i++){
		ImageBuf.CopyImage(150 + (i + 1) * 50, 201, 50, 49, TankPic[3][i]);             //拷贝上、下、左、右朝向tank
	}

	for (int i = 0; i <= 5; i++) {
		ImageBuf.CopyImage(50 + i * 50, 150, 50, 50, BoomPic[i]);                       //for boom
	}

	for (int i = 0; i < 2; i++)
	{
		ImageBuf.CopyImage(i * 15, 150, 15, 15, BulletPic[i]);             //拷贝上、下、左、右朝向tank
	}

	ImageBuf.CopyImage(0, 100, 50, 50, HomeBase);             //拷贝上、下、左、右朝向tank

	nCurTankX = 9;
	nCurTankY = 25;
	nCurRotate = 0;

}


CMapHelper::~CMapHelper()
{
}

void CMapHelper::MixPic(int x, int y, int w, int h, unsigned char *buf)             //glReadPixels 
{
	int PixelByte = 4;        //for RGBA color

	int SrcTempPos = 0, TempPos = 0;
	unsigned char *Temp = new unsigned char[w*h*PixelByte];

	glReadPixels(x, y, w, h, GL_RGB, GL_UNSIGNED_BYTE, Temp);
	glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, Temp);
	for (int i = 0; i<w*h; i++)
	{
		if ((buf[SrcTempPos + 3]) == 0)          //找出了边框为黑色的部分
		{
			memcpy(&buf[SrcTempPos], &Temp[TempPos], 3);         //显示背景色
		}
		SrcTempPos += 4;
		TempPos += PixelByte;
	}
	delete[]Temp;
}

void CMapHelper::drawMap() {

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (g_mapData[i][j] == 0x01) {
				DrawElement(j * 25, (25 - i) * 25, g_mapData[i][j]);
			}
			else if (g_mapData[i][j] == 0x02) {
				DrawElement(j * 25, (25 - i) * 25, g_mapData[i][j]);
			}
			else if (g_mapData[i][j] == 0x05) {
				DrawElement(j * 25, (25 - i) * 25, g_mapData[i][j]);
			}
			else if (g_mapData[i][j] == 0x06){
				DrawHomeBase(j * 25, (25 - i) * 25);
			}
		}
	}

	//开始绘制坦克
	DrawTank(nCurTankX * 25, (25-nCurTankY)*25, 1, nCurRotate);

}

void CMapHelper::testDraw() {

	int nType = 1;
	int nRotate = 0;

	//首先绘制的是基本的数据
	for (int i = 1; i < 6; i++) {
		nType = i;
		DrawElement((i-1)*25, 0, nType);
	}

	//然后再绘制坦克
	for (int nType = 0; nType < 4; nType++) {
		for (int nRotate = 0; nRotate < 4; nRotate++) {
			DrawTank(nRotate * 50, 50 + nType *50, nType, nRotate);
		}
	}

	//然后再绘制炸弹的效果
	for (int i = 0; i <= 5; i++) {
		nType = i;
		DrawBoom(i * 50, 250, nType);
	}

	//然后再绘制两种子弹
	for (int i = 0; i < 2; i++) {
		nType = i;
		DrawBullet(i*50, 300, nType);
	}

	//最后绘制基地
	DrawHomeBase(0, 350);
}

bool CMapHelper::CheckImpact(int x, int y) {

	if (x < 0 || x+1 > 25) {
		return true;
	}

	if (y-1 < 0 || y > 25) {
		return true;
	}

	if (g_mapData[y][x] != 0x00 ||
		g_mapData[y][x+1]!= 0x00 ||
		g_mapData[y - 1][x] != 0x00 ||
		g_mapData[y - 1][x+1]!= 0x00) {
		return true;
	}

	return false;
}

void CMapHelper::DrawElement(int x, int y, int nType) {
	glRasterPos2i(x, y);      //为像素操作指定光栅位置  用25*i j  为了显示图像的不重叠
	MixPic(25, 25, 25, 25, MapPic[nType]);
	glDrawPixels(25, 25, GL_RGBA, GL_UNSIGNED_BYTE, MapPic[nType]);  //将一个像素块写入帧缓存  
}

void CMapHelper::DrawBoom(int x, int y, int nType) {

	glRasterPos2i(x, y);      //为像素操作指定光栅位置  用25*i j  为了显示图像的不重叠
	glDrawPixels(50, 50, GL_RGBA, GL_UNSIGNED_BYTE, BoomPic[nType]);  //将一个像素块写入帧缓存  
}

void CMapHelper::DrawTank(int x, int y, int nType, int nRotate) {

	glRasterPos2i(x, y);      //为像素操作指定光栅位置  用25*i j  为了显示图像的不重叠
	glDrawPixels(50, 49, GL_RGBA, GL_UNSIGNED_BYTE, TankPic[nType][nRotate]);  //将一个像素块写入帧缓存  
}

void CMapHelper::DrawHomeBase(int x, int y) {

	glRasterPos2i(x, y);      //为像素操作指定光栅位置  用25*i j  为了显示图像的不重叠				
	glDrawPixels(50, 50, GL_RGBA, GL_UNSIGNED_BYTE, HomeBase);  //将一个像素块写入帧缓存  

}

void CMapHelper::DrawBullet(int x, int y, int nType) {

	glRasterPos2i(x, y);      //为像素操作指定光栅位置  用25*i j  为了显示图像的不重叠
	glDrawPixels(15, 15, GL_RGBA, GL_UNSIGNED_BYTE, BulletPic[nType]);  //将一个像素块写入帧缓存  
}
