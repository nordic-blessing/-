#pragma once
#include "common.h"
//===============================================================================================
// ���ƣ��ռǸ�ʽ
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/12/2:10pm
//===============================================================================================
struct Date
{
	char year[5];
	char month[3];
	char day[3];
	char weekday[13];
};
struct Diary
{
	struct Date date;
	char content[2000];
	char weather[20];
	char mood[20];
	char title[21];
	char date_copy[30];
};
//===============================================================================================
// ���ƣ��û���Ϣ��ʽ
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/3/2:10pm
//===============================================================================================
//�û�������Ϣ
struct User
{
	char account[21] = { 0 };
	char password[21] = { 0 };
	char name[11] = { 0 };
	char year[5];
	char month[3];
	char day[3];
	char email[30] = { 0 };
	char telephone[12] = { 0 };
};
//�û����Ի�������Ϣ
struct Userset
{
	char music_path[100];
	COLORREF theme_color;
	COLORREF theme_colorlight;
	int diary_writeN = 0;
};