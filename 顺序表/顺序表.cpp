/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: 顺序表
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

//宏
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE maxn
typedef int Status;
typedef int ElemType;
typedef ElemType *Triplet;

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

int e;
SqList L;

//函数声明
Status InitList(SqList &L);
//Status DestroyList(Sqlist &L);
void ClearList(SqList &L);
bool ListEmpty(SqList L);
Status ListLenght(SqList L);
Status GetElem(SqList L, int i, ElemType &e);
Status LocateElem(SqList L, ElemType e);
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e);
Status ListInsert(SqList &L, int i, ElemType e);
Status ListDelete(SqList &L, int i, ElemType &e);
Status ListTraverse(SqList L, Status (*v)(ElemType));

Status visit(ElemType e)
{
    cout << e;
    return OK;
}


//构建空表
Status InitList(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//清空表
void ClearList(SqList &L)
{
    for (int i = 0; i < L.length; i++)
        *(L.elem + i)= 0;
    L.length = 0;
}

//空表判断
bool ListEmpty(SqList L)
{
    if (L.length)
        return true;
    else
        return false;
}

//表长
Status ListLenght(SqList L)
{
    if (!L.elem)
        return ERROR;
    return L.length;
}

//单点查询
Status GetElem(SqList L, int i, ElemType &e)
{
    if (!L.elem || i > L.length || i < 0)
        return ERROR;
    e = *(L.elem + i - 1);
    return OK;
}

//元素位置
int LocateElem(SqList L, ElemType e)
{
    if (!L.elem)
        return ERROR;
    int i = 0;
    while (*(L.elem + i) != e)
        i++;
    return i < ListLenght(L) ? i + 1 : ERROR;
}

//前驱
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    if (!L.elem || LocateElem(L, cur_e) <= 1)
        return ERROR;
    GetElem(L, LocateElem(L, cur_e) - 1, pre_e);
    return OK;
}

//后继
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    if (!L.elem || LocateElem(L, cur_e) >= L.length)
        return ERROR;
    GetElem(L, LocateElem(L, cur_e) + 1, next_e);
    return OK;
}

//插入
Status ListInsert(SqList &L, int i, ElemType e)
{
    if (!L.elem || i > L.length + 1|| i < 0)
        return ERROR;
    for (int j = L.length; j >= i; j--)
        *(L.elem + j + 1) = *(L.elem + j);
    *(L.elem + i - 1) = e;
    L.length++;
    return OK;
}

//删除
Status ListDelete(SqList &L, int i, ElemType &e)
{
    if (!L.elem || i > L.length || i < 0)
        return ERROR;
    e = *(L.elem + i - 1);
    for (int j = i + 1; j < L.length; j++)
        *(L.elem + j - 1) = *(L.elem + j);
    L.length--;
    return OK;
}

//表遍历
Status ListTraverse(SqList L, Status (*v)(ElemType))
{

    if (!L.elem)
        return ERROR;
    cout << "遍历:";
    int i = 0;
    while (i < L.length)
    {
        i == 0 ? cout << "": cout << "->";
        (*v)(*(L.elem + i));
        i++;
    }
    puts("\n");
    return OK;
}

//main
int main()
{

    InitList(L);
    ListInsert(L, 1, 3);
    ListInsert(L, 2, 3);
    ListInsert(L, 3, 2);
    ListInsert(L, 4, 1);

    ListTraverse(L, visit);

    GetElem(L, 1, e);
    cout << "第1个元素:" << e << endl << endl;
    cout << "2的位置:" << LocateElem(L, 2) << endl << endl;
    PriorElem(L, 2, e);
    cout << "元素2的前驱:" << e << endl << endl;

    NextElem(L, 2, e);
    cout << "元素2的后继:" << e << endl << endl;
    ListDelete(L, 4, e);
    cout << "删除第四个元素:" << e << endl << endl;


    ListTraverse(L, visit);
    cout << "长度:" << ListLenght(L) << endl << endl;
    ClearList(L);
    ListTraverse(L, visit);
    ListEmpty(L) ? cout << "非空" << endl: cout << "空" << endl;
    return 0;
}
//void (*print) (SqList *)
//{
//    (*print)(&l);
//}
//ListTraverse(la,print);
