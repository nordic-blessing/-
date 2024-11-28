//***************************************************************
//*  函数 名：deleteTeacherInfo                                 *
//*  主要功能：                                                 *
//*     将工资号为no的教师从教师信息表teacherList中删除         *
//*  输入参数：                                                 *
//*     teacherList：指向教师信息表的头指针                     *
//*     no：教师的工资号                                        *
//*  返回值：                                                   *
//*     0—失败；1—成功                                        *
//***************************************************************
int deleteTeacherInfo(TeacherList teacherList, char no[])
{
    if(!teacherList)                            // 教师信息表头结点为空，返回错误
    {
        return 0;
    }

    TeacherNode *pre = teacherList;             // 指向前驱结点的指针
    TeacherNode *p = pre->next;                 // 指向当前结点的指针
    
    while(p != NULL)                            // 循环后移指针，至当前结点的工资号与no相等为止
    {
        if(strcmp(p->data.no, no) == 0)         // 查找成功
        {
            break;
        }
        pre = p;
        p = p->next;
    }

    if(!p)                                      // 查找不成功
    {
        return false;
    }
    else                                        // 查找成功
    {
        pre->next = p->next;                    // 从链表中删掉当前结点
        delete p;                               // 释放当前结点所占用的空间
        return 1;
    }
}
