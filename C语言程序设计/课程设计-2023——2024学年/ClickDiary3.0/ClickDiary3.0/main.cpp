//===============================================================================================
// 名称：Click
// 作者：nordic-blessing & whynotwhat & komorebi & 败败
// 主要功能：日记 & 音乐 & 虚拟人
// 开工时间：2023/11/30/11:30 am
// 完工时间：
//===============================================================================================
#include "common.h"
#include "button.h"
#include "userInfo.h"
#include "musicplay.h"
#include "transparentdraw.h"

void Login();		//登录
void Menu();		//主页
void ToRegister();	//注册
void Write();		//创作
void Set();			//设置
void Look();		//浏览
void Me();			//我的信息页面

ExMessage m;																	//用于鼠标消息
COLORREF themecolor = RGB(1, 122, 213);											//主题颜色初始化
COLORREF themecolor_1 = RGB(93, 200, 255);										//主题浅色初始化
char bgm_path[100] = "music/你的名字.mp3";										//音乐地址初始化
User read_user;																	//用户信息（已登录）
Userset read_set = { "music/你的名字.mp3",RGB(1, 122, 213) ,RGB(93, 200, 255) };	//用户设置初始化
char filename_set[20];															//用于储存用户设置的文件地址
char filename_diary[20];														//用于储存用户日记的文件地址
char bgm[100];																	//用于储存音乐地址
Diary new_diary;																//用于储存新日记的“容器”
int diary_N = 0;

//===============================================================================================
// 名称：错误提醒
// 作者：nordic-blessing
// 时间：2023/12/5/3:10pm
//===============================================================================================
void error(int error_x, int error_y)
{
	setfillcolor(RED);
	solidcircle(error_x, error_y, 6);
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	line(error_x - 3, error_y - 3, error_x + 3, error_y + 3);
	line(error_x - 3, error_y + 3, error_x + 3, error_y - 3);
}
void correct(int correct_x, int correct_y)
{
	setfillcolor(GREEN);
	solidcircle(correct_x, correct_y, 6);
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	line(correct_x - 3, correct_y, correct_x, correct_y + 3);
	line(correct_x, correct_y + 3, correct_x + 3, correct_y - 3);
}
//===============================================================================================
// 名称：抗锯齿文字输出
// 作者：nordic-blessing
// 时间：2023/12/5/3:10pm
//===============================================================================================
void puttext(int x, int y, const char* text, int lfHight, LPCTSTR font, COLORREF color, int nWeight = 0)
{
	LOGFONT f;
	gettextstyle(&f);
	//设置文字高度
	f.lfHeight = lfHight;
	//设置字体
	_tcscpy(f.lfFaceName, font);
	//设置文字粗细，默认值为0
	f.lfWeight = nWeight;
	//抗锯齿
	f.lfQuality = ANTIALIASED_QUALITY;
	//设置文字颜色
	settextcolor(color);
	//设置文字背景为透明
	setbkmode(TRANSPARENT);
	settextstyle(&f);
	//输出文字
	outtextxy(x, y, text);
}
//===============================================================================================
// 名称：注册_ToRegister()
// 作者：nordic-blessing
// 时间：2023/12/12/8:47pm
//===============================================================================================
const COLORREF register_gray = RGB(233, 234, 235);
const COLORREF register_gray_1 = RGB(246, 246, 246);
const COLORREF register_text = RGB(117, 117, 117);
void ToRegister()
{
	User newUser[1] = {0};
	setbkcolor(WHITE);
	clearrectangle(0, 0, 800, 600);
	//顶部标题矩形
	setfillcolor(themecolor);
	fillrectangle(0, 0, 800, 60);
	//“Click | Enjoy everyday”
	char title[] = "Click | Enjoy everyday";
	puttext(30, 15, title, 35, "Ink Draft", WHITE);
	//“注册”
	char welcom[] = "欢 迎 注 册 Click  ";
	puttext(400 - (textwidth(welcom) / 2), 70, welcom, 30, "千图笔锋手写体", BLACK, 100);
	setlinecolor(themecolor);
	setlinestyle(PS_SOLID, 2);
	line(400 - 4 - textwidth(welcom) / 2, 98, 400 + 4 + textwidth(welcom) / 2, 98);
	//“生日”“年”“月”“日”
	char birthday[] = "生 日";
	puttext(400 - 105 - textwidth(birthday) / 2, 442 - textheight(birthday) / 2, birthday, 20, "宋体", BLACK);
	//按钮
	//创建按钮
	Button* submit = creatButton(400 - 35, 600 - 60, 70, 44, 
		"注 册", WHITE, WHITE, "宋体", 15,
		themecolor, themecolor_1);
	Button* name_create = creatButton(400 - 140, 120, 280, 44, 
		"昵 称", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* account_create = creatButton(400 - 140, 180, 280, 44, 
		"账 号", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* password_create = creatButton(400 - 140, 240, 280, 44, 
		"密 码", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* password_create_check = creatButton(400 - 140, 300, 280, 44, 
		"确 认 密 码", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* email_create = creatButton(400 - 140, 360, 280, 44, 
		"邮 箱", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* birthday_year_create = creatButton(400 - 70, 420, 60, 44, 
		"2005", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* birthday_month_create = creatButton(400, 420, 60, 44, 
		"1", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* birthday_day_create = creatButton(400 + 70, 420, 60, 44, 
		"14", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* telephone_create = creatButton(400 - 140, 480, 280, 44, 
		"手机", register_text, register_text, "宋体", 15,
		register_gray, register_gray_1);
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "宋体", 13,
		RGB(255, 255, 255), RGB(254, 225, 136));
	BeginBatchDraw();
	while (1)
	{
		drawButton(submit);
		drawButton(name_create);
		drawButton(account_create);
		drawButton(password_create);
		drawButton(password_create_check);
		drawButton(email_create);
		drawButton(birthday_year_create);
		drawButton(birthday_month_create);
		drawButton(birthday_day_create);
		drawButton(telephone_create);
		drawButton(account_create);
		drawButton(exit);
		peekmessage(&m, EM_MOUSE);
		if (isClickButton(name_create, m))
		{
			setcolor(WHITE);
			clearrectangle(400 + 140 + 8 , 120 , 400 + 140 + 8 + 6 + 4 + 200, 120 + 44);
			InputBox(newUser->name, 10, "请设置登录昵称\n（不超过10个字符，可使用字母、数字、下划线）");
			//将按钮上的文字更改为输入
			if(strlen(newUser->name) > 0)
			{
				correct(400 + 140 + 8, 120 + 22);
				strcpy(name_create->text, newUser->name);
			}
			else
			{
				error(400 + 140 + 8, 120 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 142-6, "请设置昵称", 13, "宋体", RED);
				strcpy(name_create->text, "昵 称");
			}
		}
		if (isClickButton(account_create, m))
		{
			setcolor(WHITE);
			clearrectangle(400 + 140 + 8, 180, 400 + 140 + 8 + 6 + 4 + 200, 180 + 44);
			//输入账号
			InputBox(newUser->account, 20, "请设置登录账号\n（不超过20个字符，可使用字母、数字、下划线）");
			//将按钮上的文字更改为输入
			if (strlen(newUser->account) > 0)
			{
				correct(400 + 140 + 8, 180 + 22);
				strcpy(account_create->text, newUser->account);
			}
			else
			{
				error(400 + 140 + 8, 180 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 202 - 6, "请设置账号", 13, "宋体", RED);
				strcpy(name_create->text, "登 录");
			}
		}
		char setpassword[21];
		if (isClickButton(password_create, m))
		{
			setcolor(WHITE);
			clearrectangle(400 + 140 + 8, 240, 400 + 140 + 8 + 6 + 4 + 200, 240 + 44);
			InputBox(setpassword, 21, "请设置登录密码\n（不超过20个字符，可使用字母、数字、下划线，注意字母区分大小写）");
			//将按钮上的文字更改为输入
			if (strlen(setpassword) > 0)
			{
				strcpy(password_create->text, setpassword);
				//获取密码的长度
				int i = strlen(setpassword);
				//将输入的密码转换为"*"输出
				for (int j = 1; j <= i; j++)
				{
					password_create->text[j - 1] = '*';
				}
				correct(400 + 140 + 8, 240 + 22);
			}
			else
			{
				error(400 + 140 + 8, 240 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 262 - 6, "请设置密码", 13, "宋体", RED);
				strcpy(name_create->text, "密 码");
			}
		}
		char checkpassword[21];
		if (isClickButton(password_create_check, m))
		{
			setbkcolor(WHITE);
			clearrectangle(400 + 140 + 8, 300, 400 + 140 + 8 + 6 + 4 + 200, 300 + 44);
			InputBox(checkpassword, 21, "请确认登录密码");
			if (strlen(checkpassword) > 0)
			{
				//将按钮上的文字更改为输入
				strcpy(password_create_check->text, checkpassword);
				//将输入的密码转换为相同长度的"*"输出
				for (int j = 1; j <= strlen(checkpassword); j++)
				{
					password_create_check->text[j - 1] = '*';
				}
			}
			else
			{
				error(400 + 140 + 8, 300 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 322 - 6, "请确认密码", 13, "宋体", RED);
				strcpy(password_create_check->text, "确 认 密 码");
				continue;
			}
			if ((strcmp(setpassword, checkpassword) != 0))
			{
				error(400 + 140 + 8, 300 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 322 - 6, "密码不一致，请重新确认", 13, "宋体", RED);
			}
			else
			{
				correct(400 + 140 + 8, 300 + 22);
				strcpy(newUser->password, checkpassword);
			}
		}
		if (isClickButton(email_create, m))
		{
			setcolor(WHITE);
			clearrectangle(400 + 140 + 8, 360, 400 + 140 + 8 + 6 + 4 + 200, 360 + 44);
			InputBox(newUser->email, 20, "请设置邮箱地址");
			if (strlen(newUser->email)>0)
			{
				correct(400 + 140 + 8, 360 + 22);
				strcpy(email_create->text, newUser->email);
			}
			else
			{

			}
		}
		if (isClickButton(birthday_year_create, m))
		{
			setcolor(WHITE);
			InputBox(newUser->year, 5, "请输入年");
			if (strlen(newUser->year)>0)
			{
				strcpy(birthday_year_create->text, newUser->year);
			}
			else
			{
				strcpy(birthday_year_create->text, "2005");
			}
		}
		if (isClickButton(birthday_month_create, m))
		{
			setcolor(WHITE);
			InputBox(newUser->month, 3, "请输入月");
			if (strlen(newUser->month) > 0)
			{
				strcpy(birthday_month_create->text, newUser->month);
			}
			else
			{
				strcpy(birthday_month_create->text, "1");
			}
		}
		if (isClickButton(birthday_day_create, m))
		{
			setcolor(WHITE);
			clearcircle(400 + 130 + 8, 420 + 22, 6);
			InputBox(newUser->day, 3, "请输入日");
			if (strlen(newUser->day) > 0)
			{
				strcpy(birthday_day_create->text, newUser->day);
			}
			else
			{
				strcpy(birthday_day_create->text, "14");
			}
			if (strlen(newUser->year) == 0
				&& strlen(newUser->month) == 0
				&& strlen(newUser->day) == 0)
			{
				error(400 + 130 + 8, 420 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 442 - 6, "请设置生日", 13, "宋体", RED);
			}
		}
		if (isClickButton(telephone_create, m))
		{
			setcolor(WHITE);
			clearcircle(400 + 140 + 8, 480 + 22, 6);
			InputBox(newUser->telephone, 12, "请设置手机号码");
			if (strlen(newUser->telephone) > 0)
			{
				correct(400 + 140 + 8, 480 + 22);
				strcpy(telephone_create->text, newUser->telephone);
			}
		}
		if (isClickButton(submit, m))
		{
			if (strlen(newUser->account) > 0 && strlen(newUser->password) > 0)
			{
				//写入用户信息
				ofstream fin("userdata.dat", ios::binary | ios::app);
				if (!fin.is_open())
				{
					MessageBox(GetHWnd(), "文件打开失败！", "错误", MB_ICONERROR | MB_OK);
				}
				else
				{
					fin.write((char*)&newUser, sizeof(User));
					fin.close();
				}
				Sleep(880);
				Login();
				m.message = 0;
			}
			if (strlen(newUser->account) == 0 && strlen(newUser->password) == 0)
			{
				m.message = 0;
				MessageBox(GetHWnd(), "请设置登录账号和密码！", "错误", MB_ICONERROR | MB_OK);
				continue;
			}
			if (strlen(newUser->account) == 0)
			{
				m.message = 0;
				MessageBox(GetHWnd(), "请设置登录账号！", "错误", MB_ICONERROR | MB_OK);
				continue;
			}
			if (strlen(newUser->password) == 0)
			{
				m.message = 0;
				MessageBox(GetHWnd(), "请设置登录密码！", "错误", MB_ICONERROR | MB_OK);
				continue;
			}
		}
		if (isClickButton(exit, m))
		{
			Sleep(150);
			printf("退出注册\n\n");
			m.message = 0;
			Login();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// 名称：登录_Login()
// 作者：nordic-blessing
// 时间：2023/11/30/8:47pm
//===============================================================================================
const COLORREF login_gray = RGB(233, 234, 235);
const COLORREF login_gray_1 = RGB(246, 246, 246);
const COLORREF login_text = RGB(117, 117, 117);
void Login()
{
	char account_cin[21]="";
	char password_cin[21]="";
	//创建按钮
	//账号
	Button* account = creatButton(400 - 140, 300 + 60 * -1, 280, 44, 
		"账号", login_text, WHITE, "宋体", 15,
		login_gray, login_gray_1);
	//密码
	Button* password = creatButton(400 - 140, 300 + 10, 280, 44, 
		"密码", login_text, WHITE, "宋体", 15,
		login_gray, login_gray_1);
	//登录
	Button* login = creatButton(400 + 70 * -1, 300 + 80, 140, 44,
		"登录", WHITE, WHITE, "宋体", 20,
		themecolor_1, themecolor);
	//注册
	Button* toRegister = creatButton(400 - 70, 300 + 136, 140, 44, 
		"注册", WHITE, WHITE, "宋体", 20,
		themecolor_1, themecolor);
	//开始绘制
	g_pBuf11 = GetImageBuffer();
	// 缓冲区获取。
	DWORD* g_pBuf = GetImageBuffer();
	// 设置透明度百分比为 50 也就是 128。
	setalpha(128);
	BeginBatchDraw();
	IMAGE* img = new IMAGE[105];
	char path[30] = { 0 };
	int i;
	for (i = 0;i<104*4;i++)
	{
			int n = i / 4;
			sprintf_s(path, "login_back/%04d.jpg", n);
			loadimage(&img[n], path, 800, 600);
			putimage(0, 0, &img[n]);
		if (i == 104*4-1)
		{
			i = 0;
		}
		//绘制登录界面
		//上标题
		//欢迎
		char welcom1[] = "记录美好生活";
		char welcom2[] = "| enjoy your days";
		puttext(400 + (textwidth(welcom1) + textwidth(welcom2)) / 2 * -1, 300 + 264 * -1,
			welcom1, 25, "千图笔锋手写体", WHITE);
		puttext(400 + (textwidth(welcom1) + textwidth(welcom2)) / 2 * -1 + textwidth(welcom1), 300 - 264,
			welcom2, 36, "Ink Draft", WHITE, 200);
		//线
		setlinecolor(themecolor);
		setlinestyle(PS_SOLID, 3);
		line(400 - (textwidth(welcom1) + textwidth(welcom2)) / 2, 300 + 232 * -1, 
			400 + (textwidth(welcom1) + textwidth(welcom2)) / 2, 300 + 232 * -1);
		//头像
		setfillcolor(login_gray);
		solidcircle(400 + 0, 300 + 160 * -1, 50);
		//Click
		char title[] = "Click     ";
		puttext(400 - textwidth(title) / 2, 300 + 115 * -1, title, 60, "Ink Draft", WHITE);
		drawButton(login);
		drawButton(account);
		drawButton(password);
		drawButton(toRegister);
		peekmessage(&m, EM_MOUSE);
		if (isClickButton(account, m))
		{
			setbkcolor(WHITE);
			clearcircle(400 + 140 + 8, 262, 6);
			InputBox(account_cin, 20, "账号");
			if (!account_cin[0] == '\0')
			{
				strcpy(account->text, account_cin);
			}
			printf("输入账号 %s\n", account_cin);
		}
		if (isClickButton(password, m))
		{
			InputBox(password_cin, 20, "密码");
			if(!password_cin[0]=='\0')
			{
				strcpy(password->text, password_cin);
				printf("输入密码 %s\n", password_cin);
				int i = strlen(password_cin);
				for (int j = 1; j <= i; j++)
				{
					password->text[j - 1] = '*';
				}
			}
		}
		if (isClickButton(login, m))
		{
			ifstream fin_login("userdata.dat", ios::binary);
			if (!fin_login.is_open())
			{
				MessageBox(GetHWnd(), "文件打开失败！", "错误", MB_ICONERROR | MB_OK);
			}
			int n = 0;
			char i[21] = "";
			while (fin_login.read((char*)&read_user, sizeof(User)))
			{
				if (strcmp(read_user.account, account_cin) == 0)
				{
					if (strcmp(read_user.password, password_cin) == 0)
					{
						printf("登录成功！\n");
						//清除登录框的输入
						memset(account_cin, 0, sizeof(account_cin));
						memset(password_cin, 0, sizeof(password_cin));
						//读入此用户的设置
						sprintf(filename_set, "%s_set.dat", read_user.name);
						ifstream fin(filename_set, ios::binary);
						if (!fin.is_open())
						{
							fin_login.close();
							ofstream fout(filename_set, ios::binary);
							fout.write((char*)&read_set, sizeof(Userset));
							fout.close();
							Menu();
						}
						fin.read((char*)&read_set, sizeof(Userset));
						themecolor = read_set.theme_color;
						themecolor_1 = read_set.theme_colorlight;
						musicplay(bgm_path, true, 200, true);
						strcpy(bgm_path, read_set.music_path);
						musicplay(bgm_path, true, 200);
						fin_login.close();
						fin.close();
						Menu();
					}
					else
					{
						m.message = 0;
						MessageBox(GetHWnd(), "登录失败!\n密码错误！", "警告", MB_OK);
						printf("登录失败！\n密码错误！\n");
						break;
					}
				}
				if (strcmp(i,read_user.account)==0)
				{
					printf("未找到用户！\n");
					fin_login.close();
					MessageBox(GetHWnd(), "账号不存在！", "错误", MB_ICONERROR | MB_OK);
					m.message = 0;
					break;
				}
				else
				{
					strcpy(i, read_user.account);
					fin_login.seekg(sizeof(User), ios::beg);  // 将文件指针定位到下一个User结构体的开头位置
				}
			}
		}
		if (isClickButton(toRegister, m))
		{
			printf("注册");
			m.message = 0;
			ToRegister();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// 名称：主页_Menu()
// 作者：nordic-blessing
// 时间：2023/12/2/11:34am
//===============================================================================================
const COLORREF menubk = RGB(245, 245, 245);
const COLORREF menu_gray = RGB(243, 243, 243);
const COLORREF menu_gray1 = RGB(236, 236, 235);
void Menu()
{
	setbkcolor(menubk);
	cleardevice();
	//顶部标题矩形
	setfillcolor(themecolor);
	solidrectangle(0, 0, 800, 60);
	//菜单栏背景
	setfillcolor(menu_gray1);
	solidrectangle(0, 60, 140, 600);
	//“Click | Enjoy everyday”
	puttext(30, 15, "Click | Enjoy everyday", 30, "Ink Draft", WHITE);
	//按钮
		//创建按钮
	Button* look = creatButton(0, 60, 140, 80, 
		"浏览", themecolor, WHITE, "微软雅黑", 22,
		menu_gray, themecolor);
	Button* set = creatButton(0, 140, 140, 80, 
		"设置", themecolor, WHITE, "微软雅黑", 22, 
		menu_gray, themecolor);
	Button* me = creatButton(0, 220, 140, 80, 
		"我", themecolor, WHITE, "微软雅黑", 22,
		menu_gray, themecolor);
	Button* write = creatButton(0, 510, 140, 80, 
		"+", BLACK, RGB(85, 85, 85), "微软雅黑", 25, 
		RGB(255, 255, 255), RGB(254, 225, 136));
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "宋体", 13, 
		RGB(255, 255, 255), RGB(254, 225, 136));
	//绘图
	BeginBatchDraw();
	while (1)
	{
		drawButton(look);
		drawButton(set);
		drawButton(me);
		drawButton(write);
		drawButton(exit);
		peekmessage(&m, EM_MOUSE);
		if (isClickButton(look, m))
		{
			Sleep(150);
			m.message = 0;
			Look();
		}
		if (isClickButton(me, m))
		{
			Sleep(150);
			m.message = 0;
			Me();
		}
		if (isClickButton(set, m))
		{
			Sleep(150);
			m.message = 0;
			Set();
		}
		if (isClickButton(write, m))
		{
			Sleep(150);
			m.message = 0;
			Write();
		}
		if (isClickButton(exit, m))
		{
			Sleep(150);
			m.message = 0;
			read_set.theme_color = themecolor;
			read_set.theme_colorlight = themecolor_1;
			strcpy(read_set.music_path, bgm_path);
			sprintf(filename_set, "%s_set.dat", read_user.name);
			ofstream fout(filename_set, ios::binary);
			if (!fout.is_open())
			{
				MessageBox(GetHWnd(), "文件打开失败！", "错误", MB_ICONERROR | MB_OK);
			}
			else
			{
				fout.write((char*)&read_set, sizeof(Userset));
				fout.close();
			}

			Login();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// 名称：设置_Set()
// 作者：nordic-blessing
// 时间：2023/12/6/9:43pm
//===============================================================================================
COLORREF set_box = RGB(245, 245, 245);
COLORREF set_box1 = RGB(229, 241, 251);
COLORREF theme_blue = RGB(1,122,213);
COLORREF theme_lightblue = RGB(65, 165, 238);
COLORREF theme_pink = RGB(255, 149, 176);
COLORREF theme_lightpink = RGB(255, 169, 199);
COLORREF theme_green = RGB(16, 124, 65);
COLORREF theme_lightgreen = RGB(33, 163, 102);
COLORREF theme_black = RGB(52, 56, 58);
COLORREF theme_lightblack = RGB(100, 108, 112);
COLORREF theme_purple = RGB(110, 79, 164);
COLORREF theme_lightpurple = RGB(204, 150, 248);
COLORREF theme_yellow = RGB(244, 165, 0);
COLORREF theme_lightyellow = RGB(255, 206, 68);
void Set()
{
	setbkcolor(menubk);
	clearrectangle(140, 60, 800, 600);
	puttext(165, 75, "主题", 20, "千图笔锋手写体", themecolor);
	puttext(165, 180, "背景音乐", 20, "千图笔锋手写体", themecolor);
	Button* blue_theme = creatButton(160 + 65, 105, 70, 40,
		"经典蓝", BLACK, WHITE, "宋体", 14,
		theme_blue, theme_lightblue);
	Button* pink_theme = creatButton(160 + 85 + 65, 105, 70, 40, 
		"桃桃粉", BLACK, WHITE, "宋体", 14,
		theme_pink, theme_lightpink);
	Button* green_theme = creatButton(160 + 85 * 2 + 65, 105, 70, 40, 
		"浅葱绿", BLACK, WHITE, "宋体", 14,
		theme_green, theme_lightgreen);
	Button* black_theme = creatButton(160 + 85 * 3 + 65, 105, 70, 40, 
		"极致黑", WHITE, BLACK, "宋体", 14,
		theme_black, theme_lightblack);
	Button* purple_theme = creatButton(160 + 85 * 4 + 65, 105, 70, 40, 
		"星辰紫", BLACK, WHITE, "宋体", 14,
		theme_purple, theme_lightpurple);
	Button* yellow_theme = creatButton(160 + 85 * 5 + 65, 105, 70, 40, 
		"盛夏黄", BLACK, WHITE, "宋体", 14,
		theme_yellow, theme_lightyellow);
	Button* music_path = creatButton(160 + 65, 210, 500, 30, 
		bgm_path, BLACK, WHITE, "宋体", 14,
		RGB(228, 228, 207), RGB(226, 226, 226));
	Button* save = creatButton(160 + 270, 560, 70, 30, 
		"保 存", WHITE, WHITE, "宋体", 14,
		themecolor, set_box1);
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "宋体", 13,
		RGB(255, 255, 255), RGB(254, 225, 136));
	BeginBatchDraw();
	while (1)
	{
		drawButton(blue_theme);
		drawButton(pink_theme);
		drawButton(green_theme);
		drawButton(black_theme);
		drawButton(purple_theme);
		drawButton(yellow_theme);
		drawButton(music_path);
		drawButton(save);
		drawButton(exit);
		peekmessage(&m, EM_MOUSE);
		if (isClickButton(blue_theme, m))
		{
			setbkcolor(menubk);
			clearrectangle(160 + 65, 105 + 40 + 6, 160 + 85 * 5 + 65 + 70, 105 + 40 + 6 * 3);
			themecolor = theme_blue;
			themecolor_1 = theme_lightblue;
			correct(160 + 65 + 35, 105 + 40 + 6 * 2);
			m.message = 0;
		}
		if (isClickButton(pink_theme, m))
		{
			setbkcolor(menubk);
			clearrectangle(160 + 65, 105 + 40 + 6, 160 + 85 * 5 + 65 + 70, 105 + 40 + 6 * 3);
			themecolor = theme_pink;
			themecolor_1 = theme_lightpink;
			correct(160 + 65 + 85 + 35, 105 + 40 + 6 * 2);
			m.message = 0;
		}
		if (isClickButton(green_theme, m))
		{
			setbkcolor(menubk);
			clearrectangle(160 + 65, 105 + 40 + 6, 160 + 85 * 5 + 65 + 70, 105 + 40 + 6 * 3);
			themecolor = theme_green;
			themecolor_1 = theme_lightgreen;
			correct(160 + 65 + 85 * 2 + 35, 105 + 40 + 6 * 2);
			m.message = 0;
		}
		if (isClickButton(black_theme, m))
		{
			setbkcolor(menubk);
			clearrectangle(160 + 65, 105 + 40 + 6, 160 + 85 * 5 + 65 + 70, 105 + 40 + 6 * 3);
			themecolor = theme_black;
			themecolor_1 = theme_lightblack;
			correct(160 + 65 + 85 * 3 + 35, 105 + 40 + 6 * 2);
			m.message = 0;
		}
		if (isClickButton(purple_theme, m))
		{
			setbkcolor(menubk);
			clearrectangle(160 + 65, 105 + 40 + 6, 160 + 85 * 5 + 65 + 70, 105 + 40 + 6 * 3);
			themecolor = theme_purple;
			themecolor_1 = theme_lightpurple;
			correct(160 + 65 + 85 * 4 + 35, 105 + 40 + 6 * 2);
			m.message = 0;
		}
		if (isClickButton(yellow_theme, m))
		{
			setbkcolor(menubk);
			clearrectangle(160 + 65, 105 + 40 + 6, 160 + 85 * 5 + 65 + 70, 105 + 40 + 6 * 4);
			themecolor = theme_yellow;
			themecolor_1 = theme_lightyellow;
			correct(160 + 65 + 85 * 5 + 35, 105 + 40 + 6 * 2);
			m.message = 0;
			FlushBatchDraw();
		}
		if (isClickButton(music_path, m))
		{
			m.message = 0;
			InputBox(bgm, 100, "请输入 .mp3 文件的路径：\n（请将文件提前存放于 music 文件夹中）", "music_path");
			if(strlen(bgm)>0)
			{
				strcpy(music_path->text, bgm);
			}
			else
			{
				strcpy(bgm_path, music_path->text);
			}
		}
		if (isClickButton(save, m))
		{
			m.message = 0;
			//更改背景音乐
			musicplay(bgm_path, true, 200, true);
			printf("原来的背景音乐 %s\n", bgm_path);
			strcpy(bgm_path, music_path->text);
			printf("现在的背景音乐 %s\n\n", bgm_path);
			musicplay(bgm_path, true, 200);
			//将设置存入文件
			read_set.theme_color = themecolor;
			read_set.theme_colorlight = themecolor_1;
			strcpy(read_set.music_path, bgm_path);
			sprintf(filename_set, "%s_set.dat", read_user.name);
			ofstream fout(filename_set, ios::binary);
			if (!fout.is_open())
			{
				MessageBox(GetHWnd(), "文件打开失败！", "错误", MB_ICONERROR | MB_OK);
			}
			else
			{
				fout.write((char*)&read_set, sizeof(Userset));
				fout.close();
			}
			Menu();
		}
		if (isClickButton(exit, m))
		{
			Sleep(150);
			m.message = 0;
			Menu();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// 名称：我_Me()
// 作者：whynotwhat
// 时间：2024/1/3/8：23pm
//===============================================================================================
void Me()
{
	//开始绘制界面
	settextcolor(themecolor);
	setbkmode(TRANSPARENT);
	settextstyle(22, 0, "宋体");
	outtextxy(940 / 2 - textwidth("个人空间") / 2, 70, "个人空间");
	outtextxy(200, 160, "昵称：");
	outtextxy(300, 160, read_user.name);
	outtextxy(200, 210, "邮件:");
	outtextxy(300, 210, read_user.email);
	outtextxy(200, 260, "电话号码:");
	outtextxy(300, 260, read_user.telephone);
	outtextxy(200, 310, "生日:");
	char birthday[40] = "";
	sprintf(birthday, "%s-%s-%s", read_user.year, read_user.month, read_user.day);
	outtextxy(300, 310, birthday);
}
//===============================================================================================
// 名称：浏览_Look()
// 作者：nordic-blessing
// 时间：2023/12/6/9:43pm
//===============================================================================================
COLORREF diary_color = RGB(216, 216, 215);
COLORREF diary_color1 = RGB(230, 230, 230);
char color_choice[5] = { theme_lightblue,theme_lightpink,theme_lightgreen,
	theme_lightpurple,theme_lightyellow };
/*int rand_color()
{
	// 使用当前时间作为随机数种子
	srand(time(NULL));
	// 生成一个在0到6之间的随机数
	int randomIndex = rand() % 7;
	//返回颜色选择结果
	return randomIndex;
}*/
void Look()
{
	char b1[200] = "您还没有写过日记";
	char b2[200] = "请先去创作吧";
	char b3[200] = "welcome to Click";
	char b4[200] = "记录生活点滴";
	
	//Diary* diary = new Diary[diary_N];
	Diary* diary = (Diary*)malloc(read_set.diary_writeN * sizeof(Diary));
	//读取日记
	diary_N = 0;
	sprintf(filename_diary, "%s_diary.txt", read_user.name);
	ifstream fin(filename_diary);
	if (!fin.is_open())
	{
		MessageBox(GetHWnd(), "您还未书写过您的生活点滴！\n快去写下你的第一篇Click吧", "错误", MB_ICONERROR | MB_OK);
		Menu();
	}
	char line[30];													//用于读取文件中的属性名称
	while (!fin.eof())												//循环读取，直至文件结束
	{
		fin >> line;												//读入分隔符
		if (strcmp(line, "=============================") != 0)
			break;												//未读到分隔符，转向下一次读取
		diary_N++;													//开始读取第diary_N篇日记
		fin >> line;												//读入日期属性
		fin.getline(diary[diary_N].date_copy, 17);
		fin >> line;												//读入标题属性
		fin.getline(diary[diary_N].title, 21);
		fin >> line;												//读入心情属性
		fin.getline(diary[diary_N].mood, 11);
		fin >> line;												//读入天气属性
		fin.getline(diary[diary_N].weather, 11);
		fin >> line;												//读入内容属性
		fin.getline(diary[diary_N].content, 2000, '`');
	}
	fin.close();

	//color_choice[rand_color()];
	setbkcolor(menubk);
	clearrectangle(140, 60, 800, 600);
	char look_title[30];
	sprintf(look_title, "您已记录了 %d 篇点滴", diary_N);
	puttext(180, 120, look_title, 23, "千图笔锋手写体", BLACK);
	Button* page_down = creatButton(770, 322, 30, 28,
		">", BLACK, WHITE, "宋体", 14,
		themecolor, themecolor_1);
	Button* page_up = creatButton(770, 290, 30, 28,
		"<", BLACK, WHITE, "宋体", 14,
		themecolor, themecolor_1);
	Button* exit = creatButton(770, 0, 30, 30,
		"!", BLACK, RGB(85, 85, 85), "宋体", 13,
		RGB(255, 255, 255), RGB(254, 225, 136));
	Button* diary1 = creatButton(170, 180, 570, 90,
		b1, BLACK, WHITE, "宋体", 12,
		diary_color1, diary_color);
	Button* diary2 = creatButton(170, 280, 570, 90,
		b2, BLACK, WHITE, "宋体", 12,
		diary_color1, diary_color);
	Button* diary3 = creatButton(170, 380, 570, 90,
		b3, BLACK, WHITE, "宋体", 12,
		diary_color1, diary_color);
	Button* diary4 = creatButton(170, 480, 570, 90,
		b4, BLACK, WHITE, "宋体", 12,
		diary_color1, diary_color);
	BeginBatchDraw();
	while (1)
	{
		int n1 = 1;
		int n2 = 2;
		int n3 = 3;
		int n4 = 4;
		renew:
		if (diary_N > 0)
		{
			sprintf(b1, "%s\t%s\t\t\t%.50s....", diary[n1].date_copy, diary[n1].title, diary[n1].content);
			strcpy(diary1->text, b1);
			if (diary_N > 1)
			{
				sprintf(b2, "%s\t%s\t\t\t%.50s....", diary[n2].date_copy, diary[n2].title, diary[n2].content);
				strcpy(diary2->text, b2);
			}

			if (diary_N > 2)
			{
				sprintf(b3, "%s\t%s\t\t\t%.50s....", diary[n3].date_copy, diary[n3].title, diary[n3].content);
				strcpy(diary3->text, b3);
			}
			if (diary_N > 3)
			{
				sprintf(b4, "%s\t%s\t\t\t%.50s....", diary[n4].date_copy, diary[n4].title, diary[n4].content);
				strcpy(diary4->text, b4);
			}
		}

		//绘制界面
		drawButton(page_down);
		drawButton(page_up);
		drawButton(exit);
		drawButton_left(diary1);
		drawButton_left(diary2);
		drawButton_left(diary3);
		drawButton_left(diary4);
		peekmessage(&m, EM_MOUSE);
		if (isClickButton(diary1, m))
		{
			m.message = 0;
			char text1[2200] = "";
			sprintf(text1, "标题：%s\n天气：%s\n心情：%s\n内容：%s",
				diary[n1].title, diary[n1].weather, diary[n1].mood, diary[n1].content);
			MessageBox(GetHWnd(), text1, diary[n1].date_copy, MB_OK);
		}
		if (isClickButton(diary2, m))
		{
			m.message = 0;
			char text2[2200] = "";
			sprintf(text2, "标题：%s\n天气：%s\n心情：%s\n内容：%s",
				diary[n2].title, diary[n2].weather, diary[n2].mood, diary[n2].content);
			MessageBox(GetHWnd(), text2, diary[n2].date_copy, MB_OK);
		}
		if (isClickButton(diary3, m))
		{
			m.message = 0;
			char text3[2200] = "";
			sprintf(text3, "标题：%s\n天气：%s\n心情：%s\n内容：%s",
				diary[n3].title, diary[n3].weather, diary[n3].mood, diary[n3].content);
			MessageBox(GetHWnd(), text3, diary[n3].date_copy, MB_OK);
		}
		if (isClickButton(diary4, m))
		{
			m.message = 0;
			char text4[2200] = "";
			sprintf(text4, "标题：%s\n天气：%s\n心情：%s\n内容：%s",
				diary[n4].title, diary[n4].weather, diary[n4].mood, diary[n4].content);
			MessageBox(GetHWnd(), text4, diary[n4].date_copy, MB_OK);
		}
		if (isClickButton(page_down, m))
		{
			m.message = 0;
			if (diary_N - n4 > 0)
			{
				n1++;
				n2++;
				n3++;
				n4++;
				goto renew;
			}
			else
			{
				MessageBox(GetHWnd(), "已经没有更多日记了,快去记录美好生活吧！", "提醒", MB_OK);
			}
		}
		if (isClickButton(page_up, m))
		{
			m.message = 0;
			if (n1>1)
			{
				n1--;
				n2--;
				n3--;
				n4--;
				goto renew;
			}
			else
			{
				MessageBox(GetHWnd(), "已经是第一页了", "提醒", MB_OK);
			}
		}
		if (isClickButton(exit, m))
		{
			Sleep(150);
			m.message = 0;
			Menu();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// 名称：创作_Write()
// 作者：nordic-blessing
// 时间：2023/12/12/12:02pm
//===============================================================================================
COLORREF diary_title = RGB(67, 142, 185);
COLORREF diary_text = RGB(117, 117, 117);
COLORREF diary_gray = RGB(230, 231, 232);
COLORREF diary_gray1 = RGB(104, 104, 104);
void Write()
{
	setbkcolor(menubk);
	clearrectangle(140, 60, 800, 600);
	Button* title = creatButton(160, 75, 380, 40,
		"标  题", diary_title, diary_gray, "宋体", 18,
		diary_gray, diary_gray1);
	Button* date_month = creatButton(160, 120, 70, 30,
		"月", diary_title, diary_gray, "宋体", 15,
		diary_gray, diary_gray1);
	Button* date_day = creatButton(240, 120, 70, 30, 
		"日", diary_title, diary_gray, "宋体", 15,
		diary_gray, diary_gray1);
	Button* date_weekday = creatButton(320, 120, 70, 30, 
		"星 期", diary_title, diary_gray, "宋体", 15,
		diary_gray, diary_gray1);
	Button* weather = creatButton(570, 120, 100, 30, 
		"天 气", diary_title, diary_gray, "宋体", 15,
		diary_gray, diary_gray1);
	Button* mood = creatButton(680, 120, 100, 30, 
		"心 情", diary_title, diary_gray, "宋体", 15,
		diary_gray, diary_gray1);
	Button* content = creatButton(160, 160, 780 - 160, 550 - 150 - 10,
		"肆 意 书 写 青 春 | Write Anything You Want", diary_title, diary_gray, "宋体", 15,
		diary_gray, diary_gray1);
	Button* submit = creatButton(160 + 270, 560, 70, 30,
		"保 存", diary_title, diary_gray, "宋体", 14,
		diary_gray, diary_gray1);
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "宋体", 13,
		RGB(255, 255, 255), RGB(254, 225, 136));
	BeginBatchDraw();
	while (1)
	{
		m.message = 0;
		drawButton(title);
		drawButton(date_month);
		drawButton(date_day);
		drawButton(date_weekday);
		drawButton(weather);
		drawButton(mood);
		drawButton(content);
		drawButton(submit);
		drawButton(exit);
		peekmessage(&m, EM_MOUSE);
		if (isClickButton(title, m))
		{
			InputBox(new_diary.title, 21, "标题");
			if (strlen(new_diary.title) > 0)
				strcpy(title->text, new_diary.title);
		}
		if (isClickButton(date_month, m))
		{
			InputBox(new_diary.date.month, 3, "月");
			if (strlen(new_diary.date.month) > 0)
				strcpy(date_month->text, new_diary.date.month);
		}
		if (isClickButton(date_day, m))
		{
			InputBox(new_diary.date.day, 3, "日");
			if (strlen(new_diary.date.day) > 0)
				strcpy(date_day->text, new_diary.date.day);

		}
		if (isClickButton(date_weekday, m))
		{
			InputBox(new_diary.date.weekday, 10, "星期");
			if (strlen(new_diary.date.weekday) > 0)
				strcpy(date_weekday->text, new_diary.date.weekday);
		}
		if (isClickButton(weather, m))
		{
			InputBox(new_diary.weather, 10, "天气");
			if (strlen(new_diary.weather) > 0)
				strcpy(weather->text, new_diary.weather);
		}
		if (isClickButton(mood, m))
		{
			InputBox(new_diary.mood, 10, "心情");
			if (strlen(new_diary.mood) > 0)
				strcpy(mood->text, new_diary.mood);
		}
		if (isClickButton(content, m))
		{
			InputBox(new_diary.content, 2000, "开始记录您的生活点滴", "content", content->text, 780 - 160, 550 - 150 - 10);
			if (strlen(new_diary.content) > 0)
				strcpy(content->text, new_diary.content);
			else;
		}
		if (isClickButton(submit, m))
		{
			m.message = 0;
			//将编辑的日记写入文件
			sprintf(filename_diary, "%s_diary.txt", read_user.name);
			ofstream fout_diary(filename_diary,ios::app);
			fout_diary << "============================= " << endl;
			fout_diary << "日期： " << new_diary.date.month << "-" << new_diary.date.day<< "-" << new_diary.date.weekday << endl;
			fout_diary << "标题： " << new_diary.title << endl;
			fout_diary << "心情： " << new_diary.mood << endl;
			fout_diary << "天气： " << new_diary.weather << endl;
			fout_diary << "内容： " << new_diary.content << "`" << endl;
			fout_diary.close();
			read_set.diary_writeN++;
			strcpy(read_set.music_path, bgm_path);
			sprintf(filename_set, "%s_set.dat", read_user.name);
			ofstream fout(filename_set, ios::binary);
			if (!fout.is_open())
			{
				MessageBox(GetHWnd(), "文件打开失败！", "错误", MB_ICONERROR | MB_OK);
			}
			else
			{
				fout.write((char*)&read_set, sizeof(Userset));
				fout.close();
			}
			Menu();
		}
		if (isClickButton(exit, m))
		{
			Sleep(150);
			m.message = 0;
			Menu();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// 名称：主函数_main()
// 作者：nordic-blessing
// 时间：2023/11/30/11:30am
//===============================================================================================
int main()
{
	printf("Welcome to Click | Enjoy your days\n\n");
	//播放音乐
	musicplay(bgm_path, true, 200);
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	Login();
	return 0;
}