#pragma once
#include "common.h"
// ��ʼ��͸���Ȱٷֱ�Ϊ 50 Ҳ���� 128��
int alpha = 128;
// ���ð�͸���Ⱥ�����
void setalpha(int al) { alpha = al; }
// �򿪻�������
DWORD* g_pBuf11;
// ����ǰ��ɫ�ͱ���ɫ��͸�����㡣
COLORREF Alphargb1(int r1, int g1, int b1, int r2, int g2, int b2, int alp)
{	// �滻��ɫ��
	alp = alpha;
	// ��͸����ɫ��ϼ����㷨�����峤�޸ĵ������㷨��ʹ��λ���㷨�������Ч�ʣ�
	COLORREF rgb_alpha = RGB
	(
		(r1 * alp + r2 * (256 - alp)) >> 8,
		(g1 * alp + g2 * (256 - alp)) >> 8,
		(b1 * alp + b2 * (256 - alp)) >> 8
	);
	// ������ɫ��
	return rgb_alpha;
}
// ��ʾ������ָ�룬����ȡ�����ϵ���ɫֵ��
COLORREF fast_getpixelcolor(int x, int y, int WIDTH) { COLORREF c = g_pBuf11[y * WIDTH + x]; return BGR(c); }
// ���ٻ�������͸�����㺯�� 2
void putpixealpha(DWORD* g_pBuf, int x, int y, COLORREF c)
{
	int WIDTH = getwidth(), HEIGHT = getheight(), puti = y * WIDTH + x;
	// ��� puti ������������Χ��ֱ�ӷ��ء�
	if (puti < 0 || puti >= (WIDTH * HEIGHT)) { return; }
	COLORREF backdropcolor, bkcolor = getbkcolor();
	// ��ȡ�����ϵ���ɫ�㡣
	backdropcolor = fast_getpixelcolor(x, y, WIDTH);
	// �������屳����ɫ�ͻ�ͼ����ɫ��
	int r2 = GetRValue(c), g2 = GetGValue(c), b2 = GetBValue(c), r1 = GetRValue(backdropcolor), g1 = GetGValue(backdropcolor), b1 = GetBValue(backdropcolor);

	// �����ȡ����ɫ���ڱ���ɫ������͸�����㡣
	if (bkcolor == backdropcolor) { g_pBuf[puti] = BGR(c); }
	// ͸����ɫ��ϲ������
	if (backdropcolor != bkcolor) { g_pBuf[puti] = BGR(Alphargb1(r2, g2, b2, r1, g1, b1, 128)); }
}

// ��֧��͸���ľ��Ρ�
void rec(int x1, int y1, int x2, int y2, COLORREF c)
{	// ��ȡ��ͼ����ȡ�
	int WIDTH = getwidth();	g_pBuf11 = GetImageBuffer();
	for (int i = y1; i < y1 + (y2 - y1); i++)
		for (int j = x1; j < x1 + (x2 - x1); j++)
			putpixealpha(g_pBuf11, j, i, c);
}
