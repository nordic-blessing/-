#pragma once
#include "common.h"
#include "transparentdraw.h"//͸����ͼ
//===============================================================================================
// ���ƣ�͸�����ΰ�ť
// ���ߣ�nordic-blessing
// ��Ҫ���ܣ���װ��ť����(���ƣ���ɫ�������
// ��ʽ��
//		Button* ��ť���� = creatButton(x, y, w, h,
//			text, text_inColor, text_outColor, textFont, textH,
//			outcolor, incolor);
//		drawButton(��ť����);
//		peekmessage(&m, EM_MOUSE);
//		if(isClickButton(��ť����, m)) {}
//===============================================================================================
//�ṹ��
struct Button
{
	int x;						//��ʼ���� X
	int y;						//��ʼ���� X
	int w;						//��
	int h;						//��
	COLORREF curColor;			//��ǰ��ť��ɫ
	COLORREF inColor;			//�����ͣʱ��ť����ɫ
	COLORREF outColor;			//��겻��ʱ��ť����ɫ
	char* text;					//����
	COLORREF text_curColor;		//��ǰ������ɫ
	COLORREF text_outColor;		//�����ͣʱ���ֵ���ɫ
	COLORREF text_inColor;		//��겻��ʱ���ֵ���ɫ
	LPCTCH textFont;			//����
	int textH;					//���ָ߶�
};
//������ť����̬�ڴ���䣩
Button* creatButton(int x, int y, int w, int h,
	const char* str, COLORREF text_outColor, COLORREF text_inColor, LPCTCH textFont, int textH,
	COLORREF outColor, COLORREF inColor)
{
	Button* pB = (Button*)malloc(sizeof(Button));
	if (pB)
	{
		pB->x = x;
		pB->y = y;
		pB->w = w;
		pB->h = h;
		pB->textH = textH;
		pB->text_curColor = text_outColor;
		pB->text_outColor = text_outColor;
		pB->text_inColor = text_inColor;
		pB->textFont = textFont;
		pB->outColor = outColor;
		pB->inColor = inColor;
		pB->curColor = pB->outColor;
		int textLength = strlen(str) + 1;
		pB->text = (char*)malloc(sizeof(char) * textLength);
		if (pB->text)
		{
			strcpy_s(pB->text, textLength, str);
		}
	}
	return pB;
}
//����ť
void drawButton(struct Button* pB)
{
	rec(pB->x, pB->y, pB->x + pB->w, pB->y + pB->h, pB->curColor);
	settextcolor(pB->text_curColor);
	setbkmode(TRANSPARENT);
	ANTIALIASED_QUALITY;
	settextstyle(pB->textH, 0, pB->textFont);
	int textW = textwidth(pB->text);		//��
	int textH = textheight(pB->text);		//��
	int xx = pB->x + (pB->w - textW) / 2;	//��
	int yy = pB->y + (pB->h - textH) / 2;	//��
	outtextxy(xx, yy, pB->text);
}
void drawButton_left(struct Button* pB)
{
	rec(pB->x, pB->y, pB->x + pB->w, pB->y + pB->h, pB->curColor);
	settextcolor(pB->text_curColor);
	setbkmode(TRANSPARENT);
	ANTIALIASED_QUALITY;
	settextstyle(pB->textH, 0, pB->textFont);
	int textH = textheight(pB->text);
	int xx = pB->x + 20;
	int yy = pB->y + (pB->h - textH) / 2;
	outtextxy(xx, yy, pB->text);
}
//����Ƿ��ڰ�ť��
bool isInButton(struct Button* pB, ExMessage m)
{
	if (m.x > pB->x && m.x < pB->x + pB->w
		&& m.y > pB->y && m.y < pB->y + pB->h)
	{
		pB->curColor = pB->inColor;//������ť��ɫ
		pB->text_curColor = pB->text_inColor;//����������ɫ
		return true;
	}
	pB->curColor = pB->outColor;//��ԭ��ť��ɫ
	pB->text_curColor = pB->text_outColor;//��ԭ������ɫ
	return false;
}
//�����
bool isClickButton(struct Button* pB, ExMessage m)
{
	if (isInButton(pB, m) && m.message == WM_LBUTTONDOWN)
	{
		//�����Ч
		PlaySound("sound/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		m.message = 0;
		return true;
	}
	return false;
}