#include<graphics.h>
#include<stdio.h>
#include<conio.h>

//变量，根据素材的情况得来

IMAGE backgeound;     //窗口背景

IMAGE standImg[2];     //0：左边  1：右边    背景图
IMAGE standImgY[2];    //掩码图    ps：vs2017支持png图片

IMAGE moveImg[2];
IMAGE moveImgY[2];

IMAGE jumpImg[2];
IMAGE jumpImgY[2];

IMAGE jumpCut[2];
IMAGE jumpCutY[2];

IMAGE cutImg[2];
IMAGE cutImgY[2];
//枚举方向    0为左 1为右
enum direction{left, right};
//封装结构体
struct role
{
	int x, y;       //角色在窗口的坐标
	int postion;     //角色方向   0左  1右
}saber{ 100, 305, right};  //角色起始位置
//游戏地图信息
struct backImg
{
	int x, y;
}img = {0, 0};
//加载图片资源
void loadResource()
{
	loadimage(&backgeound, "Background\\background.png", 2500, 650);
	//背景图
	//站立的图片
	loadimage(standImg + 0, "Stand\\left.png");
	loadimage(standImg + 1, "Stand\\right.png");
	//掩码图
	loadimage(standImgY + 0, "Stand\\lefty.png");
	loadimage(standImgY + 1, "Stang\\righty.png");
	//移动图片
	loadimage(moveImg + 0, "Move\\left.png");
	loadimage(moveImg + 1, "Move\\right.png");
	//掩码图
	loadimage(moveImgY + 0, "Move\\lefty.png");
	loadimage(moveImgY + 1, "Move\\righty.png");
	//跳跃图片
	loadimage(jumpImg + 0, "Jump\\left.png");
	loadimage(jumpImg + 1, "Jump\\right.png");
	//掩码图
	loadimage(jumpImgY + 0, "Jump\\lefty.png");
	loadimage(jumpImgY + 1, "Jump\\righty.png");
	//跳砍图片
	loadimage(jumpCut + 0, "JumpCut\\left.png");
	loadimage(jumpCut + 1, "JumpCut\\right.png");
	//掩码图
	loadimage(jumpCutY + 0, "JumpCut\\lefty.png");
	loadimage(jumpCutY + 1, "JumpCut\\righty.png");
	//攻击图片
	loadimage(cutImg + 0, "Cuting\\left.png");
	loadimage(cutImg + 1, "Cuting\\right.png", 5100, 400);
	//掩码图	   I  mg
	loadimage(cutImgY + 0, "Cuting\\lefty.png");
	loadimage(cutImgY + 1, "Cuting\\righty.png", 5100, 400);
}
//画角色站立
void drawRole_Stand()
{
	//透明贴图
	putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
	//SRCAND
	putimage(saber.x, saber.y, 400, 300, standImgY + saber.postion, 0, 0, SRCAND);
	//SRCPAINT
	putimage(saber.x, saber.y, 400, 300, standImg + saber.postion, 0, 0, SRCPAINT);
}
//移动
void drawRole_Move(int frameNum)
{
	for (int i = 0; i < frameNum; i++)
	{
		BeginBatchDraw();                //写入内存
		putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
		//SRCAND
		putimage(saber.x, saber.y, 400, 300, moveImgY + saber.postion, 400 , 0, SRCAND);
		//SRCPAINT
		putimage(saber.x, saber.y, 400, 300, moveImg + saber.postion, 400 , 0, SRCPAINT);
		Sleep(30);
		EndBatchDraw();                 //释放内存
	}
}
//跳
void drawRole_Jump(int frameNum)
{
	for (int i = 0; i < frameNum; i++)
	{
		BeginBatchDraw();
		putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
		//SRCAND
		putimage(saber.x, saber.y, 400, 300, jumpImgY + saber.postion, 400 * i, 0, SRCAND);
		//SRCPAINT
		putimage(saber.x, saber.y, 400, 300, jumpImg + saber.postion, 400 * i, 0, SRCPAINT);
		Sleep(50);
		EndBatchDraw();
	}
}
//砍跳
void drawRole_JumpCut(int frameNum)
{
	for (int i = 0; i < frameNum; i++)
	{
		BeginBatchDraw();
		putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
		//SRCAND
		putimage(saber.x, saber.y, 400, 300, jumpCutY + saber.postion, 400 * i, 0, SRCAND);
		//SRCPAINT
		putimage(saber.x, saber.y, 400, 300, jumpCut + saber.postion, 400 * i, 0, SRCPAINT);
		Sleep(50);
		EndBatchDraw();
	}
}
//砍
void drawRole_Cut(int frameNum)
{
	for (int i = 0; i < (frameNum - 1); i++)
	{
		BeginBatchDraw();
		putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
		//SRCAND
		putimage(100, 305 - 50, 300, 400, cutImgY + saber.postion, 400 * i, 0, SRCAND);
		//x与y为图标窗口原点坐标，xx与yy表示取图片的坐标原点，原点都为左上角，w与h为输出长与宽
		//SRCPAINT
		putimage(100, 305 - 50, 300, 400, cutImg + saber.postion, 400 * i, 0, SRCPAINT);
		Sleep(80);
		EndBatchDraw();
	}
}
//改变位置
void moveRole()
{
	switch (saber.postion)
	{
	case right:
		//saber.x += 30;
		img.x += 30;           //人不动，背景移动
		break;
	case left:
		//saber.x -= 30;
		img.x -= 30;           //人不动，背景移动
		break;
	}
}
//按键控制
void keyDown()
{
	char userKey = _getch();
	switch (userKey)
	{
	case 'A':          //左移
	case 'a':
	case 75:
		saber.postion = left;
		moveRole();
		drawRole_Move(8);
		break;
	case 'd':          //右移
	case 'D':
	case 77:
		saber.postion = right;
		moveRole();
		drawRole_Move(8);
		break;
	case 'j':           //跳
	case 'J':
		drawRole_Jump(8);
		break;
	case 'k':           //跳砍
	//case 'K':
		drawRole_JumpCut(8);
		break;
	case 'l':           //砍
	case 'L':
		drawRole_Cut(17);
		break;
	}

}

int main(void)
{
	loadResource();       //加载资源
	initgraph(1000, 650);  //建立画布
	while (1)
	{
		drawRole_Stand();
		if (_kbhit())
		{
			keyDown();
		}
	}
	drawRole_Stand();     //画站立的人物  （初始的画面）
	_getch();

	closegraph();

	return 0;
}
