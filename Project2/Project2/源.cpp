#include<graphics.h>
#include<stdio.h>
#include<conio.h>

//�����������زĵ��������

IMAGE backgeound;     //���ڱ���

IMAGE standImg[2];     //0�����  1���ұ�    ����ͼ
IMAGE standImgY[2];    //����ͼ    ps��vs2017֧��pngͼƬ

IMAGE moveImg[2];
IMAGE moveImgY[2];

IMAGE jumpImg[2];
IMAGE jumpImgY[2];

IMAGE jumpCut[2];
IMAGE jumpCutY[2];

IMAGE cutImg[2];
IMAGE cutImgY[2];
//ö�ٷ���    0Ϊ�� 1Ϊ��
enum direction{left, right};
//��װ�ṹ��
struct role
{
	int x, y;       //��ɫ�ڴ��ڵ�����
	int postion;     //��ɫ����   0��  1��
}saber{ 0, 250, right};  //��ɫ��ʼλ��
//��Ϸ��ͼ��Ϣ
struct backImg
{
	int x, y;
}img = {0, 0};
//����ͼƬ��Դ
void loadResource()
{
	loadimage(&backgeound, "Background\\backgeound.bmp", 2500, 650);
	//����ͼ
	//վ����ͼƬ
	loadimage(standImg + 0, "Stand\\left.bmp");
	loadimage(standImg + 1, "Stand\\right.bmp");
	//����ͼ
	loadimage(standImgY + 0, "Stand\\lefty.bmp");
	loadimage(standImgY + 1, "Stang\\righty.bmp");
	//�ƶ�ͼƬ
	loadimage(moveImg + 0, "Move\\left.bmp");
	loadimage(moveImg + 1, "Move\\right.bmp");
	//����ͼ
	loadimage(moveImgY + 0, "Move\\lefty.bmp");
	loadimage(moveImgY + 1, "Move\\righty.bmp");
	//��ԾͼƬ
	loadimage(jumpImg + 0, "Jump\\left.bmp");
	loadimage(jumpImg + 1, "Jump\\right.bmp");
	//����ͼ
	loadimage(jumpImgY + 0, "Jump\\lefty.bmp");
	loadimage(jumpImgY + 1, "Jump\\righty.bmp");
	//����ͼƬ
	loadimage(jumpCut + 0, "JumpCut\\left.bmp");
	loadimage(jumpCut + 1, "JumpCut\\right.bmp");
	//����ͼ
	loadimage(jumpCutY + 0, "JumpCut\\lefty.bmp");
	loadimage(jumpCutY + 1, "JumpCut\\righty.bmp");
	//����ͼƬ
	loadimage(cutImg + 0, "Cuting\\left.bmp");
	loadimage(cutImg + 1, "Cuting\\right.bmp");
	//����ͼ	   I  mg
	loadimage(cutImgY + 0, "Cuting\\lefty.bmp");
	loadimage(cutImgY + 1, "Cuting\\righty.bmp");
}
//����ɫվ��
void drawRole_Stand()
{
	//͸����ͼ
	putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
	//SRCAND
	putimage(saber.x, saber.y, 400, 300, standImgY + saber.postion, 0, 0, SRCAND);
	//SRCPAINT
	putimage(saber.x, saber.y, 400, 300, standImg + saber.postion, 0, 0, SRCPAINT);
}
//�ƶ�
void drawRole_Move(int frameNum)
{
	for (int i = 0; i < frameNum; i++)
	{
		BeginBatchDraw();                //д���ڴ�
		putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
		//SRCAND
		putimage(saber.x, saber.y, 400, 300, moveImgY + saber.postion, 400 * i, 0, SRCAND);
		//SRCPAINT
		putimage(saber.x, saber.y, 400, 300, moveImg + saber.postion, 400 * i, 0, SRCPAINT);
		Sleep(50);
		EndBatchDraw();                 //�ͷ��ڴ�
	}
}
//��
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
//����
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
//��
void drawRole_Cut(int frameNum)
{
	for (int i = 0; i < frameNum; i++)
	{
		BeginBatchDraw();
		putimage(0, 0, 1000, 650, &backgeound, img.x, 0);
		//SRCAND
		putimage(saber.x, saber.y, 400, 300, cutImgY + saber.postion, 400 * i, 0, SRCAND);
		//SRCPAINT
		putimage(saber.x, saber.y, 400, 300, cutImg + saber.postion, 400 * i, 0, SRCPAINT);
		Sleep(50);
		EndBatchDraw();
	}
}
//�ı�λ��
void moveRole()
{
	switch (saber.postion)
	{
	case right:
		saber.x += 30;
		//img.x -= 30;           //�˲����������ƶ�
		break;
	case left:
		saber.x -= 30;
		//img.x += 30;           //�˲����������ƶ�
		break;
	}
}
//��������
void keyDown()
{
	char userKey = _getch();
	switch (userKey)
	{
	case 'A':          //����
	case 'a':
	case 75:
		saber.postion = left;
		moveRole();
		drawRole_Move(8);
		break;
	case 'd':          //����
	case 'D':
	case 77:
		saber.postion = right;
		moveRole();
		drawRole_Move(8);
		break;
	case 'j':           //��
	case 'J':
		drawRole_Jump(8);
		break;
	case 'k':           //����
	//case 'K':
		drawRole_JumpCut(8);
		break;
	case 'l':           //��
	case 'L':
		drawRole_Cut(8);
		break;
	}

}

int main(void)
{
	loadResource();       //������Դ
	initgraph(1000, 650);  //��������
	while (1)
	{
		drawRole_Stand();
		if (_kbhit())
		{
			keyDown();
		}
	}
	drawRole_Stand();     //��վ��������  ����ʼ�Ļ��棩
	_getch();

	closegraph();

	return 0;
}
