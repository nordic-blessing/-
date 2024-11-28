//***************************************************************
//*  函数 名：insertTeacherInfo                                 *
//*  主要功能：                                                 *
//*     按教工号插入教工信息到有序的教工信息表中，              *
//*     假设链表已按教工号大小链接的                            *
//*  输入参数：                                                 *
//*     teacherList：指向教师信息表的头指针                     *
//*     teacher：教师的信息                                     *
//*  返回值：                                                   *
//*     指向教师信息表的头指针                                  *
//***************************************************************
TeacherList insertTeacherInfo(TeacherList teacherList, TeacherInfo teacher)
{
    TeacherList pNew = NULL;                // 指向新生成结点的指针
    TeacherNode *p = teacherList;           // 指向当前教师结点的前驱结点的指针
    TeacherNode *q = NULL                   // 指向当前教师结点的指针
    pNew = new TeacherNode;                 // 生成新结点
    pNew->data = teacher;
    pNew->next = NULL;
    if(!teacherList)                        // 教师信息表头指针为空
    {
        teacherList = initTeacherList();    // 建立一个空的教师信息表（只含头结点）
    }
    q = teacherList->next;                  // 指向第一个结点; 
    while(q)                                // 寻找插入位置
    {
        if(strcmp(q->data.no, pNew->data.no) > 0)
        {
            break;
        }
        else
        {
            p = q;                          // p指针后移
            q = q->next;                    // q指针后移
        }
    }
    pNew->next = q;                         // 新结点的后继指针指向q
    p->next = pNew;                         // 前驱结点p的后继指向新结点
    return teacherList;
}
