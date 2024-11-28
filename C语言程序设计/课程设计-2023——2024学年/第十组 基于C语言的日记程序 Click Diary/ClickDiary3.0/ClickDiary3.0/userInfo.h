#pragma once
#include "common.h"
//===============================================================================================
// 名称：日记格式
// 作者：nordic-blessing
// 时间：2023/12/12/2:10pm
//===============================================================================================
struct Date
{
	char year[4];
	char month[2];
	char day[2];
	char weekday[10];
};
struct Diary
{
	struct Date date;
	char content[2000];
	char weather[11];
	char mood[11];
	char title[21];
	char date_copy[17];
};

//===============================================================================================
// 名称：用户信息格式
// 作者：nordic-blessing
// 时间：2023/12/3/2:10pm
//===============================================================================================
//用户基本信息
struct User
{
	char account[21] = { 0 };
	char password[21] = { 0 };
	char name[11] = { 0 };
	Date birthday;
	char email[30] = { 0 };
	char telephone[12] = { 0 };
};
//用户个性化设置信息,音乐路径，主题颜色，主题亮色，日技数，账户，密码，昵称，生日，邮件，电话
struct Userset
{
	char music_path[100];
	COLORREF theme_color;
	COLORREF theme_colorlight;
	int diary_writeN = 0;
	
};