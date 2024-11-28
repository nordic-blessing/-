#pragma once
#include "common.h"
#include "transparentdraw.h"//透明绘图
//===============================================================================================
// 名称：透明矩形按钮
// 作者：nordic-blessing
// 主要功能：封装按钮功能(绘制，变色，点击）
// 格式：
//		Button* 按钮名称 = creatButton(x, y, w, h,
//			text, text_inColor, text_outColor, textFont, textH,
//			outcolor, incolor);
//		drawButton(按钮名称);
//		peekmessage(&m, EM_MOUSE);
//		if(isClickButton(按钮名称, m)) {}
//===============================================================================================
//结构体
struct Button
{
	int x;						//初始坐标 X
	int y;						//初始坐标 X
	int w;						//宽
	int h;						//高
	COLORREF curColor;			//当前按钮颜色
	COLORREF inColor;			//鼠标悬停时按钮的颜色
	COLORREF outColor;			//鼠标不在时按钮的颜色
	char* text;					//文字
	COLORREF text_curColor;		//当前文字颜色
	COLORREF text_outColor;		//鼠标悬停时文字的颜色
	COLORREF text_inColor;		//鼠标不在时文字的颜色
	LPCTCH textFont;			//字体
	int textH;					//文字高度
};
//创建按钮（动态内存分配）
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
//画按钮
void drawButton(struct Button* pB)
{
	rec(pB->x, pB->y, pB->x + pB->w, pB->y + pB->h, pB->curColor);
	settextcolor(pB->text_curColor);
	setbkmode(TRANSPARENT);
	ANTIALIASED_QUALITY;
	settextstyle(pB->textH, 0, pB->textFont);
	int textW = textwidth(pB->text);		//文
	int textH = textheight(pB->text);		//字
	int xx = pB->x + (pB->w - textW) / 2;	//居
	int yy = pB->y + (pB->h - textH) / 2;	//中
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
//鼠标是否在按钮中
bool isInButton(struct Button* pB, ExMessage m)
{
	if (m.x > pB->x && m.x < pB->x + pB->w
		&& m.y > pB->y && m.y < pB->y + pB->h)
	{
		pB->curColor = pB->inColor;//调整按钮颜色
		pB->text_curColor = pB->text_inColor;//调整文字颜色
		return true;
	}
	pB->curColor = pB->outColor;//还原按钮颜色
	pB->text_curColor = pB->text_outColor;//还原文字颜色
	return false;
}
//鼠标点击
bool isClickButton(struct Button* pB, ExMessage m)
{
	if (isInButton(pB, m) && m.message == WM_LBUTTONDOWN)
	{
		//点击音效
		PlaySound("sound/click.wav", NULL, SND_FILENAME | SND_ASYNC);
		m.message = 0;
		return true;
	}
	return false;
}