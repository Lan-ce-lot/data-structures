/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: ������
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

//��
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define LIST_INIT_SIZE maxn
typedef int Status;
typedef int ElemType;
typedef ElemType *Triplet;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}*LinkList;

LinkList L;
ElemType e;

//��������
Status InitList(LinkList &L);
void DestroyList(LinkList &L);
void ClearList(LinkList &L);
bool ListEmpty(LinkList L);
int ListLenght(LinkList L);
Status GetElem(LinkList L, int i, ElemType &e);
Status LocateElem(LinkList L, ElemType e);
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e);
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e);
Status ListInsert(LinkList &L, int i, ElemType e);
Status ListDelete(LinkList &L, int i, ElemType &e);
Status ListTraverse(LinkList L, Status (*v)(ElemType));

//��ʼ��
Status InitList(LinkList &L)
{
    L = (LinkList) malloc (sizeof(LNode));
    if (!L)
        exit(OVERFLOW);
    L->next = NULL;
    return OK;
}

//����
void DestroyList(LinkList &L)
{
    LinkList p = L;
    while (p != NULL)
    {
        L = p->next;
        free(p);
        p = L;
    }
}

//���
void ClearList(LinkList &L)
{
    LinkList p, q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;

}

//�жϿ�
bool ListEmpty(LinkList L)
{
    return L->next ? true : false;
}

//����
int ListLenght(LinkList L)
{
    int i = 0;
    while (L->next)
        L = L->next, i++;
    return i;
}

//�����ѯ
Status GetElem(LinkList L, int i, ElemType &e)
{
    if (i > ListLenght(L) || i <= 0)
        return ERROR;
    int j  = 0;
    while (j != i)
    {
        L = L->next;
        j++;
    }
    e = L->data;
    return OK;
}

//λ��
Status LocateElem(LinkList L, ElemType e)
{
    int i = 0;
    while (L->data != e && L->next)
        L = L->next, i++;
    return L->next ? i : ERROR;
}

//ǰ��
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    if (LocateElem(L, cur_e) <= 1)
        return ERROR;
    GetElem(L, LocateElem(L, cur_e) - 1, pre_e);
    return OK;
}

//���
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    if (LocateElem(L, cur_e) >= ListLenght(L))
        return ERROR;
    GetElem(L, LocateElem(L, cur_e) + 1, next_e);
    return OK;
}

//����
Status ListInsert(LinkList &L, int i, ElemType e)
{
    if (i > ListLenght(L) + 1 || i < 0)
        return ERROR;
    LinkList p = L, q;
    int j = 1;

    q = (LinkList) malloc (sizeof(LNode));

    if (!ListLenght(L))
    {
        L->next = q;
        q->next = NULL;
        q->data = e;
        return OK;
    }
    while (j != i)
    {
        p = p->next;
        j++;
    }
    q->data = e;
    q->next = p->next;
    p->next = q;

    return OK;
}

//ɾ��
Status ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i > ListLenght(L) + 1 || i <= 0)
        return ERROR;
    LinkList p = L, q;
    int j = 1;
    while (j != i)
    {
        p = p->next;
        j++;
    }
    e = p->next->data;
    q = p->next;
    p->next = q->next;

    if (!ListLenght(L))
    {
        L->next = NULL;
    }
    free(q);

    return OK;
}

//����
Status ListTraverse(LinkList L)
{
    cout << "����:";
    while(L->next)
    {
        L = L->next;
        L->next ? cout << L->data << " -> " : cout << L->data;
    }
    puts("\n");
    return OK;
}

//main
int main()
{
    InitList(L);
    ListEmpty(L) ? cout << "�ǿ�\n\n" : cout << "��\n\n";

    cout << "�����һ��λ��:3" << endl;
    ListInsert(L, 1, 3);
    ListTraverse(L);

    ListEmpty(L) ? cout << "�ǿ�\n\n" : cout << "��\n\n";

    cout << "�����һ��λ��:2" << endl;
    ListInsert(L, 1, 2);
    ListTraverse(L);
    cout << "�����һ��λ��:1" << endl;
    ListInsert(L, 1, 1);
    ListTraverse(L);

    cout << "�����һ��λ��:0" << endl;
    ListInsert(L, 1, 0);
    ListTraverse(L);

    cout << "���������λ��:0" << endl;
    ListInsert(L, 3, 0);
    ListTraverse(L);



    PriorElem(L, 2, e);
    cout << "ǰ��:" << e << endl;
    NextElem(L, 2, e);
    cout << "���:" << e << endl;

    ListDelete(L, 1, e);
    cout << "ɾ����һ��Ԫ��:" << e << endl;
    ListTraverse(L);


    ListDelete(L, 4, e);
    cout << "ɾ�����ĸ�Ԫ��:" << e << endl;
    ListTraverse(L);



    return 0;
}
