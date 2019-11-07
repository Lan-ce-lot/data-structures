/*************************************************************************
 > FileName:
 > Author:      Lance
 > Mail:        lancelot_hcs@qq.com
 > Date:        9102.1.8
 > Description: eg:1-7
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define debug(a) cout << "*" << a << "*" << endl
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;


typedef int Status;
//ºê
#define ERROR 0
#define OK 1



template <typename Ele>
struct _Queue
{
    typedef struct QNode
    {
        Ele data;
        struct QNode *next;
    } QNode, *LinkQueue;

    LinkQueue front;
    LinkQueue rear;
    Ele e;

    Status InitQueue()
    {
        rear = front = (LinkQueue)malloc(sizeof(QNode));

        if (!front)
            exit(OVERFLOW);

        rear->next = front->next;
        return OK;
    }

    void DestroyQueue()
    {
        LinkQueue L = front;
        while (!Qempty())
        {
            front = front->next;
            free(L);
            L = front;
        }
        rear = NULL;
    }

    Status clear()
    {
        LinkQueue L = front;
        while (!Qempty())
        {
            front = front->next;
            free(L);
            L = front;
        }
        front = rear;
    }


    bool Qempty()
    {
        return rear == front;
    }

    int Qlength()
    {
        int Len = 0;
        LinkQueue L = front;
        while (L)
        {
            L = L->next;
            Len++;
        }
        return Len - 1;
    }

    Status GetHead(Ele &e)
    {
        e = front->next->data;
        return Qempty() ? ERROR : OK;
    }

    Status EnQueue(Ele e)
    {
        rear->next = (LinkQueue)malloc(sizeof (QNode));
        if (!rear->next)
            return ERROR;
        rear = rear->next;
        rear->data= e;

        return OK;
    }

    Status DeQueue()
    {
        if (!Qempty())
        {

            LinkQueue L = front;

            front = front->next;
            e = front->data;
            free(L);
            return OK;
        }

        return ERROR;
    }

    Status QTraverse()
    {
        LinkQueue L = front;
        cout << "¶ÓÁÐ:";
        while (L != rear)
        {
            cout << L->next->data << ' ';
            L = L->next;
        }
        cout << endl << endl;
    }
};


