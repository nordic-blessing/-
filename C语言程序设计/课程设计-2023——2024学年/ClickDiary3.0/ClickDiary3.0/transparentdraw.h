#pragma once
#include "common.h"
// 初始换透明度百分比为 50 也就是 128。
int alpha = 128;
// 设置半透明度函数。
void setalpha(int al) { alpha = al; }
// 打开缓冲区。
DWORD* g_pBuf11;
// 进行前景色和背景色半透明计算。
COLORREF Alphargb1(int r1, int g1, int b1, int r2, int g2, int b2, int alp)
{	// 替换颜色。
	alp = alpha;
	// 半透明颜色混合计算算法。（村长修改的特殊算法，使用位移算法，能提高效率）
	COLORREF rgb_alpha = RGB
	(
		(r1 * alp + r2 * (256 - alp)) >> 8,
		(g1 * alp + g2 * (256 - alp)) >> 8,
		(b1 * alp + b2 * (256 - alp)) >> 8
	);
	// 返回颜色。
	return rgb_alpha;
}
// 显示缓冲区指针，并读取坐标上的颜色值。
COLORREF fast_getpixelcolor(int x, int y, int WIDTH) { COLORREF c = g_pBuf11[y * WIDTH + x]; return BGR(c); }
// 快速缓冲区半透明画点函数 2
void putpixealpha(DWORD* g_pBuf, int x, int y, COLORREF c)
{
	int WIDTH = getwidth(), HEIGHT = getheight(), puti = y * WIDTH + x;
	// 如果 puti 超出缓冲区范围，直接返回。
	if (puti < 0 || puti >= (WIDTH * HEIGHT)) { return; }
	COLORREF backdropcolor, bkcolor = getbkcolor();
	// 读取背景上的颜色点。
	backdropcolor = fast_getpixelcolor(x, y, WIDTH);
	// 声明定义背景颜色和绘图的颜色。
	int r2 = GetRValue(c), g2 = GetGValue(c), b2 = GetBValue(c), r1 = GetRValue(backdropcolor), g1 = GetGValue(backdropcolor), b1 = GetBValue(backdropcolor);

	// 如果获取的颜色等于背景色不进行透明计算。
	if (bkcolor == backdropcolor) { g_pBuf[puti] = BGR(c); }
	// 透明颜色混合并输出。
	if (backdropcolor != bkcolor) { g_pBuf[puti] = BGR(Alphargb1(r2, g2, b2, r1, g1, b1, 128)); }
}

// 画支持透明的矩形。
void rec(int x1, int y1, int x2, int y2, COLORREF c)
{	// 获取绘图区宽度。
	int WIDTH = getwidth();	g_pBuf11 = GetImageBuffer();
	for (int i = y1; i < y1 + (y2 - y1); i++)
		for (int j = x1; j < x1 + (x2 - x1); j++)
			putpixealpha(g_pBuf11, j, i, c);
}
