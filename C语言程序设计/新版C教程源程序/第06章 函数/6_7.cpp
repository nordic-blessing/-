#include <iostream>                 // 包含输入输出接口文件
using namespace std;                // 引用标准命名空间
char *strlmt(char str[], char ch, int n);
void createMenu(char menuTitle[20], char menuItem[][20], int n);
void showMenu(char menuTitle[20], char menuItem[][20], void (*menuExecFun[])(), int n);
void showAdminCourseManagerMenu();
void returnFunc();
void courseAppend();                // 新增课程函数
void courseQuery();                 // 课程查询函数
void courseDelete();                // 课程删除函数
void courseUpdate();                // 课程修改函数
void courseBrowse();                // 课程浏览函数
int main()
{
    showAdminCourseManagerMenu();   // 显示课程信息菜单并执行相应选项
	return 0;
}

char *strlmt(char str[], char ch, int n)
// 将字符串str扩展至长度为|n|，如果n小于0则在str的左边添加字符ch，否则，在str的右边添加字符ch
// 如果str长于n，则截断。当n小于0时，截断左侧字符，否则截断右侧字符
{
    int m = strlen(str);                    // 字符串原长度
    int len = n > 0?n:-n;                   // 字符串新长度
    int i = 0;
    char* strReturn  = new char[100]; 
    if(len == 0)                            // 字符串新长度为零，则返回空字符串
    {
        return "";
    }

    if(ch == '\0')
    {
        return str;
    }


    if(m < len)
    {   
        if(n < 0)
        {
            // 生成后继字符串
            for(i = 0; i < len-m; i++)
            {
                strReturn[i] = ch;
            }
            strReturn[i] = '\0';
            return strcat(strReturn, str);
        }
        else
        {
            strcpy(strReturn, str);
            // 生成后继字符串
            for(i = m; i < len; i++)
            {
                strReturn[i] = ch;
            }
            strReturn[i] = '\0';
        }
    }
    else
    {
        if(n < 0)
        {   // 截断左侧字符
            for(i = m; i > m - len; i--)
            {
                strReturn[i - m + len] = str[i];
            }
        }
        else
        {   // 截断右侧字符
            for(i = 0; i < len; i++)
            {
                strReturn[i] = str[i];
            }
            strReturn[i] = '\0';
        }
    }
    return strReturn;
}

void createMenu(char menuTitle[20], char menuItem[][20], int n)     
// 生成菜单
//      menuTitle   菜单名称
//      menuItem    各菜单项
//      n           菜单项数（0-n)
{
    int len = strlen(menuTitle);
    int i = 0;
    char itemNo = ' ';

    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\t\t|"<<strlmt("-", '-', 21 - len/2)<<menuTitle<<strlmt("-", '-', 21 - len/2)<<"|\n";
    for(i = 0; i <= n; i++)
    {
        if(i < 10)
        {
            itemNo = '0' + i;
        }
        else
        {
            itemNo = 'a' + (i - 10);
        }
        cout<<"\t\t|         "<<itemNo<<". "<<strlmt(menuItem[i], ' ', 30)<<"|\n";
    }
    cout<<"\t\t|------------------------------------------|\n\n";
    cout<<"\t\t\t请输入模块编号(0-"<<itemNo<<"):";
}

///**********************************************************
///  函 数 名：showMenu                                     *
///  输入参数：                                             *
///      menuTile：     菜单标题                            *
///      menuItem：     菜单选项数组                        *
///      menuExecFun：  菜单选项执行函数数组                *
///      n：            菜单项数                            *
///  返回值                                                 *
///      无                                                 *
///  函数功能：                                             *
///      显示菜单，根据用户输入的模块编号                   *
///      调用相应模块的执行函数                             *
///**********************************************************
void showMenu(char menuTitle[20], char menuItem[][20], void (*menuExecFun[])(), int n)
{
    while(1)
    {                                           // 循环地显示菜单，直到用户选择0为止
        char choice = ' ';                      // 用户选择的模块编号
        int nChoice = 0;                        // 模块编号数值
        createMenu(menuTitle, menuItem, n);     // 生成并显示菜单
        cin>>choice;                            // 输入选择功能的编号
        nChoice = choice - '0';                 // 将模块号从字符转换为数值
        if(nChoice >= 0 || nChoice <= n)        // 如果模块号合法
        {
            (menuExecFun[nChoice])();           // 执行菜单命令
        }
        if(choice == '0')                       // 模块号为0时
        {
            break;                              // 退出循环
        }   
    }
}

void showAdminCourseManagerMenu()  
// 显示并执行管理员课程信息管理菜单
{
    void (*menuExecFuns[6])();
    menuExecFuns[0] = returnFunc;
    menuExecFuns[1] = courseAppend;             // 新增课程函数
    menuExecFuns[2] = courseQuery;              // 课程查询函数
    menuExecFuns[3] = courseDelete;             // 课程删除函数
    menuExecFuns[4] = courseUpdate;             // 课程修改函数
    menuExecFuns[5] = courseBrowse;             // 课程浏览函数
    char menuTitle[20] = "课程信息管理";
    char menuItem[][20] = {"返回", "新增课程信息", "查询课程信息", "删除课程信息", "修改课程信息", "浏览课程信息"};
    showMenu(menuTitle, menuItem, menuExecFuns, 5);
}

void returnFunc()
{
}
void courseAppend()                 // 新增课程函数
{
}
void courseQuery()                  // 课程查询函数
{
}
void courseDelete()                 // 课程删除函数
{
}
void courseUpdate()                 // 课程修改函数
{
}
void courseBrowse()                 // 课程浏览函数
{
}
