//===============================================================================================
// ���ƣ�Click
// ���ߣ�nordic-blessing & whynotwhat & komorebi & �ܰ�
// ��Ҫ���ܣ��ռ� & ���� & ������
// ����ʱ�䣺2023/11/30/11:30 am
// �깤ʱ�䣺
//===============================================================================================
#include "common.h"
#include "button.h"
#include "userInfo.h"
#include "musicplay.h"
#include "transparentdraw.h"

void Login();		//��¼
void Menu();		//��ҳ
void ToRegister();	//ע��
void Write();		//����
void Set();			//����
void Look();		//���
void Me();			//�ҵ���Ϣҳ��

ExMessage m;																	//���������Ϣ
COLORREF themecolor = RGB(1, 122, 213);											//������ɫ��ʼ��
COLORREF themecolor_1 = RGB(93, 200, 255);										//����ǳɫ��ʼ��
char bgm_path[100] = "music/�������.mp3";										//���ֵ�ַ��ʼ��
User read_user;																	//�û���Ϣ���ѵ�¼��
Userset read_set = { "music/�������.mp3",RGB(1, 122, 213) ,RGB(93, 200, 255) };	//�û����ó�ʼ��
char filename_set[20];															//���ڴ����û����õ��ļ���ַ
char filename_diary[20];														//���ڴ����û��ռǵ��ļ���ַ
char bgm[100];																	//���ڴ������ֵ�ַ
Diary new_diary;																//���ڴ������ռǵġ�������
int diary_N = 0;

//===============================================================================================
// ���ƣ���������
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/5/3:10pm
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
// ���ƣ�������������
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/5/3:10pm
//===============================================================================================
void puttext(int x, int y, const char* text, int lfHight, LPCTSTR font, COLORREF color, int nWeight = 0)
{
	LOGFONT f;
	gettextstyle(&f);
	//�������ָ߶�
	f.lfHeight = lfHight;
	//��������
	_tcscpy(f.lfFaceName, font);
	//�������ִ�ϸ��Ĭ��ֵΪ0
	f.lfWeight = nWeight;
	//�����
	f.lfQuality = ANTIALIASED_QUALITY;
	//����������ɫ
	settextcolor(color);
	//�������ֱ���Ϊ͸��
	setbkmode(TRANSPARENT);
	settextstyle(&f);
	//�������
	outtextxy(x, y, text);
}
//===============================================================================================
// ���ƣ�ע��_ToRegister()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/12/8:47pm
//===============================================================================================
const COLORREF register_gray = RGB(233, 234, 235);
const COLORREF register_gray_1 = RGB(246, 246, 246);
const COLORREF register_text = RGB(117, 117, 117);
void ToRegister()
{
	User newUser[1] = {0};
	setbkcolor(WHITE);
	clearrectangle(0, 0, 800, 600);
	//�����������
	setfillcolor(themecolor);
	fillrectangle(0, 0, 800, 60);
	//��Click | Enjoy everyday��
	char title[] = "Click | Enjoy everyday";
	puttext(30, 15, title, 35, "Ink Draft", WHITE);
	//��ע�ᡱ
	char welcom[] = "�� ӭ ע �� Click  ";
	puttext(400 - (textwidth(welcom) / 2), 70, welcom, 30, "ǧͼ�ʷ���д��", BLACK, 100);
	setlinecolor(themecolor);
	setlinestyle(PS_SOLID, 2);
	line(400 - 4 - textwidth(welcom) / 2, 98, 400 + 4 + textwidth(welcom) / 2, 98);
	//�����ա����ꡱ���¡����ա�
	char birthday[] = "�� ��";
	puttext(400 - 105 - textwidth(birthday) / 2, 442 - textheight(birthday) / 2, birthday, 20, "����", BLACK);
	//��ť
	//������ť
	Button* submit = creatButton(400 - 35, 600 - 60, 70, 44, 
		"ע ��", WHITE, WHITE, "����", 15,
		themecolor, themecolor_1);
	Button* name_create = creatButton(400 - 140, 120, 280, 44, 
		"�� ��", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* account_create = creatButton(400 - 140, 180, 280, 44, 
		"�� ��", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* password_create = creatButton(400 - 140, 240, 280, 44, 
		"�� ��", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* password_create_check = creatButton(400 - 140, 300, 280, 44, 
		"ȷ �� �� ��", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* email_create = creatButton(400 - 140, 360, 280, 44, 
		"�� ��", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* birthday_year_create = creatButton(400 - 70, 420, 60, 44, 
		"2005", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* birthday_month_create = creatButton(400, 420, 60, 44, 
		"1", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* birthday_day_create = creatButton(400 + 70, 420, 60, 44, 
		"14", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* telephone_create = creatButton(400 - 140, 480, 280, 44, 
		"�ֻ�", register_text, register_text, "����", 15,
		register_gray, register_gray_1);
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "����", 13,
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
			InputBox(newUser->name, 10, "�����õ�¼�ǳ�\n��������10���ַ�����ʹ����ĸ�����֡��»��ߣ�");
			//����ť�ϵ����ָ���Ϊ����
			if(strlen(newUser->name) > 0)
			{
				correct(400 + 140 + 8, 120 + 22);
				strcpy(name_create->text, newUser->name);
			}
			else
			{
				error(400 + 140 + 8, 120 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 142-6, "�������ǳ�", 13, "����", RED);
				strcpy(name_create->text, "�� ��");
			}
		}
		if (isClickButton(account_create, m))
		{
			setcolor(WHITE);
			clearrectangle(400 + 140 + 8, 180, 400 + 140 + 8 + 6 + 4 + 200, 180 + 44);
			//�����˺�
			InputBox(newUser->account, 20, "�����õ�¼�˺�\n��������20���ַ�����ʹ����ĸ�����֡��»��ߣ�");
			//����ť�ϵ����ָ���Ϊ����
			if (strlen(newUser->account) > 0)
			{
				correct(400 + 140 + 8, 180 + 22);
				strcpy(account_create->text, newUser->account);
			}
			else
			{
				error(400 + 140 + 8, 180 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 202 - 6, "�������˺�", 13, "����", RED);
				strcpy(name_create->text, "�� ¼");
			}
		}
		char setpassword[21];
		if (isClickButton(password_create, m))
		{
			setcolor(WHITE);
			clearrectangle(400 + 140 + 8, 240, 400 + 140 + 8 + 6 + 4 + 200, 240 + 44);
			InputBox(setpassword, 21, "�����õ�¼����\n��������20���ַ�����ʹ����ĸ�����֡��»��ߣ�ע����ĸ���ִ�Сд��");
			//����ť�ϵ����ָ���Ϊ����
			if (strlen(setpassword) > 0)
			{
				strcpy(password_create->text, setpassword);
				//��ȡ����ĳ���
				int i = strlen(setpassword);
				//�����������ת��Ϊ"*"���
				for (int j = 1; j <= i; j++)
				{
					password_create->text[j - 1] = '*';
				}
				correct(400 + 140 + 8, 240 + 22);
			}
			else
			{
				error(400 + 140 + 8, 240 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 262 - 6, "����������", 13, "����", RED);
				strcpy(name_create->text, "�� ��");
			}
		}
		char checkpassword[21];
		if (isClickButton(password_create_check, m))
		{
			setbkcolor(WHITE);
			clearrectangle(400 + 140 + 8, 300, 400 + 140 + 8 + 6 + 4 + 200, 300 + 44);
			InputBox(checkpassword, 21, "��ȷ�ϵ�¼����");
			if (strlen(checkpassword) > 0)
			{
				//����ť�ϵ����ָ���Ϊ����
				strcpy(password_create_check->text, checkpassword);
				//�����������ת��Ϊ��ͬ���ȵ�"*"���
				for (int j = 1; j <= strlen(checkpassword); j++)
				{
					password_create_check->text[j - 1] = '*';
				}
			}
			else
			{
				error(400 + 140 + 8, 300 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 322 - 6, "��ȷ������", 13, "����", RED);
				strcpy(password_create_check->text, "ȷ �� �� ��");
				continue;
			}
			if ((strcmp(setpassword, checkpassword) != 0))
			{
				error(400 + 140 + 8, 300 + 22);
				puttext(400 + 140 + 8 + 6 + 8, 322 - 6, "���벻һ�£�������ȷ��", 13, "����", RED);
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
			InputBox(newUser->email, 20, "�����������ַ");
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
			InputBox(newUser->year, 5, "��������");
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
			InputBox(newUser->month, 3, "��������");
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
			InputBox(newUser->day, 3, "��������");
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
				puttext(400 + 140 + 8 + 6 + 8, 442 - 6, "����������", 13, "����", RED);
			}
		}
		if (isClickButton(telephone_create, m))
		{
			setcolor(WHITE);
			clearcircle(400 + 140 + 8, 480 + 22, 6);
			InputBox(newUser->telephone, 12, "�������ֻ�����");
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
				//д���û���Ϣ
				ofstream fin("userdata.dat", ios::binary | ios::app);
				if (!fin.is_open())
				{
					MessageBox(GetHWnd(), "�ļ���ʧ�ܣ�", "����", MB_ICONERROR | MB_OK);
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
				MessageBox(GetHWnd(), "�����õ�¼�˺ź����룡", "����", MB_ICONERROR | MB_OK);
				continue;
			}
			if (strlen(newUser->account) == 0)
			{
				m.message = 0;
				MessageBox(GetHWnd(), "�����õ�¼�˺ţ�", "����", MB_ICONERROR | MB_OK);
				continue;
			}
			if (strlen(newUser->password) == 0)
			{
				m.message = 0;
				MessageBox(GetHWnd(), "�����õ�¼���룡", "����", MB_ICONERROR | MB_OK);
				continue;
			}
		}
		if (isClickButton(exit, m))
		{
			Sleep(150);
			printf("�˳�ע��\n\n");
			m.message = 0;
			Login();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// ���ƣ���¼_Login()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/11/30/8:47pm
//===============================================================================================
const COLORREF login_gray = RGB(233, 234, 235);
const COLORREF login_gray_1 = RGB(246, 246, 246);
const COLORREF login_text = RGB(117, 117, 117);
void Login()
{
	char account_cin[21]="";
	char password_cin[21]="";
	//������ť
	//�˺�
	Button* account = creatButton(400 - 140, 300 + 60 * -1, 280, 44, 
		"�˺�", login_text, WHITE, "����", 15,
		login_gray, login_gray_1);
	//����
	Button* password = creatButton(400 - 140, 300 + 10, 280, 44, 
		"����", login_text, WHITE, "����", 15,
		login_gray, login_gray_1);
	//��¼
	Button* login = creatButton(400 + 70 * -1, 300 + 80, 140, 44,
		"��¼", WHITE, WHITE, "����", 20,
		themecolor_1, themecolor);
	//ע��
	Button* toRegister = creatButton(400 - 70, 300 + 136, 140, 44, 
		"ע��", WHITE, WHITE, "����", 20,
		themecolor_1, themecolor);
	//��ʼ����
	g_pBuf11 = GetImageBuffer();
	// ��������ȡ��
	DWORD* g_pBuf = GetImageBuffer();
	// ����͸���Ȱٷֱ�Ϊ 50 Ҳ���� 128��
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
		//���Ƶ�¼����
		//�ϱ���
		//��ӭ
		char welcom1[] = "��¼��������";
		char welcom2[] = "| enjoy your days";
		puttext(400 + (textwidth(welcom1) + textwidth(welcom2)) / 2 * -1, 300 + 264 * -1,
			welcom1, 25, "ǧͼ�ʷ���д��", WHITE);
		puttext(400 + (textwidth(welcom1) + textwidth(welcom2)) / 2 * -1 + textwidth(welcom1), 300 - 264,
			welcom2, 36, "Ink Draft", WHITE, 200);
		//��
		setlinecolor(themecolor);
		setlinestyle(PS_SOLID, 3);
		line(400 - (textwidth(welcom1) + textwidth(welcom2)) / 2, 300 + 232 * -1, 
			400 + (textwidth(welcom1) + textwidth(welcom2)) / 2, 300 + 232 * -1);
		//ͷ��
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
			InputBox(account_cin, 20, "�˺�");
			if (!account_cin[0] == '\0')
			{
				strcpy(account->text, account_cin);
			}
			printf("�����˺� %s\n", account_cin);
		}
		if (isClickButton(password, m))
		{
			InputBox(password_cin, 20, "����");
			if(!password_cin[0]=='\0')
			{
				strcpy(password->text, password_cin);
				printf("�������� %s\n", password_cin);
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
				MessageBox(GetHWnd(), "�ļ���ʧ�ܣ�", "����", MB_ICONERROR | MB_OK);
			}
			int n = 0;
			char i[21] = "";
			while (fin_login.read((char*)&read_user, sizeof(User)))
			{
				if (strcmp(read_user.account, account_cin) == 0)
				{
					if (strcmp(read_user.password, password_cin) == 0)
					{
						printf("��¼�ɹ���\n");
						//�����¼�������
						memset(account_cin, 0, sizeof(account_cin));
						memset(password_cin, 0, sizeof(password_cin));
						//������û�������
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
						MessageBox(GetHWnd(), "��¼ʧ��!\n�������", "����", MB_OK);
						printf("��¼ʧ�ܣ�\n�������\n");
						break;
					}
				}
				if (strcmp(i,read_user.account)==0)
				{
					printf("δ�ҵ��û���\n");
					fin_login.close();
					MessageBox(GetHWnd(), "�˺Ų����ڣ�", "����", MB_ICONERROR | MB_OK);
					m.message = 0;
					break;
				}
				else
				{
					strcpy(i, read_user.account);
					fin_login.seekg(sizeof(User), ios::beg);  // ���ļ�ָ�붨λ����һ��User�ṹ��Ŀ�ͷλ��
				}
			}
		}
		if (isClickButton(toRegister, m))
		{
			printf("ע��");
			m.message = 0;
			ToRegister();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
}
//===============================================================================================
// ���ƣ���ҳ_Menu()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/2/11:34am
//===============================================================================================
const COLORREF menubk = RGB(245, 245, 245);
const COLORREF menu_gray = RGB(243, 243, 243);
const COLORREF menu_gray1 = RGB(236, 236, 235);
void Menu()
{
	setbkcolor(menubk);
	cleardevice();
	//�����������
	setfillcolor(themecolor);
	solidrectangle(0, 0, 800, 60);
	//�˵�������
	setfillcolor(menu_gray1);
	solidrectangle(0, 60, 140, 600);
	//��Click | Enjoy everyday��
	puttext(30, 15, "Click | Enjoy everyday", 30, "Ink Draft", WHITE);
	//��ť
		//������ť
	Button* look = creatButton(0, 60, 140, 80, 
		"���", themecolor, WHITE, "΢���ź�", 22,
		menu_gray, themecolor);
	Button* set = creatButton(0, 140, 140, 80, 
		"����", themecolor, WHITE, "΢���ź�", 22, 
		menu_gray, themecolor);
	Button* me = creatButton(0, 220, 140, 80, 
		"��", themecolor, WHITE, "΢���ź�", 22,
		menu_gray, themecolor);
	Button* write = creatButton(0, 510, 140, 80, 
		"+", BLACK, RGB(85, 85, 85), "΢���ź�", 25, 
		RGB(255, 255, 255), RGB(254, 225, 136));
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "����", 13, 
		RGB(255, 255, 255), RGB(254, 225, 136));
	//��ͼ
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
				MessageBox(GetHWnd(), "�ļ���ʧ�ܣ�", "����", MB_ICONERROR | MB_OK);
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
// ���ƣ�����_Set()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/6/9:43pm
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
	puttext(165, 75, "����", 20, "ǧͼ�ʷ���д��", themecolor);
	puttext(165, 180, "��������", 20, "ǧͼ�ʷ���д��", themecolor);
	Button* blue_theme = creatButton(160 + 65, 105, 70, 40,
		"������", BLACK, WHITE, "����", 14,
		theme_blue, theme_lightblue);
	Button* pink_theme = creatButton(160 + 85 + 65, 105, 70, 40, 
		"���ҷ�", BLACK, WHITE, "����", 14,
		theme_pink, theme_lightpink);
	Button* green_theme = creatButton(160 + 85 * 2 + 65, 105, 70, 40, 
		"ǳ����", BLACK, WHITE, "����", 14,
		theme_green, theme_lightgreen);
	Button* black_theme = creatButton(160 + 85 * 3 + 65, 105, 70, 40, 
		"���º�", WHITE, BLACK, "����", 14,
		theme_black, theme_lightblack);
	Button* purple_theme = creatButton(160 + 85 * 4 + 65, 105, 70, 40, 
		"�ǳ���", BLACK, WHITE, "����", 14,
		theme_purple, theme_lightpurple);
	Button* yellow_theme = creatButton(160 + 85 * 5 + 65, 105, 70, 40, 
		"ʢ�Ļ�", BLACK, WHITE, "����", 14,
		theme_yellow, theme_lightyellow);
	Button* music_path = creatButton(160 + 65, 210, 500, 30, 
		bgm_path, BLACK, WHITE, "����", 14,
		RGB(228, 228, 207), RGB(226, 226, 226));
	Button* save = creatButton(160 + 270, 560, 70, 30, 
		"�� ��", WHITE, WHITE, "����", 14,
		themecolor, set_box1);
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "����", 13,
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
			InputBox(bgm, 100, "������ .mp3 �ļ���·����\n���뽫�ļ���ǰ����� music �ļ����У�", "music_path");
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
			//���ı�������
			musicplay(bgm_path, true, 200, true);
			printf("ԭ���ı������� %s\n", bgm_path);
			strcpy(bgm_path, music_path->text);
			printf("���ڵı������� %s\n\n", bgm_path);
			musicplay(bgm_path, true, 200);
			//�����ô����ļ�
			read_set.theme_color = themecolor;
			read_set.theme_colorlight = themecolor_1;
			strcpy(read_set.music_path, bgm_path);
			sprintf(filename_set, "%s_set.dat", read_user.name);
			ofstream fout(filename_set, ios::binary);
			if (!fout.is_open())
			{
				MessageBox(GetHWnd(), "�ļ���ʧ�ܣ�", "����", MB_ICONERROR | MB_OK);
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
// ���ƣ���_Me()
// ���ߣ�whynotwhat
// ʱ�䣺2024/1/3/8��23pm
//===============================================================================================
void Me()
{
	//��ʼ���ƽ���
	settextcolor(themecolor);
	setbkmode(TRANSPARENT);
	settextstyle(22, 0, "����");
	outtextxy(940 / 2 - textwidth("���˿ռ�") / 2, 70, "���˿ռ�");
	outtextxy(200, 160, "�ǳƣ�");
	outtextxy(300, 160, read_user.name);
	outtextxy(200, 210, "�ʼ�:");
	outtextxy(300, 210, read_user.email);
	outtextxy(200, 260, "�绰����:");
	outtextxy(300, 260, read_user.telephone);
	outtextxy(200, 310, "����:");
	char birthday[40] = "";
	sprintf(birthday, "%s-%s-%s", read_user.year, read_user.month, read_user.day);
	outtextxy(300, 310, birthday);
}
//===============================================================================================
// ���ƣ����_Look()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/6/9:43pm
//===============================================================================================
COLORREF diary_color = RGB(216, 216, 215);
COLORREF diary_color1 = RGB(230, 230, 230);
char color_choice[5] = { theme_lightblue,theme_lightpink,theme_lightgreen,
	theme_lightpurple,theme_lightyellow };
/*int rand_color()
{
	// ʹ�õ�ǰʱ����Ϊ���������
	srand(time(NULL));
	// ����һ����0��6֮��������
	int randomIndex = rand() % 7;
	//������ɫѡ����
	return randomIndex;
}*/
void Look()
{
	char b1[200] = "����û��д���ռ�";
	char b2[200] = "����ȥ������";
	char b3[200] = "welcome to Click";
	char b4[200] = "��¼������";
	
	//Diary* diary = new Diary[diary_N];
	Diary* diary = (Diary*)malloc(read_set.diary_writeN * sizeof(Diary));
	//��ȡ�ռ�
	diary_N = 0;
	sprintf(filename_diary, "%s_diary.txt", read_user.name);
	ifstream fin(filename_diary);
	if (!fin.is_open())
	{
		MessageBox(GetHWnd(), "����δ��д�����������Σ�\n��ȥд����ĵ�һƪClick��", "����", MB_ICONERROR | MB_OK);
		Menu();
	}
	char line[30];													//���ڶ�ȡ�ļ��е���������
	while (!fin.eof())												//ѭ����ȡ��ֱ���ļ�����
	{
		fin >> line;												//����ָ���
		if (strcmp(line, "=============================") != 0)
			break;												//δ�����ָ�����ת����һ�ζ�ȡ
		diary_N++;													//��ʼ��ȡ��diary_Nƪ�ռ�
		fin >> line;												//������������
		fin.getline(diary[diary_N].date_copy, 17);
		fin >> line;												//�����������
		fin.getline(diary[diary_N].title, 21);
		fin >> line;												//������������
		fin.getline(diary[diary_N].mood, 11);
		fin >> line;												//������������
		fin.getline(diary[diary_N].weather, 11);
		fin >> line;												//������������
		fin.getline(diary[diary_N].content, 2000, '`');
	}
	fin.close();

	//color_choice[rand_color()];
	setbkcolor(menubk);
	clearrectangle(140, 60, 800, 600);
	char look_title[30];
	sprintf(look_title, "���Ѽ�¼�� %d ƪ���", diary_N);
	puttext(180, 120, look_title, 23, "ǧͼ�ʷ���д��", BLACK);
	Button* page_down = creatButton(770, 322, 30, 28,
		">", BLACK, WHITE, "����", 14,
		themecolor, themecolor_1);
	Button* page_up = creatButton(770, 290, 30, 28,
		"<", BLACK, WHITE, "����", 14,
		themecolor, themecolor_1);
	Button* exit = creatButton(770, 0, 30, 30,
		"!", BLACK, RGB(85, 85, 85), "����", 13,
		RGB(255, 255, 255), RGB(254, 225, 136));
	Button* diary1 = creatButton(170, 180, 570, 90,
		b1, BLACK, WHITE, "����", 12,
		diary_color1, diary_color);
	Button* diary2 = creatButton(170, 280, 570, 90,
		b2, BLACK, WHITE, "����", 12,
		diary_color1, diary_color);
	Button* diary3 = creatButton(170, 380, 570, 90,
		b3, BLACK, WHITE, "����", 12,
		diary_color1, diary_color);
	Button* diary4 = creatButton(170, 480, 570, 90,
		b4, BLACK, WHITE, "����", 12,
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

		//���ƽ���
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
			sprintf(text1, "���⣺%s\n������%s\n���飺%s\n���ݣ�%s",
				diary[n1].title, diary[n1].weather, diary[n1].mood, diary[n1].content);
			MessageBox(GetHWnd(), text1, diary[n1].date_copy, MB_OK);
		}
		if (isClickButton(diary2, m))
		{
			m.message = 0;
			char text2[2200] = "";
			sprintf(text2, "���⣺%s\n������%s\n���飺%s\n���ݣ�%s",
				diary[n2].title, diary[n2].weather, diary[n2].mood, diary[n2].content);
			MessageBox(GetHWnd(), text2, diary[n2].date_copy, MB_OK);
		}
		if (isClickButton(diary3, m))
		{
			m.message = 0;
			char text3[2200] = "";
			sprintf(text3, "���⣺%s\n������%s\n���飺%s\n���ݣ�%s",
				diary[n3].title, diary[n3].weather, diary[n3].mood, diary[n3].content);
			MessageBox(GetHWnd(), text3, diary[n3].date_copy, MB_OK);
		}
		if (isClickButton(diary4, m))
		{
			m.message = 0;
			char text4[2200] = "";
			sprintf(text4, "���⣺%s\n������%s\n���飺%s\n���ݣ�%s",
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
				MessageBox(GetHWnd(), "�Ѿ�û�и����ռ���,��ȥ��¼��������ɣ�", "����", MB_OK);
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
				MessageBox(GetHWnd(), "�Ѿ��ǵ�һҳ��", "����", MB_OK);
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
// ���ƣ�����_Write()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/12/12/12:02pm
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
		"��  ��", diary_title, diary_gray, "����", 18,
		diary_gray, diary_gray1);
	Button* date_month = creatButton(160, 120, 70, 30,
		"��", diary_title, diary_gray, "����", 15,
		diary_gray, diary_gray1);
	Button* date_day = creatButton(240, 120, 70, 30, 
		"��", diary_title, diary_gray, "����", 15,
		diary_gray, diary_gray1);
	Button* date_weekday = creatButton(320, 120, 70, 30, 
		"�� ��", diary_title, diary_gray, "����", 15,
		diary_gray, diary_gray1);
	Button* weather = creatButton(570, 120, 100, 30, 
		"�� ��", diary_title, diary_gray, "����", 15,
		diary_gray, diary_gray1);
	Button* mood = creatButton(680, 120, 100, 30, 
		"�� ��", diary_title, diary_gray, "����", 15,
		diary_gray, diary_gray1);
	Button* content = creatButton(160, 160, 780 - 160, 550 - 150 - 10,
		"�� �� �� д �� �� | Write Anything You Want", diary_title, diary_gray, "����", 15,
		diary_gray, diary_gray1);
	Button* submit = creatButton(160 + 270, 560, 70, 30,
		"�� ��", diary_title, diary_gray, "����", 14,
		diary_gray, diary_gray1);
	Button* exit = creatButton(770, 0, 30, 30, 
		"!", BLACK, RGB(85, 85, 85), "����", 13,
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
			InputBox(new_diary.title, 21, "����");
			if (strlen(new_diary.title) > 0)
				strcpy(title->text, new_diary.title);
		}
		if (isClickButton(date_month, m))
		{
			InputBox(new_diary.date.month, 3, "��");
			if (strlen(new_diary.date.month) > 0)
				strcpy(date_month->text, new_diary.date.month);
		}
		if (isClickButton(date_day, m))
		{
			InputBox(new_diary.date.day, 3, "��");
			if (strlen(new_diary.date.day) > 0)
				strcpy(date_day->text, new_diary.date.day);

		}
		if (isClickButton(date_weekday, m))
		{
			InputBox(new_diary.date.weekday, 10, "����");
			if (strlen(new_diary.date.weekday) > 0)
				strcpy(date_weekday->text, new_diary.date.weekday);
		}
		if (isClickButton(weather, m))
		{
			InputBox(new_diary.weather, 10, "����");
			if (strlen(new_diary.weather) > 0)
				strcpy(weather->text, new_diary.weather);
		}
		if (isClickButton(mood, m))
		{
			InputBox(new_diary.mood, 10, "����");
			if (strlen(new_diary.mood) > 0)
				strcpy(mood->text, new_diary.mood);
		}
		if (isClickButton(content, m))
		{
			InputBox(new_diary.content, 2000, "��ʼ��¼����������", "content", content->text, 780 - 160, 550 - 150 - 10);
			if (strlen(new_diary.content) > 0)
				strcpy(content->text, new_diary.content);
			else;
		}
		if (isClickButton(submit, m))
		{
			m.message = 0;
			//���༭���ռ�д���ļ�
			sprintf(filename_diary, "%s_diary.txt", read_user.name);
			ofstream fout_diary(filename_diary,ios::app);
			fout_diary << "============================= " << endl;
			fout_diary << "���ڣ� " << new_diary.date.month << "-" << new_diary.date.day<< "-" << new_diary.date.weekday << endl;
			fout_diary << "���⣺ " << new_diary.title << endl;
			fout_diary << "���飺 " << new_diary.mood << endl;
			fout_diary << "������ " << new_diary.weather << endl;
			fout_diary << "���ݣ� " << new_diary.content << "`" << endl;
			fout_diary.close();
			read_set.diary_writeN++;
			strcpy(read_set.music_path, bgm_path);
			sprintf(filename_set, "%s_set.dat", read_user.name);
			ofstream fout(filename_set, ios::binary);
			if (!fout.is_open())
			{
				MessageBox(GetHWnd(), "�ļ���ʧ�ܣ�", "����", MB_ICONERROR | MB_OK);
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
// ���ƣ�������_main()
// ���ߣ�nordic-blessing
// ʱ�䣺2023/11/30/11:30am
//===============================================================================================
int main()
{
	printf("Welcome to Click | Enjoy your days\n\n");
	//��������
	musicplay(bgm_path, true, 200);
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();
	Login();
	return 0;
}