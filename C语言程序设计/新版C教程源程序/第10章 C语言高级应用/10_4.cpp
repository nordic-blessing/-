//***************************************************************
//*  函数 名：writeTeacherInfo                                  *
//*  主要功能：                                                 *
//*     在一行中输出教师信息                                    *
//*  输入参数：                                                 *
//*     teacher：教师的信息                                     *
//*  返回值：                                                   *
//*     无                                                      *
//***************************************************************
void writeTeacherInfo(TeacherInfo teacher)
{
    cout<<"  工资号： ";
    cout<<teacher.no << "\t";    
    cout<<"  姓名： ";
    cout<<teacher.name << "\t";        
    cout<<" "<<(teacher.sexy==1?"男":"女")<<"  ";    
    cout << endl;
    return;
}

//***************************************************************
//*  函数 名：browseTeacherList                                 *  
//*  主要功能：                                                 *
//*     浏览教工信息表                                          *
//*  输入参数：                                                 *
//*     teacherList：指向教师信息表的头指针                     *
//*  返回值：                                                   *
//*     无                                                      *
//***************************************************************
void browseTeacherList(TeacherList teacherList)
{
    if(!teacherList)                        // 教师信息表头结点为空直接返回
    {
        return;
    }

    TeacherNode *p = teacherList->next;     // 指向当前教师结点的指针
    int n = 0;                              // 教师人数

      while(p != NULL)                      // 循环后移指针，至p指向教师表的最后一个结点为止
    {
        writeTeacherInfo(p->data);          // 输出当前教师信息
        p = p->next;                        // 指针后移
        n++;
    }
    cout<<"  共有教师 "<<n<<" 人"<<endl;
}
